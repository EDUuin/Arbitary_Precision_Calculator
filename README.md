# Arbitrary Precision Calculator (APC)

## Overview

The **Arbitrary Precision Calculator (APC)** is a command-line calculator written in C that performs arithmetic operations on integers of virtually unlimited size.

Instead of relying on standard C data types such as `int`, `long`, or `long long`, this project represents numbers using a **Doubly Linked List**, where each node stores a single digit. This allows the calculator to handle extremely large integers without overflow.

The project demonstrates:

* Data structures using doubly linked lists
* Dynamic memory management
* Manual arithmetic implementation
* Command-line argument handling
* Modular programming in C

---

## Features

* Supports arbitrarily large integers
* Handles positive and negative numbers
* Implements arithmetic manually without built-in big integer libraries
* Modular code structure
* Command-line based execution
* Proper input validation
* Leading zero removal in results

---

## Supported Operations

| Operation      | Symbol |
| -------------- | ------ |
| Addition       | `+`    |
| Subtraction    | `-`    |
| Multiplication | `*`    |
| Division       | `/`    |

---

## Project Structure

```text
.
├── main.c                 # Main driver program
├── apc.h                  # Header file with structures and prototypes
├── apc_utils.c            # Utility/helper functions
├── apc_operation.c        # Addition, subtraction, multiplication
├── apc_division.c         # Division implementation
├── apc_validation.c       # Input validation
├── Makefile               # Build automation
└── Documentation.txt      # Detailed project documentation
```

---

## Data Structure Used

Each digit of a number is stored in a node of a doubly linked list.

```c
typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
} Dlist;
```

Example:

```text
Number: 987654

Head → [9] ↔ [8] ↔ [7] ↔ [6] ↔ [5] ↔ [4] ← Tail
```

This representation removes size limitations imposed by standard integer types.

---

## Arithmetic Logic

### Addition

* Starts from the Least Significant Digit (LSD)
* Performs digit-by-digit addition
* Propagates carry values

### Subtraction

* Handles borrow operations
* Compares operands before subtraction
* Removes unnecessary leading zeros

### Multiplication

* Implements schoolbook multiplication
* Uses shifting with zero insertion
* Accumulates partial products using addition

### Division

* Uses repeated subtraction method
* Computes quotient by counting subtractions
* Handles division-by-zero safely

---

## Compilation

Using Makefile:

```bash
make
```

Or compile manually:

```bash
gcc main.c apc_utils.c apc_operation.c apc_division.c apc_validation.c -o apc
```

---

## Usage

```bash
./apc <operand1> <operator> <operand2>
```

### Examples

#### Addition

```bash
./apc 999999999999999999999 + 1
```

Output:

```text
1000000000000000000000
```

#### Subtraction

```bash
./apc -5000 - 2500
```

Output:

```text
-7500
```

#### Multiplication

```bash
./apc 123456789 * 987654321
```

#### Division

```bash
./apc 1000 / 25
```

Output:

```text
40
```

---

## Input Validation

The calculator validates:

* Valid operators
* Numeric operands
* Optional sign (`+` or `-`)
* Division by zero

Example invalid input:

```bash
./apc 12a + 34
```

Output:

```text
ERROR: Operand 1 should contain only digits
```

---

## Important Functions

| Function                 | Purpose                                      |
| ------------------------ | -------------------------------------------- |
| `addition()`             | Performs large integer addition              |
| `subtraction()`          | Performs large integer subtraction           |
| `multiplication()`       | Performs multiplication                      |
| `division()`             | Performs division using repeated subtraction |
| `compare_lists()`        | Compares two linked-list numbers             |
| `insert_front()`         | Inserts digit at beginning                   |
| `remove_leading_zeros()` | Cleans result formatting                     |
| `copy_list()`            | Creates deep copy of a number                |
| `print_list()`           | Displays final result                        |

---

## Applications

* Big integer arithmetic
* Educational data structure projects
* Cryptographic computations
* Competitive programming practice
* Precision-sensitive calculations

---

## Advantages

* No integer overflow
* Works with very large numbers
* Clear modular implementation
* Good demonstration of linked list operations
* Easy to extend with new features

---

## Current Limitations

* Division uses repeated subtraction and is slow for huge numbers
* Only integer arithmetic supported
* No floating-point support
* No modulus operation

---

## Future Improvements

* Implement long division algorithm
* Add modulo (`%`) support
* Add floating-point arithmetic
* Improve execution efficiency
* Add file-based input/output
* Create interactive calculator mode

---

## Learning Outcomes

This project helps in understanding:

* Doubly Linked Lists
* Dynamic Memory Allocation
* Arbitrary Precision Arithmetic
* Modular Programming
* Command-Line Argument Parsing
* Manual Arithmetic Algorithms

---

## Author

**Edwin Shaji Varghese**

B.Tech Electrical and Electronics Engineering

---

## License

This project is intended for educational and learning purposes.
