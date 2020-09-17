#ifndef DNA_SEQUENCE_READER_H
#define DNA_SEQUENCE_READER_H


#include "i_reader.h"


class Reader:public IReader
{
public:
    /* virtual */ std::string read()const{ return m_data; }

protected:
    std::string m_data;
};


#endif //DNA_SEQUENCE_READER_H
