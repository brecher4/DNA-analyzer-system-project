#ifndef SRC_SYSTEM_MANAGER_H
#define SRC_SYSTEM_MANAGER_H


#include "db_dna_sequences.h"


class IReader;
class IWriter;


class SystemManager
{
public:
    void start(IReader* input, IWriter* output);

private:
   DBDNASequence m_dbDNASequence;
};


#endif //SRC_SYSTEM_MANAGER_H
