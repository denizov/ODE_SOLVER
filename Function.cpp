//
//  Function.cpp
//  
//
//  Created by deniz on 4.01.2022.
//

#include "Function.hpp"
#include <iostream>
#include <cmath>

double functionExplicit(double x, double y){
   // double dydx=2*x-5; //this is our unit test to compare analytical solution and the output of the code. The integral of the equation is x^2-5x+c. If we take the initial point as 0, we can see that c is also 0.
    // For the final point of x = 3, integral equation (x^2-5x+c) becomes 3^2-5*3+0 = -6. According to analytical solution, for the initial
    //point of x is 0.0, initial point of y is 0.0, final point of x is 3 and the step size is 0.1. According to these numbers, final point of y should be -6.
    //As we can see from the output of the code, the output of the code is -6.3 which is close to the analytical solution.
    //If you want to test the unit test case, you can uncomment the line for the equation 2x-5 and recompile.

    //dydx=3*pow(x,2)-2*y; //dy/dx
    
    double dydx=x+2*y;    //this is our unit test to compare analytical solution and the output of the code. According to analytical solution, for the initial
    //point of x is 2, initial point of y is 3, final point of x is 2.5 and the step size is 0.1. According to these numbers, final point of y should be 9.07356.
    //As we can see from the output of the code, it is obvious that analytical solution and the output of the code matches.
    //If you want to test the unit test case, you can uncomment the line for the equation x+2y and recompile.

    return dydx;
}
double functionImplicit(double x, double y, double h){
    
   //double dydxNext=y+(2*x-5)*h;
    double dydxNext=(y+(x*h))/(1-2*h); // Implicit function for dydx=x+2*y;
    return dydxNext;
}
