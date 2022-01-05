//
//  EulerSolver.hpp
//  
//
//  Created by deniz on 4.01.2022.
//

#ifndef EulerSolver_hpp
#define EulerSolver_hpp
#include "Function.hpp"
#include <iostream>

class EulerSolver{
protected:
    double _x_initial,_y_initial,_x_final,h,y_final,_step_size;
public:
    EulerSolver(double xi,double xf,double yi,double h);
    
    double virtual solve()=0;
    
    
    virtual ~EulerSolver() = default;
};




class ExplicitEuler : public EulerSolver{
private:
    double _y_final;
public:
    ExplicitEuler(double xi,double xf,double yi,double h);
    double solve() override ;
    
};

class ImplicitEuler : public EulerSolver{
private:
    double _y_final;
public:
    ImplicitEuler(double xi,double xf,double yi,double h);
    double solve() override ;
    
};



#endif /* EulerSolver_hpp */
