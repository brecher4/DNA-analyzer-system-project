#ifndef DNA_SEQUENCE_FILE_READER_H
#define DNA_SEQUENCE_FILE_READER_H


#include <string>
#include "reader.h"


class FileReader:public Reader
{
public:
    FileReader(const std::string& fileName);

    /* virtual */ void initInput();

private:
    std::string m_fileName;
};


#endif //DNA_SEQUENCE_FILE_READER_H
