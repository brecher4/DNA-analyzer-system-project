#include "file_writer.h"
#include <fstream>


FileWriter::FileWriter(const std::string& fileName):m_fileName(fileName){}


void FileWriter::write(const char* sequence)const
{
    std::ofstream myFile;
    myFile.open(m_fileName.c_str());

    if(myFile.is_open())
    {
        myFile << sequence;
        myFile.close();
    }

    else
    {
        throw std::runtime_error("UNABLE TO OPEN THE FILE :(");
    }
}
