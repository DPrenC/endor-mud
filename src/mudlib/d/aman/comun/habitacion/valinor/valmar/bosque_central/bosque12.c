/*****************************************************************************************
 ARCHIVO:       bosque12.c
 AUTOR:         Ztico
 FECHA:         16-03-2005
 DESCRIPCIÓN:   Bosque Central de Faeria.
 COMENTARIOS:   Hay un tronco con un bichito dentro.
*****************************************************************************************/

#include "./path.h"
#include <commands.h>

#define MANOSTRONCO ({"mano por el agujero", "la mano por el agujero",\
	                    "la mano en el agujero", "mano en agujero", "la mano en agujero",\
	                    "mano por agujero", "mano por el tronco", "la mano por el tronco",\
	                    "la mano en el tronco", "mano en tronco", "la mano en tronco",\
                      "mano por tronco"})

inherit BASE_CENTRAL;

public int cmd_meter(string str);
public int mordido();
public int filtrar(string str);
public int reestablecer();

create()
{
    if(::create()) return 1;

    SetIntLong(::QueryIntLong() +
        "A tu lado se encuentra un viejo tronco, que posiblemente sirva de refugio a "
        "alguna criatura del bosque.\n");
    AddDetail("tronco", "No es más que un viejo tronco medio podrido con un agujero, es "
        "posible que si metes la mano puedas encontrar algo.\n");

    AddRoomCmd("meter", "cmd_meter");

    AddExit("norte", HAB_BOSQUE_CENTRAL("bosque18.c"));
    AddExit("sur", HAB_BOSQUE_CENTRAL("bosque07.c"));

    AddItem(PNJ_VALMAR("elfa.c"), REFRESH_DESTRUCT, 1);
}

/*****************  FUNCIONES PARA EL TRONCO ********************************************/

public int cmd_meter(string str)
{
    if(str && member(MANOSTRONCO, LOWER(str)) >= 0)
    {
        write("Metes la mano por el agujero. ¡¡¡Ohhh, Algo te ha mordido!!!\nSientes una "
            "ligera somnolencia.\n");
        say(CAP(TNAME) + " mete la mano por el agujero y ves como la saca de inmediato "
            "con un gesto de dolor en la cara. Acto seguido ves como cierra los ojos y "
            "cae en un profundo sueño.\n");
        mordido();
        return 1;
    }
    return notify_fail("¿Qué quieres meter y por donde?\n", NOTIFY_NOT_OBJ);
}

public int mordido()
{
    add_action("filtrar", "", AA_NOSPACE);
    call_out("reestablecer", 30);
    return 1;
}

public int filtrar(string str)
{
    write("Es tal el sopor en el que te encuentras, que te impide hacer cualquier cosa "
        "que no sea seguir durmiendo.\n");
    say("Ves como " + CAP(TNAME) + " se mueve entre sueños.\n");
    return 1;
}

public int reestablecer()
{
    remove_action("", TP);
    write("Te despiertas y notas como la cabeza te da vueltas. Estás realmente cansad"
        + AO + ".\n");
    say(CAP(TNAME) + " se despierta. Tiene muy mal aspecto.\n");
    TP->SetTP(0);
    return 1;
}
