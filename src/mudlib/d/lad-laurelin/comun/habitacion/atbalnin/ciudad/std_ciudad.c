#include "path.h"
#include "/secure/wizlevels.h"
#include <weather.h>

inherit LAD_ROOM;

create()
{
  object ob;
  int val_pnjs;

  ::create();
 SetIntLong("Est�s en alg�n lugar de la ciudad de Atbalnin.\n");
  SetIntShort("la ciudad de Atbalnin.");
  SetLocate("la ciudad de Atbalnin");
  SetIntNoise("Oyes muchos y diversos sonidos.\n");
  SetIntSmell("Huele.\n");
  SetIndoors(0);

  AddDetail("ciudad", W("Atbalnin es una ciudad �lfica corriente. Sus "
  	"habitantes viven en caba�as construidas por entre los �rboles, "
  	"en los troncos, las copas, ah� donde haya lugar y no haya que "
  	"alterar demasiado el bosque. Como en la mayor�a de sus ciudades, "
  	"debe haber un riachuelo o un lago que provea de agua a todos sus "
  	"habitantes.\n"
  	"Aunque ahora son tiempos pac�ficos, la estructura de la ciudad "
  	"recuerda a una fortaleza militarizada, ya que est� compuesta por "
  	"dos anillos conc�ntricos. El externo, est� construido alrededor "
  	"de la muralla natural que protege la ciudad y que el bosque ha "
  	"extendido para proteger a sus guardianes, y la parte interna es "
  	"propiamente la ciudad. Sin embargo, esto cambi� hace ya tiempo, y "
  	"ahora hay construcciones de todo tipo en ambos anillos.\n"));

  switch (NIGHTDAY->QueryState())
  {
    case ND_PREDAWN: val_pnjs=8; break;
    case ND_DAWN..ND_POSTNOON: val_pnjs=4; break;
    case ND_PREFALL: val_pnjs=8; break;
    default: val_pnjs=0;
  }

  SetServer(NIGHTDAY);
  if (val_pnjs)
    if (!random(val_pnjs))
      AddItem(DOM_STD+"elfo", REFRESH_REMOVE, 1)[2]->AddWalkZones("/d/lad-laurelin/comun/habitacion/atbalnin/ciudad");
}

int en_obras()
{
  write("No puedes entrar aqu�, est� en construcci�n.\n");
  return 1;
}

