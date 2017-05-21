/***************************************************************************************
 ARCHIVO:	fruteria.c
 AUTOR:		[z] Zomax
 FECHA:		25-10-2001
 COMENTARIOS:	Frutería, planta baja.
 MODIFICACION:  11-05-2003 Quito linea para nuevo driver 3.2.9 (mixed carcel;)
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("shop");

create () {
 ::create();

  SetLocate("Koek");
  SetIntShort("la frutería");
  SetIntSmell("La fruta deja su aroma por todas partes.\n");
  SetIntNoise("No se oye nada especial.\n");
  SetIntLong(W("Estás en la frutería. Es un lugar pequeño pero bien distribuído "
  	"que rebosa de frutas de todos los colores. Tienen muy buena pinta. Al "
  	"fondo de la habitación hay un pequeño mostrador donde Felith pesa las "
  	"frutas. En los estantes que hay por toda la estancia están repartidas "
  	"las frutas según su procedencia: de los campos de Koek, Gaddaro y algunas "
  	"de más lejos. Hay un cartel donde puedes leer el horario de venta al público.\n"));
  AddDetail(({"mostrador"}),W("El mostrador está hecho de madera, y sirve para "
  	"que Felith pueda dejar la fruta y pesarla mientras los clientes esperan.\n"));
  AddDetail(({"fruta","frutas"}),W("Hay de todos tipos, formas, colores y clases... "
  	"nunca habías visto tanta variedad.\n"));
  AddDetail(({"estante","estantes"}),W("La fruta está colocada en los estantes "
  	"formando cuadrados de diferentes colores.\n"));
  AddDetail(({"suelo"}),W("Es un suelo muy normal, hecho con tablones de madera "
  	"un poco gastados por el paso de los clientes.\n"));
  AddDetail(({"pared","paredes"}),W("Están cubiertas de estantes donde descansa "
  	"la fruta. No queda espacio libre para ningún tipo de decoración.\n"));
  AddDetail(({"techo"}),"Un techo de lo más normal, hecho de tablones de madera.\n");
  AddDetail(({"decoración"}),"No ves ningún tipo de decoración en ningún sitio.\n");
  AddDetail(({"cartel","horario"}),W("Hay un pequeño cartel colgado en el que "
  	"pone el horario de apertura. Deberías leerlo.\n"));
  AddReadMsg(({"cartel","horario"}),("\n"
  "       *-------------------------------------------------------*\n"
  "       |                                                       |\n"
  "       |            [36mTabla de Horarios de la Frutería[0m           |\n"
  "       |                                                       |\n"
  "       |    El horario de la apertura de la frutería es de     |\n"
  "       |    las [52m8[0m hasta las [52m24[0m, diariamente.                   |\n"
  "       |                                                       |\n"
  "       |                                              [50mFelith[0m   |\n"
  "       *-------------------------------------------------------*\n"));
  AddExit("este",RHOEHAB("koek/calles/kadhu_02"));
  h1=8;
  h2=24;
  pnj="koek/tiendas/felith";
  fcosas("fruteria");
  carcel=(RHOEHAB("koek/calles/kadhu_02"));
}
