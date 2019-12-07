#pragma once

#include "Function.h"

class TIdent : public TFunction {
public:
    TIdent () = default;
    TIdent (const TIdent& copy_from) = default;
    TIdent (TIdent&& move_from) = default;
    TIdent(const TOptions& opt);


    double operator() (double x_value) override;
    double GetDeriv (double x_value ) override ;
    std::string ToString () override ;
};
