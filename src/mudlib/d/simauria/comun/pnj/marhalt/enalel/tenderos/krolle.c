/*****************************************************************************
 AUTOR:		[t] Tyflos
 DETALLES:	PNJ de Enalel
 *****************************************************************************/

#include "path.h"
#include <properties.h>

inherit ENALPNJ"base";

create(){
  ::create();
 
  SetStandard("Krolle","medioelfo",10+random(3),GENERO_MASCULINO);
  SetShort("Krolle el herrero");
  SetLong(W("Es un fornido semielfo de alta estatura. Su fornido cuerpo está "
  "siempre en tensión para hacer las mejores piezas de herrería de la zona.\n"));
  SetIds(({"medioelfo","medio elfo","semielfo","semi elfo","Krolle","herrero","krolle"}));
  Set(P_CANT_LURE,1);
  SetAlign(300);
  SetStr(QueryStr()+6);
  SetCon(QueryCon()+3);
  InitChats(5,({
  	"Krolle golpea con fuerza el yunque.\n",
	"Krolle sujeta con las pinzas una pieza de metal que está forjando.\n",
	"Krolle sumerje en el agua una pieza incandescente.\n",
	"Krolle Saca una pieza de metal y comienza a trabajarla.\n",
	"Krolle te mira y te pregunta: ¿quieres algo?"}));
}
