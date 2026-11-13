# Q2 – Copy Constructors: Shallow and Deep Copies
Main program demonstrates deep copy, assignment, self-assignment, pass-by-value/reference,
copy timings and vector alternative. Complete-the-Code program is included separately.
For the shallow-copy experiment, preserve a separate unsafe variant and run only in an
isolated sanitizer/WSL environment; do not run a double-delete program if it risks your work.
Rule of Three: destructor, copy constructor, copy assignment. Copy constructor is used
for initialization from another object, pass-by-value, and returning by value (subject
to copy elision). Record actual sanitizer availability/output.
