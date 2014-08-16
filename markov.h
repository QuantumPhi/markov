#include <string.h>

#include "pair.h"

class Markov
{
protected:
    Markov(char* file_name)
    {
        fp = fopen(file_name, "r");
        word_map = (map<Pair, vector<char*>>*)(malloc(sizeof map<Pair, vector<char*>>));
    }

    ~Markov()
    {
        fclose(fp);
        delete word_map;
    }
    FILE* fp;
    map<Pair, vector<char*>>* word_map;

public:
    char* concat(char* a, char* b);
    char* generate(int length);
}
