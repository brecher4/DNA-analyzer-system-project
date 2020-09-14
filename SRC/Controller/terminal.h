#ifndef SRC_TERMINAL_H
#define SRC_TERMINAL_H


class IReader;
class IWriter;
class DBDNASequence;


class Terminal
{
public:
    static void start(IReader* input, IWriter* output, DBDNASequence* database);
};


#endif //SRC_TERMINAL_H
