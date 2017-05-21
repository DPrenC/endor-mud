/*****************************************************************************************
 ARCHIVO:       posada03_atrio.c
 AUTOR:         Ztico
 FECHA:         07-04-2005
 DESCRIPCIÓN:   Posada del Unicornio Azul. Atrio.
 COMENTARIOS:

*****************************************************************************************/

#include "./path.h"

inherit BASE_ISLA;

public int cmd_beber(string str);
public int cmd_coger(string str);

create()
{
    if(::create()) return 1;

    SetIntShort("el atrio de la posada");
    SetIntLong("Ante ti, un jardín rodeado de verde seto alberga flores multicolores e "
        "infinidad de pequeños arbustos decorativos y plantas trepadoras. "
        "En el centro puedes ver un estanque que recibe agua de un surtidor. Por "
        "una pasarela de madera puedes acceder a dicho surtidor si necesitas beber agua. "
        "Alrededor de este jardín se distribuyen las habitaciones y al norte puedes "
        "observar una escalera que da acceso al Gran Comedor.\n");
    AddDetail(({"jardín", "jardin"}), "Ocupa la parte central del atrio.\n");
    AddDetail(({"arbustos", "arbustos decorativos"}), "Son verdes y están en perfectas "
        "condiciones.\n");
    AddDetail(({"flores", "flores multicolores"}), "La mayoría son rojas y azules, pero "
        "puedes ver también flores de un delicado color rosado, otras más grandes "
        "de color durazno en los pétalos con pintas amarillas en el centro.\n");
    AddDetail("plantas", "Adornan las esbeltas columnas de alabastro.\n");
    AddDetail("columnas", "Son de color hueso y tienen unos dos metros de separación "
        "entre ellas.\n");
    AddDetail("estanque", "Está plagado de nenúfares y lotos.\n");
    AddDetail(({"nenúfares", "nenufares"}), "Sus flores se reflejan en el agua. Las "
        "hojas crean contrastes con la superficie del agua y proveen sombra y refugio "
        "para los peces.\n");
    AddDetail("lotos", "Tienen un follaje de enormes hojas redondas de color verde "
        "glauco y flores que se elevan por encima de las hojas.\n");
    AddDetail("peces", "Hay un montón de peces de colorines.\n");
    AddDetail("surtidor", "Está tallado en mármol blanco recreando el cuerpo de un "
        "tritón.\nJusto al lado hay una taza labrada en plata.\n");
    AddDetail("pasarela", "Construida de madera, gracias a ella puedes alcanzar el "
        "surtidor y beber agua si lo deseas.\n");
    AddDetail("taza", "Es una taza de plata.\n");
    AddDetail(({"habitaciones", "habitación", "habitacion"}), "Desde este punto se "
        "abren cuatro senderos por los que acceder a las puertas de las habitaciones.\n");
    AddDetail(({"escaleras", "escalera"}), "Los escalones son de madera al igual que la "
        "baranda. Desde este punto no puedes ver donde acaba.\n");

    AddRoomCmd("beber", "cmd_beber");
    AddRoomCmd("coger", "cmd_coger");

    AddExit("arriba", HAB_BOSQUE_ISLA("posada06_comedor.c"));
    AddExit("sur", HAB_BOSQUE_ISLA("posada01_vestib.c"));
    AddExit("oeste", "./posada02_hab1");
    AddExit("este", "./posada04_hab2");
    AddExit("noroeste", "./posada05_hab3");
    AddExit("noreste", "./posada07_hab4");
    AddDoor("oeste", "la puerta de la habitación 1", 
    "Es una puerta de madera simple que da acceso a la habitación 1.\n",
    ({"puerta 1", "puerta de madera", "habitación 1", "puerta", "puerta oeste", 
"puerta del oeste"}));
    AddDoor("este", "la puerta de la habitación 2", 
    "Es una puerta de madera simple que da acceso a la habitación 2.\n",
    ({"puerta 2", "puerta de madera", "habitación 2", "puerta", "puerta este", 
"puerta del este"}));
    AddDoor("noroeste", "la puerta de la habitación 3", 
    "Es una puerta de madera simple que da acceso a la habitación 3.\n",
    ({"puerta 3", "puerta de madera", "habitación 3", "puerta", "puerta noroeste", 
"puerta del noroeste"}));
    AddDoor("noreste", "la puerta de la habitación 4", 
    "Es una puerta de madera simple que da acceso a la habitación 4.\n",
    ({"puerta 4", "puerta de madera", "habitación 4", "puerta", "puerta nordeste", 
"puerta del nordeste"}));
}

public int cmd_beber(string str)
{
    int max_drink;
    int actual_drink;

    if (!str || str != "agua") return notify_fail("¿Beber Qué?\n", NOTIFY_NOT_OBJ);
    max_drink = TP->QueryMaxDrink();
    actual_drink = TP->QueryDrink();

    if(TP->QueryDrink() == max_drink)
    {
        write("Ya has calmado tu sed, no puedes beber nada más.\n");
             say(CAP(TNAME) + " ha saciado su sed y no puede beber nada más.\n");
return 1;
    }
    write("Avanzas por la pasarela en dirección al surtidor.\n"
        "Coges agua con la taza y te la bebes toda de un trago.\n"
        "Acto seguido lavas la taza y la dejas donde estaba.\n"
        "Te sientes menos sedient"+ AO +".\n\n");
    say(CAP(TNAME) +" coge agua con la taza y se la bebe\n"
        "toda de un trago.\n");
    say(CAP(TNAME) +" lava la taza y la deja donde estaba.\n\n");
    actual_drink += 4 + random(10);
    TP->SetDrink(actual_drink);
    return 1;
}

public int cmd_coger(string str)
{
    if(!str) return 0;
    if(str == "taza" || str == "taza de plata")
    {
        write("No te puedes llevar la taza, ladronzuel" + AO + ".\n");
        return 1;
    }
    return 0;
}
