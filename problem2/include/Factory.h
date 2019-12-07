#pragma once

#include "Function.h"
#include "TOptions.h"

#include <memory>
#include <vector>
#include <map>


class TFunctionFactory {
    class TImpl;
    std::unique_ptr<const TImpl> Impl;
public:
    TFunctionFactory();
    ~TFunctionFactory();
    TFunctionPtr CreateObject(const std::string& type, const TOptions & opts = TOptions()) const;

    std::vector<std::string> GetAvailableObjects() const;
};
