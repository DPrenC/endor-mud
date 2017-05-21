/***************************************************************************************
 ARCHIVO:	felith.c
 AUTOR:		[z] Zomax
 FECHA:		25-10-2001
 COMENTARIOS:	Felith, la frutera.
 MODIFICACIÓN:  20-04-2003 Ahora las respuestas solo se las da al player que pregunta.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit NPC;
#include RHOEDANYO

create(){
  ::create();
  SetStandard("Felith la frutera","humano",10,GENERO_FEMENINO);
  SetWhimpy(0);
  SetAlign(250);
  SetAggressive(0);
  SetName("Felith");
  SetIds(({"humana","felith","Felith","frutera"}));
  Set(P_CANT_LURE,1);
  SetShort("Felith la frutera");
  SetLong(W("Felith es una joven muy bella de aspecto frágil pero aguda "
  	"inteligencia que se ocupa de la frutería. Lleva un pequeño delantal "
  	"para no ensuciarse y una pequeña pulsera en la muñeca que brilla como "
  	"el reflejo del sol en el agua del lago. Tiene además la costumbre de "
  	"salir a la calle muy a menudo cuando no tiene clientela.\n"));

  AddQuestion(({"fruteria","frutería"}),W("Felith te dice: Tengo esta frutería desde hace "
  	"bastante tiempo, pero ya me estaba cansando de ella, hasta que "
  	"llegó el jóven tan apuesto de la verdulería justo enfrente de aquí. "
  	"Desde entonces cuando me aburro salgo a la calle para verle trabajar. "
  	"Espero que se decida pronto a hablar conmigo, porque estoy apunto de "
  	"tirarme a sus brazos.\n"),1);
  AddQuestion(({"verdulero","jaush","Jaush","joven","jóven","joven apuesto","jóven apuesto"}),W(
	"Felith te dice: Ah... Jaush es el chico más apuesto del lugar... y está soltero... "
	"creo que le gusto, porque le he pillado varias veces observándome y "
	"se ha sonrrojado, pero nunca dice nada... quizás sea porque es muy "
	"tímido... voy a tener que dar yo el primer paso.\n"),1);
  AddQuestion(({"koek","Koek","pueblo","Pueblo","pueblo de koek","pueblo de Koek","Pueblo de koek","Pueblo de Koek"}),W(
	"Felith te dice: Koek es todo lo que he conocido, pero nunca me canso de él.\n"),1);
  AddQuestion(({"cylin","Cylin","bosque","Bosque","bosque de cylin","Bosque de cylin","bosque de Cylin","Bosque de Cylin"}),W(
	"Felith te dice: Um... un sitio tenebroso... no te aconsejo que entres.\n"),1);
  AddQuestion(({"templo","Templo","Seri-Solderteg"}),W(
	"Felith te dice: El templo nos protege y nos proporciona visitantes que dejan sus "
	"ahorros en Koek, así que me parece de lo más bien.\n"),1);
  AddQuestion(({"horario","abierto","cerrado","abrir","cerrar"}),W(
	"Felith te dice: Suelo encargarme de la frutería de 8 a 21.\n"),1);
  AddItem(RHOEARM("koek/varios/delantal"),2,SF(wearme));
  InitChats(5,({"Felith suspira: ¿Es que nunca se atreverá a venir?.\n",
  		"Felith dice: ¿Te puedo ayudar?\n",
		"Felith tiene la mirada perdida hacia la verdulería.\n"}));
}
