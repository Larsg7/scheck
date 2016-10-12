#ifndef ERROR_H
#define ERROR_H

#include <stdexcept>
#include <string>

/**
 * @brief The Error class for this project. Is used to throw errors.
 */
class Error : public std::runtime_error
{
public:
    Error ( const std::string & msg )
        : runtime_error ( msg ) {}
};

#endif // ERROR_H
