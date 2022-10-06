#include <string>

void toLowerCase(std::string &str)
{
    for (size_t i = 0; str[i] != '\0'; ++i)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] + 32;
        }
    }
}