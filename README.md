# DSA Practical Assignments

**Student:** Yuvraj Santosh Tapkir  
**PRN:** 202501110180  
**Batch shown in practical file:** AIML (B3)

This repository contains the source-code files extracted from the submitted 66-page merged practical PDF, along with the original PDF for reference.

## Folder structure

- `Source_Code/` — individual C and C++ source files.
- `Original_Practical_PDF/` — original practical document containing problem statements, code screenshots/text, outputs and complexity analysis.

## Source-code index

| File | Practical / program |
|---|---|
| `01_Array_Student_Mark_Analysis.cpp` | Array — Student Mark Analysis System |
| `02_Hashing_Parking_Lot.cpp` | Hashing — Parking Lot Management with Linear Probing |
| `03_Sentinel_Search_Phonebook.cpp` | Sentinel Search — Friend Phone Book |
| `04_Circular_Linked_List_Call_Log.c` | Practical 4 — Call Log Management (C source) |
| `05_Doubly_Linked_List_Train_Reservation.c` | Practical 4 — Train Reservation (Doubly Linked List, C source) |
| `06_Stack_Using_Two_Queues.cpp` | Practical 5 — Stack using two Queues |
| `07_Queue_Using_Linked_List.cpp` | Practical 6 — Queue using Linked List |
| `08_Queue_Using_Two_Stacks.cpp` | Practical 6 — Queue using two Stacks |
| `09_Task_Scheduler_Deque.cpp` | Practical 7 — Task Scheduler using Deque |
| `10_Palindrome_Using_Deque.cpp` | Assignment 8 — Palindrome Checking using Deque |

## Important notes

1. The source code is transcribed from the code sections in the original PDF. The original PDF is retained so the source can be compared with the submitted practical record.
2. The PDF labels the Call Log program as a Circular Linked List, but the displayed implementation links nodes in a linear singly linked manner. This has not been silently changed.
3. The PDF section headings say “Trees” for Practical 7 and “Graph” for Assignment 8, while the corresponding programs shown are Deque-based. The original titles/content have been preserved in this index.
4. The two Practical 4 programs and two Practical 6 programs are kept as separate source files because they are separate programs in the PDF.
5. The source files were checked for C/C++ syntax using GCC/G++. This is a syntax check, not a guarantee that every runtime scenario has been tested.

## How to compile

For a C++ file:

```bash
g++ -std=c++17 Source_Code/filename.cpp -o program
./program
```

For a C file:

```bash
gcc -std=c11 Source_Code/filename.c -o program
./program
```
