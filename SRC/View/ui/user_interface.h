#ifndef SRC_USER_INTERFACE_H
#define SRC_USER_INTERFACE_H


#include "../../Controller/system_manager.h"
#include "../../Controller/callback.h"


class IReader;
class IWriter;
class DBDNASequence;


class UI
{
public:
    virtual ~UI(){}

    virtual void run(IReader* input, IWriter* output, DBDNASequence* database, Callback<SystemManager>& callback) = 0;
};


#endif //SRC_USER_INTERFACE_H
