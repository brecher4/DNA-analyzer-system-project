#ifndef SRC_CALLBACK_H
#define SRC_CALLBACK_H


#include "parser_params.h"


class IReader;
class IWriter;


template <typename cInstance>
class Callback
{
public:
    typedef void(cInstance::*TFunc)(ParserParams&, IReader*, IWriter*);

    Callback(cInstance* obj, TFunc func);

    void operator()(ParserParams& params, IReader* input, IWriter* output);

private:
    cInstance* m_obj;
    TFunc m_func;
};


template <typename cInstance>
inline Callback<cInstance>::Callback(cInstance* obj, Callback::TFunc func):m_obj(obj),m_func(func){}


template <typename cInstance>
inline void Callback<cInstance>::operator()(ParserParams &params, IReader* input, IWriter* output)
{
    (m_obj->*m_func)(params, input, output);
}


#endif //SRC_CALLBACK_H
