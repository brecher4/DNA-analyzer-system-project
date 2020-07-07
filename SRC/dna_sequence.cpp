#include "dna_sequence.h"
#include <cstring>
#include <iostream>
#include <algorithm>


char DNASequence::NucleotideAsChar::operator=(char nucleotide)
{
    if (!isValidNucleotide(nucleotide))
    {
        throw std::invalid_argument("DNA ISN'T VALID :(");
    }

    m_nucleotide = nucleotide;

    return m_nucleotide;
}


DNASequence::NucleotideAsChar::operator char()
{
    return m_nucleotide;
}


bool DNASequence::NucleotideAsChar::isValidNucleotide(char nucleotide, const char* validNucleotide)
{
    int length = strlen(validNucleotide);

    for (int i = 0; i < length; i++)
    {
        if (validNucleotide[i] == nucleotide)
        {
            return true;
        }
    }

    return false;
}


bool DNASequence::isValidDnaSequence(const char* dnaSequence, const char* validSequence)
{
    return strlen(dnaSequence) == strspn(dnaSequence, validSequence);
}


void DNASequence::copyCharPtrToNucleotide(const char* dnaSequence)
{
    char* ptrDnaSequence = (char*)dnaSequence;
    size_t i = 0;

    while (*ptrDnaSequence)
    {
        m_dnaSequence[i] = *ptrDnaSequence;
        i++;
        ptrDnaSequence++;
    }
}


void DNASequence::initDataDnaSequence(const char* dnaSequence)
{
    if (!dnaSequence || !isValidDnaSequence(dnaSequence))
    {
        throw std::invalid_argument("DNA ISN'T VALID :(");
    }

    m_dnaSequence = new Nucleotide[strlen(dnaSequence) + 1];
    copyCharPtrToNucleotide(dnaSequence);
    m_lengthDnaSequence = strlen(dnaSequence);
}


DNASequence::DNASequence(const char* str)
{
    initDataDnaSequence(str);
}


DNASequence::DNASequence(const std::string& str)
{
    initDataDnaSequence(str.c_str());
}


DNASequence::DNASequence(const IReader& iReader)
{
    initDataDnaSequence(iReader.read().c_str());
}


DNASequence::~DNASequence()
{
    delete[] m_dnaSequence;
}


DNASequence::DNASequence(const DNASequence& dnaSequence)
{
    initDataDnaSequence(dnaSequence.getDnaSequenceAsStr());
}


const DNASequence& DNASequence::operator=(const DNASequence& dnaSequence)
{
    if (m_dnaSequence == dnaSequence.m_dnaSequence)
    {
        return *this;
    }

    delete[] m_dnaSequence;
    initDataDnaSequence(dnaSequence.getDnaSequenceAsStr());

    return *this;
}


DNASequence::Nucleotide& DNASequence::operator[](size_t index)
{
    if (index < m_lengthDnaSequence)
    {
        return m_dnaSequence[index];
    }

    throw std::out_of_range("INDEX ISN'T VALID :(");
}


size_t DNASequence::length()const
{
    return m_lengthDnaSequence;
}


DNASequence DNASequence::slice(size_t startIndex, size_t endIndex)const
{
    endIndex = std::min(endIndex, m_lengthDnaSequence);

    if(startIndex > endIndex)
    {
        throw std::invalid_argument("START INDEX BIGGER THEN END INDEX :(");
    }

    DNASequence subDna(endIndex - startIndex);

    for (size_t i = startIndex, j = 0; i < endIndex; i++, j++)
    {
        subDna.m_dnaSequence[j] = m_dnaSequence[i];
    }

    return subDna;
}


DNASequence DNASequence::pairing()const
{
    DNASequence pairDnaSequence(m_lengthDnaSequence);

    for (size_t i = m_lengthDnaSequence - 1, j = 0; j < m_lengthDnaSequence; i--, j++)
    {
        if (m_dnaSequence[i] == 'A')
        {
            pairDnaSequence[j] = 'T';
        }

        if (m_dnaSequence[i] == 'T')
        {
            pairDnaSequence[j] = 'A';
        }

        if (m_dnaSequence[i] == 'C')
        {
            pairDnaSequence[j] = 'G';
        }

        if (m_dnaSequence[i] == 'G')
        {
            pairDnaSequence[j] = 'C';
        }
    }

    return pairDnaSequence;
}


size_t DNASequence::find(const DNASequence& dnaSequence)const
{
    std::string sequence = ((std::string)getDnaSequenceAsStr());
    size_t index = sequence.find((std::string)dnaSequence.getDnaSequenceAsStr());

    if (index == std::string::npos)
    {
        return m_lengthDnaSequence;
    }

    return index;
}


size_t DNASequence::count(const DNASequence& dnaSequence)const
{
    size_t numOfOccurrences = 0;
    DNASequence temp = *this;
    size_t index = temp.find(dnaSequence);

    if (index == 0)
    {
        numOfOccurrences++;
    }

    for (size_t i = 1; i < m_lengthDnaSequence && index != temp.m_lengthDnaSequence; i++)
    {
        temp = temp.slice(1, temp.m_lengthDnaSequence);
        index = temp.find(dnaSequence);

        if(index == 0)
        {
            numOfOccurrences++;
        }
    }

    return numOfOccurrences;
}


std::list<size_t> DNASequence::findAll(const DNASequence& dnaSequence)const
{
    std::list<size_t> indexesList;
    DNASequence temp = *this;
    size_t index = temp.find(dnaSequence);

    if (index == 0)
    {
        indexesList.push_back(0);
    }

    for (size_t i = 1; i < m_lengthDnaSequence && index != temp.m_lengthDnaSequence; i++)
    {
        temp = temp.slice(1, temp.m_lengthDnaSequence);
        index = temp.find(dnaSequence);

        if (index == 0)
        {
            indexesList.push_back(i);
        }
    }

    return indexesList;
}


void DNASequence::createConsensusSequences(std::list<DNASequence>& consensusSequencesList, std::list<size_t>& startCodonList, std::list<size_t>& endCodonList)const
{
    std::list<size_t>::iterator iterStartCodon;
    std::list<size_t>::iterator iterEndCodon;

    for (iterStartCodon = startCodonList.begin(); iterStartCodon != startCodonList.end(); iterStartCodon++)
    {
        for (iterEndCodon = endCodonList.begin(); iterEndCodon != endCodonList.end(); iterEndCodon++)
        {
            if (*iterStartCodon < *iterEndCodon && (*iterEndCodon - *iterStartCodon) % 3 == 0)
            {
                consensusSequencesList.push_back(slice(*iterStartCodon, *iterEndCodon + 3));
            }
        }
    }
}


std::list<DNASequence> DNASequence::findConsensusSequences()const
{
    std::list<DNASequence> consensusSequencesList;
    std::list<size_t> startCodonIndexesATG = findAll("ATG");
    std::list<size_t> endCodonIndexesTAG = findAll("TAG");
    std::list<size_t> endCodonIndexesTAA = findAll("TAA");
    std::list<size_t> endCodonIndexesTGA = findAll("TGA");

    createConsensusSequences(consensusSequencesList, startCodonIndexesATG, endCodonIndexesTAG);
    createConsensusSequences(consensusSequencesList, startCodonIndexesATG, endCodonIndexesTAA);
    createConsensusSequences(consensusSequencesList, startCodonIndexesATG, endCodonIndexesTGA);

    return consensusSequencesList;
}


void DNASequence::writeDnaSequence(const IWriter& iWriter)
{
    iWriter.write(getDnaSequenceAsStr());
}


const char* DNASequence::getDnaSequenceAsStr()const
{
    return (const char*)m_dnaSequence;
}


bool operator==(const DNASequence& dnaSequence1, const DNASequence& dnaSequence2)
{
    return strcmp(dnaSequence1.getDnaSequenceAsStr(), dnaSequence2.getDnaSequenceAsStr()) == 0;
}


bool operator!=(const DNASequence& dnaSequence1, const DNASequence& dnaSequence2)
{
    return strcmp(dnaSequence1.getDnaSequenceAsStr(), dnaSequence2.getDnaSequenceAsStr()) != 0;
}


std::ostream& operator<<(std::ostream& out, const DNASequence& dnaSequence)
{
    out << "DnaSequence: " << dnaSequence.getDnaSequenceAsStr();

    return out;
}


DNASequence::DNASequence(size_t lengthDnaSequence)
{
    m_dnaSequence = new Nucleotide[lengthDnaSequence + 1];
    m_lengthDnaSequence = lengthDnaSequence;
}