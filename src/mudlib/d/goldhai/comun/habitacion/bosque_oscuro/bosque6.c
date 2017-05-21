/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 06-01-98                |
 |               Ultima Modificacion.. 18-11-98                |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit GBOSQUE;

create()
{
    string tipo;
    ::create();
    SetIntShort("un claro del bosque");
    SetIntLong("Has llegado a un claro dentro del bosque oscuro. Es una zona libre de la "
        "espesa y áspera vegetación que cubre estos lugares. Aquí normalmente crecen unas "
        "extrañas flores de color amarillo cuya vida jamás nadie ha podido descifrar.\nSe "
        "cuenta que dependiendo de la época del año en que nacieron producen unos extraños "
        "efectos si se ingieren, pero ya se sabe que todo puede ser una simple leyenda. Si "
        "deseas irte de este lugar, puedes hacerlo yendo en dirección Norte u Oeste a través "
        "del bosque.\n");
    AddDetail("claro","Es una zona con una vegetación no tan espesa.\n");
    AddExit("norte",BOSCURO("bosque5"));
    AddExit("oeste",BOSCURO("bosque7"));
    tipo="nar";
    switch(random(3))
    {
        case 0: tipo="sac"; break;
        case 1: tipo="nar"; break;
        case 2: tipo="ven"; break;
        default: tipo="nar";
    }
    AddItem(PLANTAS("floresamarillas_"+tipo));
    AddPnj();
    SetLocate("bosque oscuro de Goldhai");
}

reset()
{
    string tipo;
    ::reset();
    if(present("flores amarillas")) return;
    switch(random(3))
    {
        case 0: tipo="sac"; break;
        case 1: tipo="nar"; break;
        case 2: tipo="ven"; break;
        default: tipo="nar";
    }
    AddItem(PLANTAS("floresamarillas_"+tipo));
    return;
}
