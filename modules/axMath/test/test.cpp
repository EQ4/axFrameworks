//
//  main.cpp
//  axEventTest
//
//  Created by Alexandre Arsenault on 2015-05-12.
//  Copyright (c) 2015 Alexandre Arsenault. All rights reserved.
//

#include "axMathVector.h"

int main(int argc, const char * argv[])
{
    // insert code here...
    std::cout << "Program start." << std::endl;
    
    ax::Math::Vector<double> pt1(1.0, 2.0, 3.0);
    ax::Math::Vector<double> pt2(4.0, 5.0, 6.0);

    ax::Math::Vector<double> pt3(pt1 + pt2);
    
    pt3.Print();
    
    for(int i = 0; i < pt3.Size(); i++)
    {
        std::cout << pt3[i] << std::endl;
    }
    
    for(int i = 0; i < pt3.Size(); i++)
    {
        pt3[i] = i;
    }
    
    for(auto& n : pt3)
    {
        std::cout << n << std::endl;
    }
    
    for(auto& n : pt3)
    {
        n = 9;
    }
    
    for(auto& n : pt3)
    {
        std::cout << n << std::endl;
    }

    return 0;
}

