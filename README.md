# 📚 Library Management System

A modular Library Management System built in Modern C++ demonstrating Object-Oriented Programming (OOP), STL, clean architecture, and Git-based version control.

---

## 📖 Overview

This project is a console-based Library Management System built using Modern C++. It allows users to manage books efficiently by performing operations such as adding, removing, searching, issuing, and returning books. The project demonstrates Object-Oriented Programming (OOP) principles, modular design, and the use of STL containers while following clean software engineering practices.

---

## ✨ Features

- Add new books to the library.
- Search books by their unique ID.
- Display all books available in the library.
- Issue books to users.
- Return issued books.
- Remove books from the library.
- Prevent duplicate book entries.
- Prevent issued books from being removed.

---

## 🛠️ Tech Stack

- **Language:** Modern C++ (C++17)
- **Standard Template Library (STL):** `unordered_map`, `string`
- **Programming Paradigm:** Object-Oriented Programming (OOP)
- **Build Tool:** g++
- **Version Control:** Git
- **Repository Hosting:** GitHub
- **Development Environment:** Visual Studio Code + WSL (Ubuntu)

---

## 🎯 OOP & Modern C++ Concepts Demonstrated

- Encapsulation
- Classes and Objects
- Constructor Initialization Lists
- Const Correctness
- Const Function Overloading
- Pass-by-Reference
- Function Overloading
- Header / Source File Separation (`.hpp` / `.cpp`)
- STL Containers (`std::unordered_map`)
- Iterators
- Pointers and References
- Modular Project Structure

---

## 📂 Project Structure

```text
library-management-system/
│
├── book.hpp        # Declaration of the Book class
├── book.cpp        # Implementation of the Book class
├── library.hpp     # Declaration of the Library class
├── library.cpp     # Implementation of the Library class
├── main.cpp        # Entry point of the application
├── .gitignore      # Files ignored by Git
└── README.md       # Project documentation
```

### File Description

#### 📄 book.hpp

Contains the declaration of the `Book` class, including its data members and public member functions.

#### 📄 book.cpp

Implements the `Book` class, including the constructor, getters, and operations such as issuing and returning books.

#### 📄 library.hpp

Contains the declaration of the `Library` class, which manages the collection of books.

#### 📄 library.cpp

Implements the core library operations including:

- Add Book
- Remove Book
- Search Book
- Display Books
- Issue Book
- Return Book

#### 📄 main.cpp

Acts as the entry point of the application. It provides a menu-driven interface and interacts with the `Library` class to perform various operations.

---

## ⚙️ How to Build

Compile the project using:

```bash
g++ -std=c++17 -g -Wall -Wextra -Wpedantic main.cpp book.cpp library.cpp -o app
```

---

## ▶️ How to Run

Run the application using:

```bash
./app
```

---

## 🚀 Project Roadmap

### ✅ Completed

- [x] Designed a modular Object-Oriented architecture.
- [x] Implemented the `Book` and `Library` classes.
- [x] Added CRUD operations (Add, Remove, Search, Display).
- [x] Implemented book issue and return functionality.
- [x] Added business rules to prevent duplicate book entries.
- [x] Prevented issued books from being removed.
- [x] Used STL (`std::unordered_map`) for efficient book management.
- [x] Applied Modern C++ concepts such as constructor initialization lists, const correctness, pass-by-reference, and function overloading.
- [x] Separated declarations and implementations using `.hpp` and `.cpp` files.
- [x] Implemented a menu-driven console application.
- [x] Added Git version control.
- [x] Published the project on GitHub.
- [x] Added professional project documentation.

---

### 🔄 Planned Enhancements

- [ ] Persist library data using file handling.
- [ ] Introduce multithreading with proper synchronization (`std::mutex`) to safely handle concurrent book issue/return operations.
- [ ] Replace console output with a configurable logging system.
- [ ] Implement custom exception handling.
- [ ] Add unit tests for core library operations.
- [ ] Integrate Redis for caching frequently accessed data.
- [ ] Integrate Kafka for event-driven notifications.
- [ ] Expose the application through REST APIs.
- [ ] Containerize the project using Docker.

> 🚧 This project is being developed incrementally to learn and demonstrate Modern C++ and backend software engineering concepts. New features will be added over time.

---

## 👨‍💻 Author

**Mohd Shezan Ansari**

Backend Software Engineer

**Interests**

- Modern C++
- Backend Development
- Software Engineering
- 5G Core Networks

---

## ⭐ Support

If you found this project useful, consider giving it a ⭐ on GitHub.