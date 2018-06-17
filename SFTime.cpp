//
//  SFTime.cpp
//  my_assignment3
//
//  Created by Jing Liang on 2/19/18.
//  Copyright © 2018 Jing Liang. All rights reserved.
//
#include "SFTime.hpp"
#include <string>
#include <ctime>
#include <iostream>
#include <stdlib.h>
#include "SFDateTime.hpp"
namespace SoftwareFoundations{
    SFTime::SFTime(){//default to now(HH:MM:SS)
        time_t now=time(0);
        tm *ltm = localtime(&now);
        SFhour = ltm->tm_hour;
        SFmin = 1+ltm->tm_min;
        SFsec = ltm->tm_sec;
        dayadjustM = 0;
    }
    SFTime::SFTime(const char *aTimeString){    //must parse the given string of the form "HH:MM:SS"
        dayadjustM = 0;
        if(aTimeString!=nullptr){
            std::string aString(aTimeString);
            auto pos = aString.find(":");
            std::string hour = aString.substr(0,pos);
            aString = aString.erase(0,pos+1);
            pos = aString.find(":");
            std::string min = aString.substr(0,pos);
            aString = aString.erase(0,pos+1);
            std::string sec = aString;
            SFhour = std::stoi(hour);
            SFmin = std::stoi(min);
            SFsec = std::stoi(sec);
            if( !timevalid() ){
                std::cerr<<"Invalid time !"<<std::endl;
            }
        }
        else{
            SFTime();
        }
    }
    
    bool SFTime::timevalid(int thehour,int themin, int thesec) const{
        if(thehour>=0 && thehour<=23 && themin>=0 && themin<=59 && thesec>=0 && thesec<=59)
            return true;
        else
            return false;
    }
    bool SFTime::timevalid() const{
        if(SFhour>=0 && SFhour<=23 && SFmin>=0 && SFmin<=59 && SFsec>=0 && SFsec<=59)
            return true;
        else
            return false;
    }
    
    
    SFTime::SFTime(int anHour, int aMinutes, int aSeconds){  //build time from individual parts
        bool istimevalid = timevalid(anHour,aMinutes,aSeconds);
        if(!istimevalid){
            std::cerr<<"The time is not valid!"<<std::endl;
        }
        SFhour = anHour;
        SFmin = aMinutes;
        SFsec = aSeconds;
        dayadjustM = 0;
    }
    
    SFTime::SFTime(const SFTime &aCopy){    // SFTime(const SFDateTime &aCopy);
        SFhour = aCopy.SFhour;
        SFmin = aCopy.SFmin;
        SFsec = aCopy.SFsec;
        dayadjustM = aCopy.dayadjustM;
    }
    
    SFTime::SFTime(const SFDateTime &aCopy){
        SFhour = aCopy.getHour();
        SFmin = aCopy.getMinutes();
        SFsec = aCopy.getSeconds();
    }
    
    
    SFTime& SFTime::adjustByMinutes(int n) { //-- to +/- N minutes from the given time
        dayadjustM = 0;
        int remainmin = 0;
        int minoffset = SFhour*60+SFmin;
        int minaday = 24*60;
        if(n>=0){
            remainmin = 60-SFmin+(23-SFhour)*60;
            if(n<=remainmin){
                minoffset += n;
            }else{
                n -= remainmin;
                dayadjustM +=1;
                while(n>=minaday){
                    n -=minaday;
                    dayadjustM +=1;
                }
                minoffset = n;
            }
        }else{
            remainmin = minoffset;
            int absn = abs(n);
            if(absn<=remainmin){
                minoffset -= absn;
            }else{
                absn -= remainmin;
                dayadjustM -=1;
                while(absn>=minaday){
                    absn -=minaday;
                    dayadjustM -=1;
                }
                minoffset = 60-absn;
            }
        }
        for (int count=0;count<24;count++){
            if(minoffset<60){
                SFhour = count;
                SFmin = minoffset;
                break;
            }
            minoffset = minoffset -60;
        }
        return *this;
    }
    SFTime& SFTime::adjustByHours(int n) {//-- to +/- N hours from the given time. 11:15 + 2hours is 13:15 (rolls over)
        adjustByMinutes(60*n);
        return *this;
    }
    
    SFInterval SFTime::operator-(const SFTime &other) const {  //determine interval between two times...
        SFInterval timediff;
        int time2hour = 0;
        int time2min = 0;
        int time2sec = 0;
        int secdiff = 0;
        int mindiff = 0;
        int hourdiff = 0;
        if( (*this).operator<(other)){
            if(getSeconds()>other.getSeconds()){
                time2sec = other.getSeconds()+60;
                time2min = other.getMinutes() -1;
                secdiff = time2sec - getSeconds();
                
            }else{
                secdiff = other.getSeconds() - getSeconds();
                time2min = other.getMinutes();
            }
            if(getMinutes()>time2min){
                mindiff = time2min+60-getMinutes();
                time2hour = other.getHour()-1;
            }else{
                mindiff = time2min - getMinutes();
                time2hour = other.getHour();
            }
            hourdiff = time2hour - getHour();
            timediff.setSeconds(secdiff);
            timediff.setMinutes(mindiff);
            timediff.setHours(hourdiff);
        }
        else{
            time2hour = other.getHour()+24;
            if(getSeconds()>other.getSeconds()){
                time2sec = other.getSeconds()+60;
                time2min = other.getMinutes() -1;
                secdiff = time2sec - getSeconds();
                
            }else{
                secdiff = other.getSeconds() - getSeconds();
                time2min = other.getMinutes();
            }
            if(getMinutes()>time2min){
                mindiff = time2min+60-getMinutes();
                time2hour -=time2hour-1;
            }else{
                mindiff = time2min - getMinutes();
            }
            hourdiff = time2hour - getHour();
            timediff.setSeconds(secdiff);
            timediff.setMinutes(mindiff);
            timediff.setHours(hourdiff);
            //timediff.adjustDay(-1);
        }
        
        return timediff;
    }
    
    
    SFInterval SFTime::operator-(const SFDateTime &aother) const{
        SFTime other(aother.getHour(),aother.getMinutes(),aother.getSeconds());
        SFInterval timediff;
        int time2hour = 0;
        int time2min = 0;
        int time2sec = 0;
        int secdiff = 0;
        int mindiff = 0;
        int hourdiff = 0;
        if( (*this).operator<(other)){
            if(getSeconds()>other.getSeconds()){
                time2sec = other.getSeconds()+60;
                time2min = other.getMinutes() -1;
                secdiff = time2sec - getSeconds();
                
            }else{
                secdiff = other.getSeconds() - getSeconds();
                time2min = other.getMinutes();
            }
            if(getMinutes()>time2min){
                mindiff = time2min+60-getMinutes();
                time2hour = other.getHour()-1;
            }else{
                mindiff = time2min - getMinutes();
                time2hour = other.getHour();
            }
            hourdiff = time2hour - getHour();
            timediff.setSeconds(secdiff);
            timediff.setMinutes(mindiff);
            timediff.setHours(hourdiff);
        }
        else{
            time2hour = other.getHour()+24;
            if(getSeconds()>other.getSeconds()){
                time2sec = other.getSeconds()+60;
                time2min = other.getMinutes() -1;
                secdiff = time2sec - getSeconds();
                
            }else{
                secdiff = other.getSeconds() - getSeconds();
                time2min = other.getMinutes();
            }
            if(getMinutes()>time2min){
                mindiff = time2min+60-getMinutes();
                time2hour -=time2hour-1;
            }else{
                mindiff = time2min - getMinutes();
            }
            hourdiff = time2hour - getHour();
            timediff.setSeconds(secdiff);
            timediff.setMinutes(mindiff);
            timediff.setHours(hourdiff);
            
            
            timediff.adjustDay(-1);
        }
        
        return timediff;
    } //determine interval between two objects...
    
    int SFTime::getHour() const{
        return SFhour;
    }
    int SFTime::getMinutes() const{
        return SFmin;
    }
    int SFTime::getSeconds() const{
        return SFsec;
    }
    int SFTime::getDayAdjust() const{
        return dayadjustM;
    }
    
    SFTime& SFTime::setHour(int ahour){
        SFhour = ahour;
        return *this;
    }
    SFTime& SFTime::setMinute(int amin){
        SFmin = amin;
        return *this;
    }
    SFTime& SFTime::setSecond(int asec){
        SFsec = asec;
        return *this;
    }
    
    
    
    SFTime& SFTime::startOfDay(){  //change time to (00:00:00)
        SFhour = 0;
        SFmin = 0;
        SFsec = 0;
        return *this;
    }
    SFTime& SFTime::endOfDay(){  // change time to (23:59:59)
        SFhour = 23;
        SFmin = 59;
        SFsec = 59;
        return *this;
    }
    
    std::string SFTime::toTimeString(){  //Returns string of the form HH:MM:SS
        std::string tstring;
        std::string hour = std::to_string(SFhour);
        std::string min = std::to_string(SFmin);
        std::string sec = std::to_string(SFsec);
        tstring = std::string(2-hour.length(),'0')+hour+":"+std::string(2-min.length(),'0')+min+":"+std::string(2-sec.length(),'0')+sec;
        return tstring;
    }
    
    //ADD RELATIONAL OPERATORS HERE... >, <, <=, >=, !=, ==
    bool SFTime::operator>(const SFTime &aSFTime) const{
        if(SFhour>aSFTime.SFhour){
            return true;
        }
        else if(SFhour==aSFTime.SFhour && SFmin>aSFTime.SFmin){
            return true;
        }
        else if(SFhour==aSFTime.SFhour && SFmin==aSFTime.SFmin && SFsec>aSFTime.SFsec){
            return true;
        }
        else
            return false;
    }
    bool SFTime::operator<(const SFTime &aSFTime) const{
        return !operator>(aSFTime) && !operator==(aSFTime);
    }
    bool SFTime::operator>=(const SFTime &aSFTime) const{
        return !operator<(aSFTime);
    }
    bool SFTime::operator<=(const SFTime &aSFTime) const{
        return !operator>(aSFTime);
    }
    bool SFTime::operator==(const SFTime &aSFTime) const{
        if(SFhour==aSFTime.SFhour && SFmin==aSFTime.SFmin && SFsec==aSFTime.SFsec)
            return true;
        else
            return false;
    }
    bool SFTime::operator!=(const SFTime &aSFTime) const{
        return !operator==(aSFTime);
    }
}
