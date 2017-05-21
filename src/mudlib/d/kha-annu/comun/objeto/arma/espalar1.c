//*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*
//*   espag1.c                          *
//* Archivo de: Gorthem, El forjador    *
//* Email: jorcama@euibbs.upv.es        *
//* Basado en --------.c                *
//* Creacion: 12.05.98                  *
//* Modificacion: 02.11.98              *
//* Agradecimientos:                    *
//*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*/

// Espada larga normal

#include "./path.h"
#include <combat.h>
#include <properties.h>
#include <materials.h>

inherit WEAPON;

create() {
  ::create();
  SetShort("Espada larga");
  SetLong(
"Es una espada larga, normal y corriente, pero puedes notar la finura\n"
"de las forjas enanas. No se ven espadas de esta calidad en todas partes.\n");
  SetStandard(WT_ESPADA, 1, P_SIZE_MEDIUM, M_ACERO);
  SetIds( ({"espada"}) );
  SetAds(({"larga","normal"}));
  SetWC(6);
  SetDamType(DT_SLASH);
  SetWeight(4000);
  SetValue(1000);
  SetResetQuality(100);
}
