

#include "gtest/gtest.h"
#include "iostream"
#include "Factory.h"
#include "Function.h"



TEST (Function, newton_method_0) {
    // arrange
    TFunctionFactory factory;
    auto f = factory.CreateObject("polynomial", {5,21,4});
    //act
    auto root = newton_method(f, 50, 0);

    double root1 = -5;
    double root2 = -1/4;
    double special_point = -21.0/4; // GetDeriv(Special point) == 0
    double surround = 0.25 ;

    bool res_check = (root >= root1-surround &&  root <= root1+0.5 )
                     || (root >= root2-surround &&  root <= root2+surround)
                     || (root >= special_point-surround &&  root <= special_point+surround);
    // assert
    ASSERT_EQ (true,res_check) << root << "  " << f->ToString();
}

TEST (Function, newton_method_1) {
    // arrange
    TFunctionFactory factory;
    auto f = factory.CreateObject("polynomial", {0,2,1});
    //act
    auto root = newton_method(f, 50, 0);

    double root1 = 0;
    double root2 = -2;
    double special_point = -1; // GetDeriv(Special point) == 0
    double surround = 0.25 ;

    bool res_check = (root >= root1-surround &&  root <= root1+0.5 )
                     || (root >= root2-surround &&  root <= root2+surround)
                     || (root >= special_point-surround &&  root <= special_point+surround);
    // assert
    ASSERT_EQ (true,res_check) << root << "  " << f->ToString();
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return  RUN_ALL_TESTS();;
}