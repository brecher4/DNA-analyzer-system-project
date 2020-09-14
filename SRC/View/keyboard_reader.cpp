#include <iostream>
#include "keyboard_reader.h"


void KeyboardReader::initInput()
{
    getline(std::cin, m_data);
}

