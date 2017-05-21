/*=============================================================*
 |           << GOLDHAI.Barcos [w] Woo@simauria >>             |
 *=============================================================*
 |              Creacion............. 24-02-99                 |
 |              Ultima Modificacion.. 24-02-99                 |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit GROOM;

public create()
{
 ::create();
 SetIntShort("el bote fantasma");
 SetIntLong("Estás sentado en uno de los tablones que atraviesan el bote de "
            "lado a lado. Todo se mueve mucho y parece que en cualquier "
            "momento te vayas a ir al agua, pero inesplicablemente este bote "
            "sucio y viejo flota de maravilla. Lo que más te intriga es que "
            "carezca de tripulación.\n");

 AddDetail(({"bote", "bote fantasma"}), QueryIntLong());

 SetIndoors(0); // [w] No es un camarote
}
