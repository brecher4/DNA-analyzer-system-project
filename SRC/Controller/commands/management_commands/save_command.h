#ifndef SRC_SAVE_COMMAND_H
#define SRC_SAVE_COMMAND_H


#include "management_commands.h"


class DNAMetaData;


class SaveCommand: public ManagementCommands
{
public:
    /* virtual */ void initParams(const ParserParams& params);
    /* virtual */ void execute(IWriter* output, DBDNASequence* database)const;

private:
    bool isValidParams();
};


#endif //SRC_SAVE_COMMAND_H
