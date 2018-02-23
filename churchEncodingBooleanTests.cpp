#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
#include <functional>

using namespace std;

//TRUE = {x -> { y -> x}}
auto TRUE = [](auto x){
    return [x](auto y){
        return x;
    };
};

//FALSE = {x -> { y -> y}}
auto FALSE = [](auto x){
   return [](auto y){
        return y;
   };
};

//IF = {proc -> { x ->  { y -> proc(x)(y) }}}
auto IF = [](auto proc){
    return [proc](auto x){
       return [x, proc](auto y){
           return proc(x)(y);
       };
    };
};

//to_boolean = {proc -> IF(proc)(true)(false) }
auto to_boolean = [](auto proc){
    return IF(proc)(true)(false);
};

TEST_CASE("true, false and if work"){
    CHECK(FALSE(true)(false) == false);
    CHECK(TRUE(true)(false) == true);

    CHECK(IF(TRUE)("foo")("bar") == "foo");
    CHECK(IF(FALSE)("foo")("bar") == "bar");

    CHECK(to_boolean(TRUE) == true);
    CHECK(to_boolean(FALSE) == false);
} 
