/**
 * PPATH asesinos/gremio.c
 */

#include <moving.h>
#include <config.h>
#include "path.h"

inherit GUILD;

public void create_ob() {
  ::create_ob();
  SetGuildMaster("Artemis Entreri");
  SetGuildDomain("simauria");
  SetCreators( ({"Izet","Nyh"}) );

  SetGuildobject(OBJETO("rosanegra"));

  AddExit("suroeste", "./room/tienda1");
  AddExit("arriba" , "/d/simauria/comun/habitacion/marhalt/nandor/cementerio/templo4");
  SetIntShort("el Gremio de las Rosas Negras");
  SetIntLong(W("Has llegado a una sala semienvuelta en penumbras. "
    "A tu alrededor te parece distinguir como si algo se moviera, y al "
    "fijarte mejor te das cuenta de que sólo era una sombra. "
    "Casi parece como si la luz estuviera medida aquí, y como si la "
    "oscuridad tuviese vida propia.\n"));
  SetIntSmell(W("Notas un olor familiar... lirios... "
    "el olor de la muerte.\n"));
  SetIntNoise(W("No oyes nada. El silencio de este lugar es casi agobiante.\n"));
  SetIntBright(40);
  Set(P_TPORT, 0);
  SetGuildclass(GC_ASESINOS);
  SetGuildname(GN_ASESINOS);

}
