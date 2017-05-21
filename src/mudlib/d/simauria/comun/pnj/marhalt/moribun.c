/*El moribundo que se muere en Nandor.
  (c) Bansee@Simauria.
  Revisado por Nemesis.
  [n] Castellanizado. (Oct'02)
  [Ratwor] lo estandarizo y lo hago ciudadano de Nandor. 23/04/2010
*/
#include <properties.h>
inherit NPC;

create()
{
    ::create();
    SetStandard("Isrbore", "humano", 2, GENDER_MALE);
    AddId(({"hombre", "viejo", "anciano", "moribundo"}));
    SetShort("Un viejo moribundo");
    SetLong("Este viejo moribundo disfruta en tranquilidad de sus últimas horas"
    " de vida. parece que ni se entera de tu presencia.\n");
    SetCitizenship("nandor");
    SetShrugMsg("El viejo no parece escucharte.\n");
    InitChats(5,({"El moribundo dice: 'Humm.... Arrgg....'\n",
              "El moribundo dice: 'Widbel, ¿estás ahí?\n"}));
}
