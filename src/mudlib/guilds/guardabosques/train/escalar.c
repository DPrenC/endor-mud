/***
fichero /guilds/guardabosques/train/escalar.c
30/08/2004. Kastwey@simauria. Arreglado algunos returns y puesto mensajes de salida
para la room.
***/

#include "path.h"
inherit TRAIN_BASE;


int cmd_escalar(string str)
{
  int perc;

  write("Empiezas a trepar por la cuerda...\n");
  say (W(capitalize(TP->QueryName()) + " empieza a trepar por la cuerda...\n"),TP);
  perc=TP->UseSkill(HAB_TREPAR);

  if (perc<1)
{
	write (W("�Pero se te resbala por entre los dedos y "
    	"caes!\nAfortunadamente la red amortigua tu ca�da y no "
    	"sufres ning�n da�o.\n"));
say (W("pero se le resbala por entre los dedos y cae!\n"),TP);
}
else
{

 write("Has escalado hasta la copa del arbol.\n");
  say (W(capitalize(TP->QueryName()) + " consigue escalar hasta la copa del �rbol.\n"),TP);
  tell_room(TRAIN + "saltar",W(capitalize(TP->QueryName()) + " llega trepando por una de las cuerdas.\n"));
  TP->move(TRAIN+"saltar");
}

  return 1;
}

create()
{
  ::create();

SetIntShort("la zona de escalada");
SetIntLong(W("Est�s en una zona al aire libre del gremio de los "
  	"guardabosques. Frente a ti hay un enorme �rbol, con diversas cuerdas "
  	"que puedes usar para escalarlo. Hacia el oeste ves una peque�a e "
  	"inaccesible monta�a. Aunque quiz�s podr�as llegar hasta ese saliente "
  	"si escalaras el �rbol, en cuya base ves una red, por si acaso "
  	"fallas en la escalada y te caes.\n"));
  AddDetail(({"arbol", "�rbol"}), "Es un �rbol enorme que puedes "
  	"escalar.\n");
  AddDetail(({"monta�a", "montanya"}), W("Es una monta�a bastante peque�a, "
  	"con unas laderas totalmente lisas y verticales. Quiz�s pudieras "
  	"llegar hasta ella escalando el �rbol y luego saltando hasta un "
  	"peque�o saliente que puedes ver.\n"));
  AddDetail("saliente", "Es un saliente de la monta�a como otro cualquiera.\n");
  AddDetail(({"cuerda", "cuerdas"}), "Ves varias cuerdas atadas a las ramas "
  	"del �rbol. Las podr�as usar para escalar.\n");
  AddExit("sur", TRAIN+"entrenamiento");
  AddExit("oeste", TRAIN+"escalar_montanya");
  AddRoomCmd("escalar", SF(cmd_escalar));
}
