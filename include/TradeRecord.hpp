#include <string>
#include <iostream>

struct TradeTimeStamp
{
  public:

    TradeTimeStamp() : _valid(false) {;}

    TradeTimeStamp(const std::string & time_str);

    bool is_valid() const { return _valid; }

    bool operator < (const TradeTimeStamp & rhs) {
        return (_date < rhs._date ||
                (_date == rhs._date &&
                 (_hour < rhs._hour ||
                  (_hour == rhs._hour &&
                   (_minute < rhs._minute ||
                    (_minute == rhs._minute &&
                     (_second < rhs._second)
                        )
                       )
                      )
                     )
                    )
            );
    }

    friend std::ostream & operator << (std::ostream & s, const TradeTimeStamp & rhs); 
    
  private:
    
    int _date;
    short int _hour;
    short int _minute;
    float _second;
    bool _valid;
};

struct TradeRecord
{
    TradeRecord(const std::string & record_str);

    bool valid() const {
        return time.is_valid() && price >= .0 && volume >= .0;
    }

    friend std::ostream & operator << (std::ostream & s, const TradeRecord & rhs);
    
    float price;
    float volume;
    TradeTimeStamp time;
};
