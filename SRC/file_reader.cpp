#include <fstream>
#include "file_reader.h"


FileReader::FileReader(const std::string& fileName)
{
    m_data = readFromFile(fileName);
}


std::string FileReader::readFromFile(const std::string& fileName)
{
    std::string data;
    std::ifstream myFile;
    myFile.open(fileName.c_str());

    if(myFile.is_open())
    {
        getline(myFile, data);
        myFile.close();
    }

    else
    {
        throw std::runtime_error("UNABLE TO OPEN THE FILE :(");
    }

    return data;
}
