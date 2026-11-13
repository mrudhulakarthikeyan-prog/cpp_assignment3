#include <iostream>
#include <string>

class UnsafePrescription {
    int n;
    std::string* medicines;
public:
    explicit UnsafePrescription(int count)
        : n(count), medicines(new std::string[count]) {}
    // Intentionally no copy constructor: compiler-generated copy is shallow.
    ~UnsafePrescription() {
        std::cout << "Destructor releasing array at " << static_cast<void*>(medicines) << '\n';
        delete[] medicines;
    }
    void set(int i, const std::string& value) { medicines[i] = value; }
    void print() const {
        for (int i = 0; i < n; ++i) std::cout << medicines[i] << ' ';
        std::cout << '\n';
    }
};

int main() {
    std::cout << "Q2 - INTENTIONALLY UNSAFE SHALLOW COPY\n";
    UnsafePrescription original(2);
    original.set(0, "Paracetamol");
    original.set(1, "ORS");
    {
        UnsafePrescription copy = original; // shallow pointer copy
        std::cout << "Original: "; original.print();
        std::cout << "Copy: "; copy.print();
    } // copy destructor frees the shared array
    std::cout << "Original is now dangling; do not dereference it.\n";
    // The original destructor will attempt to free the same pointer again.
    // Run ONLY under AddressSanitizer to observe the double-free report.
}
