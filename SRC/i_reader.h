#ifndef DNA_SEQUENCE_I_READER_H
#define DNA_SEQUENCE_I_READER_H


#include <string>


class IReader
{
public:
    virtual ~IReader(){}

    virtual std::string read()const = 0;
};


#endif //DNA_SEQUENCE_I_READER_H
