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

    // getters
    std::string getCurrentLine () const;
    unsigned int getLineNum () const;

private:
    /**
     * @brief Parser::readNextLine reads the next line in submission and saves it
     *          to currentLineStr and currentLineIst
     * @return true if reading was successful
     */
    bool readNextLine ();

    /**
     * @brief returns the next character in submission while taking care of line
     *          numbers and current line
     * @return the next character in submission
     */
    char getNextChar ();
    // current line number
    unsigned int lineNum;
    // pos in line
    unsigned int pos;
    // string of current line
    std::string currentLineStr;
    // stringstream of current line
    std::istringstream currentLineIst;
    // inputstream of complete submission (points to is)
    std::istream & submission;
    // states a word can be in
    enum State { stInSpace, stInWord, stInNum };
    // the actual state the current word is in
    State state;

};

#endif // PARSER_H
