//
//  SFInterval.hpp
//  my_assignment3
//
//  Created by Jing Liang on 2/19/18.
//  Copyright © 2018 Jing Liang. All rights reserved.
//

#ifndef SFInterval_hpp
#define SFInterval_hpp

#include <stdio.h>
#include <iostream>
#include <string>
namespace SoftwareFoundations{
    class SFInterval {
    public:
        SFInterval(int year=0,int month=0,int day=0,int hour=0,int minute=0,int second=0):years(year),months(month),days(day),minutes(minute),hours(hour),seconds(second){}
        SFInterval(SFInterval &aCopy);
        operator const char*(); // Returns the interval of the form "Y years, M months, D days, H hours, M minutes and S seconds"
        // Ex. 5 years, 3 months, 2 days, 6 hours, 7 minutes and 10 seconds
        
        SFInterval& setYears(int ayear);
        SFInterval& setMonths(int amonth);
        SFInterval& setDays(int aday );
        SFInterval& setHours(int ahour);
        SFInterval& setMinutes(int aminute);
        SFInterval& setSeconds(int asecond);
        SFInterval& adjustDay(int aday);
        
        int SFIgetYears() const;
        int SFIgetMonths() const;
        int SFIgetDays() const;
        int SFIgetHours() const;
        int SFIgetMinutes() const;
        int SFIgetSeconds() const;
        int SFIgetadjustDay() const;
        SFInterval operator+(SFInterval &another);
        SFInterval operator=(SFInterval &another);
    private:
        int years;
        int months;
        int days;
        int hours;
        int minutes;
        int seconds;
        
    };
}
#endif /* SFInterval_hpp */
