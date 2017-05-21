/****************************************************************************
Fichero: despensa.c
Autor: Ratwor
Fecha: 01/01/2008
Descripci�n: La despensa del castillo.
****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;

create(){
    ::create();
    SetIntBright(25);
    SetIntShort("la despensa");
    SetIntLong("�sta es la despensa del castillo donde se amontonan toda clase de "
    "v�beres. De unas varas cuelgan largas ristras de embutidos junto a una docena de "
    "jamones y paletillas ahumadas. Sacos llenos de patatas, cebollas y toda clase de "
    "tub�rculos se ordenan en las paredes junto con algunas tinajas de valioso aceite "
    "tra�do del sur. De  ganchos clavados al muro cuelgan algunos animales "
    "despellejados y abiertos en canal, listos para ser trasladados a la cocina.\n");
    AddDetail("embutidos", "Chorizos, morcillas y toda clase de embutidos.\n");
    AddDetail("tinajas", "Tinajas de barro llenas de aceite.\n");
    AddDetail("animales", "Varios conejos, dos jabal�es y algo que parece un venado o un "
    "corzo.\n");
    AddExit("norte", "./zona_servidumbre1");
    SetLocate("el castillo de Nandor");

}
