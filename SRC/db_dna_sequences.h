#ifndef SRC_DB_DNA_SEQUENCES_H
#define SRC_DB_DNA_SEQUENCES_H


#include <map>
#include <string>


class DNAMetaData;


class DBDNASequence
{
public:
    void addNewDNA(DNAMetaData* dnaMetaData);
    DNAMetaData* findDNAById(size_t idDNA);
    DNAMetaData* findDNAByName(std::string nameDNA);
    bool isNameExists(std::string nameDNA);

private:
    typedef std::map<size_t, DNAMetaData*> HashById;
    typedef std::map<std::string, size_t> HashByName;

    HashById m_hashTableById;
    HashByName m_hashTableByName;
};


#endif //SRC_DB_DNA_SEQUENCES_H
