#define CATCH_CONFIG_MAIN // Tell catch to handle my main
#include "catch/catch.hpp"

#include "MathParse.h"

TEST_CASE( "Useless - Make sure Make works" )
{
    string ans;

    ans = ParseMathExpression( "1+1" );

    REQUIRE( ans != "" );
};

TEST_CASE( "isValidExpression - Simple addition with no parenthesis" )
{
    string exp = "1+1";
    bool isValidExp;

    isValidExp = isValidExpression( exp );

    REQUIRE( isValidExp == true );
};

TEST_CASE( "isValidExpression - Matched Parenthesis" )
{
    string exp = "(10+20)*2";
    bool isValidExp;

    isValidExp = isValidExpression( exp );

    REQUIRE( isValidExp == true );
};

TEST_CASE( "isValidExpression - Non-Matched parenthesis" )
{
    string exp = "10+10)*22";
    bool isValidExp;

    isValidExp = isValidExpression( exp );

    REQUIRE( isValidExp == false );
};

TEST_CASE( "isValidExpression - Multi-Layered Parenthesis" )
{
    string exp = "100*(10+3)/(3**3(6))";
    bool isValidExp;

    isValidExp = isValidExpression( exp );

    REQUIRE( isValidExp == true );
};
