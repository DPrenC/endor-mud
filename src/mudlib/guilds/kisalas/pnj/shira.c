/****************************************************************************
Fichero: shira.c
Autor: Riberales
Fecha: 15/02/2006
Descripci�n: Shira, la tabernera del Gremio.
****************************************************************************/

#include "path.h"
#include <guild.h>


inherit NPC;

create()
{
    ::create();
    SetStandard("shira","humano",([GC_KISALAS: 25]),GENERO_FEMENINO);
    AddId(({"kisala","humana"}));
    SetShort("shira la joven");
    SetLong("Shira es una joven humana de ojos verdes y una larga y negra "
            "cabellera, que recoge en un par de graciosas trenzas. Su mirada "
            "te hace pensar que es una mujer muy dulce, pero muy segura de s� "
            "misma. Adem�s, la ligereza en sus movimientos seguro que hacen "
            "de esta Kisala una gran combatiente.\n");

    SetIds(({"shira","Shira","kisala","tabernera","humana","joven"}));

    InitChats(3,({
              "Shira te sonr�e.\n",
              "Shira se pone a limpiar la ya inmaculada barra.\n"}));
}
