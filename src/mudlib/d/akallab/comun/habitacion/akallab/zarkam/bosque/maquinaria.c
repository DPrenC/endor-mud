/*
DESCRIPCION  : Maquinaria (Aserradero en el bosque)
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/bosque/bosque_??.c
MODIFICACION : 13-04-98 [Elric@Simauria] Creacion
               10-10-98 [Angor@Simauria] Rehecha
               26-10-99 [Angor@Simauria] modificacion/quest
			   04-11-99 [Angor@Simauria] Parcheado bug "coger todo" del quest
--------------------------------------------------------------------------------
*/

#include "path.h"
#include AK_MACRO
#include <messages.h>
#include <moving.h>


inherit ROOM;

public int coger_cmd(string str){
  object ob1,ob2,ob3;
  if (!TP) return 0;

  ob2=present("escalera",environment(TP));
  if ((str=="todo") && (ob2))
     {
	 write("Quieres llevarte a casa toneladas de maquinaria? Si no puedes con ella...\n");
  	 return 1;
	 }

  if (str=="escalera")
      {
      ob2=present("escalera",environment(TP));
      if (!ob2) return 0;

      ob1=present("senko",environment(TP));
      if (!ob1 || !living(ob1)) return 0;

      if (present("cubo",ob1) && present("tablon",ob1) && present("serrucho",ob1))
         {
         tell_room(TO, ({ MSG_SEE, NOMBRE+" coge una escalera de madera.\n" }) );
         write("Senko, entretenido reparando el engranaje de la sierra te "
            "dice: Puedes llevarte la escalera, pero luego la devuelves.\n");

         if (!(ob2->move(TP)))
            write("Senko dice: Ja, ja... no puedes con la escalera eh!\n");

         ob3=present("cubo",ob1); ob3->remove();
         ob3=present("tablon",ob1); ob3->remove();
         ob3=present("serrucho",ob1); ob3->remove();

         return 1;
         }
      else
         {
         write("Senko te dice: deja ahi esa maldita escalera y ayudame a "
               "reparar esto de una vez...\n");
         return 1;
         }
      }
      else return 0;
   return 0;
  }


create() {
  ::create();
  SetIntShort("la maquinaria del aserradero");
  SetIntLong(
  "Frente a ti se hallan unas grandes sierras mecanicas y toda una serie de "
    "engranajes encargados de moverlas con la fuerza del agua embalsada en la "
    "presa. Con estas sierras los orcos convierten los troncos del bosque en "
    "grandes tablones que por lo que ves, hasta ser transportados a Zarkam, "
    "guardan en el almacen que queda al norte. Una gran puerta de doble hoja "
    "al oeste, permite entrar a los carros a por la madera. El suelo esta "
    "lleno de serrin.\n");

  AddDetail(({"puerta"}),
  "Es una gran puerta de doble hoja. Es lo suficientemente grande como "
    "para que los grandes carros que vienen a por madera desde Zarkam puedan "
    "entrar aqui a cargar.\n");

  AddDetail(({"engranaje","engranajes"}),
  "Ves muchos tipos distintos de engranajes, pero aun asi, se sincronizan "
    "entre ellos haciendo mover las sierras que cortan la madera.\n");

  AddDetail(({"sierra","sierras"}),
  "Grandes y afiladas sierras, la mayoria circulares, se encargan de "
    "cortar los troncos de madera formando tablones mas manejables y faciles "
    "de transportar.\n");

  AddDetail(({"madera","troncos"}),
  "La madera ya cortada se apila sobre unos carros para ser transportada a "
    "otro lugar.\n");

  SetIntNoise("El ruido de la maquinaria te impide oir cualquier otra cosa.\n");
  SetIntSmell("Inspiras fuertemente y tus fosas nasales se llenan de serrin. "
              "Aaachiiisss...!!!\n");
  SetLocate("bosque de Zarkam");
  SetIndoors(1);
  SetIntBright(50);

  AddExit("sur",Z_BOSQUE("cabanya"));
  AddExit("este",Z_BOSQUE("presa"));
  AddExit("norte",Z_BOSQUE("almacen"));
  AddExit("oeste",Z_BOSQUE("bosque_64"));

  AddItem(QUEST+"amuleto/lenyador", REFRESH_DESTRUCT);
  AddItem(QUEST+"amuleto/escalera", REFRESH_DESTRUCT);

  AddRoomCmd("coger","coger_cmd");
}
