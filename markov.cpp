#include "markov.h"

using namespace std;

char* Markov::concat(char* a, char* b)
{
    char* strbuf = (char*)(malloc(sizeof(char) * (strlen(a) + strlen(b)));
    strcat(strbuf, a);
    strcat(strbuf, b);
    return strbuf;
}

char* Markov::next(ifstream in)
{
    char* text;
    char ch;
    while((in >> ch) != ' ')
    {
        if(ch == EOF)
            return NULL;
        text = concat(text, &ch);
    }

    return text;
}

void Markov::initialize(char* file_name)
{
    ifstream in(file_name);
    char* a = next(in), b = next(in), c = next(in);
    key_pair word_pair;
    vector<char*> values;

    while(true)
    {
        if(c == NULL)
            break;
        word_pair = {a, b};
        values = word_map.find(word_pair).second;
        if(values == NULL)
        {
            values = new vector<char*>;
            values.push_back(c);
            word_map[word_pair] = values;
        }
        else
            values.push_back(c);
    }
}

char* Markov::generate(int length)
{
    char* text;
    srand(time(NULL));
    rand_pos = rand() % word_map->size();
    pair<key_pair, vector<char*>> map_array[word_pair.size()];
    int pos = 0;
    for(auto i = begin(word_pair); i != word_map.end(); i++)
    {
        map_array[pos] = i->first;
        pos++;
    }

    char* a = map_array[rand_pos].first,
          b = map_array[rand_pos].second;

    vector<char*> values;

    for(int i = 0; i < length; i++)
    {
        values = word_map.find(key_pair{a, b}).second;

        text = concat(text, a);

        a = b;
        b = values.at(rand() % values.size());
    }

    return text;
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
