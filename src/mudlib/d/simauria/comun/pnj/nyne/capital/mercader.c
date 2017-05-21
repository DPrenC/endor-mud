/*
DESCRIPCION : mercader (clavaito al de Maler)
FICHERO     : mercader.c
MODIFICACION: 11-06-01 [Tirdos] Creacion
--------------------------------------------------------------------------------
*/
#include "./path.h"
inherit NPC;
#include <properties.h>
#include <combat.h>
#include <rooms.h>
create ()
{
  ::create();
seteuid(getuid());
SetStandard("un mercader","humano",23+random(5),GENERO_MASCULINO);
SetShort("un mercader");
SetLong(("Es un mercader humano, todo te hace pensar que se trata de un individuo"
"avispado debes tener cuidado si haces tratos con el, parece capaz de venderle "
"unas gafas a un ciego.\n"));
SetIds(({"humano","mercader"}));
SetAggressive(0);
SetAlign(75);
SetSize(P_SIZE_MEDIUM);
SetAC(10);
InitChats(3,"El mercader te mira y dice: 'Eres nuevo en la ciudad?'.\n");
AddItem(ARMA("daga"),REFRESH_NONE,SF(wieldme));
}