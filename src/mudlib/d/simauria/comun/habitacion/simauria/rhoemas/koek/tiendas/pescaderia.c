/***************************************************************************************
 ARCHIVO:	pescaderia.c
 AUTOR:		[z] Zomax
 FECHA:		24-10-2001
 COMENTARIOS:	Pescadería, planta baja.
 MODIFICACION:  11-05-2003 Quito linea para nuevo driver 3.2.9
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("shop");

create () {
 ::create();

  SetLocate("Koek");
  SetIntShort("la pescadería");
  SetIntSmell(W("Huele a pescado, un olor que ni con cien botellas de "
  	"lejía se lograría quitar.\n"));
  SetIntNoise("No oyes nada especial por aquí.\n");
  SetIntLong(W("Esta es la pescadería que tienen Kaewin y su marido, el "
  	"pescador Froeker. Mientras que Kaewin se ocupa de la venta, Froeker "
  	"está en el lago pescando con su nieto. Hay varios estantes con "
  	"pescado de varias clases y algo de sal para conservarlos mejor. "
  	"De todas formas parece que aquí se acaba pronto, porque ves los "
  	"ves muy frescos. Hay un cartel donde puedes leer el horario de "
  	"venta al público.\n"));
  AddDetail(({"estante","estantes"}),W("Hay un montón de estantes con "
  	"pescado colocados por la habitación. Son de madera y parecen muy "
  	"viejos, pero aún cumplen a la perfección con lo que se espera de "
  	"ellos.\n"));
  AddDetail(({"pez","peces","pescado","pescados"}),W("Hay muchos pescados "
  	"en los estantes... lo mejor es que leas la lista de cosas a la venta.\n"));
  AddDetail(({"sal"}),W("Algunos estantes están llenos de sal para conservar "
  	"mejor el pescado.\n"));
  AddDetail(({"suelo"}),W("Es un suelo hecho con tablones de madera de lo "
  	"más corrientes.\n"));
  AddDetail(({"pared","paredes"}),W("Este lugar tiene unas paredes muy "
  	"sencillas, sin ningún tipo de decoración.\n"));
  AddDetail(({"techo"}),"Un techo de lo más normal, hecho de tablones de madera.\n");
  AddDetail(({"cartel","horario"}),W("Hay un pequeño cartel colgado en el "
  	"que pone el horario de apertura. Deberías leerlo.\n"));
  AddReadMsg(({"cartel","horario"}),("\n"
  "       *-------------------------------------------------------*\n"
  "       |                                                       |\n"
  "       |           [36mTabla de Horarios de la Pescadería[0m          |\n"
  "       |                                                       |\n"
  "       |    El horario de la apertura de la pescadería es de   |\n"
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
