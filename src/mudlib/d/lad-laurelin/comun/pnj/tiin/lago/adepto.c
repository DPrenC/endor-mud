/*
DESCRIPCION    : adepto muerto
FICHERO        :
CREACION       : 12-2-99 Alura
U.MODIFICACION :
*/

#include "path.h"
#include <moving.h>
#include <properties.h>


inherit "std/undead";

move(dest,method,stuff)
{
 if(method==M_GO && dest->QueryLocate()!="templo de Dehim")
    return ME_NO_ENTER;
        return ::move(dest,method,stuff);
        }

create() {
  ::create();
  SetStandard("un adepto no-muerto","adepto",26,GENERO_MASCULINO);
  SetShort("un adepto no-muerto");
  SetLong(
  "Esta pobre alma no consiguio ser monje en vida, y ahora no es mas que el re-\n"
  "flejo de lo que fue.\n");
  SetRace("no-muerto");
  SetIds(({"zombie","muerto","adepto"}));
  SetAds(({"desfigurado","demacrado"}));
  SetAlign(0);
  SetSize(P_SIZE_MEDIUM);
  SetAC(0);
  SetHands(({({"mano derecha",1,1}),({"mano izquierda",0,1})}));
  SetAggressive(0);

}
