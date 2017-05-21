//*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*
//*   espag2.c                          *
//* Archivo de: Gorthem, El forjador    *
//* Email: jorcama@euibbs.upv.es        *
//* Basado en --------.c                *
//* Creacion: 12.05.98                  *
//* Modificacion: 02.11.98              *
//* Agradecimientos:                    *
//* Retocado por [Y] Yandros a 03.11.98 *
//* Hay un ligero problema con el sexo :)*
//*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*/

// Espada larga corta

#include "./path.h"
#include <combat.h>
#include <properties.h>
#include <materials.h>



inherit WEAPON;


create() {
  ::create();
  SetShort("Espada corta");
  SetLong(
"Es una espada corta hecha por los enanos, notas el temple de la hoja cuando\n"
"calibras la espada. Cualquiera que la vea puede pensar que es magica al ver\n"
"su finura y su acabado perfecto.\n");
  SetStandard(WT_ESPADA, 1, P_SIZE_SMALL, M_ACERO);
  SetIds( ({"espada","espada corta"}) );
  SetAds(({"corta","normal"}));
  SetWC(4);
  SetDamType(DT_SLASH);
  Set(P_GENDER, GENDER_FEMALE);
  SetWeight(2500);
  SetValue(650);
  SetResetQuality(100);
  SetSize(P_SIZE_SMALL);
}
