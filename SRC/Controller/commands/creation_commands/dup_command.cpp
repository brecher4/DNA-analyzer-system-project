#include <stdexcept>
#include <sstream>
#include "dup_command.h"
#include "../../parser_params.h"
#include "../../../Model/db_dna_sequences.h"
#include "../../../Model/dna_meta_data.h"
#include "../../utils.h"


void DupCommand::initParams(const ParserParams& params)
{
    m_pParams = &params;

    if(!isValidParams())
    {
        throw std::invalid_argument("INVALID PARAMETERS");
    }
}


void DupCommand::execute(IReader* input, IWriter* output, DBDNASequence* database)const
{
    std::string nameDNA;
    DNAMetaData* pDNA = Utils::findDNAMetaData((*m_pParams)[1][0], (*m_pParams)[1].substr(1), database);

    if(3 == (*m_pParams).getSize())
    {
        nameDNA = Utils::getValidDNAName((*m_pParams)[2].substr(1), database);
    }

    else
    {
        nameDNA = Utils::getValidDNAName(pDNA->getName(), database);
    }

    pDNA = new DNAMetaData(pDNA->getDNASequence(),nameDNA);
    database->addNewDNA(pDNA);

    output->write(pDNA->getDNADataFormat().c_str());
}


bool DupCommand::isValidParams()const
{
    return (2 == m_pParams->getSize()  && ('@' == (*m_pParams)[1][0] ||
                ('#' == (*m_pParams)[1][0] && Utils::isNum((*m_pParams)[1].substr(1))))) ||
            ((3 == m_pParams->getSize() && '@' == (*m_pParams)[2][0]) && ('@' == (*m_pParams)[1][0] ||
                ('#' == (*m_pParams)[1][0] && Utils::isNum((*m_pParams)[1].substr(1)))));
}
