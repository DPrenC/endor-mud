/*=============================================================*
 |           << GOLDHAI.Crowy [w] Woo@simauria >>              |
 *=============================================================*
 |              Creacion............. 02-02-99                 |
 |              Ultima Modificacion...02-07-00                 |
 |                                                             |
 *=============================================================*/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>


inherit ARMOUR;

create() {
 ::create();
 SetStandard(AT_RING,0,P_SIZE_GENERIC);
 SetShort("el anillo de frobbon");
 SetLong("\
Estas mirando un magnífico anillo de oro adornado con decenas de diminutas\n\
piedras preciosas de todos los colores inimaginables. Tiene grabada una\n\
pequeña inscripción que dice: 'Para mi amado Frobbon'.\n");
 SetIds(({"anillo","anillo de frobbon"}));
 SetValue(100000); // Es muy caro.. pero invendible.
 SetWeight(20);
 Set(P_NOGET, "El anillo se te escurre y se cae.\n");
// SetNoDrop("Es un anillo muy importante como para dejarlo en cualquier lado.\n");
 Set(P_NOGIVE, "Este anillo es de Frobbon, no pretenderás dárselo a cualquiera, ¿verdad?\n");
 Set(P_NOSELL,"Es demasiado valioso para poder venderlo sin levantar sospechas.\n");
 Set(P_GENDER,GENERO_FEMENINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
}
