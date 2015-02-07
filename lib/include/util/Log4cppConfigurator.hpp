#include <string>
#include <map>
#include <vector>

class Log4cppConfigurator
{
  public:

    static void configure(const std::string & streams);

    static void configure(const std::map<std::string, std::string> & streams);

  private:

    static void _configure(const std::vector<std::string> & stream_vec);
};
