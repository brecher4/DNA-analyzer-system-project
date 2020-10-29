#ifndef SRC_COMMAND_H
#define SRC_COMMAND_H


#include "i_command.h"


class Command: public ICommand
{
public:
    /* virtual */ ~Command() = 0;

protected:
    const ParserParams* m_pParams;
};


#endif //SRC_COMMAND_H
