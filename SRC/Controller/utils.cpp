#include <sstream>
#include "utils.h"
#include "../Model/dna_meta_data.h"


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


bool Utils::isNum(const std::string& str)
{
    return str.find_first_not_of("0123456789") == std::string::npos;
}