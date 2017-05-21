/*
DESCRIPCION : (tipo) parte de arriba de una torre del castillo
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/castillo/torre_t0.c
MODIFICACION: 26-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

int guardias;  //numero de guardias sobre la torre

create() {
 ::create();
 SetPreIntShort("sobre");
 SetIntShort("una torre");
 SetIntLong(
    "Estas en la parte superior de una de las torres del castillo. Desde aqui arriba "
    "puedes divisar claramente la ciudad y la mayor parte del valle al otro lado de "
    "las gruesas almenas que protegen la torre. Hay varios altos postes en los que "
    "el viento hace flamear las alargadas banderas negras simbolo del imperio orco. "
    "Una trampilla de madera permite bajar a pisos inferiores.\n");

 AddDetail(({"poste","postes","bandera","banderas"}),
    "Junto a las almenas de la torre hay varios postes altos y delgados cuya funcion "
    "es la de ser los mastiles de otras tantas alargadas banderas negras, los "
    "simbolos que identifican al imperio orco.\n");

 AddDetail(({"almena","almenas"}),
    "Las almenas son unos bloques de piedra que coronan los muros de la torre. Su "
    "funcion es la de proteger a los defensores de la fortificacion, a la vez que los "
    "huecos entre ellas les permiten atacar.\n");

AddDetail(({"torre","torres"}),QueryIntLong());

if (guardias!=0) AddItem(PNJ("z_castillo/vigia"), REFRESH_DESTRUCT, guardias);

SetIntNoise("El viento sopla frio con fuerza agitando las banderas.\n");
SetIntSmell("Hmm.. el aire es mas bien frio por la altura.\n");
SetLocate("castillo de Zarkam");
SetIndoors(0);
}
