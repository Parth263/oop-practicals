#include<iostream>
#include<string>

using namespace std;
class Publication
{
    string name;
    float price;
    public:
        Publication ()
        {
        name="None";
        price=0.0;
        }
        void getdata (string s)
        {
            cout<<"\nEnter the name of the "<<s<<" : ";
            cin>>name;
            bool flag=false;
            while (flag==false)
            {
                cout<<"Enter the price of the "<<s<<" : Rs.";
                cin>>price;
                try
                {
                    if (price<=0)
                      throw price;
                    else
                      flag=true;
                }
                catch (float x)
                {
                    price=0.0;
                    cout<<"\nYou have entered price to be "<<x<<" which is an invalid search input."; 
                    cout<<"\nValue of Price has been set to "<<price;
                    cout<<"\nPlease enter a valid input!"<<endl;
                }
            }
        }
        inline string getname()
        {
            return name;
        }
        inline float getprice()
        {
            return price;
        }
        ~Publication ()
        {
        }
};
class Book: public Publication
{
    int pages;
    public:
        Book ()
        {
          pages=0;
        }
        void getpages()
        {
            bool flag=false; 
            while (flag==false)
            {
                cout<<"Enter the number of pages in the book: "; 
                cin>>pages;
                try
                {
                if (pages<-0)
                    throw pages;
                else
                    flag=true;
                }
                catch (int x)
                {
                  pages=0;
                  cout<<"\nYou have entered number of pages to be "<<x<<" which is an invalid search input."; 
                  cout<<"\nValue of Number of Pages has been set to "<<pages;
                  cout<<"\nPlease enter a valid input!"<<endl;
                }
            }
        }
        void display()
        {
            cout<<"\tBook Found !"<<endl;
            cout<<"\n\t Details of Book \n";
            cout<<"\n\tName of the Book: "<<getname();
            cout<<"\n\tNumber of pages : "<<pages;
            cout<<"\n\tPrice: Rs."<<getprice () <<"/-";
        }
        ~Book ()
        {
        }
};
class Tape:public Publication
{
   float time;
   public:
      Tape ()
      {
         time=0.0;
      } 
      void gettime ()
      {
        bool flag=false;
        while(flag==false)
        {
            cout<<"Enter the playing time of the tape (in minn) :";
            cin>>time;
            try
            {
                if (time<=0)
                   throw time;
                else
                   flag=true;
            }
            catch (float x)
            {
                time=0.0;
                cout<<"\nYou have entered the playing time of audio cassette to be "<<x<<" mins which is an invalid search input." ;
                cout<<"\nValue of Playing Time has been set to "<<time;
                cout<<"\nPlease enter a valid input!";
            }
        }
      }
      void display()
      {
        cout<<"\tAudio Cassette Found "<<endl;
        cout<<"\n\t -------- Details of Audio Cassette --------\n";
        cout<<"\n\tName of the Tape : "<<getname(); 
        cout<<"\n\tPlaying time :"<<time<<" mins";
        cout<<"\n\tPrice: Rs."<<getprice() <<"/-";
      }
      ~Tape ()
      {
      }
};
int main()
{
    int choice;
    string n;
    Book objb;
    Tape objt;
    cout<<"\t\tWELCOME TO OUR COMPANY'S MARKETING SITE\n"<<endl;
    do
    {
        cout<<"\n\t*** Menu ***\n";
        cout<<"\tl.Search for a Book\n\t2. Search for an Audio Cassette \n\t3.Display Book Details";
        cout<<"\n\t4.Display Audio Cassette Details\n\t5.Exit\n";
        cout<<"\nEnter your choice: ";
        cin>>choice;

        switch (choice)
        {
        case 1: objb.getdata("book");
                objb.getpages ();
                cout<<"\n Book is being Searched ..."<<endl;
                break;

        case 2: objt.getdata ("audio cassette"); 
                objt.gettime(); 
                cout<<"\n Audio Cassette is being Searched....."<<endl;
                break;
        case 3: try
                {
                if (objb.getname()=="None")
                    throw 3;
                else
                {
                    objb.display();
                    cout<<"\n We hope you will purchase the book from our Company store soon!"<<endl;
                }
                }
                catch (int x)
                {
                    cout<<"\nNo Book has been searched yet."<<endl;
                    cout<<"Choose correct option !"<<endl;
                }
                break;
        case 4: try
                {
                if (objt.getname()=="None")
                throw 4;
                else
                {
                    objt.display();
                    cout<<"\n We hope you will purchase the audio cassette from our Company store soon!"<<endl;
                }
                }
                catch (int x)
                {
                    cout<<"\nNo Audio Cassette has been searched yet."<<endl;
                    cout<<"Choose correct option !"<<endl;
                }
                break;
        case 5: cout<<"\n->->> Visit Again <<<";
                break;
        }
    } 
    while (choice!=5);
    cout<<"\n\t*** End of Program ***";
    cout<<"\nThank You!";
    return 0;
}







// Certainly! This C++ program is a good example of object-oriented programming, demonstrating concepts like inheritance, polymorphism, exception handling, and more. Let's break it down step by step:

// ### Class Declaration and Inheritance

// 1. **Class `Publication`**: This is a base class that represents a general publication. It contains:
//    - Private members: `string name` and `float price` for storing the publication's name and price.
//    - A default constructor that initializes `name` to "None" and `price` to 0.0.
//    - The `getdata` member function, which is used to input the name and price of the publication. It uses exception handling to ensure the price is positive.
//    - Inline member functions `getname` and `getprice` to return the publication's name and price.
//    - A destructor, which is currently empty.

// 2. **Class `Book` (Inherits from `Publication`)**: This class represents a book. It includes:
//    - An integer member `pages` for storing the number of pages.
//    - A default constructor that initializes `pages` to 0.
//    - The `getpages` member function, which inputs the number of pages and uses exception handling to ensure it's a valid number.
//    - The `display` member function to output the details of the book.
//    - A destructor, which is also currently empty.

// 3. **Class `Tape` (Inherits from `Publication`)**: This class represents an audio cassette. It contains:
//    - A float member `time` for storing the playing time.
//    - A default constructor initializing `time` to 0.0.
//    - The `gettime` member function, which inputs the playing time and uses exception handling similar to `getpages`.
//    - The `display` member function to output the details of the tape.
//    - A destructor, which is again empty.

// ### Main Function

// 4. **Menu-Driven Interface**:
//    - The `main` function offers a menu-driven interface for the user to interact with books and audio cassettes.
//    - It creates instances of `Book` (`objb`) and `Tape` (`objt`).
//    - The user is prompted to choose an action from the menu.
//    - Based on the user's choice, appropriate actions are taken (like searching for a book or an audio cassette, displaying their details, etc.).
//    - Exception handling is used to ensure that details are displayed only if the book or tape has been searched for.

// ### Exception Handling

// 5. **Exception Handling**:
//    - In both `getdata` functions (for `Book` and `Tape`), exceptions are thrown and caught within the same function to handle invalid price or playing time.
//    - In the `display` section of the menu, exceptions are used to ensure that details are displayed only if the respective item has been initialized.

// ### OOP Concepts Illustrated

// - **Inheritance**: `Book` and `Tape` inherit from `Publication`. This demonstrates the "is-a" relationship and promotes code reusability.
  
// - **Polymorphism**: Not directly implemented, but the program has potential for it. If `display` was a virtual function in `Publication`, it could be an example of polymorphism.

// - **Encapsulation**: Data members are kept private within classes, and member functions are used to interact with this data.

// - **Abstraction**: The classes provide a simplified interface for complex underlying code that handles books and tapes.

// - **Exception Handling**: Used to manage runtime errors elegantly, ensuring the program remains robust and stable.

// ### Summary

// The program is an example of a basic database system for a bookstore or library, capable of handling books and audio cassettes. It illustrates fundamental OOP concepts, particularly inheritance and encapsulation, and also includes basic error handling for user inputs.