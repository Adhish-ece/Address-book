# Address Book in C

This is a simple **Address Book Management System** written in C.  
It uses **file handling (CSV format)** to store and manage contacts.

---

## Features
- Add a new contact  
- Search contact by phone/email  
- Edit an existing contact  
- Delete a contact  
- Display all contacts  
- Stores contacts in a CSV file  

---

## How It Works
- Contacts are stored in a CSV file (`address.csv`)  
- First line of the file keeps the count of total contacts  
- Each contact record contains: Name, Phone, Email, Location  

---

## Compilation & Execution

To run this program, open your terminal or command prompt and navigate to the folder containing `main.c` and `utilis.h`. Compile the program using the command:

```bash
gcc main.c -o addressbook
```
Here, gcc is the GNU C compiler, main.c is the source file, and -o addressbook tells the compiler to create an executable named addressbook.
If the compilation is successful, an executable file will be generated (addressbook on Linux/Mac or addressbook.exe on Windows).
