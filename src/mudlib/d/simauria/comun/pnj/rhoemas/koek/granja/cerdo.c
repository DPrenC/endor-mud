/***************************************************************************************
 ARCHIVO:	cerdo.c
 AUTOR:		[z] Zomax
 FECHA:		24-12-2001	¡Feliz Nochebuena!
 COMENTARIOS:	Un cerdo
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit NPC;

create(){
  ::create();
  SetStandard("un cerdo","cerdo",5+random(5),GENERO_MASCULINO);
  SetIds(({"cerdo"}));
  SetLong(W("Es un cerdo. Tiene el hocico manchado de barro y la verdad es "
  	"que casi todo el cuerpo también. Aún así te parece simpático.\n"));
  AddSubDetail(({"hocico","barro"}),W("Sin duda es un poco cerdo. Tiene el "
  	"hocico absolutamente lleno de barro.\n"));
  SetSize(2);
  SetWhimpy(0);
  SetAlign(250);
  SetAggressive(0);
  SetHands(({({"una pata",1,6}),({"una pata",1,6}),({"el hocico",1,8})}));
}
