#include <stdexcept>
#include "rename_command.h"
#include "../../parser_params.h"
#include "../../../Model/db_dna_sequences.h"
#include "../../../View/writer/file_writer.h"
#include "../../../Model/dna_meta_data.h"
#include "../../utils.h"


void RenameCommand::initParams(const ParserParams& params)
{
    m_pParams = &params;

    if(!isValidParams())
    {
        throw std::invalid_argument("INVALID PARAMETERS");
    }
}


void RenameCommand::execute(IReader* input, IWriter* output, DBDNASequence* database)const
{
    DNAMetaData* pDNA = Utils::findDNAMetaData((*m_pParams)[1][0], (*m_pParams)[1].substr(1), database);

    if(database->isNameExists((*m_pParams)[2].substr(1)))
    {
        throw std::invalid_argument("THE NEW NAME EXISTS IN DATABASE");
    }

    pDNA->setName((*m_pParams)[2].substr(1));
    pDNA->setStatus(MODIFIED);
    output->write("DNA name renamed successfully \n");
}


bool RenameCommand::isValidParams()const
{
    return 3 == (*m_pParams).getSize() &&
           ('@' == (*m_pParams)[1][0] ||
            ('#' == (*m_pParams)[1][0] && Utils::isNum((*m_pParams)[1].substr(1)))) &&
            '@' == (*m_pParams)[2][0];
}
