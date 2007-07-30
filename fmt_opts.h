#ifndef __FMT_OPTS_H__
#define __FMT_OPTS_H__

#include "config.h"
#include "common.h"
#include <stack>

struct formatting_options
{
   enum halign {align_left, align_right, align_center, align_justify, align_error};
   bool chpBold, chpItalic, chpUnderline, chpSub, chpSup;
   int chpFontSize;
   int papLeft, papRight, papFirst;
   int papBefore, papAfter;
   halign papAlign;
   bool papInTbl;
   formatting_options()
   {
      chpBold=chpItalic=chpUnderline=chpSub=chpSup=false;
      chpFontSize=0;
      papLeft=papRight=papFirst=papBefore=papAfter=0;
      papAlign=align_left;
      papInTbl=false;
   }
   bool operator==(const formatting_options &opt) // tests only for character options
   {
      return chpBold==opt.chpBold && chpItalic==opt.chpItalic 
                      && chpUnderline==opt.chpUnderline && chpSub==opt.chpSub
                      && chpSup==opt.chpSup && chpFontSize==opt.chpFontSize;
   }
   bool operator!=(const formatting_options &opt) // tests only for character options
   {
      return !(*this==opt);
   }
   formatting_options &operator=(const formatting_options &opt)
   {
      memcpy(this, &opt, sizeof(formatting_options));
      return *this;
   }
   std::string get_par_str() const;
   std::string get_span_str() const;
};

typedef std::stack<formatting_options> fo_stack;


class html_text {
 private:
   formatting_options cur_opt;
   const formatting_options &opt;
   std::string text;
 public:
   html_text(const formatting_options &_opt) : opt(_opt) {}
   const std::string &str() { return text; }
   template <class T> void write(T s)
   {
      if (cur_opt!=opt || text.empty())
      {
         if (!text.empty())
            text+="</span>";
         text+=opt.get_span_str();
         cur_opt=opt;
      }
      text+=s;
   }
//   void write(char c) { write(std::string()+c); }
   void clear() { text.clear(); }
};

#endif

