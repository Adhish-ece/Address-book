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
- Contacts are stored in a CSV file called `address.csv`  
- The first line of the file keeps the count of total contacts  
- Each contact record contains: Name, Phone, Email, Location  
- Phone numbers must be 10 digits  
- Gmail IDs must contain `@` and `.com`  
- Duplicate phone numbers or emails are not allowed  
- All data is stored persistently, so it remains even after closing the program  

---

## Compilation & Execution

To run this program, open your terminal or command prompt and navigate to the folder containing `main.c` and `utilis.h`. Compile the program using the command:

```bash
gcc main.c -o addressbook
```
Here, gcc is the GNU C compiler, main.c is the source file, and -o addressbook tells the compiler to create an executable named addressbook.
If the compilation is successful, an executable file will be generated (addressbook on Linux/Mac or addressbook.exe on Windows).

Run the program with the command:
```bash
./addressbook   # Linux/Mac
addressbook.exe # Windows
```

---
When the program runs, a menu will appear:
```bash
===== Address Book (By Adhish) =====
1. Add Contact
2. Search Contact
3. Edit Contact
4. Delete Contact
5. Print All Contact
6. Exit
Enter choice:
```
All data is stored in `address.csv`, which is created automatically if it does not exist.  
Each contact includes Name, Phone, Email, and Location. Phone numbers must be 10 digits, Gmail IDs must contain `@` and `.com`,  
and duplicate entries are not allowed. This ensures that all data remains safe and persistent even after closing the program.

---



