#include "MathParse.h"

string ParseMathExpression( const string expression )
{
    return expression;
}

bool isValidExpression( const string expression )
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

void generateTokens( vector<Token> &tokens, const string expression )
{
    int size = expression.size();
    Token token;
    
    for( int i=0; i < size; i++ )
    {
        if ( isdigit( expression.at( i ) ) )
        {
            token.type = 0;
            token.value = stoi( expression.substr( i, 1 ) );
            tokens.push_back( token );
        } else if ( expression.at( i ) == '+' )
        {
            token.type = 1;
            token.value = 0;
            tokens.push_back( token );
        } else if ( expression.at( i ) == '-' )
        {
            token.type = 1;
            token.value = 1;
            tokens.push_back( token );
        }
    }
}
