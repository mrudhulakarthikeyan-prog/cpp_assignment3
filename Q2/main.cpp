#include <chrono>
#include <iostream>
#include <string>
#include <vector>

class Prescription {
    int n;
    std::string* medicines;
public:
    explicit Prescription(int count)
        : n(count < 0 ? 0 : count), medicines(new std::string[n]) {}
    Prescription(const Prescription& other)
        : n(other.n), medicines(new std::string[other.n]) {
        for (int i=0; i<n; ++i) medicines[i]=other.medicines[i];
        std::cout << "Deep-copy constructor called\n";
    }
    Prescription& operator=(const Prescription& other) {
        if (this != &other) {
            std::string* fresh = new std::string[other.n];
            for (int i=0; i<other.n; ++i) fresh[i]=other.medicines[i];
            delete[] medicines;
            medicines=fresh; n=other.n;
        }
        return *this;
    }
    ~Prescription() { delete[] medicines; }
    void set(int i,const std::string& s) { if(i>=0&&i<n) medicines[i]=s; }
    std::string get(int i) const { return (i>=0&&i<n)?medicines[i]:"<invalid>"; }
    int size() const { return n; }
};
void byValue(Prescription p) { (void)p.get(0); }
void byConstReference(const Prescription& p) { (void)p.get(0); }

int main() {
    std::cout << "Q2 - DEEP COPY / RULE OF THREE\n";
    Prescription p(2); p.set(0,"Paracetamol"); p.set(1,"ORS");
    Prescription q=p; q.set(1,"Cetirizine");
    Prescription r(1); r=p; p.set(0,"Ibuprofen");
    r=r; // self-assignment test
    std::cout << p.get(0) << ' ' << p.get(1) << " | "
              << q.get(0) << ' ' << q.get(1) << " | "
              << r.get(0) << ' ' << r.get(1) << '\n';
    byValue(p);
    byConstReference(p);
    for(int n : {10,1000,100000}) {
        Prescription large(n);
        auto start=std::chrono::steady_clock::now();
        Prescription copy=large;
        auto us=std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::steady_clock::now()-start).count();
        std::cout << "Copy " << n << " medicines: " << us << " us\n";
    }
    std::vector<std::string> vectorAlternative{"Paracetamol","ORS"};
    auto vectorCopy=vectorAlternative;
    std::cout << "vector deep-copy size: " << vectorCopy.size() << '\n';
}
