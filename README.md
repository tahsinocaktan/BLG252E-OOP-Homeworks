# BLG252E - Object Oriented Programming Homeworks

## Overview
This repository contains three C++ assignments completed as part of the **BLG252E - Object Oriented Programming** course at **Istanbul Technical University (ITU)** during the 2023-2024 academic year. Each assignment focuses on different object-oriented programming principles, including **class design, operator overloading, polymorphism, file handling, and STL usage**.

## Assignments

### **1. Homework 1 - Customer & Product Classes**
**Topics Covered:**
- Implementation of `Product` and `Customer` classes based on UML class diagrams.
- Overloading the `operator+` to add products to a customer’s order list.
- Implementing constraints to prevent exceeding credit limits or order limits.
- Writing a `main` function to test the program without user input.
- Outputting customer details including total debt and ordered products.

📌 **Key OOP Concepts:**
- Constructor overloading
- Operator overloading
- Encapsulation and data members

### **2. Homework 2 - Power Plant Polymorphism & Histogram Visualization**
**Topics Covered:**
- Implementing an **abstract base class (`Plant`)** for power plants.
- Creating derived classes (`Coal` and `Hydro`) with overridden `plot()` functions.
- Using **polymorphism** via an array of base class pointers.
- Generating histograms for **megawatt outputs, carbon emissions, and hydro heights**.
- Computing **average carbon emissions** for coal plants and **average dam height** for hydro plants.

📌 **Key OOP Concepts:**
- Abstract classes
- Polymorphism
- Dynamic memory allocation (heap)
- Function overriding

### **3. Homework 3 - STL-Based Book Management System**
**Topics Covered:**
- Using **STL Maps** to store books, authors, and publishers.
- Reading structured data from text files (`AUTHORS.txt`, `PUBLISHERS.txt`, `BOOKS.txt`).
- Implementing the `Book` class with appropriate constructors and a `print()` function.
- Grouping and displaying book lists by publisher, ensuring formatted output.

📌 **Key OOP Concepts:**
- Standard Template Library (STL) usage
- File handling (reading structured data from text files)
- Data mapping with `std::map`
- Formatted output using `<iomanip>`

## How to Run
1. Clone this repository:
   ```sh
   git clone https://github.com/<your-username>/BLG252E-OOP-Assignments.git
   cd BLG252E-OOP-Assignments
   ```
2. Compile each assignment separately using a C++ compiler (e.g., g++):
   ```sh
   g++ homework1.cpp -o homework1
   ./homework1
   ```
3. For **Homework 3**, ensure the required text files (`AUTHORS.txt`, `PUBLISHERS.txt`, `BOOKS.txt`) are in the same directory before running:
   ```sh
   g++ homework3.cpp -o homework3
   ./homework3
   ```

## Dependencies
- **C++ Compiler** (e.g., `g++`, `clang++`, `MSVC`)
- **STL Library** (For Homework 3)
- **File Handling Support** (For Homework 3)

## Contributors
- Developed by [Tahsin OCAKTAN]

---
This repository showcases fundamental object-oriented programming principles applied in real-world C++ scenarios. Contributions and improvements are welcome!


