/*    Realizada por : Cajun, el ejecutor
      Creado : 17-10-98
      Modificada por Nyh.
*/

#include <rooms.h>
#include <properties.h>
#include <gremios.h>

inherit NPC;

create() {
  ::create();
  SetStandard("Perl","humano",([ GC_GUERRERO: 10 ]), GENDER_MALE );
  SetShort("el comisario de polic�a");
  SetLong(
"El comisario es de complexi�n fuerte aunque parece bastante amable. Est�\n"
"muy atareado arreglando unos papeles en una estanter�a. Sera mejor no\n"
"molestarle.\n");
  SetIds(({"comisario","Comisario","policia","hombre"}));
  SetAlign(400);

}
