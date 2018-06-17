//
//  SFInterval.cpp
//  my_assignment3
//
//  Created by Jing Liang on 2/19/18.
//  Copyright © 2018 Jing Liang. All rights reserved.
//
#include <cstring>
#include "SFInterval.hpp"
namespace SoftwareFoundations{
    
    
    SFInterval::SFInterval(SFInterval &aCopy){
        years = aCopy.years;
        months = aCopy.months;
        days = aCopy.days;
        hours = aCopy.hours;
        minutes = aCopy.minutes;
        seconds = aCopy.seconds;
    }
    
    
    SFInterval& SFInterval::setYears(int ayear){
        years = ayear;
        return *this;
    }
    SFInterval& SFInterval::setMonths(int amonth){
        months = amonth;
        return *this;
    }
    SFInterval& SFInterval::setDays(int aday ){
        days = aday;
        return *this;
    }
    SFInterval& SFInterval::setHours(int ahour){
        hours = ahour;
        return *this;
    }
    SFInterval& SFInterval::setMinutes(int aminute){
        minutes = aminute;
        return *this;
    }
    SFInterval& SFInterval::setSeconds(int asecond){
        seconds = asecond;
        return *this;
    }
    SFInterval& SFInterval::adjustDay(int aday){
        days = days+aday;
        return *this;
    }
    int SFInterval::SFIgetYears() const{
        return years;
    }
    int SFInterval::SFIgetMonths() const{
        return months;
    }
    int SFInterval::SFIgetDays() const{
        return days;
    }
    int SFInterval::SFIgetHours() const{
        return hours;
    }
    int SFInterval::SFIgetMinutes() const{
        return minutes;
    }
    int SFInterval::SFIgetSeconds() const{
        return seconds;
    }
    
    
    SFInterval SFInterval::operator+(SFInterval &another){
        years += another.years;
        months += another.months;
        days += another.days;
        hours += another.hours;
        minutes += another.minutes;
        seconds += another.seconds;
        return *this;
    }
    
    SFInterval SFInterval::operator=(SFInterval &another){
        years = another.years;
        months = another.months;
        days = another.days;
        hours = another.hours;
        minutes = another.minutes;
        seconds = another.seconds;
        return *this;
    }
    
    SFInterval::operator const char*(){
        std::string date = std::to_string(years) + " years, "+ std::to_string(months) +" months, "+ std::to_string(days) +" days, " + std::to_string(hours) +" hours, " + std::to_string(minutes) +" minutes and "+ std::to_string(seconds) +" seconds";
        // Returns the interval of the form "Y years, M months, D days, H hours, M minutes and S seconds"
        // Ex. 5 years, 3 months, 2 days, 6 hours, 7 minutes and 10 seconds
        const char* timediff = date.c_str();
        return timediff;
    }
}
