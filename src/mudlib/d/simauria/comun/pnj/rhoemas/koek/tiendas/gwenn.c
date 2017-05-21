/***************************************************************************************
 ARCHIVO:	gwenn.c
 AUTOR:		[z] Zomax
 FECHA:		25-10-2001
 COMENTARIOS:	Gwenn, la lechera.
 MODIFICACI�N:  20-04-2003 Ahora las respuestas solo se las da al player que pregunta.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit NPC;
#include RHOEDANYO

create(){
  ::create();
  SetStandard("Gwenn la lechera","humano",10,GENERO_FEMENINO);
  SetWhimpy(0);
  SetAlign(250);
  SetAggressive(0);
  SetName("Gwenn");
  SetIds(({"humana","gwenn","Gwenn","lechera"}));
  Set(P_CANT_LURE,1);
  SetShort("Gwenn la lechera");
  SetLong(W("Gwenn, la lechera es una mujer mayor pero a�n no anciana "
  	"que trabaja duro desde que enviud� hace tiempo. Tiene un "
  	"precioso pelo rubio ceniza que le cae hasta los hombros y "
  	"unos ojos algo tristes color miel. Tiene las manos muy suaves "
  	"y delicadas y maneja las cosas con gran delicadeza.\n"));

  AddQuestion(({"lecheria","lecher�a"}),W("Gewnn te dice: La lecher�a me recuerda a "
  	"mi marido, descanse en paz, pero no puedo irme y dejarla "
  	"desatendida, ser�a una ofensa para �l, as� que procuro dedicarle "
  	"todo mi esfuerzo para que est� como si �l a�n viviera.\n"),1);
  AddQuestion(({"marido","esposo"}),W("Gewnn te dice: Mi marido muri� hace ya varios "
  	"a�os, de una larga enfermedad. Era un hombre bueno que se "
  	"preocupaba mucho por m�... s�lo me quedan los recuerdos.\n"),1);
  AddQuestion(({"koek","Koek","pueblo","Pueblo","pueblo de koek","pueblo de Koek","Pueblo de koek","Pueblo de Koek"}),W(
	"Gewnn te dice: Koek es un lugar ideal para montar un negocio.\n"),1);
  AddQuestion(({"cylin","Cylin","bosque","Bosque","bosque de cylin","Bosque de cylin","bosque de Cylin","Bosque de Cylin"}),W(
	"Gewnn te dice: Um... un lugar algo siniestro... por las noches se oyen ruidos "
	"de los animales m�s extra�os y peligrosos que te puedas imaginar.\n"),1);
  AddQuestion(({"templo","Templo","Seri-Solderteg"}),W("Gewnn te dice: En el templo rinden "
  	"culto a no se qu� diosa... la verdad... a los comerciantes de Koek "
  	"s�lo nos importa que nos llena las tiendas de gente.\n"),1);
  AddQuestion(({"horario","abierto","cerrado","abrir","cerrar"}),W("Gewnn te dice: Me ocupo "
	"de la lecher�a de 8 a 22.\n"),1);
  AddItem(RHOEARM("koek/varios/delantal"),REFRESH_REMOVE,SF(wearme));
}
