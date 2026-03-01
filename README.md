# Linux-file-Explorer-system-call-based-

📂 Linux Mini File Explorer (Shell-Style | System Call Based)

C | Linux | System Calls | Directory Traversal | File Handling


📌 Project Overview

This project is a shell-style interactive file explorer developed in C using Linux system calls.

The program allows users to navigate directories and open files using commands similar to Linux shell.

It supports:

cd <directory> → Enter directory

open <filename> → Open and read file

<path> → Navigate directly to path

back → Move to parent directory

exit / quit → Terminate program

Invalid input handling

The implementation uses low-level system calls to understand how Linux handles filesystem operations internally.


🧠 Concepts Used

This project demonstrates practical usage of:

opendir()

readdir()

closedir()

open()

read()

close()

File descriptors

String parsing & command handling

Path manipulation

Error handling


⚙️ Supported Commands
📂 Change Directory
cd folder_name

Moves into specified directory if exists.
If not found → prints: 

Invalid directory
📄 Open File
open filename.txt

Uses:

open() to get file descriptor

read() to read content

Displays file content in terminal.

If file not found -> prints:

Invalid file
📁 path:- shows absolute path


Program navigates directly to given path if valid.

⬅ Go Back
back

Moves to parent directory.

❌ Exit Program
exit

or

quit

Terminates the application safely.


🖥 Example Session
Current Path: /home/narendra

> cd Projects
Current Path: /home/narendra/Projects

> open test.txt
Displaying file content...

> back
Current Path: /home/narendra

> exit
Program terminated.

🎯 Key Learning Outcomes

✔ Linux system call usage
✔ File descriptor management
✔ Directory traversal logic
✔ Path parsing and validation
✔ Error handling for invalid inputs
✔ Building mini-shell style applications


🛠 Compile & Run
gcc file_explorer.c
./a.out
