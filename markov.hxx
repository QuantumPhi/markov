#include <iostream>
#include <map>
#include <vector>
#include <string.h>

using namespace std;

typedef struct
{
    char* a, b;
} key_pair;

class Markov
{
protected:
    map<key_pair, vector<char*> > word_map;

    Markov(char* file_name)
    {
        initialize(file_name);
    }

    ~Markov() {}

    static char* next(ifstream input);
    void initialize(char* file_name);

public:
    char* generate(int length);
};
