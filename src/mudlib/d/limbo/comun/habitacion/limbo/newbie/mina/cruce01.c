/*
DESCRIPCION  : cruce entre galerias
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/mina/cruce01.c
MODIFICACION : 05-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;

create()
{
    ::create();
    SetIntShort("un cruce entre galer�as");
    SetIntLong("Has llegado a un cruce. En este punto coinciden varias de las galer�as de este nivel de la mina. Adem�s, "
        "sobre tu cabeza se alza un agujero oscuro cuya altura no adivinas y que parece ser uno de los pozos de esta mina. "
        "Una escalera fijada en la pared del pozo y que baja hasta el suelo de la galer�a permite ascender por �l.\n");
    AddDetail(({"cruce"}), QueryIntLong());
    AddDetail(({"escalera"}),"Una larga escalera de madera est� fijada firmemente a la pared del pozo. Permite subir por "
        "�l.\n");
    AddDetail(({"pozo"}),"Sobre este cruce de galer�as no hay techo, sino un agujero oscuro en la roca. Es uno de los "
        "pozos excavados en esta mina para llegar de unos niveles a otros.\n");
    SetIntNoise("Oyes el eco de tus pasos y el goteo del agua.\n");
    SetIntSmell("Huele a tierra mojada.\n");
    SetLocate("mina de isla Limbo");
    SetIndoors(1);
    SetIntBright(0);
    AddExit("este",MINA("cruce00"));
    AddExit("sur",MINA("cruce02"));
    AddExit("arriba",MINA("pozo18"));
    AddItem(PNJ("osezno"), REFRESH_DESTRUCT, 1);
}
