#include <stdexcept>
#include <string>
#include "count_command.h"
#include "../../parser_params.h"
#include "../../../Model/db_dna_sequences.h"
#include "../../../Model/dna_meta_data.h"
#include "../../utils.h"


void CountCommand::initParams(const ParserParams& params)
{
    m_pParams = &params;

    if(!isValidParams())
    {
        throw std::invalid_argument("INVALID PARAMETERS");
    }
}


void CountCommand::execute(IReader* input, IWriter* output, DBDNASequence* database)const
{
    bool isAllocateDNASeq = false;
    std::string nameDNA;
    size_t numAppearances;

    const DNAMetaData* pDNAMetaData1 = Utils::findDNAMetaData((*m_pParams)[1][0], (*m_pParams)[1].substr(1), database);
    const DNAMetaData* pDNAMetaData2 = Utils::findDNAMetaData((*m_pParams)[2][0], (*m_pParams)[2].substr(1), database);

    const DNASequence* pDNA1 = NULL;
    const DNASequence* pDNA2 = NULL;

    if(pDNAMetaData1)
    {
        pDNA1 = &(pDNAMetaData1->getDNASequence());
    }

    else
    {
        pDNA1 = new DNASequence((*m_pParams)[1]);
        isAllocateDNASeq = true;
    }

    if(pDNAMetaData2)
    {
        pDNA2 = &(pDNAMetaData2->getDNASequence());
        numAppearances = pDNA1->count(*pDNA2);
    }

    else
    {
        numAppearances = pDNA1->count((*m_pParams)[2]);
    }

    output->write((Utils::castNumToStr(numAppearances) + "\n").c_str());

    if(isAllocateDNASeq)
    {
        delete pDNA1;
    }
}


bool CountCommand::isValidParams()const
{
    return 3 == m_pParams->getSize()  &&
           ('#' != (*m_pParams)[1][0] || Utils::isNum((*m_pParams)[1].substr(1))) &&
           ('#' != (*m_pParams)[2][0] || Utils::isNum((*m_pParams)[2].substr(1)));
}
