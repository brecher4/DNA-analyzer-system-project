#include "load_command.h"
#include "../../../View/screen_writer.h"
#include "../../parser_params.h"
#include "../../../Model/dna_meta_data.h"
#include "../../../Model/db_dna_sequences.h"
#include "../../../View/file_reader.h"
#include <stdexcept>
#include <sstream>


LoadCommand::LoadCommand(const ParserParams& params): CreationCommands(params)
{
    if(!isValidParams())
    {
        throw std::invalid_argument("INVALID PARAMETERS");
    }
}


void LoadCommand::execute(IWriter* output, DBDNASequence* database)const
{
    DNAMetaData* pDNAMetaData;
    std::string nameDNA;

    if(3 == (*m_pParams).getSize())
    {
        nameDNA = ICommand::getValidDNAName((*m_pParams)[2].substr(1), database);
    }

    else
    {
        nameDNA = ICommand::getValidDNAName((*m_pParams)[1].substr(0, (*m_pParams)[1].find('.')), database);
    }

    FileReader file((*m_pParams)[1]);
    file.initInput();

    pDNAMetaData = new DNAMetaData(file.read(),nameDNA);
    database->addNewDNA(pDNAMetaData);

    output->write(getDNADataAsStr(pDNAMetaData).c_str());
}


bool LoadCommand::isValidParams()
{
    return 2 == (*m_pParams).getSize() || (3 == (*m_pParams).getSize() && '@' == (*m_pParams)[2][0]);
}


std::string LoadCommand::getDNADataAsStr(const DNAMetaData *pDNAMetaData)
{
    std::stringstream data;
    size_t lengthDNA = pDNAMetaData->getDNASequence().length();

    data << "[" << pDNAMetaData->getId() << "] " << pDNAMetaData->getName() << ": ";

    if(lengthDNA > 40)
    {
        data << pDNAMetaData->getDNASequence().slice(0,33) << "..." << pDNAMetaData->getDNASequence().slice(lengthDNA - 3, lengthDNA);
    }

    else
    {
        data << pDNAMetaData->getDNASequence();
    }

    data << "\n";

    return data.str();
}


