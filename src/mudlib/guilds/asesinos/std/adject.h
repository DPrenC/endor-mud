#include "path.h"
#include <properties.h>

string QueryAdjective()
{
int mess;
string out;

   mess=this_object()->Query(P_GENDER);

   switch(mess)
   {
      case GENDER_FEMALE:
         out="la";
         break;
      default:
         out="el";
   }
   return out;
}

string QueryGenero()
{
int mess;
string out;

   mess=this_object()->Query(P_GENDER);

   switch(mess)
   {
      case GENDER_FEMALE:
         out="a";
         break;
      default:
         out="o";
   }
   return out;
}
