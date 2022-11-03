#ifndef MYHASH_
#define MYHASH_
#include <string>

template <class T>
class myHash
{
private:
    // hashsize is number you are going to decided on.
    const static int HASHSIZE = 133170;
    T *hash;
    int size;

public:
    myHash()
    {
        hash = new T[HASHSIZE];
        // initialize
        size = 0;
        for (int i = 0; i < HASHSIZE; i++)
        {
            hash[i] = "";
        }
    }; // constructor
    void insert(T item)
    {
        int key = findhash(item);
        if (hash[key].empty())
        {
            hash[key] = item;
        }
        else
        {
            key += doubleHash(item);
            if (hash[key].empty())
            {
                hash[key] = item;
            }
            else
            {
                /*bool entered = false;
                while (!entered)
                {
                    key++;
                    if (hash[key].empty())
                    {
                        hash[key] = item;
                        entered = true;
                    }
                }*/
                std::cout << "it broke"
                          << "\n";
            }
        }
    }
    bool find(T item, double long &tempLong)
    {
        int key = findhash(item);
        if (hash[key].compare(item) == 0) // found it
        {
            tempLong++;
            return true;
        }
        else if (hash[key].empty())
        {
            return false;
        }

        key += doubleHash(item);
        if (hash[key].compare(item) == 0) // found it
        {
            tempLong++;
            return true;
        }
        /*bool found = false;
        while (!found)
        {
            key++;
            if (hash[key].compare(item) == 0)
            {
                return true;
            }
            else if (hash[key].empty() || key > HASHSIZE)
            {
                return false;
            }
        }*/
        return false;
    }

    int getsize()
    {
        return size;
    }
    int findhash(std::string word)
    {
        int i;
        long int val = 0;
        for (i = 0; i <= word.size(); i++)
        {
            val += (i) * (int)word[i] + (i + 1) ^ (int)word[i] + i ^ ((int)word[i] + HASHSIZE) + (HASHSIZE - i);
        }
        return val % HASHSIZE;
    }

    int doubleHash(std::string word)
    {
        int i;
        long int val = 0;
        for (i = 0; i <= word.size(); i++)
        {
            val += (i) + (HASHSIZE * (i + 1)) ^ (5) * ((int)word[i] + i * (i + 1) ^ 3);
        }
        return val % HASHSIZE;
    }
    ~myHash()
    {
        delete[] hash;
    }
};
#endif