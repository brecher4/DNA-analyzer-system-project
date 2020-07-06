#include <iostream>
#include "keyboard_reader.h"


void KeyboardReader::initInputFromKeyboard()
{
    getline(std::cin, m_data);
}

