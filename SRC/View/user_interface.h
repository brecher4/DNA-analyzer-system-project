#ifndef SRC_USER_INTERFACE_H
#define SRC_USER_INTERFACE_H


class IReader;
class IWriter;
class DBDNASequence;


class UI
{
public:
    virtual void run(IReader* input, IWriter* output, DBDNASequence* database) = 0;
};

#endif //SRC_USER_INTERFACE_H
