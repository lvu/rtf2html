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
   if (chpFColor.r>=0)
   {
      style+="color:#";
      style+=hex(chpFColor.r&0xFF)+hex(chpFColor.g&0xFF)+hex(chpFColor.b&0xFF);
      style+=";";
   }
   if (chpBColor.r>=0)
   {
      style+="background-color:#";
      style+=hex(chpBColor.r&0xFF)+hex(chpBColor.g&0xFF)+hex(chpBColor.b&0xFF);
      style+=";";
   }
   if (chpHighlight>0)
   {
      style+="background-color:";
      switch (chpHighlight)
      {
      case 1: style+="black"; break;
      case 2: style+="blue"; break;
      case 3: style+="aqua"; break;
      case 4: style+="lime"; break;
      case 5: style+="fuchsia"; break;
      case 6: style+="red"; break;
      case 7: style+="yellow"; break;
      case 9: style+="navy"; break;
      case 10: style+="teal"; break;
      case 11: style+="green"; break;
      case 12: style+="purple"; break;
      case 13: style+="maroon"; break;
      case 14: style+="olive"; break;
      case 15: style+="gray"; break;
      case 16: style+="silver"; break;
      }
      style+=";";
   }
   if (!chpFont.name.empty())
   {
      style+="font-family:'";
      style+=chpFont.name;
      style+="'";
      switch (chpFont.family)
      {
      case font::ff_serif: style+=", serif"; break;
      case font::ff_sans_serif: style+=", sans-serif"; break;
      case font::ff_cursive: style+=", cursive"; break;
      case font::ff_fantasy: style+=", fantasy"; break;
      case font::ff_monospace: style+=", monospace"; break;
      }
      style+=";";
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
