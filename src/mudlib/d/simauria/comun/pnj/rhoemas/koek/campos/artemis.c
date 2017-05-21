/***************************************************************************************
 ARCHIVO:	artemis.c
 AUTOR:		[z] Zomax
 FECHA:		24-04-2003
 COMENTARIOS:	Artemis el pinto de paisajes.
 ***************************************************************************************/

#include "path.h"
#include <moving.h>
#include <properties.h>

inherit NPC;

public string ftinte()
{
	mapping quest=TP->QueryAttribute("DraegoQuest");

	if (quest && member(quest,"tunica") && quest["tunica",0]==5)
	{
		quest+=(["tunica":6]);
		clone_object(RHOEVAR("koek/varios/tinte_azul"))->move(TP,M_SILENT);
		return W("Artemis te dice: �Tinte en polvo? Si, me queda algo, de hecho "
		"bastante... podr�a d�rtelo pero no tengo el color que me pides, s�lo tengo "
		"az�l, toma, a ver si te sirve...\nArtemis te da tinte en polvo az�l.\n");
	}
	else if (quest && member(quest,"tunica") && quest["tunica",0]>5)
	{
		return W("Artemis te dice: No me queda, lo siento, necesito el poco "
		"que tengo.\n");
	}
	else return "Artemis se encoge de hombros.\n";
}

create(){
  ::create();
  SetStandard("Artemis","humano",15,GENERO_MASCULINO);
  SetWhimpy(0);
  SetAlign(250);
  SetAggressive(0);
  SetName("Artemis");
  SetIds(({"humano","artemis","Artemis","pintor"}));
  SetShort("Artemis el pintor");
  SetLong(W("Artemis es un pintor un tanto bohemio con una puntiaguda barba algo recortada que "
  	"y mirada exc�ntrica. Se mueve a espavientos, del mismo modo que da pinceladas a sus "
  	"cuadros que por cierto dejan bastante que desear. Es un incomprendido.\n"));
  InitChats(5,({"Artemis fija su mirada en el paisaje.\n",
  		"Artemis da un par de pinceladas al aire.\n",
		"Artemis dice: �As� no se puede pintar en condiciones!.\n",
		"Artemis se dice a si mismo: Si pongo aqu� un par de l�neas y aqu�...\n"}));
  AddQuestion(({"tinte"}),SF(ftinte),1);
  AddQuestion(({"paisaje","campos","koek"}),W("Artemis te dice: Es un paisaje maravilloso, "
  	"l�stima que a veces se me vaya la inspiraci�n, pero aqu� me salen cuadros de verdadero "
  	"maestro.\n"),1);
}
