/*
DESCRIPCION : Griff Overwald
FICHERO     : /d/simauria/comun/pnj/simauria/berat/griff.c
MODIFICACION: 04-11-99 [Icaro];
              02-06-00 [Maler] eliminados los retornos;añadidos acentos
	      11-01-02 [Nemesis] Cambiado el nombre, que al parecer era
	                         el de un famoso jugador de Blood Bowl.
				 Suerte que tengo implantado un GenIAL
				 en el cerebro...
				 Ya de paso, meto un par de acentos que
				 se le pasaron a Maler
--------------------------------------------------------------------------------
*/
#include "./path.h"
#include <properties.h>
#include <gremios.h>

inherit NPC;
create() {
    ::create();
    SetStandard("Koravor Wallabund", "humano", ([GC_LUCHADOR: 35]), GENDER_MALE);
    AddId(({"gladiador", "koravor"}));
    SetShort("Koravor Wallabund");
    SetLong("Es Koravor Wallabund, un famoso gladiador humano, "
    "te preguntas qué hará por aquí.\n");
    SetWeight(100000);
    SetCitizenship("berat");
    InitChats(2,({
    "Koravor se mueve pensativo.\n",
    "Koravor te dice: creo que te conozco de algo.\n",
    "Koravor se rasca la cabeza.\n"}));
}


