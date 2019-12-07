cmake_minimum_required(VERSION 3.10)
project(task2)

set(CMAKE_CXX_STANDARD 17)

include_directories (${MyProject_SOURCE_DIR}/include)


add_library(TFunction Function.cpp TConst.cpp TIdent.cpp TComplexFunc.cpp TPolynomial.cpp TExp.cpp TPower.cpp)
add_library(TFactory Factory.cpp)

