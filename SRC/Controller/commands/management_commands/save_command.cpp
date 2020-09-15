#include <stdexcept>
#include <sstream>
#include <iostream>
#include "save_command.h"
#include "../../parser_params.h"
#include "../../../Model/db_dna_sequences.h"
#include "../../../View/file_writer.h"
#include "../../../Model/dna_meta_data.h"


void SaveCommand::initParams(const ParserParams& params)
{
    m_pParams = &params;

    if(!isValidParams())
    {
        throw std::invalid_argument("INVALID PARAMETERS");
    }
}


void SaveCommand::execute(IWriter* output, DBDNASequence* database)const
{
    DNAMetaData* pDNA;
    std::string nameFile;

    if('@' == (*m_pParams)[1][0])
    {
        pDNA = database->findDNAByName((*m_pParams)[1].substr(1));
    }

    else
    {
        std::istringstream in((*m_pParams)[1].substr(1));
        size_t idDNA;
        in >> idDNA;
        pDNA = database->findDNAById(idDNA);
    }

    if(m_pParams->getSize() == 2)
    {
        nameFile = pDNA->getName() + ".rawdna";
    }

    else
    {
        nameFile = (*m_pParams)[2];
    }

    FileWriter file("../Model/DNA_sequences_files/save_DNA/" + nameFile);
    file.write(pDNA->getDNADataAsStr().c_str());

    pDNA->setStatus(UP_TO_DATA);

    std::cout << "\n";
}


bool SaveCommand::isValidParams()
{
    return (2 == (*m_pParams).getSize() || 3 == (*m_pParams).getSize()) &&
                ('@' == (*m_pParams)[1][0] || '#' == (*m_pParams)[1][0]);
}
