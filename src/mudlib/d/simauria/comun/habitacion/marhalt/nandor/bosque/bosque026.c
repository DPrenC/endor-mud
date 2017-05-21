/****************************************************************************
Fichero: bosque026.c
Autor: Ratwor
Fecha: 09/12/2006
Descripci�n: El bosque de Marhalt.
Uno de los 2  ca�averales para buscar el cebo para pescar, tanto en este r�o como en
el quest del at�n.
Orilla sur del r�o.
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
    return notify_fail("�Qu� exactamente?.\n");
    else{
        if (member(({"barro", "en el barro", "el barro", "en barro", "cebo",
        "gusano", "gusanos", "invertebrados", "invertebrado", "suelo", "en suelo",
        "lombriz", "el suelo", "en el suelo"}), str) < 0)
        return notify_fail("�Qu� necesitas exactamente?");
    }
    if (present("cebo", TO))
        return notify_fail("Ya tienes un gusano a la vista, s�lo tienes que cogerlo.\n",
        NOTIFY_NOT_VALID);
    int busqueda = TP->UseSkill(HAB_RASTREAR);
    if (busqueda < 0){
        write("Examinas el barro removi�ndolo por distintos sitios de la zona, pero "
        "no consigues encontrar ning�n invertebrado.\n");
        say(CAP(TP->QueryName())+ " examina el barro removi�ndolo.\n");
        TP->AddTP(-1);
        return 1;
    } else {
        write ("buscas por el barro removi�ndolo y encuentras un gusano que te ser� "
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

    SetIntShort("un ca�averal embarrado");
    SetIntLong("A orillas del ensanchamiento que forma el r�o Kandal en una de sus "
        "curvas se ha formado una peque�a zona despejada del bosque, donde su suelo "
        "es notablemente m�s h�medo, formando una superficie ligeramente embarrada.\n"
        " Gracias a las caracter�sticas de la zona, las aves acostumbran a venir aqu�"
        " a escarbar en el barro en busca de alimento como gusanos y otros peque�os "
        "invertebrados.\n el ca�averal contin�a en direcci�n sudeste.\n");
    AddDetail(({"ca�averal", "suelo", "barro"}), "En esta zona de la orilla del r�o "
        "se ha formado en el suelo una peque�a capa de barro donde las aves escarban"
        " buscando su comida. El ca�averal contin�a hacia el sudeste.\n");
    AddDetail(({"gusano", "gusanos", "cebo", "invertebrados", "invertebrado",
        "peque�o invertebrado", "peque�os invertebrados", "lombriz", "lombrices"}),
        "Se esconden en el barro, tendr�s que removerlo o escarbar para encontrar lo "
        "que necesitas.\n");
    AddDetail(({"agua", "rio", "r�o", "agua", "aguas"}),
        "El r�o ha formado aqu� un ensanchamiento, al forzarse una curva del caudal "
        "del Kandal.\n Sus aguas cristalinas, donde se puede apreciar los felices "
        "pececillos en su h�bitat, invitan a darse un chapuz�n.\n");
    AddDetail(({"pez", "pececito", "pececitos", "pececillo", "pececillos"}),
        "Parecen ser buenas piezas para darse un buen manjar, pero ahora est�n en su "
        "ambiente nadando felizmente.\n");
    AddRoomCmd(({"rastrear", "buscar", "remover", "escarbar"}), "cmd_buscar");
    AddRoomCmd("pescar", "cmd_pescar");
    AddRoomCmd("beber", "cmd_beber");

    AddExit("norte","./bosque019");
    AddExit("sudeste","./bosque028");
    AddExit("noroeste", "./bosque018");
}

int cmd_beber(string str){
    if (!str) return notify_fail("�Qu� quieres beber?.\n");
    if (str=="agua" || str=="agua del r�o" || str=="agua del rio" || str=="agua de rio"
        || str=="agua de r�o"){
            return notify_fail("Esta parte del ca�averal tiene demasiado barro, hay "
            "mucho r�o donde puedas beber.\n");
    }
    return 0;
}

int cmd_pescar(){
    write("En el ca�averal no se podr� pescar nada con tanto barro, el r�o es muy "
        "largo y seguro que hay mejores zonas para hacerlo.\n");
    return 1;
}
