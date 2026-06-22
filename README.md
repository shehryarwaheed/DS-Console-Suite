🧩 DS-Console-Suite
A collection of three C++ console applications, each built from scratch using custom data structures (linked lists, doubly linked lists, queues, and stacks) instead of STL containers.

Developed by:

* L24-3023 Muhammad Shehryar Waheed

📦 Projects in this Repo

1. 📝 Notepad — a console-based text editor built on a custom doubly linked list, with cursor navigation, undo support, and file save/load.
2. 📊 sh Excel — a spreadsheet-style grid application built with SFML, using a custom doubly linked grid structure for cells (supports selection, sum/average, and multi-cell editing).
3. ⚙️ Process Manager — a CPU scheduling simulator built with custom queue and stack classes, supporting priority scheduling, round-robin time slicing, task killing, and task restoration.

🛠️ Prerequisites
Before running these projects, make sure you have the following installed:

* [Visual Studio Community](https://visualstudio.microsoft.com/vs/community/) (2019 or later)
* Windows OS (x64) — all three projects use `<windows.h>` / `<conio.h>`
* [SFML 2.x](https://www.sfml-dev.org/download.php) — required ONLY for the sh Excel project

🚀 How to Run Locally

Step 1 — Clone the Repository

⚠️ This repo is read-only. You can only fetch/clone the code, not push changes.

```
git clone https://github.com/shehryarwaheed/DS-Console-Suite.git
```

Or download the ZIP directly from the green Code button above.

Step 2 — Open the Project You Want to Run
Each project lives in its own folder. Open the relevant `.cpp` file in a new Visual Studio C++ Console Application project (or your own `.sln`), then build and run.

📝 Running Notepad

1. Create a new **Empty C++ Console App** project in Visual Studio.
2. Add `notepad/Notepad.cpp` to the project.
3. Set configuration to **Debug | x64**.
4. Press **F5** or click the green ▶ Start button.
5. Use arrow keys to move the cursor, type to insert text, **Backspace** to delete, **Ctrl+Z** to undo, **Ctrl+S** to save, and **Esc** to exit.

📊 Running sh Excel

This project needs SFML set up first.

1. Download SFML 2.x from [sfml-dev.org](https://www.sfml-dev.org/download.php)
2. Extract it to a folder (e.g. `C:\SFML`)
3. Open Visual Studio → go to your project properties:
   * C/C++ → General → Additional Include Directories → Add `C:\SFML\include`
   * Linker → General → Additional Library Directories → Add `C:\SFML\lib`
   * Linker → Input → Additional Dependencies → Add:

```
sfml-graphics-d.lib
sfml-window-d.lib
sfml-system-d.lib
sfml-audio-d.lib
```

4. Copy all `.dll` files from `C:\SFML\bin` into your project's `x64\Debug\` folder.
5. Add `sh-excel/sh_Excel.cpp` to a new C++ console/Win32 project, along with a `font\` and `images\` folder containing the required font and background assets (`bbhsansbogle-regular.ttf`, `robotocondensed-regular.ttf`, `back2.png`).
6. Set configuration to **Debug | x64** and press **F5**.
7. Click cells to select them, double-click or press **Enter** to edit, hold **Ctrl** to multi-select, and use **Alt+N** to select cells by name.

⚙️ Running Process Manager

1. Create a new **Empty C++ Console App** project in Visual Studio.
2. Add `process-manager/Process_manager.cpp` to the project.
3. Set configuration to **Debug | x64**.
4. Press **F5** or click the green ▶ Start button.
5. The ready queue of tasks loads automatically. Choose to kill, restore, or run tasks via round-robin scheduling with priority reordering until the queue empties.

📁 Project Structure

```
DS-Console-Suite/
├── notepad/
│   └── Notepad.cpp            # Console text editor (doubly linked list)
├── sh-excel/
│   └── sh_Excel.cpp           # SFML spreadsheet grid app
├── process-manager/
│   └── Process_manager.cpp    # CPU scheduling simulator (queue + stack)
└── README.md
```

🔒 Contributing & Permissions
This repository is view/clone only.

* ✅ You can clone or download the code
* ✅ You can run it locally
* ❌ You cannot push changes to this repository
* ❌ Pull requests are not accepted

If you'd like to suggest something, open an Issue — but changes to the codebase are managed solely by the original author.

📄 License
This project is for educational purposes only. All rights reserved by the original author.
