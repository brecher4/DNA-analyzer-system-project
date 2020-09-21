#include <stdexcept>
#include <string>
#include "find_all_command.h"
#include "../../parser_params.h"
#include "../../../Model/db_dna_sequences.h"
#include "../../../Model/dna_meta_data.h"
#include "../../utils.h"


void FindAllCommand::initParams(const ParserParams& params)
{
    m_pParams = &params;

    if(!isValidParams())
    {
        throw std::invalid_argument("INVALID PARAMETERS");
    }
}


void FindAllCommand::execute(IReader* input, IWriter* output, DBDNASequence* database)const
{
    bool isAllocateDNASeq = false;
    std::string nameDNA;
    std::list<size_t> indexes;

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
        indexes = pDNA1->findAll(*pDNA2);
    }

    else
    {
        indexes = pDNA1->findAll((*m_pParams)[2]);
    }

    if(indexes.empty())
    {
        output->write("sub sequence DNA did not found\n");
    }

    else
    {
        output->write((Utils::castNumsListToStr(indexes) + "\n").c_str());
    }

    if(isAllocateDNASeq)
    {
        delete pDNA1;
    }
}


bool FindAllCommand::isValidParams()const
{
    return 3 == m_pParams->getSize()  &&
           ('#' != (*m_pParams)[1][0] || Utils::isNum((*m_pParams)[1].substr(1))) &&
           ('#' != (*m_pParams)[2][0] || Utils::isNum((*m_pParams)[2].substr(1)));
}
