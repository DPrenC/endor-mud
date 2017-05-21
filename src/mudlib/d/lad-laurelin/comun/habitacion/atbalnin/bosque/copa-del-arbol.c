#include "path.h"
#include <skills.h>
#include <moving.h>
#include <damage.h>


inherit LAD_ROOM_EX;

#define Me capitalize(TI->QueryName())
int cmd_bajar(string str)
{
  int perc;

  perc=TI->UseSkill(HAB_TREPAR);
  if (perc<-50)
  {
    write("¡La cuerda se te escapa por entre los dedos y caes haciendote daño!\n");
    say(W("A "+Me+" se le escapa la cuerda por entre los dedos y cae dolorosamente.\n"));
    TI->Defend(50-(100+perc), DT_BLUDGEON);
    TI->move(ATB_B("bosque24"), M_SPECIAL, " cae desde arriba con un fuerte golpe");
  }
  else if (perc<0)
  {
    write("¡La cuerda se te escapa por entre los dedos y caes!\n");
    say(W("A "+Me+" se le escapa la cuerda por entre los dedos y cae.\n"));
    TI->move(ATB_B("bosque24"), M_SPECIAL, " cae desde arriba con un fuerte golpe");
  }
  else
    TI->move(ATB_B("bosque24"), M_SPECIAL, Me+" baja trepando por la cuerda");
  return 1;
}


create(){
  ::create();

  SetIntLong(W("Estás en la copa de un inmenso árbol. Y por supuesto "
  	"el tamaño del nido que está frente a tí hace juego con el resto.\n"));
  SetIntShort("la copa de un árbol");
  AddItem(QUEST+"nido", REFRESH_DESTRUCT);

  SetLocate("el bosque de Atbalnin");
  SetIndoors(0);

  AddExit("bajar", SF(cmd_bajar));
  AddExit("nido", ATB_B("nido"));
}
