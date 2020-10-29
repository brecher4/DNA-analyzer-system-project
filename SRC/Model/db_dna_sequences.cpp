#include <stdexcept>
#include <algorithm>
#include "db_dna_sequences.h"


DBDNASequence::DBDNASequence()
{
    std::vector<size_t> vec;

    m_hashTableByStatus.insert(std::pair<Status, std::vector<size_t> >(UP_TO_DATA, vec));
    m_hashTableByStatus.insert(std::pair<Status, std::vector<size_t> >(MODIFIED, vec));
    m_hashTableByStatus.insert(std::pair<Status, std::vector<size_t> >(NEW, vec));
}


void DBDNASequence::addNewDNA(DNAMetaData *dnaMetaData)
{
    m_hashTableById.insert(std::pair<size_t, DNAMetaData*>(dnaMetaData->getId(), dnaMetaData));
    m_hashTableByName.insert(std::pair<std::string, size_t>(dnaMetaData->getName(), dnaMetaData->getId()));
    m_hashTableByStatus.at(dnaMetaData->getStatus()).push_back(dnaMetaData->getId());
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


void DBDNASequence::setStatusDNA(DNAMetaData* dnaMetaData, Status status)
{
    size_t id = dnaMetaData->getId();
    std::vector<size_t>& vec = m_hashTableByStatus.at(dnaMetaData->getStatus());
    std::vector<size_t>::iterator iter = std::find(vec.begin(), vec.end(), id);
    vec.erase(iter);
    m_hashTableByStatus.at(status).push_back(id);
    dnaMetaData->setStatus(status);
}


std::vector<size_t> DBDNASequence::getIdsByOrder()const
{
    HashById::const_iterator iter;
    std::vector<size_t> vecIds;

    for(iter = m_hashTableById.begin(); iter != m_hashTableById.end(); ++iter)
    {
        vecIds.push_back(iter->first);
    }

    std::sort(vecIds.begin(), vecIds.end());

    return vecIds;
}


size_t DBDNASequence::getNumModifiedDNA()const
{
    return m_hashTableByStatus.at(MODIFIED).size();
}


size_t DBDNASequence::getNumNewDNA()const
{
    return m_hashTableByStatus.at(NEW).size();
}
