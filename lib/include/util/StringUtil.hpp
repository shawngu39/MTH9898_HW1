#include <vector>
#include <string>

class StringUtil
{
  public:

    static void split(const std::string& input,
                      const char delim,
                      std::vector<std::string>& output);
};
