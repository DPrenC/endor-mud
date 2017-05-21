/***
fichero: /guilds/guardabosques/train/ladera.c
30/08/2004. Kastwey@simauria. Puestos los mensajes de salida para las acciones del player.
***/

#include "path.h"

inherit TRAIN_BASE;

int cmd_sur()
{
  write(W("Después de caminar un rato y de rodear la montaña, llegas hasta "+
  	"las inmediaciones del gremio, donde empezaste el entrenamiento.\n"));
  say(W(capitalize(TP->QueryName()) + " se va hacia el sur.\n"),TP);
  TP->move(TRAIN+"entrenamiento");
tell_room(TRAIN + "entrenamiento",W(capitalize(TP->QueryName()) + " llega.\n"));
return 1;
}
create()
{
  ::create();

  SetIntShort("la ladera de la montaña");
  SetIntLong(W("Hacia el este ves una montaña, en cuya ladera estás ahora. "
  	"Podrías intentar llegar a la cima pero seguro que tendrás cosas "
  	"mejor que hacer. Parece haber un camino hacia el sur que la rodea.\n"));
  AddExit("sur", SF(cmd_sur));
}
