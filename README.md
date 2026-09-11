# Address_book
# 📒 Address Book Management System

A simple and efficient **Address Book Management System** developed in **C**. This project provides a command-line interface to manage contact information and demonstrates practical concepts such as **Data Structures, File Handling, String Manipulation, Modular Programming, Pointers, and Input Validation**.

## 📌 Table of Contents

* [Project Overview](#-project-overview)
* [Features](#-features)
* [Project Objectives](#-project-objectives)
* [Technologies Used](#-technologies-used)
* [Project Structure](#-project-structure)
* [System Requirements](#-system-requirements)
* [Compilation](#-compilation)
* [Running the Project](#-running-the-project)
* [Functional Description](#-functional-description)
* [Input Validation](#-input-validation)
* [Data Storage](#-data-storage)
* [Workflow](#-workflow)
* [Sample Output](#-sample-output)
* [Future Enhancements](#-future-enhancements)
* [Learning Outcomes](#-learning-outcomes)
* [Author](#-author)

---

## 📌 Project Overview

The **Address Book Management System** is a menu-driven C application designed to store and manage contact information.

The system allows users to:

* Add new contacts
* Search for contacts
* Edit existing contacts
* Delete contacts
* Display all contacts
* Save contact information to a file

The project uses modular programming to divide the application into multiple source files, making the code easier to understand, maintain, and extend.

---

## ✨ Features

* ➕ Add a new contact
* 🔍 Search contacts
* ✏️ Edit contact details
* 🗑️ Delete contacts
* 📋 Display all contacts
* 💾 Save contacts using file handling
* 📂 Load existing contacts
* ✅ Input validation
* 🧩 Modular programming
* 📊 Data structure implementation
* 🔤 String manipulation

---

## 🎯 Project Objectives

* To understand the implementation of **data structures in C**.
* To practice **file handling operations**.
* To improve understanding of **pointers and structures**.
* To implement **string manipulation functions**.
* To develop a modular and maintainable C program.
* To implement proper **input validation and error handling**.

---

## 🛠️ Technologies Used

| Technology          | Usage                                        |
| ------------------- | -------------------------------------------- |
| **C**               | Core programming language                    |
| **Data Structures** | Managing contact records                     |
| **Structures**      | Storing contact information                  |
| **Pointers**        | Dynamic data manipulation                    |
| **File Handling**   | Saving and loading contacts                  |
| **String Handling** | Managing names, phone numbers, and email IDs |
| **GCC**             | Compilation                                  |

---

## 📁 Project Structure

```text
Address-Book/
│
├── main.c
├── contact.c
├── contact.h
├── file.c
├── file.h
├── validation.c
├── validation.h
├── Makefile
└── README.md
```

> The exact file names may vary depending on your project implementation.

---

## 💻 System Requirements

* GCC Compiler
* Linux / Windows / macOS
* Command-line terminal
* Basic knowledge of C programming

---

## ⚙️ Compilation

If you are using GCC:

```bash
gcc *.c -o addressbook
```

For a project using a Makefile:

```bash
make
```

---

## ▶️ Running the Project

### Linux / macOS

```bash
./addressbook
```

### Windows

```bash
addressbook.exe
```

---

## 🔧 Functional Description

### 1. Add Contact

Allows the user to enter and store new contact information such as:

* Name
* Mobile number
* Email ID

### 2. Search Contact

Allows users to search for an existing contact using available contact details such as name or phone number.

### 3. Edit Contact

Allows users to modify the details of an existing contact.

### 4. Delete Contact

Removes a selected contact from the address book.

### 5. Display Contacts

Displays all stored contacts in a structured format.

### 6. Save Contacts

Stores contact information in a file so that the data can be preserved after the program terminates.

### 7. Load Contacts

Reads previously saved contact information from the file when the application starts.

---

## ✅ Input Validation

The application validates user input to reduce invalid data entry.

Examples include:

* Validating phone numbers
* Validating email addresses
* Checking for empty names
* Checking whether a contact exists
* Handling invalid menu choices

---

## 💾 Data Storage

The project uses **file handling in C** to provide persistent storage.

Contact information can be written to and read from a file using standard C file operations such as:

```c
fopen()
fprintf()
fscanf()
fread()
fwrite()
fclose()
```

This allows contact information to remain available even after the program is closed.

---

## 🔄 Workflow

```text
        Start
          |
          v
   Load Contact Data
          |
          v
    Display Menu
          |
    +-----+-----+-----+-----+-----+
    |     |     |     |     |     |
   Add  Search Edit Delete Display
    |     |     |     |     |
    +-----+-----+-----+-----+
          |
          v
      Save Data
          |
          v
         Exit
```

---

## 🖥️ Sample Output

```text
========================================
       ADDRESS BOOK MANAGEMENT
========================================

1. Add Contact
2. Search Contact
3. Edit Contact
4. Delete Contact
5. Display Contacts
6. Save Contacts
7. Exit

Enter your choice: 1

Enter Name   : Darshan
Enter Mobile : 9876543210
Enter Email  : darshan@example.com

Contact added successfully!
```

### Display Contacts

```text
========================================
           CONTACT LIST
========================================

Name       : Darshan
Mobile     : 9876543210
Email      : darshan@example.com

========================================
```

---

## 🚀 Future Enhancements

* Add sorting of contacts by name
* Add duplicate contact detection
* Add password-based access
* Improve the user interface
* Add contact groups
* Add birthday and address fields
* Implement dynamic memory allocation
* Develop a graphical user interface

---

## 📚 Learning Outcomes

Through this project, I gained practical experience in:

* **C Programming**
* **Data Structures**
* **Structures and Pointers**
* **File Handling**
* **String Manipulation**
* **Modular Programming**
* **Input Validation**
* **Debugging and Error Handling**
* **Makefile and GCC compilation**

---

## 👨‍💻 Author

**Darshuu**

### 📌 Project

**Address Book Management System**

### 💻 Language

**C Programming**

---
