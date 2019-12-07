

#include "gtest/gtest.h"
#include "iostream"
#include "Factory.h"
#include "Function.h"

#include <cmath>
#include <chrono>



TEST (Function_find_root, newton_method_1) {
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

TEST (Function_find_root, newton_method_2) {
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


TEST (Function_find_root, newton_method_3) {
    // arrange
    TFunctionFactory factory;
    auto f = factory.CreateObject("exp", 1);
    auto g = factory.CreateObject("const", 1);
    //act
    //плохо если стартовать там где производная близка к 0
    auto root = newton_method(f-g, 50, -3); // e^x - 1

    double root1 = 0;
    double surround = 0.25 ;

    bool res_check = (root >= root1-surround &&  root <= root1+0.5 );

    // assert
    ASSERT_EQ (true,res_check) << root << "  " << f->ToString();
}

TEST (Exceptions, logic_error_1) {
    // arrange
    TFunctionFactory factory;
    auto f = factory.CreateObject("exp", 1);
    //act

    // assert
    ASSERT_THROW (f+"aaa", std::logic_error) << "Hm... no throw " ;
}

TEST (Exceptions, logic_error_2) {
    // arrange
    TFunctionFactory factory;
    auto f = factory.CreateObject("exp", 1);
    //act

    // assert
    ASSERT_THROW (f+5, std::logic_error) << "Hm... no throw " ;
}

TEST (Exceptions, logic_error_3) {
    // arrange
    TFunctionFactory factory;
    auto f = factory.CreateObject("exp", 1);
    //act

    // assert
    ASSERT_THROW (f+(double)5, std::logic_error) << "Hm... no throw " ;
}

TEST (Exceptions, logic_error_4) {
    // arrange
    TFunctionFactory factory;
    auto f = factory.CreateObject("exp", 1);
    //act

    // assert
    ASSERT_THROW ((double)5+f, std::logic_error) << "Hm... no throw " ;
}

TEST (Exceptions, logic_error_5) {
    // arrange
    TFunctionFactory factory;
    auto f = factory.CreateObject("exp", 1);
    //act

    // assert
    ASSERT_THROW ("hmm"+f, std::logic_error) << "Hm... no throw " ;
}


TEST (NoExceptions, operation_plus) {
    // arrange
    TFunctionFactory factory;
    auto f = factory.CreateObject("exp");
    auto g = factory.CreateObject("power", 2);
    //act

    // assert
    ASSERT_NO_THROW (f+g) << "Hm... exception  " ;
}
TEST (NoExceptions, operation_minus) {
    // arrange
    TFunctionFactory factory;
    auto f = factory.CreateObject("exp");
    auto g = factory.CreateObject("power", 2);
    //act

    // assert
    ASSERT_NO_THROW (f-g) << "Hm... exception  " ;
}

TEST (NoExceptions, operation_multiply) {
    // arrange
    TFunctionFactory factory;
    auto f = factory.CreateObject("exp");
    auto g = factory.CreateObject("power", 2);
    //act

    // assert
    ASSERT_NO_THROW (f*g) << "Hm... exception  " ;
}
TEST (NoExceptions, operation_division) {
    // arrange
    TFunctionFactory factory;
    auto f = factory.CreateObject("exp");
    auto g = factory.CreateObject("power", 2);
    //act

    // assert
    ASSERT_NO_THROW (f/g) << "Hm... exception  " ;
}

TEST (Factory, CreateObject_ident) {
    // arrange
    TFunctionFactory factory;
    auto f = factory.CreateObject("ident");
    //act
    // assert
    ASSERT_NE (nullptr, f) << "Hm... object not created" ;
}

TEST (Factory, CreateObject_const) {
    // arrange
    TFunctionFactory factory;
    auto f = factory.CreateObject("const");
    //act
    // assert
    ASSERT_NE (nullptr, f) << "Hm... object not created" ;
}

TEST (Factory, CreateObject_exp) {
    // arrange
    TFunctionFactory factory;
    auto f = factory.CreateObject("exp");
    //act
    // assert
    ASSERT_NE (nullptr, f) << "Hm... object not created" ;
}

TEST (Factory, CreateObject_power) {
    // arrange
    TFunctionFactory factory;
    auto f = factory.CreateObject("power");
    //act
    // assert
    ASSERT_NE (nullptr, f) << "Hm... object not created" ;
}

TEST (Factory, CreateObject_polynomial) {
    // arrange
    TFunctionFactory factory;
    auto f = factory.CreateObject("polynomial");
    //act
    // assert
    ASSERT_NE (nullptr, f) << "Hm... object not created" ;
}


TEST (Factory, CreateObject_wrong) {
    // arrange
    TFunctionFactory factory;
    auto f = factory.CreateObject("abracadabra");
    //act
    // assert
    ASSERT_EQ (nullptr, f) << "Hm... object abracadabra created" ;
}

TEST (Function_value_check, TIdent) {
    // arrange
    TFunctionFactory factory;
    auto f = factory.CreateObject("ident");
    //act
    double x = rand()%256; //
    double f_x = (*f)(x);
    double real_f_x = x;
    // assert
    ASSERT_EQ (f_x, real_f_x) << "Hm... "<<f->ToString()<<" = "<<f_x<<" if x="<<x;
}

TEST (Function_value_check, TConst) {
    // arrange
    TFunctionFactory factory;
    auto f = factory.CreateObject("const", 25);
    //act
    double x = rand()%256; //
    double f_x = (*f)(x);
    double real_f_x = 25;
    // assert
    ASSERT_EQ (f_x, real_f_x) << "Hm... "<<f->ToString()<<" = "<<f_x<<" if x="<<x;
}

TEST (Function_value_check, TExp) {
    // arrange
    TFunctionFactory factory;
    auto f = factory.CreateObject("exp");
    //act
    double x = rand()%256; //
    double f_x = (*f)(x);
    double real_f_x = std::exp(x);
    // assert
    ASSERT_EQ (f_x, real_f_x) << "Hm... "<<f->ToString()<<" = "<<f_x<<" if x="<<x;
}

TEST (Function_value_check, TPolynomial) {
    // arrange
    TFunctionFactory factory;
    auto f = factory.CreateObject("polynomial", {1,2,3,4,5});
    //act
    double x = rand()%256; //
    double f_x = (*f)(x);
    double real_f_x =1+ 2*std::pow(x,1)+3*std::pow(x,2)+4*std::pow(x,3)+5*std::pow(x,4);
    // assert
    ASSERT_EQ (f_x, real_f_x) << "Hm... "<<f->ToString()<<" = "<<f_x<<" if x="<<x;
}

TEST (Function_value_check, TPower) {
    // arrange
    TFunctionFactory factory;
    double pow = rand()%256;
    auto f = factory.CreateObject("power", pow );
    //act
    double x = rand()%256; //
    double f_x = (*f)(x);
    double real_f_x =std::pow(x,pow);
    // assert
    ASSERT_EQ (f_x, real_f_x) << "Hm... "<<f->ToString()<<" = "<<f_x<<" if x="<<x;
}


TEST (Function_derivity_value_check, TIdent) {
    // arrange
    TFunctionFactory factory;
    auto f = factory.CreateObject("ident");
    //act
    double x = rand()%256; //
    double f_x = f->GetDeriv(x);
    double real_f_x =1;
    // assert
    ASSERT_EQ (f_x, real_f_x) << "Hm... "<<f->ToString()
                               <<" derivity equal to "<<f_x<<" if x="<<x;
}

TEST (Function_derivity_value_check, TConst) {
    // arrange
    TFunctionFactory factory;
    auto f = factory.CreateObject("const",120);
    //act
    double x = rand()%256; //
    double f_x = f->GetDeriv(x);
    double real_f_x =0;
    // assert
    ASSERT_EQ (f_x, real_f_x) << "Hm... "<<f->ToString()
                               <<" derivity equal to "<<f_x<<" if x="<<x;
}

TEST (Function_derivity_value_check, TExp) {
    // arrange
    TFunctionFactory factory;
    auto f = factory.CreateObject("exp");
    //act
    double x = rand()%256; //
    double f_x = f->GetDeriv(x);
    double real_f_x = std::exp(x);
    // assert
    ASSERT_EQ (f_x, real_f_x) << "Hm... "<<f->ToString()
                               <<" derivity equal to "<<f_x<<" if x="<<x;
}

TEST (Function_derivity_value_check, TPower) {
    // arrange
    TFunctionFactory factory;
    double pow = rand()%256;
    
    auto f = factory.CreateObject("power", pow);
    //act
    double x = rand()%256; //
    double f_x = f->GetDeriv(x);
    double real_f_x = pow*std::pow(x,pow-1);

    // assert
    ASSERT_EQ (f_x, real_f_x) << "Hm... "<<f->ToString()
                               <<" derivity equal to "<<f_x<<" if x="<<x;
}

TEST (Function_derivity_value_check, TPolynomial) {
    // arrange
    TFunctionFactory factory;
   
    auto f = factory.CreateObject("polynomial", {1,2,3,4,5});
    //act
    double x = rand()%256; //
    double f_x = f->GetDeriv(x);
    double real_f_x =2+6*x+12*std::pow(x,2)+20*std::pow(x,3);

    // assert
    ASSERT_EQ (f_x, real_f_x) << "Hm... "<<f->ToString()
                               <<" derivity equal to "<<f_x<<" if x="<<x;
}





int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
    srand(millis%40960);
    return  RUN_ALL_TESTS();;
}