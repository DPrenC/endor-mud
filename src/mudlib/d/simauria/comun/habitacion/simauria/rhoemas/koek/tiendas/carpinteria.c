/***************************************************************************************

 ARCHIVO:	carpinteria_00.c

 AUTOR:		[z] Zomax

 FECHA:		19-12-2001

 COMENTARIOS:	Carpintería, planta baja.

 ***************************************************************************************/



#include <wizlevels.h>

#include "path.h"



inherit SHOP;

#include RHOEPRESO



mixed ficheros;



void fcosas(string tienda)

{

	int i;

	ficheros=get_dir(RHOEVAR("koek/comercio/"+tienda+"/*.c"));

 	for (i = sizeof(ficheros);i--;)

 	{

 		AddArticle(RHOEVAR("koek/comercio/"+tienda+"/"+ficheros[i]),REFRESH_REMOVE,5);

 	}

}



create () {

 ::create();



  SetLocate("Koek");

  SetIntShort("la carpintería");

  SetIntSmell("Huele a madera de todas clases.\n");

  SetIntNoise("No oyes nada especial por aquí.\n");

  SetIntLong(W("Estás en la carpintería de Koek. En este taller se trabajan "

  	"prácticamente todas las piezas de madera de este valle, por lo que "

  	"está siempre abierto y en funcionamiento, debido a la gran demanda. "

  	"Puedes ver mucho serrín en el suelo.\n"));

  AddDetail(({"serrín","serrin"}),"Eso fue madera en una época.\n");

  AddDetail(({"suelo"}),W("Es un suelo hecho con tablones de madera de lo "

  	"más corrientes. Está lleno de serrín.\n"));

  AddDetail(({"pared","paredes"}),W("Este lugar tiene unas paredes muy "

  	"sencillas, sin ningún tipo de decoración.\n"));

  AddDetail(({"techo"}),W("Un techo de lo más normal, hecho de tablones "

  	"de madera.\n"));

  AddDetail(({"cartel","horario"}),W("Hay un pequeño cartel colgado en el "

  	"que pone el horario de apertura. Deberías leerlo.\n"));

  AddReadMsg(({"cartel","horario"}),("\n"

  "       *-------------------------------------------------------*\n"

  "       |                                                       |\n"

  "       |           [36mTabla de Horarios de la Carpintería[0m         |\n"

  "       |                                                       |\n"

  "       |    La carpintería permanecerá abierta todo el día en  |\n"

  "       |    pro del bien común.                                |\n"

  "       |                                                       |\n"

  "       |                                              [50mMireba[0m   |\n"

  "       *-------------------------------------------------------*\n"));

  AddExit("oeste",RHOEHAB("koek/calles/cendaf_01"));
    SetLastDest(RHOEHAB("koek/calles/cendaf_01"));
    SetNotifyExits("oeste");
  SetShopkeeper(RHOEPNJ("koek/tiendas/jared"));

  fcosas("carpinteria");

  carcel=(RHOEHAB("koek/calles/cendaf_01"));

  RemoveDustbin();

  AddRoomCmd("matar","fmatar");

  AddRoomCmd("robar","frobar");

  AddRoomCmd("confesar","fconfesar");

  AddRoomCmd("entregarse","fentregarse");

  AddRoomCmd("almacen","falmacen");

}



int falmacen(string str)

{

	if(!IS_LEARNER(TP))

	{

		write("El almacen está cerrado, no puedes pasar.\n");

		return 1;

	}



}

