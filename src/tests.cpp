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
    string exp = "100*(10+3)/(3^3(6))";
    bool isValidExp;

    isValidExp = isValidExpression( exp );

    REQUIRE( isValidExp == true );
};

TEST_CASE( "isValidExpression - Addition at end of string" )
{
    string exp = "1+";
    bool isValidExp;

    isValidExp = isValidExpression( exp );
    
    REQUIRE( isValidExp == false );
};

TEST_CASE( "isValidExpression - Addition at beginning of string" )
{
    string exp = "+1";
    bool isValidExp;

    isValidExp = isValidExpression( exp );

    REQUIRE( isValidExp == false );
};

TEST_CASE( "isValidExpression - Two + in a row" )
{
    string exp = "1++3";
    bool isValidExp;

    isValidExp = isValidExpression( exp );

    REQUIRE( isValidExp == false );
};

TEST_CASE( "isValidExpression - Subtraction at end of string" )
{
    string exp = "1-";
    bool isValidExp;

    isValidExp = isValidExpression( exp );

    REQUIRE( isValidExp == false );
};

TEST_CASE( "isValidExpression - Subtraction at beginning of string" )
{
    string exp = "-1";
    bool isValidExp;

    isValidExp = isValidExpression( exp );

    REQUIRE( isValidExp == true );
};

TEST_CASE( "isValidExpression - Two - in a row" )
{
    string exp = "1--3";
    bool isValidExp;

    isValidExp = isValidExpression( exp );

    REQUIRE( isValidExp == false );
};

TEST_CASE( "generateTokens - simple 1+1" )
{
    vector<int[2]> tokens;
    string exp = "1+1";

    generateTokens( tokens, exp );

    REQUIRE( tokens.at(0)[0] == 0 );
    REQUIRE( tokens.at(0)[1] == 1 );
    REQUIRE( tokens.at(1)[0] == 1 );
    REQUIRE( tokens.at(1)[1] == 1 );
};
