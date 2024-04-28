#include "MathParse.h"

string ParseMathExpression( string expression )
{
    return expression;
}

bool isValidExpression( string expression )
{
    int parenCount = 0;
    bool isValid = true;
    
    for ( int i=0; i < expression.size(); i++ )
    {
        if ( expression.at(i) == '(' )
        {
            parenCount++;
        } else if ( expression.at(i) == ')' )
        {
            parenCount--;
        }

        if ( parenCount < 0 )
        {
            isValid = false;
        }
    }

    return isValid;
}
