/****************************************************************************
Fichero: /d/kha-annu/comun/pnj/gigante.c
Autor: Yalin
Fecha: 10/05/2007
Descripción: Prisionero gigante en las mazmorras de Kha-annu.
****************************************************************************/

#include "path.h"
#include <properties.h>
#include <guild.h>
inherit NPC;

create()
{
    ::create();
    SetStandard("un gigante","gigante",([ GC_LUCHADOR:44+d6() ]), GENERO_MASCULINO);
    SetShort("un gigante");
    SetLong("Es un humanoide de desmesuradas proporciones.\nSi está "
        "encerrado en este lugar, no debe ser nadie de quien puedas fiarte, "
        "con toda seguridad es peligroso.\nTe quedas sorprendido mientras "
        "tratas de imaginar cuántos enanos fueron necesarios para meterlo aquí.\n");
    SetAggressive(1);
    SetAlign(-500);
    InitAChats(10,
        ({"El gigante ruge: ¡Voy a aplastarte como a una cucaracha!\n",
        "El gigante se burla de ti: Gracias por abrirme... Vas a ser mi primera víctima.\n",
        "El gigante grita enloquecido: ¡Malditos enanos! ¿Voy a triturar hasta sus casuchas!\n",
        "El gigante maldice: ¡Encerrarme a mí! ¡No sabéis lo que os espera!\n"}));
}
