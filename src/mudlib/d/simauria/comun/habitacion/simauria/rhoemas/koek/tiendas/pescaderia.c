/***************************************************************************************
 ARCHIVO:	pescaderia.c
 AUTOR:		[z] Zomax
 FECHA:		24-10-2001
 COMENTARIOS:	Pescader�a, planta baja.
 MODIFICACION:  11-05-2003 Quito linea para nuevo driver 3.2.9
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("shop");

create () {
 ::create();

  SetLocate("Koek");
  SetIntShort("la pescader�a");
  SetIntSmell(W("Huele a pescado, un olor que ni con cien botellas de "
  	"lej�a se lograr�a quitar.\n"));
  SetIntNoise("No oyes nada especial por aqu�.\n");
  SetIntLong(W("Esta es la pescader�a que tienen Kaewin y su marido, el "
  	"pescador Froeker. Mientras que Kaewin se ocupa de la venta, Froeker "
  	"est� en el lago pescando con su nieto. Hay varios estantes con "
  	"pescado de varias clases y algo de sal para conservarlos mejor. "
  	"De todas formas parece que aqu� se acaba pronto, porque ves los "
  	"ves muy frescos. Hay un cartel donde puedes leer el horario de "
  	"venta al p�blico.\n"));
  AddDetail(({"estante","estantes"}),W("Hay un mont�n de estantes con "
  	"pescado colocados por la habitaci�n. Son de madera y parecen muy "
  	"viejos, pero a�n cumplen a la perfecci�n con lo que se espera de "
  	"ellos.\n"));
  AddDetail(({"pez","peces","pescado","pescados"}),W("Hay muchos pescados "
  	"en los estantes... lo mejor es que leas la lista de cosas a la venta.\n"));
  AddDetail(({"sal"}),W("Algunos estantes est�n llenos de sal para conservar "
  	"mejor el pescado.\n"));
  AddDetail(({"suelo"}),W("Es un suelo hecho con tablones de madera de lo "
  	"m�s corrientes.\n"));
  AddDetail(({"pared","paredes"}),W("Este lugar tiene unas paredes muy "
  	"sencillas, sin ning�n tipo de decoraci�n.\n"));
  AddDetail(({"techo"}),"Un techo de lo m�s normal, hecho de tablones de madera.\n");
  AddDetail(({"cartel","horario"}),W("Hay un peque�o cartel colgado en el "
  	"que pone el horario de apertura. Deber�as leerlo.\n"));
  AddReadMsg(({"cartel","horario"}),("\n"
  "       *-------------------------------------------------------*\n"
  "       |                                                       |\n"
  "       |           [36mTabla de Horarios de la Pescader�a[0m          |\n"
  "       |                                                       |\n"
  "       |    El horario de la apertura de la pescader�a es de   |\n"
  "       |    las [52m6[0m hasta las [52m23[0m, diariamente.                   |\n"
  "       |                                                       |\n"
  "       |                                              [50mKaewin[0m   |\n"
  "       *-------------------------------------------------------*\n"));
  AddExit("oeste",RHOEHAB("koek/calles/kadhu_01"));
  h1=6;
  h2=23;
  pnj="koek/tiendas/kaewin";
  fcosas("pescaderia");
  carcel=(RHOEHAB("koek/calles/kadhu_01"));
}
