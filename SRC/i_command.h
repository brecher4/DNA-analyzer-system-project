#ifndef SRC_I_COMMAND_H
#define SRC_I_COMMAND_H


class IWriter;
class DBDNASequence;
class ParserParams;


class ICommand
{
public:
    ICommand(const ParserParams& params):m_pParams(&params){}
    virtual ~ICommand(){}

    virtual void execute(IWriter* output, DBDNASequence* database)const = 0;

protected:
    const ParserParams* m_pParams;
};


#endif //SRC_I_COMMAND_H
