/* 3 Write C++ program to draw a concave polygon and fill it with desired color using scan fill algorithm. Apply the concept of inheritance. */

#include<iostream>
#include<graphics.h>
using namespace std;

int main()
{
 
 int gd=DETECT, gm;
 initgraph(&gd,&gm,NULL);

 int  cnt,temp,i,j,n, ymax, ymin, yscan;
 float inter_x[10], m[10],dx,dy; 
 int x[10],y[10];
 
 cout<<"Enter no. of vertices of polygon: ";
 cin>>n;
 
 for(i=0;i<n;i++)
{
  cout<<" Enter " << i+1 << " vertices of polygon (as x and y) is: ";
  cin>>x[i]>>y[i];
}
x[n]=x[0];
y[n]=y[0];

for(i=0;i<n;i++)          //draw a polygon
{
  line(x[i],y[i],x[i+1],y[i+1]);
}

ymax=0;
ymin=480;

 for(i=0;i<n;i++)      //find ymax and ymin
 {
   if(y[i]>ymax)
    ymax=y[i];
    if(y[i]<ymin)
    ymin=y[i];
	
 }

 for(i=0;i<n;i++)       //cal slope of each side
 {
  dx=x[i+1]-x[i];
  dy=y[i+1]-y[i];
   
   if(dx==0)
   m[i]=0;
   
   else if(dy==0)
   m[i]=0;
   
   else
   m[i]=(float)dy/dx;
 }

for(yscan=ymax;yscan>ymin;yscan--)
 {
    cnt=0;
    for(i=0;i<n;i++)
    {
     	if(y[i]>yscan && y[i+1]<=yscan || y[i]<=yscan && y[i+1]>yscan)
     	{
                  if(m[i]==0)
         	         inter_x[cnt]=x[i];  //inactive edge
       	      else
           	        inter_x[cnt]= x[i] + (yscan-y[i])/m[i];  //active edge
       	        cnt++;
    	}
   }
      
    
      for(j=0;j<cnt-1;j++)  //find intersection points
      {
    	if(inter_x[j]<=inter_x[j+1])
    	{
     		temp=inter_x[j];
    		inter_x[j]=inter_x[j+1];
     		inter_x[j+1]=temp;
            }
      }
   
     
    for(j=0;j<cnt-1;j=j+2)            //fill the polygon using line
    {
        line(inter_x[j],yscan,inter_x[j+1],yscan);
        delay(100);
    }
 }  //end of for loop

getch();
return 0;
}  

/*
 avanish@avanish-Lenovo-G580:~/Desktop/CG_PRACT_CRB$ g++ 1scanline.cpp -lgraph
(base) avanish@avanish-Lenovo-G580:~/Desktop/CG_PRACT_CRB$ ./a.out 
Enter no. of vertices of polygon: 5
 Enter 1 vertices of polygon (as x and y ) is: 400 400
 Enter 2 vertices of polygon (as x and y ) is: 400 100
 Enter 3 vertices of polygon (as x and y ) is: 200 300
 Enter 4 vertices of polygon (as x and y ) is: 100 200
 Enter 5 vertices of polygon (as x and y ) is: 100 400
 

*/

// The Scan Line Fill algorithm is a method used in computer graphics to fill or color a polygon. It's particularly useful for polygons that are complex or non-convex. The algorithm works by 'scanning' each horizontal (or sometimes vertical) line—or scan line—that intersects with the polygon and determining which parts of these lines are inside the polygon. These parts are then filled with a color or pattern.

// ### How the Scan Line Fill Algorithm Works:
// 1. **Determine the Range of Scan Lines**: The algorithm first identifies the vertical range over which it will operate, typically from the lowest to the highest y-coordinate of the polygon's vertices (ymin to ymax).

// 2. **Calculating Intersection Points**:
//    - For each scan line (a horizontal line at a specific y-coordinate), the algorithm calculates the points where the line intersects the edges of the polygon.
//    - Special care is needed for edges that are horizontal or very steep, as they might not intersect a scan line in the usual way.

// 3. **Sorting Intersection Points**: 
//    - The intersection points along a scan line are sorted in order of increasing x-coordinate. This step is crucial to determine the fill correctly, especially for concave polygons.

// 4. **Filling Between Pairs of Points**:
//    - The algorithm then pairs up the sorted intersection points (usually taking them two at a time, from left to right).
//    - For each pair, the segment of the scan line between these two points is inside the polygon and is thus filled with the desired color or pattern.

// 5. **Repeat for Each Scan Line**:
//    - This process is repeated for every scan line in the range determined in step 1.
//    - The result is that the entire polygon gets filled.

// ### Key Features and Considerations:
// - **Handling Complex Polygons**: The algorithm efficiently handles concave polygons and those with holes, making it versatile for various shapes.
// - **Edge Cases**: Care must be taken to handle edges that are horizontal, as they don't intersect scan lines in a standard way. Similarly, vertices where the polygon changes from being concave to convex (or vice versa) need special handling.
// - **Efficiency**: The algorithm can be optimized for better performance, especially for polygons with many vertices or in cases where the filled area is large.

// ### Applications:
// - The Scan Line Fill algorithm is widely used in raster graphics editors, computer-generated imagery (CGI), and other applications where filling polygons is a common task. It's a fundamental technique in the field of computer graphics.

// This algorithm exemplifies how computer graphics can efficiently render complex shapes, a cornerstone in both 2D and 3D graphic applications.

// This C++ program uses the graphics.h library to draw and fill a concave polygon using the scan line fill algorithm. The program doesn't explicitly demonstrate inheritance, which is a key object-oriented programming concept. However, I'll explain the code and the underlying concept of the scan line fill algorithm:

// ### Step-by-Step Explanation of the Code

// #### 1. Initialization
// - The graphics mode is initialized using `initgraph`.
// - An array of `x` and `y` coordinates are declared to store the vertices of the polygon.

// #### 2. Input Vertices
// - The program prompts the user to enter the number of vertices (`n`) and their coordinates. The coordinates are stored in arrays `x` and `y`.
// - The last point is set to be the same as the first point to close the polygon.

// #### 3. Draw the Polygon
// - A loop is used to draw lines between consecutive vertices, using the `line` function.

// #### 4. Find `ymax` and `ymin`
// - The program scans through the vertices to find the maximum and minimum y-coordinates (`ymax` and `ymin`). These values determine the vertical range over which the scan line algorithm will operate.

// #### 5. Calculate Slopes
// - For each edge of the polygon, the slope is calculated and stored in the array `m`. The slope is calculated as the change in y divided by the change in x (`dy/dx`).

// #### 6. Scan Line Algorithm
// - Starting from `ymax` and going down to `ymin`, the program iterates over each horizontal line (`yscan`).
// - For each scan line, intersection points with the polygon's edges are found.
// - Special cases are handled:
//   - If an edge is horizontal (`dy == 0`), its slope is set to 0.
//   - If an edge is vertical (`dx == 0`), it's treated as an inactive edge.
// - Intersection points are calculated and stored in `inter_x`.
// - The intersection points are sorted, and pairs of points are used to draw horizontal lines to fill the polygon.

// #### 7. Delay and Close
// - A delay is added to visually demonstrate the filling process.
// - `getch()` is used to wait for a key press before the program exits.

// ### Concept Behind the Code: Scan Line Fill Algorithm

// The scan line fill algorithm is a technique used in computer graphics to fill polygons. It works by moving across the polygon horizontally (or vertically) and determining which regions to fill. The key steps in the algorithm are:

// 1. **Determine Intersection Points**: For each horizontal line (or scan line), calculate where it intersects the edges of the polygon.

// 2. **Sort Intersection Points**: Sort these points from left to right.

// 3. **Fill Between Pairs of Points**: For each pair of intersection points, draw a horizontal line between them. This step fills in the polygon.

// ### Note on Inheritance
// - The program does not demonstrate the use of inheritance, a concept where a new class (derived class) is created from an existing class (base class), inheriting its properties and methods. To apply inheritance, you could create classes representing different shapes or algorithms, with shared and specialized behaviors.

// The program effectively demonstrates the scan line fill algorithm for a concave polygon, which is a foundational concept in computer graphics for polygon filling.