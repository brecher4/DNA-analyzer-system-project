#include "db_dna_sequences.h"
#include "dna_meta_data.h"


void DBDNASequence::addNewDNA(DNAMetaData *dnaMetaData)
{
    m_hashTableById.insert(std::pair<size_t, DNAMetaData*>(dnaMetaData->getId(), dnaMetaData));
    m_hashTableByName.insert(std::pair<std::string, size_t>(dnaMetaData->getName(), dnaMetaData->getId()));
}
