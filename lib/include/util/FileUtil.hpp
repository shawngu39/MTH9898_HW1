#include <vector>
#include <string>

class FileUtil
{
  public:

    static bool read(const std::string & file_name,
                     std::vector<std::string> & output);
};
