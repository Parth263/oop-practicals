#include<iostream>
#include<fstream>
#include<string>
#include<limits> // Include for numeric_limits
using namespace std;

class Employee {
    string name, designation;
    int id;
    double salary;

public:
    Employee() {
        name = "None";
        id = 0;
        designation = "None";
        salary = 0;
    }

    void accept(int x) {
        cout << "\n\nEnter the details of Employee No. " << x + 1 << ":";
        cout << "\n\tEnter the Employee Name: ";
        cin >> name;
        cout << "\tEnter the Employee ID: ";
        cin >> id;
        cout << "\tEnter the designation of the Employee: ";
        cin >> designation;
        cout << "\tEnter the salary of the Employee: Rs.";
        while (!(cin >> salary)) {
            cout << "Invalid input. Please enter a numeric value for salary: Rs.";
            cin.clear(); // Clear error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
        }
    }

    void display(int x) {
        cout << "\n\n-------- Details of Employee No. " << x + 1 << " ---------";
        cout << "\n\tName: " << name;
        cout << "\n\tEmployee ID: " << id;
        cout << "\n\tDesignation: " << designation;
        cout << "\n\tSalary: Rs." << salary;
    }
};

int main() {
    int choice, n, i;
    cout << "\t\tWELCOME TO EMPLOYEE DATABASE";
    cout << "\nHow many employee records would you like to enter? ";
    cin >> n;
    Employee obj[n];
    ofstream fout;
    ifstream fin;

    do {
        cout << "\n\n\t\t****** MENU ******";
        cout << "\n\t1.Write Employee Details into File\n\t2.Read Employee Details from File\n\t3.Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                fout.open("Employee Records.dat", ios::out);
                cout << "\nEmployee File has been opened for writing.";
                cout << "\n\tWriting Employee Information to File....";
                for (i = 0; i < n; i++) {
                    obj[i].accept(i);
                    fout.write((char*)&obj[i], sizeof(obj[i]));
                }
                cout << "\nEmployee Information written to File successfully!";
                fout.close();
                cout << "\nEmployee File has been closed.";
                break;

            case 2:
                fin.open("Employee Records.dat", ios::in);
                cout << "\nEmployee File has been opened for reading.";
                cout << "\n\tReading Employee Information from File....";
                for (i = 0; i < n; i++) {
                    fin.read((char*)&obj[i], sizeof(obj[i]));
                    obj[i].display(i);
                }
                cout << "\nEmployee Information read from File successfully!";
                fin.close();
                cout << "\nEmployee File has been closed.";
                break;

            case 3:
                cout << "\n\t-------- EXIT---------";
                break;

            default:
                cout << "\n You have entered an invalid choice. Enter a valid choice!";
        }
    } while (choice != 3);

    cout << "\n*** End of Program ***";
    cout << "\nThank You!";
    return 0;
}



// This C++ program demonstrates a simple employee database system using object-oriented programming, file input/output (I/O), and control structures. Let's break down the code and the concepts behind it:

// ### Class Declaration: `Employee`

// 1. **Class `Employee`**:
//    - This class models an employee with attributes: `name`, `designation`, `id`, and `salary`.
//    - A default constructor initializes these attributes to default values.
//    - The `accept` member function inputs the details of an employee from the user.
//    - The `display` member function outputs the details of an employee.

// ### Main Function and Program Flow

// 2. **Variable Declarations**:
//    - `choice`, `n`, `i` are integer variables for control flow and iteration.
//    - An array of `Employee` objects `obj[n]` is created to store details of `n` employees.
//    - File stream objects `ofstream fout` and `ifstream fin` are created for file writing and reading, respectively.

// 3. **File Operations**:
//    - **Writing to File (Case 1)**:
//      - The file "Employee Records.dat" is opened in write mode (`ios::out`).
//      - The `accept` function is called for each `Employee` object to input details.
//      - Employee details are written to the file using `fout.write()`.
//      - The file is closed using `fout.close()`.
//    - **Reading from File (Case 2)**:
//      - The file "Employee Records.dat" is opened in read mode (`ios::in`).
//      - Employee details are read from the file using `fin.read()`.
//      - The `display` function is called for each `Employee` object to output details.
//      - The file is closed using `fin.close()`.

// 4. **Menu-Driven Interface**:
//    - The `do-while` loop creates a menu-driven interface allowing users to choose actions (write to file, read from file, exit).
//    - The `switch` statement is used to execute the corresponding block of code based on the user's choice.

// ### Concepts Illustrated in the Code

// 1. **Object-Oriented Programming (OOP)**:
//    - **Encapsulation**: The `Employee` class encapsulates employee-related data and methods.
//    - **Objects and Classes**: `Employee` objects are instances of the `Employee` class.

// 2. **File Input/Output**:
//    - The program demonstrates reading from and writing to binary files using `ifstream` and `ofstream`.
//    - The `write()` and `read()` functions are used for binary I/O.

// 3. **Control Structures**:
//    - A `do-while` loop is used for the menu.
//    - A `switch` statement handles the user's choices.
//    - For-loops are used for iterating over employee records.

// 4. **Error Checking**:
//    - The program doesn't include explicit error checking for file I/O operations or input validation, which would be important for robustness.

// 5. **Array of Objects**:
//    - An array of `Employee` objects is used to manage multiple employee records.

// 6. **Direct Memory Manipulation**:
//    - The program uses `(char*) &obj[i]` and `sizeof(obj[i])` for direct memory access to read/write employee objects. This method directly writes the memory representation of objects to a file, which is not always safe or portable.

// ### Summary

// This program is a basic demonstration of creating a simple database application using classes and objects in C++, combined with file I/O for data persistence. It showcases how to manipulate files at a binary level, though care must be taken with this approach due to issues of portability and data structure alignment.



// File handling in C++ involves reading from and writing data to files. It's an essential part of many C++ programs, especially those dealing with data storage, data retrieval, and document processing. C++ provides a robust and flexible set of classes and functions in its Standard Template Library (STL) for handling files.

// Key Concepts in File Handling
// File Streams: C++ uses stream classes to perform file operations. The primary file stream classes are:
// ifstream: For reading from files.
// ofstream: For writing to files.
// fstream: For both reading and writing.
// Opening a File: Before performing any operation (read/write), a file must be opened. In C++, this is typically done using the open() member function of the stream classes. You can also open a file using the constructor of these classes.
// Closing a File: After completing all operations on a file, it should be closed using the close() member function. This is important for resource management and data integrity.
// Reading/Writing Operations: These operations can be performed in two modes:
// Text Mode: The file is treated as a sequence of characters.
// Binary Mode: The file is treated as a sequence of bytes. This mode is used for non-text files like images, audio, etc.
// File Pointers: These are used to control the location in a file from where the data needs to be read or written. The main file pointers are get (for reading) and put (for writing).
// Error Handling: File operations can fail for various reasons (like file not found, access denied, etc.). C++ file streams have member functions (like fail(), eof()) to check the status of file operations.
// Examples of File Handling
// Writing to a File:
// cpp
// Copy code
// ofstream outfile;
// outfile.open("example.txt", ios::out); // Open for writing in text mode
// outfile << "This is a line.\n";
// outfile.close();
// Reading from a File:
// cpp
// Copy code
// ifstream infile;
// infile.open("example.txt", ios::in); // Open for reading in text mode
// string line;
// while (getline(infile, line)) {
//     cout << line << endl;
// }
// infile.close();