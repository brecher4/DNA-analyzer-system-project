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
    DNAMetaData(const DNASequence& dnaSequence, const std::string& name);

    size_t getId()const { return m_id; }
    const std::string& getName()const { return m_name; }
    const DNASequence& getDNASequence()const { return m_DNASequence; }
    size_t getCountCopies() { return m_countCopies++; }

    std::string getDNADataAsStr();

private:
    size_t m_id;
    std::string m_name;
    Status m_status;
    DNASequence m_DNASequence;
    size_t m_countCopies;
};


#endif //SRC_DNA_META_DATA_H
