#ifndef __COMMON_H__
#define __COMMON_H__

#include "config.h"
#include <string>
#include <sstream>

#ifndef HAVE_RINT

#include <cmath>
   inline int rint(double f)
   { 
      return(f-std::floor(f)<0.5?std::floor(f):std::ceil(f));
   }

#endif

inline std::string from_int(int value)
{
   std::ostringstream buf;
   buf<<value;
   return buf.str();
}

#endif
