#include <sstream>
#include "utils.h"
#include "../Model/dna_meta_data.h"
#include "../Model/db_dna_sequences.h"


std::string Utils::getShortDNADataFormat(const DNAMetaData *pDNAMetaData)
{
    std::stringstream data;
    size_t lengthDNA = pDNAMetaData->getDNASequence().length();

    data << "[" << pDNAMetaData->getId() << "] " << pDNAMetaData->getName() << ": ";

    if(lengthDNA > 40)
    {
        data << pDNAMetaData->getDNASequence().slice(0,33) << "..." << pDNAMetaData->getDNASequence().slice(lengthDNA - 3, lengthDNA);
    }

    else
    {
        data << pDNAMetaData->getDNASequence();
    }

    data << "\n";

    return data.str();
}


std::string Utils::getValidDNAName(const std::string& name, DBDNASequence* database)
{
    std::string tempName = name;
    DNAMetaData* pDNAMetaData;

    while(database->isNameExists(tempName))
    {
        pDNAMetaData = database->findDNAByName(name);
        std::stringstream out;
        out << tempName << "_" << pDNAMetaData->getCountCopies();
        tempName = out.str();
    }

    return tempName;
}


DNAMetaData* Utils::findDNAMetaData(char c, const std::string& str, DBDNASequence* database)
{
    size_t idDNA;

    switch(c)
    {
        case '@':
            return database->findDNAByName(str);

        case '#':
            idDNA = Utils::castStrToNum(str);
            return database->findDNAById(idDNA);

        default :
            return NULL;
    }
}


size_t Utils::castStrToNum(const std::string& str)
{
    std::istringstream in(str);
    size_t num;
    in >> num;

    return num;
}


std::string Utils::castNumToStr(size_t num)
{
    std::stringstream out;
    out << num;

    return out.str();
}


bool Utils::isNum(const std::string& str)
{
    return str.find_first_not_of("0123456789") == std::string::npos;
}