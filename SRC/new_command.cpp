#include <stdexcept>
#include <sstream>
#include "new_command.h"
#include "db_dna_sequences.h"
#include "dna_meta_data.h"
#include "parser_params.h"
#include "screen_writer.h"


NewCommand::NewCommand(const ParserParams& params): CreationCommands(params)
{
    if(!isValidParams())
    {
        throw std::invalid_argument("INVALID PARAMETERS");
    }
}


void NewCommand::execute(IWriter* output, DBDNASequence* database)const
{
    DNAMetaData* pDNAMetaData;
    std::string nameDNA;
    static size_t count = 1;

    if(3 == (*m_pParams).getSize())
    {
        nameDNA = ICommand::getValidDNAName((*m_pParams)[2].substr(1), database);
    }

    else
    {
        std::stringstream out;
        out << "seq" << count;
        ++count;
        nameDNA = ICommand::getValidDNAName(out.str(), database);
    }

    pDNAMetaData = new DNAMetaData((*m_pParams)[1],nameDNA);
    database->addNewDNA(pDNAMetaData);

    output->write(pDNAMetaData->getDNADataAsStr().c_str());
}


bool NewCommand::isValidParams()
{
    return 2 == (*m_pParams).getSize() || (3 == (*m_pParams).getSize() && '@' == (*m_pParams)[2][0]);
}
