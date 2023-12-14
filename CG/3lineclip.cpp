/* 3 Write C++ program to implement Cohen Southerland line clipping algorithm. */
	
#include<iostream>
#include<graphics.h>

using namespace std;
static int x_max, y_max, x_min, y_min;

// Defining region codes
static int INSIDE = 0; // 0000
static int LEFT = 1; // 0001
static int RIGHT = 2; // 0010
static int BOTTOM = 4; // 0100
static int TOP = 8; // 1000

// Defining x_max, y_max and x_min, y_min for
// clipping rectangle. Since diagonal points are
// enough to define a rectangle
// Function to compute region code for a point(x, y)
int binaryCode(double x, double y)
{
	// initialized as being inside
	int code = INSIDE;

	if (x < x_min) // to the left of rectangle
		code |= LEFT;
	else if (x > x_max) // to the right of rectangle
		code |= RIGHT;
	if (y < y_min) // below the rectangle
		code |= BOTTOM;
	else if (y > y_max) // above the rectangle
		code |= TOP;

	return code;
}

// Implementing Cohen-Sutherland algorithm
// Clipping a line from P1 = (x1, y1) to P2 = (x2, y2)

void cohenSutherlandClip(double x1, double y1, double x2, double y2)
{
	// Compute region codes for P1, P2
	int code1 = binaryCode(x1, y1);
	int code2 = binaryCode(x2, y2);

	// Initialize line as outside the rectangular window
	bool accept = false;
	

	while (true) {
		if ((code1 == 0) && (code2 == 0)) {
		// If both endpoints lie within rectangle
			accept = true;
			break;
		}
		else if (code1 & code2) {
		// If both endpoints are outside rectangle,
			break;
		}
		else {
		// Some segment of line lies within the
		// rectangle
			int code_out;
			double x, y;

			// At least one endpoint is outside the
			// rectangle, pick it.
			if (code1 != 0)
				code_out = code1;
			else
				code_out = code2;

		// Find intersection point;
		// using formulas y = y1 + slope * (x - x1),
		// x = x1 + (1 / slope) * (y - y1)
			if (code_out & TOP) {
		// point is above the clip rectangle
				x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
				y = y_max;
			}
			else if (code_out & BOTTOM) {
				// point is below the rectangle
			x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
			y = y_min;
			}
			else if (code_out & RIGHT) {
			// point is to the right of rectangle
			y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);			x = x_max;
			}
			else if (code_out & LEFT) {
			// point is to the left of rectangle
				y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
				x = x_min;
			}

			// Now intersection point x, y is found
			// We replace point outside rectangle
			// by intersection point
			if (code_out == code1) {
				x1 = x;
				y1 = y;
				code1 = binaryCode(x1, y1);
			}
			else {
				x2 = x;
				y2 = y;
				code2 = binaryCode(x2, y2);
			}
		}
	}
	if (accept) {
	delay(2000);
	rectangle(x_min,y_min,x_max,y_max);
	line(x1,y1,x2,y2);  
	}
}
// Driver code
int main()
{
	int gdriver = DETECT,gmode =VGAMAX;
	initgraph(&gdriver,&gmode,NULL);
	
            cout<<"Enter left, top and right, bottom of window: ";
	cin>>x_min>>y_min>>x_max>>y_max;
	rectangle(x_min,y_min,x_max,y_max);
	int x1,y1,x2,y2;
	cout<<"Enter the endpoints of the line: ";
	cin>>x1>>y1>>x2>>y2;
	line(x1,y1,x2,y2);  
	cleardevice();
	
	cohenSutherlandClip(x1,y1,x2,y2); 
	
	getch();
	return 0;
	
}



// //Output 
// 100
// 100
// 300
// 300
// 100
// 150
// 300
// 150


// The Cohen-Sutherland Line Clipping Algorithm is a famous method in computer graphics for clipping a line to a rectangular clipping window. This algorithm efficiently determines whether a line segment is visible in the specified rectangular area and, if only a portion of the line is visible, it calculates that visible portion. 

// ### How the Algorithm Works:
// 1. **Region Coding**: Each point in the plane is assigned a region code. This 4-bit code corresponds to the position of the point relative to the clipping rectangle. The four bits represent top, bottom, right, and left, respectively. For example, a point to the right of the rectangle and above it would have a code of 1001 (top and right bits are set).

// 2. **Assigning Region Codes to Line Endpoints**: The region codes for both endpoints of a line segment are computed.

// 3. **Trivial Acceptance or Rejection**:
//    - **Trivial Acceptance**: If both endpoints of a line segment have a region code of 0000, it means both points are inside the clipping rectangle, and the line segment is entirely visible.
//    - **Trivial Rejection**: If the bitwise AND of the region codes of the endpoints is not 0000, it means both points are outside the clipping rectangle in the same external region, and the line segment is entirely invisible.

// 4. **Subdivision**: If the line segment is neither trivially accepted nor rejected, the algorithm divides it into smaller segments. This subdivision continues until the segments can be trivially accepted or rejected.

// 5. **Intersection Calculation**: For segments that cannot be trivially accepted or rejected, the algorithm calculates the intersections of the line segment with the clipping boundary. This is done using the mathematical equations of the line and the edges of the clipping rectangle.

// 6. **Updating Region Codes**: After finding the intersection with a boundary, the algorithm updates the region code of the point that was outside the clipping rectangle and repeats the process.

// ### Features of the Algorithm:
// - **Efficiency**: It quickly eliminates many line segments that are entirely outside the clipping area without calculating intersections.
// - **Simplicity**: The algorithm is straightforward and easy to implement.
// - **Rectangular Clipping Windows**: It's specifically designed for axis-aligned rectangular clipping windows.

// ### Applications:
// - **Computer Graphics**: It's used in graphical applications for rendering scenes with rectangular viewports.
// - **Geographic Information Systems (GIS)** and other fields where quick determination of visible line segments within a rectangular frame is necessary.

// The Cohen-Sutherland algorithm is an excellent example of an algorithm that balances computational efficiency with simplicity, making it ideal for real-time computer graphics applications.

// This C++ program implements the Cohen-Sutherland line clipping algorithm using the graphics.h library. The Cohen-Sutherland algorithm is a computer graphics algorithm used for line clipping. The algorithm divides the space into regions and efficiently determines the lines (or portions of them) that are visible within a rectangular window.

// ### Detailed Explanation of the Code

// #### 1. Initialization and Global Variables
// - The `graphics.h` library is included for graphical functions.
// - Global variables `x_max, y_max, x_min, y_min` define the clipping rectangle's boundaries.
// - Region codes (`INSIDE, LEFT, RIGHT, BOTTOM, TOP`) are defined to categorize the position of points relative to the clipping rectangle.

// #### 2. Function `binaryCode`
// - This function calculates the region code for a point (`x, y`) based on its position relative to the clipping rectangle.
// - It uses bitwise OR operations to combine the relevant region codes.

// #### 3. Function `cohenSutherlandClip`
// - This is the implementation of the Cohen-Sutherland line clipping algorithm.
// - It takes the endpoints of a line (`x1, y1, x2, y2`) as input.
// - Region codes for both endpoints are computed.
// - The algorithm iterates until it concludes whether to accept or reject the line (or a portion of it).
// - The line is accepted if both endpoints are inside the rectangle. If both are outside and share an outside region, the line is rejected.
// - Otherwise, the algorithm calculates intersection points with the clipping rectangle's boundaries to clip the line.

// #### 4. Calculating Intersection Points
// - Intersection points are calculated based on which part of the boundary the line needs to be clipped.
// - The formulas used depend on whether the clipping is being done against the top, bottom, left, or right edges of the rectangle.
// - After finding an intersection point, the algorithm replaces the endpoint outside the rectangle with this intersection point and recalculates the region code.

// #### 5. Drawing the Line and Rectangle
// - If the line (or a segment of it) is accepted, it is drawn using the `line` function after a delay.
// - The clipping rectangle is also drawn using the `rectangle` function.

// #### 6. Main Function
// - Initializes the graphics mode.
// - Takes input for the coordinates of the clipping rectangle and the line.
// - Draws the initial line.
// - Clears the graphics window and then applies the `cohenSutherlandClip` function to clip the line.
// - Waits for a key press before closing.

// ### Flow of the Code
// 1. **Initialization**: Sets up the graphics mode and takes user input for the clipping rectangle and the line to be clipped.
// 2. **Clipping Algorithm Execution**: The `cohenSutherlandClip` function is called with the line coordinates.
// 3. **Region Code Calculation**: For each endpoint of the line, its region code is computed.
// 4. **Clipping Decision and Computation**: The algorithm determines whether to clip the line and calculates new endpoints if necessary.
// 5. **Rendering**: Draws the clipping rectangle and the clipped line.
// 6. **Completion**: Waits for user interaction before closing.

// ### Concept of Cohen-Sutherland Line Clipping Algorithm
// - The main idea behind the algorithm is to use region codes for the endpoints of the line and efficiently determine whether to draw or clip the line.
// - It reduces computational overhead by quickly rejecting lines that are completely outside the clipping window and accepting lines completely inside.
// - For lines that intersect the clipping boundaries, it calculates exact intersection points and clips the line accordingly.

// This algorithm is a classic example of a computational geometry algorithm used in computer graphics for rendering and is particularly efficient for simple rectangular clipping windows.