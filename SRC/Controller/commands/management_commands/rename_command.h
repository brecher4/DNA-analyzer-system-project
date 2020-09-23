#ifndef SRC_RENAME_COMMAND_H
#define SRC_RENAME_COMMAND_H


#include "management_commands.h"


class DNAMetaData;


class RenameCommand: public ManagementCommands
{
public:
    /* virtual */ void initParams(const ParserParams& params);
    /* virtual */ void execute(IReader* input, IWriter* output, DBDNASequence* database)const;

private:
    bool isValidParams()const;
};


#endif //SRC_RENAME_COMMAND_H
