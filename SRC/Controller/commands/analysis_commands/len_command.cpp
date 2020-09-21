#include <stdexcept>
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


void LenCommand::execute(IReader* input, IWriter* output, DBDNASequence* database)const
{
    std::string nameDNA;
    DNAMetaData* pDNA = Utils::findDNAMetaData((*m_pParams)[1][0], (*m_pParams)[1].substr(1), database);

    output->write((Utils::castNumToStr(pDNA->getDNASequence().length()) + "\n").c_str());
}


bool LenCommand::isValidParams()const
{
    return 2 == m_pParams->getSize()  && ('@' == (*m_pParams)[1][0] ||
        ('#' == (*m_pParams)[1][0] && Utils::isNum((*m_pParams)[1].substr(1))));
}
