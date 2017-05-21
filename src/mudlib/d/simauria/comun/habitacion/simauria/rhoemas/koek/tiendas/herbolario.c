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

  SetIntSmell(W("Las hierbas que se venden aquí han dejado un aroma tan fuerte "

  	"que te produce mareos.\n"));

  SetIntNoise("No oyes nada especial por aquí.\n");

  SetIntLong(W("Este es el herbolario. Aquí puedes comprar todo tipo de hierbas "

  	"extrañas. Es un lugar pequeño y poco ventilado, así que las hierbas a la "

  	"venta parece que se adueñen del aire. Hay un cartel donde puedes leer el "

  	"horario de venta al público.\n"));

  AddDetail(({"suelo"}),W("Es un suelo muy normal, hecho con tablones de madera "

  	"un poco gastados por el paso de los clientes.\n"));

  AddDetail(({"pared","paredes"}),"No hay ningún tipo de decoración.\n");

  AddDetail(({"techo"}),"Un techo de lo más normal, hecho de tablones de madera.\n");

  AddDetail(({"hierba","hierbas"}),W("Hay muchas. Deberías de ver las que hay a la "

  	"venta para poder elegir.\n"));

  AddDetail(({"cartel","horario"}),W("Hay un pequeño cartel colgado en el que "

  	"pone el horario de apertura. Deberías leerlo.\n"));

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

