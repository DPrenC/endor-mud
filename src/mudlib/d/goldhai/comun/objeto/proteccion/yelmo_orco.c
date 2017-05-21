/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 05-10-98                |
 |               Ultima Modificacion.. 21-02-99                |
 |                                                             |
 *=============================================================*/

#include <combat.h>
#include <properties.h>
#include <materials.h>
#include "path.h"

inherit ARMOUR;

create()
{
 ::create();
 SetStandard(AT_HELMET,1,P_SIZE_MEDIUM,M_HIERRO);
 SetWeight(1000);
 SetShort("un yelmo orco");
 SetIds(({"yelmo","yelmo orco"}));
 SetValue(1000);
 Set(P_GENDER,GENERO_MASCULINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 SetLong("\
Es un t�pico yelmo orco de metal. Esta dise�ado para que cubra la mayor\n\
parte del rostro y as� protegerte mejor de los golpes.\n");
}

