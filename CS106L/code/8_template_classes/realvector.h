#ifndef RealVector_H
#define RealVector_H

#include <string>
#include <algorithm>
#include <stdexcept>


template<typename T> 
class RealVector {
public:
    using iterator = T*;

    const int kInitialSize = 2; 

    
private:
  
};

// Important: For template classes, include the .cpp at the bottom of the .h instead of including the .h in the top of the .cpp
#include "realvector.cpp"

#endif // RealVector_H