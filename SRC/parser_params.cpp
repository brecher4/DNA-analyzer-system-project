#include "parser_params.h"
#include "i_reader.h"


void ParserParams::parseInput(const IReader& input, char delimiter)
{
    std::string dataInput = input.read();
    size_t sizeVector = m_params.size();
    size_t i = 0;
    size_t indexDelimiter;

    if(dataInput.empty())
    {
        if(i < sizeVector)
        {
            m_params[0] = "";
        }

        else
        {
            m_params.push_back("");
        }
    }

    while(i < sizeVector && !dataInput.empty())
    {
        indexDelimiter = dataInput.find(delimiter);
        m_params[i] = dataInput.substr(0, indexDelimiter);
        dataInput.erase(0, indexDelimiter + 2);
        ++i;
    }

    while(!dataInput.empty())
    {
        indexDelimiter = dataInput.find(delimiter);
        m_params.push_back(dataInput.substr(0, indexDelimiter));
        dataInput.erase(0, indexDelimiter + 2);
        ++i;
    }

    m_size = i;
}


const std::string &ParserParams::operator[](size_t index) const
{
    return m_params[index];
}
