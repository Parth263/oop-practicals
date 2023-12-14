#include<iostream>
#include<string>
using namespace std;
class Personal;
class Database
{
     int roll_no;
     string name,class_name,dob,blood_grp,address,tel_no;
     char div;
     double lic_no;
     public:
     static int count;
     Database()
    {
        name="ABC";
        roll_no=0;
        class_name="FE";
        div='A';
    }
    void accept(string name,string class_name,char div,int roll_no)
    {
      count++;
      this->name=name;
      this->class_name=class_name;
      this->div=div;
      this->roll_no=roll_no;
    }
    inline void display()
    {
        cout<<"\n\tName : "<<name;
        cout<<"\n\tClass : "<<class_name;
        cout<<"\n\tDivision : "<<div;
        cout<<"\n\tRoll : "<<roll_no;
    }
    ~Database()
    {
    }
    static int show_count();
    friend class Personal;
};
int Database::count=0;
int Database::show_count()
{
   return count;
}
class Personal
{
  public:
    void initialize(Database *ptr)
    {
       ptr->dob="DD/MM/YYYY";
       ptr->blood_grp="o+ve";
       ptr->address="XYZ area";
       ptr->tel_no="1234567890";
       ptr->lic_no=123456;
    }
    void accept (Database *ptr)
    {
   cout<<"Enter the data of birth of the student :";
   cin>>ptr->dob;
   cout<<"Enter the Blood group of the student :";
   cin>>ptr->blood_grp;
   cout<<"Enter the contact address of the student :";
   cin>>ptr->address;
   bool flag=false ;
   while (flag==false)
   {
   try
   {
   cout<<"Enter Telephone number of the student :";
   cin>>ptr->tel_no;

   if (ptr->tel_no.length() >10 || ptr->tel_no.length() <10)
     throw 1;
   else
     break;
  }
  catch (int x)
    {
    cout<<"\n\t Invalid Number. Enter a valid Contact Number!"<<endl;
    }
  }
    cout<<"Enter the Driving License number of the student :";
    cin>>ptr->lic_no;
  }
  void display (Database *ptr)
  {
    cout<<"\n\tDate of Birth: "<<ptr->dob;
    cout<<"\n\tBlood Group : "<<ptr->blood_grp; 
    cout<<"\n\tAddress :    "<<ptr->address;
    cout<<"\n\tContact Number: "<<ptr->tel_no;
    cout<<"\n\tDriving License No. : "<<ptr->lic_no;
  }
  };
  int main()
  {
    int i, n, choice, perrno;
    string pername, perclass;
    char perdiv;
    Database *ptr=NULL,*temp=0;
    Database objd;
    Personal obj;
    cout<<"**Welcome to our Database**"<<endl;
  do
  {
    cout<<"\n\t*****MENU***\n\n\t1.Enter the records\n\t2.Display  default record\n\t3.Display all recorda\n\t4.Exit"<<endl;
    cout<<"\nEnter your choice: ";
    cin>>choice;

    switch (choice)
    {
      case 1: cout<<"How many records do you want to enter : "; 
      cin>>n;
      ptr=new Database [n];

      for (temp = ptr,i = 0;temp != NULL && i < n; temp++, i++)

      {
        cout<<"\n Details of Student No. "<<i+1;
        cout<<"\nEnter the Name of the student :";
        cin>>pername;
        cout<<"Enter the Class of the student :";
        cin>>perclass;
        cout<<"Enter the Division of the student :";
        cin>>perdiv;
        cout<<"Enter the Roll No. of the student :";
        cin>>perrno;
        temp ->accept (pername, perclass, perdiv, perrno);
        obj.initialize (temp);
        obj.accept(temp);
  }
  break;
  case 2:{
    cout<<"\n--------------default record ----------------"<<endl;
    objd.display();
    Database *it=&objd;
    obj.initialize(it);
    obj.display(it);
    cout<<"\n\n";
    break;
  }
  case 3: cout<<"\nThe Database has total "<< Database::show_count()<<" records";
  for(temp=ptr,i=0;temp!=NULL&&i<n;temp++,i++)
  {cout<<"\n\n-----------Details of student No"<<i+1<<"--------"<<endl;
  temp->display();
  cout<<"\n\n Personal Details :"<<endl;
  obj.display(temp);
  }
  cout<<"\n\n----------END OF RECORDS IN DATABASE------------"<<endl;
  break;
  case 4: delete[] ptr;
          cout<<"\nData in database has been deleted successfully!";
          cout<<"\n******** End Of Program *********";
          cout<<"\nThank You !";
          break;
  default: cout<<"\n You have entered a wrong choice please Enter a valid choice!";
    }
  } while(choice!=4);
  return 0;
}




// Classes and Objects: The code defines two classes - Database and Personal. Objects of these classes represent entities with attributes and behaviors. Database objects hold academic-related data, and Personal objects manage personal details associated with a Database object.
// Dynamic Memory Allocation: The program uses dynamic memory allocation for Database objects (new Database[n]). It allows the program to allocate memory for an array of Database objects at runtime, based on user input.
// Memory Management: The use of new for memory allocation is paired with delete[] to free the allocated memory, demonstrating basic memory management to prevent memory leaks.
// Friend Class: Personal is declared as a friend of Database. This means Personal has access to private and protected members of Database. This is used to modify personal details like date of birth, blood group, etc., in the Database object.
// Static Members: Database contains a static member count which is used to keep track of the number of Database objects created. Static members are shared across all instances of a class.
// Inline Functions: The display function in the Database class is declared inline, suggesting to the compiler to replace the function call with the function code itself to potentially reduce overhead.
// Exception Handling: The program uses basic exception handling (try, catch blocks) to manage errors, such as when a user enters an invalid telephone number.
// Pointers and Pointer Arithmetic: The program uses pointers (Database *ptr, *temp) and pointer arithmetic to iterate through an array of Database objects.

// In C++, destructors play a critical role in the management of dynamic memory. When objects are created using the new keyword, they must be destroyed using delete to free the memory. The destructor is called when delete is used, allowing the program to clean up resources associated with the object.

// Example:
// cpp
// Copy code
// class Example {
// public:
//     Example() {
//         // Constructor: Code to initialize an object
//     }
//     ~Example() {
//         // Destructor: Code to release resources, clean up
//     }
// };

// int main() {
//     Example* obj = new Example(); // Constructor called
//     // ... use obj ...
//     delete obj; // Destructor called
//     return 0;
// }
// In this example, when obj is deleted, the destructor ~Example() is called to perform cleanup.

// Importance:
// Destructors are particularly important in resource management and avoiding memory leaks in languages like C++, where the programmer is responsible for manual memory management. They ensure that resources are properly released when an object is no longer needed.



// Sure, let's break down the flow of this C++ program in a simple and understandable way. The program is designed to maintain a database of student records, encompassing both academic and personal information.

// ### Overview of Classes:
// 1. **`Database` Class**: Manages academic information of students (like name, class, division, roll number).
// 2. **`Personal` Class**: Manages personal details of students (like date of birth, blood group, address, telephone number, driving license number).

// ### Flow of the Program:

// #### 1. Program Starts
// - The program begins execution in the `main` function.

// #### 2. Menu Display
// - The user is presented with a menu of options:
//   1. Enter the records
//   2. Display default record
//   3. Display all records
//   4. Exit

// #### 3. Processing User Choices
// - Based on the user's input, the program follows different paths:

//    **Case 1: Enter Records**
//    - The user specifies how many student records to enter.
//    - The program dynamically allocates an array of `Database` objects for storing these records.
//    - For each student:
//      - Academic details are entered and stored in a `Database` object.
//      - The `Personal` object initializes and accepts personal details for the student.
//    - The process repeats for the number of records specified.

//    **Case 2: Display Default Record**
//    - The program displays the default academic details of a `Database` object (created as `objd`).
//    - It then displays the default personal details, which are initialized but not user-entered.

//    **Case 3: Display All Records**
//    - The program goes through all entered student records.
//    - For each student, both academic and personal details are displayed.
//    - This is done by iterating over the array of `Database` objects and using both `Database` and `Personal` methods.

//    **Case 4: Exit and Cleanup**
//    - The dynamically allocated memory for student records is released using `delete[]`.
//    - The program exits the loop and then terminates.

// #### 4. Looping the Menu
// - The menu keeps appearing after each operation until the user chooses to exit (Case 4).

// ### Important Concepts Utilized:
// - **Dynamic Memory Allocation**: Using `new` and `delete[]` for managing arrays of objects.
// - **Class Friendship**: `Personal` class can access private members of `Database` due to being declared a friend.
// - **Inline Functions**: `display` function in `Database` class is an inline function.
// - **Static Members**: `count` in `Database` class is a static member to keep track of the number of records.
// - **Menu-Driven Interface**: Allows user interaction for various functionalities.
// - **Pointers and Pointer Arithmetic**: Used for accessing and iterating through arrays of objects.
// - **Exception Handling**: Basic try-catch blocks for error handling in telephone number input.

// ### Simplified Explanation:
// Imagine you have a digital filing cabinet (the program) to keep records of students. Each file has two parts: one for school-related information (like name and class) and another for personal information (like address and phone number).

// When you start, you get options like adding new files, looking at a sample file, seeing all files, or closing the cabinet. If you add files, you’ll fill in details for each student, and then the cabinet saves it. You can also look at all the information you’ve saved whenever you want. When you’re done, you close the cabinet, and it keeps everything safe for next time.