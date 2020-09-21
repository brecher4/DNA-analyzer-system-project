#include <stdexcept>
#include <sstream>
#include <iostream>
#include "save_command.h"
#include "../../parser_params.h"
#include "../../../Model/db_dna_sequences.h"
#include "../../../View/writer/file_writer.h"
#include "../../../Model/dna_meta_data.h"
#include "../../utils.h"


void SaveCommand::initParams(const ParserParams& params)
{
    m_pParams = &params;

    if(!isValidParams())
    {
        throw std::invalid_argument("INVALID PARAMETERS");
    }
}


void SaveCommand::execute(IReader* input, IWriter* output, DBDNASequence* database)const
{
    std::string nameFile;
    DNAMetaData* pDNA = Utils::findDNAMetaData((*m_pParams)[1][0], (*m_pParams)[1].substr(1), database);

    if(m_pParams->getSize() == 2)
    {
        nameFile = pDNA->getName();
    }

    else
    {
        nameFile = (*m_pParams)[2];
    }

    FileWriter file("../Model/DNA_sequences_files/save_DNA/" + nameFile + ".rawdna");
    file.write(pDNA->getDNADataFormat().c_str());

    database->setStatusDNA(pDNA, UP_TO_DATA);

    output->write("DNA saved successfully \n");
}


bool SaveCommand::isValidParams()const
{
    return (2 == (*m_pParams).getSize() || 3 == (*m_pParams).getSize()) &&
            ('@' == (*m_pParams)[1][0] ||
            ('#' == (*m_pParams)[1][0] && Utils::isNum((*m_pParams)[1].substr(1))));
}
