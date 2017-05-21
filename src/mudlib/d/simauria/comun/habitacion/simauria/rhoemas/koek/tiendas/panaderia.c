/***************************************************************************************
 ARCHIVO:	panaderia.c
 AUTOR:		[z] Zomax
 FECHA:		20-10-2001
 COMENTARIOS:	Panaderia, planta baja.
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("shop");

//mixed carcel;

create () {
 ::create();

  SetLocate("Koek");
  SetIntShort("la panader�a");
  SetIntSmell("El pan reci�n hecho se huele por todas partes.\n");
  SetIntNoise("Oyes los ruidos de la le�a al arder en el piso de abajo.\n");
  SetIntLong(W("Est�s en la panaderia de Koek, el negocio de Jynad y su "
  	"marido Jens. Es un sitio muy peque�o y bastante simple con un "
  	"mostrador con todo tipo de pan en �l. En un rinc�n hay varios "
  	"capazos y sacos vac�os. Todo el lugar est� te�ido de blanco por "
 	"la harina que se ha ido depositando por todas partes desde el "
 	"s�tano. Hay un cartel donde pone el horario de venta al p�blico.\n"));
  AddDetail(({"mostrador","mesas","mesa"}),W("Hay unas cuantas mesas muy "
 	"simples donde se coloca el pan para vender. Est�n hechas de "
 	"madera y tienen harina por todas partes.\n"));
  AddDetail(({"rinc�n","rincon","esquina"}),W("En una esquina de la "
  	"habitaci�n hay varios cubos y sacos vac�os.\n"));
  AddDetail(({"pan","panes","hogaza","hogazas","hogaza de pan","hogazas de pan"}),W(
 	"Hay pan de todo tipo: redondo, barra, de centeno, trigo...\n"));
  AddDetail(({"capazo","capazos","capazo de mimbre","capazos de mimbre"}),W(
 	"Unos cuantos capazos de mimbre que han sido usados para llevar "
 	"el pan se amontonan en un rinc�n.\n"));
  AddDetail(({"suelo"}),W("Es un suelo hecho con tablones de madera que "
  	"aisla un poco el calor que produce el horno del s�tano y est� un "
  	"poco sucio por la harina.\n"));
  AddDetail(({"saco","sacos","saco de harina","sacos de harina"}),W("Hay "
  	"varios sacos vac�os que han sido usados para traer harina del molino.\n"));
  AddDetail(({"escalera","escaleras"}),W("Una peque�a escalera de madera "
  	"baja hacia el s�tano.\n"));
  AddDetail(({"pared","paredes"}),W("Este lugar tiene unas paredes muy "
  	"sencillas, sin ning�n tipo de decoraci�n.\n"));
  AddDetail(({"techo"}),"Un techo de lo m�s normal, hecho de tablones de madera.\n");
  AddDetail(({"decoraci�n"}),"No ves ning�n tipo de decoraci�n en ning�n sitio.\n");
  AddDetail(({"harina"}),"Hay harina por todas partes... por algo es una panaderia.\n");
  AddDetail(({"cartel","horario"}),W("Hay un peque�o cartel colgado en el "
  	"que pone el horario de apertura. Deber�as leerlo.\n"));
  AddReadMsg(({"cartel","horario"}),("\n"
  "       *-------------------------------------------------------*\n"
  "       |                                                       |\n"
  "       |           [36mTabla de Horarios de la Panader�a[0m           |\n"
  "       |                                                       |\n"
  "       |    El horario de la apertura de la panader�a es de    |\n"
  "       |    las [52m4[0m hasta las [52m22[0m, diariamente.                   |\n"
  "       |                                                       |\n"
  "       |                                               [50mJynad[0m   |\n"
  "       *-------------------------------------------------------*\n"));
  AddExit("este",RHOEHAB("koek/calles/kadhu_03"));
  AddExit("abajo",RHOEHAB("koek/tiendas/panaderia_sotano"));
  h1=4;
  h2=22;
  pnj="koek/tiendas/jynad";
  fcosas("panaderia");
  carcel=(RHOEHAB("koek/calles/kadhu_03"));
}
