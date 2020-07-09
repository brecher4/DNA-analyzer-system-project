#ifndef SRC_NEW_COMMAND_H
#define SRC_NEW_COMMAND_H


#include "creation_commands.h"


class DNAMetaData;


class NewCommand: public CreationCommands
{
public:
    NewCommand(const ParserParams& params);

    /* virtual */ void execute(IWriter* output, DBDNASequence* database)const;

private:
    bool isValidParams();
};


#endif //SRC_NEW_COMMAND_H
