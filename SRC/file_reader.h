#ifndef DNA_SEQUENCE_FILE_READER_H
#define DNA_SEQUENCE_FILE_READER_H


#include <string>
#include "reader.h"


class FileReader:public Reader
{
public:
    FileReader(const std::string& fileName);

private:
    static std::string readFromFile(const std::string& fileName);
};


#endif //DNA_SEQUENCE_FILE_READER_H
