#include <util/Log4cppConfigurator.hpp>
#include <util/StringUtil.hpp>

#include "log4cpp/Category.hh"
#include "log4cpp/FileAppender.hh"
#include "log4cpp/OstreamAppender.hh"
#include "log4cpp/Priority.hh"

using namespace std;

void
Log4cppConfigurator::configure(
    const string & streams
    )
{
    log4cpp::Appender *appender1 =
        new log4cpp::OstreamAppender("console", &std::cout);
    appender1->setLayout(new log4cpp::BasicLayout());

    log4cpp::Category& root = log4cpp::Category::getRoot();
    root.setPriority(log4cpp::Priority::INFO);
    root.addAppender(appender1);
    
    vector<string> stream_vec;
    const char delim = ' ';
    StringUtil::split(streams, delim, stream_vec);
    for (size_t idx = 0; idx < stream_vec.size(); ++idx)
    {
        log4cpp::Category& cat =
            log4cpp::Category::getInstance(stream_vec[idx]);
        cat.setPriority(log4cpp::Priority::DEBUG);
    }
}
