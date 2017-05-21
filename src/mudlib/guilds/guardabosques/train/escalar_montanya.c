/***
fichero: /guilds/guardabosques/train/escalar_montanya.c
30/08/2004. Kastwey@simauria. Puesto los mensajes de salida para las acciones del player.
31/08/2004. A�adido el allow_enter para evitar entradas no permitidas... puertas dimensionales, etc.
***/
#include "path.h"

inherit TRAIN_BASE;


int cmd_escalar(string str)
{
  int perc;

  write("Empiezas a escalar...\n");
  say (W(capitalize(TP->QueryName()) + " comienza a escalar por la monta�a...\n"),TP);
  perc=TP->UseSkill(HAB_TREPAR, -30);
  if (perc<1)
  {
    write("�No encuentras un punto de apoyo y caes al vac�o!\n");
    say(W("No encuentra un punto de apoyo y cae al vac�o!\n"),TP);
    SetDieMsg(TP->QueryName()+" se despe�a por una monta�a y muere.\n");
    TP->Defend(random(-(perc/3)));
    return 1;
  }
  write("Milagrosamente consigues escalar hasta un peque�o saliente.\n");
  say(W("Sorprendentemente, " + capitalize(TP->QueryName()) + " consigue llegar hasta un peque�o saliente.\n"),TP);
  tell_room(TRAIN + "montanya",W(capitalize(TP->QueryName()) + " llega escalando desde la base de la monta�a.\n"));
  TP->move(TRAIN+"montanya");

  return 1;
}

create()
{
  ::create();

  SetIntShort("la base de una monta�a");
  SetIntLong(W("Est�s en la base de una monta�a. Podr�as intentar escalar "
  	"hasta un peque�o saliente, pero la pared es extremadamente lisa, "
  	"lo cual hace muy dificil el poder escalar hasta arriba. Adem�s no "
  	"hay nada que amortigue la ca�da.\n"));
  AddDetail("saliente", "Es un saliente de la monta�a como otro cualquiera.\n");
  AddExit("este", TRAIN+"escalar");
  AddRoomCmd("escalar", SF(cmd_escalar));
}
