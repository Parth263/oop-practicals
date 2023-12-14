#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int item_code;
class Item
{
    string name;
    int code, quantity;
    double cost;
    public:
        Item()
        {
            name="None";
            code=0;
            quantity=0;
            cost=0.01;

        }
        void accept ()
        {
            cout<<"\nEnter the Item Details ";
            cout<<"\n\tName of Item: "; 
            cin>>name;
            cout<<"\tCode of Item : #";
            cin>>code;
            cout<<"\tTotal quantity of Item: ";
            cin>>quantity;
            cout<<"\tCost of Item: Rs.";
            cin>>cost;
        }
        bool check(vector<Item>::iterator it, int x)
        {
            if(it->code==x) 
                return true; 
            else
                return false; 
        }
        int getcode ()
        {
            return code;
        }
        int getquantity()
        {
            return quantity;
        }
        double getcost ()
        {
            return cost;
        }
        void display (vector<Item>::iterator it)

        {
        cout<<"\n\n\t----- Details of Item #"<<it->code<<"---------";
        cout<<"\n\tItem Name: "<<it->name;
        cout<<"\n\tItem Code: "<<it->code;
        cout<<"\n\tItem Cost: Rs."<<it->cost<<"/-";
        cout<<"\n\tItem Quantity: "<<it->quantity;
        } 
        inline void mesg (string s)
        {
        cout<<"\nAll records have been sorted by "<<s;
        }
};
bool less_code(Item obj1, Item obj2)
{
    // Check if obj1's code is less than obj2's code
    return (obj1.getcode () <obj2.getcode ());
}
bool less_quantity (Item obj1, Item obj2)
{
    return (obj1.getquantity()<obj2.getquantity());
}
bool less_cost (Item obj1, Item obj2)
{
 return (obj1.getcost() <obj2.getcost());
}
bool isthere (Item obj)
{
if (obj.getcode()==item_code) 
    return true;
 else 
    return false;
}
int main()
{
    Item obj;
    vector <Item> v;
    vector <Item>::iterator it, it2;
    int choice,i,n;
    do
    {
        cout<<"\n\n\t\t*** MENU***";
        cout<<"\n\tl.Insert Item Record\n\t2.Sort Item Records\n\t3.Search Item Record\n\t4.Delete Item Record";
        cout<<"\n\t5.Display all Item Record\n\ts.Exit\n";
        cout<<"\nEnter your choice: ";
        cin>>choice;
        switch (choice)
        {
            case 1: obj.accept();
                    v.push_back (obj);
                    cout<<"\nItem Record inserted successfully !";
            break;

            case 2: int ch;
            cout<<"\n\n\tSort by :\n\t\tl.Item Code\n\t\t2.Item Quantity\n\t\t3.Item Cost\n"; 
            cout<<"\nEnter your choice: ";
            cin>>ch;
            switch(ch)
            {
            case 1: sort(v.begin(), v.end(),less_code);
                    obj.mesg("Item Code") ;
                    break;
            case 2: sort(v.begin(), v.end(),less_quantity);
                    obj.mesg("Item Quantity");
                    break;
            case 3: sort(v.begin(), v.end(),less_cost);
                    obj.mesg("Item Cost"); 
                    break;
            default: cout<<"\nInvalid option selected. Select a valid option !";
            }
            break;

            case 3: cout<<"\nEnter the Item Code of the Item to be searched =";
            cin>>item_code;
            it=find_if(v.begin(), v.end(), isthere);
            if(it!=v.end())
            {
            cout<<"\nItem with Item code "<<item_code<<" found in the Records at position "<<(it-v.begin())+1;
            obj.display(it);
            }
            else
            cout<<"\nItem with Item code "<<item_code<<" not found in the Records.";
            break;
            case 4:{
                int x ;
                bool flag=false;
                cout<<"\nEnter the Item Code you would like to delete";
                cin>>x;
                for(it=v.begin(),i=0;it!=v.end(),i<=v.size();it++, i++)
                {
                if (obj.check(it,x)) 
                {
                    v.erase (v.begin()+i);
                    flag=true;
                    break;
                }
                }
                if(flag==true)
                cout<<"\nItem with Item Code "<<x<<" has been deleted successfully";
                else
                cout<<"\nItem with Item Code "<<x<<" does not exist in the Records.";
                break;
            }
            case 5:
            for(it=v.begin(); it!=v.end();it++)
            obj.display(it);
            cout<<"\nAll the Item Records have been displayed successfully";
            break;
            case 6: break;
            default: cout<<"\nInvalid option selected. Enter a valid choice!";
        }
    }
    while(choice!=6);
    cout<<"\n\t\t*** End of Program ***";
    cout<<"\nThank You!";
    return 0;
};




// In the `check` function within the `Item` class, `vector<Item>::iterator it` and `int x` are the parameters. This function is designed to check whether the item pointed to by the iterator `it` has the same code as the integer `x`. Let's break it down for clarity:

// ### Vector

// 1. **What is a Vector?**
//    - In C++, a vector is a dynamic array that can grow or shrink in size. It's part of the Standard Template Library (STL) and is used to store a collection of objects. In this case, the vector stores objects of the `Item` class.

// 2. **Why Use Vectors?**
//    - Vectors are used here because they provide flexibility in managing a collection of `Item` objects. They allow easy addition (with `push_back`) and removal (with `erase`) of elements and can dynamically adjust their size as needed.

// ### Vector Iterator

// 1. **What is an Iterator?**
//    - An iterator is like a pointer that points to elements in a container like a vector. It's used to iterate through the elements of the vector, accessing or modifying them.

// 2. **Role in `check` Function**
//    - The iterator `it` is used to point to a specific `Item` object within the vector. The `check` function uses this iterator to access the `Item` object it points to.

// ### Function Role

// - **Purpose**: The function `check` is designed to compare the code of the `Item` object pointed to by `it` with the given code `x`.
// - **How It Works**: 
//   - If the code of the item equals `x`, the function returns `true`, indicating a match.
//   - If not, it returns `false`.

// ### Usage in the Program

// - In the `main` function, particularly in the case for deleting an item (case 4), this `check` function is used to find the specific item in the vector that matches the provided code. Once found, that item can be deleted from the vector.

// ### Example:

// Imagine you have a list of items, and you're looking for one with a specific code. The `check` function is like asking, "Is this the item I'm looking for?" as you go through each item in the list (`vector`). If you find the right item (the codes match), you confirm it's the one you're looking for.




// This C++ program is a simple inventory management system that allows a user to insert, sort, search, delete, and display item records. It uses object-oriented programming concepts like classes, objects, and iterators. Let's break down the code and explain its key components and concepts:

// ### Class Definition: `Item`
// - **Attributes**: `name`, `code`, `quantity`, `cost` (private)
// - **Constructor**: Initializes an `Item` object with default values.
// - **Member Functions**:
//     - `accept()`: Accepts details of an item from the user.
//     - `check(vector<Item>::iterator it, int x)`: Checks if the current item matches a given code.
//     - `getcode()`, `getquantity()`, `getcost()`: Accessors for item code, quantity, and cost.
//     - `display(vector<Item>::iterator it)`: Displays details of an item.
//     - `mesg(string s)`: Prints a message after sorting.

// ### Sorting Functions
// - `less_code`, `less_quantity`, `less_cost`: These functions are used for sorting based on different criteria (code, quantity, cost).

// ### Global Variable
// - `item_code`: Used for searching items by code.

// ### Main Function
// 1. **Variable Declarations**: Variables for the item (`obj`), a vector of items (`v`), iterators, and user choices.
// 2. **Menu Driven Loop**: Repeats until the user chooses to exit (option 6).
// 3. **Switch Case**:
//     - **Case 1** (Insert Record): Adds a new item to the vector `v`.
//     - **Case 2** (Sort Records): Sorts the records based on user's choice of criteria.
//     - **Case 3** (Search Record): Searches for an item by code.
//     - **Case 4** (Delete Record): Deletes an item by code.
//     - **Case 5** (Display Records): Displays all item records.
//     - **Case 6**: Exits the program.

// ### Key Concepts:
// - **Object-Oriented Programming (OOP)**: The program uses classes and objects (Item class) to represent and manage data.
// - **STL Vectors**: It uses `vector` from the Standard Template Library (STL) to store and manage collections of items.
// - **Iterators**: Used to iterate over the vector of items.
// - **Function Pointers**: In sorting, function pointers are passed to the `sort` function to define sorting criteria.
// - **Menu-Driven Program**: Allows user interaction and operation choices through a menu.

// ### Easy Explanation:
// Imagine a store where you keep a list of items. Each item has a name, a code, a quantity, and a cost. In this program, you can:
// - **Add new items**: Enter details like name, code, etc.
// - **Arrange items**: Sort them by code, quantity, or cost.
// - **Look for a specific item**: Search for an item using its code.
// - **Remove an item**: Delete an item from the list.
// - **See all items**: Display all items and their details.

// It's like a digital notebook for keeping track of store items. You can add new notes (items), organize them, find a specific note, delete a note, or look at all the notes you've made.