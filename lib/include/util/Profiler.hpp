#include <chrono>


class Profiler
{
  public:

    Profiler() {;}

    void start() { _start = std::chrono::steady_clock::now(); }

    void stop() { _end = std::chrono::steady_clock::now(); }

    std::chrono::steady_clock::rep time_elapsed_ms() const;

    std::chrono::steady_clock::rep time_elapsed_ns() const;
    
  private:

    std::chrono::steady_clock::time_point _start;
    std::chrono::steady_clock::time_point _end;
};
