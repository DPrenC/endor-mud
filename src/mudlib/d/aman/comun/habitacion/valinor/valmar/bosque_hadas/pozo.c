/*****************************************************************************************
 ARCHIVO:       pozo.c
 AUTOR:         Ztico
 FECHA:         26-04-2005
 DESCRIPCIÓN:   Bosque de las Hadas.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"
#include <colours.h>

inherit BASE_HADAS;

public int cmd_mover(string str);
public int f_mensaje();

create()
{
    if(::create()) return 1;

    SetIntShort("un pozo");
    SetIntLong("Estás en lo que parece ser el final del largo túnel por el que caíste. "
        "Apenas hay luz. El ambiente es muy húmedo y las paredes gotean. Sin embargo, "
        "el supuesto pozo, o no lo es en realidad, o está totalmente seco.\n");
    AddDetail(({"paredes", "pared"}), "Es una sala rectangular. Las paredes drenan agua,"
        " que cae en pequeños reguerillos hasta el suelo.\n");
    AddDetail("suelo", "Es arcilloso y está embarrado, en una de las esquinas hay "
        "una piedra bastante extraña.\n");
    AddDetail(({"piedra", "piedra extraña"}), "Cuando te acercas y la observas, te das "
        "cuenta de que la piedra tiene un brillo poco natural.\n");
    AddDetail(({"reguerillo", "reguerillos", "reguero", "regueros"}), "varios regueros "
        "de agua descienden filtrándose desde las paredes, yendo a parar al ya de por "
        "sí embarrado suelo.\n");
    SetIndoors(1); //está dentro de la cueva
    SetIntBright(10);

    AddRoomCmd("mover", "cmd_mover");
}

public int cmd_mover(string str)
{
    if(!str || str != "piedra") return notify_fail("¿Mover <qué>?\n", NOTIFY_NOT_OBJ);

    write("Mueves la piedra y a continuación escuchas un burbujeo alarmante.\n");
    say(CAP(TNAME) + " hace algo y a continuación escuchas un burbujeo alarmante.\n");
    call_out("f_mensaje", 4);
    return 1;
}

public int f_mensaje()
{
    string msg;
    string msg_barras;

    msg = TC_BOLD TC_BLUE "\n"
        "     \n" TC_CYAN
        "     Oyes un estruendo a tu espalda, que resuena en toda la sala\n"
        "     aturdiendo tus oídos y haciendo que tu corazón dé un vuelco,\n"
        "     te giras y ves cómo  las piedras de una de las paredes caen\n"
        "     formando un " TC_BLUE "ALUD" TC_CYAN " de agua y piedra que "
             "te " TC_BLUE "ARRASTRA" TC_CYAN " sin poder\n     remediarlo...\n"
        "     " TC_BLUE "\n" TC_NORMAL;

    msg_barras = TC_BOLD TC_BLUE "\n"
        "     \\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/"
        "\\/\\/\\/\\/\\/\\\n" TC_CYAN
        "     Oyes un estruendo a tu espalda, que resuena en toda la sala\n"
        "     aturdiendo tus oídos y haciendo que tu corazón dé un vuelco,\n"
        "     te giras y ves cómo  las piedras de una de las paredes caen\n"
        "     formando un " TC_BLUE "ALUD" TC_CYAN " de agua y piedra que "
             "te " TC_BLUE "ARRASTRA" TC_CYAN " sin poder\n     remediarlo...\n"
        "     " TC_BLUE "/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\"
        "/\\/\\/\\/\\/\\/\\/\\/\\/\\/\n" TC_NORMAL;


    //Lo siguiente coge a los players que haya en ese momento en la room y los traslade
    filter(all_inventory(), (:if (query_once_interactive($1))
                             {
                                 tell_object($1, ($1->QueryTiflo()) ? $2 : $3);
                                 $1->move(HAB_BOSQUE_HADAS("fondo_estanque.c"));
                                 $1->LookAfterMove();
                             }
                             return 0;:), msg, msg_barras);
    return 1;
}
