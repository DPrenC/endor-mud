/****************************************************************************
Fichero: bosque026.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
Uno de los 2  cañaverales para buscar el cebo para pescar, tanto en este río como en
el quest del atún.
Orilla sur del río.
****************************************************************************/

#include "./path.h"
#include <moving.h>
#include <skills.h>
inherit MARH("nandor/bosque/orilla");

int cmd_buscar(string str){
    object cebo;
    if(TP->QueryTP()<1) return notify_fail("Necesitas descansar un rato.\n",
        NOTIFY_NOT_VALID);
    if (!str)
    return notify_fail("¿Qué exactamente?.\n");
    else{
        if (member(({"barro", "en el barro", "el barro", "en barro", "cebo",
        "gusano", "gusanos", "invertebrados", "invertebrado", "suelo", "en suelo",
        "lombriz", "el suelo", "en el suelo"}), str) < 0)
        return notify_fail("¿Qué necesitas exactamente?");
    }
    if (present("cebo", TO))
        return notify_fail("Ya tienes un gusano a la vista, sólo tienes que cogerlo.\n",
        NOTIFY_NOT_VALID);
    int busqueda = TP->UseSkill(HAB_RASTREAR);
    if (busqueda < 0){
        write("Examinas el barro removiéndolo por distintos sitios de la zona, pero "
        "no consigues encontrar ningún invertebrado.\n");
        say(CAP(TP->QueryName())+ " examina el barro removiéndolo.\n");
        TP->AddTP(-1);
        return 1;
    } else {
        write ("buscas por el barro removiéndolo y encuentras un gusano que te será "
        "estupendo para usarlo como cebo.\n");
        say (CAP(TP->QueryName())+ " busca por el suelo removiendo el barro y parece "
        "que ha encontrado un gusano.\n");
        cebo=clone_object(OTRO("cebo"));
	    cebo->move(environment(TP));
	    TP->AddTP(-1);
        return 1;
    }
    return 0;
}

create(){
    ::create();

    SetIntShort("un cañaveral embarrado");
    SetIntLong("A orillas del ensanchamiento que forma el río Kandal en una de sus "
        "curvas se ha formado una pequeña zona despejada del bosque, donde su suelo "
        "es notablemente más húmedo, formando una superficie ligeramente embarrada.\n"
        " Gracias a las características de la zona, las aves acostumbran a venir aquí"
        " a escarbar en el barro en busca de alimento como gusanos y otros pequeños "
        "invertebrados.\n el cañaveral continúa en dirección sudeste.\n");
    AddDetail(({"cañaveral", "suelo", "barro"}), "En esta zona de la orilla del río "
        "se ha formado en el suelo una pequeña capa de barro donde las aves escarban"
        " buscando su comida. El cañaveral continúa hacia el sudeste.\n");
    AddDetail(({"gusano", "gusanos", "cebo", "invertebrados", "invertebrado",
        "pequeño invertebrado", "pequeños invertebrados", "lombriz", "lombrices"}),
        "Se esconden en el barro, tendrás que removerlo o escarbar para encontrar lo "
        "que necesitas.\n");
    AddDetail(({"agua", "rio", "río", "agua", "aguas"}),
        "El río ha formado aquí un ensanchamiento, al forzarse una curva del caudal "
        "del Kandal.\n Sus aguas cristalinas, donde se puede apreciar los felices "
        "pececillos en su hábitat, invitan a darse un chapuzón.\n");
    AddDetail(({"pez", "pececito", "pececitos", "pececillo", "pececillos"}),
        "Parecen ser buenas piezas para darse un buen manjar, pero ahora están en su "
        "ambiente nadando felizmente.\n");
    AddRoomCmd(({"rastrear", "buscar", "remover", "escarbar"}), "cmd_buscar");
    AddRoomCmd("pescar", "cmd_pescar");
    AddRoomCmd("beber", "cmd_beber");

    AddExit("norte","./bosque019");
    AddExit("sudeste","./bosque028");
    AddExit("noroeste", "./bosque018");
}

int cmd_beber(string str){
    if (!str) return notify_fail("¿Qué quieres beber?.\n");
    if (str=="agua" || str=="agua del río" || str=="agua del rio" || str=="agua de rio"
        || str=="agua de río"){
            return notify_fail("Esta parte del cañaveral tiene demasiado barro, hay "
            "mucho río donde puedas beber.\n");
    }
    return 0;
}

int cmd_pescar(){
    write("En el cañaveral no se podrá pescar nada con tanto barro, el río es muy "
        "largo y seguro que hay mejores zonas para hacerlo.\n");
    return 1;
}
