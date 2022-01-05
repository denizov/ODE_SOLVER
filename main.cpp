#include <iostream>
#include <cmath>
#include "header.h"
#include "EulerSolver.hpp"
#include "Function.hpp"

void Solver(std::unique_ptr<EulerSolver>& s){
    std::cout<<"solverin ici"<<std::endl;
    double solution=s->solve();
    std::cout<<"solution is"<<solution<<std::endl;
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
    std::cin >> step_size; //0.1   with these example values final point of y should be 6.
    
    if(step_size>abs(x_initial-x_final)){
        throw "Step size larger than the range!";
    }

    
    
    std::unique_ptr<EulerSolver> zbam = std::make_unique<ExplicitEuler>(x_initial,x_final,y_initial,step_size);
    
    Solver(zbam);
    
    std::unique_ptr<EulerSolver> bum = std::make_unique<ImplicitEuler>(x_initial,x_final,y_initial,step_size);
    
    Solver(bum);

    return 0;
}
