#include <fstream>

#include "inc/parser.h"
#include "inc/error.h"

using std::istream;
using std::string;

Parser::Parser ( istream & is )
    : submission ( is ), lineNum (0)
{

}

string Parser::getNextWord ()
{
    string word;

    if ( currentLineIst >> word )
    {
        return word;
    }
    else if ( currentLineIst.eof() )
    {
        if ( readNextLine() )
        {
            return getNextWord();
        }
        else
        {
            return "";
        }
    }
    else
    {
        throw Error ( "Read error" );
    }

}

bool Parser::readNextLine ()
{
    if ( getline( submission, currentLineStr ) )
    {
        currentLineIst.clear();
        currentLineIst.str( currentLineStr );
        lineNum++;
        return true;
    }
    else if ( submission.eof() )
    {
        return false;
    }
    else
    {
        throw Error ( "Read error" );
    }
}

string Parser::getCurrentLine() const
{
    return currentLineStr;
}

unsigned int Parser::getLineNum() const
{
    return lineNum;
}
