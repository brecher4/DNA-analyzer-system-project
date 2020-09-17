#ifndef DNA_SEQUENCE_DNA_SEQUENCE_H
#define DNA_SEQUENCE_DNA_SEQUENCE_H


#include <list>
#include "../View/reader/i_reader.h"
#include "../View/writer/i_writer.h"


class DNASequence
{
private:
    class NucleotideAsChar;
    typedef NucleotideAsChar Nucleotide;

    class NucleotideAsChar
    {
    public:
        NucleotideAsChar() { m_nucleotide = '\0'; }

        char operator=(char nucleotide);
        operator char();
        static bool isValidNucleotide(char nucleotide, const char* validNucleotide="ACGT");

    private:
        char m_nucleotide;
    };

public:
    DNASequence(const char* str);
    DNASequence(const std::string& str);
    DNASequence(const IReader& iReader);
    ~DNASequence();
    DNASequence(const DNASequence& dnaSequence);
    const DNASequence& operator=(const DNASequence& dnaSequence);

    Nucleotide& operator[](size_t index);
    size_t length()const;
    DNASequence slice(size_t startIndex, size_t endIndex)const;
    DNASequence pairing()const;
    size_t find(const DNASequence& dnaSequence)const;
    size_t count(const DNASequence& dnaSequence)const;
    std::list<size_t> findAll(const DNASequence& dnaSequence)const;
    std::list<DNASequence> findConsensusSequences()const;
    void writeDnaSequence(const IWriter& iWriter);

    friend bool operator==(const DNASequence& dnaSequence1, const DNASequence& dnaSequence2);
    friend bool operator!=(const DNASequence& dnaSequence1, const DNASequence& dnaSequence2);
    friend std::ostream& operator<<(std::ostream& out, const DNASequence& dnaSequence);

private:
    explicit DNASequence(size_t lengthDnaSequence);
    const char* getDnaSequenceAsStr()const;
    void copyCharPtrToNucleotide(const char* dnaSequence);
    void initDataDnaSequence(const char* dnaSequence);
    void createConsensusSequences(std::list<DNASequence>& consensusSequencesList, std::list<size_t>& startCodonList, std::list<size_t>& endCodonList)const;

    static bool isValidDnaSequence(const char* dnaSequence, const char* validSequence = "ACTG");

    Nucleotide* m_dnaSequence;
    size_t m_lengthDnaSequence;
};


#endif //DNA_SEQUENCE_DNA_SEQUENCE_H
