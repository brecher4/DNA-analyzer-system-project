#ifndef SRC_UTILS_H
#define SRC_UTILS_H


#include <string>


class DNAMetaData;
class DBDNASequence;


class Utils
{
public:
    static std::string getShortDNADataFormat(const DNAMetaData* pDNAMetaData);
    static std::string getValidDNAName(const std::string& name, DBDNASequence* database);
    static DNAMetaData* findDNAMetaData(char c, const std::string& str, DBDNASequence* database);

    static size_t castStrToNum(const std::string& str);
    static std::string castNumToStr(size_t num);
    static bool isNum(const std::string& str);
};


#endif //SRC_UTILS_H
