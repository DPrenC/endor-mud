/*
DESCRIPCION  : Galeria que conduce a la cueva del jefe
FICHERO      : /d/akallab/comun/rooms/akallab/kuntz/cueva/jefe00.c
MODIFICACION : 11-12-99 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
#include <messages.h>
#include <moving.h>



inherit ROOM;

int ir_o()
{
object obj,obj2,obj3;
int cuenco, vacio;

obj3=clone_object(COMIDA("frutos_bosque"));

if (TP->QueryIsPlayer())
   {
   //sin guardias, pasas
   if (!present("guardia",TO))
      return TP->move(K_CUEVA("jefe01"),M_SPECIAL,
      ({"se va hacia el oeste","llega desde el este"}));

   //con guardias necesitas "regalo"
   cuenco=0;
   vacio=1;
   FORALL(obj,TP)
     {
	 if (obj->QueryIds())
	    {
	    if (member(obj->QueryIds(), "cuenco")!=-1)
	       {
		   cuenco=1;
	       if ((obj->QueryContenido())==(obj3->QueryShort()))
		      {
		      vacio=0;
		      obj2=obj;
		      }
		   }
	     }
	  }
   if (cuenco==0)
      {
	  write("El jefe de los guardias te dice: Eres un maldito extranjero "
	        "al que no conzco y quieres pasar a ver al jefe... Mmmmm... "
			"Que interes puede tener el jefe en ti? ademas, no traes nada "
			"que ofrecerle, nisiquiera un maldito cuenco con comida. Vete "
			"a molestar a otra parte.\n");
      tell_room(TO, ({ MSG_SEE, "El jefe de los guardias no deja pasar a "+TP->QueryName()+
	    " a la caverna del jefe.\n"}), ({TP}));
	  return 1;
	  }
   else if (vacio==1)
           {
      write("El jefe de los guardias te dice: Eres un maldito extranjero "
	        "al que no conzco y quieres pasar a ver al jefe... Mmmmm... "
			"Que interes puede tener el jefe en ti? ademas, no traes nada "
			"que ofrecerle... Tienes un cuenco de comida, pero esta vacio. "
			"Vete a molestar a otra parte.\n");
	  tell_room(TO, ({ MSG_SEE, "El jefe de los guardias no deja pasar a "+TP->QueryName()+
	    " a la caverna del jefe.\n"}), ({TP}));
	  return 1;
		   }
	    else
		   {
      write("El jefe de los guardias te dice: Eres un maldito extranjero "
	        "al que no conzco y quieres pasar a ver al jefe... Mmmmm... "
			"Que interes puede tener el jefe en ti? ademas, no traes nada "
			"que ofrecerle... un momento!... tienes un cuenco con comida... "
			"No es que sea gran cosa y dudo que te haga mucho caso, pero "
			"bueno, puedes pasar. Yo me quedare con el cuenco de comida y "
			"ya se lo dare mas tarde... Ah!, por cierto, hoy no esta de muy "
			"buen humor...\n");
	  tell_room(TO, ({ MSG_SEE, "El jefe de los guardias deja pasar a "+TP->QueryName()+
	    " a la caverna del jefe.\n"}),({TP}));
      obj2->remove();
	  return TP->move(K_CUEVA("jefe01"),M_SPECIAL,
	         ({"se va hacia el oeste","llega desde el este"}));
		   }
    }

//el pnj pasa sin problemas
return TP->move(K_CUEVA("jefe01"),M_SPECIAL,
       ({"se va hacia el oeste","llega desde el este"}));
}

create(){
  ::create();
  SetIntShort("una galería que conduce a la cueva del jefe");
  SetIntLong(
  "Te encuentras en la galeria que conduce desde la Gran Caverna hacia la "
    "cueva del jefe de la tribu. La galeria es relativamente ancha y en ella "
	"suele encontrarse la guardia personal del jefe de la tribu para controlar "
	"quien puede y quien no acceder a la cueva.\n");

 SetIntNoise("Oyes el goteo del agua.\n");
 SetIntSmell("Huele.... a troll!!.\n");
 SetLocate("cavernas Troll en Kuntz");
 SetIndoors(1);
 SetIntBright(0);

 AddExit("nordeste",K_CUEVA("caverna19"));
 //AddExit("oeste",K_CUEVA("jefe01"));
 AddExit("oeste",SF(ir_o));

 AddItem(PNJ("k_cueva/guardia_jefe"), REFRESH_DESTRUCT,4);
 AddItem(OTRO("monton_calaveras"), REFRESH_DESTRUCT);
}
