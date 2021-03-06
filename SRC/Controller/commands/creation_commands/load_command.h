#ifndef SRC_LOAD_COMMAND_H
#define SRC_LOAD_COMMAND_H


#include <string>
#include "creation_commands.h"


class DNAMetaData;


class LoadCommand: public CreationCommands
{
public:
    /* virtual */ void initParams(const ParserParams& params);
    /* virtual */ void execute(IReader* input, IWriter* output, DBDNASequence* database)const;

private:
    bool isValidParams()const;
};


#endif //SRC_LOAD_COMMAND_H
