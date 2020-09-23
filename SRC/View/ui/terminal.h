#ifndef SRC_TERMINAL_H
#define SRC_TERMINAL_H


#include "user_interface.h"


class Terminal:public UI
{
public:
    /* virtual */ void run(IReader* input, IWriter* output, DBDNASequence* database, Callback<SystemManager>& callback);
};


#endif //SRC_TERMINAL_H
