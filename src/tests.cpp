#define CATCH_CONFIG_MAIN // Tell catch to handle my main
#include "catch/catch.hpp"

#include "MathParse.h"

TEST_CASE( "Useless - Make sure Make works" )
{
    string ans;

    ans = ParseMathExpression( "1+1" );

    REQUIRE( ans != "" );
};
