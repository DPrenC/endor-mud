/* ******************************************************
   *                                                    *
   *  Archivo:      amuletozaf.c                        *
   *  Autor:        [a] Articman                        *
   *  Descripción:  Objeto para dar vida a la gargola.  *
   *                Se consigue ayudando al historiador.*
   *  Modificación: 31/01/02 [a] Creación               *
   ******************************************************  */




#include <properties.h>
#include <materials.h>
#include <combat.h>

#include "path.h"
inherit ARMOUR;
inherit ROOM;


create() {

::create();
SetStandard(AT_AMULETO,0,P_SIZE_GENERIC,M_ORO);
SetIds(({"amuleto","amuleto de zafiro","amuleto zafiro","q_amuleto_gargola"}));

SetShort("un amuleto de zafiro");

SetLong(W("Es un amuleto de oro de forma romboidal con "
"un bello zafiro redondo en el centro. Tiene una cadena "
"también de oro.\n"));

Set(P_GENDER,GENERO_MASCULINO);

Set(P_NUMBER,NUMERO_SINGULAR);

SetWeight(100);
Set(P_NOSELL,1);

}
