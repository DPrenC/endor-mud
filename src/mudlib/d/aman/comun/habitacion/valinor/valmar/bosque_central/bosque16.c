/*****************************************************************************************
 ARCHIVO:       bosque16.c
 AUTOR:         Ztico
 FECHA:         16-03-2005
 DESCRIPCIÓN:   Bosque Central de Faeria.
 COMENTARIOS:   Hay una madriguera con un bichito dentro.
*****************************************************************************************/

#include "./path.h"
#include <commands.h>

#define MANOSMADRIGUERA ({"mano por el agujero", "la mano por el agujero",\
	            "la mano en el agujero", "mano en agujero", "la mano en agujero",\
	            "mano por agujero", "mano por la madriguera", "la mano por la madriguera",\
	            "la mano en la madriguera", "mano en madriguera", "la mano en madriguera",\
	            "mano por madriguera"})

inherit BASE_CENTRAL;

public int cmd_meter(string str);
public int mordido();
public int filtrar(string str);
public int reestablecer();

create()
{
    if(::create()) return 1;

    SetIntLong(::QueryIntLong() +
        "Un pequeño promontorio de tierra se eleva a tus pies. Será mejor que no lo "
        "pises pues parece la entrada de alguna madriguera.\n");
    AddDetail(({"madriguera", "promontorio"}), "Es un agujero muy oscuro, yo que tú no "
        "metería la mano.\n");
    AddRoomCmd("meter", "cmd_meter");

    AddExit("norte", HAB_BOSQUE_CENTRAL("bosque22.c"));
    AddExit("sur", HAB_BOSQUE_CENTRAL("bosque10.c"));
    AddExit("este", HAB_BOSQUE_CENTRAL("bosque17.c"));
    AddExit("oeste", HAB_BOSQUE_CENTRAL("bosque15.c"));
    AddExit("noroeste", HAB_BOSQUE_CENTRAL("bosque21.c"));
}

/*****************  FUNCIONES PARA LA MADRIGUERA ****************************************/

public int cmd_meter(string str)
{
    if(str && member(MANOSMADRIGUERA, LOWER(str)) >= 0)
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