#include <stdexcept>
#include "command_factory.h"
#include "creation_commands/new_command.h"
#include "creation_commands/load_command.h"
#include "management_commands/save_command.h"
#include "creation_commands/dup_command.h"
#include "analysis_commands/count_command.h"
#include "analysis_commands/len_command.h"
#include "analysis_commands/find_command.h"
#include "analysis_commands/find_all_command.h"
#include "control_commands/help_command.h"
#include "control_commands/list_command.h"
#include "control_commands/show_command.h"
#include "control_commands/quit_command.h"


CommandFactory::HashCommands CommandFactory::m_commandsHash;

struct InitCommandsHash
{
    InitCommandsHash()
    {
        CommandFactory::m_commandsHash.insert(std::pair<std::string, ICommand*>("new", new NewCommand));
        CommandFactory::m_commandsHash.insert(std::pair<std::string, ICommand*>("load", new LoadCommand));
        CommandFactory::m_commandsHash.insert(std::pair<std::string, ICommand*>("dup", new DupCommand));
        CommandFactory::m_commandsHash.insert(std::pair<std::string, ICommand*>("save", new SaveCommand));
        CommandFactory::m_commandsHash.insert(std::pair<std::string, ICommand*>("count", new CountCommand));
        CommandFactory::m_commandsHash.insert(std::pair<std::string, ICommand*>("len", new LenCommand));
        CommandFactory::m_commandsHash.insert(std::pair<std::string, ICommand*>("find", new FindCommand));
        CommandFactory::m_commandsHash.insert(std::pair<std::string, ICommand*>("findall", new FindAllCommand));
        CommandFactory::m_commandsHash.insert(std::pair<std::string, ICommand*>("help", new HelpCommand));
        CommandFactory::m_commandsHash.insert(std::pair<std::string, ICommand*>("list", new ListCommand));
        CommandFactory::m_commandsHash.insert(std::pair<std::string, ICommand*>("show", new ShowCommand));
        CommandFactory::m_commandsHash.insert(std::pair<std::string, ICommand*>("quit", new QuitCommand));
    }
}initCommandsHash;


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
    delete m_commandsHash.at("count");
    delete m_commandsHash.at("len");
    delete m_commandsHash.at("find");
    delete m_commandsHash.at("findall");
    delete m_commandsHash.at("help");
    delete m_commandsHash.at("list");
    delete m_commandsHash.at("show");
    delete m_commandsHash.at("quit");
}


std::vector<std::string> CommandFactory::getCommandNames()
{
    HashCommands::const_iterator iter;
    std::vector<std::string> vec;

    for(iter = m_commandsHash.begin(); iter != m_commandsHash.end(); ++iter)
    {
        vec.push_back(iter->first);
    }

    return vec;
}
