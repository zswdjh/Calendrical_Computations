//
//  SFDateTime.cpp
//  my_assignment3
//
//  Created by Jing Liang on 2/19/18.
//  Copyright © 2018 Jing Liang. All rights reserved.
//

#include "SFDateTime.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include <map>
namespace SoftwareFoundations{
    SFDateTime::SFDateTime(SFTimezone *aTimezone):SFTime(),SFDate(){  //init a new datetime based on GMT, unless a valid timezone is provided
        const char* GMT = "GMT";
        SFTimezone gmt(GMT);
        std::map<std::string,int> tzmap = { {"GMT",0},{"PST",-8},{"CST",-6},{"EST",-5} };
        int timeadjust = 0;
        if(aTimezone==nullptr){
            SFDTzone.SFTZsetTimezone(GMT);
        }
        else{
            timeadjust = tzmap.find("GMT")->second - tzmap.find(aTimezone->SFTZgetTimezone())->second;
            adjustByHours(timeadjust);
            SFDTzone.SFTZsetTimezone(GMT);
            setTimezone(*aTimezone);
        }
    }
    
    SFDateTime::SFDateTime(const SFDateTime &aCopy):SFTime(aCopy),SFDate(aCopy){
        SFDTzone = aCopy.SFDTzone;
    } //copy construct
    
    
    
    SFDateTime::SFDateTime(int aMonth, int aDay, int aYear, int anHour, int aMinutes, int aSeconds, SFTimezone *aTimezone){
        setDay(aDay);
        setMonth(aMonth);
        setYear(aYear);
        setSecond(aSeconds);
        setMinute(aMinutes);
        setHour(anHour);
        std::map<std::string,int> tzmap = { {"GMT",0},{"PST",-8},{"CST",-6},{"EST",-5} };
        const char* GMT = "GMT";
        SFTimezone gmt(GMT);
        if(aTimezone==nullptr){
            setTimezone(gmt);
        }
        else{
            std::string current = aTimezone->SFTZgetTimezone(); //current timezone
            int timeadjust = 0; //first to adjust to GMT time zone
            timeadjust = tzmap.find("GMT")->second - tzmap.find(current)->second;
            adjustByHours(timeadjust);
            SFDTzone.SFTZsetTimezone(GMT);
            setTimezone(*aTimezone);
        }
        
    }
    
    SFDateTime::SFDateTime(const char* aString, SFTimezone *aTimezone){   //parse the given string of the form "MM/DD/YYYY HH:MM:SS"
        if(isdigit(aString[0])){
            std::stringstream fullstring(aString);     //separate MM/DD/YYYY and HH:MM:SS
            std::string date;
            std::string time;
            fullstring>>date>>time;
            auto pos1 = date.find("/");
            std::string month = date.substr(0,pos1);
            date = date.erase(0,pos1+1);
            pos1 = date.find("/");
            std::string day = date.substr(0,pos1);
            date = date.erase(0,pos1+1);
            std::string year = date;
            
            auto pos2 = time.find(":");
            std::string hour = time.substr(0,pos2);
            time = time.erase(0,pos2+1);
            pos2 = time.find(":");
            std::string minute = time.substr(0,pos2);
            time = time.erase(0,pos2+1);
            std::string second = time;
            
            (*this).setDay(std::stoi(day));
            (*this).setMonth(std::stoi(month));
            (*this).setYear(std::stoi(year));
            (*this).setSecond(std::stoi(second));
            (*this).setMinute(std::stoi(minute));
            (*this).setHour(std::stoi(hour));
        }
        if(isalpha(aString[0])){   //seperate "Jan 1,1961 12:24:25"
            std::map<std::string,int>monthname = { {"Jan",1},{"Feb",2},{"Mar",3},{"Apr",4},{"May",5},{"Jun",6},{"Jul",7},{"Aug",8},{"Sep",9},{"Sept",9},{"Oct",10},{"Nov",11},{"Dec",12},{"January",1},{"February",2},{"March",3},{"April",4},{"June",6},{"July",7},{"August",8},{"September",9},{"October",10},{"November",11},{"December",12}};
            std::stringstream fullstring(aString);
            std::string month;
            std::string day;
            std::string year;
            std::string dayplusyear;
            std::string time;
            fullstring>>month>>dayplusyear>>time;
            setMonth(monthname.find(month)->second);
            auto pos = dayplusyear.find(",");
            day = dayplusyear.substr(0,pos);
            setDay(std::stoi(day));
            dayplusyear = dayplusyear.erase(0,pos+1);
            setYear(std::stoi(dayplusyear));
            auto pos1 = time.find(":");
            std::string hour = time.substr(0,pos1);
            time = time.erase(0,pos1+1);
            pos1 = time.find(":");
            std::string min = time.substr(0,pos1);
            time = time.erase(0,pos1+1);
            std::string sec = time;
            setHour(std::stoi(hour));
            setMinute(std::stoi(min));
            setSecond(std::stoi(sec));
            
        }
        
        
        
        
        const char* GMT = "GMT";
        SFTimezone gmt(GMT);
        std::map<std::string,int> tzmap = { {"GMT",0},{"PST",-8},{"CST",-6},{"EST",-5} };
        int timeadjust = 0;
        if(aTimezone==nullptr){
            SFDTzone.SFTZsetTimezone(GMT);
        }
        else{
            timeadjust = tzmap.find("GMT")->second - tzmap.find(aTimezone->SFTZgetTimezone())->second;
            adjustByHours(timeadjust);
           // SFDTzone.SFTZsetTimezone(GMT);
            setTimezone(*aTimezone);
        }
        
        
    }
    
    SFDateTime::SFDateTime(const SFDate &aDate, const SFTime &aTime, SFTimezone *aTimezone):SFTime(aTime),SFDate(aDate){
        const char* GMT = "GMT";
        SFTimezone gmt(GMT);
        std::map<std::string,int> tzmap = { {"GMT",0},{"PST",-8},{"CST",-6},{"EST",-5} };
        int timeadjust = 0;
        
        if(aTimezone==nullptr){
            const char* GMT = "GMT";
            SFTimezone gmt(GMT);
            setTimezone(gmt);
        }
        else{
            timeadjust = tzmap.find("GMT")->second - tzmap.find(aTimezone->SFTZgetTimezone())->second;
            adjustByHours(timeadjust);
            // SFDTzone.SFTZsetTimezone(GMT);
            setTimezone(*aTimezone);
        }
    }
    
 
    
    SFInterval SFDateTime::operator-(const SFDateTime &aother){  //determine interval between two objects...
        SFTimezone thistz = getTimezone();
        SFTimezone aothertz = aother.getTimezone();
        SFDateTime other(aother.getMonth(),aother.getDay(),aother.getYear(),aother.getHour(),aother.getMinutes(),aother.getSeconds(),&aothertz);
        SFInterval timedatediff;

            if((*this).operator<(other)==true){
                other.setTimezone(thistz);
                (*this).SFTime::operator-(other);
                timedatediff.setSeconds((*this).SFTime::operator-(other).SFIgetSeconds());
                timedatediff.setMinutes((*this).SFTime::operator-(other).SFIgetMinutes());
                timedatediff.setHours((*this).SFTime::operator-(other).SFIgetHours());
                adjustByDays(getDayAdjust());
                (*this).SFDate::operator-(other);
                timedatediff.setDays((*this).SFTime::operator-(other).SFIgetDays());
                timedatediff.setMonths((*this).SFTime::operator-(other).SFIgetMonths());
                timedatediff.setYears((*this).SFTime::operator-(other).SFIgetYears());
            }
            else{
                (*this).setTimezone(aothertz);
                (other).SFTime::operator-((*this));
                timedatediff.setSeconds(other.SFTime::operator-((*this)).SFIgetSeconds());
                timedatediff.setMinutes(other.SFTime::operator-((*this)).SFIgetMinutes());
                timedatediff.setHours(other.SFTime::operator-((*this)).SFIgetHours());
                other.adjustByDays(other.getDayAdjust());
                other.SFDate::operator-((*this));
                timedatediff.setDays(other.SFTime::operator-((*this)).SFIgetDays());
                timedatediff.setMonths(other.SFTime::operator-((*this)).SFIgetMonths());
                timedatediff.setYears(other.SFTime::operator-((*this)).SFIgetYears());
            }
        
        
        return timedatediff;
        
        /*
        SFDateTime newadate(aother);
        SFTime newtime(newadate.getHour(),newadate.getMinutes(),newadate.getSeconds());
        SFDate newdate(newadate.getMonth(),newadate.getDay(),newadate.getYear());
        SFInterval finaldiff;
        
       
        int time2hour = 0;
        int time2min = 0;
        int time2sec = 0;
        int secdiff = 0;
        int mindiff = 0;
        int hourdiff = 0;
        if( (*this).SFTime::operator<(newtime)){
            if(getSeconds()>newtime.getSeconds()){
                time2sec = newtime.getSeconds()+60;
                time2min = newtime.getMinutes() -1;
                secdiff = time2sec - getSeconds();
                
            }else{
                secdiff = newtime.getSeconds() - getSeconds();
                time2min = newtime.getMinutes();
            }
            if(getMinutes()>time2min){
                mindiff = time2min+60-getMinutes();
                time2hour = newtime.getHour()-1;
            }else{
                mindiff = time2min - getMinutes();
                time2hour = newtime.getHour();
            }
            hourdiff = time2hour - getHour();
            finaldiff.setSeconds(secdiff);
            finaldiff.setMinutes(mindiff);
            finaldiff.setHours(hourdiff);
        }
        else{
            time2hour = newtime.getHour()+24;
            newdate.adjustByDays(-1);
            if(getSeconds()>newtime.getSeconds()){
                time2sec = newtime.getSeconds()+60;
                time2min = newtime.getMinutes() -1;
                secdiff = time2sec - getSeconds();
                
            }else{
                secdiff = newtime.getSeconds() - getSeconds();
                time2min = newtime.getMinutes();
            }
            if(getMinutes()>time2min){
                mindiff = time2min+60-getMinutes();
                time2hour -=time2hour-1;
            }else{
                mindiff = time2min - getMinutes();
            }
            hourdiff = time2hour - getHour();
            finaldiff.setSeconds(secdiff);
            finaldiff.setMinutes(mindiff);
            finaldiff.setHours(hourdiff);
        }
        
        
        
        //adjust the day
        int month[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        int bigday = 0;
        int daydiff = 0;
        int monthdate1 = 0;
        int monthdiff = 0;
        int monthdate2 = 0;
        int yeardate1 = 0;
        int yeardate2 = 0;
        int yeardiff = 0;
        if( (*this).SFDate::operator<(newdate)){   //first variable is smaller than second, in the future
            if(newdate.getDay()<getDay()){
                bigday = newdate.getDay()+ month[getMonth()];
                if( getMonth() ==2 && checkleap())
                    bigday +=1;
                daydiff = bigday-getDay();
                monthdate1 = getMonth()+1;
            }
            else{
                daydiff = newdate.getDay() -getDay();
                monthdate1 = getMonth();
            }
            
            if(newdate.getMonth()< monthdate1){
                monthdate2 = 12 + newdate.getMonth();
                monthdiff = monthdate2 - monthdate1;
                yeardate2 = newdate.getYear() - 1;
                
            }
            else{
                monthdate2 = newdate.getMonth();
                monthdiff = monthdate2 - monthdate1;
                yeardate2 = newdate.getYear();
            }
            
            yeardiff = yeardate2-getYear();
            finaldiff.setDays( daydiff );
            finaldiff.setMonths(monthdiff);
            finaldiff.setYears(yeardiff);
            
        }else{
            if(getDay()<newdate.getDay()){
                bigday = getDay()+ month[newdate.getMonth()];
                if( newdate.getMonth() ==2 && newdate.checkleap())
                    bigday +=1;
                daydiff = bigday-newdate.getDay();
                monthdate2 = newdate.getMonth()+1;
            }
            else{
                daydiff = getDay() -newdate.getDay();
                monthdate2 = newdate.getMonth();
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
            finaldiff.setDays( -daydiff );
            finaldiff.setMonths(-monthdiff);
            finaldiff.setYears(-yeardiff);
            
        }
        
        return finaldiff;
         */
    }
    
    SFTimezone SFDateTime::getTimezone() const {    //retrieve timezone currently associated with this object
        return SFDTzone;
    }
    
    
    SFDateTime&  SFDateTime::setTimezone(SFTimezone &aTimezone){  //change timezone, also need to change time.
        SFTimezone oldtz = getTimezone();
        SFTimezone newtz = aTimezone;
        std::string oldtimezone(oldtz);
        std::string newtimezone(newtz);
        std::map<std::string,int> tzmap = { {"GMT",0},{"PST",-8},{"CST",-6},{"EST",-5} };
        int timeadjust = 0;
        timeadjust = tzmap.find(newtimezone)->second - tzmap.find(oldtimezone)->second;
        adjustByHours(timeadjust);  // no change
        SFDTzone.SFTZsetTimezone(newtimezone.c_str());
        return *this;
    }
    
    //ADD RELATIONAL OPERATORS HERE... >, <, <=, >=, !=, ==
    bool SFDateTime::operator>(const SFDateTime &adatetime) {
        bool result = false;
        SFTimezone returntz = adatetime.getTimezone();
        SFDateTime newadate(adatetime.getMonth(), adatetime.getDay(), adatetime.getYear(), adatetime.getHour(), adatetime.getMinutes(), adatetime.getSeconds(),&returntz);
        std::map<std::string,int> tzmap = { {"GMT",0},{"PST",-8},{"CST",-6},{"EST",-5} };
        SFTimezone oldtz = getTimezone();
        newadate.setTimezone(oldtz);
        
        if( (*this).SFDate::operator>(newadate) ){
            result = true;
        }
        else if( (*this).SFDate::operator==(newadate) && (*this).SFTime::operator>(newadate)){
            result = true;
        }
        else{
            result = false;
        }
        return result;
    }
    
    bool SFDateTime::operator<(const SFDateTime &adatetime) {
        return (!operator>(adatetime) && !operator==(adatetime));
    }
    bool SFDateTime::operator>=(const SFDateTime &adatetime){
        return !operator<(adatetime);
    }
    bool SFDateTime::operator<=(const SFDateTime &adatetime) {
        return !operator>(adatetime);
    }
    bool SFDateTime::operator==(const SFDateTime &adatetime) {
        bool result = false;
        SFTimezone returntz = adatetime.getTimezone();
        SFDateTime newadate(adatetime.getMonth(), adatetime.getDay(), adatetime.getYear(), adatetime.getHour(), adatetime.getMinutes(), adatetime.getSeconds(),&returntz);
        std::map<std::string,int> tzmap = { {"GMT",0},{"PST",-8},{"CST",-6},{"EST",-5} };
        SFTimezone oldtz = getTimezone();
        newadate.setTimezone(oldtz);
        
        if( (*this).SFDate::operator==(newadate) && (*this).SFTime::operator==(newadate)){
            result = true;
        }
        else{
            result = false;
        }
        return result;
    }
    
    bool SFDateTime::operator!=(const SFDateTime &adatetime){
        return !operator==(adatetime);
    }
    
    SFDateTime::operator const char*(){
        std::string str = toDateTimeString();
        const char* c = str.c_str();
        return c;
    }  //Returns string of the form "MON DATE, YEAR HH:MM:SS TIMEZONE" Ex. Jan 4, 1961 09:15:00 PST
    
    SFDateTime::operator SFDate() {
        return *this;
    }
    SFDateTime::operator SFTime() {
        return *this;
    }
    SFDateTime::operator SFTimezone(){
        return SFDTzone;
    }
    
    std::string SFDateTime::toDateTimeString(){
        std::string outputstr;
        std::map<int,std::string> month = { {1,"Jan"},{2,"Feb"},{3,"Mar"},{4,"Apr"},{5,"May"},{6,"Jun"},{7,"July"},{8,"Aug"},{9,"Sep"},{10,"Oct"},{11,"Nov"},{12,"Dec"} };
        outputstr = month.find(getMonth())->second + " " +std::to_string(getDay()) + ", "+std::to_string(getYear())+" "+ SFTime::toTimeString()+" "+ std::string(SFDTzone);
        return outputstr;
    }  //Jan 4, 1961 09:15:00 PST (always this format)
    
    
}
