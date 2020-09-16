#include "dna_meta_data.h"
#include <sstream>


DNAMetaData::DNAMetaData(const DNASequence& dnaSequence, const std::string& name):
                            m_name(name),m_status(NEW),m_DNASequence(dnaSequence),m_countCopies(1)
{
    static size_t s_id = 1;

    m_id = s_id;
    ++s_id;
}


std::string DNAMetaData::getDNADataFormat()
{
    std::stringstream data;

    data << "[" << m_id << "] " << m_name << ": " << m_DNASequence << "\n";

    return data.str();
}
