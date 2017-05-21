/*****************************************************************************************
 ARCHIVO:       robledal18.c
 AUTOR:         Ztico
 FECHA:         03-05-2005
 DESCRIPCIÓN:   Robledal en la Isla de los druidas.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit BASE_ISLA;

create()
{
    if(::create()) return 1;

    SetIntShort("el acantilado del oeste");
    SetIntLong("Estás en lo que parece un mirador orientado hacia el bosque de las "
        "dríadas. La erosión ha trabajado duramente sobre las rocas, y sobre "
        "ellas se precipita un pequeño y juguetón arroyo de agua espumosa.\n");
    AddDetail("mirador", "Es una pequeña tarima labrada directamente en la roca.\n");
    AddDetail("bosque", "Observas atentamente por si alcanzaras a ver a alguna de esas "
        "extrañas criaturas que habitan en el bosque. Parece que es demasiado "
        "frondoso.\n");
    AddDetail("rocas", "Diversas formas caprichosas e insinuantes se han ido formando a "
        "lo largo de la historia de estos parajes.\n");
    AddDetail("arroyo", "Nace de un tunel situado bajo varias raices gruesas y desemboca "
        "con ferocidad sobre las aguas del Glinnael.\n");

    SetIntSmell("Huele a hojas frescas y a humedad.\n");
    SetIntNoise("Escuchas el sonido del agua al chocar contra las verdosas piedras del "
        "fondo del acantilado.\n");

    AddRoomCmd("beber", "cmd_beber");

    AddExit("noreste", HAB_BOSQUE_ISLA("robledal23.c"));
    AddExit("sur", HAB_BOSQUE_ISLA("robledal13.c"));
    AddExit("sureste", HAB_BOSQUE_ISLA("robledal14.c"));
}

int cmd_beber(string str)
{
    int max_drink;
    int actual_drink;

    if (!str || str != "agua") return notify_fail("¿Beber Qué?\n", NOTIFY_NOT_OBJ);
    max_drink = TP->QueryMaxDrink();
    actual_drink = TP->QueryDrink();

    if(TP->QueryDrink() == max_drink)
    {
        write("Ya has calmado tu sed, no puedes beber nada más.\n");
                             say(CAP(TNAME) +
                                 " ha saciado su sed y no puede beber nada más.\n");
                                   return 1;
    }
    write("Avanzas hacia el arroyo.\n"
        "Coges agua con las manos y te la bebes toda de un trago.\n"
        "Te sientes menos sedient"+ AO +".\n\n");
    say(CAP(TNAME) +" coge agua con las manos y se la bebe\n"
        "toda de un trago.\n");
    actual_drink += 4 + random(10);
    TP->SetDrink(actual_drink);
    return 1;
}
