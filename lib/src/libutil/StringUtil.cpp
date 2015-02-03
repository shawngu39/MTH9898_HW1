#include <util/StringUtil.hpp>

#include <sstream>

using namespace std;

void
StringUtil::split(
    const string & input,
    const char delim,
    vector<string> & output
    )
{
    output.clear();
    stringstream iss(input);
    string elem;
    while (getline(iss, elem, delim))
    {
        output.push_back(elem);
    }
}
