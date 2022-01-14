# ODE_Solver

In the second sprint of the project, we have implemented both explicit and implicit Euler Scheme.
We have created classes and header files to make connections and required calculations. 
Function.cpp file contains the function that we have used for the calculations. 
This function can be changed but it also has to be changed for the implicit one. The EulerSolver.cpp 
file is making the required calculations for both the implicit and explicit choice. After that we are taking
the required initial conditions from the user in the main.cpp file. In the main part there are two options at first.
The user should choose whether the test case will be used or not. Second option rather than the test 
case initial points requires the parameters from the user. After this step, the user choose whether
the explicit or implicit euler solver function will be called. After all of that, the expected solution will show up.
We have included some flags for the errors. The error statements show up if there is a problem with the choices.
If you want to change the function and the parameters for the test case, you can change them respectively through 
Function.cpp and main.cpp. 
For the test case, explicit solver is obvious but for the implicit solver, y'= x+2y the output comes like
 y(x)≈C1*2.71828^(2x) - 0.5x - 0.25. According to this equation and the parameters that have been given in the test case,
output should be around 10 and our solution is also close to that. The explicit Euler function gives the 
exact solution for its own purpose.




