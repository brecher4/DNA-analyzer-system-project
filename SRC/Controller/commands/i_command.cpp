#include "i_command.h"
#include "../../Model/db_dna_sequences.h"
#include "../../Model/dna_meta_data.h"
#include <sstream>


std::string ICommand::getValidDNAName(const std::string& name, DBDNASequence* database)
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
