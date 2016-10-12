#include <fstream>

#include "inc/parser.h"
#include "inc/error.h"

using std::istream;
using std::string;

/**
 * initialises submission and lineNum
 */
Parser::Parser ( istream & is )
    : submission ( is ), lineNum ( 0 )
{
}


string Parser::getNextWord ()
{
    string word;

    if ( currentLineIst >> word )       // check if we can read from current line
    {
        return word;
    }
    else if ( currentLineIst.eof() )    // are we at the end of current line?
    {
        if ( readNextLine() )           // is there a next line to be read?
        {
            return getNextWord();       // try getting a new word
        }
        else                            // we have reached the end of the file
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
    if ( getline( submission, currentLineStr ) ) // is there a new line to be read?
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
