#include <iostream>

#include "Factory.h"
#include "Function.h"

int main() {

    TFunctionFactory factory;
    auto objects = factory.GetAvailableObjects();
    for (const auto& obj : objects) {
        std::cout << obj << std::endl;
    }

    TFunctionPtr f,g,h;

    f = factory.CreateObject("const",5);
    g = factory.CreateObject("exp",12);
    h = factory.CreateObject("polynomial",{-3,4,1});
    std::cout<< (f*h)->ToString() << std::endl;

    std::cout<<(*f).GetDeriv(5)<<"\n";


    std::cout<<h->ToString()<<"  = 0  "<< gradient_descent(h)<<std::endl;
    std::cout<<h->ToString()<<"  = 0  "<< newton_method(h)<<std::endl;
    std::cout<<h->ToString()<< "  x=1: " << (*h)(1)<<std::endl;
    std::cout<<h->ToString()<< "  x=1: " << h->GetDeriv(0)<<std::endl;



    return 0;
}
