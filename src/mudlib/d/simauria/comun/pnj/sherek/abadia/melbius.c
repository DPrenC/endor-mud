/****************************************************************************
Fichero: /d/simauria/comun/pnj/abadia/melbius
Autor: Lug y Yalin
Fecha: 10/09/2006
Descripción: El abad de Sherek.
****************************************************************************/

#include "path.h"
#include <guild.h>
#include <properties.h>
#include <combat.h>
#include <spellmonster.h>
#include <skills.h>
inherit PNJ("sherek/monjebase");

create()
{
    ::create();
    SetStandard("melbius","humano",([ GC_CLERIGO:100+d10() ]), GENERO_MASCULINO);
    SetName("Melbius");
    AddId(({"Melbius","melbius","abad"}));
    SetShort("Melbius, el abad");
    SetLong("Estás en presencia del abad, monje prior y rector de la abadía "
        "de Sherek, supremo dueño y señor de los dominios de Sherek y "
        "dictador de facto de todas las almas que los habitan.\nMelbius es "
        "un monje de vida muy austera, entregado casi de continuo a la "
        "meditación y el entrenamiento, tanto del cuerpo como del espíritu.\n"
        "Es un hombre alto, fuerte y, a juzgar por la expresión inquisitiva "
        "de su mirada, dirías que profundamente sabio.\n");
    SetCon(QueryCon()+15);
    SetInt(QueryInt()+20);
    SetHP(QueryMaxHP());
    SetDex(QueryDex()+4);
    SetStr(QueryStr()+4);
    Set(P_CANT_LURE,1);
    AddItem(ARMA("sherek/abadia/maza_acero"),REFRESH_REMOVE,1,SF(wieldme));
    AddItem(PROT("sherek/abadia/tunicaa"),REFRESH_REMOVE,1,SF(wearme));
    AddItem(PROT("sherek/abadia/zapatilla"),REFRESH_REMOVE,1,SF(wearme));
}
