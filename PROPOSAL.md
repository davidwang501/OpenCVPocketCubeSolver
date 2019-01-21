# Project Proposal
# OpenCV 2x2 Rubik's Cube Solver

My CS126 final project is a 2x2 Rubik's cube solver that uses color detection through a camera to read in the 6 sides of an unsolved cube and outputs an optimal solution (in Rubik's cube notation) to solve the cube. 

### Libraries
I will use OpenFrameworks to display the 6 sides of the cube as they are being scanned in by the webcam. OpenCV will be used to scan each face of the cube.

### Plan
As a backup, I will first implement the solver with user inputted cube sides. Each side of the cube will be displayed on the window with all squares blank except the center square  so the user can fill the color of each piece on the cube. Then, I will pass the input (6 by 2 array of colors) to an algorithm that will return a series of steps the user can take to solve the cube. The exact algorithm I will decide to use is still under consideration, since implementation difficulty of different algorithms vary dramatically. Some algorithms I am considering include the basic method, the Varasano method, and the Ortega method. 

After I ensure my algorithm works on manually inputted cubes, I will use OpenCV to "scan" the cube through my webcam so that the user doesn't have to manually input each square on the cube. As each face is being scanned, the scanned input will be displayed on the window so the user can make sure it is correct. 




