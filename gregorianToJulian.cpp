
//#include "dateCheck.h"
#include "timeConversionBaseClass.hpp"

// template < typename T > // T is either `const string` or `const char *`
double timeConversionBaseClass::gregorianToJulian(const char *inputOfSomeType, bool bbb) { //Declare function gregorianToJulian. ***Note*** that Julian \
    is spelled with a CAPITAL "J" !!! This function prototype takes just one input argument, a pointer to the structure \
    YearMonthDay, and returns a double.
    workingString = string(inputOfSomeType); //Taking the string of type string should cause a problem?¿
    int work;
    work = SECONDSPERHOUR;
    found = regex_search(workingString, matched, regSpace);
    if (!found) {
        regISOT.assign("(.*)T(.*)");
        found = regex_search(workingString, matched, regISOT);
        if (!found) return ((double)NAN); //Exit by returning a null
    }
    found = false;
    if (debug_mode) {
        cout << "matched.length()=" << matched.length() << "\n";
        cout << "matched.size()=" << matched.size() << endl;
    }
    if (matched.size() != 3) {
        return ((double)-1); //Exit by returning a minus 1 because we did not get two substrings;
    }
    //So at this point our input string (or array of characters, known as a c-strig) should have been split apart into 2 pieces:\
    a date part and a time part.
    datePart = matched[1].str();
    timePart = matched[2].str();
    found = false;
    found = regex_search(datePart, matchDate, splitApartDate);
    if (debug_mode) {
        cout << "matcheDate.length()=" << matchDate.length() << "\n";
         cout << "matcheDate.size()=" << matchDate.size() << endl;
    }
    if ( (!found) && (matchDate.size() != 4) ) {
        return ((double)-2); //Return with -2 error code indicating that we failed to split the date apart into three pieces.
    }
    y = stoi(matchDate[1].str() );
    mn = stoi(matchDate[2].str() );
    dblD = stod(matchDate[3].str() ); 
    found = regex_search(timePart, matchTime, splitApartTime);
    if (debug_mode) {
        cout << "matcheTime.length()=" << matchTime.length() << "\n";
        cout << "matcheTime.size()=" << matchTime.size() << endl;
    }
    if (found && (matchTime.size() == 2) ) {
        hr = stoi(matchTime[1].str() );
/* The following were already set to zero by the constructor
        min = 0;
        dblSec = 0;
*/
    } else if (found && (matchTime.size() == 3) ) {
        hr = stoi(matchTime[1].str() );
        min = stoi(matchTime[2].str() );
/* The constructor already set the dblSec to zero
        dblSec = 0;
*/
    } else if (found && (matchTime.size() == 4) ) {
        hr = stoi(matchTime[1].str() );
        min = stoi(matchTime[2].str() );
        dblSec = stod(matchTime[3].str() );
    } else {
        return ((double)-3); //Return indicating strange results when parsing the time part.
    }
    //note: 1461 divided by 4 is 365.25
    dblJD = (1461*(y+4800+(mn-14)/12))/4+(367*(mn-2-12*((mn-14)/12)))/12-(3*((y+4900+(mn-14)/12)/100))/4 + dblD-32075 ;
//    ymd->dblJD = (1461*(ymd->y+4800+(ymd->mn-14)/12))/4+(367*(ymd->mn-2-12*((ymd->mn-14)/12)))/12-(3*((ymd->y+4900+(ymd->mn-14)/12)/100))/4+ymd->dblD-32075 ;
/* ymd->intJD = (1461*(ymd->y+4800+(ymd->mn-14)/12))/4+(367*(ymd->mn-2-12*(ymd->mn-14)/12))/12-(3*((ymd->y+4900+(ymd->mn-14)/12)/100))/4+ymd->dblD-32075; */
    
    intJD = (int)(dblJD);  //Recast the double as an integer and save this integer version of the Julian Day (sans hh:mm:ss) in a separate location */
    this->intJD = (int)(this->dblJD);  //Recast the double as an integer and save this integer version of the Julian Day (sans hh:mm:ss) in a separate location */
return(this->dblJD + ((double)this->hr/HOURSPERDAY) + ((double)this->min/(HOURSPERDAY*MINUTESPERHOUR)) + this->dblSec/(HOURSPERDAY*SECONDSPERHOUR));

}

