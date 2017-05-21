/* Tienda estándar de Lad Laurelin
   [t] Theuzifan

   31-03-99 [t] Creación. La tienda está cerrada por la noche por defecto.
*/

#include "path.h"
#include "/secure/wizlevels.h"
#include <nightday.h>
#include <moving.h>
#include <properties.h>

inherit SHOP;

static int opentime, closetime;
static string closed_str;

int SetCommerceOpenTime(int time){  return opentime=time;  }
int SetCommerceCloseTime(int time){  return closetime=time;  }
int QueryCommerceOpenTime(){  return opentime;  }
int QueryCommerceCloseTime(){  return closetime;  }
int ValidCommerceTime(int t)
{
  int t1, t2;

  t1=QueryCommerceOpenTime();
  t2=QueryCommerceCloseTime();

  if (t1<t2) return (t>=t1 && t<=t2);
  else return (t>=t1 && t<=t2);

  return (1);
}

string SetClosedShopString(string s){  return closed_str=s;  }
string QueryClosedShopString(){  return closed_str;  }

create()
{
  ::create();
  SetIntLong("Estás en una tienda de Lad Laurelin.\n");
  SetIntShort("una tienda");
  SetLocate("Lad Laurelin");
  SetCommerceOpenTime(ND_PREDAWN);
  SetCommerceCloseTime(ND_NIGHT);
  SetClosedShopString("La tienda está cerrada.\n");
}

int allow_enter(int method, mixed extra)
{
  int state;

  if (TP==PO)
  {
    if (method!=M_GO) return ::allow_enter(method, extra);

    state=NIGHTDAY->QueryState();
    if (ValidCommerceTime(NIGHTDAY->QueryState())
       && TP->Query(P_LSTATE)!=LSTATE_GHOST)
    {
      write(QueryClosedShopString());
      return ME_NO_ENTER;
    }
  }
  return ::allow_enter(method, extra);
}


