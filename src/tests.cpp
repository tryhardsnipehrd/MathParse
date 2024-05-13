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
    vector<Token> tokens;
    string exp = "1+1";

    generateTokens( tokens, exp );

    REQUIRE( tokens.at(0).type == 0 );
    REQUIRE( tokens.at(0).value == 1 );
    REQUIRE( tokens.at(1).type == 1 );
    REQUIRE( tokens.at(1).value == 0 );
};

TEST_CASE( "generateTokens - simple 1-1" )
{
    vector<Token> tokens;
    string exp = "1-1";

    generateTokens( tokens, exp );

    REQUIRE( tokens.at(1).type == 1 );
    REQUIRE( tokens.at(1).value == 1 );
    REQUIRE( tokens.at(2).type == 0 );
    REQUIRE( tokens.at(2).value == 1 );
};

TEST_CASE( "generateTokens - multiple digit numbers" )
{
    vector<Token> tokens;
    string exp = "19+10";

    generateTokens( tokens, exp );
    
    REQUIRE( tokens.size() == 3 );
    REQUIRE( tokens.at(0).type == 0 );
    REQUIRE( tokens.at(0).value == 19 );
    REQUIRE( tokens.at(1).type == 1 );
    REQUIRE( tokens.at(1).value == 0 );
    REQUIRE( tokens.at(2).type == 0 );
    REQUIRE( tokens.at(2).value == 10 );
};

TEST_CASE( "generateTokens - Larger equation with multiple digits" )
{
    vector<Token> tokens;
    string exp = "1911-32805+02032015-10062004";

    generateTokens( tokens, exp );

    REQUIRE( tokens.size() == 7 );
    REQUIRE( tokens.at(0).type == 0 );
    REQUIRE( tokens.at(0).value == 1911 );
    REQUIRE( tokens.at(4).type == 0 );
    REQUIRE( tokens.at(4).value == 2032015 );
};

TEST_CASE( "generateTokens - Equation with Parenthesis" )
{
    vector<Token> tokens;
    string exp = "24+(10-2)";

    generateTokens( tokens, exp );

    REQUIRE( tokens.size() == 7 );
    REQUIRE( tokens.at(0).type == 0 );
    REQUIRE( tokens.at(0).value == 24 );
    REQUIRE( tokens.at(2).type == 2 );
    REQUIRE( tokens.at(2).value == 0 );
    REQUIRE( tokens.at(6).type == 2 );
    REQUIRE( tokens.at(6).value == 1 );
};

TEST_CASE( "generateTokens - Simple Division and Multiplication" )
{
    vector<Token> tokens;
    string exp = "6*6/6";

    generateTokens( tokens, exp );

    REQUIRE( tokens.size() == 5 );
    REQUIRE( tokens.at(1).type == 1 );
    REQUIRE( tokens.at(1).value == 2 );
    REQUIRE( tokens.at(3).type == 1 );
    REQUIRE( tokens.at(3).value == 3 );
};

TEST_CASE( "generateTokens - Complex equation with parenthesis" )
{
    vector<Token> tokens;
    string exp = "(19+2)*11/(10*11)";

    generateTokens( tokens, exp );

    REQUIRE( tokens.size() == 13 );
    REQUIRE( tokens.at(0).type == 2 );
    REQUIRE( tokens.at(0).value == 0 );
    REQUIRE( tokens.at(5).type == 1 );
    REQUIRE( tokens.at(5).value == 2 );
};
