#include <iostream>
#include <memory>
#include <cmath>
#include "header.h"
#include "EulerSolver.hpp"
#include "Function.hpp"
#include <chrono>
#include <fstream>

void Solver(std::unique_ptr<EulerSolver>& s){
    std::chrono::time_point<std::chrono::system_clock> start;
    std::chrono::time_point<std::chrono::system_clock> end;
    start = std::chrono::system_clock::now(); //I moved the chrono here to discard text writing time, It turns our actual solver time is lower than we think. We will think about it in final part.

    double solution=s->solve();
    end = std::chrono::system_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Elapsed time:" << elapsed_time.count() << "microseconds" << std::endl;
  
    std::cout<<"solution is "<<solution<<std::endl;
    std::ofstream myfile;
    myfile.open ("Result.txt");
    myfile << solution;
    myfile.close();
}

int main()
{

    std::cout << "The function that has been used is x+2y. If you want to change the function look for the Function.cpp" << std::endl;
    std::cout << "Do you want to use the test case" << std::endl << "Press y for yes, n for no, press s for performance test" << std::endl;
    
    std::cin >> test_choice;
    
    if (test_choice == 'y'){  //if statement for the test case (We want to use test case)
        std::cout << "You are using the test case" << std::endl;
        std::cout << "The initial point of x is 2" << std::endl;
        x_initial = 2;
        std::cout << "The initial point of y is 3" << std::endl;
        y_initial = 3;
        std::cout << "The final point of x is 2.5" << std::endl;
        x_final = 2.5;
        std::cout << "Step size is 0.1" << std::endl;
        step_size = 0.1;
        std::cout << "Final point of y should be 9.07536 for the explicit" <<std::endl;
    }
    else if (test_choice == 'n'){  //else if statement for the test case (Do not want to use test case)
    std::cout << "You are not using the test case. You are going to decide on your own parameters." << std::endl;
    std::cout << "Please enter the initial point of x: "<<std::endl;
    std::cin >> x_initial; 
    std::cout << "Please enter the initial point of y: "<<std::endl;
    std::cin >> y_initial;
    std::cout << "Please enter the final point of x: "<<std::endl;
    std::cin >> x_final; 
    std::cout << "Please enter the step size: "<<std::endl;
    std::cin >> step_size;
        if(step_size>fabs(x_initial-x_final)){
            throw (std::runtime_error("Step size larger than the range!"));
        }
    }
    else if (test_choice == 's'){
    std::cout << "You are using the performance case" << std::endl;
    std::cout << "The initial point of x is -2" << std::endl;
    x_initial = -2;
    std::cout << "The initial point of y is 0" << std::endl;
    y_initial = 0;
    std::cout << "The final point of x is 15" << std::endl;
    x_final = 15;
    std::cout << "Step size is 0.1" << std::endl;
    step_size = 0.1;
    }
        

    else{ //else statement for the test case
        throw (std::runtime_error("!!!!Please choose y or n!!!!"));
        
    }
    
    std::unique_ptr<EulerSolver> euler;
    
    std::cout<<"Do you want to solve with explicit or implicit?"<<std::endl<<"Press e for explixit, press i for implicit"<<std::endl;
    
    std::cin>>choice;
    
    if(choice=='e'){
        euler=std::make_unique<ExplicitEuler>(x_initial,x_final,y_initial,step_size);
    }
    else if(choice=='i'){
        euler = std::make_unique<ImplicitEuler>(x_initial,x_final,y_initial,step_size);
    }
    else{
        throw (std::runtime_error("!!!!Please choose e or i!!!!"));
    }

        Solver(euler);
        



    return 0;
}
