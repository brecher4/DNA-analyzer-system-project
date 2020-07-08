#ifndef SRC_DB_DNA_SEQUENCES_H
#define SRC_DB_DNA_SEQUENCES_H


#include <map>
#include <string>


class DNAMetaData;


class DBDNASequence
{
public:
    void addNewDNA(DNAMetaData* dnaMetaData);

private:
    std::map<size_t, DNAMetaData*> m_hashTableById;
    std::map<std::string, size_t> m_hashTableByName;
};


#endif //SRC_DB_DNA_SEQUENCES_H
