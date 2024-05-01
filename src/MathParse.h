#pragma once

#include <string>
#include <vector>
#include <cctype>

using namespace std;

string ParseMathExpression( string expression );
bool isValidExpression( string expression );
void generateTokens( vector<int[2]> &tokens, string expression );
