/*
DESCRIPCION  : habitacion del lord, el jefe jefazo, malo maloso
FICHERO      : lord.c
MODIFICACION : 16-07-00 [Maler] Creacion
*/

//Cambiar 7 por 0 en la línea siguiente para quitar enculadas
#define ENCULE 666
#include "path.h"
#include <living.h>
#include <door.h>
#include <sounds.h>

inherit ROOMFF("fortalez");
object pelas;
void Destruct(object obj)
{
 if (!obj) return;
 catch(obj->remove());
 if (obj) destruct(obj);
}

create()
{
    ::create();
    SetIntShort("el salón del trono");
    SetIntLong("Estás en el salón del trono. Aquí, el jefe de la banda de bandidos "
    "impone su voluntad sobre el resto de sus hombres. Una harapienta "
    "alfombra roja baja desde el trono hasta tu posición. Los tiempos de gloria "
    "de esta habitación están muy distantes ya, y sólo son un eco de lo que llegaron a ser en el pasado.\n");
    SetIndoors(1);
    AddExit("sur",ROOMFF("patio15"));
    AddDoor("sur", "un gran portón",
    "Es una enorme puerta de madera maciza.\n", ({"portón", "puerta", "gran portón",
    "gran porton", "porton"}), GENDER_MALE,
    ([P_DOOR_CLOSE_SOUND: SND_SUCESOS("cerrar_porton"),
    P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_porton")]));
    AddItem(PNJFF("lord"),REFRESH_REMOVE);
  }

void init()
{
   ::init();
   if(ENCULE == 7)
   {
      if(!present("dinero",TO))
      {
         pelas=clone_object("/obj/money");
        pelas->AdjustMoney( (["mithril":10]) );
         pelas->move(TO);
      }
      add_action("Enculada","coger");
   }
}

int Enculada(string arg)
{
   if(!arg) return 0;
   if(!present(arg,environment(TP))) return 0;
   if(present(arg,environment(TP)) == pelas)
    {
      Destruct(pelas);
    }

   if(TP && TP->QueryGender() == MALE)
   {
      log_file("ENCULADOS","*** "+ctime(time())+" "+capitalize(getuid(TP))+
                           " fue penetrado por el gorila cipotón.\n");
      "/obj/chmaster"->SendEmote("info",capitalize(getuid(TP))+
                                   " fue penetrado por el gorila cipotón.");
      write(W(
      "Un gorila cipotón empuñando un bote de Vicks Vapor'ub sale de entre "
      "las columnas donde se escondía y te la enchufa doblada por todo el "
      "ano, dejándote dolorido y casi sin respiración.\n"));
      write(W(
      "El gorila te pone un poco de Vicks en el pechito, y respiras mejor.\n"));
      say(W(
      "Un gorila cipotón empuñando un bote de Vicks Vapor'ub sale de entre "
      "las columnas donde se escondía y se la enchufa doblada por todo el "
      "ano a "+TP->QueryName()+", dejándole dolorido y casi sin "
      "respiración.\n"));
      say(W(
      "El gorila le pone un poco de Vicks en el pechito a "+
      TP->QueryName()+", y parece que respira mejor.\n"));
   }
   return 0;
}

