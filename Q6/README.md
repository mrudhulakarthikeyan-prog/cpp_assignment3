# Q6 – Rules of Operator Overloading
Run main.cpp. Text owns a dynamic character array and implements constructor, deep-copy
constructor, copy assignment, destructor, +, ==, != and <<. Tests empty/long text and
self-assignment, counts copy-constructor calls, and times 100,000 std::string appends.
Explain non-overloadable ::, ., .*, ?:, sizeof; precedence/arity cannot change; at least
one operand must be user-defined; operator= must be a member; << is commonly a friend
non-member. Compare a+b+c character-copy cost and temporary storage. Run under ASan if
available.
