//
//  SFTimezone.cpp
//  my_assignment3
//
//  Created by Jing Liang on 2/19/18.
//  Copyright © 2018 Jing Liang. All rights reserved.
//

#include "SFTimezone.hpp"
#include <string>
#include <iostream>
namespace SoftwareFoundations{
    SFTimezone::SFTimezone(){        //default constructor: nullptr   tell me how to assign a string to
         std::string zone = "GMT";
         SFtimezone = new char[zone.size()+1];
         std::copy(zone.begin(),zone.end(),SFtimezone);
         SFtimezone[zone.size()] = '\0';
    }
    
    SFTimezone::~SFTimezone(){
        if(SFtimezone!=nullptr)
            delete[] SFtimezone;
        SFtimezone = nullptr;
        
    }
    
    SFTimezone::SFTimezone(const char* aTimezoneAbbrev){      // tell me how to assign a char* to a char*
        if(aTimezoneAbbrev==nullptr){
            std::string zone = "GMT";
            SFtimezone = new char[zone.size()+1];
            std::copy(zone.begin(),zone.end(),SFtimezone);
            SFtimezone[zone.size()] = '\0';
        }
        else{
        size_t zonelen = strlen(aTimezoneAbbrev);
        SFtimezone = new char[zonelen+1];
        strcpy(SFtimezone,aTimezoneAbbrev);
        }
    } //GMT, EST, CST, PST
    
    SFTimezone::SFTimezone(const SFTimezone &aTimezone){
        if(aTimezone.SFtimezone!=nullptr){
            SFtimezone = new char[strlen(aTimezone.SFtimezone)+1];
            strcpy(SFtimezone,aTimezone.SFtimezone);
        }
        else{
            std::string zone = "GMT";
            SFtimezone = new char[zone.size()+1];
            std::copy(zone.begin(),zone.end(),SFtimezone);
            SFtimezone[zone.size()] = '\0';
        }
    }
    
    SFTimezone::operator const char*(){
        return SFtimezone;
    } // Returns the 3 letter abbreviation of the timezone object
    
    SFTimezone& SFTimezone::SFTZsetTimezone(const char* aTimezone){
        if(SFtimezone!=nullptr){
            delete[] SFtimezone;
            SFtimezone = nullptr;
        }
        if(aTimezone!=nullptr){
            SFtimezone = new char[strlen(aTimezone)+1];
            strcpy(SFtimezone,aTimezone);
        }
        else{
            std::string zone = "GMT";
            SFtimezone = new char[zone.size()+1];
            std::copy(zone.begin(),zone.end(),SFtimezone);
            SFtimezone[zone.size()] = '\0';
        }
        return *this;
    }
    
    char* SFTimezone::SFTZgetTimezone() const{
        return SFtimezone;
    }
    
}
