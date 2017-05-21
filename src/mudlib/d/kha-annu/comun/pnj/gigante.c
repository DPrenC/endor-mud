/****************************************************************************
Fichero: /d/kha-annu/comun/pnj/gigante.c
Autor: Yalin
Fecha: 10/05/2007
Descripci�n: Prisionero gigante en las mazmorras de Kha-annu.
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
    SetLong("Es un humanoide de desmesuradas proporciones.\nSi est� "
        "encerrado en este lugar, no debe ser nadie de quien puedas fiarte, "
        "con toda seguridad es peligroso.\nTe quedas sorprendido mientras "
        "tratas de imaginar cu�ntos enanos fueron necesarios para meterlo aqu�.\n");
    SetAggressive(1);
    SetAlign(-500);
    InitAChats(10,
        ({"El gigante ruge: �Voy a aplastarte como a una cucaracha!\n",
        "El gigante se burla de ti: Gracias por abrirme... Vas a ser mi primera v�ctima.\n",
        "El gigante grita enloquecido: �Malditos enanos! �Voy a triturar hasta sus casuchas!\n",
        "El gigante maldice: �Encerrarme a m�! �No sab�is lo que os espera!\n"}));
}
