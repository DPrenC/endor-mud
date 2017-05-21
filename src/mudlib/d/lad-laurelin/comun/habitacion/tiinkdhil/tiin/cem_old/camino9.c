/*
DESCRIPCION  :
FICHERO      : /d/lad-laurelin/comun/habitacion/tiinkdhil/
NOTAS:
MODIFICACION :
*/

#include "./path.h"
#include <properties.h>
#include <rooms.h>
inherit ROOM;

int leer_mensaje(string Que){
	if (Que=="mensaje"||Que=="mensaje de arco"||Que=="pilar"){
	write("\n"+"  Consigues leer:\n"+"\n"+
	      "  El cielo se oscureció, y de ella vinieron\n"
              "los seres que no deberian existir, a robar las\n"
              "vidas de nuestros hermanos. Los recordaremos.\n");
	return 1;}
}

init(){
	::init();
	add_action("leer_mensaje","leer");
}


create() {
  ::create();
SetIntShort("el camino del cementerio");
SetIntLong(
"  Te encuentras frente a un arco de piedra. En este punto deja de haber árboles\n"
"y en su lugar se abre una gran explanada con gran cantidad de lápidas hacinadas.\n"
"El arco que parece elevarse hacia el cielo contiene un mensaje en uno de sus\n"
"pilares.\n");

AddDetail(({"lapidas","sepulturas","tumbas","lápidas"}),"  Las lapidas son de construccion simple, pero en estas estan mal\n"
                                              "colocadas da la sensacion de que alguien ha estado cavando, sobre\n"
                                              "cada una de las tumbas.\n");
AddDetail(({"mensaje","pilar","mensaje de arco"}),"\n"+"  Consigues leer:\n"+"\n"+"  El cielo se oscureció, y de ella vinieron\n"
                                "los seres que no deberian existir, a robar las\n"
                                "vidas de nuestros hermanos. Los recordaremos.\n");
AddDetail(({"arco"})," Es un arco de piedra bastante grande y parece como si fuese el\n"
                     "encargado vigilar la entrada a esta parte del cementerio.\n");

AddDetail (({"niebla"}),"  En este punto del camino la niebla ya casi ha desaparecido excepto\n"
                        "cerca del suelo donde aun permanece impidiendo ver con claridad el suelo.\n");

SetIntNoise("  Se oye un ruido familiar, parece ser el de un fuego encendido.\n");

SetIntSmell("  Definitivamente huele a carne podrida.\n ");
SetLocate("Cementerio2");
SetIndoors (0); /* 0 exterior; 1 interior */
SetIntBright(20);

AddExit("oeste","camino5");
AddExit("este","camino11");
}
