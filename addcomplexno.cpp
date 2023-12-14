#include<iostream>
#include<string>
using namespace std;

class Complex
{
  float real, img;
  public:
    Complex ()
    {
       real=0.0;
       img=0.0;
    }
    Complex operator + (Complex obj)
    {
    Complex temp;
    temp.real=real+obj.real; 
    temp.img=img+obj.img;
    return temp;
    }
    Complex operator *(Complex obj)
    {
    Complex temp;
    temp.real=(real*obj.real) - (img*obj.img);
    temp.img=(real*obj.img)+(img*obj.real);
    return temp;
    }
    friend istream& operator >>(istream&, Complex&);
    friend ostream& operator <<(ostream&, Complex&);
    void display (string ch)
    {
    cout<<"\nThe "<<ch<<" number is: "<<real<<"+"<<img<<"i";
    }
};
istream& operator >>(istream& in, Complex& obj)
{
in>>obj.real;
in>>obj.img;
return in;
}
ostream& operator <<(ostream& out, Complex& obj)
{
 out<<obj.real<<"+"<<obj.img<<"i";
 return out;
}
int main()
{
  float r, i;
  int choice;
  Complex obj1, obj2, result;
  cout<<"\n-----Enter the First number----"<<endl;
  cout<<"\tEnter the real and imaginary part : ";
  cin>>obj1;
  cout<<"\n-----Enter the Second number-----"<<endl; 
  cout<<"\tEnter the real and imaginary part: ";
  cin>>obj2;
  do
  {
   cout<<"\n********* MENU *********"<<endl<<"\tl.Addition of complex numbers\n"; 
   cout<<"\t2.Multiplication of complex numbers\n\t3.Display the result\n\t4.Exit\n"; 
   cout<<"\nEnter your choice: ";
   cin>>choice;
   switch (choice)
   {
    case 1: obj1.display("first"); 
            obj2.display("second"); 
            result=obj1+obj2;
            break;

    case 2: obj1.display("first"); 
            obj2.display("second"); 
            result=obj1*obj2;
            break;
    case 3: cout<<"\nThe result is: "<<result<<endl;
            break;
   }
  }
  while (choice!=4);
  cout<<"Thank You !";
  cout<<"\n\t****** End of Program ******"<<endl;
  return 0;
}








// What is a Constructor?
// A constructor in C++ is a special type of member function that is automatically called when an object of a class is created. It is used to initialize the object's properties. Constructors have the same name as the class and do not have a return type.

// Key Characteristics of Constructors:
// Initialization: Constructors initialize the data members of a class when an object is created.
// Automatic Invocation: They are called automatically when an object is instantiated.
// No Return Type: Unlike regular functions, constructors do not return a value (not even void).
// Can Be Overloaded: Like other functions, constructors can be overloaded (i.e., you can have more than one constructor with different parameters).
// Why is a Default Constructor Needed Here?
// In your Complex class, a default constructor is defined as follows:

// cpp
// Copy code
// Complex ()
// {
//    real=0.0;
//    img=0.0;
// }
// This is a default constructor because it takes no parameters. It initializes the real and img members of a new Complex object to 0.0.

// The Need for the Default Constructor in This Case:
// Initialization: The default constructor ensures that when a Complex object is created without any arguments, its real and img members are set to 0.0. Without this, the members would contain garbage values, leading to unpredictable behavior.
// Explicit Initialization: It provides clarity and intention in the code, showing that the real and img should start at 0.0 unless otherwise specified.
// Use in the Code: In the main function, when you declare Complex obj1, obj2, result;, these objects are instantiated using the default constructor. This is necessary to ensure they start in a valid, known state (with 0.0 values) before any operations are performed on them.
// Good Practice: Even if C++ provides an implicit default constructor, defining your own makes the code more readable and maintainable, and it ensures the object is always initialized as intended.
// In summary, the default constructor in your Complex class is essential for proper initialization and to ensure the class always behaves as expected when new instances are created.
// User
// what is operator overloading and what is need of operator overloading here 
// GPT
// What is Operator Overloading?
// Operator overloading is a feature in C++ that allows programmers to redefine the way operators work for user-defined types (classes). By default, operators like +, -, *, etc., work with fundamental data types (like int, float, double). Operator overloading enables these operators to be used with objects of a class, giving them a specific meaning based on the class's context.

// Key Characteristics of Operator Overloading:
// Custom Behavior for Operators: You can define or redefine the behavior of operators for your class.
// Syntax: The syntax for operator overloading is to define a function, the name of which is the keyword operator followed by the symbol of the operator being overloaded (e.g., operator+).
// Enhances Readability: It allows for more intuitive and readable code, especially when dealing with complex operations or types.
// Why is Operator Overloading Needed in the Complex Class?
// In your Complex class, operator overloading is used to redefine how + and * operators work with Complex objects:

// Overloading the Addition Operator (+):
// cpp
// Copy code
// Complex operator + (Complex obj)
// {
//     Complex temp;
//     temp.real = real + obj.real; 
//     temp.img = img + obj.img;
//     return temp;
// }
// This enables you to add two Complex objects using the + operator in a natural and intuitive way (e.g., obj1 + obj2).
// Without overloading, the + operator would not know how to handle objects of the Complex type, as its default behavior only applies to primitive types like int or double.
// Overloading the Multiplication Operator (*):
// cpp
// Copy code
// Complex operator * (Complex obj)
// {
//     Complex temp;
//     temp.real = (real * obj.real) - (img * obj.img);
//     temp.img = (real * obj.img) + (img * obj.real);
//     return temp;
// }
// Similar to the addition operator, this overloads the * operator to multiply two Complex objects, following the mathematical rules for complex number multiplication.
// It makes the multiplication of complex numbers straightforward and aligns with the expected mathematical notation.
// The Need for Operator Overloading in This Context:
// Mathematical Intuitiveness: In mathematics, complex numbers can be added and multiplied. Operator overloading allows these operations to be expressed in the code as they would be written mathematically.
// Code Clarity: It makes the code involving complex numbers more readable and intuitive. For instance, result = obj1 + obj2; is more understandable than a method call like result = obj1.add(obj2);.
// Seamless Integration: It enables complex numbers to be used more seamlessly with other C++ features and standard algorithms that expect the use of operators.
// In summary, operator overloading in your Complex class provides a natural and intuitive way to perform arithmetic operations on complex numbers, enhancing the clarity and expressiveness of your code.