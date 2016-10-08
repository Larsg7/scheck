#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <set>

class Dictionary
{

public:
    Dictionary ( const std::string & fname );
    bool Check ( const std::string & word ) const;

private:
    // holds all words in this dictionary
    std::set <std::string> wordsInDic;
};

#endif // DICTIONARY_H
