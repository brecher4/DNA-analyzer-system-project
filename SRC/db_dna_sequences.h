#ifndef SRC_DB_DNA_SEQUENCES_H
#define SRC_DB_DNA_SEQUENCES_H


#include <map>
#include <string>


class DNAMetaData;


class DBDNASequence
{
public:
    static void addNewDNA(DNAMetaData* dnaMetaData);

private:
    static std::map<size_t, DNAMetaData*> m_hashTableById;
    static std::map<std::string, size_t> m_hashTableByName;
};


#endif //SRC_DB_DNA_SEQUENCES_H
