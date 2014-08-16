#include <fstream>
#include <string.h>

typedef struct
{
    char* a, b;
} key_pair;

class Markov
{
protected:
    map<key_pair, vector<char*>> word_map;

    Markov(char* file_name)
    {
        word_map = new map<key_pair, vector<char*>>;
        initialize(file_name);
    }

    ~Markov()
    {
        fclose(fp);
    }

    static char* concat(char* a, char* b);
    static char* next(ifstream in);
    void initialize(char* file_name);

public:
    char* generate(int length);
}
