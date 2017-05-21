/*
** Una simple herrer�a
** En ella, los guerreros pueden reparar armas y armaduras.
** Basada en la herrer�a del Gremio de Guerreros de NF.
** Autor: Nemesis@Simauria, Ago'99
** Update: [14-Sep-99] Nemesis: Arreglado lo del reset(). Ahora se lo lleva
**                    TODO. Excepto lo que est� vivo, claro.
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
  SetIntShort("una peque�a herrer�a");
  SetIntLong("Est�s en una peque�a herrer�a llena de herramientas para\n"
	     "reparar armas y armaduras. En el centro de la habitacion hay\n"
	     "un pesado yunque y un martillo a su lado.\n"
	     "La forja emite un fuerte calor que te hace comenzar a sudar.\n"
        "Su brillo hace que esta habitaci�n est� ba�ada en una luz rojiza.\n"
        "La se�ora de la limpieza viene de cuando en cuando, as� que no\n"
        "dejes por aqu� tiradas cosas que quieras conservar...\n");
  SetIndoors(1);
  SetIntBright(20);
  AddDetail(({"peque�a herrer�a","herreria","herramientas",
              "pequenya herreria","herrer�a"}),
    "Est� llena de todas las herramientas que un buen herrero necesita\n"
    "para forjar armas poderosas. Pero como no eres herrero, s�lo puedes\n"
    "reparar tus armas y armaduras aqu�.\n");
  AddDetail(({"armas","armaduras"}),
    "�No has traido algunas?\n");
  AddDetail(({"yunque","pesado yunque"}),
    "Est� fijo al suelo, as� que o lo dejas donde est�, o te llevas toda\n"
    "la herreria con �l...\n");
  AddDetail(({"martillo","martillo al lado del yunque"}),
    "Necesitas ser fuerte para poder usarlo.\n");
  AddDetail("forja",
    "Alguien parece cuidar el fuego. Una peque�a abertura lanza aire\n"
    "sobre la forja para que no deje de brillar.\n");
  AddDetail("fuego",
    "Un fuego chisporroteante.\n");
  AddDetail(({"peque�a abertura","abertura"}),
    "Es m�s peque�a que un pulgar, pero de ella sale suficiente aire.\n");
  AddDetail("aire",
    "No sabes de d�nde viene. Quiza hay peque�os kobolds trabajando en\n"
    "alg�n sitio.\n");
  AddDetail(({"calor","fuerte calor"}),
    "�No necesitabas ba�arte? A partir de ahora s�.\n");

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
      "La se�ora de la limpieza llega y se lleva los articulos que hab�a tirados.\n");
   else tell_room(TO,
      "La se�ora de la limpieza llega y se vuelve a marchar.\n");
   ::reset();
}
