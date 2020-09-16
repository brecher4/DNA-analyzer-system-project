#ifndef SRC_UTILS_H
#define SRC_UTILS_H


#include <string>


class DNAMetaData;


class Utils
{
public:
    static std::string getShortDNADataFormat(const DNAMetaData* pDNAMetaData);
    static bool isNum(const std::string& str);
};


#endif //SRC_UTILS_H
