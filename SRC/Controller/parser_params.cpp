#include <stdexcept>
#include "parser_params.h"
#include "../View/reader/i_reader.h"


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
            m_params[i] = "";
        }

        else
        {
            m_params.push_back("");
        }
    }

    while(i < sizeVector && (indexDelimiter = dataInput.find(delimiter)) != std::string::npos)
    {
        m_params[i] = dataInput.substr(0, indexDelimiter);
        dataInput.erase(0, indexDelimiter + 1);
        ++i;
    }

    while((indexDelimiter = dataInput.find(delimiter)) != std::string::npos)
    {
        m_params.push_back(dataInput.substr(0, indexDelimiter));
        dataInput.erase(0, indexDelimiter + 1);
        ++i;
    }

    if(!dataInput.empty())
    {
        if(i < sizeVector)
        {
            m_params[i] = dataInput.substr(0);
        }

        else
        {
            m_params.push_back(dataInput.substr(0));
        }

        ++i;
    }

    m_size = i;
}


const std::string& ParserParams::operator[](size_t index) const
{
    if(index < m_size || !m_size)
    {
        return m_params[index];
    }

    throw std::out_of_range("INDEX IS OUT OF RANGE PARAMETERS' NUMBER");
}
