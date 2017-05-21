/* ******************************************************
   *                                                    *
   *  Archivo:      anilloorof.c                        *
   *  Autor:        [a] Articman                        *
   *  Descripción:  Vendible                            *
   *  Modificación: 31/01/02 [a] Creación               *
                    07/03/02 [n] Yo te peto... ¿como le *
                                 haces heredar el ROOM?
*/




#include <properties.h>
#include <materials.h>
#include <combat.h>

#include "path.h"
inherit ARMOUR;


create() {

::create();
SetStandard(AT_ANILLO,0,P_SIZE_GENERIC,M_ORO);
SetIds(({"anillo","anillo oro","anillo de oro"}));

SetShort("un anillo de oro");

SetLong("Es un anillo de oro. Parece tener bastante valor.\n");

Set(P_GENDER,GENERO_MASCULINO);

Set(P_NUMBER,NUMERO_SINGULAR);

SetWeight(100);
SetValue(10000);
}
