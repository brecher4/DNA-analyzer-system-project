#ifndef SRC_PARSER_PARAMS_H
#define SRC_PARSER_PARAMS_H


#include <vector>
#include <string>


class IReader;


class ParserParams
{
public:
    void parseInput(const IReader& input, char delimiter = ' ');
    const std::string& operator[](size_t index)const;

private:
    std::vector<std::string> m_params;
};


#endif //SRC_PARSER_PARAMS_H
