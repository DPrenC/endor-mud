/***************************************************************************************
 ARCHIVO:	kaewin.c
 AUTOR:		[z] Zomax
 FECHA:		25-10-2001
 COMENTARIOS:	Kaewin, la pescadera.
 MODIFICACI�N:  20-04-2003 Ahora las respuestas solo se las da al player que pregunta.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit NPC;
#include RHOEDANYO

create(){
  ::create();
  SetStandard("Kaewin la pescadera","humano",10,GENERO_FEMENINO);
  SetWhimpy(0);
  SetAlign(250);
  SetAggressive(0);
  SetName("Kaewin");
  SetIds(({"humana","kaewin","Kaewin","pescadera"}));
  Set(P_CANT_LURE,1);
  SetShort("Kaewin la pescadera");
  SetLong(W("Kaewin es la encargada de la pescader�a, una mujer mayor con el "
  	"pelo blanco y de mirada un tanto triste, aunque la disimula al "
  	"vender, como buena comerciante, pero cuando la ves sin clientela "
  	"se le ve muy melanc�lica. Tiene la cara llena de arrugas y los ojos "
  	"algo enrrojecidos, puede que de llorar.\n"));

  AddSubDetail(({"arruga","arrugas"}),W("Parece que ya le van a acompa�ar por el "
  	"resto de sus d�as.\n"));
  AddSubDetail(({"ojo","ojos"}),W("Tiene los ojos enrojecidos, como si llorara "
  	"cada d�as varias veces.\n"));
  AddQuestion(({"percaderia","pescader�a"}),W("Kaewin te dice: En la pescader�a vendo el "
  	"pescado que mi marido trae del lago. No es que sea una mina de oro, "
  	"pero hasta ahora nos ha dado para vivir y criar a nuestra familia.\n"),1);
  AddQuestion(({"hijo","vaemar","Vaemar"}),W("Kaewin te dice: Estoy muy preocupada por �l... "
  	"si tan s�lo supiera d�nde est� y c�mo se encuentra... quiero volver a "
  	"abrazarle.\n"),1);
  AddQuestion(({"marido","esposo","froeker","Froeker"}),W("Kaewin te dice: Froeker es mi marido. "
  	"Toda la vida ha sido pescador y desde que se hizo demasiado viejo como para "
  	"salir en la barca se dedica a pescar en el muelle y regentar la cofrad�a "
  	"de pescadores, cerca del muelle. Incluso organiza concursos de pesca.\n"),1);
  AddQuestion(({"concurso","concurso de pesca"}),W("Kaewin te dice: Hay un concurso permanentemente "
  	"en la cofrad�a de pescadores. S�lo tienes que pescar un pez mayor que el que "
  	"la cofrad�a de pescadores tiene registrado como m�s pesado para recibir el "
  	"premio.\n"),1);
  AddQuestion(({"nuera","sia","Sia"}),W("Kaewin te dice: Sia es la mujer de nuestro hijo, y "
  	"madre de Zaesh. Tambi�n desapareci� cuando entraron los dos al bosque "
  	"de Cylin.\n"),1);
  AddQuestion(({"nieta","zaesh","Zaesh"}),W("Kaewin te dice: Zaesh es mi nieto. Mi marido y yo "
  	"nos ocupamos de �l desde que sus padres desaparecieron. Si quieres verle "
  	"puedes buscar por el lago, suele estar pescando en el muelle.\n"),1);
  AddQuestion(({"koek","Koek","pueblo","Pueblo","pueblo de koek","pueblo de Koek","Pueblo de koek","Pueblo de Koek"}),W(
	"Kaewin te dice: Me gusta Koek, y siempre me ha gustado, pero ahora me trae a la memoria "
	"recuerdos que preferir�a no tener.\n"),1);
  AddQuestion(({"cylin","Cylin","bosque","Bosque","bosque de cylin","Bosque de cylin","bosque de Cylin","Bosque de Cylin"}),W(
	"Kaewin te dice: Los monjes del templo protegen el bosque, no se por qu�... la verdad "
	"es que en el fondo creo que lo que hacen es protegernos del bosque... "
	"porque cuando mi hijo entr� le intentaron convencer de que no fuera... "
	"pero no les hizo caso.\n"),1);
  AddQuestion(({"templo","Templo","Seri-Solderteg"}),W(
	"Kaewin te dice: El templo es un lugar antiguo y de culto donde los monjes se preparan "
	"para poder hacer frente a los posibles peligros que puedan surgir.\n"),1);
  AddItem(RHOEARM("koek/varios/delantal"),REFRESH_REMOVE,SF(wearme));
}
