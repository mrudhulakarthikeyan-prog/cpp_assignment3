Q2 FAST EXPERIMENT COMMANDS (Ubuntu WSL)

You are currently in the Q2 folder. Save these files into that same Q2 folder.

1) Compile and run the unsafe shallow-copy test with AddressSanitizer:
   g++ -std=c++17 -Wall -Wextra -fsanitize=address -g shallow_copy.cpp -o shallow_asan
   ./shallow_asan

   EXPECTED: AddressSanitizer reports an attempted double-free. This is intentional.
   Do not remove the sanitizer output; capture a screenshot.

2) Test deleting the copy constructor:
   g++ -std=c++17 -Wall -Wextra deleted_copy_constructor.cpp -o deleted_copy
   EXPECTED: compilation fails because the copy constructor is deleted.
   Capture the compiler error.

3) Re-run the safe Rule-of-Three implementation:
   g++ -std=c++17 -Wall -Wextra -fsanitize=address -g main.cpp -o q2_asan
   ./q2_asan

   EXPECTED: correct independent values and no AddressSanitizer error.

IMPORTANT:
- The shallow-copy program is deliberately defective. Its purpose is to demonstrate
  the double-free bug. Run it only with AddressSanitizer and do not use it as the
  final implementation.
- Do not claim a sanitizer report if no report was actually produced.
