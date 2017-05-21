/***************************************************************************************

 ARCHIVO:	carpinteria_00.c

 AUTOR:		[z] Zomax

 FECHA:		19-12-2001

 COMENTARIOS:	Carpinter�a, planta baja.

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

  SetIntShort("la carpinter�a");

  SetIntSmell("Huele a madera de todas clases.\n");

  SetIntNoise("No oyes nada especial por aqu�.\n");

  SetIntLong(W("Est�s en la carpinter�a de Koek. En este taller se trabajan "

  	"pr�cticamente todas las piezas de madera de este valle, por lo que "

  	"est� siempre abierto y en funcionamiento, debido a la gran demanda. "

  	"Puedes ver mucho serr�n en el suelo.\n"));

  AddDetail(({"serr�n","serrin"}),"Eso fue madera en una �poca.\n");

  AddDetail(({"suelo"}),W("Es un suelo hecho con tablones de madera de lo "

  	"m�s corrientes. Est� lleno de serr�n.\n"));

  AddDetail(({"pared","paredes"}),W("Este lugar tiene unas paredes muy "

  	"sencillas, sin ning�n tipo de decoraci�n.\n"));

  AddDetail(({"techo"}),W("Un techo de lo m�s normal, hecho de tablones "

  	"de madera.\n"));

  AddDetail(({"cartel","horario"}),W("Hay un peque�o cartel colgado en el "

  	"que pone el horario de apertura. Deber�as leerlo.\n"));

  AddReadMsg(({"cartel","horario"}),("\n"

  "       *-------------------------------------------------------*\n"

  "       |                                                       |\n"

  "       |           [36mTabla de Horarios de la Carpinter�a[0m         |\n"

  "       |                                                       |\n"

  "       |    La carpinter�a permanecer� abierta todo el d�a en  |\n"

  "       |    pro del bien com�n.                                |\n"

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

		write("El almacen est� cerrado, no puedes pasar.\n");

		return 1;

	}



}

