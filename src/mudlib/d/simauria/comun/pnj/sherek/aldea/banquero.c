/* Archivo: /d/simauria/comun/pnj/abadia/banquero.c
* Descripción: banquero para el banco de la aldea y sus aledaños.
* Autor: Lug y Yalin.
*/

#include "path.h"
#include <properties.h>
#include <guild.h>
#include <combat.h>
inherit PNJ("sherek/aldea/base");

create()
{
    ::create();
    SetStandard("el banquero","humano",([ GC_NINGUNO:20+d6() ]),GENERO_MASCULINO);
    SetIds(({"banquero","humano","palson","Palson"}));
    SetName("Palson");
    SetShort("Palson, el banquero");
    SetLong("Palson es un hombre de rostro bonachón, aunque poco expresivo.\n"
        "Es del tipo gordito, por pasarse toda su vida sentado, revisando "
        "libros. Tal vez por eso no suele mostrarse demasiado agradable con "
        "la gente.\n");
    Set(P_CANT_LURE,1);
    SetAlign(200);
    AddQuestion(({"banco","hermandad","cuenta","cuentas","ingreso","ingresar","dinero","sacar"}),
        "Palson te dice: Para saber todo lo que necesites saber, tienes ahí "
        "la caja de folletos. Coge uno y no me interrumpas.\n");
        InitChats(10,
        ({"Palson refunfuña: Vaya, aquí hay un error...\n",
        "Palson se rasca la cabeza murmurando: Hmmm, esto no me cuadra...\n",
        "Palson te dice: Si quieres información sobre el banco, coge un "
            "folleto de ésos.\n",
    "Palson gruñe: Hum, otra deuda impagada... Habrá que tomar medidas.\n",
    "Palson hojea el libro de cuentas.\n",
        "Palson te dice: ¿Quieres algo, o te vas a quedar de adorno?",
        "Palson sonríe lacónicamente diciendo: Vaya, cada vez hay más ricos "
            "en Simauria...\n"}));
}
