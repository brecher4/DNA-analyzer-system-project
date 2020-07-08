#include <fstream>
#include "file_reader.h"


FileReader::FileReader(const std::string& fileName):m_fileName(fileName){}


void FileReader::initInput()
{
    std::ifstream myFile;
    myFile.open(m_fileName.c_str());

    if(myFile.is_open())
    {
        getline(myFile, m_data);
        myFile.close();
    }

    else
    {
        throw std::runtime_error("UNABLE TO OPEN THE FILE :(");
    }
}
