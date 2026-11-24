# C++ Modules 00–09

This repository contains my solutions to the **C++ Modules 00 through 09** from the  1337 Coding School — 42 Network curriculum. 
The modules introduce object-oriented programming in C++ step by step, starting with basic syntax and classes and ending with templates, STL containers, and advanced algorithms.

All exercises target **C++98** and are compiled with strict warning flags:

```text
-Wall -Wextra -Werror -std=c++98
```

## Modules

| Module | Main topics | Exercises |
| --- | --- | --- |
| [CPP Module 00](./CPP_Module_00) | Namespaces, classes, member functions, streams, initialization lists, `static` and `const` | Megaphone, PhoneBook, Account |
| [CPP Module 01](./CPP_Module_01) | Memory allocation, pointers, references, switch statements, file streams | Zombies, pointer/reference practice, Weapon, string replacement, Harl |
| [CPP Module 02](./CPP_Module_02) | Orthodox Canonical Form, operator overloading, fixed-point numbers | Fixed-point class, conversions, arithmetic and comparison operators |
| [CPP Module 03](./CPP_Module_03) | Inheritance and class hierarchies | ClapTrap, ScavTrap, FragTrap, DiamondTrap |
| [CPP Module 04](./CPP_Module_04) | Runtime polymorphism, abstract classes, interfaces, deep copies | Animals, brains, abstract animals, Materia system |
| [CPP Module 05](./CPP_Module_05) | Exceptions and reusable form hierarchies | Bureaucrat, Form/AForm, concrete forms, Intern |
| [CPP Module 06](./CPP_Module_06) | C++ casts and runtime type identification | Scalar conversion, serialization, type identification |
| [CPP Module 07](./CPP_Module_07) | Function and class templates | `whatever`, `iter`, `Array<T>` |
| [CPP Module 08](./CPP_Module_08) | STL containers, iterators, generic algorithms | `easyfind`, Span, MutantStack |
| [CPP Module 09](./CPP_Module_09) | STL-based data processing and algorithms | Bitcoin Exchange, RPN calculator, merge-insertion sort |

## Repository structure

Each module contains one directory per exercise. Every exercise is independent and includes its own `Makefile` and test-oriented `main` program.

```text
CPP_Module_XX/
└── exYY/
    ├── Makefile
    ├── main.cpp
    ├── *.cpp
    └── *.hpp
```

## Build and run

Requirements:

- A C++ compiler such as `c++` or `clang++`
- GNU Make
- A Unix-like environment

Enter any exercise directory and run `make`:

```bash
cd CPP_Module_03/ex03
make
./DiamondTrap
```

The Makefiles provide the usual rules:

```bash
make        # build the exercise
make clean  # remove object files
make fclean # remove object files and the executable
make re     # rebuild from scratch
```

## Example programs

```bash
# Module 00: convert text to uppercase
cd CPP_Module_00/ex00 && make
./megaphone "hello 1337"

# Module 01: replace every occurrence of one string in a file
cd ../../CPP_Module_01/ex04 && make
./Sed input.txt old new

# Module 06: display a scalar literal as char, int, float and double
cd ../../CPP_Module_06/ex00 && make
./convert 42.0f

# Module 09: evaluate a Reverse Polish Notation expression
cd ../../CPP_Module_09/ex01 && make
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"

# Module 09: sort a positive integer sequence
cd ../ex02 && make
./PmergeMe 3 5 9 7 4
```

`CPP_Module_09/ex00` expects the subject-provided `data.csv` file in its current working directory and an input file whose first line is `date | value`.

## Learning objectives

Across the ten modules, this project practices:

- Writing classes in Orthodox Canonical Form
- Managing object lifetime, dynamic memory, copies, and ownership
- Designing inheritance trees and polymorphic interfaces
- Using exceptions for error handling
- Choosing and applying explicit C++ casts
- Building reusable function and class templates
- Working with STL containers, algorithms, and iterators
- Comparing algorithm behavior and performance across containers

## Notes

- The code follows the C++98 constraints of the 42/1337 subject.
- Exercise executables are intentionally built inside their respective directories.
- The `main.cpp` files serve as demonstrations and basic tests; additional edge-case testing is recommended during evaluation.

## Author

Developed as part of the **1337 / 42 Network** C++ curriculum.
