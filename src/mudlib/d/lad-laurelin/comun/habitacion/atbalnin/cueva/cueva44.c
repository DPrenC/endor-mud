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
  ob=clone_object(QUEST+"/librobien");
  ob->move(TP);
  write("Coges el libro... �y todo a tu alrededor se disuelve!\n");
  write("Apareces en la ciudad de atbalnin, al lado del mendigo.\n");
  TP->move(ATB_CI("ciudad37"));
  return 1;
}

create(){
  object ob;
  ::create();

  SetIntLong(W("Est�s frente a un pedestal blanco. A su alrededor hay diversas "
  	"figuras que forman curiosas formas. Sobre el pedestal hay un libro.\n"));
  AddDetail("libro", "Es el libro de la Perduraci�n.\n");
  AddDetail(({"figura", "figuras"}), "Hay un c�rculo de figuras que rodean "
  	"el pedestal.\n");
  AddDetail("pedestal", "Es de m�rmol blanco. En el centro hay un libro.\n");
  AddExit("oeste", ATB_C("cueva43"));
  AddRoomCmd("coger", "cmd_coger");
}

