#include "path.h"
#include <skills.h>

inherit ATB_CI("std_ciudad");

create()
{
  ::create();
  SetIntLong(W("Cuando se proyecta la construcción de una ciudad, se suelen "
  	"tener en cuenta las típicas congestiones que producen el ajetreo de "
  	"las mercancías a ser vendidas, el vaiven de los habitantes, los "
  	"niños corriendo y jugando, etcétera. Así ha ocurrido aquí. No es que "
  	"hayan demasiados comercios, ni demasiados habitantes, ni demasiados "
  	"niños, pero si los hubieran, podrían campar por aquí a sus anchas.\n"));
  SetIntShort("la zona central de Atbalnin");
  	
  AddExit("sur", ATB_CI("ciudad19"));
  AddExit("oeste", ATB_CI("ciudad20"));
  AddExit("este", ATB_CI("ciudad23"));
}
