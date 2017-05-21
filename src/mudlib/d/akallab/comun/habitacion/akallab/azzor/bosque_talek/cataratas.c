/*
DESCRIPCION  : Al pie de las cataratas de Nurr
FICHERO      : /d/akallab/comun/habitacion/akallab/azzor/bosque_talek/cataratas.c
MODIFICACION : 21-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include AK_MACRO
#include <messages.h>
inherit ROOM;

public int coger_cmd(string str)
{
    object ob;
    if (str=="agua")
    {
        ob=present("frasco_vacio",TP);
        if (!ob) return notify_fail("Necesitarías un frasco vacío para poder "
            "coger un poco del agua cristalina de la laguna.\n",
            NOTIFY_NOT_VALID);
        write("Llenas un frasco vacío con agua cristalina de la laguna.\n");
        tell_room(TO, ({ MSG_SEE, NOMBRE+" llena un frasco con agua "
            "cristalina de la laguna.\n"}), ({ TP }));
        ob->RemoveId("frasco_vacio");
        ob->AddId("cur_quest_08");
        ob->SetContenido("agua cristalina");
        return 1;
    }
    return 0;
}

public int llenar_cmd(string str)
{
    if (str=="frasco") return coger_cmd("agua");
    return 0;
}

create()
{
    ::create();
   SetPreIntShort("al pie de");
    SetIntShort("las cataratas de Nurr");
    SetIntLong("Frente a ti se hallan las cataratas de Nurr, un "
        "impresionante salto de agua de unos 50 metros de altura. El río "
        "Kuneii que pasa encajonado entre las Montañas Negras entra por "
        "ellas en este valle de Azzor. Al pie de las cataratas el río forma "
        "una pequeña laguna de aguas cristalinas antes de proseguir su "
        "avance hacia el este. El ruido de las cataratas es ensordecedor y "
        "apenas deja oír otra cosa.\n");
    AddDetail(({"río","kuneii","río kuneii","río Kuneii"}),"El río Kuneii "
    "recorre este valle de este a oeste. Es un río caudaloso plagado de "
        "rápidos que hacen que no sea navegable. Nace en el vecino valle de "
        "Zarkam y a través de las Cataratas de Nurr atraviesa las Montañas "
        "Negras y entra en el valle. Desemboca al sur de la ciudad de Azzor.\n");
    SetIntNoise("El ruido de las cataratas apenas deja oir otra cosa.\n");
    AddExit("norte",BOSQUE_TALEK("bosque64"));
    AddExit("este",BOSQUE_TALEK("camino17"));
    AddRoomCmd("coger","coger_cmd");
    AddRoomCmd("llenar","llenar_cmd");
}
