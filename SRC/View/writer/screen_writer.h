#ifndef DNA_SEQUENCE_SCREENWRITER_H
#define DNA_SEQUENCE_SCREENWRITER_H


#include "i_writer.h"


class ScreenWriter: public IWriter
{
public:
    void write(const char* sequence)const;
};


#endif //DNA_SEQUENCE_SCREENWRITER_H
