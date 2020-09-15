#include <stdexcept>
#include "command_factory.h"
#include "creation_commands/new_command.h"
#include "creation_commands/load_command.h"
#include "management_commands/save_command.h"
#include "creation_commands/dup_command.h"
#include "analyzer_commands/len_command.h"
#include "analyzer_commands/find_command.h"


std::map<std::string, ICommand*> CommandFactory::m_commandsHash;


void CommandFactory::init()
{
    m_commandsHash.insert(std::pair<std::string, ICommand*>("new", new NewCommand));
    m_commandsHash.insert(std::pair<std::string, ICommand*>("load", new LoadCommand));
    m_commandsHash.insert(std::pair<std::string, ICommand*>("dup", new DupCommand));
    m_commandsHash.insert(std::pair<std::string, ICommand*>("save", new SaveCommand));
    m_commandsHash.insert(std::pair<std::string, ICommand*>("len", new LenCommand));
    m_commandsHash.insert(std::pair<std::string, ICommand*>("find", new FindCommand));
}


const ICommand* CommandFactory::getCommand(const ParserParams& params)
{
    if(!params.getSize() && params[0].empty())
    {
        throw std::invalid_argument("MISSING COMMAND");
    }

    try
    {
        ICommand* command = m_commandsHash.at(params[0]);
        command->initParams(params);

        return command;
    }

    catch (std::out_of_range& e)
    {
        throw std::invalid_argument("COMMAND NOT FOUND");
    }
}


void CommandFactory::release()
{
    delete m_commandsHash.at("new");
    delete m_commandsHash.at("load");
    delete m_commandsHash.at("dup");
    delete m_commandsHash.at("save");
    delete m_commandsHash.at("len");
    delete m_commandsHash.at("find");
}
