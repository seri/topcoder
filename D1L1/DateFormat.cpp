#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

class Date {
public:
    int day, month; 
    Date (int day, int month) : day(day), month(month) { } 
    bool operator < (Date const &date) const {
        if (month < date.month) return true;
        if (month > date.month) return false;
        return day < date.day;
    }
    bool operator <= (Date const &date) const { 
        if (month < date.month) return true;
        if (month > date.month) return false;
        return day <= date.day;
    }
    Date& operator = (Date const &date) {
        day = date.day;
        month = date.month;
        return *this;
    }
    bool valid() const {
        return month <= 12;
    }
}; 
istream& operator >> (istream &is, Date &date) {
    is >> date.day; is.ignore(1); is >> date.month;
    return is;
}
ostream& operator << (ostream &os, Date const &date) {
    os << setw(2) << setfill('0') << date.month << '/' 
       << setw(2) << setfill('0') << date.day;
    return os;
}

string concat(vector<string> v) {
    ostringstream oss;
    for (int i = 0; i < v.size(); ++i)
        oss << v[i];
    return oss.str();
} 
string fromEuropeanToUs(vector<string> const &dateList)
{
    istringstream iss(concat(dateList)); ostringstream oss; 
    Date prev(0, 0), cur(0, 0);
    while (true) { 
        iss >> cur; 
        Date temp(cur.month, cur.day);

        if (cur <= prev) {
            if (temp <= cur || temp <= prev) return "";
            cur = temp;
        }
        else if (prev < temp && temp < cur) cur = temp; 
        if (!cur.valid()) return "";

        oss << cur; 
        if (iss.good()) { 
            oss << ' '; 
            prev = cur;
        }
        else break;
    } 
    return oss.str();
}
