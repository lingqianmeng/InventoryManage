[![Build and Test](https://github.com/lingqianmeng/InventoryManage/actions/workflows/cmake.yml/badge.svg)](https://github.com/lingqianmeng/InventoryManage/actions/workflows/cmake.yml)
# InventoryManage
A lightweight, C++-based Inventory Management System for tracking products, managing stock levels, and organizing warehouse data from the command line. This repository now includes CMake-based build configuration, GoogleTest-powered unit tests, and a GitHub Actions CI workflow that builds and runs tests on each push and PR.

## 📌 Project Overview
InventoryManage is a console-based application that allows users to perform CRUD (Create, Read, Update, Delete) operations on an inventory database. It utilizes a modular C++ architecture to separate core business logic from the user interface.

## ✨ Features
- Item Tracking: Monitor stock levels for various products.
- Modular Core: Logic is abstracted into InventoryManager and InventoryItem classes for high maintainability.
- Search & Filter: Quickly find items within the inventory system.
- Persistent Data: (If applicable) Save and load inventory data to local files.
- CMake-based build for cross-platform development
- Unit tests (GoogleTest) with CI integration
- Continuous Integration: GitHub Actions workflow (.github/workflows/cmake.yml) builds the project and runs the test suite on push/PR.

## 📂 Project structure (high level)
- src/           — application sources and core library
- tests/         — GoogleTest unit tests
- CMakeLists.txt — top-level CMake configuration (pulls GoogleTest via FetchContent)
- .github/workflows/cmake.yml — GitHub Actions CI config

## 🛠 Prerequisites
- CMake >= 3.10 (3.15+ recommended)
- C++ compiler with C++17 support (g++, clang, MSVC)
- Git
- Optional:
- - IDE: VScode

## 🚀 Getting Started
### 1. Clone the Repository
Bash
```
git clone https://github.com/lingqianmeng/InventoryManage.git
cd InventoryManage
```
### 2. Config Build Process with CMake
Bash
```
cmake -S . -B build
```
### 3. Start Build
Bash
```
cmake --build build
```
### 4. Run the application
- On Linux/macOS:
```bash
./build/Debug/InventoryApp
```
- On Windows:
```powershell
./build/Debug/InventoryApp.exe
```

## 🤝 Contributing
Fork the repository.

Create a feature branch (git checkout -b feature/NewFeature).

Commit your changes (git commit -m 'Add some feature').

Push to the branch (git push origin feature/NewFeature).

Open a Pull Request.

## 📄 License
This project is licensed under the MIT License - see the LICENSE file for details.

Author: lingqianmeng

Project Link: https://github.com/lingqianmeng/InventoryManage
