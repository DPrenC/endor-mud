/***************************************************************************************
 ARCHIVO:	lecheria.c
 AUTOR:		[z] Zomax
 FECHA:		25-10-2001
 COMENTARIOS:	Lecher�a, planta baja.
 MODIFICACION:  11-05-2003 Quito linea para nuevo driver 3.2.9 (mixed carcel;)
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("shop");

create () {
 ::create();

  SetLocate("Koek");
  SetIntShort("la lecher�a");
  SetIntSmell("Huele a leche y fermentos extra�os.\n");
  SetIntNoise("No oyes nada especial.\n");
  SetIntLong(W("Esta es la lecher�a que regenta Gwenn desde que enviud�, "
  	"donde puedes comprar una gran variedad de productos l�cteos. Hay "
  	"unos grandes bidones de metal colgados de la pared con unos peque�os "
  	"grifos por los que sale la leche. En el fondo hay un mostrador, con "
  	"una peque�a silla donde descansa la tendera. A los lados ves varias "
 	"mesas con quesos de todo tipo. Hay un cartel donde puedes leer el "
 	"horario de venta al p�blico.\n"));
  AddDetail(({"mostrador","mesas","mesa"}),W("El mostrador y las mesas son "
  	"de madera, y est�n llenos de quesos y otras cosas...\n"));
  AddDetail(({"bidon","bid�n","bidones","bidon de metal","bid�n de metal","bidones de metal"}),W(
 	"Unos grandes bidones repletos de leche apoyados en la pared sirven "
 	"para contener la leche que se vende aqu�.\n"));
  AddDetail(({"grifo","grifos"}),W("Unos peque�os grifos en los bidones evitan "
  	"que la leche se escape.\n"));
  AddDetail(({"silla","peque�a silla"}),W("Es una peque�a silla de madera para "
  	"que la tendera descanse de vez en cuando.\n"));
  AddDetail(({"suelo"}),"Es un suelo hecho con tablones de madera normales.\n");
  AddDetail(({"queso","quesos"}),W("Hay un mont�n de quesos por todas partes y "
  	"de todo tipo.\n"));
  AddDetail(({"pared","paredes"}),W("Este lugar tiene unas paredes muy sencillas, "
  	"sin ning�n tipo de decoraci�n.\n"));
  AddDetail(({"techo"}),"Un techo de lo m�s normal, hecho de tablones de madera.\n");
  AddDetail(({"decoraci�n"}),"No ves ning�n tipo de decoraci�n en ning�n sitio.\n");
  AddDetail(({"leche"}),"No la ves... pero supones que est� en los bidones.\n");
  AddDetail(({"cartel","horario"}),W("Hay un peque�o cartel colgado en el que "
  	"pone el horario de apertura. Deber�as leerlo.\n"));
  AddReadMsg(({"cartel","horario"}),("\n"
  "       *-------------------------------------------------------*\n"
  "       |                                                       |\n"
  "       |            [36mTabla de Horarios de la Lecher�a[0m           |\n"
  "       |                                                       |\n"
  "       |    El horario de la apertura de la lecher�a es de     |\n"
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
