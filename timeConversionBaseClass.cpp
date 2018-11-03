//
//  timeConversionBaseClass.cpp
//  timeConversion
//
//  Created by Clifford Campo on 11/2/18.
//  Copyright © 2018 CliffordCampo. All rights reserved.
//

#include "timeConversionBaseClass.hpp"

timeConversionBaseClass::timeConversionBaseClass(bool debug)
{
    debug_mode = debug;
    regSpace.assign("(.*) (.*)");
    regISOT.assign("(.*)T(.*)");
    splitApartDate.assign("([[:digit:]]{4})-([[:digit:]]{2})-([[:digit:]]{2})");
    splitApartTime.assign("([[:d:]]{2}):([[:d:]]{2}):([[:d:]]{2})");
}

timeConversionBaseClass::~timeConversionBaseClass() {
    ;
}
void timeConversionBaseClass::setDebugMode(bool dm) {
    debug_mode = dm;
}
