#ifndef SRC_MANAGEMENT_COMMANDS_H
#define SRC_MANAGEMENT_COMMANDS_H


#include "i_command.h"


class ManagementCommands: public ICommand
{
public:
    ManagementCommands(const ParserParams& params): ICommand(params){}
};


#endif //SRC_MANAGEMENT_COMMANDS_H
