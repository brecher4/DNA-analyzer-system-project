#ifndef DNA_SEQUENCE_FILE_WRITER_H
#define DNA_SEQUENCE_FILE_WRITER_H


#include <string>
#include "i_writer.h"


class FileWriter:public IWriter
{
public:
    FileWriter(const std::string& fileName);

    /* virtual */ void write(const char* sequence)const;

private:
    std::string m_fileName;
};


#endif //DNA_SEQUENCE_FILE_WRITER_H
