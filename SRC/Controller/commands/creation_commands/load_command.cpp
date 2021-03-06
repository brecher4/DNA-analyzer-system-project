#include <stdexcept>
#include "load_command.h"
#include "../../parser_params.h"
#include "../../../Model/dna_meta_data.h"
#include "../../../Model/db_dna_sequences.h"
#include "../../../View/reader/file_reader.h"
#include "../../utils.h"


void LoadCommand::initParams(const ParserParams& params)
{
    m_pParams = &params;

    if(!isValidParams())
    {
        throw std::invalid_argument("INVALID PARAMETERS");
    }
}


void LoadCommand::execute(IReader* input, IWriter* output, DBDNASequence* database)const
{
    DNAMetaData* pDNAMetaData;
    std::string nameDNA;

    if(3 == (*m_pParams).getSize())
    {
        nameDNA = Utils::getValidDNAName((*m_pParams)[2].substr(1), database);
    }

    else
    {
        nameDNA = Utils::getValidDNAName((*m_pParams)[1].substr(0, (*m_pParams)[1].find_last_of('.')), database);
    }

    FileReader file("../Model/DNA_sequences_files/load_DNA/" + (*m_pParams)[1]);
    file.initInput();

    pDNAMetaData = new DNAMetaData(file.read(), nameDNA);
    pDNAMetaData->setStatus(UP_TO_DATA);
    database->addNewDNA(pDNAMetaData);

    output->write(Utils::getShortDNADataFormat(pDNAMetaData).c_str());
}


bool LoadCommand::isValidParams()const
{
    return 2 == (*m_pParams).getSize() || (3 == (*m_pParams).getSize() && '@' == (*m_pParams)[2][0]);
}
