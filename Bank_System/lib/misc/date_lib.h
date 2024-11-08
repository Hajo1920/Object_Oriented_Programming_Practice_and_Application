#pragma once
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class clsDate {
    private:

    short _day = 1;
    short _month = 1;
    short _year = 1900;


    static bool isLeapYear(short year){
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    
    }

    static short NumberOfDaysInMonth(short year, short month){

    short daysInMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (month == 2) ? (isLeapYear(year) ? 29:28) : daysInMonth[month-1];
    }


    static short RemainingDaysOfYear(short day, short month, short year){

    short remainingDays = 0;
    for(short x = 1; x < month; x++){
        remainingDays+= NumberOfDaysInMonth(year, x);
    }
   
    return remainingDays + day;
}

vector<string> Spliter(string str ,string delimeter){
    vector<string> vWords;
    string word;
    short pos = 0;

    while((pos = str.find(delimeter)) != std::string::npos){
        word = str.substr(0, pos);

        if(!word.empty()){
            vWords.push_back(word);
        }

        str.erase(0, pos + delimeter.length());
    }
    if(!str.empty()){
        vWords.push_back(str);
    }

    return vWords;
}

static string GetMonthName(int month){
    const string arrMonths[12] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};

    return arrMonths[month-1];
}

static int GetDay(short day, short month, short year){
    short A ,Y ,M;

    A = (14-month) /12;
    Y = year - A;
    M = month + (12*A)-2;

    return (day + Y + (Y/4)-(Y/100)+(Y/400)+((31*M)/12))%7;
}

    public:

    clsDate(){
    time_t t = time(0);
    tm* now = localtime(&t);

    _year = now->tm_year + 1900;
    _month = now->tm_mon + 1;
    _day = now->tm_mday;

    }
      
    clsDate(string str){
        vector<string> vDate = Spliter(str, "/");
        _day = stoi(vDate[0]);
        _month = stoi(vDate[1]);
        _year = stoi(vDate[2]);
    }

    clsDate(short day, short month, short year){
        _day = day;
        _month = month;
        _year =year;
    }

    clsDate(short days, short year){
     clsDate Date = GetDateFromDayOrderInYear(days, year);
    _day = Date._day;
     _month = Date._month;
     _year = Date._year;
    }

    void setDate(short day){
        _day = day;
    }

    short getDate(){
        return _day;
    }

    void setMonth(short month){
        _month = month;
    }
    short getMonth(){
        return _month;
    }

    void setYear(short year){
        _year = year;
    }

    short getYear(){
        return _year;
    }

    static string DateToString(clsDate Date){
        return to_string( Date._day) + "/" + to_string(Date._month) + "/" + to_string(Date._year);
        }

string DateToString(){
    return DateToString(*this);
}

    void Print(){
        cout << DateToString() << endl;
    }

static clsDate GetDateFromDayOrderInYear(short addedDays, short Year) {
    clsDate Date;

    Date._year = Year;
    Date._month = 1;
    Date._day = 1;
   int remainingDays = addedDays + RemainingDaysOfYear(Date._day, Date._month, Date._year);
    
    short monthDays = 0;
    while(true){
        monthDays = NumberOfDaysInMonth(Date._year, Date._month);
        if(remainingDays > monthDays){
            remainingDays-= monthDays;
            Date._month++;
             if(Date._month > 12){
            Date._month = 1;
            Date._year++;
        }
        }
       
        else{
            Date._day = remainingDays;
            break;
        }
    }
    return Date;
        }

    static bool IsValidDate(clsDate Date){

        if (Date._day < 1 || Date._day>31) return false;

        if (Date._month < 1 || Date._month>12) return false;

        if (Date._month == 2){ 
            if (isLeapYear(Date._year)){
                if (Date._day > 29)
                return false;
            }else{
                if (Date._day > 28)
                return false;
            }
            }   

            return true;
    }

    bool IsValidDate(){
        return IsValidDate(*this);
    }

  clsDate IncreaseDateByOneMonth(clsDate& Date){
    if (Date._month == 12){
        Date._month = 1;
        Date._year++;
        }else{
        Date._month++;
        }

        return Date;
  }

  void IncreaseDateByOneMonth(){
     IncreaseDateByOneMonth(*this);
  }

  void PrintYearCalendar(){
    int current = GetDay(1, _month, _year);
    int numberOfDays = NumberOfDaysInMonth(_year, _month);

    cout << endl << " ===============[-" << GetMonthName(_month) << "-]=============== " << endl;
    cout << "   Sun  Mon  Tue  Wed  Thu  Fri  Sat \n" << endl;

    unsigned short i;
    for (i = 0; i < current; i++)
        cout << "     ";

    for (int j = 1; j <= numberOfDays; j++) {
        (j <= 9) ? cout  << setw(4) << "0" << j :cout << setw(5) << j;
        if (++i == 7) {
            i = 0;
            cout << "\n\n";
        }
    }
    cout << "\n ===================================== \n" << endl;
    
}

static void PrintYearCalendar(clsDate Date){
    
    int current = GetDay(1, Date._month, Date._year);
    int numberOfDays = NumberOfDaysInMonth(Date._year, Date._month);

    cout << endl << " ===============[-" << GetMonthName(Date._month) << "-]=============== " << endl;
    cout << "   Sun  Mon  Tue  Wed  Thu  Fri  Sat \n" << endl;

    unsigned short i;
    for (i = 0; i < current; i++)
        cout << "     ";

    for (int j = 1; j <= numberOfDays; j++) {
        (j <= 9) ? cout  << setw(4) << "0" << j :cout << setw(5) << j;
        if (++i == 7) {
            i = 0;
            cout << "\n\n";
        }
    }
    cout << "\n ===================================== \n" << endl;
    
}

static bool isDateOneBeforeDatetwo(clsDate DayOne, clsDate DayTwo){
  return DayOne._year < DayTwo._year ? true : (DayOne._year == DayTwo._year ? (DayOne._month < DayTwo._month ? true: (DayOne._month == DayTwo._month ? (DayOne._day < DayTwo._day) : false)):false);
}

static bool checkIsLaclsDate(clsDate Day){
  return Day._day == NumberOfDaysInMonth(Day._year, Day._month);
}


static bool checkIsLastMonth(short month){
    return month == 12;
}

static clsDate IncreaseDateByOneDay(clsDate Date) {
    if (checkIsLaclsDate(Date)) {
        if (checkIsLastMonth(Date._month)) {
            Date._month = 1;
            Date._day = 1;
            Date._year++;
        } else {
            Date._day = 1;
            Date._month++;
        }
    } else {
        Date._day++;
    }
    return Date;
}

static clsDate GetSystemDate(){
    clsDate Date;
     time_t t = time(0);
    tm* now = localtime(&t);

    Date._year = now->tm_year + 1900;
    Date._month = now->tm_mon + 1;
    Date._day = now->tm_mday;

    return Date;
}
static string GateSystemDateAndTime(){
     time_t t = time(0);
     tm* now = localtime(&t);
    string time = to_string(now->tm_hour) + ":" + to_string(now->tm_min) + ":" + to_string(now->tm_sec);

    return DateToString(clsDate()) + " - " + time;
}


static void SwapDates(clsDate& Date1, clsDate& Date2) {
    clsDate TempDate;
    TempDate._year = Date1._year;
    TempDate._day = Date1._year;
    TempDate._day = Date1._year;

    Date1._year = Date2._year;
    Date1._month = Date2._month;
    Date1._day = Date2._day;

    Date2._year = TempDate._year;
    Date2._month = TempDate._month;
    Date2._day = TempDate._day;
}

static int GetDifferenceInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay = false) {
    int Days = 0;
    short SawpFlagValue = 1;
    if (!isDateOneBeforeDatetwo(Date1, Date2)) {
        SwapDates(Date1, Date2);
        SawpFlagValue = -1;
    }
    while (isDateOneBeforeDatetwo(Date1, Date2)) {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }
    return IncludeEndDay ? ++Days * SawpFlagValue : Days * SawpFlagValue;
}

static short CalculateMyAgeInDays(clsDate DateOfBirth)
	{
		return GetDifferenceInDays(DateOfBirth,clsDate::GetSystemDate(), true);
	}


static bool isDateOneEqualsDatetwo(clsDate DayOne, clsDate DayTwo){

  return DayOne._year == DayTwo._year  ? DayOne._month == DayTwo._month ? DayOne._month == DayTwo._month : false : false;
}

static bool isDateOneAfterDatetwo(clsDate DayOne, clsDate DayTwo){

  return (!isDateOneBeforeDatetwo(DayOne,DayTwo)) && !isDateOneEqualsDatetwo(DayOne, DayTwo);
}    
  
};