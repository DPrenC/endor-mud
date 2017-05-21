/***************************************************************************************
 ARCHIVO:	sastreria.c
 AUTOR:		[z] Zomax
 FECHA:		22-04-2003
 COMENTARIOS:	La sastrería.
 MODIFICACION:  11-05-2003 Quito linea para nuevo driver 3.2.9 (mixed carcel;)
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("shop");

create () {
 ::create();

  SetLocate("Koek");
  SetIntShort("la sastrería");
  SetIntSmell("Los tintes y el olor del cuero llena tus pulmones.\n");
  SetIntNoise("No oyes nada especial por aquí.\n");
  SetIntLong(W("Lo que antes era un local abandonado se ha convertido "
  	"en la nueva sastrería de Koek, regentada por Goalin, un joven "
  	"visionario de la moda que se decidió hace poco a instalarse "
  	"en el pueblo. Quizás encuentres algo que te guste para comprar.\n"));
  
  AddDetail(({"pared","paredes"}),W("Este lugar tiene unas paredes muy "
  	"sencillas, sin ningún tipo de decoración.\n"));
  AddDetail(({"techo"}),W("Un techo de lo más normal, hecho de tablones "
  	"de madera.\n"));
  AddDetail(({"cartel","horario"}),W("Hay un pequeño cartel colgado en el "
  	"que pone el horario de apertura. Deberías leerlo.\n"));
  AddReadMsg(({"cartel","horario"}),("\n"
  "       *-------------------------------------------------------*\n"
  "       |                                                       |\n"
  "       |            [36mTabla de Horarios de la Sastrería[0m          |\n"
  "       |                                                       |\n"
  "       |    El horario de la apertura de  la sastrería es de   |\n"
  "       |    las [52m8[0m hasta las [52m22[0m, diariamente.                   |\n"
  "       |                                                       |\n"
  "       |                                              [50mGoalin[0m   |\n"
  "       *-------------------------------------------------------*\n"));
  AddExit("oeste",RHOEHAB("koek/calles/kadhu_00"));
  h1=8;
  h2=22;
  pnj="koek/tiendas/goalin";
  fcosas("sastreria");
  carcel=(RHOEHAB("koek/calles/kadhu_00"));
}
