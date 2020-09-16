#include <stdexcept>
#include <sstream>
#include <string>
#include "find_command.h"
#include "../../parser_params.h"
#include "../../../Model/db_dna_sequences.h"
#include "../../../Model/dna_meta_data.h"
#include "../../utils.h"


void FindCommand::initParams(const ParserParams& params)
{
    m_pParams = &params;

    if(!isValidParams())
    {
        throw std::invalid_argument("INVALID PARAMETERS");
    }
}


void FindCommand::execute(IReader* input, IWriter* output, DBDNASequence* database)const
{
    const DNASequence* pDNA1 = NULL;
    const DNASequence* pDNA2 = NULL;
    bool isAllocateDNASeq = false;
    std::string nameDNA;
    size_t index;

    if('@' == (*m_pParams)[1][0])
    {
        pDNA1 = &(database->findDNAByName((*m_pParams)[1].substr(1))->getDNASequence());
    }

    else if('#' == (*m_pParams)[1][0])
    {
        std::istringstream in((*m_pParams)[1].substr(1));
        size_t idDNA;
        in >> idDNA;
        pDNA1 = &(database->findDNAById(idDNA)->getDNASequence());
    }

    if('@' == (*m_pParams)[2][0])
    {
        pDNA2 = &(database->findDNAByName((*m_pParams)[2].substr(1))->getDNASequence());
    }

    else if('#' == (*m_pParams)[2][0])
    {
        std::istringstream in((*m_pParams)[2].substr(1));
        size_t idDNA;
        in >> idDNA;
        pDNA2 = &(database->findDNAById(idDNA)->getDNASequence());
    }

    if(!pDNA1)
    {
        pDNA1 = new DNASequence((*m_pParams)[1]);
        isAllocateDNASeq = true;
    }

    if(pDNA2)
    {
        index = pDNA1->find(*pDNA2);
    }

    else
    {
        index = pDNA1->find((*m_pParams)[2]);
    }

    std::stringstream out;
    out << index;
    output->write(out.str().c_str());

    if(isAllocateDNASeq)
    {
        delete pDNA1;
    }
}


bool FindCommand::isValidParams()const
{
    return 3 == (*m_pParams).getSize()  &&
        ('#' != (*m_pParams)[1][0] || Utils::isNum((*m_pParams)[1].substr(1))) &&
        ('#' != (*m_pParams)[2][0] || Utils::isNum((*m_pParams)[2].substr(1)));
}
