#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <set>

class Dictionary
{

public:
    /**
     * @brief contructor
     * @param fname name of the wordlist file
     */
    Dictionary ( const std::string & fname );

    /**
     * @brief checks whether a word can be found in the dictionary
     * @param word word to be checked
     * @return true if word is found, false otherwise
     */
    bool Check ( const std::string & word ) const;

private:
    // holds all words in this dictionary
    std::set <std::string> wordsInDic;
};

#endif // DICTIONARY_H
