#include <util/CmdLineParser.hpp>

#include <iostream>

using namespace std;

void
CmdLineParser::parse(
    int argc,
    const char ** argv
    )
{
    int idx = 0;
    string switch_name;
    string switch_value;
    while (idx < argc)
    {
        const string elem(argv[idx]);
        if (elem.at(0) == '-')
        {
            switch_name = elem.substr(1, elem.length());
            switch_value = string(argv[idx + 1]);
            ++idx;
        }
        else
        {
            switch_value = string(argv[idx]);
        }

        if (switch_name.empty())
        {
            cerr << "empty switch name, error..." << endl;
        }
        else if (switch_name == "debug")
        {
            _debug[switch_value] = "debug";
        }
        else
        {
            this->insert(make_pair(switch_name, switch_value));
        }
        ++idx;
    }
}

void
CmdLineParser::dump() const
{
    cout << "Dump the switch-value pairs" << endl;
    for (map<string, string>::const_iterator iter = this->begin();
         iter != this->end(); ++iter)
    {
        cout << iter->first << " - " << iter->second << endl;
    }
    cout << "Dump the debug streams" << endl;
    for (map<string, string>::const_iterator iter = _debug.begin();
         iter != _debug.end(); ++iter)
    {
        cout << iter->first << " - " << iter->second << endl;
    }
}
