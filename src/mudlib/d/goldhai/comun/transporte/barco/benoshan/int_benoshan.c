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
    SetIntLong("Est�s en la cubierta del Benoshan, un bargo bastante ruinoso que, "
        "mientras no se halla repar�ndose en tierra, intenta llevar a gente de unos "
        "sitios a otros. Las defensas del barco no es que sean muy buenas, pero la "
        "tripulaci�n sabe que nadie se atrever�a a abordarlos en alta mar ya que s�lo "
        "gente sin dinero y necesitada se atrever�a a viajar en esta cascarria.\n");
    AddDetail(({"tripulaci�n", "tripulacion"}), "La verdad es que no se sabe muy bien de "
        "donde han salido, seguramente ser�n piratas y asesinos de poca monta.\n");
    SetIndoors(0); // [w] No es un camarote
}
