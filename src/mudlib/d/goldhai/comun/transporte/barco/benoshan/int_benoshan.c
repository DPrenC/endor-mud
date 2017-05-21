/*=============================================================*
 |           << GOLDHAI.Barcos [w] Woo@simauria >>             |
 *=============================================================*
 |              Creacion............. 28-10-98                 |
 |              Ultima Modificacion.. 28-10-98                 |
 |                                                             |
 *=============================================================*/

#include "./path.h"

inherit ROOM;

public void create()
{
    ::create();

    SetIntShort("el Benoshan");
    SetIntLong("Estás en la cubierta del Benoshan, un bargo bastante ruinoso que, "
        "mientras no se halla reparándose en tierra, intenta llevar a gente de unos "
        "sitios a otros. Las defensas del barco no es que sean muy buenas, pero la "
        "tripulación sabe que nadie se atrevería a abordarlos en alta mar ya que sólo "
        "gente sin dinero y necesitada se atrevería a viajar en esta cascarria.\n");
    AddDetail(({"tripulación", "tripulacion"}), "La verdad es que no se sabe muy bien de "
        "donde han salido, seguramente serán piratas y asesinos de poca monta.\n");
    SetIndoors(0); // [w] No es un camarote
}
