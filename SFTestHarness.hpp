//
//  SFTestHarness.hpp
//  ECE180-Assignment3
//
//  Created by rick gessner on 2/12/18.
//  Copyright © 2018 rick gessner. All rights reserved.
//

#ifndef SFTestHarness_hpp
#define SFTestHarness_hpp
#include <string>
#include "SFDate.hpp"
#include "SFTime.hpp"
#include "SFDateTime.hpp"
#include "SFInterval.hpp"
#include "SFTimezone.hpp"
namespace SoftwareFoundations {
  
  class SFTestHarness {
  public:
    static int runAllTests();
    static int runDateTests();
    static int runTimeTests();
    static int runDateTimeTests();
    static int runIntervalTests();
    static int runTimezoneTests();
      //class SFdate test
    static std::string dateDifferenceTest(std::string aDate1, std::string aDate2);  //n
    static std::string adjustDateByWeeksTest(std::string aDate, int aWeeks);  //n
    static std::string setMonthDateTest(std::string aDate, int aMonth); //n
    static int getDayOfWeekDateTest(std::string aDate);  //n
    static std::string endOfMonthDateTest(std::string aDate);  //n
    
      //class SFTime test
      static std::string timeDifferenceTest(std::string aTime1, std::string aTime2);  //n
      static std::string adjustTimeByMinutesTest(std::string aTime1, int aMinutes);  //n
      static int getMinutesTimeTest(std::string aTime);  //n
      
      //class SFDateTime test
    static std::string dataTimeDifferenceTest(std::string aDateTime1, std::string aTimezone1, std::string aDateTime2, std::string aTimezone2);//n
    static std::string dataTimeToStringTest(std::string aDateTime, std::string timezone);//n
    static std::string timezoneConversionDateTimeTest(std::string aDateTime, std::string timezone);//n
    static bool greaterThanDateTimeTest(std::string aDateTime1, std::string aTimezone1, std::string aDateTime2, std::string aTimezone2);//n
      
    
      
  };
    
    
  
}

#endif /* SFTestHarness_hpp */
