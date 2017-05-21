/***************************************************************************************
 ARCHIVO:	sastreria.c
 AUTOR:		[z] Zomax
 FECHA:		22-04-2003
 COMENTARIOS:	La sastrer�a.
 MODIFICACION:  11-05-2003 Quito linea para nuevo driver 3.2.9 (mixed carcel;)
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("shop");

create () {
 ::create();

  SetLocate("Koek");
  SetIntShort("la sastrer�a");
  SetIntSmell("Los tintes y el olor del cuero llena tus pulmones.\n");
  SetIntNoise("No oyes nada especial por aqu�.\n");
  SetIntLong(W("Lo que antes era un local abandonado se ha convertido "
  	"en la nueva sastrer�a de Koek, regentada por Goalin, un joven "
  	"visionario de la moda que se decidi� hace poco a instalarse "
  	"en el pueblo. Quiz�s encuentres algo que te guste para comprar.\n"));
  
  AddDetail(({"pared","paredes"}),W("Este lugar tiene unas paredes muy "
  	"sencillas, sin ning�n tipo de decoraci�n.\n"));
  AddDetail(({"techo"}),W("Un techo de lo m�s normal, hecho de tablones "
  	"de madera.\n"));
  AddDetail(({"cartel","horario"}),W("Hay un peque�o cartel colgado en el "
  	"que pone el horario de apertura. Deber�as leerlo.\n"));
  AddReadMsg(({"cartel","horario"}),("\n"
  "       *-------------------------------------------------------*\n"
  "       |                                                       |\n"
  "       |            [36mTabla de Horarios de la Sastrer�a[0m          |\n"
  "       |                                                       |\n"
  "       |    El horario de la apertura de  la sastrer�a es de   |\n"
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
