#include "path.h"
inherit ATB_CI("std_ciudad");

create()
{
  ::create();
  SetIntLong(W("Hacia el oeste ves, sientes, oyes y hueles la silenciosa, "
  	"ciega, sorda y... extremadamente olorosa vida salvaje que fluye y "
  	"crece, como no pod�a ser de otra forma, salvajemente.\n"
  	"La ciudad, los �rboles y cas.. caba�as siguen hacia el resto de "
  	"direcciones.\n"));
  AddExit("norte", ATB_CI("ciudad08"));
  AddExit("este", ATB_CI("ciudad09"));
  AddExit("oeste", ATB_B("bosque28"));
}

