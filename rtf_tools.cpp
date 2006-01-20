#include "rtf_tools.h"
#include <cstdio>
#include <cctype>
#include <algorithm>

template <class T>
struct fu_isspace : public std::unary_function<T, bool>
{
   bool operator () (T c) const
   { 
      return std::isspace(c);
   }
};

void insert_char_option(std::string &str, const std::string &opt, bool bSet)
{
   std::string sDo, sUndo;
   if (bSet)
      sUndo+="/";
   else
      sDo+="/";
   sDo+=opt;
   sUndo+=opt;
   std::string::reverse_iterator pos, pos2;
   pos=std::find_if(str.rbegin(), str.rend(), std::not1(fu_isspace<char>()));
   bool bFound=false;
   if (!str.empty())
      while (pos<str.rend()-1 && *pos=='>')
      {
         pos2=std::find(pos+1, str.rend(), '<');
         std::string tag(pos2.base(), pos.base()-1);
         if (tag=="td" || tag=="tr" || tag=="table")
            break;
         if (tag==sUndo)
         {
            bFound=true;
            break;
         }
         pos=pos2+1;
      }
   if (bFound)
   {
      ++pos2;
      str.erase(pos2.base(), pos.base());
   }
   else
   {
      ((str+="<")+=sDo)+=">";
   }
}

