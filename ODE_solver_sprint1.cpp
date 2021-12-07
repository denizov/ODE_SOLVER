#include <iostream>
#include <cmath>
#include "header.h"

float function(float x, float y){

    dydx=3*pow(x,2)+2*y; //dy/dx

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

    while(xi!=xf)
    {
       yf=yi+function(xi,yi)*h;
       xi=xi+h;
       yi=yf;
    }
}
    else  {
            while(xi>xf)
    {
       yf=yi-function(xi,yi)*h;
       xi=xi-h;
       yi=yf;
    }
    }

  std::cout<< "final y point is" << yf;

    return 0;
}
