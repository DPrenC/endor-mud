/***
fichero: /guilds/guardabosques/train/saltar.c
30/08/2004. Kastwey@simauria. Puestos los mensajes de salida para las acciones del player.
Arreglado algunos returns.
***/

#include "path.h"

inherit TRAIN_BASE;


int cmd_saltar(string str)
{
  int perc;

  write("Tomas impulso y saltas...\n");
  say(W(capitalize(TP->QueryName()) + " toma impulso y salta...\n"),TP);
  perc=TP->UseSkill(HAB_SALTAR);

  if (perc<1)
  {
    if (perc<-80)
    {
      write(W("�Pero resbalas y caes! Afortunadamente la red "
    	"de seguridad amortigua tu ca�da y no sufres ning�n da�o.\n"));
      say(W("Pero resbala y cae sobre la red!\n"),TP);
      TP->move(TRAIN+"escalar");
    return 1;
    }
    else
    {
write       (W("No consigues llegar hasta el sitio al que pretend�as "
    	"ir. Afortunadamente has conseguido cogerte a una rama y no caer al "
    	"vac�o.\n"));
    say(W("Aunque no consigue llegar a donde pretend�a, consigue agarrarse a una rama y no caer al vac�o.\n"),TP);
    return 1;
    }
    return 1;
  }
  write("Llegas hasta un peque�o saliente de una monta�a.\n");
  say(W("Llega hasta el peque�o saliente de una monta�a.\n"),TP);
tell_room(TRAIN + "montanya",W(capitalize(TP->QueryName()) + " aparece saltando desde abajo.\n"));
TP->move(TRAIN+"montanya");

  return 1;
}

create()
{
  ::create();

  SetIntShort("la copa de un �rbol");
  SetIntLong(W("Est�s en la copa de un �rbol. Puedes ir hacia el suelo bajando "
  	"por la cuerda o si lo prefieres puedes ir saltando por las ramas "
  	"hasta llegar a un saliente de una monta�a que est� hacia el oeste.\n"));
  AddDetail(({"arbol", "�rbol"}), "Es un �rbol bastante grande. Est�s en su "
  	"copa.\n");
  AddDetail(({"cuerda", "cuerdas"}), "Ves varias cuerdas atadas a las ramas "
  	"del �rbol que van hacia el suelo.\n");
  AddDetail(({"monta�a", "montanya"}), W("Es una peque�a monta�a a la que "
  	"puedes llegar saltando de rama en rama.\n"));
  AddDetail(({"saliente"}), "Saltando de rama en rama podr�as llegar hasta "
  	"�l.\n");
  AddExit("bajar", TRAIN+"escalar");
  AddRoomCmd("saltar", SF(cmd_saltar));
}

