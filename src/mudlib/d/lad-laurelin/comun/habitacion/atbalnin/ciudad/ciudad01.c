#include "path.h"
inherit ATB_CI("std_ciudad");

create()
{
  ::create();
  SetIntLong(W("Esta es la parte oeste de lo que los orgullosos atbalnineros "
  	"llamar�n ciudad. Ves como sus caba�as se reparten desordenadamente "
  	"por entre los �rboles, y si levantas la mirada puedes ver con cierto "
  	"des�nimo c�mo alguien ha construido alguna en las copas.\n"
  	"Esperas no tener que buscar a alguien all� arriba.\n"));
  AddExit("norte", ATB_CI("ciudad06"));
  AddExit("este", ATB_CI("ciudad07"));
  AddExit("sur", ATB_CI("ciudad02"));
  AddExit("oeste", ATB_B("bosque32"));
}

