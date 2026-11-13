#include <iostream>

class BookTitle {
public:
    explicit BookTitle(const char* title) {
        std::cout << "BookTitle constructor called: " << title << '\n';
    }
};

void receive(BookTitle) {
    std::cout << "Book received successfully.\n";
}

int main() {
    std::cout << "WITHOUT EXPLICIT KEYWORD\n";

    receive("C++");

    receive(BookTitle("Data Structures"));

    return 0;
}