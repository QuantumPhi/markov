#include <string.h>

#include "pair.h"

using namespace std;

public char* concat(char* a, char* b)
{
    char str[strlen(a) + strlen(b)];
    strcpy(str, a);
    strcat(str, b);
    return &str;
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
