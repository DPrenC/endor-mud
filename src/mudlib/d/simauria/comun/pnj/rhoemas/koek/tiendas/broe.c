/***************************************************************************************
 ARCHIVO:	broe.c
 AUTOR:		[z] Zomax
 FECHA:		24-10-2001
 COMENTARIOS:	Broe, el hijo del carnicero.
 MODIFICACI�N:  20-04-2003 Ahora las respuestas solo se las da al player que pregunta.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit NPC;
#include RHOEDANYO

create(){
  ::create();
  SetStandard("Broe el beb�","humano",1,GENERO_MASCULINO);
  SetWhimpy(0);
  SetAlign(250);
  SetAggressive(0);
  SetName("Broe");
  SetIds(({"humano","broe","Broe"}));
  SetShort("Broe el beb�");
  SetLong(W("Broe es el hijo de Galonor y Mireba, los carniceros. Es tan "
  	"s�lo un beb� de pocos meses cubierto de pecas y con algo de pelo "
  	"muy, muy rojo. Tiene como �nica vestimenta unos pa�ales blancos de "
  	"tela bien sujetos para evitar posibles 'accidentes'. Parece un ni�o "
  	"muy sereno, no de los que lloran sin parar, y cuando no duerme observa "
  	"las cosas con curiosidad.\n"));
  AddSubDetail(({"peca","pecas","pelo"}),"Sin duda es hijo de Galonor.\n");
  AddQuestion(({"hambre","broe","Broe"}),"Broe balcucea: �Broe amvreeee! �broe amvreeee!.\n",1);
  AddQuestion(({"hermana","adwel","Adwel"}),"Broe balcucea: Adwel edmana.\n",1);
  AddQuestion(({"padre","papa","pap�","galonor","Galonor"}),"Broe balcucea: �appa... appa...!\n",1);
  AddQuestion(({"madre","mama","mam�","mireba","Mireba"}),"Broe balcucea: �amma! �amma!.\n",1);
  AddItem(RHOEARM("koek/varios/panyales"),REFRESH_REMOVE,SF(wearme));
}
