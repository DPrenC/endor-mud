/***************************************************************************************
 ARCHIVO:	yarkol.c
 AUTOR:		[z] Zomax
 FECHA:		20-12-2001
 COMENTARIOS:	Yarkol, el alcalde del pueblo
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit NPC;
#include RHOEDANYO

create(){
  ::create();
  SetStandard("Yarkol el conductor","humano",6,GENERO_MASCULINO);
  SetWhimpy(0);
  SetAlign(250);
  SetAggressive(0);
  SetName("Yarkol");
  SetIds(({"humano","yarkol","Yarkol","conductor"}));
  SetShort("Yarkol el conductor");
  SetLong(W("Yarkol es el conductor de la diligencia que lleva desde Ishtria hasta "
  	"Koek, pasando por Berat.\n"));
}
