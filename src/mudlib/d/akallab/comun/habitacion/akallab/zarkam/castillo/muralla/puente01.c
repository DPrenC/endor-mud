/*
DESCRIPCION : pasarela entre la muralla y el castillo
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/castillo/torre/puente01.c
MODIFICACION: 04-11-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include AK_MACRO
inherit ROOM;

int ir_e() {
  write("La puerta que da al castillo esta cerrada. Tras forcejear un rato con ella no "
        "consigues que se abra.\n");

  say(  NOMBRE+" trata de abrir la puerta que da al castillo, pero tras forcejear "
        "un rato con ella no lo consigue.\n",TP);
  return 1;
}


create() {
  ::create();
 SetIntShort("la pasarela entre la muralla y el castillo");
  SetIntLong(
    "Te hallas sobre una pasarela de piedra que a modo de puente conecta la muralla "
    "con la primera planta del castillo de Zarkam. La pasarela en si es un corredor "
    "al descubierto flanqueado por almenas. Observas que bajo la pasarela transcurre "
    "un amplio corredor entre la muralla y el castillo.\n");

  AddDetail(({"almena","almenas"}),
    "Las almenas son unos bloques de piedra que coronan los muros de la pasarela. Su "
    "funcion es la de proteger a los defensores de la fortificacion, a la vez que los "
    "huecos entre ellas les permiten atacar.\n");

  AddDetail(({"pasarela"}), QueryIntLong());

  AddDetail(({"corredor"}),
    "Es una especie de amplio pasillo al descubierto que queda entre la muralla y el "
    "castillo. La pasarela en la que estas cruza por encima de el.\n");

  AddDetail(({"castillo"}),
     "La ciudad de Zarkam se ha construido en torno al gran castillo que observas al "
     "al norte de aqui. En el vive el governador orco que el emperador ha elegido "
     "para dirigir esta provincia. El castillo es una inmensa mole de piedra mas alta "
     "que cualquiera de los edificios que lo rodean. Sobre el se alza una alta torre "
     "desde la que se vigila el valle constantemente.\n");

  AddDetail(({"torre"}),"Se alza sobre el castillo. Desde alli se vigila todo el valle...\n");

  AddDetail(({"muralla"}),
     "Es un inmenso muro de piedra que protege el castillo rodeandola por completo. "
     "Dirias que debe tener al menos unos cinco metros de altura en las partes mas "
     "bajas sin contar con las almenas. Cada cierta distancia observas una torre o una "
     "escalera adosada a la muralla que permiten subir a ella. Continamente ves a "
     "soldados fuertemente armados patrullando sobre la muralla.\n");


  SetIntNoise("Se oye el ajetreo tipico del castillo.\n");
  SetIntSmell("Hmm.. el aire es mas bien frio por la altura.\n");
  SetLocate("castillo de Zarkam");
  SetIndoors(0);
  SetIntBright(30);

AddExit("este",SF(ir_e));
AddExit("oeste",Z_CASTILLO("muralla/torre24"));
}
