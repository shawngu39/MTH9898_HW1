#include <util/Profiler.hpp>

using namespace std::chrono;

steady_clock::rep
Profiler::time_elapsed_ms() const
{
    return duration_cast<std::chrono::milliseconds>(_end - _start).count();
}

steady_clock::rep
Profiler::time_elapsed_ns() const
{
    return duration_cast<std::chrono::nanoseconds>(_end - _start).count();
}
