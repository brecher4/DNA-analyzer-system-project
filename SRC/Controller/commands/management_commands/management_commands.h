#ifndef SRC_MANAGEMENT_COMMANDS_H
#define SRC_MANAGEMENT_COMMANDS_H


#include "../i_command.h"


class ManagementCommands: public ICommand
{
public:
    /* virtual */ void initParams(const ParserParams& params) = 0;
};


#endif //SRC_MANAGEMENT_COMMANDS_H
