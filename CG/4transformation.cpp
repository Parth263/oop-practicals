/* 4b) Write C++ program to implement translation, rotation and scaling transformations on equilateral triangle and rhombus. Apply the concept of operator overloading. */

#include <stdlib.h>
#include <iostream>
#include <graphics.h>
#include <math.h>

using namespace std;

class Tdimen
{
	int x1,y1,x2,y2,x3,y3;
	
	public:
	void translate();
	void scale();
	void rotate();
	
	void operator=(const Tdimen &T)
	{
		x1=T.x1;
		y1=T.y1;
		x2=T.x2;
		y2=T.y2;
		y3=T.y3;
		x3=T.x3;
		
            }

	void draw()
	{
	x1=150,y1=50,x2=100,y2=100,x3=200,y3=100;
	int gdriver = DETECT,gmode;
	initgraph(&gdriver,&gmode,NULL);
	cleardevice();
	line(x1,y1,x2,y2);
	line(x2,y2,x3,y3);
	line(x3,y3,x1,y1);
	}
	
	void result()
	{
	cleardevice();
	line(x1,y1,x2,y2);
	line(x2,y2,x3,y3);
	line(x3,y3,x1,y1);
	}
};

void Tdimen::translate()
{
	float tx,ty;
	cout<<"Enter tx & ty: ";
	cin>>tx>>ty;
	x1+=tx;x2+=tx;x3+=tx;
	y1+=ty;y2+=ty;y3+=ty;
	
}

void Tdimen::scale()
{
	float sx,sy;
	cout<<"Enter sx & sy: ";
	cin>>sx>>sy;
	x1*=sx;x2*=sx;x3*=sx;
	y1*=sy;y2*=sy;y3*=sy;
	
}

void Tdimen::rotate()
{
	float deg;
	cout<<"Enter angle: ";
	cin>>deg;
	deg = deg*3.14/180;
	int x,y;
	x=x1;y=y1;
	x1 = x*cos(deg)-y*sin(deg);
	y1 = x*sin(deg)+y*cos(deg);
	x=x2;y=y2;
	x2 = x*cos(deg)-y*sin(deg);
	y2 = x*sin(deg)+y*cos(deg);
	x=x3;y=y3;
	x3 = x*cos(deg)-y*sin(deg);
	y3 = x*sin(deg)+y*cos(deg);
	
}

int main()
{
	int option;
	Tdimen T;
	do
	{
	cout<<"\n1.Translation 2.Scaling 3.Rotation 4.Exit: ";
	cin>>option;
	switch(option)
	{
		case 1:
		T.draw();
		T.translate();
 		T.result();
		break;
		
		case 2:
		T.draw();
		T.scale();
		T.result();
		break;

		case 3:
		T.draw();
		T.rotate();
		T.result();
		break;

		case 4:
		break;

		default:
		cout<<"Invalid choice";
	}
          }while(option!=4);

closegraph();
}


// This C++ program demonstrates the use of basic 2D transformation operations—translation, scaling, and rotation—on a triangle (which could be extended to any polygon like a rhombus). It also illustrates the concept of operator overloading in C++.

// ### Code Explanation

// #### Class `Tdimen`
// - This class represents a triangle with its vertices `(x1, y1)`, `(x2, y2)`, and `(x3, y3)`.
// - Contains methods for translation, scaling, and rotation transformations, as well as methods to draw and display the transformed triangle.

// #### Operator Overloading (`operator=`)
// - Overloads the assignment operator to copy the coordinates from one `Tdimen` object to another.

// #### Method `draw`
// - Initializes the graphics mode and draws the original triangle.

// #### Method `result`
// - Clears the graphics window and redraws the triangle, reflecting any transformations that have been applied.

// #### Transformation Methods
// 1. **`translate`**:
//    - Moves the triangle by a specified amount in x (`tx`) and y (`ty`) directions.
//    - The translation is achieved by adding `tx` and `ty` to each coordinate of the triangle's vertices.

// 2. **`scale`**:
//    - Scales the triangle by a specified scale factor in x (`sx`) and y (`sy`) directions.
//    - The scaling is achieved by multiplying each coordinate of the triangle's vertices by `sx` and `sy`.

// 3. **`rotate`**:
//    - Rotates the triangle by a specified angle (`deg`).
//    - The rotation is achieved using the rotation matrix, where each vertex is transformed by the rotation equations involving sine and cosine of the given angle.

// #### Main Function
// - The `main` function provides a simple user interface to apply transformations to the triangle.
// - It repeatedly prompts the user to choose between translation, scaling, rotation, or exit.
// - Based on the user's choice, it performs the corresponding transformation and displays the result.

// ### Theoretical Concepts

// #### 1. 2D Transformations
// - **Translation**: Shifting an object from one place to another in a 2D plane. Involves adding a constant value to the x and y coordinates of each point of the object.
// - **Scaling**: Changing the size of an object. Involves multiplying the coordinates of each point of the object by scaling factors.
// - **Rotation**: Rotating an object about a pivot point. Involves changing the coordinates of each point of the object according to rotation equations.

// #### 2. Operator Overloading
// - A feature in C++ that allows the programmer to redefine the way operators work for user-defined types (like classes). In this program, the assignment operator is overloaded to copy one object's properties into another.

// #### 3. Graphics in C++
// - The `graphics.h` header file is used for drawing graphics. This program uses functions from this library to draw and manipulate the triangle on the screen.

// ### Note on Graphics.h
// - The `graphics.h` library is quite old and not standard in modern C++. Its use is mainly educational and for simple graphical demonstrations. Modern graphics programming often involves more advanced libraries like OpenGL or DirectX for complex graphics operations.