#include <stdexcept>
#include "new_command.h"
#include "../../../Model/db_dna_sequences.h"
#include "../../../Model/dna_meta_data.h"
#include "../../parser_params.h"
#include "../../utils.h"


void NewCommand::initParams(const ParserParams& params)
{
    m_pParams = &params;

    if(!isValidParams())
    {
        throw std::invalid_argument("INVALID PARAMETERS");
    }
}


void NewCommand::execute(IReader* input, IWriter* output, DBDNASequence* database)const
{
    DNAMetaData* pDNAMetaData;
    std::string nameDNA;
    bool isSentName = (3 == (*m_pParams).getSize());
    static size_t count = 0;

    if(isSentName)
    {
        nameDNA = Utils::getValidDNAName((*m_pParams)[2].substr(1), database);
    }

    else
    {
        nameDNA = Utils::getValidDNAName("seq" + Utils::castNumToStr(++count), database);
    }

    try
    {
        pDNAMetaData = new DNAMetaData((*m_pParams)[1],nameDNA);
    }

    catch(std::invalid_argument& e)
    {
        if(!isSentName)
        {
            --count;
        }

        throw e;
    }

    database->addNewDNA(pDNAMetaData);

    output->write(pDNAMetaData->getDNADataFormat().c_str());
}


bool NewCommand::isValidParams()const
{
    return 2 == (*m_pParams).getSize() || (3 == (*m_pParams).getSize() && '@' == (*m_pParams)[2][0]);
}
