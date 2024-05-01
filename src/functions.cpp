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
        switch ( expression.at(i) )
        {
            case '(':
                parenCount++;
                break;
            
            case ')':
                parenCount--;
                break;

            case '+':
                if ( i == expression.size() - 1 || i == 0 )
                {
                    isValid = false;
                } else if ( expression.at( i+1 ) == '+' )
                {
                    isValid = false;
                }
                break;

            case '-':
                if ( i == expression.size() - 1 )
                {
                    isValid = false;
                } else if ( expression.at( i+1 ) == '-' )
                {
                    isValid = false;
                }
                break;


        }
        if ( parenCount < 0 )
        {
            isValid = false;
        }
    }

    return isValid;
}

void generateTokens( vector<int[2]> &tokens, string expression )
{
    int size = expression.size();
    int token[2];
    
    for( int i=0; i < size; i++ )
    {
        if ( isdigit( expression.at( i ) ) )
        {
            token[0] = 0;
            token[1] = stoi( expression.substr( i, 1 ) );
            tokens.push_back( token );
        }
    }
}
