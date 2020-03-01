#include "a.hpp"

#include <map>

int some_function(string key)
{
    auto m = map<string, int>
    {
        {"one", 1},
        {"two", 2},
        {"three", 3}
    };

    if (m.count(key))
        return m.at(key);
    else 
        throw "Error. Unknown key: " + key;
}