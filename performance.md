# ODE Solver

## Performance

In our project, we have defined three different cases to show total time that the main calculation goes on.

These three cases have been defined according to changes that we have created through the design of the code.

- We have used `std::chrono::microseconds` for this process. We have also tried to use `gprof` 
however, computation time was too little to be able to seen on `gprof` examination. It reports all zero seconds in time columns. 
In anyways, we have added the outputs of that to show you. 

- Also we have added a new option for the performance test. When we are choosing to use default values or non-default values(user choose),
there is a new option `s`. When this option has been choosed, `x_initial` = -2 , `y_initial` = 0 , `x_final` = 15 , `step_size` = 0.1. 

We have increased the gap between initial and final points of the x value and decreased the step size to see more clearly the elapse time.

- The other thing that we have used while we are observing our computation time was using -O0 when we are compiling the code. The reason behind 
this is using no optimization for gcc. By using this technique, we prevent to decrease elapse time for consecutive running of the code. This was 
a better way to come up with fair calculation and more objective result.

### Writing out every step for either explicit or implicit euler solver calculation

Before the sprint 3 of the project (during sprint 2) we were writing out and print every intermediate step to show
how the output has been calculated. However this situation create a lot of burden for the computation time.

This situation (writing out every explicit or implicit steps) gives 627 microseconds for the performance test option.

### Stop writing every step for euler solver calculation

In this step, we inhibit the lines from the code which are enables to write and print every explicit or implicit euler calculation step.

By doing this, we have decreased the elapse time in such a good way. The output for this situation was 79 microseconds. 

In this way, we have figured out that while there is a project when the calculation steps were not taking too much time(not evet 1 milisecond),
print option for every step wastes a lot of time comparing to not printing every step(only at the end for the result).

### Using `*` (multiplication operator) instead of `/` (division)

When we are dealing with the explicit Euler solver, we are adding one tenth of the step size to the `x_final` value. As we have seen in the lecture,
multiplication is a better way than the division. In the first place this line of code was designed as `step_size/10`. However, this was not a good
idea if we compare it with `step_size*0.1`. So we have changed this division operator with the multiplication operator. 

This change also fastened our computation time. The elapse time was 48 microseconds after we have used the `*` operator for the calculation.


- To conclude, printing out every step increases the computation time a lot. So it affects the performance of the code in a bad way. Also using division 
operator is also increases computation time and decreases the performance.

- Smaller than 0.01 seconds do not show on the `gprof` function (our results are about 40-1000 microseconds). So this gives `0.00` second for all the time columns. 

