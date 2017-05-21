/***************************************************************************************
 ARCHIVO:	lecheria.c
 AUTOR:		[z] Zomax
 FECHA:		25-10-2001
 COMENTARIOS:	Lechería, planta baja.
 MODIFICACION:  11-05-2003 Quito linea para nuevo driver 3.2.9 (mixed carcel;)
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("shop");

create () {
 ::create();

  SetLocate("Koek");
  SetIntShort("la lechería");
  SetIntSmell("Huele a leche y fermentos extraños.\n");
  SetIntNoise("No oyes nada especial.\n");
  SetIntLong(W("Esta es la lechería que regenta Gwenn desde que enviudó, "
  	"donde puedes comprar una gran variedad de productos lácteos. Hay "
  	"unos grandes bidones de metal colgados de la pared con unos pequeños "
  	"grifos por los que sale la leche. En el fondo hay un mostrador, con "
  	"una pequeña silla donde descansa la tendera. A los lados ves varias "
 	"mesas con quesos de todo tipo. Hay un cartel donde puedes leer el "
 	"horario de venta al público.\n"));
  AddDetail(({"mostrador","mesas","mesa"}),W("El mostrador y las mesas son "
  	"de madera, y están llenos de quesos y otras cosas...\n"));
  AddDetail(({"bidon","bidón","bidones","bidon de metal","bidón de metal","bidones de metal"}),W(
 	"Unos grandes bidones repletos de leche apoyados en la pared sirven "
 	"para contener la leche que se vende aquí.\n"));
  AddDetail(({"grifo","grifos"}),W("Unos pequeños grifos en los bidones evitan "
  	"que la leche se escape.\n"));
  AddDetail(({"silla","pequeña silla"}),W("Es una pequeña silla de madera para "
  	"que la tendera descanse de vez en cuando.\n"));
  AddDetail(({"suelo"}),"Es un suelo hecho con tablones de madera normales.\n");
  AddDetail(({"queso","quesos"}),W("Hay un montón de quesos por todas partes y "
  	"de todo tipo.\n"));
  AddDetail(({"pared","paredes"}),W("Este lugar tiene unas paredes muy sencillas, "
  	"sin ningún tipo de decoración.\n"));
  AddDetail(({"techo"}),"Un techo de lo más normal, hecho de tablones de madera.\n");
  AddDetail(({"decoración"}),"No ves ningún tipo de decoración en ningún sitio.\n");
  AddDetail(({"leche"}),"No la ves... pero supones que está en los bidones.\n");
  AddDetail(({"cartel","horario"}),W("Hay un pequeño cartel colgado en el que "
  	"pone el horario de apertura. Deberías leerlo.\n"));
  AddReadMsg(({"cartel","horario"}),("\n"
  "       *-------------------------------------------------------*\n"
  "       |                                                       |\n"
  "       |            [36mTabla de Horarios de la Lechería[0m           |\n"
  "       |                                                       |\n"
  "       |    El horario de la apertura de la lechería es de     |\n"
  "       |    las [52m5[0m hasta las [52m23[0m, diariamente.                   |\n"
  "       |                                                       |\n"
  "       |                                               [50mGwenn[0m   |\n"
  "       *-------------------------------------------------------*\n"));
  
  AddExit("oeste",RHOEHAB("koek/calles/kadhu_03"));
  h1=5;
  h2=23;
  pnj="koek/tiendas/gwenn";
  fcosas("lecheria");
  carcel=(RHOEHAB("koek/calles/kadhu_03"));
 }
