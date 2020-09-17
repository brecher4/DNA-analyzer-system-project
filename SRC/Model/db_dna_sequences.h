#ifndef SRC_DB_DNA_SEQUENCES_H
#define SRC_DB_DNA_SEQUENCES_H


#include <map>
#include <string>
#include <vector>
#include "dna_meta_data.h"


class DBDNASequence
{
public:
    DBDNASequence();

    void addNewDNA(DNAMetaData* dnaMetaData);
    DNAMetaData* findDNAById(size_t idDNA);
    DNAMetaData* findDNAByName(std::string nameDNA);
    bool isNameExists(std::string nameDNA);
    void setStatusDNA(DNAMetaData* dnaMetaData, Status status);
    std::vector<size_t> getIdsByOrder()const;
    size_t getNumModifiedDNA()const;
    size_t getNumNewDNA()const;

private:
    typedef std::map<size_t, DNAMetaData*> HashById;
    typedef std::map<std::string, size_t> HashByName;
    typedef std::map<Status, std::vector<size_t > > HashByStatus;

    HashById m_hashTableById;
    HashByName m_hashTableByName;
    HashByStatus m_hashTableByStatus;
};


#endif //SRC_DB_DNA_SEQUENCES_H
