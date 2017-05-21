#include "path.h"
#include <skills.h>

inherit ATB_CI("std_ciudad");

create()
{
  ::create();
  SetIntLong(W("�Cual ser�a el destino de un aventurero sin armas o armaduras? "
  	"Probablemente el mismo que el de uno que s� las tenga: convertirse "
  	"prematuramente en un montoncito de blancos huesos. Sin embargo, para "
  	"que esto no suceda alarmantemente pronto, en cada ciudad deben haber "
  	"diversas tiendas que vendan los art�culos de primera necesidad que "
  	"cualquier aventurero pueda desear. Est�s precisamente ante uno de esos "
  	"establecimientos.\n"));
  SetIntShort("la zona central de Atbalnin");
  AddDetail("cartel", "Es un cartel de madera que puedes leer.\n");
  AddReadMsg("cartel", "Tienda de Armas y Armaduras.\n");

  AddExit("entrar", ATB_TI("tienda04"));
  AddExit("sur", ATB_CI("ciudad21"));
  AddExit("oeste", ATB_CI("ciudad22"));
  AddExit("este", ATB_CI("ciudad24"));
}
