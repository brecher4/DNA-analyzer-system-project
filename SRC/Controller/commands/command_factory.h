#ifndef SRC_COMMAND_FACTORY_H
#define SRC_COMMAND_FACTORY_H


#include "i_command.h"
#include "parser_params.h"


class CommandFactory
{
public:
    static const ICommand* getCommand(const ParserParams& params);
};


#endif //SRC_COMMAND_FACTORY_H
