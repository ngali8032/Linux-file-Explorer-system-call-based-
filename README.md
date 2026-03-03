📁 Remote File Access System using TCP/IP (Single Client)

🎯 Project Objective

- The main objective of this project was to understand how communication exactly happens between two systems over a network using the TCP/IP protocol.

- We aimed to gain practical knowledge of:

- How a TCP connection is established using the three-way handshake

- How data is transmitted reliably between client and server

- How socket-level communication works internally

- How connection termination and disconnection handling are managed

- In addition to understanding network communication, we extended the project by implementing remote content retrieval using Linux system calls. This allowed the client to:

Navigate directories

List files

Open and read file contents remotely

The server processes client commands received through the recv() function and retrieves file data using Linux system calls such as open(), read(), write(), and close(). After processing the request, the server transmits the response back to the client using the send() function over the established TCP connection.

By combining networking fundamentals with Linux system programming, this project provided hands-on exposure to real-world client–server communication and low-level file handling mechanisms.

🏗 System Architecture

🔹 Server

- The server starts first and waits for incoming client connections.

- It binds to a specific IP address and port number.

- Using socket(), bind(), listen(), and accept(), the server establishes a TCP connection.

- Once a client connects successfully, the server begins processing commands.

🔹 Client

The client connects using the server’s IP address and port number.

TCP connection is established using the standard three-way handshake mechanism:

SYN

SYN-ACK

ACK

After successful connection establishment, an interactive command window is displayed for the user.


💻 Working Flow

The server waits for a client to connect.

The client connects using the correct IP address and port number.

After a successful TCP connection, a command interface is opened.

Navigation begins from the root directory using:

cd /

When the client enters a command:

- The command is sent to the server.

- The server processes the request.

- The server fetches directory or file data.

- The response is sent back to the client.

- The client displays the received output.

The client can:

Change directories using cd <directory_name>

Open and read files using:

open <filename>

The server continues sending file content until reading is complete.

If the user types:

help

A guide is displayed showing all supported commands.

If the user types:

exit

or

quit

The connection is gracefully terminated.

🔄 Connection Handling & Error Management


🔹 Server-Side Technical Issues

- If the server encounters any technical issue such as:

Unexpected crash

Manual termination

Network interruption

The TCP connection will break automatically.

In such cases, the client detects the disconnection and displays:

Server got disconnected.
Connection terminated unexpectedly.


📜 Supported Commands

- cd / → Move to root directory

- cd <directory_name> → Change directory
  
- ls → List directories and files
  
- open <filename> → Read file content

- help → Display command guide

- exit / quit → Terminate connection

🛠 Technologies Used

-C Programming

-Linux Operating System

-TCP/IP Socket Programming

-Linux System Calls 

-Permission and Error Management

🎯 Learning Outcomes

- Through this project, I strengthened my understanding of:

- TCP/IP communication and connection establishment

- Linux file system structure

- Client–server architecture design

- System-level debugging

- Handling connection failures and runtime errors

- Resource management and graceful termination


▶️ Compilation & Execution
Compile:
- gcc server.c root.c -o server
- gcc client.c -o client

Run:

Start the server first:

./server <PORTNO>
Then start the client:

./client <PORTNO> <SERVER_IP_ADDRESS>
After connection is establishing successfully the client and server are involved in communication...


