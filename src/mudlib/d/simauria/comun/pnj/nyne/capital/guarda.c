/*
DESCRIPCION : guardian tocho para el Castillo de Simauria
FICHERO     : guarda.c
MODIFICACION: 8-06-01 [Tirdos] Creacion
--------------------------------------------------------------------------------
*/

#include <properties.h>
#include <rooms.h>
#include <combat.h>
#include "./path.h"
#include <gremios.h>

inherit NPC;


create() {
::create();
SetStandard("Guardian","humano",([GC_LUCHADOR: 43+ random(5)]),GENERO_MASCULINO);
SetShort("El Guardian");
SetMaxHP(1800);
SetHP(1800);
SetLong("Ante ti puedes ver a uno de los poderosos guardianes de Simauria. Dicen que\n"
"forman parte de uno de los cuerpos de elite que obedece solo al rey y velan por\n"
"la seguridad de la ciudad y sus habitante\n");
SetIds(({"guardian","humano"}));
AddQuestion("lios","El Guardían te dice: si armas jaleo en el castillo te encerrare.\n");
InitChats(15,"El guardían dice: No te metas en lios.\n");
SetAggressive(0);
SetAlign(100);
SetSize(P_SIZE_MEDIUM);
SetAC(20);
AddItem(ARMA("espada"),REFRESH_REMOVE,SF(wieldme));
AddItem(ARMA("espada"),REFRESH_REMOVE,SF(wieldme));
AddItem(ARMA("coraza"),REFRESH_REMOVE,SF(wearme));
}