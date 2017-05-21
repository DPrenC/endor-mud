/*=============================================================*
 |         << GOLDHAI.Acantilado [w] Woo@simauria >>           |
 *=============================================================*
 |            Creacion.................. 29-10-98              |
 |            Ultima Modificacion....... 23-03-00              |
 |                                                             |
 *=============================================================*/

#include "./path.h"
#include <skills.h>
#include <moving.h>

inherit GACANTILADO;

static int pluma, cascara;

fin_espera_buscar(object pl)
{
  pl->Set("_Buscar", 0);
}

int cmd_buscar(string str)
{
  object ob;
  int perc;

  if (TP->Query("_Buscar"))
  {
    write("El uso de tus habilidades te ha agotado. Decides descansar un poco.\n");
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
    ob=clone_object("/d/lad-laurelin/comun/quest/pluma");
    ob->move(TO, M_SILENT);
    ob->Set("from", "goldhai");
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
    ob=clone_object("/d/lad-laurelin/comun/quest/cascara");
    ob->move(TO, M_SILENT);
    ob->Set("aux", "goldhai");
    ob->SetValue(100000);
    write("Encuentras un trozo de cáscara de un huevo de Wyvelt.\n");
    cascara=1;
    return 1;
  }
*/
  write("No encuentras nada de valor.\n");
  return 1;
}


int cmd_hacer()
{
  write("No puedes hacer eso aqui.\n");
  return 1;
}

reset(){
  ::reset();
  pluma=cascara=0;
}

create(){
  ::create();

  seteuid(getuid());
  SetIntLong("Estás en un nido un tanto destruído por el intenso viento. Lo que mejor se "
  	"mantiene es la parte interior, pues al ser tan grande el viento tan sólo azota la parte "
  	"esterna. Te viene a la memoria una leyenda de un gran ave, un enorme pájaro llamado "
  	"Wyvelt, extinguidos hace mucho tiempo. Eran aves maravillosas y, como los dragones, "
  	"tenían la manía de guardar cosas. Quizás hasta tengas suerte y si buscas "
  	"encuentres algo.\n");

  SetIntShort("el nido de un Wyvelt");

  SetLocate("nido de Wyvelt del acantilado de Goldhai");
  SetIndoors(0);
  AddRoomCmd("hacer", SF(cmd_hacer));
  AddExit("salir", ACANTILADO("saliente"));
  AddRoomCmd("buscar", SF(cmd_buscar));
}