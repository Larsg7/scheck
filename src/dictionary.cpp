/**
 * implementation of the class dictionary used to hold a wordlist and
 * check whether a word is written correctly
 */

#include <fstream>
#include <string>
#include <iostream>

#include "inc/error.h"
#include "inc/dictionary.h"

/**
 * @brief important: the wordlist has to contain one word per line!
 */
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
