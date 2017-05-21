/*****************************************************************************************
 ARCHIVO:       bosque42.c
 AUTOR:         Ztico
 FECHA:         26-04-2005
 DESCRIPCIÓN:   Bosque de las Hadas.
 COMENTARIOS:   Poner parra
*****************************************************************************************/

#include "./path.h"

inherit BASE_HADAS;

int cmd_beber(string str);

create()
{
    if(::create()) return 1;

    SetIntShort("la sala Estival");
    SetIntLong("Entras en una enorme sala de piedra roja, inundada de luz. Un gran "
        "árbol cubierto de flores de algodón está plantado en el medio de la cueva, "
        "llamando tu atención, y un pequeño riachuelo brota de entre sus raíces y se "
        "pierde en dirección a la salida. El aire aquí es algo seco y polvoriento, "
        "hace mucho calor, y sientes deseos de tumbarte a los pies de este hermoso "
        "árbol, y refrescar tu garganta en el manantial. De algún lugar entre las "
        "ramas del árbol oyes el canto de un insecto.\n");
    AddDetail(({"riachuelo", "pequeño riachuelo", "arroyo"}), "Sus aguas, "
        "transparentes y frescas, salpican las piedras de alrededor.\n");
    //Habrá un árbol real...

    SetIndoors(1);
    SetIntBright(70);

    SetIntSmell("Hay un tenue olor a tierra reseca y flores de algodón en el "
        "ambiente.\n");
    SetIntNoise("Oyes claramente el chirrido de los insectos y el alegre fluir del "
        "agua del arroyo.\n");

    AddRoomCmd("beber", "cmd_beber");

    AddExit("noreste", HAB_BOSQUE_HADAS("bosque47.c"));
    AddExit("suroeste", HAB_BOSQUE_HADAS("bosque38.c"));

    AddItem(OBJ_OTRO_VALINOR("parra"), REFRESH_DESTRUCT);
    AddItem(PNJ_VALMAR("hada_sirviente.c"), REFRESH_DESTRUCT, random(3));
}

int cmd_beber(string str)
{
    int max_drink;
    int actual_drink;
    object pl;

    if (!str || str != "agua")
    {
        return notify_fail("¿Beber Qué?\n", NOTIFY_NOT_OBJ);
    }
    pl = TP;
    max_drink = pl->QueryMaxDrink();
    actual_drink = pl->QueryDrink();

    if(pl->QueryDrink() == max_drink)
    {
        write("Ya has calmado tu sed, no puedes beber nada más.\n");
             say(CAP(TNAME) +
                 " ha saciado su sed y no puede beber nada más.\n");
                 return 1;
    }
    write("Te acercas al arroyo. Coges agua con las manos y bebes con avidez.\n"
        "Te sientes menos sedient" + AO + ".\n\n");
    say(CAP(TNAME) +" coge agua con las manos y bebe con ansia.\n");
    actual_drink += 4 + random(10);
    pl->SetDrink(actual_drink);
    return 1;
}
