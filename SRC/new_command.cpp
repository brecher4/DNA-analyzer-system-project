#include <stdexcept>
#include "new_command.h"
#include "db_dna_sequences.h"
#include "dna_meta_data.h"
#include "parser_params.h"
#include "screen_writer.h"


NewCommand::NewCommand(const ParserParams& params):CreationCommand(params)
{
    if(!isValidParams())
    {
        throw std::invalid_argument("INVALID PARAMETERS");
    }
}


void NewCommand::execute()const
{
    DNAMetaData* pDNAMetaData;

    if(3 == (*m_pParams).getSize())
    {
        pDNAMetaData = new DNAMetaData((*m_pParams)[1],(*m_pParams)[2].substr(1));
        DBDNASequence::addNewDNA(pDNAMetaData);
    }

    else
    {
        pDNAMetaData = new DNAMetaData((*m_pParams)[1]);
        DBDNASequence::addNewDNA(pDNAMetaData);
    }

    write(pDNAMetaData);
}


bool NewCommand::isValidParams()
{
    return 2 == (*m_pParams).getSize() || (3 == (*m_pParams).getSize() && '@' == (*m_pParams)[2][0]);
}


void NewCommand::write(DNAMetaData* pDNAMetaData)const
{
    ScreenWriter output;
    output.write(pDNAMetaData->getDNADataAsStr().c_str());
}
