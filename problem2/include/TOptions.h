#ifndef TASK2_TOPTIONS_H
#define TASK2_TOPTIONS_H

#include <stdexcept>
#include <vector>
#include <any>



class TOptions {
    std::vector<double> options;
public:
    TOptions() = default;
    TOptions(std::initializer_list<double> il)
    {
        options.insert(options.begin(), il.begin(), il.end());
    }
    TOptions(double one_arg) {
        options.push_back(one_arg);
    };
    std::vector<double> get() const
    {
        return options;
    };
};


#endif //TASK2_TOPTIONS_H
