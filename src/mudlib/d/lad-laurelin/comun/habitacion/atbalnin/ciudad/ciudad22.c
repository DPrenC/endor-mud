#include "path.h"
#include <skills.h>

inherit ATB_CI("std_ciudad");

create()
{
  ::create();
  SetIntLong(W("Cuando se proyecta la construcci�n de una ciudad, se suelen "
  	"tener en cuenta las t�picas congestiones que producen el ajetreo de "
  	"las mercanc�as a ser vendidas, el vaiven de los habitantes, los "
  	"ni�os corriendo y jugando, etc�tera. As� ha ocurrido aqu�. No es que "
  	"hayan demasiados comercios, ni demasiados habitantes, ni demasiados "
  	"ni�os, pero si los hubieran, podr�an campar por aqu� a sus anchas.\n"));
  SetIntShort("la zona central de Atbalnin");
  	
  AddExit("sur", ATB_CI("ciudad19"));
  AddExit("oeste", ATB_CI("ciudad20"));
  AddExit("este", ATB_CI("ciudad23"));
}
