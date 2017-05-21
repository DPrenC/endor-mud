/*
DESCRIPCION  : Molino de Gaddaro
FICHERO      : /d/akallab/comun/habitacion/akallab/azzor/gaddaro/molino.c
MODIFICACION :
18-02-99 [Angor] Creacion
16-09-07 [Angor] Typos
*/

#include "path.h"
#include <config.h> //por NOTIFY_NOT_CMD
#include AK_MACRO
#include <messages.h>
inherit ROOM;

int usar_cmd(string str) {
  string que,donde;
  object ob;

  if (!str) return notify_fail("Que es lo que quieres usar?\n",NOTIFY_NOT_VALID)&&0;
  if (sscanf(str,"%s con %s",que,donde)<2) return notify_fail("Usar que con que?\n"),0;
  ob  =  present(que,TP);
  if (!ob) return notify_fail("Tu no tienes "+que+".\n",NOTIFY_NOT_VALID)&&0;
  if (((que=="trigo")||(que=="espigas"))&&(donde=="molino"))
     {
     write("Pones en marcha los engranajes del molino y mueles en el el "
           "trigo.\nDetienes el molino y recoges la harina y el salvado "
           "que has obtenido.\n");
     tell_room(TO, ({ MSG_SEE, NOMBRE+" muele un manojo de espigas de trigo en el molino.\n"}), ({ TP }));
     ob->remove();
     ob=clone_object(COMIDA("harina"));
     ob->move(TP);
     ob=clone_object(QUEST+"curandera/salvado");
     ob->move(TP);
     return 1;
     }
  else
     {
     if (donde=="molino") {write("No puedes usar "+que+" con molino.\n");return 1;}
     write("Usar "+que+" con que? Tal vez con el molino...\n");
     return 1;
     }
}


int moler_cmd(string str) {
  object ob;
  if (!str) return notify_fail("Que es lo que quieres moler?\n",NOTIFY_NOT_VALID)&&0;
  ob  =  present(str,TP);
  if (!ob) return notify_fail("Tu no tienes "+str+".\n",NOTIFY_NOT_VALID)&&0;
  if ((str=="trigo")||(str=="espigas")) return usar_cmd(str+" con molino");
  else return notify_fail("El molino no es para moler "+str+".\n",NOTIFY_NOT_VALID)&&0;
}


create() {
  ::create();
 SetIntShort("el molino de Gaddaro");
  SetIntLong(
    "Te encuentras en el interior del molino de Gaddaro. Es una construcción "
    "de mediano tamaño hecha de piedra junto al río. La fuerza del agua del "
    "río hace girar una gran rueda de madera en el exterior del molino. "
    "Los grandes engranajes que ves aqui dentro emplean esa fuerza de giro "
    "para mover una pesada piedra de moler. Los habitantes de Gaddaro "
    "muelen aqui el trigo cosechado en los campos para obtener harina.\n");

  AddDetail(({"molino"}),QueryIntLong());

  AddDetail(({"rueda","gran rueda"}),
  "En el exterior del molino hay una gran rueda de madera situada sobre el "
    "cauce del río. En la rueda hay una serie de planchas de madera que son "
    "empujadas por el agua al avanzar, haciendo asi que esta gire.\n");

  AddDetail(({"engranajes"}),
  "En el interior del molino puedes observas una serie de grandes engranajes. "
    "Son grandes ruedas dentadas y ejes de madera cuya funcion es la de "
    "transmitir el giro de la rueda exterior a la piedra de moler.\n");

  AddDetail(({"piedra","piedra de moler"}),
  "Para moler se emplean una gran piedra de forma conica truncada que "
    "gira sobre una plancha del mismo material. La piedra es movida por "
    "la accion de los engranajes que transmiten la fuerza del agua del "
    "río. El enorme peso de la piedra hace que al pasar sobre el trigo "
    "rompe y tritura sus semillas. Luego se emplea un tamiz para separar "
    "la harina del salvado.\n");

  SetIntNoise("Oyes el lastimero crujir de los engranajes al girar.\n");
  SetIntSmell("No huele a nada en especial.\n");
  SetLocate("valle de Azzor");
  SetIndoors(1);
  SetIntBright(40);

  AddExit("norte",AZ_CAMINO("camino12"));

  AddRoomCmd("usar",SF(usar_cmd));
  AddRoomCmd("moler",SF(moler_cmd));
}

