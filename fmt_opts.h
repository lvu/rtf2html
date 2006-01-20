#ifndef __FMT_OPTS_H__
#define __FMT_OPTS_H__

#include "config.h"
#include "common.h"
#include <stack>

struct formatting_options
{
   enum halign {align_left, align_right, align_center, align_justify, align_error};
   bool chpBold, chpItalic, chpUnderline, chpSub, chpSup;
   int papLeft, papRight, papFirst;
   int papBefore, papAfter;
   halign papAlign;
   bool papInTbl;
   formatting_options()
   {
      chpBold=chpItalic=chpUnderline= chpSub=chpSup=false;
      papLeft=papRight=papFirst=papBefore=papAfter=0;
      papAlign=align_left;
      papInTbl=false;
   }
   std::string get_par_str();
};

typedef std::stack<formatting_options> fo_stack;

#endif

