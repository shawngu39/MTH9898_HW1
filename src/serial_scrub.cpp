#include <util/FileUtil.hpp>
#include <util/StringUtil.hpp>
#include <util/Log4cppConfigurator.hpp>
#include <util/CmdLineParser.hpp>
#include <util/Profiler.hpp>

#include <log4cpp/Category.hh>

#include <TradeRecord.hpp>

#include <iostream>

using namespace std;

int main(int argc, const char **argv)
{
    CmdLineParser cmd_parser;
    cmd_parser.parse(argc - 2, &argv[2]);
    const string file_name(argv[1]);
    Log4cppConfigurator::configure(cmd_parser.debug());

    log4cpp::Category& cat =
            log4cpp::Category::getInstance("MAIN");
    const bool debug = cat.isDebugEnabled();
    
    Profiler prof;
    prof.start();
    
    vector<string> lines;
    FileUtil::read(file_name, lines);
    vector<TradeRecord> records;
    for (size_t idx = 0; idx < lines.size(); ++idx)
    {
        records.push_back(TradeRecord(lines[idx]));
    }

    prof.stop();

    cat.infoStream()
        << "Spent " << prof.time_elapsed_ms()
        << " ms loading and parsing the file";

    if (debug)
    {
        cat.debugStream()
            << "Dump the parsed records";
        for (size_t idx = 0; idx < records.size(); ++idx)
        {
            ostringstream oss;
            oss << records[idx];
            cat.debugStream() << oss.str();
        }
        cat.debugStream()
            << "Finish dumping the parsed records";
    }
    return 0;
}
