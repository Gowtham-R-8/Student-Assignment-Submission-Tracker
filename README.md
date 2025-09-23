# 📘 Student Assignment Submission Tracker – C Program

## 🎯 Objective

To develop a **Singly Linked List-based system** in C for tracking **assignment submissions** of students.

## 🗃️ Data Fields

Each submission record includes:
- `Student ID` *(int)*
- `Assignment Title` *(string)*
- `Submission Date` *(string - DD-MM-YYYY)*
- `Status` *(string - "Submitted" or "Pending")*

## 🛠️ Features

| Feature | Description |
|--------|-------------|
| ➕ Add Submission | Add a new assignment record |
| 🔄 Update Status | Update "Submitted" or "Pending" for a record |
| 🔍 Search by Student ID | View all submissions by a specific student |
| 📋 Display All Records | Show the complete submission history |
| ❌ Exit | Exit and free memory |

## 💻 How It Works

- Uses a **singly linked list** where each node is a submission record.
- Simple CLI-based menu.
- All memory is cleaned up before exit.

## 🧪 Compilation & Execution

```bash
gcc assignment_tracker.c -o assignment_tracker
./assignment_tracker


--- Student Assignment Submission Tracker ---
1. Add Submission Record
2. Update Submission Status
3. Search by Student ID
4. Display All Records
5. Exit
