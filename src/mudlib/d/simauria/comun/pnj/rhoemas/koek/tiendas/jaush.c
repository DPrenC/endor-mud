/***************************************************************************************
 ARCHIVO:	jaush.c
 AUTOR:		[z] Zomax
 FECHA:		25-10-2001
 COMENTARIOS:	Jaush, el verdulero.
 MODIFICACI�N:  20-04-2003 Ahora las respuestas solo se las da al player que pregunta.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit NPC;
#include RHOEDANYO

create(){
  ::create();
  SetStandard("Jaush el verdulero","humano",10,GENERO_MASCULINO);
  SetWhimpy(0);
  SetAlign(250);
  SetAggressive(0);
  SetName("Jaush");
  SetIds(({"humano","jaush","Jaush","verdulero"}));
  Set(P_CANT_LURE,1);
  SetShort("Jaush el verdulero");
  SetLong(W("Jaush es un humano joven que tiene los ojos azules como el agua "
  	"del lago y la tez p�lida como la luna. Tiene un brillo especial en la "
  	"mirada, sobre todo cuando ve pasar a Felith, la frutera que tiene su "
  	"negocio enfrente de �l. Lleva un peque�o delantal para no mancharse "
  	"la ropa y el pelo peinado muy hacia atr�s para poder divisar mejor a "
  	"lo lejos a Felith.\n"));

  AddSubDetail(({"ojo","ojos"}),"Miras unos preciosos ojos azules.\n");
  AddQuestion(({"verduleria","verduler�a"}),W("Jaush te dice: Hace poco que abr�a la "
  	"verduler�a. Desde que encontr� un local libre para hacerlo, y qu� "
  	"mejor que este sitio.\n"),1);
  AddQuestion(({"frutera","felith","Felith"}),W("Jaush empieza a sudar por "
  	"momentos.\nJaush te dice: Felith es la frutera, tiene el puesto justo enfrente del "
  	"mio. La verdad es que parece una mujer excepcional, pero a�n no me "
  	"he atrevido a hablar con ella... no se c�mo hacerlo.\n"),1);
  AddQuestion(({"koek","Koek","pueblo","Pueblo","pueblo de koek","pueblo de Koek","Pueblo de koek","Pueblo de Koek"}),W(
	"Jaush te dice: Este sitio me gusta... vine desde Ishtria hace poco y cuando vi a "
	"la gente y el lugar me qued� para fundar este negocio.\n"),1);
  AddQuestion(({"cylin","Cylin","bosque","Bosque","bosque de cylin","Bosque de cylin","bosque de Cylin","Bosque de Cylin"}),W(
	"Jaush te dice: He o�do historias horribles sobre �l... pero a�n no se ni donde est�.\n"),1);
  AddQuestion(({"historia","historias"}),W(
	"Jaush te dice: Pues... he o�do historias como que el hijo del pescadero y su mujer "
	"desaparecieron antes de llegar yo a Koek, hace poco m�s de un a�o.\n"),1);
  AddQuestion(({"templo","Templo","Seri-Solderteg"}),W("Jaush te dice: A�n no lo he visitado, "
  	"pero me han dicho que es muy bonito.\n"),1);
  AddQuestion(({"horario","abierto","cerrado","abrir","cerrar"}),W("Jaush te dice: Abro la "
  	"verduler�a de 8 a 21 ininterrumpidamente.\n"),1);
  AddItem(RHOEARM("koek/varios/delantal"),REFRESH_REMOVE,SF(wearme));
  InitChats(5,({"Jaush suspira: Oh... se le ve tan bella e inalcanzable...\n",
  		"Jaush dice: �Qu� deseas?\n",
		"Jaush dice: Si se dignara a hablar conmigo.\n"}));
}
