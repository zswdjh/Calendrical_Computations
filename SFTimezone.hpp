//
//  SFTimezone.hpp
//  my_assignment3
//
//  Created by Jing Liang on 2/19/18.
//  Copyright © 2018 Jing Liang. All rights reserved.
//

#ifndef SFTimezone_hpp
#define SFTimezone_hpp

#include <stdio.h>
namespace SoftwareFoundations{
    class SFTimezone {
    public:
        SFTimezone();
        ~SFTimezone();
        SFTimezone(const char* aTimezoneAbbrev); //GMT, EST, CST, PST
        SFTimezone(const SFTimezone &aTimezone);
        operator const char*(); // Returns the 3 letter abbreviation of the timezone object
        SFTimezone& SFTZsetTimezone(const char* aTimezone);
        char* SFTZgetTimezone() const;
    private:
        char* SFtimezone;
    };
}
#endif /* SFTimezone_hpp */
