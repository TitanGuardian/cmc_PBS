#include "Function.h"

TFunctionPtr operator+ (const TFunctionPtr& f,const TFunctionPtr& g) {
    return std::make_shared<TComplexFunc>(f,g,plus);
}
TFunctionPtr operator- (const TFunctionPtr& f,const TFunctionPtr& g) {
    return std::make_shared<TComplexFunc>(f,g,minus);
}
TFunctionPtr operator* (const TFunctionPtr& f,const TFunctionPtr& g) {
    return std::make_shared<TComplexFunc>(f,g,multiply);
}
TFunctionPtr operator/ (const TFunctionPtr& f,const TFunctionPtr& g) {
    return std::make_shared<TComplexFunc>(f,g,division);
}



double gradient_descent (TFunctionPtr f, size_t iterations, double delta, double x_current) {
    for (size_t itr = 0; itr < iterations ; ++itr) {
        if ((*f)(x_current)>0) {
            x_current = x_current - delta * f->GetDeriv(x_current);
        }
        else if ((*f)(x_current)<0)  {
            x_current = x_current + delta * f->GetDeriv(x_current);
        }
        else break;
    }
    return x_current;
};
double newton_method (TFunctionPtr f, size_t iterations, double x_0){
    for (size_t itr = 0; itr < iterations ; ++itr) {
        double der = f->GetDeriv(x_0);
        if (der == 0 ) break;
        x_0 = x_0 - (*f)(x_0)/ der;
    }
    return x_0;
}












