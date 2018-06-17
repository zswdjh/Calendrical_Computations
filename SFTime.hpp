//
//  SFTime.hpp
//  my_assignment3
//
//  Created by Jing Liang on 2/19/18.
//  Copyright © 2018 Jing Liang. All rights reserved.
//

#ifndef SFTime_hpp
#define SFTime_hpp
#include "SFInterval.hpp"
#include <stdio.h>
#include <string>
namespace SoftwareFoundations{
    class SFDateTime;
    class SFTime {
    public:
        SFTime();                             //default to now(HH:MM:SS)
        SFTime(const char *aTimeString);      //must parse the given string of the form "HH:MM:SS"
        SFTime(int anHour, int aMinutes, int aSeconds); //build time from individual parts
        SFTime(const SFTime &aCopy);
        SFTime(const SFDateTime &aCopy);
        
        SFTime& adjustByMinutes(int n) ;//-- to +/- N minutes from the given time
        SFTime& adjustByHours(int n) ;//-- to +/- N hours from the given time. 11:15pm + 2hours is 1:15a (rolls over)
        
        SFInterval operator-(const SFTime &other) const; //determine interval between two times...
        SFInterval operator-(const SFDateTime &aother) const; //determine interval between two objects...
        
        int   getHour() const;
        int   getMinutes() const;
        int   getSeconds() const;
        int   getDayAdjust() const;
        
        SFTime& setHour(int ahour);
        SFTime& setMinute(int amin);
        SFTime& setSecond(int asec);
        
        SFTime& startOfDay(); //change time to (00:00:00)
        SFTime& endOfDay();  // change time to (23:59:59)
        
        std::string toTimeString();  //Returns string of the form HH:MM:SS
        
        //ADD RELATIONAL OPERATORS HERE... >, <, <=, >=, !=, ==
        bool operator>(const SFTime &aSFTime) const;
        bool operator<(const SFTime &aSFTime) const;
        bool operator>=(const SFTime &aSFTime) const;
        bool operator<=(const SFTime &aSFTime) const;
        bool operator==(const SFTime &aSFTime) const;
        bool operator!=(const SFTime &aSFTime) const;
        
    protected:
        int SFhour;
        int SFmin;
        int SFsec;
        bool timevalid(int thehour,int themin, int thesec) const;
        bool timevalid() const;
        int dayadjustM;  //day adjust caused by adding or subtracting the minutes.
        
    };
}
#endif /* SFTime_hpp */
