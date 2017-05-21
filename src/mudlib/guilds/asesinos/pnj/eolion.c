#include "path.h"
#include <combat.h>
#include <living.h>
#include <moving.h>
#include <equipment.h>
#include <rooms.h>
#include <money.h>
#include <properties.h>
inherit NPC;

no_lucho()
{
    return notify_fail("Eolion te mira con una mueca burlona, coge una katana de detrás del mostrador, y "
        "con un simple gesto de sus manos la deja convertida en un amasijo de acero.\nLuego te "
        "dice con voz seria: Ten cuidado, criatura enclenque. Lo próximo podría ser tu "
        "espalda.\n",NOTIFY_NOT_VALID);
}
    
create()
{
    ::create();
    SetStandard("Eolion","humano",([GC_ASESINO:200]),GENERO_MASCULINO);
    SetChkFightFunction(SF(no_lucho));
    SetChkMagicFunction(SF(no_lucho));
    SetName("eolion");
    SetShort("Eolion, el tendero");
    SetLong("Eolion es un hombre de mediana edad y estatura. Aún así, parece muy curtido y sus "
        "músculos se marcan bajo su ropa de cuero oscura. Sobre su ojo derecho puedes ver un "
        "parche, y sus cabellos están recogidos con un pañuelo rojo con una cruz negra "
        "dibujada encima. Parece vigilar todos tus movimientos...\n");
    SetIds( ({"humano","eolion","tendero"}) );
    SetMaxAlcohol(350);
    SetAlcohol(250);
    AddItem("../obj/traje_cuero",REFRESH_DESTRUCT,1,SF(wearme));
    AddItem(OBJETO("long_katana"),REFRESH_DESTRUCT,1,SF(wieldme));
}

void init()
{
    ::init();
    call_out("bienvenida",2,TP);
}

void bienvenida(object jugata)
{
    if(jugata->Query(P_INVIS) || jugata->Query(P_HIDDEN) ) return;
    tell_room(environment(TO),"Eolion dice: Buenos días. Deseabas algo, "+
        jugata->QueryRace()+"?\n");
    tell_object(jugata,"Eolion apunta hacia ti con su dedo indice.\n");
    tell_room(environment(TO),"Eolion apunta hacia "+jugata->QueryName()+" con su dedo indice.\n",
        ({jugata}));
}

