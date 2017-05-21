/*****************************************************************************************
 ARCHIVO:       posada03_atrio.c
 AUTOR:         Ztico
 FECHA:         07-04-2005
 DESCRIPCI�N:   Posada del Unicornio Azul. Atrio.
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
    SetIntLong("Ante ti, un jard�n rodeado de verde seto alberga flores multicolores e "
        "infinidad de peque�os arbustos decorativos y plantas trepadoras. "
        "En el centro puedes ver un estanque que recibe agua de un surtidor. Por "
        "una pasarela de madera puedes acceder a dicho surtidor si necesitas beber agua. "
        "Alrededor de este jard�n se distribuyen las habitaciones y al norte puedes "
        "observar una escalera que da acceso al Gran Comedor.\n");
    AddDetail(({"jard�n", "jardin"}), "Ocupa la parte central del atrio.\n");
    AddDetail(({"arbustos", "arbustos decorativos"}), "Son verdes y est�n en perfectas "
        "condiciones.\n");
    AddDetail(({"flores", "flores multicolores"}), "La mayor�a son rojas y azules, pero "
        "puedes ver tambi�n flores de un delicado color rosado, otras m�s grandes "
        "de color durazno en los p�talos con pintas amarillas en el centro.\n");
    AddDetail("plantas", "Adornan las esbeltas columnas de alabastro.\n");
    AddDetail("columnas", "Son de color hueso y tienen unos dos metros de separaci�n "
        "entre ellas.\n");
    AddDetail("estanque", "Est� plagado de nen�fares y lotos.\n");
    AddDetail(({"nen�fares", "nenufares"}), "Sus flores se reflejan en el agua. Las "
        "hojas crean contrastes con la superficie del agua y proveen sombra y refugio "
        "para los peces.\n");
    AddDetail("lotos", "Tienen un follaje de enormes hojas redondas de color verde "
        "glauco y flores que se elevan por encima de las hojas.\n");
    AddDetail("peces", "Hay un mont�n de peces de colorines.\n");
    AddDetail("surtidor", "Est� tallado en m�rmol blanco recreando el cuerpo de un "
        "trit�n.\nJusto al lado hay una taza labrada en plata.\n");
    AddDetail("pasarela", "Construida de madera, gracias a ella puedes alcanzar el "
        "surtidor y beber agua si lo deseas.\n");
    AddDetail("taza", "Es una taza de plata.\n");
    AddDetail(({"habitaciones", "habitaci�n", "habitacion"}), "Desde este punto se "
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
    AddDoor("oeste", "la puerta de la habitaci�n 1", 
    "Es una puerta de madera simple que da acceso a la habitaci�n 1.\n",
    ({"puerta 1", "puerta de madera", "habitaci�n 1", "puerta", "puerta oeste", 
"puerta del oeste"}));
    AddDoor("este", "la puerta de la habitaci�n 2", 
    "Es una puerta de madera simple que da acceso a la habitaci�n 2.\n",
    ({"puerta 2", "puerta de madera", "habitaci�n 2", "puerta", "puerta este", 
"puerta del este"}));
    AddDoor("noroeste", "la puerta de la habitaci�n 3", 
    "Es una puerta de madera simple que da acceso a la habitaci�n 3.\n",
    ({"puerta 3", "puerta de madera", "habitaci�n 3", "puerta", "puerta noroeste", 
"puerta del noroeste"}));
    AddDoor("noreste", "la puerta de la habitaci�n 4", 
    "Es una puerta de madera simple que da acceso a la habitaci�n 4.\n",
    ({"puerta 4", "puerta de madera", "habitaci�n 4", "puerta", "puerta nordeste", 
"puerta del nordeste"}));
}

public int cmd_beber(string str)
{
    int max_drink;
    int actual_drink;

    if (!str || str != "agua") return notify_fail("�Beber Qu�?\n", NOTIFY_NOT_OBJ);
    max_drink = TP->QueryMaxDrink();
    actual_drink = TP->QueryDrink();

    if(TP->QueryDrink() == max_drink)
    {
        write("Ya has calmado tu sed, no puedes beber nada m�s.\n");
             say(CAP(TNAME) + " ha saciado su sed y no puede beber nada m�s.\n");
return 1;
    }
    write("Avanzas por la pasarela en direcci�n al surtidor.\n"
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
