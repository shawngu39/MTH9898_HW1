#include <util/Log4cppConfigurator.hpp>
#include <util/StringUtil.hpp>

#include "log4cpp/Category.hh"
#include "log4cpp/FileAppender.hh"
#include "log4cpp/OstreamAppender.hh"
#include "log4cpp/Priority.hh"

using std::string;
using std::vector;
using std::map;

void
Log4cppConfigurator::configure(
    const string & streams
    )
{   
    vector<string> stream_vec;
    const char delim = ' ';
    StringUtil::split(streams, delim, stream_vec);
    _configure(stream_vec);
}

void
Log4cppConfigurator::configure(
    const map<string, string> & streams
    )
{
    vector<string> stream_vec;
    for (auto iter = streams.begin(); iter != streams.end(); ++iter)
    {
        stream_vec.push_back(iter->first);
    }
    _configure(stream_vec);
}

void
Log4cppConfigurator::_configure(
    const vector<string> & stream_vec
    )
{
    log4cpp::Appender *appender1 =
        new log4cpp::OstreamAppender("console", &std::cout);
    appender1->setLayout(new log4cpp::BasicLayout());

    log4cpp::Category& root = log4cpp::Category::getRoot();
    root.setPriority(log4cpp::Priority::INFO);
    root.addAppender(appender1);

    for (size_t idx = 0; idx < stream_vec.size(); ++idx)
    {
        log4cpp::Category& cat =
            log4cpp::Category::getInstance(stream_vec[idx]);
        cat.setPriority(log4cpp::Priority::DEBUG);
    }
}
