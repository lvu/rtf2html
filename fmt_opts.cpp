#include "fmt_opts.h"

std::string formatting_options::get_span_str() const
{
   std::string style;
   if (chpBold)
   {
      style+="font-weight:bold;";
   }
   if (chpItalic)
   {
      style+="font-style:italic;";
   }
   if (chpUnderline)
   {
      style+="text-decoration:underline;";
   }
   if (chpFontSize>0 && !chpSub && !chpSup)
   {
      style+="font-size:";
      style+=from_int(chpFontSize/2);
      style+="pt;";
   }
   if (chpSub)
   {
      style+="font-size:";
      style+=from_int((int)(0.4*(chpFontSize?chpFontSize:24)));
      style+=";vertical-align:sub;";
   }
   if (chpSup)
   {
      style+="font-size:";
      style+=from_int((int)(0.4*(chpFontSize?chpFontSize:24)));
      style+=";vertical-align:super;";
   }
   if (style.empty())
      return std::string("<span>");
   else
   {
      style.insert(0, "<span style=\"");
      return style+"\">";
   }
}

std::string formatting_options::get_par_str() const
{
   std::string style;
   switch (papAlign)
   {
   case formatting_options::align_right:
      style+="text-align:right;";
      break;
   case formatting_options::align_center:
      style+="text-align:center;";
      break;
   case formatting_options::align_justify:
      style+="text-align:justify;";
   }
   if (papFirst!=0)
   {
      style+="text-indent:";
      style+=from_int(papFirst);
      style+="pt;";
   }
   if (papLeft!=0)
   {
      style+="margin-left:";
      style+=from_int(papLeft);
      style+="pt;";
   }
   if (papRight!=0)
   {
      style+="margin-right:";
      style+=from_int(papRight);
      style+="pt;";
   }
   if (papBefore!=0)
   {
      style+="margin-top:";
      style+=from_int(papBefore);
      style+="pt;";
   }
   if (papAfter!=0)
   {
      style+="margin-bottom:";
      style+=from_int(papAfter);
      style+="pt;";
   }
   if (style.empty())
      return std::string("<p>");
   else
   {
      style.insert(0, "<p style=\"");
      return style+"\">";
   }
}
