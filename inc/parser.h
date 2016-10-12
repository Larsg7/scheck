#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <sstream>
#include <iostream>


/**
 * @brief The Parser class implements methods to read the submission word for
 *          word and also returns the current line and line number the error
 *          appears
 * @todo update definition of word
 */
class Parser
{
public:

    /**
     * @brief Parser::Parser
     * @param is inputstream holding the complete submission
     */
    Parser ( std::istream & is );

    /**
     * @brief Parser::getNextWord
     * @return the next word on the currentline and/or the submission
     */
    std::string getNextWord ();

    /**
     * @brief Parser::readNextLine reads the next line in submission and saves it
     *          to currentLineStr and currentLineIst
     * @return true if reading was successful
     */
    bool readNextLine ();

    // getters
    std::string getCurrentLine () const;
    unsigned int getLineNum () const;

private:

    /**
     * @brief takes a string and attemps to "make" a word -> e.g. removes any
     *          trailing ,,",',. etc.
     * @param word the word to be checked
     * @return if successful returns the to be checked word, if not returns
     *          an empty string
     */
    std::string makeWord ( const std::string & word );
    // current line number
    unsigned int lineNum;
    // string of current line
    std::string currentLineStr;
    // stringstream of current line
    std::istringstream currentLineIst;
    // inputstream of complete submission (points to is)
    std::istream & submission;
};

#endif // PARSER_H
