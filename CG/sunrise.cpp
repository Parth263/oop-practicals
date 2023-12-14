// Practical 6: Write OpenGL program to draw sunrise and sunset
//sudo apt-get install freeglut3-dev
//g++ filename.cpp -lGL -lGLU -lglut
#include &lt;iostream&gt;
#include &lt;GL/glut.h&gt;
using namespace std;
// Function to initialize the drivers
void myInit(void)
{
// Clear all the screen color
glClearColor(0.0,0.0,0.0,1.0); //black
glColor3f(1.0,1.0,1.0); //white
// Sets background color to orang
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
// Specify the display area
gluOrtho2D(0.0, 400.0, 0.0, 400.0);
}
// Function to display the Hut like structure on the console
void myDisplay(void)
{
// Clear the screen buffer
glClear(GL_COLOR_BUFFER_BIT);
glPointSize(4.0);
// Rectangular part of hut
glColor3f(0.5f, 0.5f, 0.5f);
// Begin the polygon
glBegin(GL_POLYGON);
// Create the polygon
glVertex2i(40, 40);
glVertex2i(320, 40);
glVertex2i(40, 40);
glVertex2i(40, 200);
glVertex2i(40, 200);
glVertex2i(320, 200);
glVertex2i(320, 200);
glVertex2i(320, 40);
glEnd();
// Right Window Update
glColor3f(1.0f, 0.0f, 0.0f);
// Begin the polygon
glBegin(GL_POLYGON);

// Create the polygon
glVertex2i(220, 60);
glVertex2i(300, 60);
glVertex2i(220, 150);
glVertex2i(300, 150);
glVertex2i(220, 60);
glVertex2i(220, 150);
glVertex2i(300, 150);
glVertex2i(300, 60);
glEnd();
// Right Window Update part 2
glColor3f(1.0f, 0.0f, 0.0f);
// Begin the polygon
glBegin(GL_POLYGON);
// Create the polygon
glVertex2i(220, 170);
glVertex2i(300, 170);
glVertex2i(220, 190);
glVertex2i(300, 190);
glVertex2i(220, 170);
glVertex2i(220, 190);
glVertex2i(300, 190);
glVertex2i(300, 170);
glEnd();
// Door
glColor3f(0.60f, 0.42f, 0.16f);
// Begin the polygon
glBegin(GL_POLYGON);
// Create the polygon
glVertex2i(130, 40);
glVertex2i(130, 160);
glVertex2i(130, 160);
glVertex2i(180, 160);
glVertex2i(180, 100);
glVertex2i(180, 40);
glVertex2i(120, 40);
glVertex2i(170, 40);
glEnd();
// Create Door Part 2
glColor3f(0.60f, 0.42f, 0.16f);
// Begin the polygon
glBegin(GL_POLYGON);

// Create the polygon
glVertex2i(130, 170);
glVertex2i(130, 180);
glVertex2i(130, 180);
glVertex2i(180, 180);
glVertex2i(180, 170);
glVertex2i(180, 180);
glVertex2i(130, 170);
glVertex2i(180, 170);
glEnd();
// Hut&#39;s top triangle part
glColor3f(1.0f, 0.0f, 1.0f);
// Begin the polygon
glBegin(GL_POLYGON);
// Create the polygon
glVertex2i(10, 200);
glVertex2i(340, 200);
glVertex2i(200, 390);
glVertex2i(10, 200);
glVertex2i(200, 390);
glEnd();
// Sends all output to display
glFlush();
}
// Driver Code
int main(int argc, char** argv)
{
// Initialize the init function
glutInit(&amp;argc, argv);
// Initialize the toolkit;
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
// Sets the display mode and specify the colour scheme
glutInitWindowSize(1200, 740);
// Specify the window size
glutInitWindowPosition(0, 0);
// Sets the starting position
// for the window
glutCreateWindow(&quot;Basic hut like structure&quot;);
// Creates the window and
// sets the title
glutDisplayFunc(myDisplay);
myInit();
// Additional initializations
glutMainLoop();

// Go into a loop until event
// occurs
return 0;
}


// The provided C++ program uses OpenGL and the GLUT (OpenGL Utility Toolkit) library to draw a simple graphical representation of a hut-like structure. The program sets up a basic 2D OpenGL environment and then draws various geometric shapes to form the hut. 

// Let's break down the code and explain the key concepts:

// ### Initial Setup and Functions

// #### `#include` Statements
// - The program includes `<iostream>` for standard input and output and `<GL/glut.h>` for using OpenGL and GLUT functions.

// #### Function `myInit`
// - Initializes OpenGL rendering modes.
// - `glClearColor(0.0, 0.0, 0.0, 1.0)`: Sets the background color of the window to black.
// - `glColor3f(1.0, 1.0, 1.0)`: Sets the current drawing color to white, but this setting is overwritten in `myDisplay` for each object.
// - `glMatrixMode(GL_PROJECTION)`: Sets the current matrix mode to projection matrix, used for defining how the scene is projected onto the screen.
// - `glLoadIdentity()`: Resets the projection matrix.
// - `gluOrtho2D(0.0, 400.0, 0.0, 400.0)`: Defines a 2D orthographic projection matrix, essentially setting up the coordinate system for drawing.

// #### Function `myDisplay`
// - The main function where the drawing is done.
// - `glClear(GL_COLOR_BUFFER_BIT)`: Clears the screen with the current clearing (background) color.
// - `glPointSize(4.0)`: Sets the size of points to be drawn; however, this program doesn't actually draw any standalone points.
// - Uses `glColor3f` to set colors and `glBegin(GL_POLYGON)` ... `glEnd()` blocks to draw various polygons representing different parts of the hut (rectangular body, windows, door, triangular roof).
// - `glFlush()`: Outputs all the drawing commands to the screen.

// ### Drawing the Hut

// - The hut is composed of multiple polygons. Each call to `glBegin(GL_POLYGON)` followed by a series of `glVertex2i` calls and a closing `glEnd()` creates a polygon. 
// - The `glVertex2i` function specifies the vertices of these polygons in 2D integer coordinates.
// - Different parts of the hut are drawn with different colors by setting `glColor3f` before each polygon.

// ### Main Function

// - Initializes GLUT and sets up the display mode, window size, and window position.
// - Creates a window with `glutCreateWindow`.
// - Registers `myDisplay` as the display callback function.
// - Calls `myInit` for additional initializations.
// - Enters the GLUT event processing loop with `glutMainLoop`.

// ### Concepts Behind the Code

// - **OpenGL**: A powerful cross-platform graphics API used for 2D/3D graphics rendering. It provides a set of functions to render graphics.
// - **GLUT**: A utility library for OpenGL that provides a simplified API for creating windows, handling user input, and managing other tasks common in OpenGL applications.
// - **2D Drawing**: Although OpenGL is often used for 3D graphics, this program uses it for 2D drawing by setting up an orthographic projection.
// - **Polygons**: The basic drawing primitives in OpenGL are points, lines, and polygons. This program uses polygons to create the shapes.

// ### Correction

// - The title in `glutCreateWindow` and the comments suggest the program is intended to draw a basic hut-like structure, but the program's title and your question mention "sunrise and sunset." The current implementation doesn't include elements like a sun, sky, or any animation to depict sunrise or sunset. To achieve this, additional drawing routines and potentially some animation logic would be necessary.