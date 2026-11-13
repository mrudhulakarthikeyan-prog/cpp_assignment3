# DSA01 Assignment 3 – Full C++17 Implementation

This package contains runnable implementations and separate investigation programs for Q1–Q7.
Open this folder in VS Code. Use PowerShell from this folder.

## Easiest option: run everything
```powershell
Set-ExecutionPolicy -Scope Process -ExecutionPolicy Bypass
.\run_all.ps1
```
This compiles and runs the main program for each question and the separate Complete-the-Code
and Predict-the-Output programs. It saves a text run log in `Evidence/RunLogs`.
It does NOT create fake screenshots. Capture actual terminal screenshots yourself.

## Run one question
```powershell
cd Q1
g++ -std=c++17 -Wall -Wextra main.cpp -o q1.exe
.\q1.exe
```
For Q2–Q7, replace Q1/q1 with the required folder/executable name.

## Important
- `main.cpp` in each Q folder is the main runnable solution.
- Additional files contain the assignment's separate investigation/Complete-the-Code/
  Predict-the-Output activities.
- Q3 and Q5 prediction text files are intentionally blank. Write your prediction BEFORE
  running their prediction programs, as required by the brief.
- AddressSanitizer support depends on your MinGW/g++ installation. If unsupported, record
  the exact compiler/runtime limitation and use an available Valgrind/WSL environment.
- Benchmark timings vary by machine and compiler. Record your actual results; do not copy
  sample timings.
- Read each Q folder README for the experiments to capture.
- Add your name, register number, compiler version and GitHub URL below.

Student name:
Register number:
Compiler/version:
GitHub repository URL:
