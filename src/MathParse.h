#pragma once

#include <string>
#include <vector>
#include <cctype>

using namespace std;

struct Token {
    int type;
    int value;
};

string ParseMathExpression( const string expression );
bool isValidExpression( const string expression );
void generateTokens( vector<Token> &tokens, const string expression );
