#include <stdexcept>
#include <sstream>
#include "new_command.h"
#include "../../../Model/db_dna_sequences.h"
#include "../../../Model/dna_meta_data.h"
#include "../../parser_params.h"
#include "../../../View/writer/screen_writer.h"
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
    static size_t count = 1;

    if(3 == (*m_pParams).getSize())
    {
        nameDNA = Utils::getValidDNAName((*m_pParams)[2].substr(1), database);
    }

    else
    {
        std::stringstream out;
        out << "seq" << count;
        ++count;
        nameDNA = Utils::getValidDNAName(out.str(), database);
    }

    pDNAMetaData = new DNAMetaData((*m_pParams)[1],nameDNA);
    database->addNewDNA(pDNAMetaData);

    output->write(pDNAMetaData->getDNADataFormat().c_str());
}


bool NewCommand::isValidParams()const
{
    return 2 == (*m_pParams).getSize() || (3 == (*m_pParams).getSize() && '@' == (*m_pParams)[2][0]);
}
