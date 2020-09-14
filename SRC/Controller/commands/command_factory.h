#ifndef SRC_COMMAND_FACTORY_H
#define SRC_COMMAND_FACTORY_H


#include "i_command.h"
#include "../parser_params.h"
#include <map>


class CommandFactory
{
public:
    static void init();
    static const ICommand* getCommand(const ParserParams& params);
    static void release();

private:
    static std::map<std::string, ICommand*> m_commandsHash;
};


#endif //SRC_COMMAND_FACTORY_H
