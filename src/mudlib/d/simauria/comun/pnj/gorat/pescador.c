
#include <properties.h>

#include <colours.h>
#include "./path.h"

inherit NPC;

create() {
    ::create();
    SetStandard("Garlonu", "humano", 12, GENDER_MALE);
    SetShort("Garlonu el pescador");
    SetLong(
    "Garlonu es un viejo pescador con la cara algo arrugada y con notables marcas "
    "del paso del tiempo en su cuerpo.\n Se pasa las horas en el muelle pescando, "
    "aunque no suele sacar mucho fruto de ello.\n");
    AddId(({"Garlonu","garlonu","anciano", "viejo", "pescador"}));
    SetCitizenship("gorat");
    AddSubDetail(({"caña", "canya"}), "Es una simple caña de casi dos metros de larga.\n");
    AddQuestion(({"cebo"}),
    "\nEl pescador dice: Aqui un buen cebo es el gusano\n");
    AddQuestion(({"gusano"}),
    "\nEl pescador dice: Puedes encontrar gusanos a la orilla de los ríos, normalmente "
    "en zonas con barro.\n");
    AddQuestion(({"río", "rio"}),
    "\nEl pescador dice:  el río más cercano es el Kandal, en la región de Marhalt.\n");
      AddQuestion(({"pescar"}),
    "\nEl pescador dice:  lo importante para pescar es una caña de pescar, y si "
    "quieres que piquen necesitarás cebo.\n Por otra parte, las leyes de Gorat exigen "
    "tener una licencia de pesca para pescar en este embarcadero.\n");
    AddQuestion(({"licencia","licencia de pesca"}),
    "\nEl pescador dice: Una licencia es un mero tramite burocratico imprescindible"
    " para pescar en este lugar\n");
    AddQuestion(({"canya","canya de pescar", "caña", "caña de pescar"}),
    "\nEl pescador dice: Una caña de pescar es un utensilio imprescindible para "
    "pescar, la puedes comprar en las tiendas.\n");
    InitChats(3,({
    "El pescador pesca un arenque.\n",
    "El pescador pesca una bota y la tira al mar.\n",
    "El pescador se queja de lo sucio que está el embarcadero.\n",
    "El pescador silba.\n"}));
    InitAChats(7,({"El pescador grita: 'guardias'\n",
    "EL pescador dice: Que juventud! En mis tiempos te ibas a enterar! Gamberro!\n"}));
}


