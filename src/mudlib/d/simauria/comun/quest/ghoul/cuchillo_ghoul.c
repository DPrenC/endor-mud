/****************
fichero: cuchillo.c
´kastwey@simauria.
Creación: 14/07/2004
Descripción: Un cuchillo para cortarle la cabeza al ghoul del quest de Nandor.
Última modificación: 19/07/2004. Kastwey@simauria.
Modificada la descripción para que no quedase tan cutre.
****************/


#include <combat.h>
#include <properties.h>
#include <materials.h>

inherit WEAPON;

create()
{
::create();
  SetStandard(WT_CUCHILLO,3,P_SIZE_GENERIC,M_PLATA);
  SetShort("Un cuchillo afilado");
  SetLong(W("Es un cuchillo afilado con una hoja de plata. "
  "Aunque no es un cuchillo muy grande, su borde afilado parece poder cortar cualquier cosa.\n"));
  AddId("qghoul_cuchillo");
  AddId("cuchillo");
  AddId("cuchillo de cocina");
  AddId("cuchillo de carnicero");
}
