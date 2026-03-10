# CGPA Calculator (C++)

This program calculates a student's **semester GPA** and **overall CGPA** using course grades and credit hours.  
It demonstrates **Object-Oriented Programming (OOP) concepts in C++** including classes, inheritance and vectors.

## Task Description

The program performs the following operations:

- Takes the **student name**
- Accepts **previous total credits and previous CGPA**
- Takes input for the **number of courses in the current semester**
- Accepts **grade and credit hours** for each course
- Converts letter grades into **grade points**
- Calculates **total credit hours**
- Calculates **semester GPA**
- Computes the **Computes the overall CGPA using previous academic record and current semester results**
- Displays a complete **student academic report**

## Program Structure

The program is organized using multiple classes:

### StudentInfo
Stores and displays the **student's name**.

### Course
Stores **course grade and credit hours** and converts grades into grade points.

### Semester
Manages courses using a **vector** and calculates:
- Total credits
- Total grade points
- Semester GPA

### CGPA
Calculates the **overall CGPA** using previous credits, previous CGPA and current semester results.

### Student
Combines all components and generates the **final report**.

## OOP Concepts Used

- **Encapsulation** – Data and functions are organized inside classes.
- **Inheritance** – `Student` inherits from `StudentInfo`.
- **Abstraction** – GPA and CGPA calculations are handled in separate classes.

## Features

- Accepts multiple courses as input  
- Supports common grading scales (A+, A, B+, B, etc.)  
- Calculates both **GPA and CGPA**  
- Uses **vectors and classes** for structured design  

## Language Used

C++
