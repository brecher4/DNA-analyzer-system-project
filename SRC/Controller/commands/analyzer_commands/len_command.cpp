#include <stdexcept>
#include <sstream>
#include <string>
#include "len_command.h"
#include "../../parser_params.h"
#include "../../../Model/db_dna_sequences.h"
#include "../../../Model/dna_meta_data.h"
#include "../../utils.h"


void LenCommand::initParams(const ParserParams& params)
{
    m_pParams = &params;

    if(!isValidParams())
    {
        throw std::invalid_argument("INVALID PARAMETERS");
    }
}


void LenCommand::execute(IWriter* output, DBDNASequence* database)const
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

    std::stringstream len;
    len << pDNA->getDNASequence().length();
    output->write(len.str().c_str());
}


bool LenCommand::isValidParams()
{
    return 2 == (*m_pParams).getSize()  && ('@' == (*m_pParams)[1][0] || ('#' == (*m_pParams)[1][0] &&
            Utils::isNum((*m_pParams)[1])));
}
