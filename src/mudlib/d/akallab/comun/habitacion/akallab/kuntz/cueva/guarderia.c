/*
DESCRIPCION  : Guarderia en las cavernas Troll
FICHERO      : /d/akallab/comun/rooms/akallab/kuntz/cueva/guarderia.c
MODIFICACION : 24-11-99 [Angor@Simauria] Creacion
*/

#include "path.h"
#include <skills.h>
#include AK_MACRO
#include <moving.h>



inherit ROOM;

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
    write("El uso de tus habilidades te ha agotado. Esperas un poco.\n");
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
    ob->Set("from", "akallab");
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
    ob->Set("from", "akallab");
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

reset(){
  ::reset();
  pluma=cascara=0;
}

create() {
  ::create();
  seteuid(getuid());
  SetIntShort("una guardería troll");
  SetIntLong(
  "Estas en una galleria subterranea utilizada por los Troll como guardería. "
    "Es aquí donde suelen dejar a las crías al cuidado de algun troll "
	"cuando los adultos salen de cacería. Al fondo de la galeria hay "
	"un monton del hierba y ramas secas esparcidas por el suelo, y una pila "
	"de huesos con los pequeños troll juegan.\n");

  AddDetail(({"monton de hierba","hierba","monton","ramas","ramas secas"}),
  "Al fondo de la galeria se amontona un monton de hierba y ramas secas. "
    "Es alli donde duermen los retonyos troll de la guardera cuando no "
	"estan jugando o peleandose entre ellos, y donde reposa un montón "
	"de huesos.\n");

 SetIntNoise("Oyes el goteo del agua.\n");
 SetIntSmell("Huele.... ¡¡a troll!!.\n");
 SetLocate("cavernas Troll en Kuntz");
 SetIndoors(1);
 SetIntBright(0);

 AddExit("nordeste",K_CUEVA("caverna11"));
 AddItem(PNJ("k_cueva/guardia2"), REFRESH_DESTRUCT,2);
 AddItem(PNJ("k_cueva/crio_troll"), REFRESH_DESTRUCT,5);
 AddItem(OTRO("monton_calaveras"), REFRESH_DESTRUCT);

 AddRoomCmd("buscar", "cmd_buscar");
}
