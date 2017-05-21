/*
DESCRIPCION  : final de una galeria de la mina
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/mina/fin00.c
MODIFICACION : 05-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;

create()
{
    ::create();
    SetIntShort("el fin de una galería de la mina");
    SetIntLong("Sigues ascendiendo por el pozo hasta que éste acaba bruscamente frente a una inmensa roca. Quizá los "
        "mineros decidieron dejar de excavar aquí, dada la dureza de la roca o tal vez por que se acabó la veta de mineral "
        "que iban siguiendo.\n");
    AddDetail(({"pozo","final"}), QueryIntLong());
    AddDetail(({"roca"}),"La roca que bloquea el ascenso del pozo es un bloque macizo de basalto. La roca es mas ancha que "
        "el agujero del pozo y en ella se aprecian marcas de intentos por partirla.\n");
    SetIntNoise("Oyes el eco de tus pasos y el goteo del agua.\n");
    SetIntSmell("Huele a tierra mojada.\n");
    SetLocate("mina de isla Limbo");
    SetIndoors(1);
    SetIntBright(0);
    AddExit("abajo",MINA("cruce03"));
    AddItem(OTRO("cristal"), REFRESH_DESTRUCT, 1);
}
