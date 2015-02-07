#include <string>
#include <map>

class CmdLineParser : public std::map<std::string, std::string>
{
  public:

    CmdLineParser() : _debug() {;}

    void parse(int argc, const char ** argv);

    const std::map<std::string, std::string> & debug() const { return _debug; }

    void dump() const;
    
  private:

    std::map<std::string, std::string> _debug;
};
