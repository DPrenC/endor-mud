/*
DESCRIPCION  : final de una galeria de la mina (modelo)
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/mina/fin_a.c
MODIFICACION : 05-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;

create()
{
    ::create();
    SetIntShort("el fin de una galer�a de la mina");
    SetIntLong("La galer�a acaba aqu�. Por alguna raz�n los mineros decidieron dejar de excavar en esta galer�a, "
        "posiblemente al no encontrar la veta que buscaban o porque otra galer�a resultaba m�s productiva. Hay un mont�n de "
        "piedras de distintos tama�os en el lugar donde se dej� de excavar. El suelo est� mojado por el agua subterr�nea "
        "que gotea desde el techo.\n");
    AddDetail(({"galeria","final"}), QueryIntLong());
    AddDetail(({"piedra","piedras"}),"Son las piedras que se desprenden al excavar la galer�a y que han de llevarse al "
        "lavadero que hay en el exterior de la mina para ver si contienen alg�n mineral de valor. Como se dej� de excavar "
        "esta galer�a, nadie se molest� en llevarlas al lavadero.\n");
    SetIntNoise("Oyes el eco de tus pasos y el goteo del agua.\n");
    SetIntSmell("Huele a tierra mojada.\n");
    SetLocate("mina de isla Limbo");
    SetIndoors(1);
    SetIntBright(0);
}
