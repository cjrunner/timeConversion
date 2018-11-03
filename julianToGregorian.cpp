//
//  julianToGregorian.cpp
//  seasonChange
//  Direct copy from: /Users/cjc/C/baselineSource/julianToGregorian-r0.c
//  Created by Clifford Campo on 2018-11-02.
//  Copyright © 2018 CliffordCampo. All rights reserved.
//
#include "timeConversionBaseClass.hpp"
string zeroPadIfNecessary(int someInteger);
const char  *timeConversionBaseClass::julianToGregorian (double *JD,   bool dayStartsAtNoon) {
    if (dayStartsAtNoon) { /* When variable dayStartsAtNoon=0 means day starts at midnight */
        jd =  *JD+0.5;  // This could be a problem. Civilians think the day starts at midnight, \
        while astronomers define the new day as starting at noon, with noon defined as when the zenith distance \
        is at a minimum (there's some logic to that way of thinking).
    } else {
/*Ok, so day starts at noon, in keeping with our astronomer-view-of-the-world-as-they-believe-it-should-be algorithm's assumptions*/
        jd = *JD;
    }
    IP=(int)jd; /* separate the integer part from the fractional part, integer part contains the YYYY-MM-DD information */
    FP=jd-(double)IP; /* separate out the fractional part, contains hh:mm:ss information */
    if(IP>2299160) { //The Gregorian Calendar equivalent of jd = 2299160 is 1582-10-04 00:00:00.
        A=(int)(((double)IP-1867216.25)/(36524.25)); //The Gregorian Calendar equivalent of jd = 1867216.25 is 0400-02-28 06:00:00.
        B=IP+1+A-(int)(A/4);
    } else {
        B=IP;
    }
    C=B+1524;
    D=(int)(((double)C-122.1)/365.25);
    E=(int)((double)(D)*365.25);
    G=(int)((  ((double)(C)-(double)(E))/30.6001   ));
    d=(double)(C-E+FP-(int)(30.6001*G));
    if ((double)G<13.5) {
        m=G-1;
    }else {
        m=G-13;
    }
    if((double)m>2.5) {
        y=D-4716;
    } else {
        y=D-4715;
    }
    mn = (int)m;
    day = (int)d;
    
    hr = (int)(HOURSPERDAY*FP); /* extract hours from the fractional part */
    FP = HOURSPERDAY*FP-(double)hr; /* remove hours from the fractional part so FP contains information on just minutes and seconds */
    min = (int)(MINUTESPERHOUR*FP); /* extract minutes from the fractional part */
    FP  = MINUTESPERHOUR*FP -(double)min; /* remove minutes from the fractional part so FP contains information on just seconds */
    sec = (int)(SECONDSPERMINUTE)*FP; // extract seconds from the fractional part so FP contains information on just subseconds, \
    which for now, we won't worry about.
    FP  = SECONDSPERMINUTE*FP-(double)sec; // remove seconds from the fractional part so FP contains information about subseconds.
    subsec = (int)1000000*FP; /* let subsec represent the microseconds that remain */
    if ( (subsec/1000000) >= 0.5 ) sec++; 

    workingString = to_string(y) + "-" + zeroPadIfNecessary(mn) + "-" + zeroPadIfNecessary(day) + " " + zeroPadIfNecessary(hr) + ":" + zeroPadIfNecessary(min) + ":" + zeroPadIfNecessary(sec);

    return(workingString.c_str());
}
string zeroPadIfNecessary(int someInteger) {
    if (someInteger < 10) {
        return "0" + to_string(someInteger);
    } else {
        return to_string(someInteger);
    }
}
