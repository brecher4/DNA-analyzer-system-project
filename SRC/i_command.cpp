#include <sstream>
#include "i_command.h"
#include "db_dna_sequences.h"
#include "dna_meta_data.h"


std::string ICommand::getValidDNAName(const std::string& name, DBDNASequence* database)
{
    std::string tempName = name;
    DNAMetaData* pDNAMetaData;

    while(database->isNameExists(name))
    {
        pDNAMetaData = database->findDNAByName(name);
        std::stringstream out;
        out << tempName << "_" << pDNAMetaData->getCountCopies();
        tempName = out.str();
    }

    return tempName;
}
