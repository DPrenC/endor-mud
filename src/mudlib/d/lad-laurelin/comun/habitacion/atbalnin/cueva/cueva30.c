#include "path.h"
#include <door.h>

inherit ATB_C("aleat_cueva");

int cmd_coger(string w)
{
  object ob;
  if (w!="libro") return 0;
  if (sizeof(TI->QueryEnemies()||({})))
  {
    write("No puedes hacer eso con enemigos a tu alrededor.\n");
    return 1;
  }

  seteuid(getuid());
  ob=present("libromal", TP);
  if (ob) ob->remove();
  ob=present("libroneutro", TP);
  if (ob) ob->remove();
  ob=present("librobien", TP);
  if (ob) ob->remove();
  ob=clone_object(QUEST+"/libromal");
  ob->move(TP);
  write("Coges el libro... ¡y todo a tu alrededor se disuelve!\n");
  write("Apareces en la ciudad de atbalnin, al lado del mendigo.\n");
  TP->move(ATB_CI("ciudad37"));
  return 1;
}

create(){
  object ob;
  ::create();

  SetIntLong(W("Estás frente a un pedestal negro. A su alrededor hay diversos "
  	"cráneos bastante bien ordenados. En el centro del pedestal hay un "
  	"libro.\n"));
  AddDetail("libro", "Es el libro de la Destrucción.\n");
  AddDetail(({"craneos", "cráneos"}), "Hay un círculo de cráneos que rodean "
  	"el pedestal.\n");
  AddDetail("pedestal", "Es de color negro, posiblemente de mármol. En el "
  	"centro hay un libro.\n");
  AddExit("noroeste", ATB_C("cueva29"));
  AddRoomCmd("coger", "cmd_coger");
}

