#ifndef INDEX_H_INCLUDED
#define INDEX_H_INCLUDED

#include <fstream>
#include <iostream>

using namespace std;

class IndexEntry
{
private:
     long key;
     long recNr;
public:
    // constructor
    IndexEntry(long k=0L, long n=0L)
    {
        key = k;
        recNr = n;
    }
    // destructor
    // getter

    // setter
    // repr
    // more
    int recordSize() const
    {
        return sizeof(key) + sizeof(recNr);
    }
    // file io
    fstream& write(fstream& ind) const;
    fstream& read(fstream& ind);
    fstream& write_at(fstream& ind, long pos) const
    {
        ind.seekp(pos);
        ind.write((char*)&key, sizeof(key));
        ind.write((char*)&recNr, sizeof(recNr));
        return ind;
    }
    fstream& read_at(fstream& ind, long pos)
    {
        ind.seekg(pos);
        ind.read((char*)&key, sizeof(key));
        ind.read((char*)&recNr, sizeof(recNr));
        return ind;
    }
};

#endif // INDEX_H_INCLUDED
