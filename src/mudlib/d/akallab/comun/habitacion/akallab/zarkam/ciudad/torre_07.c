/*
DESCRIPCION : pasarela entre las dos torres
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/ciudad/torre_07.c
MODIFICACION: 12-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

int ir_este() {
  write("La puerta de la torre del este esta cerrada. Tras forcejear un rato con ella no "
 "consigues que se abra.\n");

 say(capitalize(TP->QueryName())
 +" trata de abrir la puerta de la torre del del este, pero tras forcejear "
  "un rato con ella no lo consigue.\n",TP);
 return 1;
}


create() {
 ::create();
 SetIntShort("una pasarela entre las dos torres");
 SetIntLong(
    "Te hallas sobre la pasarela de piedra que comunica las dos torres de la puerta "
    "norte de la ciudad. La pasarela en si es un corredor al descubierto flanqueado "
    "por altas almenas que la protegen. Junto a las almenas hay varios altos postes "
    "en los que flamean alargadas banderas negras, simbolos del imperio orco. El "
    "viento sopla con fuerza desde el noroeste\n");

 AddDetail(({"poste","postes","bandera","banderas"}),
    "Junto a las almenas del muro exterior hay varios postes altos y delgados, cuya "
    "funcion es la de ser los mastiles de otras tantas banderas negras, simbolos del "
    "imperio orco.\n");

 AddDetail(({"almena","almenas"}),
    "Las almenas son unos bloques de piedra que coronan los muros de la pasarela. Su "
    "funcion es la de proteger a los defensores de la fortificacion, a la vez que los "
    "huecos entre ellas les permiten atacar.\n");

AddDetail(({"pasarela","corredor","arco"}),
    "Entre las dos torres se extiende una pasarela que permite ir de una a la otra. "
    "La pasarela se halla sobre un arco de piedra que surge de las paredes de las dos "
    "torres que forman la puerta de la ciudad.\n");

AddDetail(({"torre","torres"}),
    "Son dos torres de piedra con una altura de unos tres pisos que forman la entrada "
    "de la ciudad de Zarkam. En ellas se aloja la guardia de soldados orcos que "
    "custodia la puerta. Ambas torres estan comunicadas por una pasarela. Al ser un "
    "lugar elevado son un buen sitio desde donde vigilar todo lo que ocurre en este "
    "valle.\n");

SetIntNoise("Se oye el ajetreo tipico de una ciudad.\n");
SetIntSmell("Hmm.. el aire es mas bien frio por la altura.\n");
SetLocate("ciudad de Zarkam");
SetIndoors(0);

AddExit("este",SF(ir_este));
AddExit("oeste",Z_CIUDAD("torre_06"));
}
