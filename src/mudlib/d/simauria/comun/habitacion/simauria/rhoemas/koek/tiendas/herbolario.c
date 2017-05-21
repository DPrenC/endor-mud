/***************************************************************************************

 ARCHIVO:	herbolario.c

 AUTOR:		[z] Zomax

 FECHA:		19-12-2001

 COMENTARIOS:	Herbolario, planta baja.

 ***************************************************************************************/



#include "path.h"



inherit RHOESTD("shop");



create () {

 ::create();



  SetLocate("Koek");

  SetIntShort("el herbolario");

  SetIntSmell(W("Las hierbas que se venden aqu� han dejado un aroma tan fuerte "

  	"que te produce mareos.\n"));

  SetIntNoise("No oyes nada especial por aqu�.\n");

  SetIntLong(W("Este es el herbolario. Aqu� puedes comprar todo tipo de hierbas "

  	"extra�as. Es un lugar peque�o y poco ventilado, as� que las hierbas a la "

  	"venta parece que se adue�en del aire. Hay un cartel donde puedes leer el "

  	"horario de venta al p�blico.\n"));

  AddDetail(({"suelo"}),W("Es un suelo muy normal, hecho con tablones de madera "

  	"un poco gastados por el paso de los clientes.\n"));

  AddDetail(({"pared","paredes"}),"No hay ning�n tipo de decoraci�n.\n");

  AddDetail(({"techo"}),"Un techo de lo m�s normal, hecho de tablones de madera.\n");

  AddDetail(({"hierba","hierbas"}),W("Hay muchas. Deber�as de ver las que hay a la "

  	"venta para poder elegir.\n"));

  AddDetail(({"cartel","horario"}),W("Hay un peque�o cartel colgado en el que "

  	"pone el horario de apertura. Deber�as leerlo.\n"));

  AddReadMsg(({"cartel","horario"}),("\n"

  "       *-------------------------------------------------------*\n"

  "       |                                                       |\n"

  "       |            [36mTabla de Horarios del Herbolario[0m           |\n"

  "       |                                                       |\n"

  "       |    El horario de la apertura del herbolario es de     |\n"

  "       |    [52m7[0m a [52m24[0m diariamente.                                |\n"

  "       |                                                       |\n"

  "       |                                             [50mWareder[0m   |\n"

  "       *-------------------------------------------------------*\n"));

  AddExit("este",RHOEHAB("koek/calles/cendaf_00"));

  h1=7;

  h2=24;

  pnj="koek/tiendas/wareder";

  fcosas("herbolario");

  carcel=(RHOEHAB("koek/calles/cendaf_00"));

  AddRoomCmd("matar","fmatar");

  AddRoomCmd("robar","frobar");

  AddRoomCmd("confesar","fconfesar");

  AddRoomCmd("entregarse","fentregarse");

}

