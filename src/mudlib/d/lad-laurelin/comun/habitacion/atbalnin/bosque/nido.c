#include "path.h"
#include <skills.h>
#include <moving.h>

inherit LAD_ROOM_EX;

static int pluma, cascara;

fin_espera_buscar(object pl)
{
  pl->Set("_Buscar", 0);
}

int cmd_buscar(string str)
{
  object ob;
  int perc;

  if (!TP || !interactive(TP)) {
  	return 0;
  }
  if (TP->Query("_Buscar"))
  {
    write("Te cansas de tanto buscar y esperas un poco.\n");
    return 1;
  }

  write("Te pones a buscar por el nido por si encuentras algo.\n");
  TP->Set("_Buscar", 1);
  call_out("fin_espera_buscar", 1, TP);
  perc=TP->UseSkill(HAB_RASTREAR,-10);
  if (perc<1)
  {
    write("No encuentras nada de valor.\n");
    return 1;
  }

  if (!pluma)
  {
    ob=clone_object(QUEST+"pluma");
    ob->move(TO, M_SILENT);
    ob->Set("from", "lad laurelin");
    write("Encuentras la pluma de un polluelo de Wyvelt.\n");
    pluma=1;
    return 1;
  }

  perc=TP->UseSkill(HAB_RASTREAR,-85);
  if (perc<1)
  {
    write("No encuentras nada de valor.\n");
    return 1;
  }
/*
  if (!cascara)
  {
    ob=clone_object(QUEST+"cascara");
    ob->move(TO, M_SILENT);
    ob->Set("from", "lad laurelin");
    ob->SetValue(100000);
    write("Encuentras un trozo de cáscara de un huevo de Wyvelt.\n");
    cascara=1;
    return 1;
  }
*/
  write("No encuentras nada de valor.\n");
  return 1;
}

cmd_hacer()
{
  write("No puedes hacer eso aqui.\n");
  return 1;
}

reset()
{
  ::reset();
  cascara=pluma=0;
}

create(){
  object ob;
  ::create();
  seteuid(getuid());
  SetIntLong(W("Es el nido de algún Wyvelt. Desde luego eran pájaros "
  	"grandes. Por la cantidad de hojas que lo cubre, podrías asegurar "
  	"que está deshabitado. Quizás hasta tengas suerte y si buscas "
  	"encuentres algo.\n"));

  SetIntShort("el nido de un Wyvelt");

  SetLocate("el bosque de Atbalnin");
  SetIndoors(0);

  AddExit("salir", ATB_B("copa-del-arbol"));
  AddRoomCmd("hacer", SF(cmd_hacer));
  AddRoomCmd("buscar", SF(cmd_buscar));
}