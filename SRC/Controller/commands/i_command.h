#ifndef SRC_I_COMMAND_H
#define SRC_I_COMMAND_H


#include <string>


class IReader;
class IWriter;
class DBDNASequence;
class ParserParams;


class ICommand
{
public:
    virtual ~ICommand(){}

    virtual void initParams(const ParserParams& params) = 0;
    virtual void execute(IReader* input, IWriter* output, DBDNASequence* database)const = 0;
};


#endif //SRC_I_COMMAND_H
