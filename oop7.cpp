#include<iostream> 
#include<string> 
#include<map> 
using namespace std;

class Map
{
    string name;
    float population;
    public:
    Map ()
    { 
        name="None";
        population=0.0;
    }
    void accept()
    {
        cout<<"\nEnter the name of the state: ";
        cin>>name;
        cout<<"Enter the population of the state (in crores): "; 
        cin>>population;
    }
    void display (map<string, float>::iterator it, int x)
    {
        cout<<"\n\t---------- Record "<<x+1<<"----------";
        cout<<"\n\t\tName of State: "<<it->first;
        cout<<"\n\t\tPopulation : "<<it->second<<" crores\n";
        cout<<"\n\t\tPopulation: "<<it->second<<" crores\n";
        } 
    inline string getname ()
    {
     return name;
    }
    inline float getpopulation()
    {
    return population;
    }
};
int main()
{
    Map obj;
    string s;
    float f;
    map <string, float> mobj;
    map <string, float>::iterator it;
    int i, choice;
    do
    {
        cout<<"\n\n\t*** MENU ***";
        cout<<"\n\tl. Insert Record\n\t2.Delete Record\n\t3. Display Record\n\t4.Exit\n";
        cout<<"\nEnter your choice: ";
        cin>>choice;
        switch (choice)
        {
            case 1: obj.accept();
                    s=obj.getname();
                    f=obj.getpopulation();
                    mobj.insert(pair<string, float>(s, f));
                    cout<<"\n\tRecord Inserted Successfully";
                    break;

            case 2: if(!mobj.empty())
            {
                    cout<<"Enter the state name whose record is to be deleted: ";
                    cin>>s;
                    it=mobj.find(s);
                    if(it!=mobj.end())
                {
                mobj.erase (s);
                cout<<"\n\tRecord of state "<<s<<" has been deleted successfully";
                }
                else
                cout<<"\n\tRecord Not Found!";
            }
            else
            cout<<"\n\tContainer is Empty. Cannot Delete Record.";
            break;

            case 3: if(!mobj.empty())
            {
            cout<<"\n\t\tDisplay of All Records\n";
            for(it=mobj.begin(),i=0;it!=mobj.end(), i<mobj.size(); it++, i++) obj.display(it, i);
            cout<<"\n\nAll Records have been displayed Successfully";
            }
            else
            cout<<"\n\tContainer is Empty. Cannot Display Records.";
            break;

            case 4: break;
            default: cout<<"\n Invalid choice entered. Enter a valid choice!";
        }
    } while(choice!=4);
    cout<<"\n\t\t*** End of Program ***";
    cout<<"\nThank You !";
    return 0;
}


// Certainly! Let's break down the key concepts involved in your C++ code, explaining each step by step:

// ### Object-Oriented Programming (OOP)

// 1. **Class Definition (`Item`)**:
//    - The program defines a class `Item`, which is an OOP concept where a class encapsulates data and functions.
//    - **Data Encapsulation**: The `Item` class encapsulates properties of an item like `name`, `code`, `quantity`, and `cost`.
//    - **Member Functions**: Functions like `accept`, `check`, `getcode`, `getquantity`, `getcost`, and `display` are encapsulated within the `Item` class. They manipulate or provide access to the object's data.

// ### Use of STL (Standard Template Library)

// 2. **Vector**:
//    - The program uses `std::vector`, a dynamic array from the STL, to store `Item` objects. This showcases dynamic memory management and STL container usage.
//    - **Dynamic Size**: Unlike standard arrays, vectors can change size dynamically.

// 3. **Iterators**:
//    - Iterators are used to traverse and manipulate elements in the vector.
//    - **Vector Iterators**: The code uses `vector<Item>::iterator` for iterating over `Item` objects stored in the vector.

// ### Algorithm Library

// 4. **Sorting and Searching**:
//    - The `<algorithm>` header is used for sorting and searching algorithms.
//    - **`sort` Function**: It sorts items in the vector based on different criteria (code, quantity, cost) using comparison functions (`less_code`, `less_quantity`, `less_cost`).
//    - **`find_if` Function**: It searches for an item in the vector based on a condition specified in the `isthere` function.

// ### Global Variables

// 5. **Global Variable (`item_code`)**:
//    - A global variable `item_code` is used to store the item code for searching. The use of global variables is generally discouraged in favor of passing parameters.

// ### Function Pointers and Comparators

// 6. **Comparator Functions**:
//    - Functions like `less_code`, `less_quantity`, and `less_cost` are used to compare two `Item` objects. These functions are passed as arguments to the `sort` function, demonstrating the use of function pointers.

// ### Inline Functions

// 7. **Inline Function (`mesg`)**:
//    - An inline function `mesg` is used for displaying messages. Inline functions can improve performance for small, frequently used functions by reducing the function call overhead.

// ### Program Structure

// 8. **Menu-Driven Interface and Control Flow**:
//    - A `do-while` loop is used to create a menu-driven interface. The user's choice is handled using a `switch` statement.
//    - Each case in the `switch` statement corresponds to a different operation (insert, sort, search, delete, display, exit).

// ### Error Checking and Input Validation

// 9. **Error Checking**:
//    - The code lacks explicit error checking for user inputs, especially for numerical values like `code`, `quantity`, and `cost`. This can lead to issues if the user enters invalid data (like a non-numeric value).

// ### Summary

// The program is a comprehensive demonstration of various C++ features, including OOP, STL containers, iterators, algorithms, function pointers, and basic input/output. It effectively manages a collection of items, showcasing how these features can be used in a real-world application. However, it could be improved with better error handling and avoiding the use of global variables.





// In C++, a `map` is a type of associative container included in the Standard Template Library (STL). It stores elements as key-value pairs and provides efficient access to the value associated with a unique key. Here are some key characteristics and functionalities of a `map`:

// ### Characteristics of `map`

// 1. **Unique Keys**: Each element in a `map` has a unique key. No two elements can have the same key.

// 2. **Ordered**: The elements in a `map` are always sorted by their keys. By default, this ordering is done using the `<` operator on the keys.

// 3. **Direct Access**: A `map` provides direct access to elements using their keys.

// 4. **Dynamic Size**: The size of a `map` can change dynamically as elements are added or removed.

// 5. **Underlying Implementation**: Typically, maps are implemented using self-balancing binary search trees, like Red-Black Trees, providing logarithmic time complexities for common operations.

// ### Common Operations

// - **Insertion**: Adds a new element with a unique key. If the key already exists, the insertion will not take place.
  
//   ```cpp
//   map<int, string> m;
//   m.insert(make_pair(1, "Apple"));
//   ```

// - **Access**: Access the value associated with a specific key. If the key does not exist, it will create a new element with a default value.

//   ```cpp
//   string fruit = m[1];  // Accessing the value with key 1
//   ```

// - **Search**: Checks if an element exists with a given key.

//   ```cpp
//   if (m.find(1) != m.end()) {
//       // Key found
//   }
//   ```

// - **Deletion**: Removes elements from the map.

//   ```cpp
//   m.erase(1);  // Erase the element with key 1
//   ```

// - **Iteration**: Iterators can be used to iterate through all elements of the map.

//   ```cpp
//   for (auto it = m.begin(); it != m.end(); ++it) {
//       cout << it->first << ": " << it->second << endl;
//   }
//   ```

// ### Use Cases

// Maps are particularly useful when you need efficient lookups, insertions, and deletions based on unique keys. They are widely used in situations where the association between unique keys and values is vital, such as databases, caching mechanisms, and various algorithms where rapid access to data based on keys is required.

// ### Summary

// In summary, a `map` in C++ is a powerful and flexible data structure that provides sorted key-value storage with efficient access and modification capabilities. Its ability to automatically sort elements and provide fast lookup times makes it an essential component in the C++ STL for handling complex data-centric operations.