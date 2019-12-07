#pragma once

#include <string>
#include <vector>
#include "TOptions.h"
#include "memory"


#define PRECISION 7

enum Operation {plus,minus,multiply,division};

class TFunction;
using TFunctionPtr = std::shared_ptr<TFunction>;

class TFunction {

public:
    virtual double operator() (double x_value) = 0;
    virtual double GetDeriv (double x_value) = 0;
    virtual std::string ToString () = 0;
};

#include "TPower.h"
#include "TConst.h"
#include "TExp.h"
#include "TIdent.h"
#include "TPolynomial.h"
#include "TComplexFunc.h"

TFunctionPtr operator+ (const TFunctionPtr& f,const TFunctionPtr& g);
TFunctionPtr operator- (const TFunctionPtr& f,const TFunctionPtr& g);
TFunctionPtr operator* (const TFunctionPtr& f,const TFunctionPtr& g);
TFunctionPtr operator/ (const TFunctionPtr& f,const TFunctionPtr& g);


template<class T>
TFunctionPtr operator+ (T lhs, const TFunctionPtr& rhs) {
    throw std::logic_error("Invalid type of operand");
}
template<class T>
TFunctionPtr operator- (T lhs, const TFunctionPtr& rhs) {
    throw std::logic_error("Invalid type of operand");
}
template<class T>
TFunctionPtr operator* (T lhs, const TFunctionPtr& rhs) {
    throw std::logic_error("Invalid type of operand");
}
template<class T>
TFunctionPtr operator/ (T lhs, const TFunctionPtr& rhs) {
    throw std::logic_error("Invalid type of operand");
}

template<class T>
TFunctionPtr operator+ (const TFunctionPtr& lhs, T rhs ) {
    throw std::logic_error("Invalid type of operand");
}
template<class T>
TFunctionPtr operator- (const TFunctionPtr& lhs, T rhs) {
    throw std::logic_error("Invalid type of operand");
}
template<class T>
TFunctionPtr operator* (const TFunctionPtr& lhs, T rhs) {
    throw std::logic_error("Invalid type of operand");
}
template<class T>
TFunctionPtr operator/ (const TFunctionPtr& lhs, T rhs) {
    throw std::logic_error("Invalid type of operand");
}


double gradient_descent (TFunctionPtr f, size_t iterations = 50, double delta = 0.005, double x_current = 0);

double newton_method (TFunctionPtr f, size_t iterations = 50, double x_0 = 0);


