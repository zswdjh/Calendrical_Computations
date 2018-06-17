//
//  SFDateTime.hpp
//  my_assignment3
//
//  Created by Jing Liang on 2/19/18.
//  Copyright © 2018 Jing Liang. All rights reserved.
//

#ifndef SFDateTime_hpp
#define SFDateTime_hpp

#include <stdio.h>
#include "SFInterval.hpp"
#include "SFTimezone.hpp"
#include "SFDate.hpp"
#include "SFTime.hpp"
namespace SoftwareFoundations{
    class SFDateTime:public SFDate,public SFTime {
    public:
        SFDateTime(SFTimezone *aTimezone=nullptr); //init a new datetime based on GMT, unless a valid timezone is provided
    
        SFDateTime(const SFDateTime &aCopy); //copy construct
        SFDateTime(int aMonth, int aDay, int aYear, int anHour=0, int aMinutes=0, int aSeconds=0, SFTimezone *aTimezone=nullptr);
        SFDateTime(const char* aString, SFTimezone *aTimezone=nullptr); //parse the given string of the form "MM/DD/YYYY HH:MM:SS"
        SFDateTime(const SFDate &aDate, const SFTime &aTime, SFTimezone *aTimezone=nullptr);
        
        
        SFInterval operator-(const SFDateTime &aother); //determine interval between two objects...
        
        SFTimezone getTimezone() const; //retrieve timezone currently associated with this object
        SFDateTime&  setTimezone(SFTimezone &aTimezone); //change timezone
        
        //ADD RELATIONAL OPERATORS HERE... >, <, <=, >=, !=, ==
        bool operator>(const SFDateTime &adatetime);
        bool operator<(const SFDateTime &adatetime);
        bool operator>=(const SFDateTime &adatetime);
        bool operator<=(const SFDateTime &adatetime);
        bool operator==(const SFDateTime &adatetime);
        bool operator!=(const SFDateTime &adatetime) ;
        
        
        
        operator const char*();   //Returns string of the form "MON DATE, YEAR HH:MM:SS TIMEZONE" Ex. Jan 4, 1961 09:15:00 PST
        operator SFDate() ;
        operator SFTime() ;
        operator SFTimezone();
        
        std::string toDateTimeString();   //Jan 4, 1961 09:15:00 PST (always this format)
    private:
        SFTimezone SFDTzone;
     };

}
#endif /* SFDateTime_hpp */


/*
 public:
 
 private:
 int SFDTyear;
 int SFDTmonth;
 int SFDTday;
 int SFDThour;
 int SFDTminute;
 int SFDTsecond;
 char* SFDTzone;*/
