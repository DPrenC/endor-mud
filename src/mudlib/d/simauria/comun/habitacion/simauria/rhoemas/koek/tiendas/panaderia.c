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
  SetIntShort("la panadería");
  SetIntSmell("El pan recién hecho se huele por todas partes.\n");
  SetIntNoise("Oyes los ruidos de la leña al arder en el piso de abajo.\n");
  SetIntLong(W("Estás en la panaderia de Koek, el negocio de Jynad y su "
  	"marido Jens. Es un sitio muy pequeño y bastante simple con un "
  	"mostrador con todo tipo de pan en él. En un rincón hay varios "
  	"capazos y sacos vacíos. Todo el lugar está teñido de blanco por "
 	"la harina que se ha ido depositando por todas partes desde el "
 	"sótano. Hay un cartel donde pone el horario de venta al público.\n"));
  AddDetail(({"mostrador","mesas","mesa"}),W("Hay unas cuantas mesas muy "
 	"simples donde se coloca el pan para vender. Están hechas de "
 	"madera y tienen harina por todas partes.\n"));
  AddDetail(({"rincón","rincon","esquina"}),W("En una esquina de la "
  	"habitación hay varios cubos y sacos vacíos.\n"));
  AddDetail(({"pan","panes","hogaza","hogazas","hogaza de pan","hogazas de pan"}),W(
 	"Hay pan de todo tipo: redondo, barra, de centeno, trigo...\n"));
  AddDetail(({"capazo","capazos","capazo de mimbre","capazos de mimbre"}),W(
 	"Unos cuantos capazos de mimbre que han sido usados para llevar "
 	"el pan se amontonan en un rincón.\n"));
  AddDetail(({"suelo"}),W("Es un suelo hecho con tablones de madera que "
  	"aisla un poco el calor que produce el horno del sótano y está un "
  	"poco sucio por la harina.\n"));
  AddDetail(({"saco","sacos","saco de harina","sacos de harina"}),W("Hay "
  	"varios sacos vacíos que han sido usados para traer harina del molino.\n"));
  AddDetail(({"escalera","escaleras"}),W("Una pequeña escalera de madera "
  	"baja hacia el sótano.\n"));
  AddDetail(({"pared","paredes"}),W("Este lugar tiene unas paredes muy "
  	"sencillas, sin ningún tipo de decoración.\n"));
  AddDetail(({"techo"}),"Un techo de lo más normal, hecho de tablones de madera.\n");
  AddDetail(({"decoración"}),"No ves ningún tipo de decoración en ningún sitio.\n");
  AddDetail(({"harina"}),"Hay harina por todas partes... por algo es una panaderia.\n");
  AddDetail(({"cartel","horario"}),W("Hay un pequeño cartel colgado en el "
  	"que pone el horario de apertura. Deberías leerlo.\n"));
  AddReadMsg(({"cartel","horario"}),("\n"
  "       *-------------------------------------------------------*\n"
  "       |                                                       |\n"
  "       |           [36mTabla de Horarios de la Panadería[0m           |\n"
  "       |                                                       |\n"
  "       |    El horario de la apertura de la panadería es de    |\n"
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
