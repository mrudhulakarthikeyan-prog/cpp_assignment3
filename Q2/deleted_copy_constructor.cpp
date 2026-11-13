#include <string>

class Prescription {
    int n;
    std::string* medicines;
public:
    explicit Prescription(int count) : n(count), medicines(new std::string[count]) {}
    Prescription(const Prescription&) = delete;
    ~Prescription() { delete[] medicines; }
};

int main() {
    Prescription first(2);
    Prescription second = first; // Expected compile-time error: copy is deleted.
}
