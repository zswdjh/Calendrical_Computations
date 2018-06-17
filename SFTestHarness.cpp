//
//  SFTestHarness.cpp
//  ECE180-Assignment3
//
//  Created by rick gessner on 2/12/18.
//

#include "SFTestHarness.hpp"
using SoftwareFoundations::SFTestHarness;

int SFTestHarness::runDateTests() {
   // std::cout<<"-------------These are runDateTest()-----------------"<<std::endl;
  //date difference test
   /* std::string aDate1 = "02/15/2018";
    std::string aDate2 = "02/17/2018";
    std::string result = dateDifferenceTest(aDate1, aDate2);*/
    //std::cout<<"Date different test is "<<result<<std::endl;
    
  //adjust by week test
   /* int aWeek = 1;
    result = adjustDateByWeeksTest(aDate1,aWeek);*/
    //std::cout<<"Adjust by week test is "<<result<<std::endl;
    
    //set month
  /*  int aMonth = 5;
    result = setMonthDateTest(aDate1,aMonth);*/
    //std::cout<<"Set Month test is "<<result<<std::endl;
    
    //get day of week test
   // getDayOfWeekDateTest(aDate1);
    //std::cout<<"get day of week test is okay"<<std::endl;
    
    //end of month test
  //  std::string aDate3 = "03/15/2018";
   // endOfMonthDateTest(aDate3);
    //std::cout<<"end of month test is "<<result<<std::endl;
    
    //get day of year
    //result = getWeekOfYear(aDate1);
    //std::cout<<"get week of year test is "<<result<<std::endl;
    
    //adjust by month test
   // std::string aDate4 = "03/31/2018";
   // int aMonths = 1;
   // result = adjustDateByMonthTest(aDate4, aMonths);
    //std::cout<<"adjust by month test is "<<result<<std::endl;
    
    //advance by one day(operator++) test
   // std::string aDate5 = "12/31/2018";
    //result = advanceByOneDay(aDate5);
    //std::cout<<"advance by one day(operator++) test is "<<result<<std::endl;
    
    //back up by one day(operator--) test
   // std::string aDate6 = "01/01/2019";
   // result = backUpByOneDay(aDate6);
    //std::cout<<"back up by one day(operator--) test is "<<result<<std::endl;
    
    //copy constructor test
    //result = testCopyConstructor(aDate6);
    //std::cout<<"copy constructor of same type test is "<<result<<std::endl;
    
    //default constructor test
    //result = defaultCopyConstructor();
   // std::cout<<"default copy constructor is "<<result<<std::endl;
  
    
    //derived class to base class copy constructor test
   // std::string datetime = "02/15/2018 01:05:15";
   // result = derToBaseClassCopyConstructors(datetime);
    //std::cout<<"derived class to base class copy constructor test is "<<result<<std::endl;
    
    return 0;
}

int SFTestHarness::runTimeTests() {
    //std::cout<<"-------------These are runTimeTest()-----------------"<<std::endl;
    //test time difference
   /* std::string aTime1 = "09:05:15";
    std::string aTime2 = "09:05:22";
    std::string result = timeDifferenceTest(aTime1,aTime2); */
    //std::cout<<"time difference test is "<<result<<std::endl;
    
    //test adjust by minute
    //int aMinutes = 5;
   // result = adjustTimeByMinutesTest(aTime1, aMinutes);
    //std::cout<<"adjust by minute test is "<<result<<std::endl;
    
    //get min test
    //getMinutesTimeTest(aTime1);
    //std::cout<<"get minute test is okay"<<std::endl;
    
    //adjust by hour
    //int aHour = 25;
    //result = adjustTimeByHourTest(aTime1,aHour);
    //std::cout<<"adjust by hour test is "<<result<<std::endl;
    
    //get start of Day test
   // result = startOfDayTest(aTime1);
    //std::cout<<"Start of day test is "<<result<<std::endl;
    
    //get end of day test
    //result = endOfDayTest(aTime1);
    //std::cout<<"End of day test is "<<result<<std::endl;
    
    //greater than time test
    //bool result1=false;
   // result1 = greaterThanTimeTest(aTime2, aTime1);
    /*if(result1 == true){
        std::cout<<"GreaterThan Time test is okay"<<std::endl;
    }
    else{
        std::cout<<"GreaterThan Time test is wrong"<<std::endl;
    }*/
    
    //equal time test
   // result1 = equalTimeTest(aTime1, aTime1);
    /*if(result1==true){
        std::cout<<"equalTimeTest is okay"<<std::endl;
    }
    else{
        std::cout<<"equalTimeTest is wrong"<<std::endl;
    }*/
    
  return 0;
}

int SFTestHarness::runDateTimeTests() {
    //std::cout<<"-------------These are runDateTimeTest()-----------------"<<std::endl;
    
    //datetime difference test
   /* std::string dt1 = "02/15/2018 09:05:15";
    std::string dt2 = "02/15/2018 11:05:15";
    std::string tz1 = "PST";
    std::string tz2 = "EST";
    std::string result = dataTimeDifferenceTest(dt1, tz1, dt2, tz2);*/
   // std::cout<<"datetime difference test is "<<result<<std::endl;
    
    
    //run datatimetostring test
    
   /* std::string dt3 = "02/15/2018 09:05:15";
    std::string tz3 = "PST";
    
    std::string result1;
    result1 = dataTimeToStringTest(dt3, tz3); */
    //std::cout<<"DateTimeToString test is "<<result1<<std::endl;
    
   /* std::string dt3name = "Feb 15,2018 09:05:15";
    result1 = dataTimeToStringTest(dt3name, tz3);  */
    //std::cout<<"DateTimeToString test (initialize with format \"Jan 1,1961 HH:MM:SS\")"<<result1<<std::endl;
    
    //run constructor test(set the time zone not by default)
   // result1 = initializedDateTimeNotUsingDefaultGMTTest(dt3, tz3);
   // std::cout<<"initializeDateTime by not using default time zone is "<<result1<<std::endl;
    
    
    
    //run grater than datetime test
    /*
    std::string dt4 = "02/15/2018 11:05:15";
    std::string tz4 = "EST";
    bool bresult = greaterThanDateTimeTest(dt3, tz3, dt4, tz4);*/
    /*if(bresult==true)
        std::cout<<"greaterThanDateTimeTest is okay"<<std::endl;
    else
        std::cout<<"greaterThanDateTimeTest is wrong"<<std::endl;
    */
    
   // std::string dt5 = "02/15/2018 10:05:15";
   // std::string tz5 = "CST";
  //  bool bresult1 = equalDateTimeTest(dt4, tz4, dt5, tz5);
    /*if(bresult1==true)
        std::cout<<"EqualDateTimeTest is okay"<<std::endl;
    else
        std::cout<<"EqualDateTimeTest is wrong"<<std::endl;
    */
    
    
    
  return 0;
}

int SFTestHarness::runIntervalTests() {
    //std::cout<<"-------------These are runIntervalTest()-----------------"<<std::endl;
    //std::cout<<"checked in SFTime and STDate and SFDateTime class "<<std::endl;
  return 0;
}

int SFTestHarness::runTimezoneTests() {
    //std::cout<<"-------------These are runTimezoneTest()-----------------"<<std::endl;
    //timezone conversion test
   /* std::string dt1 = "02/15/2018 09:05:15";
    std::string tz1 = "PST";
    std::string result;
    result = timezoneConversionDateTimeTest(dt1, tz1);*/
    //std::cout<<"timezone conversion datatime test is "<<result<<std::endl;
    
    
  return 0;
}

//*******************************SFDate class *****************************************

/*
 * Return string representation of interval between two dates
 * Ex. aDate1 = "02/15/2018"
 *     aDate2 = "02/17/2018"
 * Returns : "0 years, 0 months, 2 days, 0 hours, 0 minutes and 0 seconds"
 */
std::string SFTestHarness::dateDifferenceTest(std::string aDate1, std::string aDate2) {   //necessary
    std::string result;
    std::string expectedre = "0 years, 0 months, 2 days, 0 hours, 0 minutes and 0 seconds";
    SFDate date1(aDate1.c_str());
    SFDate date2(aDate2.c_str());
    result = date1.operator-(date2);
    return result;
    
}

/*
 * Return string representation of date with weeks adjusted
 * Ex. aDate = "02/15/2018"
 *     aWeeks = 1
 * Returns : "02/22/2018"
 */
std::string SFTestHarness::adjustDateByWeeksTest(std::string aDate, int aWeeks) {  //necessary
    std::string result;
    SFDate date1(aDate.c_str());
    date1.adjustByWeeks(aWeeks);
    //std::cout<<"result is: "<<date1.toDateString()<<std::endl;
    //result = "okay";
    result = date1.toDateString();
    return result;
}

/*
 * Return string representation of date with month adjusted
 * Ex. aDate = "03/31/2018"
 *     aMonths = 1
 * Returns : "05/01/2018"
 */
/*
std::string SFTestHarness::adjustDateByMonthTest (std::string aDate, int aMonths){
    SFDate date1(aDate.c_str());
    date1.adjustByMonths(aMonths);
    std::string expected = "05/01/2018";
    std::string actual = date1.toDateString();
    return actual;
}
*/

/*
 * Return string representation of date with month changed
 * Ex. aDate = "02/15/2018"
 *     aMonth = 5
 * Returns : "05/15/2018"
 */
std::string SFTestHarness::setMonthDateTest(std::string aDate, int aMonth) { //necessary
    SFDate date1(aDate.c_str());
    date1.setMonth(aMonth);
    std::string result;
    result = date1.toDateString();
    return result;
}

/*
 * Return integer representation of the day of the week for the given date
 * Ex. aDate = "02/15/2018"
 * Returns : 4
 */
int SFTestHarness::getDayOfWeekDateTest(std::string aDate) {   //necessary
    SFDate date1(aDate.c_str());
    date1.getDayOfweek();
    return date1.getDayOfweek();
}

/*
 * Return string representation of date at the end of month of the given date
 * Ex. aDate = "03/15/2018"
 * Returns : "03/31/2018"
 */
std::string SFTestHarness::endOfMonthDateTest(std::string aDate) {   //necessary
    SFDate date1(aDate.c_str());
    date1.endOfMonth();
    std::string result;
    result = date1.toDateString();
    return result;
}

/*
 * Return true if getweekofyear return the right answer in SFDate class
 * Ex. aDateTime1 = "02/15/2018"
 *     expected answer = 7 (week7)
 *
 * Returns : 7
 */
/*
std::string SFTestHarness::getWeekOfYear(std::string aDate){   //extra
    SFDate date1(aDate.c_str());
    int actual = date1.getWeekOfYear();
    return std::to_string(actual);
}
*/
/*
 * Return string representation of adjust day by 1;
 * Ex. aDate = "12/31/2018"
 * Returns : "01/01/2019"
 */
/*
std::string SFTestHarness::advanceByOneDay(std::string aDate1){
    SFDate date1(aDate1.c_str());
    date1.operator++();
    std::string result;
    std::string expected = "01/01/2019";
    std::string actual = date1.toDateString();
    return actual;
}
*/
/*
 * Return string representation of adjust day by -1;
 * Ex. aDate = "01/01/2019"
 * Returns : "12/31/2018"
 */
/*
std::string SFTestHarness::backUpByOneDay(std::string aDate1){
    SFDate date1(aDate1.c_str());
    date1.operator--();
    std::string actual = date1.toDateString();
    return actual;
}
*/
/*
 * Return string representation of a SFdate class created by copy constructor of same type.
 * Ex. aDate = "01/01/2019"
 * Returns : "01/01/2019"
 */
/*
std::string SFTestHarness::testCopyConstructor(std::string aDate1){
    SFDate original(aDate1.c_str());
    SFDate copy(original);
    std::string result;
    if(original.toDateString().compare(copy.toDateString())==0){
        result = "okay";
    }
    else{
        result = "wrong";
    }
    return result;
}
*/
/*
 * Return string representation of a SFdate class created by current date.
 * Ex. aDate = "02/27/2018"
 * Returns : "02/27/2018"
 */
/*
std::string SFTestHarness::defaultCopyConstructor(){
    SFDate current;
    std::string curday = "02/27/2018";
    std::string result;
    if(curday.compare(curday)==0){
        result = "okay";
    }
    else{
        result = "wrong";
    }
    return result;
}

std::string SFTestHarness::derToBaseClassCopyConstructors(std::string aDate1){
    SFDateTime datetime(aDate1.c_str());
    SFDate date(datetime);
    std::string expected = "02/15/2018";
    std::string actual = date.toDateString();
    std::string result;
    if(expected.compare(actual)==0){
        result = "okay";
    }
    else{
        result = "wrong";
    }
    return result;
}
*/

//*******************************SFTime class *****************************************


/*
 * Return string representation of interval between two times
 * Ex. aTime1 = "09:05:15"
 *     aTime2 = "09:05:22"
 * Returns : "0 years, 0 months, 0 days, 0 hours, 0 minutes and 7 seconds"
 */
std::string SFTestHarness::timeDifferenceTest(std::string aTime1, std::string aTime2) {   //necessary
    SFTime time1(aTime1.c_str());
    SFTime time2(aTime2.c_str());
    std::string result;
    result = time1.operator-(time2);
    return result;
}

/*
 * Return string representation of interval between two times
 * Ex. aTime1 = "09:05:15"
 *     aMinutes = 5
 * Returns : "09:10:15"
 */
std::string SFTestHarness::adjustTimeByMinutesTest(std::string aTime1, int aMinutes) {   //necessary
    SFTime time1(aTime1.c_str());
    time1.adjustByMinutes(aMinutes);
    std::string result = time1.toTimeString();
   
  return result;
}

/*
 * Return string representation of interval between two times
 * Ex. aTime1 = "09:05:15"
 *     aHour = 25
 * Returns : "10:05:15"
 */
/*
std::string SFTestHarness::adjustTimeByHourTest(std::string aTime1, int aHour){
    SFTime time1(aTime1.c_str());
    time1.adjustByHours(25);
    std::string expected = "10:05:15";
    std::string actual = time1.toTimeString();
    std::string result;
    if(expected.compare(actual)==0){
        result = "okay";
    }else{
        result = "wrong";
    }
    return result;
}
*/

/*
 * Return string representation of start of the day
 * Ex. aTime1 = "09:05:15"
 *
 * Returns : "00:00:00"
 */
/*
std::string SFTestHarness::startOfDayTest(std::string aTime1){
    SFTime time1(aTime1.c_str());
    time1.startOfDay();
    std::string expected = "00:00:00";
    std::string actual = time1.toTimeString();
    std::string result;
    if(expected.compare(actual)==0){
        result = "okay";
    }else{
        result = "wrong";
    }
    return result;
}
*/
/*
 * Return string representation of end of the day
 * Ex. aTime1 = "09:05:15"
 *
 * Returns : "23:59:59"
 */
/*
std::string SFTestHarness::endOfDayTest(std::string aTime1){
    SFTime time1(aTime1.c_str());
    time1.endOfDay();
    std::string expected = "23:59:59";
    std::string actual = time1.toTimeString();
    std::string result;
    if(expected.compare(actual)==0){
        result = "okay";
    }else{
        result = "wrong";
    }
    return result;
}
*/
/*
 * Return minutes from the given time
 * Ex. aTime = "09:05:15"
 * Returns : 5
 */
int SFTestHarness::getMinutesTimeTest(std::string aTime) {   //necessary
    SFTime time1(aTime.c_str());
    int minute = time1.getMinutes();
    
  return minute;
}

/*
 * Return true if aTime1 is stricty greater than aTime2
 * Ex. aTime1 = "09:05:22"
 *
 *     aTime2 = "09:05:15"
 *
 * Returns : true
 */

/*
bool SFTestHarness::greaterThanTimeTest(std::string aTime1, std::string aTime2){
    SFTime time1(aTime1.c_str());
    SFTime time2(aTime2.c_str());
    bool result = time1.operator>(time2);
    return result;
}
*/
/*
 * Return true if aTime1 is equal to aTime2
 * Ex. aTime1 = "09:05:15"
 *
 *     aTime2 = "09:05:15"
 *
 * Returns : true
 */

/*
bool SFTestHarness::equalTimeTest(std::string aTime1, std::string aTime2){
    SFTime time1(aTime1.c_str());
    SFTime time2(aTime2.c_str());
    bool result = time1.operator==(time2);
    return result;
}
*/
//*******************************SFDateTime class *****************************************


/*
 * Return string representation of interval between two times
 * Ex. aDateTime1 = "02/15/2018 09:05:15"
 *     aTimeZone1 = "PST"
 *     aDateTime2 = "02/15/2018 11:05:15"
 *     aTimeZone2 = "EST"
 * Returns : "0 years, 0 months, 0 days, 1 hours, 0 minutes and 0 seconds"
 */
std::string SFTestHarness::dataTimeDifferenceTest(std::string aDateTime1, std::string aTimezone1, std::string aDateTime2, std::string aTimezone2) {
    SFTimezone tz1(aTimezone1.c_str());    //necessary
    SFTimezone tz2(aTimezone2.c_str());
    SFDateTime datetime1(aDateTime1.c_str(),&tz1);
    SFDateTime datetime2(aDateTime2.c_str(),&tz2);
    //std::cout<<datetime2.operator-(datetime1)<<std::endl;
    std::string result;
    result = datetime1.operator-(datetime2);
    return result;
}

/*
 * Return string representation of given date-time
 * Ex. aDateTime = "02/15/2018 09:05:15"
 *     aTimeZone = "PST"
 * Returns : "Feb 15, 2018 01:05:15 PST"
 */
std::string SFTestHarness::dataTimeToStringTest(std::string aDateTime, std::string timezone) {  //necessary
    SFDateTime datetime1(aDateTime.c_str());
    SFTimezone newtz(timezone.c_str());
    datetime1.setTimezone(newtz);
    std::string realresult = datetime1.toDateTimeString();
    return realresult;
  
}

/*
 * Return string representation of given GMT date-time converted to given timezone
 * Ex. aDateTime = "02/15/2018 09:05:15"
 *     aTimeZone = "PST"
 * Returns : "Feb 15, 2018 01:05:15 PST"
 */
std::string SFTestHarness::timezoneConversionDateTimeTest(std::string aDateTime, std::string timezone) {   //necessary
    SFDateTime datetime1(aDateTime.c_str());
    SFTimezone newtz(timezone.c_str());
    datetime1.setTimezone(newtz);
    std::string realresult = datetime1.toDateTimeString();
    return realresult;
}

/*
 * Return true if aDateTime1 is stricty greater than aDateTime2
 * Ex. aDateTime1 = "02/15/2018 09:05:15"
 *     aTimeZone1 = "PST"
 *     aDateTime2 = "02/15/2018 11:05:15"
 *     aTimeZone2 = "EST"
 * Returns : true
 */
bool SFTestHarness::greaterThanDateTimeTest(std::string aDateTime1, std::string aTimezone1, std::string aDateTime2, std::string aTimezone2) {//necessary
    SFTimezone tz1(aTimezone1.c_str());
    SFTimezone tz2(aTimezone2.c_str());
    SFDateTime datetime1(aDateTime1.c_str(),&tz1);
    SFDateTime datetime2(aDateTime2.c_str(),&tz2);
    bool relation = datetime1.operator>(datetime2);
    return relation;
}


/*
 * Return true if aDateTime can initialize the timezone (which is different than GMT)
 * Ex. aDateTime1 = "02/15/2018 09:05:15"
 *     aTimeZone1 = "PST"
 *
 * Returns : "Feb 15, 2018 09:05:15 PST"
 */


/*
std::string SFTestHarness::initializedDateTimeNotUsingDefaultGMTTest(std::string aDateTime,std::string atimezone) {
    SFTimezone tz1(atimezone.c_str());
    SFDateTime datetime1(aDateTime.c_str(),&tz1);
    std::string realresult =datetime1.toDateTimeString();
    //std::cout<<realresult<<std::endl;
    std::string expected = "Feb 15, 2018 09:05:15 PST";
    std::string result;
    if(expected.compare(realresult)==0){
        result = "okay";
    }
    else{
        result = "wrong";
    }
    return result;
}

bool SFTestHarness::equalDateTimeTest(std::string aDateTime1, std::string aTimezone1, std::string aDateTime2, std::string aTimezone2){
    SFTimezone tz1(aTimezone1.c_str());
    SFTimezone tz2(aTimezone2.c_str());
    SFDateTime datetime1(aDateTime1.c_str(),&tz1);
    SFDateTime datetime2(aDateTime2.c_str(),&tz2);
    bool expectedresult = true;
    bool relation = datetime1.operator==(datetime2);
    if(expectedresult==relation)
        return true;
    else
        return false;
}
*/




int SFTestHarness::runAllTests() {
  int theResult = runDateTests();
  theResult+=runTimeTests();
  theResult+=runDateTimeTests();
  theResult+=runIntervalTests();
  theResult+=runTimezoneTests();
  return theResult;
}
