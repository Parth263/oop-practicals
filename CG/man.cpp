/* Practical 7:Write C++ program to draw man walking in the rain with an umbrella. */
#include &lt;cstdlib&gt;
#include &lt;iostream&gt;
#include &lt;stdlib.h&gt;
#include &lt;graphics.h&gt;
#include &lt;math.h&gt;
using namespace std;
int main()
{
int gd=DETECT,gm;
int j,i;
initgraph(&amp;gd,&amp;gm,NULL);
for(i=0;i&lt;500;i=i+5)
{
line(20,380,580,380); //platform
if(i%2==0)
{
line(25+i,380,35+i,340); //leftleg
line(45+i,380,35+i,340);//right leg
line(35+i,310,25+i,330);//left hand
delay(20);
}
else
{
line(35+i,380,35+i,340); //leftleg
line(35+i,310,40+i,330); //left hand
delay(20);
}
line(35+i,340,35+i,310); //body
circle(35+i,300,10); //head
line(35+i,310,50+i,330); // hand
line(50+i,330,50+i,280); //umbrella stick
line(15+i,280,85+i,280); //umbrella right
arc(50+i,280,180,360,35); //umbrella body
arc(55+i,330,360,180,5);//umbrella handle
delay(200);
cleardevice();
}
getch();
return 0;
}


// This C++ program uses the `graphics.h` library to create a simple animation of a man walking in the rain with an umbrella. The program achieves this by drawing a series of frames in a loop, each slightly altered to create the illusion of motion.

// ### Explanation of the Code:

// 1. **Initialization**:
//    - `int gd = DETECT, gm;` declares graphics driver and mode variables.
//    - `initgraph(&gd, &gm, NULL);` initializes the graphics system.

// 2. **Animation Loop**:
//    - The `for` loop `for(i = 0; i < 500; i = i + 5)` creates the animation frames. The variable `i` is incremented to move the figure horizontally across the screen.
//    - Inside the loop, various graphics functions draw the scene in each frame.

// 3. **Drawing the Scene**:
//    - `line(20, 380, 580, 380);` draws a horizontal line representing the platform or ground.
//    - The condition `if(i % 2 == 0)` creates a simple walking animation by alternating the position of the legs and one arm in each frame.
//    - The man is drawn using lines for the body and limbs (`line` function) and a circle for the head (`circle` function).
//    - The umbrella is drawn using a combination of lines, an arc for the canopy (`arc` function), and another arc for the handle.

// 4. **Movement and Delay**:
//    - The man and the umbrella move to the right in each frame as determined by the incrementing `i` variable.
//    - `delay(200);` pauses the program briefly to make each frame visible, creating the animation effect.

// 5. **Clearing the Screen**:
//    - `cleardevice();` clears the screen in each iteration of the loop, preparing it for the next frame.

// 6. **Ending the Program**:
//    - `getch();` waits for a key press.
//    - `return 0;` ends the program.

// ### Concepts Behind the Code:

// - **Basic Animation**: The program creates an animation by quickly drawing and clearing frames, each slightly different from the last, giving the illusion of motion.

// - **Conditional Logic**: The use of `if(i % 2 == 0)` to alternate the position of the legs and arm provides a simple walking animation.

// - **Graphics Programming**: The use of `graphics.h`, a C++ graphics library, demonstrates basic 2D graphics programming concepts like drawing primitives (lines, circles, arcs) and managing frames for animation.

// ### Limitations and Enhancements:

// - **Simplicity**: The program is quite basic, using simple shapes and lines. More complex graphics could be used for a more realistic figure and smoother animation.
// - **Rain Effect**: The program's title suggests a rain scene, but no rain is drawn. Adding rain would involve drawing many vertical lines across the screen, perhaps also animated to move downward.
// - **Refactoring for Readability**: The code could be refactored for better readability and maintainability, perhaps by separating the drawing of the man and the umbrella into separate functions.

// To run this program, one needs a C++ environment that supports `graphics.h`, which is mainly found in older compilers like Turbo C++. Modern systems may require a setup like MinGW (on Windows) or an equivalent on other platforms, along with a graphics library compatible with `graphics.h`.