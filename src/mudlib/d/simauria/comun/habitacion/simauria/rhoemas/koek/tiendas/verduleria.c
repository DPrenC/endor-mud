/***************************************************************************************
 ARCHIVO:	verduleria.c
 AUTOR:		[z] Zomax
 FECHA:		25-10-2001
 COMENTARIOS:	Verdulería, planta baja.
 MODIFICACION:  11-05-2003 Quito linea para nuevo driver 3.2.9 (mixed carcel;)
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("shop");

create () {
 ::create();

  SetLocate("Koek");
  SetIntShort("la verdulería");
  SetIntSmell("Huele a verduras... algo lógico, piensas.\n");
  SetIntNoise("Nada, no oyes nada de nada... al menos nada que te interese.\n");
  SetIntLong(W("Esta es la verdulería. Aquí Jaush pasa el día atendiendo "
  	"a los clientes que entran y sobre todo mirando de reojo a Felith, "
  	"que tiene su frutería justo enfrente. Hay algún mostrador con "
  	"verduras de todo tipo dispuestas para ser vendidas y un gran ventanal "
  	"por el que se ve la calle y, cómo no, la frutería. Hay un cartel donde "
  	"puedes leer el horario de venta al público.\n"));
  AddDetail(({"mostrador","mesas","mesa"}),W("Hay un gran mostrador que ocupa la "
  	"mayor parte del comercio y que está repleto de las verduras que Jaush "
  	"suele vender. Además hay algún otro mucho más pequeño, pero vacío.\n"));
 AddDetail(({"verdura","verduras","vegetal","vegetales"}),W("Ves varios tipos... "
 	"lo mejor es que mires la lista del comercio.\n"));
 AddDetail(({"ventana","ventanal","gran ventana","gran ventanal"}),W("Por el "
 	"gran ventanal que hay al oeste puedes ver con toda claridad la calle y "
 	"la frutería de enfrete.\n"));
 AddDetail(({"fruteria","frutería","calle"}),"Ves todo a través de la ventana.\n");
 AddDetail(({"suelo"}),W("Es un suelo hecho con tablones de madera un poco gastado "
 	"de tanto pisarlo.\n"));
 AddDetail(({"pared","paredes"}),W("Este lugar tiene unas paredes muy sencillas, "
 	"sin ningún tipo de decoración.\n"));
 AddDetail(({"techo"}),"Un techo de lo más normal, hecho de tablones de madera.\n");
 AddDetail(({"decoración"}),"No ves ningún tipo de decoración en ningún sitio.\n");
 AddDetail(({"cartel","horario"}),W("Hay un pequeño cartel colgado en el que "
 	"pone el horario de apertura. Deberías leerlo.\n"));
 AddReadMsg(({"cartel","horario"}),("\n"
  "       *-------------------------------------------------------*\n"
  "       |                                                       |\n"
  "       |           [36mTabla de Horarios de la Verdulería[0m          |\n"
  "       |                                                       |\n"
  "       |    El horario de la apertura de la verdulería es de   |\n"
  "       |    las [52m8[0m hasta las [52m24[0m, diariamente.                   |\n"
  "       |                                                       |\n"
  "       |                                             [50mJaush[0m     |\n"
  "       *-------------------------------------------------------*\n"));
 AddExit("oeste",RHOEHAB("koek/calles/kadhu_02"));
 h1=8;
 h2=24;
 pnj="koek/tiendas/jaush";
 fcosas("verduleria");
 carcel=(RHOEHAB("koek/calles/kadhu_02"));
}
