#include <iostream>
#include <string>
using namespace std;

class Book {
    string title, author;
    double price;
    int copies;

    static int validCopies(int n) { return n < 0 ? 0 : n; }

public:
    Book() : Book("Unknown", "Unknown", 0.0, 0) {
        cout << "Default constructor called\n";
    }
    explicit Book(string t) : Book(t, "Unknown", 0.0, 0) {
        cout << "Title-only constructor called\n";
    }
    Book(string t, string a, double p, int c)
        : title(t), author(a), price(p), copies(validCopies(c)) {
        cout << "Full parameterized constructor called\n";
    }
    void display() const {
        cout << "\nTitle: " << title << "\nAuthor: " << author
             << "\nPrice: " << price << "\nCopies: " << copies << '\n';
    }
};

int main() {
    cout << "Q1 - CONSTRUCTORS AND CONSTRUCTOR OVERLOADING\n";
    Book empty;
    Book donated("C++ Programming");
    Book full("Data Structures", "Mark Allen", 550.50, 10);
    Book invalid("Operating Systems", "Galvin", 650.00, -5);
    empty.display(); donated.display(); full.display(); invalid.display();
}
