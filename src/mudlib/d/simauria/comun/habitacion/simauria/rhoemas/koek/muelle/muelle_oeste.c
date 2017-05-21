/***************************************************************************************

 ARCHIVO:	muelle_oeste.c

 AUTOR:		[z] Zomax

 FECHA:		18-11-2001

 COMENTARIOS:	Extremo Oeste del muelle

 ***************************************************************************************/



#include "path.h"



inherit RHOESTD("muelle");



create () {

  ::create();



  SetLocate("Koek");

  SetIntShort("el extremo oeste del muelle");

  AddRoomCmd("pescar","fpescar");

  carcel=(RHOEHAB("koek/muelle/muelle_centro"));

  

  AddExit("este",RHOEHAB("koek/muelle/muelle_centro"));

  AddItem(RHOEPNJ("koek/varios/gato"),1,3+random(3));

  map[neu,des]= "Aquí, en la parte oeste del muelle, las cosas se toman con mucha "

  	"calma. Hay una barca amarrada al muelle, parece que algo vieja, que va a "

  	"ser arreglada en poco tiempo. En esta zona las barcas con desperfectos son "

  	"amarradas para que los diferentes artesanos de la ciudad las arreglen. Sin "

  	"duda el carpintero tiene mucho trabajo por aquí. ";

  

  AddDetail(({"barca"}),W("Es la barca más destrozada que has visto nunca. Da miedo "

  	"sólo de mirarla. El carpintero tiene buena fama, pero visto lo visto dudas de "

  	"que pueda arreglarla aunque sólo sea un poco.\n"));

}



int fpescar(string str)

{

	notify_fail("Este no parece un buen sitio para pescar.\n");

	return 0;

}
