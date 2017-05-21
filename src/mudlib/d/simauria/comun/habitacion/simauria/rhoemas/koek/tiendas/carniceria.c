/***************************************************************************************
 ARCHIVO:	carniceria_00.c
 AUTOR:		[z] Zomax
 FECHA:		24-10-2001
 COMENTARIOS:	Carnicer�a, planta baja.
 MODIFICACION:  11-05-2003 Quito linea para nuevo driver 3.2.9 (mixed carcel;)
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("shop");

create () {
 ::create();

  SetLocate("Koek");
  SetIntShort("la carnicer�a");
  SetIntSmell("Huele a sangre, un olor que te resulta familiar.\n");
  SetIntNoise("No oyes nada especial por aqu�.\n");
  SetIntLong(W("Est�s en la carnicer�a de Mireba y su marido, Galonor. "
  	"Mireba se ocupa de la venta de la carne mientras que Galonor se "
  	"ocupa de comprar el ganado y sacrificarlo. A los lados de la "
  	"estancia puedes ver unas mesas donde se amontona la carne, y al "
  	"fondo un mostrador donde suele estar Mireba atendiendo. Hay un "
  	"cartel donde puedes leer el horario de venta al p�blico.\n"));
  AddDetail(({"mesa","mesas"}),"Son de madera y est�n llenas de sangre.\n");
  AddDetail(({"mostrador"}),W("Un gran mostrador de madera al fondo justo "
  	"donde Mireba atiende a los clientes.\n"));
  AddDetail(({"sangre"}),W("Puedes ver peque�as manchas de sangre por todas "
  	"partes... hasta se huele en el ambiente.\n"));
  AddDetail(({"carne","carnes"}),W("Hay carne de todo tipo dispuesta sobre "
  	"las mesas.\n"));
  AddDetail(({"suelo"}),W("Es un suelo hecho con tablones de madera de lo "
  	"m�s corrientes, algunos manchados con sangre.\n"));
  AddDetail(({"pared","paredes"}),W("Este lugar tiene unas paredes muy "
  	"sencillas, sin ning�n tipo de decoraci�n.\n"));
  AddDetail(({"techo"}),W("Un techo de lo m�s normal, hecho de tablones "
  	"de madera.\n"));
  AddDetail(({"cartel","horario"}),W("Hay un peque�o cartel colgado en el "
  	"que pone el horario de apertura. Deber�as leerlo.\n"));
  AddReadMsg(({"cartel","horario"}),("\n"
  "       *-------------------------------------------------------*\n"
  "       |                                                       |\n"
  "       |           [36mTabla de Horarios de la Carnicer�a[0m          |\n"
  "       |                                                       |\n"
  "       |    El horario de la apertura de la carnicer�a es de   |\n"
  "       |    las [52m10[0m hasta las [52m22[0m, diariamente.                  |\n"
  "       |                                                       |\n"
  "       |                                              [50mMireba[0m   |\n"
  "       *-------------------------------------------------------*\n"));
  AddExit("este",RHOEHAB("koek/calles/kadhu_01"));
  AddExit("abajo",RHOEHAB("koek/tiendas/carniceria_sotano"));
  h1=10;
  h2=22;
  pnj="koek/tiendas/mireba";
  fcosas("carniceria");
  carcel=(RHOEHAB("koek/calles/kadhu_01"));
}
