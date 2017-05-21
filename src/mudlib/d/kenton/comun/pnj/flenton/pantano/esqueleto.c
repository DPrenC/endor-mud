/***************************************************************************************
 ARCHIVO:	esqueleto.c
 AUTOR:		[k] Korsario
 FECHA:		13-11-1998
 COMENTARIOS:	Un esqueleto
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit NPC;

create(){
  ::create();
  SetStandard("un esqueleto guerrero","esqueleto",15,GENERO_MASCULINO);
  SetHands(({({"su mano derecha",0,10}),({"su mano izquierda",0,10})}));
  SetIds(({"esqueleto","muerto","nomuerto"}));
  SetAggressive(1);
  SetAlign(-100);
  SetWhimpy(0);

  SetShort("un esqueleto guerrero");
  SetLong(W("Ves un esqueleto viviente. Los restos de lo que en su dia fue un gran "
  	"guerrero que como tú llegó aquí buscando aventura, pero solo encontró su "
  	"propia muerte.\n"));

  AddItem(FLENARM+"espada_esqueleto",REFRESH_REMOVE,SF(wieldme));
  AddItem(FLENPRT+"escudo_esqueleto",REFRESH_REMOVE,SF(wearme));
}
