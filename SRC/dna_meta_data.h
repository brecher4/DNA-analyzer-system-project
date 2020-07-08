#ifndef SRC_DNA_META_DATA_H
#define SRC_DNA_META_DATA_H


#include <string>
#include "dna_sequence.h"


enum Status
{
    UP_TO_DATA,
    MODIFIED,
    NEW
};


class DNAMetaData
{
public:
    DNAMetaData(const DNASequence& dnaSequence, const std::string& name = "");

    const std::string& getName()const { return m_name; }
    size_t getId()const { return m_id; }

    std::string getDNADataAsStr();

private:
    size_t m_id;
    std::string m_name;
    Status m_status;
    DNASequence m_DNASequence;
};


#endif //SRC_DNA_META_DATA_H
