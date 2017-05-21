/*=============================================================*
 |           << GOLDHAI.Barcos [w] Woo@simauria >>             |
 *=============================================================*
 |              Creacion............. 23-08-98                 |
 |              Ultima Modificacion.. 23-08-98                 |
 |                                                             |
 *=============================================================*/

#include "./path.h"

inherit ROOM;

public void create()
{
    ::create();

    SetIntShort("el Sothkorn");
    SetIntLong("Te encuentras en el Sothkorn, uno de los peores barcos que ha navegado "
        "por estos mares. El color rojo intenso de su casco intenta disimular sus "
        "grietas que le hace visible a muchas millas de distancia. La tripulación "
        "intenta pasar el tiempo libre de la mejor forma posible.\n");
    AddDetail(({"tripulación", "tripulacion"}), "Está compuesta principalmente de elfos "
        "ataviados con las vestimentas más sucias que jamás hayas visto.\n");
    SetIndoors(0); // [w] No es un camarote
}
