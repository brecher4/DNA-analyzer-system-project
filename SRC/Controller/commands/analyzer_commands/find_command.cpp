#include <stdexcept>
#include <sstream>
#include <string>
#include "find_command.h"
#include "../../parser_params.h"
#include "../../../Model/db_dna_sequences.h"
#include "../../../Model/dna_meta_data.h"


void FindCommand::initParams(const ParserParams& params)
{
    m_pParams = &params;

    if(!isValidParams())
    {
        throw std::invalid_argument("INVALID PARAMETERS");
    }
}


void FindCommand::execute(IWriter* output, DBDNASequence* database)const
{
    DNAMetaData* pDNA1;
    DNAMetaData* pDNA2 = NULL;
    std::string nameDNA;
    size_t index;

    if('@' == (*m_pParams)[1][0])
    {
        pDNA1 = database->findDNAByName((*m_pParams)[1].substr(1));
    }

    else
    {
        std::istringstream in((*m_pParams)[1].substr(1));
        size_t idDNA;
        in >> idDNA;
        pDNA1 = database->findDNAById(idDNA);
    }

    if('@' == (*m_pParams)[2][0])
    {
        pDNA2 = database->findDNAByName((*m_pParams)[2].substr(1));
    }

    else if('#' == (*m_pParams)[2][0])
    {
        std::istringstream in((*m_pParams)[2].substr(1));
        size_t idDNA;
        in >> idDNA;
        pDNA2 = database->findDNAById(idDNA);
    }

    if(pDNA2)
    {
        index = pDNA1->getDNASequence().find(pDNA2->getDNASequence());
    }

    else
    {
        index = pDNA1->getDNASequence().find((*m_pParams)[2]);
    }

    std::stringstream out;
    out << index;
    output->write(out.str().c_str());
}


bool FindCommand::isValidParams()
{
    return 3 == (*m_pParams).getSize()  && ('@' == (*m_pParams)[1][0] || ('#' == (*m_pParams)[1][0] &&
        (*m_pParams)[1].substr(1).find_first_not_of("0123456789") == std::string::npos)) &&
        ('#' != (*m_pParams)[2][0] || (*m_pParams)[2].substr(1).find_first_not_of("0123456789") == std::string::npos);
}
