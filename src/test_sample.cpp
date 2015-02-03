#include <util/FileUtil.hpp>
#include <util/StringUtil.hpp>
#include <util/Log4cppConfigurator.hpp>

#include "log4cpp/Category.hh"

#include <iostream>

using namespace std;

int main()
{
    const string debug_stream("FILEUTIL.READ");
    Log4cppConfigurator::configure("");

    log4cpp::Category& cat =
            log4cpp::Category::getInstance("MAIN");
    const bool debug = cat.isDebugEnabled();
    
    string file_name("/media/sf_Baruch/MATH9898_Big_Data/HW/HW1/data10.txt");
    vector<string> lines;
    FileUtil::read(file_name, lines);
    vector<string> elems;
    
    for (size_t idx = 0; idx < lines.size(); ++idx)
    {
        cat.infoStream() << "line " << idx << ": " << lines[idx];
    }
    
    for (size_t idx = 0; idx < lines.size(); ++idx)
    {
        StringUtil::split(lines[idx], ',', elems);
        
        if (elems.size() != 3)
        {
            cat.errorStream() << "Incorrect format";
            continue;
        }
        cat.infoStream() << elems[0] << "\t" << elems[1]
             << "\t" << elems[2];
    }
    return 0;
}
