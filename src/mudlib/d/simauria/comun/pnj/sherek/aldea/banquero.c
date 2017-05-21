/* Archivo: /d/simauria/comun/pnj/abadia/banquero.c
* Descripci�n: banquero para el banco de la aldea y sus aleda�os.
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
    SetLong("Palson es un hombre de rostro bonach�n, aunque poco expresivo.\n"
        "Es del tipo gordito, por pasarse toda su vida sentado, revisando "
        "libros. Tal vez por eso no suele mostrarse demasiado agradable con "
        "la gente.\n");
    Set(P_CANT_LURE,1);
    SetAlign(200);
    AddQuestion(({"banco","hermandad","cuenta","cuentas","ingreso","ingresar","dinero","sacar"}),
        "Palson te dice: Para saber todo lo que necesites saber, tienes ah� "
        "la caja de folletos. Coge uno y no me interrumpas.\n");
        InitChats(10,
        ({"Palson refunfu�a: Vaya, aqu� hay un error...\n",
        "Palson se rasca la cabeza murmurando: Hmmm, esto no me cuadra...\n",
        "Palson te dice: Si quieres informaci�n sobre el banco, coge un "
            "folleto de �sos.\n",
    "Palson gru�e: Hum, otra deuda impagada... Habr� que tomar medidas.\n",
    "Palson hojea el libro de cuentas.\n",
        "Palson te dice: �Quieres algo, o te vas a quedar de adorno?",
        "Palson sonr�e lac�nicamente diciendo: Vaya, cada vez hay m�s ricos "
            "en Simauria...\n"}));
}
