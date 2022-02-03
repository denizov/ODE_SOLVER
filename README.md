# ODE_Solver

In the third sprint of the project, we have tested the performance of our code.
The general process is declined in the `performance.md` file. Details can be seen in there. We gave the main attention on 
that file because the main purpose for the sprint 3 is optimizng code and getting a better result for the computation time.

We have included some flags for the errors. The error statements show up if there is a problem with the choices.
If you want to change the function and the parameters for the test case, you can change them respectively through 
Function.cpp and main.cpp. 
For the test case, explicit solver is obvious but for the implicit solver, `y'= x+2y` the output comes like
`y(x)≈C1*2.71828^(2x) - 0.5x - 0.25`. These steps are the same with the sprint 2 but for the performance test, 
we have created a new choice and when using this choice, default values are different than the ones in the `yes` option that
we have used in sprint 2. So do not ignore it. The details are explained in the `performance.md` file.




