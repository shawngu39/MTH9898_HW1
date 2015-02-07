#include <TradeRecord.hpp>

#include <util/StringUtil.hpp>

#include <vector>

using std::vector;
using std::string;


TradeTimeStamp::TradeTimeStamp(
    const string & time_str
    ) : _valid(false)
{
    vector<string> time_parts;
    vector<string> seconds; 
    StringUtil::split(time_str, ':', time_parts);

    if (time_parts.size() != 4)
    {
        return;
    }

    // Implicit conversion from int to short int for _hour, _minute and _second.
    _date = std::stoi(time_parts[0]);
    _hour = std::stoi(time_parts[1]);
    _minute = std::stoi(time_parts[2]);
    _second = std::stof(time_parts[3]);
    _valid = true;
}

std::ostream &
operator << (
    std::ostream & s,
    const TradeTimeStamp & rhs
    )
{
    return s << rhs._date << ":"
             << rhs._hour << ":"
             << rhs._minute << ":"
             << rhs._second;
}


TradeRecord::TradeRecord(
    const string & record_str
    )
{
    vector<string> elements;

    StringUtil::split(record_str, ',', elements);

    // This is not very efficient. Can improve the construction-copy if I have more time.
    time = TradeTimeStamp(elements[0]);
    price = std::stof(elements[1]);
    volume = std::stof(elements[2]);
}


std::ostream &
operator << (
    std::ostream & s,
    const TradeRecord & rhs
    )
{
    return s << rhs.time << "\t"
             << rhs.price << "\t"
             << rhs.volume;
}
