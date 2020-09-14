#include <stdexcept>
#include <sstream>
#include "dup_command.h"
#include "parser_params.h"
#include "db_dna_sequences.h"
#include "dna_meta_data.h"


DupCommand::DupCommand(const ParserParams& params): CreationCommands(params)
{
    if(!isValidParams())
    {
        throw std::invalid_argument("INVALID PARAMETERS");
    }
}


void DupCommand::execute(IWriter* output, DBDNASequence* database)const
{
    DNAMetaData* pDNA;
    std::string nameDNA;

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

    if(3 == (*m_pParams).getSize())
    {
        nameDNA = ICommand::getValidDNAName((*m_pParams)[2].substr(1), database);
    }

    else
    {
        nameDNA = ICommand::getValidDNAName(pDNA->getName(), database);
    }

    pDNA = new DNAMetaData(pDNA->getDNASequence(),nameDNA);
    database->addNewDNA(pDNA);

    output->write(pDNA->getDNADataAsStr().c_str());
}


bool DupCommand::isValidParams()
{
    return (2 == (*m_pParams).getSize()  && ('@' == (*m_pParams)[1][0] || '#' == (*m_pParams)[1][0])) ||
            ((3 == (*m_pParams).getSize() && '@' == (*m_pParams)[2][0]) && ('@' == (*m_pParams)[1][0] || '#' == (*m_pParams)[1][0]));
}