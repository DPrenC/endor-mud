/*
DESCRIPCION  : Camino que conduce a Stonehenge
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/camino00.c
MODIFICACION : 09-01-97 [angor] Creacion.
*/

#include "./path.h"
inherit ROOM;

public int coger_cmd(string str)
{
 if (!str) return notify_fail("Que es lo que quieres coger?\n",NOTIFY_NOT_VALID)&&0;
 if ((str=="estatua")||(str=="mateese")||(str=="Mateese")){
 write(
  "Esta estatua parece haber sido hecha por un Dios... Tras meditarlo un momento "
  "decides que lo mejor es no tocarla por si acaso.\n");
  return 1;
 }
}

create() {
  ::create();
  SetIntShort("el camino hacia Stohenge.");
  SetIntLong(
"El camino empedrado asciende lentamente abriendose paso entre el bosque "
"hacia la cima de la loma que se encuentra al oeste de la isla y sobre la "
"que se encuentra el monumento de Stonehenge. Junto al camino, y sobre un "
"pequenyo altar de piedra se encuentra una estatua que representa a una elfa. "
"El clima es agradable y el aroma del bosque en primavera, embriagador.\n");

   AddDetail(({"isla","isla Limbo","Limbo","limbo"}),
  "La isla Limbo es el lugar magico de Simauria donde habitan los dioses. "
  "Gracias a ellos, es en este lugar donde las almas de los seres se "
  "encarnan y dan sus primeros pasos para vivir en este mundo.\n");

 AddDetail(({"Stonehenge","stonehenge","monumento"}),
  "Stonehenge es un monumento de piedra que se encuentra sobre una loma "
  "al oeste de la isla Limbo. El poder de los dioses hace que este lugar "
  "este conectado, de forma inexplicable, a otros muchos lugares a lo "
  "largo y ancho de Simauria.\n");

  AddDetail(({"altar","estatua","Mateese","mateese"}),
  "Una pequenya estatua, parcialemente cubierta por la vegetacion se "
  "encuentra sobre un altar situado junto al camino. Representar a una bella "
  "elfa cuya mirada pensativa parece contemplar y entender a un tiempo la "
  "complejidad del mundo que la rodea. Bajo la estatua, se encuentran tallados "
  "en la piedra el nombre de -Mateese- y una inscripcion de texto.\n");

  AddDetail(({"texto","inscripcion"}),
 "Aunque la inscripcion tallada en la piedra esta desgastada por el paso "
 "del tiempo, aun puedes leer un mensaje escrito en una extranya lengua: "
 "                     -The Goddess Mateese- "
 "'The work of this Goddess of a distant world has inspired me'. [Angor]\n");

 SetIntNoise("Solo el dulce trinar de los pajaros altera el silencio.\n");
 SetIntSmell("Las flores inundan el bosque de una suave fragancia.\n");
 SetLocate("isla Limbo");

AddExit("oeste",LIMBO("camino01"));
AddExit("este",LIMBO("camino02"));

AddRoomCmd("coger","coger_cmd");

SetIndoors(0);
}
