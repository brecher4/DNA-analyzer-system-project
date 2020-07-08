#ifndef SRC_LOAD_COMMAND_H
#define SRC_LOAD_COMMAND_H


#include "creation_command.h"


class DNAMetaData;


class LoadCommand: public CreationCommand
{
public:
    LoadCommand(const ParserParams& params);

    /* virtual */ void execute(IWriter* output, DBDNASequence* database)const;

private:
    bool isValidParams();
};


#endif //SRC_LOAD_COMMAND_H
