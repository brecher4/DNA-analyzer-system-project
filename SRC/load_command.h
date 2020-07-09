#ifndef SRC_LOAD_COMMAND_H
#define SRC_LOAD_COMMAND_H


#include <string>
#include "creation_commands.h"


class DNAMetaData;


class LoadCommand: public CreationCommands
{
public:
    LoadCommand(const ParserParams& params);

    /* virtual */ void execute(IWriter* output, DBDNASequence* database)const;

private:
    bool isValidParams();

    static std::string getDNADataAsStr(const DNAMetaData* pDNAMetaData);
};


#endif //SRC_LOAD_COMMAND_H
