//
//  SFDate.cpp
//  my_assignment3
//
//  Created by Jing Liang on 2/19/18.
//  Copyright © 2018 Jing Liang. All rights reserved.
//
#include "SFDateTime.hpp"
#include "SFDate.hpp"
#include <ctime>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <map>
#include <cctype>
#include <sstream>
namespace SoftwareFoundations{
    SFDate::SFDate(){
        time_t now=time(NULL);
        tm *ltm = localtime(&now);
        SFyear = 1900+ltm->tm_year;
        SFmonth = 1+ltm->tm_mon;
        SFday = ltm->tm_mday;
    }
    
    void SFDate::checkvalid() const{
        while(1){
            if(SFyear<0){
                std::cerr<<"The year can not be a negative value!"<<std::endl;
            }
            if(SFmonth<=0 || SFmonth>12){
                std::cerr<<"The month is invalid! "<<std::endl;
            }
            if( SFday<=0 || SFday>31 ){
                std::cerr<<"The date is invalid!"<<std::endl;
            }
            if( SFday==31&&(SFmonth==2||SFmonth==4||SFmonth==6||SFmonth==9||SFmonth==11) ){
                std::cerr<<"This month doesn't have 31 days!"<<std::endl;
            }
            if( SFday==30 && SFmonth==2){
                std::cerr<<"Febrary doesn't have 30 days!"<<std::endl;
            }
            if( SFday==29 && SFmonth==2 && !checkleap()){
                std::cerr<<"Febrary doesn't have 29 days in normal year!"<<std::endl;
            }
            break;
        }
    }
    
    bool SFDate::checkleap() const{
        return (SFyear % 4 == 0 && SFyear % 100 !=0) || (SFyear % 400 == 0) ;
    }
    
    SFDate::SFDate(const char *aDateTimeString){
        if (aDateTimeString!=nullptr){
            if(isdigit(aDateTimeString[0])){   // deal with the format "MM/DD/YYYY"
            std::string aDateString(aDateTimeString);
            auto pos = aDateString.find("/");
            std::string month = aDateString.substr(0,pos);
            aDateString = aDateString.erase(0,pos+1);
            pos = aDateString.find("/");
            std::string day = aDateString.substr(0,pos);
            aDateString = aDateString.erase(0,pos+1);
            std::string year = aDateString;
            SFmonth = std::stoi(month);
            SFday = std::stoi(day);
            SFyear = std::stoi(year);
            }
            if(isalpha(aDateTimeString[0])){    //deal with format "Jan 1,1961" or "January 1,1961"
                std::map<std::string,int>monthname = { {"Jan",1},{"Feb",2},{"Mar",3},{"Apr",4},{"May",5},{"Jun",6},{"Jul",7},{"Aug",8},{"Sep",9},{"Sept",9},{"Oct",10},{"Nov",11},{"Dec",12},{"January",1},{"February",2},{"March",3},{"April",4},{"June",6},{"July",7},{"August",8},{"September",9},{"October",10},{"November",11},{"December",12}};
                std::stringstream date(aDateTimeString);
                std::string month;
                std::string dayplusyear;
                date>>month>>dayplusyear;
                SFmonth = monthname.find(month)->second;
                auto pos = dayplusyear.find(",");
                std::string day = dayplusyear.substr(0,pos);
                SFday = std::stoi(day);
                dayplusyear = dayplusyear.erase(0,pos+1);
                SFyear = std::stoi(dayplusyear);
                
            }
           // checkvalid();
        }
        else{
            SFDate();
        }
            
       
        
    }
    
    int SFDate::offsetday() const{   //calculate how many days has passed in the current year.
        int offset = SFday;
        switch(SFmonth-1){
            case 11:
                offset+=30;
            case 10:
                offset+=31;
            case 9:
                offset+=30;
            case 8:
                offset+=31;
            case 7:
                offset+=31;
            case 6:
                offset+=30;
            case 5:
                offset+=31;
            case 4:
                offset+=30;
            case 3:
                offset+=31;
            case 2:
                offset+=28;
            case 1:
                offset+=31;
        }
        return offset;
    }
    
    SFDate::SFDate(int month, int day, int year){
       // checkvalid();
        SFyear = year;
        SFmonth = month;
        SFday = day;
        
    }
    
    SFDate::SFDate(const SFDate &aCopy){
        SFyear = aCopy.SFyear;
        SFmonth = aCopy.SFmonth;
        SFday = aCopy.SFday;
    }
    
   
     SFDate::SFDate(const SFDateTime &aCopy){
         SFyear = aCopy.getYear();
         SFmonth = aCopy.getMonth();
         SFday = aCopy.getDay();
     }
    
    
    SFDate& SFDate::operator++(){
        adjustByDays(1);
        return *this;
    }
    
    SFDate& SFDate::operator--(){
        adjustByDays(-1);
        return *this;
    }
    
    SFInterval SFDate::operator-(const SFDate &other) const{   //in the future , always second varaible minus first variable, including the end date.
        SFInterval diff;
        int month[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
            int bigday = 0;
            int daydiff = 0;
            int monthdate1 = 0;
            int monthdiff = 0;
            int monthdate2 = 0;
            int yeardate1 = 0;
            int yeardate2 = 0;
            int yeardiff = 0;
        if( (*this).operator<(other)){   //first variable is smaller than second, in the future
            if(other.getDay()<getDay()){
                 bigday = other.getDay()+ month[getMonth()];
                if( getMonth() ==2 && checkleap())
                    bigday +=1;
                 daydiff = bigday-getDay();
                 monthdate1 = getMonth()+1;
            }
            else{
                daydiff = other.getDay() -getDay();
                monthdate1 = getMonth();
            }
            
            if(other.getMonth()< monthdate1){
                monthdate2 = 12 + other.getMonth();
                monthdiff = monthdate2 - monthdate1;
                yeardate2 = other.getYear() - 1;
                
            }
            else{
                monthdate2 = other.getMonth();
                monthdiff = monthdate2 - monthdate1;
                yeardate2 = other.getYear();
            }
            
            yeardiff = yeardate2-getYear();
            diff.setDays( daydiff );
            diff.setMonths(monthdiff);
            diff.setYears(yeardiff);

        }else{
            if(getDay()<other.getDay()){
                bigday = getDay()+ month[other.getMonth()];
                if( other.getMonth() ==2 && other.checkleap())
                    bigday +=1;
                daydiff = bigday-other.getDay();
                monthdate2 = other.getMonth()+1;
            }
            else{
                daydiff = getDay() -other.getDay();
                monthdate2 = other.getMonth();
            }
            
            if(getMonth()< monthdate2){
                monthdate1 = 12 + getMonth();
                monthdiff = monthdate1 - monthdate2;
                yeardate1 = getYear() - 1;
            }
            else{
                monthdate1 = getMonth();
                monthdiff = monthdate1 - monthdate2;
                yeardate1 = getYear();
            }
            yeardiff = yeardate1-yeardate2;
            diff.setDays( -daydiff );
            diff.setMonths(-monthdiff);
            diff.setYears(-yeardiff);
            
        }
        return diff;
    } //determine interval between two dates...
    
    
    SFInterval SFDate::operator-(const SFDateTime &aother) const{  //determine interval between two objects...
        SFInterval diff;
        SFDate other(aother.getMonth(),aother.getDay(),aother.getYear());
        
        int month[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        int bigday = 0;
        int daydiff = 0;
        int monthdate1 = 0;
        int monthdiff = 0;
        int monthdate2 = 0;
        int yeardate1 = 0;
        int yeardate2 = 0;
        int yeardiff = 0;
        if( (*this).operator<(other)){   //first variable is smaller than second, in the future
            if(other.getDay()<getDay()){
                bigday = other.getDay()+ month[getMonth()];
                if( getMonth() ==2 && checkleap())
                    bigday +=1;
                daydiff = bigday-getDay();
                monthdate1 = getMonth()+1;
            }
            else{
                daydiff = other.getDay() -getDay();
                monthdate1 = getMonth();
            }
            
            if(other.getMonth()< monthdate1){
                monthdate2 = 12 + other.getMonth();
                monthdiff = monthdate2 - monthdate1;
                yeardate2 = other.getYear() - 1;
                
            }
            else{
                monthdate2 = other.getMonth();
                monthdiff = monthdate2 - monthdate1;
                yeardate2 = other.getYear();
            }
            
            yeardiff = yeardate2-getYear();
            diff.setDays( daydiff );
            diff.setMonths(monthdiff);
            diff.setYears(yeardiff);
            
        }else{
            if(getDay()<other.getDay()){
                bigday = getDay()+ month[other.getMonth()];
                if( other.getMonth() ==2 && other.checkleap())
                    bigday +=1;
                daydiff = bigday-other.getDay();
                monthdate2 = other.getMonth()+1;
            }
            else{
                daydiff = getDay() -other.getDay();
                monthdate2 = other.getMonth();
            }
            
            if(getMonth()< monthdate2){
                monthdate1 = 12 + getMonth();
                monthdiff = monthdate1 - monthdate2;
                yeardate1 = getYear() - 1;
            }
            else{
                monthdate1 = getMonth();
                monthdiff = monthdate1 - monthdate2;
                yeardate1 = getYear();
            }
            yeardiff = yeardate1-yeardate2;
            diff.setDays( -daydiff );
            diff.setMonths(-monthdiff);
            diff.setYears(-yeardiff);
            
        }
        
        return diff;
    }
    
    void SFDate::monthforward(){  //used for adjusting subtracting/adding month
        while(1){
        if(SFmonth==2 && checkleap() && SFmonth==30){   //deal with leap year(2.30, 2.31) normal year(2.29,2.30,2.31)
            SFmonth = 3;
            SFday = 1;
            break;
        }
        if(SFmonth==2 && checkleap() && SFmonth==31){
            SFmonth =3;
            SFday = 2;
            break;
        }
        if(SFmonth==2 && !checkleap() && SFmonth==29){
            SFmonth = 3;
            SFday = 1;
            break;
        }
        if(SFmonth==2 && !checkleap() && SFmonth==30){
            SFmonth =3;
            SFday = 2;
            break;
        }
        if(SFmonth==2 && !checkleap() && SFmonth==31){
            SFmonth =3;
            SFday = 3;
            break;
        }
        if(SFmonth==4 && SFday ==31){
            SFmonth = 5;
            SFday = 1;
            break;
        }
        if(SFmonth==6 && SFday ==31){
            SFmonth = 7;
            SFday = 1;
            break;
        }
        if(SFmonth==9 && SFday ==31){
            SFmonth = 10;
            SFday = 1;
            break;
        }
        if(SFmonth==11 && SFday ==31){
            SFmonth = 12;
            SFday = 1;
            break;
        }
            
            break;
        }
        
    }
    
    
    
    
    SFDate& SFDate::adjustByDays(int n){   //-- to add or subtract N days from the given date
        int passday = offsetday();
        int remainday = 0;
        int newoffset = 0;
        int dayinyear = 0;
        if(n>=0){
            remainday = checkleap()?(366-passday):(365-passday);
            newoffset = 0;
            if(n<=remainday){
                newoffset = passday+n;
            }
            else{
                n -= remainday;
                SFyear +=1;
                dayinyear = checkleap()?366:365;
                while(n>=dayinyear){
                    n -= dayinyear;
                    SFyear+=1;
                    dayinyear = checkleap()?366:365;
                }
                newoffset = n;
            }
            int month[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
            checkleap()? month[2]=29:month[2]=28;
            for(int count = 1;count<=12;count++){
                if(newoffset<=month[count]){
                    SFmonth = count;
                    break;
                }
                newoffset = newoffset - month[count];
            }
            SFday = newoffset;
        }
        else{
            remainday = passday;
            int absn = abs(n);
            if(absn<remainday){
                newoffset = passday+n;
            }
            else{
                absn -= remainday;
                SFyear -=1;
                dayinyear = checkleap()?366:365;
                while(absn>=dayinyear){
                    absn -= dayinyear;
                    SFyear -=1;
                    dayinyear = checkleap()?366:365;
                }
                newoffset = checkleap()?366-absn:365-absn;
                
            }
            int month[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
            checkleap()? month[2]=29:month[2]=28;
            int count = 0;
            for(count = 1;count<=12;count++){
                if(newoffset<=month[count]){
                    break;
                }
                newoffset = newoffset - month[count];
            }
            SFday = newoffset;
            SFmonth = count;
        }
         return *this;
    }
    
    SFDate& SFDate::adjustByWeeks(int n){         //-- to add or subtract N weeks from the given date
        adjustByDays(7*n);
        return *this;
    }
    
    SFDate& SFDate::adjustByMonths(int n){       //-- to add or subtract N months from the given date
        if(n+SFmonth>=1){
           SFyear = SFyear+(SFmonth+n-1)/12;
           (SFmonth+n)%12==0? SFmonth=12: SFmonth =(SFmonth+n)%12;
        }
        else{
            SFyear = SFyear + (SFmonth+n+1)/12 -1;
            SFmonth = 12 +(SFmonth+n)%12;
        }
        monthforward();
        return *this;
    }
    
    SFDate& SFDate::adjustByYears(int n){       //-- to add or subtract N years from the given date
        SFyear = SFyear + n;
        monthforward();
        return *this;
    }
    
    SFDate& SFDate::setDay(int aDay){
        if(aDay<=0 || aDay>31){
            std::cerr<<"Invalid days in setDay"<<std::endl;
        }
        SFday = aDay;
        monthforward();
        return *this;
    }
    
    SFDate& SFDate::setMonth(int aMonth){
        if(aMonth<=0 || aMonth>12){
            std::cerr<<"Invalid month in setMonth"<<std::endl;
        }
        SFmonth = aMonth;
        monthforward();
        return *this;
    }
    
    SFDate& SFDate::setYear(int Year){
        if(Year<=0){
            std::cerr<<"Invalid year in setYear"<<std::endl;
        }
        SFyear = Year;
        monthforward();
        return *this;
    }
    
    int SFDate::getDay() const{
        return SFday;
    }
    
    int SFDate::getMonth() const{
        return SFmonth;
    }
    
    int SFDate::getYear() const{
        return SFyear;
    }
    
    int SFDate::getWeekOfYear() const{
        SFDate extra(*this);
        extra.startOfYear();
        int daysofyear = offsetday();
        int weeknum = 0;
        int dayofweek = (*this).getDayOfweek();
        
        int firstdayofyear =extra.getDayOfweek();
        weeknum = (daysofyear+6)/7;
        if(dayofweek<firstdayofyear){
            weeknum++;
        }
        return weeknum;
    }
    
    int SFDate::getDayOfYear() const{
        return offsetday();
    }
    
    int SFDate::getDayOfweek() const{
        int week = -1;
        int month =SFmonth;
        int year = SFyear;
        int day = SFday;
        if(month==1||month==2){
            month +=12;
            year -=1;
        }
        week = (day+ 1 + 2*month + 3*(month+1)/5 + year + year/4 - year/100 + year/400 )%7;
        return week;
    }
    
    int SFDate::daysInMonth() const{
        int month[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        checkleap()? month[2]=29:month[2]=28;
        return month[SFmonth];
    }
    
    SFDate& SFDate::startOfMonth(){
        SFday = 1;
        return *this;
    }
    
    SFDate& SFDate::endOfMonth(){
        if(SFmonth==4 || SFmonth ==6 || SFmonth ==9 || SFmonth==11)
            SFday= 30;
        else if (SFmonth ==2 && checkleap())
            SFday = 29;
        else if (SFmonth ==2 && !checkleap())
            SFday = 28;
        else
            SFday = 31;
        return *this;
    }
    
    SFDate& SFDate::startOfYear(){
        SFmonth = 1;
        SFday = 1;
        return *this;
    }
    
    SFDate& SFDate::endOfYear(){
        SFmonth = 12;
        SFday = 31;
        return *this;
    }
    
    std::string SFDate::toDateString(){
        std::string dstring;
        std::string year = std::to_string(SFyear);
        std::string month = std::to_string(SFmonth);
        std::string day = std::to_string(SFday);
        dstring = std::string(2 - month.length(),'0')+month+"/"+std::string(2-day.length(),'0')+day+"/"+std::string(4-year.length(),'0')+year;
        return dstring;
    }
    
    bool SFDate::operator>(const SFDate &aSFDate) const{
        if(SFyear>aSFDate.SFyear){
            return true;
        }
        else if(SFyear==aSFDate.SFyear && SFmonth>aSFDate.SFmonth){
            return true;
        }
        else if(SFyear==aSFDate.SFyear && SFmonth==aSFDate.SFmonth && SFday>aSFDate.SFday){
            return true;
        }
        else
            return false;
    }
    
    bool SFDate::operator<(const SFDate &aSFDate) const{
        return !operator>(aSFDate) && !operator==(aSFDate);
    }
    bool SFDate::operator<=(const SFDate &aSFDate) const{
        return !operator>(aSFDate);
    }
    bool SFDate::operator>=(const SFDate &aSFDate) const{
        return !operator<(aSFDate);
    }
    bool SFDate::operator!=(const SFDate &aSFDate) const{
        return !operator==(aSFDate);
    }
    bool SFDate::operator==(const SFDate &aSFDate) const{
        if(SFyear==aSFDate.SFyear && SFmonth==aSFDate.SFmonth && SFday==aSFDate.SFday)
            return true;
        else
            return false;
    }
    
}
