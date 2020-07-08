#include "dna_meta_data.h"
#include <sstream>


DNAMetaData::DNAMetaData(const DNASequence& dnaSequence, const std::string& name):
        m_name(name),m_status(NEW),m_DNASequence(dnaSequence)
{
    static size_t s_id = 1;
    static size_t s_count = 1;

    m_id = s_id;
    ++s_id;

    if(name.empty())
    {
        std::stringstream newName;
        newName << "seq" << s_count;
        m_name = newName.str();
        ++s_count;
    }
}


std::string DNAMetaData::getDNADataAsStr()
{
    std::stringstream data;
    size_t lengthDNA = m_DNASequence.length();

    data << "[" << m_id << "] " << m_name << ": " << m_DNASequence << "\n";

    return data.str();
}
