#include "path.h"
#include <skills.h>

inherit ATB_CI("std_ciudad");

create()
{
  ::create();
  SetIntLong(W("Al norte puedes vislumbrar algo parecido a una tienda; o en "
  	"todo caso algún sitio donde se compran y venden cosas. Al sur "
  	"vislumbras la silueta de un gran edificio. Aparte de esto, todo "
  	"parece normal.\n"));

  AddDetail("tienda", W("Desde aquí ves una construcción que parece que se usa "
  	"como tienda o algo similar.\n"));
  AddExit("oeste", ATB_CI("ciudad30"));
  AddExit("sur", ATB_CI("ciudad32"));
  AddExit("este", ATB_CI("ciudad33"));
  AddExit("norte", ATB_CI("ciudad40"));
}


