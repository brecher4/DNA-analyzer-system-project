#include <stdexcept>
#include <sstream>
#include <vector>
#include "show_command.h"
#include "../../parser_params.h"
#include "../../../Model/db_dna_sequences.h"
#include "../../../Model/dna_meta_data.h"
#include "../../utils.h"


void ShowCommand::initParams(const ParserParams& params)
{
    m_pParams = &params;

    if(!isValidParams())
    {
        throw std::invalid_argument("INVALID PARAMETERS");
    }
}


void ShowCommand::execute(IWriter* output, DBDNASequence* database)const
{
    DNAMetaData* pDNA;

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

    if(3 == (*m_pParams).getSize())
    {
        std::istringstream in((*m_pParams)[2]);
        size_t numChars;
        in >> numChars;
        output->write(getDNADataFormat(*pDNA, numChars).c_str());
    }

    else
    {
        output->write(getDNADataFormat(*pDNA).c_str());
    }
}


bool ShowCommand::isValidParams()const
{
    return (2 == (*m_pParams).getSize() ||
            (3 == (*m_pParams).getSize() && Utils::isNum((*m_pParams)[2]))) &&
            ('@' == (*m_pParams)[1][0] ||
            ('#' == (*m_pParams)[1][0] && Utils::isNum((*m_pParams)[1].substr(1))));
}


std::string ShowCommand::getDNADataFormat(const DNAMetaData& pDNA, size_t numChars)const
{
    std::stringstream out;

    out << "[" << pDNA.getId() << "] " << pDNA.getName() << " ";

    switch(pDNA.getStatus())
    {
        case UP_TO_DATA:
            out << "up to data";
            break;

        case MODIFIED:
            out << "modified";
            break;

        case NEW:
            out << "new";
            break;
    }

    out << "\n";

    size_t numCharsInLine = 99;
    size_t numCharsLeftToPrint = std::min(numChars, pDNA.getDNASequence().length());
    size_t begin = 0;
    size_t end = std::min(numCharsInLine, numCharsLeftToPrint);

    while(numCharsLeftToPrint)
    {
        out << pDNA.getDNASequence().slice(begin, end) << "\n";
        numCharsLeftToPrint -= end - begin;
        begin = end;
        end = std::min(begin + numCharsInLine, begin + numCharsLeftToPrint);
    }

    return out.str();
}
