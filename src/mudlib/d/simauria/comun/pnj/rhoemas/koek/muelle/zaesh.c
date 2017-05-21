/***************************************************************************************
 ARCHIVO:	zaesh.c
 AUTOR:		[z] Zomax
 FECHA:		25-10-2001
 COMENTARIOS:	Zaesh, el nieto del pescador.
 MODIFICACI�N:  20-04-2003 Ahora las respuestas solo se las da al player que pregunta.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit NPC;
#include RHOEDANYO

create(){
  ::create();
  SetStandard("Zaesh, el nieto del pescador","humano",5,GENERO_MASCULINO);
  SetWhimpy(0);
  SetAlign(250);
  SetAggressive(0);
  SetName("Zaesh");
  SetIds(({"humano","zaesh","Zaesh"}));
  SetShort("Zaesh, el nieto del pescador");
  SetLong(W("Zaesh es un muchacho muy joven, de unos diez a�os con el pelo "
  	"casta�o y mirada perdida pero que est� siempre pendiente de lo que "
  	"dice su abuelo. Tiene una peque�a navaja con la que arregla las redes "
  	"y el hilo de pescar cuando se enredan. Parece muy sereno, sin duda una "
  	"cualidad que le da mucha ventaja a la hora de pescar\n"));

  AddQuestion(({"padres","padre","madre","sia","Sia","valemar","Valemar"}),W(
	"Zaesh te dice: Mis padres est�n de viaje, por eso estoy viviendo con mis abuelos "
	"ahora. Aqu� me lo paso muy bien, pero tengo ganas de que vuelvan pronto.\n"),1);
  AddQuestion(({"abuelo","abuelos","Froeker","froeker","kaewin","Kaewin"}),W(
	"Zaesh te dice: Mis abuelos son Froeker y Kaewin. Son muy buenos conmigo... pero "
	"echo de menos a mis padres.\n"),1);
  AddQuestion(({"concurso","concurso de pesca"}),W("Zaesh te dice: Hay un concurso permanentemente "
  	"en la cofrad�a de pescadores. S�lo tienes que pescar un pez mayor que el que "
  	"la cofrad�a de pescadores tiene registrado como m�s pesado para recibir el "
  	"premio. Procura pescar s�lo peces, nada de armas ni otras cosas.\n"),1);
  AddQuestion(({"koek","Koek","pueblo","Pueblo","pueblo de koek","pueblo de Koek","Pueblo de koek","Pueblo de Koek"}),W(
	"Zaesh te dice: Lo que m�s me gusta de Koek es el lago... es precioso, sobre todo "
	"por la noche, cuando refleja la luz de la luna.\n"),1);
  AddQuestion(({"cylin","Cylin","bosque","Bosque","bosque de cylin","Bosque de cylin","bosque de Cylin","Bosque de Cylin"}),W(
	"Zaesh te dice: Nunca lo he visto, as� que no se que decirte de �l.\n"),1);
  AddQuestion(({"templo","Templo","Seri-Solderteg"}),W("Zaesh te dice: Yo s�lo he ido una vez "
  	"al templo... a rezar, hace un a�o o as�... pero me pareci� muy bonito todo.\n"),1);

  AddItem(RHOEWEA("koek/varios/navaja"),REFRESH_REMOVE,SF(wieldme));
}
