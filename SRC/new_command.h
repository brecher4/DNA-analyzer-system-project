#ifndef SRC_NEW_COMMAND_H
#define SRC_NEW_COMMAND_H


#include "creation_command.h"


class NewCommand: public CreationCommand
{
public:
    NewCommand(const ParserParams& params);

    void execute()const;

private:
    bool isValidParams();
};


#endif //SRC_NEW_COMMAND_H