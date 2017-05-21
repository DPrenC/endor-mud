/***************************************************************************************
 ARCHIVO:	severaw.c
 AUTOR:		[z] Zomax
 FECHA:		18-12-2001
 COMENTARIOS:	Severaw, un pescador.
 MODIFICACIÓN:  20-04-2003 Ahora las respuestas solo se las da al player que pregunta.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit NPC;
#include RHOEDANYO

create(){
  ::create();
  SetStandard("Severaw el pescador","humano",10,GENERO_MASCULINO);
  SetWhimpy(10);
  SetAlign(50);
  SetAggressive(0);
  SetName("Severaw");
  SetIds(({"humano","severaw","Severaw","pescador"}));
  SetShort("Severaw el pescador");
  SetLong(W("Severaw es la típica imagen del pescador que exagera hasta el "
  	"grosor de una aguja comparándola con el pilar de una casa. Tiene la "
  	"cara curtida por el sol y una barba blanca muy espesa. Suele andar "
  	"acompañado por la taberna del pescador, aunque alguna vez se le "
  	"ve pescando en el muelle.\n"));
  AddQuestion(({"concurso","concurso de pesca"}),W("Severaw te dice: En la "
  	"cofradía, el concurso es en la cofradía, cerca del muelle.\n"),1);
}
