#include <iostream>
#include <cmath>
#include "header.h"

double function(double x, double y){
    dydx=2*x-5; //this is our unit test to compare analytical solution and the output of the code. The integral of the equation is x^2-5x+c. If we take the initial point as 0, we can see that c is also 0.
    // For the final point of x = 3, integral equation (x^2-5x+c) becomes 3^2-5*3+0 = -6. According to analytical solution, for the initial
    //point of x is 0.0, initial point of y is 0.0, final point of x is 3 and the step size is 0.1. According to these numbers, final point of y should be -6.
    //As we can see from the output of the code, the output of the code is -6.3 which is close to the analytical solution.
    //If you want to test the unit test case, you can uncomment the line for the equation 2x-5 and recompile.

    //dydx=3*pow(x,2)-2*y; //dy/dx
    
    //dydx=x+2*y;    //this is our unit test to compare analytical solution and the output of the code. According to analytical solution, for the initial
    //point of x is 2, initial point of y is 3, final point of x is 2.5 and the step size is 0.1. According to these numbers, final point of y should be 9.07356.
    //As we can see from the output of the code, it is obvious that analytical solution and the output of the code matches.
    //If you want to test the unit test case, you can uncomment the line for the equation x+2y and recompile.

    return dydx;
}

int main()
{

    std::cout << "Please enter the initial point of x: "<<std::endl;
    std::cin >> x_initial; //0
    std::cout << "Please enter the initial point of y: "<<std::endl;
    std::cin >> y_initial; //0
    std::cout << "Please enter the final point of x: "<<std::endl;
    std::cin >> x_final; //3
    std::cout << "Please enter the step size: "<<std::endl;
    std::cin >> h; //0.1   with these example values final point of y should be 6.
    
    if(h>abs(x_initial-x_final)){
        throw "Step size larger than the range!";
    }

    if (x_final>x_initial){

    while(x_final>=x_initial+h)
    {
        y_final=y_initial+function(x_initial,y_initial)*h;
        x_initial=x_initial+h;
        y_initial=y_final;
    }
}
    else  {
            while(x_initial>=x_final+h)
    {
        y_final=y_initial-function(x_initial,y_initial)*h;
        x_initial=x_initial-h;
        y_initial=y_final;
    }
    }

    std::cout<< "final y point is " << y_final<<std::endl;

    return 0;
}
