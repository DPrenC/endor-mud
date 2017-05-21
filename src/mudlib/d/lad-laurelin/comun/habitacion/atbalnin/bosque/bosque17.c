#include "path.h"
inherit CARAVAN_STOP;
inherit ATB_B("bosque_norte");

create(){
  ::create();
  seteuid(getuid());
  SetIntLong(W(QueryIntLong()+"Desde aquí puedes coger la "+
  	"caravana que va a Simauria.\n"));
  AddCaravana(NAHLIN("nahlin"));
  AddExit("norte", ATB_B("bosque25"));
}

