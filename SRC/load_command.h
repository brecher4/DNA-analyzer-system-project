#ifndef SRC_LOAD_COMMAND_H
#define SRC_LOAD_COMMAND_H


#include "creation_command.h"


class DNAMetaData;


class LoadCommand: public CreationCommand
{
public:
    LoadCommand(const ParserParams& params);

    void execute()const;
    void write(DNAMetaData* pDNAMetaData)const;

private:
    bool isValidParams();
};


#endif //SRC_LOAD_COMMAND_H
