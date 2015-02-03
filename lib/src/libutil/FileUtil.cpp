#include <util/FileUtil.hpp>
#include <log4cpp/Category.hh>

#include <fstream>

using namespace std;

bool
FileUtil::read(
    const string & file_name,
    vector<string> & output
    )
{
    static log4cpp::Category& cat =
        log4cpp::Category::getInstance("FILEUTIL.READ");
    static const bool debug = cat.isDebugEnabled();

    if (debug)
    {
        cat.debugStream()
            << "Read file " << file_name;
    }
    
    output.clear();
    ifstream ifs(file_name.c_str());

    if (!ifs.is_open())
    {
        cat.errorStream()
            << "Failed to open the file "
            << file_name;
        return false;
    }
    
    string line;
    while (ifs.good() && !ifs.eof())
    {
        getline(ifs, line);
        if (!line.empty())
        {
            output.push_back(line);
            if (debug)
            {
                cat.debugStream()
                    << "Reading line: "
                    << line << ". (" << line.size() << ")";
            }
        }
    }
    return true;
}
