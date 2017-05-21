#include "path.h"
inherit ATB_CI("std_ciudad");

create()
{
  ::create();
  SetIntLong(W("�Qu� tienen en com�n todos los callejones? Normalmente "
  	"la misma gente, o cuando menos el mismo tipo de gente (aunque no "
  	"podr�as jurar que las caras que ven no son las que ya has visto en "
  	"tantos otros sitios), el mismo inconfundible olor, y la inconfundible "
  	"aura de problemas. Durante a�os este call�j�n fu� as�, y parece "
  	"resistirse al cambio aunque los habitantes actuales sean elfos.\n"));
  SetIntShort("un s�rdido callej�n");

  AddExit("oeste", ATB_CI("ciudad31"));
  AddExit("suroeste", ATB_CI("ciudad32"));
}
