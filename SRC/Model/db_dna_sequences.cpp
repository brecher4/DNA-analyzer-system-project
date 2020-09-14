#include <stdexcept>
#include "db_dna_sequences.h"
#include "dna_meta_data.h"


void DBDNASequence::addNewDNA(DNAMetaData *dnaMetaData)
{
    m_hashTableById.insert(std::pair<size_t, DNAMetaData*>(dnaMetaData->getId(), dnaMetaData));
    m_hashTableByName.insert(std::pair<std::string, size_t>(dnaMetaData->getName(), dnaMetaData->getId()));
}


DNAMetaData* DBDNASequence::findDNAById(size_t idDNA)
{
    HashById::iterator iter = m_hashTableById.find(idDNA);

    if(iter == m_hashTableById.end())
    {
        throw std::invalid_argument("ID NOT FOUND IN DATABASE");
    }

    return iter->second;
}


DNAMetaData* DBDNASequence::findDNAByName(std::string nameDNA)
{
    HashByName::iterator iter = m_hashTableByName.find(nameDNA);

    if(iter == m_hashTableByName.end())
    {
        throw std::invalid_argument("NAME NOT FOUND IN DATABASE");
    }

    return findDNAById(iter->second);
}


bool DBDNASequence::isNameExists(std::string nameDNA)
{
    try
    {
        findDNAByName(nameDNA);
    }

    catch(std::invalid_argument& e)
    {
        return false;
    }

    return true;
}
