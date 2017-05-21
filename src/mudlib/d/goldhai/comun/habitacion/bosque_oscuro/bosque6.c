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
        "espesa y �spera vegetaci�n que cubre estos lugares. Aqu� normalmente crecen unas "
        "extra�as flores de color amarillo cuya vida jam�s nadie ha podido descifrar.\nSe "
        "cuenta que dependiendo de la �poca del a�o en que nacieron producen unos extra�os "
        "efectos si se ingieren, pero ya se sabe que todo puede ser una simple leyenda. Si "
        "deseas irte de este lugar, puedes hacerlo yendo en direcci�n Norte u Oeste a trav�s "
        "del bosque.\n");
    AddDetail("claro","Es una zona con una vegetaci�n no tan espesa.\n");
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
