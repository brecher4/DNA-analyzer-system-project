#ifndef DNA_SEQUENCE_KEYBOARD_READER_H
#define DNA_SEQUENCE_KEYBOARD_READER_H


#include <string>
#include "reader.h"


class KeyboardReader:public Reader
{
public:
    void initInputFromKeyboard();
};


#endif //DNA_SEQUENCE_KEYBOARD_READER_H
