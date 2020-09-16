#ifndef SRC_LIST_COMMAND_H
#define SRC_LIST_COMMAND_H


#include "control_commands.h"


class DNAMetaData;


class ListCommand: public ControlCommands
{
public:
    /* virtual */ void initParams(const ParserParams& params);
    /* virtual */ void execute(IWriter* output, DBDNASequence* database)const;

private:
    bool isValidParams();
};


#endif //SRC_LIST_COMMAND_H
