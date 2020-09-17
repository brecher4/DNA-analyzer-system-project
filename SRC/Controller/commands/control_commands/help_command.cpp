#include <stdexcept>
#include <sstream>
#include <fstream>
#include "help_command.h"
#include "../../parser_params.h"
#include "../../../Model/db_dna_sequences.h"
#include "../../../Model/dna_meta_data.h"
#include "../command_factory.h"


void HelpCommand::initParams(const ParserParams& params)
{
    m_pParams = &params;

    if(!isValidParams())
    {
        throw std::invalid_argument("INVALID PARAMETERS");
    }
}


void HelpCommand::execute(IReader* input, IWriter* output, DBDNASequence* database)const
{
    if(1 == m_pParams->getSize())
    {
        output->write(getAvailableCommands().c_str());
    }

    else
    {
        output->write(getInfoCommand((*m_pParams)[1]).c_str());
    }
}


bool HelpCommand::isValidParams()const
{
    return (1 == m_pParams->getSize() || 2 == m_pParams->getSize());
}


std::string HelpCommand::getAvailableCommands()const
{
    std::stringstream out;
    out << "The list of all the available commands:\n";
    std::vector<std::string> nameCommands = CommandFactory::getCommandNames();
    size_t numCommands = nameCommands.size();

    for(size_t i = 0; i < numCommands; ++i)
    {
        out << nameCommands[i] << "\n";
    }

    return out.str();
}


std::string HelpCommand::getInfoCommand(const std::string& str)const
{
    std::stringstream out;

    std::ifstream myFile;
    myFile.open(("../Model/info_commands/info_" + str + "_command.txt").c_str());
    std::string line;

    if(!myFile.is_open())
    {
        throw std::runtime_error("NAME COMMAND IS NOT VALID");
    }

    while(getline(myFile, line))
    {
        out << line << "\n";
    }

    myFile.close();

    return out.str();
}
