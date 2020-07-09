#include <stdexcept>
#include <sstream>
#include "save_command.h"
#include "parser_params.h"
#include "db_dna_sequences.h"
#include "file_writer.h"
#include "dna_meta_data.h"


SaveCommand::SaveCommand(const ParserParams& params): ManagementCommands(params)
{
    if(!isValidParams())
    {
        throw std::invalid_argument("INVALID PARAMETERS");
    }
}


void SaveCommand::execute(IWriter* output, DBDNASequence* database)const
{
    DNAMetaData* pDNA;

    if('@' == (*m_pParams)[1][0])
    {
        pDNA = database->findDNAByName((*m_pParams)[1].substr(1));
    }

    else
    {
        std::istringstream in((*m_pParams)[1].substr(1));
        size_t idDNA;
        in >> idDNA;
        pDNA = database->findDNAById(idDNA);
    }

    if(m_pParams->getSize() == 2)
    {
        FileWriter file(pDNA->getName() + ".rawdna");
        file.write(pDNA->getDNADataAsStr().c_str());
    }

    else
    {
        FileWriter file((*m_pParams)[2]);
        file.write(pDNA->getDNADataAsStr().c_str());
    }
}


bool SaveCommand::isValidParams()
{
    return (2 == (*m_pParams).getSize() || 3 == (*m_pParams).getSize()) &&
                ('@' == (*m_pParams)[1][0] || '#' == (*m_pParams)[1][0]);
}
