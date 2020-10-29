#ifndef SRC_COMMAND_FACTORY_H
#define SRC_COMMAND_FACTORY_H


#include <map>
#include "i_command.h"
#include "../parser_params.h"


class CommandFactory
{
public:
    static void release();
    static const ICommand* getCommand(const ParserParams& params);
    static std::vector<std::string> getCommandNames();

    friend struct InitCommandsHash;

private:
    typedef std::map<std::string, ICommand*> HashCommands;
    typedef std::pair<std::string, ICommand*> PairCommand;

    static HashCommands m_commandsHash;
};


#endif //SRC_COMMAND_FACTORY_H
