#include <iostream>
#include <cmath>
#include "header.h"

float function(float x, float y){

    dydx=3*pow(x,2)-2*y; //dy/dx
    //dydx=x+2*y;	//this is our unit test to compare analytical solution and the output of the code. According to analytical solution, for the initial
    //point of x is 2, initial point of y is 3, final point of x is 2.5 and the step size is 0.1. According to these numbers, final point of y should be 9.07356.
    //As we can see from the output of the code, it is obvious that analytical solution and the output of the code matches.
    //If you want to test the unit test case, you can uncomment the line for the equation x+2y and recompile.

    return dydx;
}

int main()
{

    std::cout << "Please enter the initial point of x: ";
    std::cin >> xi;
    std::cout << "Please enter the initial point of y: ";
    std::cin >> yi;
    std::cout << "Please enter the final point of x: ";
    std::cin >> xf;
    std::cout << "Please enter the step size: ";
    std::cin >> h;

    if (xf>xi){

    while(xf>=xi+h)
    {
       yf=yi+function(xi,yi)*h;
       xi=xi+h;
       yi=yf;
    }
}
    else  {
            while(xi>=xf+h) 
    {
       yf=yi-function(xi,yi)*h;
       xi=xi-h;
       yi=yf;
    }
    }

  std::cout<< "final y point is " << yf;

    return 0;
}
