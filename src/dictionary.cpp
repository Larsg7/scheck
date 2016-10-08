#include <fstream>
#include <string>
#include <iostream>

#include "inc/error.h"
#include "inc/dictionary.h"

Dictionary::Dictionary ( const std::string & fname )
{
    std::ifstream is ( fname );
    std::string word;

    if ( ! is.is_open() )
    {
        throw Error ( "Could not open wordlist " + fname );
    }

    while ( std::getline( is, word ) )
    {
        wordsInDic.insert( word );
    }

    if ( ! is.eof() )
    {
        throw Error ( "Error reading "+fname );
    }
}

bool Dictionary::Check( const std::string & word ) const
{
    return wordsInDic.find( word ) != wordsInDic.end();
}
