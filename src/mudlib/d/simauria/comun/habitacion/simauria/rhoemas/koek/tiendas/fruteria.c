/***************************************************************************************
 ARCHIVO:	fruteria.c
 AUTOR:		[z] Zomax
 FECHA:		25-10-2001
 COMENTARIOS:	Fruter�a, planta baja.
 MODIFICACION:  11-05-2003 Quito linea para nuevo driver 3.2.9 (mixed carcel;)
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("shop");

create () {
 ::create();

  SetLocate("Koek");
  SetIntShort("la fruter�a");
  SetIntSmell("La fruta deja su aroma por todas partes.\n");
  SetIntNoise("No se oye nada especial.\n");
  SetIntLong(W("Est�s en la fruter�a. Es un lugar peque�o pero bien distribu�do "
  	"que rebosa de frutas de todos los colores. Tienen muy buena pinta. Al "
  	"fondo de la habitaci�n hay un peque�o mostrador donde Felith pesa las "
  	"frutas. En los estantes que hay por toda la estancia est�n repartidas "
  	"las frutas seg�n su procedencia: de los campos de Koek, Gaddaro y algunas "
  	"de m�s lejos. Hay un cartel donde puedes leer el horario de venta al p�blico.\n"));
  AddDetail(({"mostrador"}),W("El mostrador est� hecho de madera, y sirve para "
  	"que Felith pueda dejar la fruta y pesarla mientras los clientes esperan.\n"));
  AddDetail(({"fruta","frutas"}),W("Hay de todos tipos, formas, colores y clases... "
  	"nunca hab�as visto tanta variedad.\n"));
  AddDetail(({"estante","estantes"}),W("La fruta est� colocada en los estantes "
  	"formando cuadrados de diferentes colores.\n"));
  AddDetail(({"suelo"}),W("Es un suelo muy normal, hecho con tablones de madera "
  	"un poco gastados por el paso de los clientes.\n"));
  AddDetail(({"pared","paredes"}),W("Est�n cubiertas de estantes donde descansa "
  	"la fruta. No queda espacio libre para ning�n tipo de decoraci�n.\n"));
  AddDetail(({"techo"}),"Un techo de lo m�s normal, hecho de tablones de madera.\n");
  AddDetail(({"decoraci�n"}),"No ves ning�n tipo de decoraci�n en ning�n sitio.\n");
  AddDetail(({"cartel","horario"}),W("Hay un peque�o cartel colgado en el que "
  	"pone el horario de apertura. Deber�as leerlo.\n"));
  AddReadMsg(({"cartel","horario"}),("\n"
  "       *-------------------------------------------------------*\n"
  "       |                                                       |\n"
  "       |            [36mTabla de Horarios de la Fruter�a[0m           |\n"
  "       |                                                       |\n"
  "       |    El horario de la apertura de la fruter�a es de     |\n"
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
