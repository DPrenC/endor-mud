/*
DESCRIPCION  : Donde les kitan el alijo
FICHERO      : aduana.c
MODIFICACION :

[Chs] Chaos@Simauria.upv.es

18-04-00 [Chs] Creacion

--------------------------------------------------------------------------------
*/
#include "./path.h"
#include <moving.h>


inherit SIM_ROOM;

#define NOMBRE capitalize(TP->QueryPresay()+TP->QueryName())
#define AO     (TP->QueryGenderEndString())
#define S2     (TP->QueryGender()==2?"a":"e")

int ir_pueblo()
{
object alijo;
status found;
while (alijo = present("alijo", TP) ) // recorre el inventario y destruye los alijos
  {
  alijo->remove();
  found = 1 ;
  }
   if (found)
   {
    write(W("Avanzas por el camino hacia el oeste pero de repente eres "
      "detenid"+AO+" por unos guardias.\nEl Capitán te requisa la mercancia"
      " diciendo:'No puedes pasar llevando esa mercancía'.\n"));
    say(W(NOMBRE+" avanza por el camino hacia el oeste y es retenid"+AO+
      " por unas guardias.\nEl Capitán le requisa la mercancia a "+NOMBRE+" y "
      "dice: "+NOMBRE+" no puedes pasar llevando esa mercancía.\n"),TP);
   }
   say(NOMBRE+" se va hacia el oeste.\n");
   TP->move("/d/simauria/comun/habitacion/nyne/krigor/sendero",M_SILENT);
   say(NOMBRE+" llega del este.\n");
   tell_object(TP,
    "El Capitán te dice:'¡Que tenga un buen dia!'\n");
return 1;
}
int salir_pueblo()
{
 object alijo;
 status found;

 found =0;
  while (alijo = present("alijo",TP))
  {
     alijo->remove();
     found = 1;
  }
  if( found)
  {
     write(W("Avanzas por el camino hacia el oeste pero de repente eres "
      "detenid"+AO+" por unos guardias.\nEl Capitán te requisa la mercancia"
      " diciendo:'No puedes pasar llevando esa mercancía'.\n"));
    say(W(NOMBRE+" avanza por el camino hacia el oeste y es retenid"+AO+
      " por unas guardias.\nEl Capitán le requisa la mercancia a "+NOMBRE+" y "
      "dice: "+NOMBRE+" no puedes pasar llevando esa mercancía.\n"),TP);
   }
   say(NOMBRE+" se va hacia el este.\n");
    TP->move("/d/simauria/comun/habitacion/nyne/krigor/camino",M_SILENT);
   say(NOMBRE+" llega del oeste.\n");
   tell_object(TP,
    "El Capitán te dice:'¡Que tenga un buen día!'\n");
return 1;
}


create() {
 ::create();
 SetIntShort("un puesto de guardia");
 SetIntLong(W("En un lateral del desfiladero ves un puesto de guardia. "
               "Es una pequeña construcción donde los guardias se turnan "
               "para vigilar la entrada al pueblo de Krigor. Al lado de la "
               "casa ves un cartel. Hacia el este puedes observar unos "
               "pastos que son atravesados por un camino que lleva al pueblo.\n"));
AddDetail(({ "cartel" , "letrero" }),"Bienvenido a Krigor.\n");
AddDetail(({ "pastos" , "campo" , "pasto" }),
	   W("Son unos pastos de hierba verde y fresca, dan ganas de tumbarse "
             "en ellos.\n"));
AddDetail(({"casa","construcción"}),
	    W("Es una pequeña casa hecha de madera. Dentro ves algunos guardias "
	     "que vigilan la entrada al pueblo, de posibles ataques de bandidos. "
	     "También impiden el paso a los contrabandista.\n"));
AddDetail(({"camino","sendero"}),
	   "Es un estrecho camino que cruza los prados de pasto");
AddDetail(({"Krigor","pueblo","krigor"}),
	   W("Es un pequeño pueblo de montanya, esta rodeado de pastos de hierba "
	     "donde se ve ganado pastar tranquilamente.\n"));
SetIntNoise("Oyes el susurro del viento através de las rocas.\n");
SetIntSmell("Hules a comida frita.\n");
SetLocate("Krigor");
SetIndoors(0);

AddExit("este",SF(salir_pueblo));
AddExit("oeste",SF(ir_pueblo));
}