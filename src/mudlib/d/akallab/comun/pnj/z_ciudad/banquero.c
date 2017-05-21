/****************************************************************************
Fichero: /d/akallab/comun/pnj/z_ciudad/banquero.c
Autor: Yalin
Fecha: 31/03/2008 17:02
Descripción: Banquero de Zarkam.
****************************************************************************/

#include "path.h"
#include <properties.h>
#include <guild.h>
#include <combat.h>
inherit NPC;

create()
{
    ::create();
    SetStandard("el banquero","orco",([ GC_NINGUNO:20+d6() ]),GENERO_MASCULINO);
    SetIds(({"banquero","orco","naaroj","Naaroj"}));
    SetName("Naaroj");
    SetShort("Naaroj, el banquero");
    SetLong("Naaroj es un orco de rostro huraño, como todos los orcos.\n"
        "Está más que gordo, por pasarse toda su vida sentado, revisando "
        "libros. Tal vez por eso no suele mostrarse demasiado agradable con "
        "la gente.\n");
    Set(P_CANT_LURE,1);
    SetAlign(200);
    AddQuestion(({"banco","hermandad","cuenta","cuentas","ingreso","ingresar","dinero","sacar"}),
        "Naaroj te dice: Para saber todo lo que necesites saber, tienes ahí "
        "la caja de folletos. Coge uno y no me interrumpas.\n");
    InitChats(10,
        ({"Naaroj refunfuña: Vaya, aquí hay un error...\n",
        "Naaroj se rasca la cabeza murmurando: Hmmm, esto no me cuadra...\n",
        "Naaroj te dice: Si quieres información sobre el banco, coge un "
            "folleto de ésos.\n",
        "Naaroj gruñe: Hum, otra deuda impagada... Habrá que tomar medidas.\n",
        "Naaroj hojea el libro de cuentas.\n",
        "Naaroj suspira: ¡Y yo sin poder reparar el tejado...! ¿De dónde sacarán tanto dinero? "
            "Seguro que no es legal...\n",
        "Naaroj te dice: ¿Quieres algo, o te vas a quedar de adorno?",
        "Naaroj sonríe lacónicamente diciendo: Vaya, cada vez hay más ricos "
            "en Simauria...\n"}));
}
