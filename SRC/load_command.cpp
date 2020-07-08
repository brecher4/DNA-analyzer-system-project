#include "load_command.h"
#include "screen_writer.h"
#include "parser_params.h"
#include "dna_meta_data.h"
#include "db_dna_sequences.h"
#include "file_reader.h"
#include <stdexcept>


LoadCommand::LoadCommand(const ParserParams& params):CreationCommand(params)
{
    if(!isValidParams())
    {
        throw std::invalid_argument("INVALID PARAMETERS");
    }
}


void LoadCommand::execute()const
{
    DNAMetaData* pDNAMetaData;
    FileReader file((*m_pParams)[1]);

    if(3 == (*m_pParams).getSize())
    {
        pDNAMetaData = new DNAMetaData(file.read(),(*m_pParams)[2].substr(1));
        DBDNASequence::addNewDNA(pDNAMetaData);
    }

    else
    {
        pDNAMetaData = new DNAMetaData(file.read(), (*m_pParams)[1].substr(0, (*m_pParams)[1].find('.')));
        DBDNASequence::addNewDNA(pDNAMetaData);
    }

    write(pDNAMetaData);
}


bool LoadCommand::isValidParams()
{
    return 2 == (*m_pParams).getSize() || (3 == (*m_pParams).getSize() && '@' == (*m_pParams)[2][0]);
}


void LoadCommand::write(DNAMetaData* pDNAMetaData)const
{
    ScreenWriter output;
    output.write(pDNAMetaData->getDNADataAsStr().c_str());
}

