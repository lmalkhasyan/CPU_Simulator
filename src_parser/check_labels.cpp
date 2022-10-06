#include <map>
#include <string>
#include <vector>

void map_labels(std::vector<std::string> &str, size_t line, std::multimap<std::string, size_t> &labels)
{
    auto it = str.begin();
	if(it < str.end() && it->back() == ':')
    {
        it->pop_back();
        labels.insert({*it,line});
        str.erase(str.begin());
    }
} 

void check_labels(std::string &line)
{
    for (size_t i = 0; line[i] != '\0'; ++i)
    {
        if (line[i] == ':')
        {
            line.insert(i + 1, 1,' ');
            ++i;
        }
    }
}