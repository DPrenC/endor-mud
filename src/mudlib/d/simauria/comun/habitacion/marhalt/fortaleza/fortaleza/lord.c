/*
DESCRIPCION  : habitacion del lord, el jefe jefazo, malo maloso
FICHERO      : lord.c
MODIFICACION : 16-07-00 [Maler] Creacion
*/

//Cambiar 7 por 0 en la l�nea siguiente para quitar enculadas
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
    SetIntShort("el sal�n del trono");
    SetIntLong("Est�s en el sal�n del trono. Aqu�, el jefe de la banda de bandidos "
    "impone su voluntad sobre el resto de sus hombres. Una harapienta "
    "alfombra roja baja desde el trono hasta tu posici�n. Los tiempos de gloria "
    "de esta habitaci�n est�n muy distantes ya, y s�lo son un eco de lo que llegaron a ser en el pasado.\n");
    SetIndoors(1);
    AddExit("sur",ROOMFF("patio15"));
    AddDoor("sur", "un gran port�n",
    "Es una enorme puerta de madera maciza.\n", ({"port�n", "puerta", "gran port�n",
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
                           " fue penetrado por el gorila cipot�n.\n");
      "/obj/chmaster"->SendEmote("info",capitalize(getuid(TP))+
                                   " fue penetrado por el gorila cipot�n.");
      write(W(
      "Un gorila cipot�n empu�ando un bote de Vicks Vapor'ub sale de entre "
      "las columnas donde se escond�a y te la enchufa doblada por todo el "
      "ano, dej�ndote dolorido y casi sin respiraci�n.\n"));
      write(W(
      "El gorila te pone un poco de Vicks en el pechito, y respiras mejor.\n"));
      say(W(
      "Un gorila cipot�n empu�ando un bote de Vicks Vapor'ub sale de entre "
      "las columnas donde se escond�a y se la enchufa doblada por todo el "
      "ano a "+TP->QueryName()+", dej�ndole dolorido y casi sin "
      "respiraci�n.\n"));
      say(W(
      "El gorila le pone un poco de Vicks en el pechito a "+
      TP->QueryName()+", y parece que respira mejor.\n"));
   }
   return 0;
}

