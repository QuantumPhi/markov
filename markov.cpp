#include "markov.h"

using namespace std;

public char* Markov::concat(char* a, char* b)
{
    char* strbuf = (char*)(malloc(sizeof(char) * (strlen(a) + strlen(b)));
    strcat(strbuf, a);
    strcat(strbuf, b);
    return strbuf;
}

public char* generate(int length)
{
    srand(time(NULL));
    random = rand() % word_map->size();
}

public int main(int argc, char** argv)
{
    char* text;
    char* line;
    if(argc > 0)
    {
        FILE* fp = fopen(argv[0], "r");
        while(fscanf(fp, "%s", line) != EOF)
        {
            concat(text, line);
        }
    }

    return 0;
}
