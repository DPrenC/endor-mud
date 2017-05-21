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
"la seguridad dentro del castillo\n");
SetIds(({"guardian","humano"}));
AddQuestion("lios","El Guardían te dice: si armas jaleo en el castillo te encerrare.\n");
InitChats(15,"El guardían dice: No te metas en lios.\n");
SetAggressive(0);
SetAlign(100);
SetSize(P_SIZE_MEDIUM);
SetAC(20);
AddItem(ARMA("espada"),REFRESH_REMOVE,SF(wieldme));
AddItem(ARMA("espada"),REFRESH_REMOVE,SF(wieldme));
// Si no funciona se quita el resto y lo cargamos con //
// AddItem(ARMA_IS("coraza"),REFRESH_REMOVE,SF(wearme))//
AddItem(ARMOUR, REFRESH_REMOVE,
    ([P_SHORT:"una cota de malla",
      P_LONG:
"Es una cota de malla de metal. Esta diseñada para que cubra la mayor\n"
"parte del cuerpo y asi protegerte mejor de los golpes.\n",
      P_IDS:({"cota","placa","malla","cota de malla"}),
      P_VALUE:750,
      P_WEIGHT:22700,
      P_AC:12,
      P_SIZE:P_SIZE_MEDIUM,
      P_MATERIAL:M_ACERO,
      P_ARMOUR_TYPE:AT_MAIL]),SF(wearme));
}