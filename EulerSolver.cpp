//
//  EulerSolver.cpp
//  
//
//  Created by deniz on 4.01.2022.
//

#include "EulerSolver.hpp"
#include "Function.hpp"
#include <iostream>

EulerSolver::EulerSolver(double xi,double xf,double yi,double h): _x_initial(xi),_y_initial(yi),_x_final(xf),_step_size(h){
    
    //std::cout << "Constructing an Eulersolver "<< std::endl;
}

ExplicitEuler::ExplicitEuler(double xi,double xf,double yi,double h): EulerSolver(xi,xf,yi,h){
    //std::cout << "Constructing an explicitEuler "<< std::endl;
}

ImplicitEuler::ImplicitEuler(double xi,double xf,double yi,double h): EulerSolver(xi,xf,yi,h){
    
}

double ExplicitEuler::solve(){
    if (_x_final>_x_initial){
        //std::cout<<"Inside Explicit Euler solve"<<std::endl;
    while(_x_final+(_step_size*0.1)>=_x_initial+_step_size)
    {
        _y_final=_y_initial+functionExplicit(_x_initial,_y_initial)*_step_size;
        //std::cout<<"explicit y's: "<<_y_final<<std::endl;
        _x_initial=_x_initial+_step_size;
        _y_initial=_y_final;
        //std::cout<<_x_initial<<std::endl;
    }
}
    else  {
            while(_x_initial>=_x_final+_step_size)
    {
        _y_final=_y_initial-functionExplicit(_x_initial,_y_initial)*_step_size;
        std::cout<<"explicit y's: "<<_y_final<<std::endl;
        _x_initial=_x_initial-_step_size;
        _y_initial=_y_final;
    }
    }
    
    return _y_final;
    
    
}





double ImplicitEuler::solve(){
    //std::cout<<"Inside Implicit Euler solve"<<std::endl;
    if (_x_final>_x_initial){

    while(_x_final>=_x_initial+_step_size)
    {
        
        
        
        _y_final=functionImplicit(_x_initial+h,_y_initial,_step_size);
        std::cout<<"imlicit y's: "<<_y_final<<std::endl;
        _x_initial=_x_initial+_step_size;
        _y_initial=_y_final;
    }
}
    else  {
        throw (std::runtime_error("Wrong parameters"));
    }
    
    return _y_final;
    
    
    
    
    
    
    
    
}
