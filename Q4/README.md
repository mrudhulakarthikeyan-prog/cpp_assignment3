# Q4 – Arithmetic and Stream Operator Overloading
Run main.cpp and complete_the_code.cpp. Money stores signed paise in long long;
negative results are represented as signed amounts. Test paise carry, subtraction,
+=, equality, formatted output and integer-vs-double timing. Explain + returns a new
value, += returns *this by reference, << is a non-member friend to put ostream on the
left, and a+b maps to a.operator+(b). Multiplying two Money amounts is not a natural
billing operation; multiplication by a quantity is more meaningful.
