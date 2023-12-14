#include<iostream> 
using namespace std;

template<typename T>
void display (T arr[], int n)
{
    for (int i=0;i<n;i++)
      cout<<arr[i]<<"\t";
}
template<typename T>
void selectionsort(T arr[], int no)
{
    int i,j,n=no;
    T temp;
    cout<<"\nThe array before performing Selection Sort: \t";
    display (arr,n);
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if (arr[j]<arr[i])
            {
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            arr[j]=temp;
            }
          
        }
    }
    cout<<"\nThe array after performing Selection Sort: \t";
    display (arr,n);
}
int main()
{
    int i,n;
    cout<<"\n------- SELECTION SORT FOR INTEGER ARRAY ---------"<<endl;
    cout<<"\n\tEnter the total numbers in the array: ";
    cin>>n;
    int arr1 [n];
    cout<<"\n";
    for(i=0;i<n;i++)
    {
        cout<<"Enter the number in array at position ["<<i<<"]";
        cin>>arr1[i];
    }
    selectionsort (arr1,n);
    cout<<"\n\n------ SELECTION SORT FOR FLOAT ARRAY ------"<<endl;
    cout<<"\n\tEnter the total numbers in the array: "; 
    cin>>n;
    float arr2[n];
    cout<<"\n";
    for(i=0;i<n;i++)
    {
    cout<<"Enter the number in array at position ["<<i<<"]: ";
    cin>>arr2[i];
    }
    selectionsort (arr2, n);
    return 0;
};










// In C++, a template is a powerful and flexible feature that allows you to define generic classes or functions. Templates enable the creation of code that can work with any data type, making it possible to write more general, reusable code.

// ### Types of Templates in C++

// 1. **Function Templates**: These are used to create functions that can work with any data type. You write a single function template, and it can be used with different data types without rewriting the entire function for each type.

// 2. **Class Templates**: Similar to function templates, but used for classes. A single class template can work with different data types, allowing for the creation of a class that can handle various types without multiple class definitions.

// ### How Templates Work

// Templates work by substituting the template parameters with actual data types. When you call a function template or instantiate a class template with a specific type, the compiler generates a new version of the function or class for that data type.

// ### Example of a Function Template

// Here’s a simple example of a function template in C++:

// ```cpp
// template <typename T>
// T add(T a, T b) {
//     return a + b;
// }
// ```

// In this example, `template <typename T>` declares a template with a type parameter `T`. The `add` function can now add two variables of any type (`int`, `float`, `double`, etc.) as long as they are of the same type.

// ### Example of a Class Template

// Here’s an example of a class template in C++:

// ```cpp
// template <typename T>
// class Array {
// private:
//     T* arr;
//     int size;
// public:
//     Array(T arr[], int s);
//     void print();
// };

// template <typename T>
// Array<T>::Array(T arr[], int s) {
//     size = s;
//     this->arr = new T[size];
//     for (int i = 0; i < size; i++) {
//         this->arr[i] = arr[i];
//     }
// }


// ### Advantages of Using Templates

// 1. **Code Reusy**: Write code once and use it with different data types.
// 2. **Type Safety**: Templates are type-safe, meaning errors related to type mismatches are caught at compile time, not at runtime.
// 3. **Flexibility**: Templates can be used to create highly flexible and reusable code components.

// ### Summary

// Templates in C++ are a abilitmechanism for writing generic, type-independent code. They are a cornerstone of C++'s support for generic programming, allowing developers to write more flexible and reusable code.

// Code Analysis with Snippets
// Template Function for Displaying Arrays
// cpp
// Copy code
// template<typename T>
// void display(T arr[], int n) {
//     for (int i = 0; i < n; i++)
//         cout << arr[i] << "\t";
// }
// This is a generic function to display any type of array.
// template<typename T> declares a template with a type parameter T.
// T arr[] and int n are parameters for the array and its size, respectively.
// The function iterates over the array and prints each element.
// Template Function for Selection Sort
// cpp
// Copy code
// template<typename T>
// void selectionsort(T arr[], int no) {
//     int i, j, n = no;
//     T temp;
//     for (i = 0; i < n - 1; i++) {
//         for (j = i + 1; j < n; j++) {
//             if (arr[j] < arr[i]) {
//                 temp = arr[i];
//                 arr[i] = arr[j];
//                 arr[j] = temp;
//             }
//         }
//     }
// }
// This function sorts an array using the selection sort algorithm.
// The nested for loops are used to iterate through the array.
// It compares each element (arr[i]) with every other element in the unsorted part of the array (arr[j]).
// If a smaller element is found, it swaps that element with the current element.
// Main Function for Demonstrating the Sort with Integers and Floats
// cpp
// Copy code
// int main() {
//     // Code to input integer array and sort it
//     // Code to input float array and sort it
// }
// The main function demonstrates the use of the selectionsort template with both integer and float arrays.
// It prompts the user to enter the number of elements and the elements themselves, then calls the selectionsort function.
// Selection Sort Algorithm Explained
// Selection sort is a simple comparison-based sorting algorithm with the following steps:

// Initial Setup: Start with the first element of the array.
// Finding the Minimum:
// From the current position, iterate through the unsorted portion of the array to find the smallest (or largest for descending order) element.
// Swapping:
// Swap this smallest element found with the element at the current position. After the swap, the element at the current position is in its final sorted position.
// Move to Next Element:
// Move to the next element and repeat the process until the entire array is sorted.
// Time Complexity:
// The time complexity of selection sort is O(n²), where n is the number of elements. This is because it uses two nested loops: the outer loop runs n times and the inner loop runs n times in the worst case.
// Efficiency:
// Selection sort is not efficient for large lists compared to more advanced algorithms like quicksort or mergesort. However, it is straightforward to understand and implement.
