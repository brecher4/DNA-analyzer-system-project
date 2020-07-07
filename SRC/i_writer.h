#ifndef DNA_SEQUENCE_I_WRITER_H
#define DNA_SEQUENCE_I_WRITER_H


class IWriter
{
public:
    virtual ~IWriter(){}

    virtual void write(const char* sequence)const = 0;
};


#endif //DNA_SEQUENCE_I_WRITER_H
