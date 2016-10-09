#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <sstream>
#include <iostream>



class Parser
{
public:
    Parser ( std::istream & is );
    std::string getNextWord ();
    bool readNextLine ();

    std::string getCurrentLine () const;
    unsigned int getLineNum () const;

private:
    std::stringstream getNextLine ();
    unsigned int lineNum;
    std::string currentLineStr;
    std::istringstream currentLineIst;
    std::istream & submission;
};

#endif // PARSER_H
