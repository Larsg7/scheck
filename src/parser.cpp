#include <fstream>

#include "inc/parser.h"
#include "inc/error.h"

using std::istream;
using std::string;

/**
 * initialises submission and lineNum
 */
Parser::Parser ( istream & is )
    : submission ( is ), lineNum ( 0 ),
      pos ( 0 ), state ( stInSpace )
{
}


string Parser::getNextWord ()
{
    string word;

    while ( char c = getNextChar() )
    {
        switch ( state ) {
        case stInSpace:
            if ( std::isalpha( c ) )
            {
                word += c;
                state = stInWord;
            }
            else if ( std::isdigit( c ) )
            {
                state = stInNum;
            }
            break;
        case stInWord:
            if ( std::isalpha( c ) || c == '\'' )
            {
                word += c;
            }
            else if ( std::isdigit( c ) )
            {
                state = stInNum;
            }
            else
            {
                state = stInSpace;
                return word;
            }
            break;
         case stInNum:
            if ( std::isalnum( c ) || c == '\'' )
            {
                word += c;
            }
            else
            {
                state = stInSpace;
                word = "";
            }
            break;
        default:
            throw Error ( "character is in bad state" );
            break;
        }
    }
    return word;

}

char Parser::getNextChar ()
{
    if ( pos >= currentLineStr.size() )
    {
        if ( ! readNextLine() )
        {
            return 0;
        }
    }
    return currentLineStr[ pos++ ];
}

bool Parser::readNextLine ()
{
    if ( getline( submission, currentLineStr ) ) // is there a new line to be read?
    {
        pos = 0;
        currentLineIst.clear();
        currentLineIst.str( currentLineStr );
        currentLineStr += " ";
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
