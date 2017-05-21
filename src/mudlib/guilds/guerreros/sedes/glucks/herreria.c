/*
** Una simple herrería
** En ella, los guerreros pueden reparar armas y armaduras.
** Basada en la herrería del Gremio de Guerreros de NF.
** Autor: Nemesis@Simauria, Ago'99
** Update: [14-Sep-99] Nemesis: Arreglado lo del reset(). Ahora se lo lleva
**                    TODO. Excepto lo que esté vivo, claro.
*/

#include "/guilds/guerreros/wguild.h"
#include <skills.h>

inherit "/std/room";

public int IsSmithy()
{
  return 1;
}

public int cmd_repair(string str)
{
  if (TP&&TP->QueryAttr(HAB_REPARAR,1)) return 0;
  return notify_fail("El martillo es demasiado pesado para ti.\n"),0;
}

public void create()
{
  ::create();
  SetIntShort("una pequeña herrería");
  SetIntLong("Estás en una pequeña herrería llena de herramientas para\n"
	     "reparar armas y armaduras. En el centro de la habitacion hay\n"
	     "un pesado yunque y un martillo a su lado.\n"
	     "La forja emite un fuerte calor que te hace comenzar a sudar.\n"
        "Su brillo hace que esta habitación esté bañada en una luz rojiza.\n"
        "La señora de la limpieza viene de cuando en cuando, así que no\n"
        "dejes por aquí tiradas cosas que quieras conservar...\n");
  SetIndoors(1);
  SetIntBright(20);
  AddDetail(({"pequeña herrería","herreria","herramientas",
              "pequenya herreria","herrería"}),
    "Está llena de todas las herramientas que un buen herrero necesita\n"
    "para forjar armas poderosas. Pero como no eres herrero, sólo puedes\n"
    "reparar tus armas y armaduras aquí.\n");
  AddDetail(({"armas","armaduras"}),
    "¿No has traido algunas?\n");
  AddDetail(({"yunque","pesado yunque"}),
    "Está fijo al suelo, así que o lo dejas donde está, o te llevas toda\n"
    "la herreria con él...\n");
  AddDetail(({"martillo","martillo al lado del yunque"}),
    "Necesitas ser fuerte para poder usarlo.\n");
  AddDetail("forja",
    "Alguien parece cuidar el fuego. Una pequeña abertura lanza aire\n"
    "sobre la forja para que no deje de brillar.\n");
  AddDetail("fuego",
    "Un fuego chisporroteante.\n");
  AddDetail(({"pequeña abertura","abertura"}),
    "Es más pequeña que un pulgar, pero de ella sale suficiente aire.\n");
  AddDetail("aire",
    "No sabes de dónde viene. Quiza hay pequeños kobolds trabajando en\n"
    "algún sitio.\n");
  AddDetail(({"calor","fuerte calor"}),
    "¿No necesitabas bañarte? A partir de ahora sí.\n");

  AddRoomCmd("repair",SF(cmd_repair));
  AddExit("arriba","./sede_glucksfall");
}

reset()
{
   object items;
   int check,i;

   check=0;
   i=0;
   items=all_inventory(TO);
 while(i<sizeof(items))
 {
  if (!living(items[i]))
  {
   items[i]->remove();
   if (items[i]) items[i]->destruct();
   check++;
  }
  i++;
 }
   if(check) tell_room(TO,
      "La señora de la limpieza llega y se lleva los articulos que había tirados.\n");
   else tell_room(TO,
      "La señora de la limpieza llega y se vuelve a marchar.\n");
   ::reset();
}
