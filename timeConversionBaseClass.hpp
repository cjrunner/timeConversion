//
//  timeConversionPriv.hpp
//  timeConversion
//
//  Created by Clifford Campo on 11/2/18.
//  Copyright © 2018 CliffordCampo. All rights reserved.
//

/* The classes below are not exported */
#ifndef __timeConversion__
#define __timeConversion__
#include <iostream>
#include <string>
#include <regex>
#include <cmath> //Used for generating Not-A-Number (NaN)constant
#include <ctgmath>
#include <iomanip>
using namespace std;
// #pragma GCC visibility push(hidden)

class timeConversionBaseClass {
private:
    bool debug_mode;      // Indicate debug mode
    const int PASS = 0;
    const int INITIALIZE = 3;
    const int FAIL = 1;
    const int DAMNEDIFIKNOW = 2;
    const int LENGTHSOK = 1;
    const int MONTHSANDYEARSOK = 2;
    const int MONTHSANDDAYSOK31 = 3;
    const int MONTHSANDDAYSOK30 = 4;
    const int MONTHSANDDAYSOK29 = 5;
    const int MONTHSANDDAYSOK28 = 6;
    const int HOURSPERDAY =   24;
    const int MINUTESPERHOUR = 60;
    const int SECONDSPERMINUTE = 60;
    const int SECONDSPERHOUR = 3600;
    const int UNKNOWN = 7;
    const int ASTROTIME  =  1;
    const int CIVILTIME  =  0;
    const int TOGREGORIAN  =  1;      // Do a Julian to Gregorian Conversion
    const int TOJULIAN  =  2;      // Do a Gregorian to Julian Conversion
    const int NONE    =    0;      // No conversion
    const int MINUTESPERDAY =  HOURSPERDAY *  MINUTESPERHOUR;
    const int SECONDSPERDAY = HOURSPERDAY * SECONDSPERHOUR;
    const int YEAROUTOFRANGE =  1; /* Year is > 9999 */
    const int MONTHOUTOFRANGE = 2; /* Month is <1 or >12 */
    int A = 0;
    int IP = 0;
    int B = 0;
    int C = 0;
    int D = 0;
    int E = 0;
    int G = 0;
    int m = 0;
    int mn = 0; //months
    int rc=0;
    int day = 0;
    int y = 0;
    int hr = 0;
    int min = 0;
    int sec = 0;
    int intJD = 0;
    double  subsec = 0;
    double jd =0 ;
    double FP = 0;
    double d = 0;
    double dblD = 0;
    double dblSec = 0;
    double dblJD = 0;
    const char* ISO8601_copy; //Copied from input parameter
    string ISO8601_madeIntoString;
    
public:
    string workingString;
    string datePart;
    string timePart;
    regex regSpace;
    regex regISOT;
    regex splitApartDate;
    regex splitApartTime;
    
    smatch matched;
    smatch matchSpace;
    smatch matchISOT;
    
    smatch matchDate;
    smatch matchTime;
    int numberOfSubStringsTime;
    int numberOfSubStringsDate;
    bool found = false;
    ~timeConversionBaseClass(void);
    timeConversionBaseClass(bool = false);
    //    int julianToGregorian (double *, char *, bool=false); //bool = false means day starts at mid-night.
    //    template < class T > // T is either `const string` or `const char *`
    double gregorianToJulian(const char *, bool=false);
    //    double gregorianToJulian(const string ymd);
    
    //    template < class T > // T is either `const string` or `const char *`
    const char  *julianToGregorian(double *, bool=false);
    //    string julianToGregorian(double);
    //    int julianToGregorian (double *JD,  char *ISO8601, bool dayStartsAtNoon)
    void setDebugMode(bool);
};
// #pragma GCC visibility pop
#endif
