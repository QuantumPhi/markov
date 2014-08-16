#include "markov.hxx"

string Markov::next(ifstream input)
{
    string text;
    char ch;
    while((input >> ch) != ' ')
    {
        if(ch == EOF)
            return NULL;
        text += ch;
    }

    return text;
}

void Markov::initialize(char* file_name)
{
    ifstream in(file_name);
    string a = next(in), b = next(in), c = next(in);
    key_pair word_pair;
    vector<string> values;

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

string Markov::generate(int length)
{
    string text;
    srand(time(NULL));
    rand_pos = rand() % word_map->size();
    pair<key_pair, vector<char*> > map_array[word_pair.size()];
    int pos = 0;
    for(auto i = begin(word_pair); i != word_map.end(); i++)
    {
        map_array[pos] = i->first;
        pos++;
    }

    string a = map_array[rand_pos].first,
          b = map_array[rand_pos].second;

    vector<string> values;

    for(int i = 0; i < length; i++)
    {
        values = word_map.find(key_pair{a, b}).second;

        text += a;

        a = b;
        b = values.at(rand() % values.size());
    }

    return text;
}

int main(int argc, char** argv)
{
    return 0;
}
