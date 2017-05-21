/*
DESCRIPCION  : Almacen en la caverna de las minas
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/mina/nivel0/almacen0.c
MODIFICACION : 03-11-99 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
#include <messages.h>
inherit ROOM;

static int npico, nantorcha;

reponer_antorchas(){nantorcha=6; return;}
reponer_picos(){npico=2; return;}

reset() {
  ::reset();
  reponer_antorchas();
  reponer_picos();
}

string mirar_cajones(){
  string str;
  str="Las estanterias estan llenas de grandes cajones de madera con todo "
      "tipo de trastos y utensilios usados por los mineros para su trabajo. "+
	  "Tras rebuscar un rato en el que tienes ante ti";
  if ((npico==0)&&(nantorcha==0))
     {
     str+=" no encuentras nada que te sea util.\n";
     }
  else
     {
	 str+=" encuentras";
	 if (npico>0) str+=" "+npico+" pico"+(npico>1?"s":"");
	 if ((npico>0)&&(nantorcha>0)) str+=" y";
     if (nantorcha>0) str+=" "+nantorcha+" antorcha"+(nantorcha>1?"s":"");
     }

return (str+".\n");
}


int coger_cmd(string str) {
  object obj;

  if ((str!="antorcha")&&(str!="pico")) return 0;
  if (str=="antorcha")
     {
	 if (nantorcha>0)
	    {
	    obj=clone_object("/obj/torch");
	    if (obj)
		   {
	       if (obj->move(TP))
		      {
			  tell_room(TO, ({ MSG_SEE, NOMBRE+" coge una antorcha de uno de los cajones.\n"}), ({ TP }));
			  write("Coges una antorcha de uno de los cajones.\n");
			  nantorcha-=1;
			  if (nantorcha==0) call_out("reponer_antorchas",300);
              return 1;
			  }
		   else
		      {
              write("Llevas demasiado peso como para ademas coger una antorcha.\n");
              return 1;
			  }
   	       }
        write("Error: Avisa a un programador.\n");
        return 1;
	    }
	 else
	    {
	    notify_fail("En el cajon no quedan mas antorchas.\n");
	    return 0;
	    }
     }
   else
     {
	 if (npico>0)
	    {
	    obj=clone_object(ARMA("pico"));
	    if (obj)
		   {
	       if (obj->move(TP))
		      {
			  tell_room(TO, ({ MSG_SEE, NOMBRE+" coge un pico de uno de los cajones.\n"}), ({ TP }));
			  write("Coges un pico de uno de los cajones.\n");
			  npico-=1;
			  if (npico==0) call_out("reponer_picos",300);
              return 1;
			  }
		   else
		      {
              write("Llevas demasiado peso como para ademas coger un pico.\n");
              return 1;
			  }
   	       }
        write("Error: Avisa a un programador.\n");
        return 1;
	    }
	 else
	    {
	    notify_fail("En el cajon no quedan mas picos.\n");
	    return 0;
	    }

	 }
}


create() {
  ::create();
  SetIntShort("el almacén de las minas");
  SetIntLong(
  "Estas en el interior de un caseta de madera. Aqui, los orcos han "
    "reconvertido una antigua galeria en un almacen de material para el "
	"trabajo en la mina. Una larga hilera de estanterias recorre las "
	"paredes de esta galeria, desde el suelo hasta el bajo techo. En "
	"ellas se apilan de forma desordenada todo tipo de cajones de madera. "
	"Una vieja lampara de aceite colgada del techo ilumina pobremente "
	"el ambiente.\n");

  AddDetail(({"galeria","almacen"}),QueryIntLong());

  AddDetail(({"casetas","caseta","casetas de madera"}),
  "Son unas construcciones toscas de madera situadas junto a algunas de las "
    "paredes de la caverna. Seguramente seran usadas por los mineros.\n");

  AddDetail(({"estanterias","estanteria"}),
  "Las paredes de esta galeria almacen estan llenas de ellas.\n");

  AddDetail(({"cajones","cajon"}),SF(mirar_cajones));

  AddDetail(({"lampara"}),
  "Esta firmemente sujeta al techo iluminando pobrememte este almacen.\n");

  SetIntNoise("No se oye gran cosa.\n");
  SetIntSmell("Huele a polvo y tierra.\n");
  SetLocate("minas de Zarkam");
  SetIndoors(1);
  SetIntBright(50);

  AddExit("este",Z_MINAS("/nivel0/caverna6"));
  AddExit("norte",Z_MINAS("/nivel0/almacen1"));

  AddRoomCmd("coger",SF(coger_cmd));
  reset();
}
