InventoryManage
A lightweight, C++ based Inventory Management System designed to track products, manage stock levels, and organize warehouse data efficiently.

📌 Project Overview
InventoryManage is a console-based application that allows users to perform CRUD (Create, Read, Update, Delete) operations on an inventory database. It utilizes a modular C++ architecture to separate core business logic from the user interface.

✨ Features
Item Tracking: Monitor stock levels for various products.

Modular Core: Logic is abstracted into InventoryManager and InventoryItem classes for high maintainability.

Search & Filter: Quickly find items within the inventory system.

Persistent Data: (If applicable) Save and load inventory data to local files.

📂 Project Structure
Following a standard C++ repository layout:

🛠 Prerequisites
Compiler: GCC/G++ (MinGW-w64 recommended for Windows)

C++ Standard: C++17 or higher

IDE: VSCode

🚀 Getting Started
1. Clone the Repository
Bash

git clone https://github.com/lingqianmeng/InventoryManage.git
cd InventoryManage
2. Compilation
To compile the project using g++ from the root directory:

Bash

g++ -std=c++17 src/main.cpp src/core/*.cpp -Isrc/core -o bin/InventoryManage
3. Running the App
Bash

./bin/InventoryManage
⚙️ VS Code Configuration
If you are using Visual Studio Code, ensure your tasks.json includes the src/core directory:

Include Path: -I${workspaceFolder}/src/core

Source Files: ${workspaceFolder}/src/*.cpp and ${workspaceFolder}/src/core/*.cpp

🤝 Contributing
Fork the repository.

Create a feature branch (git checkout -b feature/NewFeature).

Commit your changes (git commit -m 'Add some feature').

Push to the branch (git push origin feature/NewFeature).

Open a Pull Request.

📄 License
This project is licensed under the MIT License - see the LICENSE file for details.

Author: lingqianmeng

Project Link: https://github.com/lingqianmeng/InventoryManage
