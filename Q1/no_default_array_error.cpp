class Book {
public:
    Book(const char*) {}
};
int main() {
    Book shelf[3]; // Expected compile error: no default constructor.
}
