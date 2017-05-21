/*    caimanp.c
      Creado por : Nemesis
      Fecha : 29-Dic-97
      Descripcion : Cria de caiman que esta por las alcantarillas.
      Modificado por Nyh
*/

#include <living.h>
#include <combat.h>
#include <moving.h>
#include <gremios.h>

inherit NPC;

create() {
  ::create();
 SetStandard("una cr�a de caim�n","cocodrilo",([ GC_LUCHADOR: 4 ]), GENDER_MALE);
  SetShort("una cr�a de caim�n");
  SetLong(
"Es una cria de caiman. Aun esta lejos de su madurez y no es mas que un\n"
"lagarto grande. De todas formas, quiza su madre este por aqui cerca...\n");
  AddId(({"caiman","caim�n","cria","cr�a"}));
  SetAds(({"pequenyo","cria", "cr�a"}));
  SetAlign(0);
}