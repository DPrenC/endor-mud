/*****************************************************************************************
 ARCHIVO:       posada09_secreta.c
 AUTOR:         Ztico
 FECHA:         13-04-2005
 DESCRIPCI�N:   Posada del Unicornio Azul. Alcoba Secreta.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"
#include <wizlevels.h>
#include <moving.h>
//#include <properties.h>
inherit BASE_ISLA;

private int antorchas = 1;

//***** Funciones para las antorchas ******

public int cmd_encender(string str);
public int cmd_apagar(string str);
public string f_estado_antorchas();


public int f_salir();
public int cmd_empujar(string str);

create()
{
    if(::create()) return 1;

    SetIntShort("la alcoba secreta");
    SetIntLong("No deber�as estar aqu�. Sostenidas por argollas de bronce observas "
        "antorchas estrat�gicamente ubicadas. Por todos lados observas artilugios y "
        "aparatos, as� como pilas enormes de pergamino. Las estanter�as que rodean la "
        "estancia est�n cargadas de extra�os libros forrados de cuero.\n");
    SetIntBright(30);
    SetIndoors(1);
    AddDetail(({"argollas", "argolla"}), "Sirven para sujetar las antorchas.\n");
    AddDetail(({"antorcha", "antorchas"}), SF(f_estado_antorchas));
    AddDetail(({"artilugios", "aparatos"}), "Como no conoces su naturaleza prefieres "
        "no probarlos.\n");
    AddDetail(({"estanter�a", "estanteria", "estanter�as", "estanterias"}), "Son de "
        "madera y no admiten ni un libro m�s.\n");
    AddDetail("libros", "Est�n llenos de polvo, todos excepto uno.\n");
    AddDetail("libro", "Parece que es usado con frecuencia.\n");

    AddRoomCmd("encender", "cmd_encender");
    AddRoomCmd("apagar", "cmd_apagar");
    AddRoomCmd(({"empujar", "mover"}), "cmd_empujar");
//    AddItem(QUEST_RUNAS("gleryn"), REFRESH_DESTRUCT);
    AddExit("salir", SF(f_salir));
    HideExit("salir", 1);

}

public int f_salir()
{
    if(IS_LEARNER(TP))
        TP->move(HAB_BOSQUE_ISLA("posada08_salon.c"), M_GO, "puerta");
    else write("No hay salida hacia all�.\n");
    return 1;
}

public int cmd_empujar(string str)
{
    if(!str || str != "libro")
        return notify_fail("�Empujar qu�?\n");
    write("Empujas el libro y tu cuerpo se desmaterializa apareciendo en otro lugar.\n");
    say(CAP(TNAME)+" mueve un libro de la estanter�a y desaparece.\n");
        TP->move(HAB_BOSQUE_ISLA("posada08_salon"), M_GO);
//    call_out( "movimiento", 1);
    return 1;
}

public int cmd_encender(string str)
{
    if(!str || (str != "antorcha" && str != "antorchas"))
    {
        return notify_fail("�Encender <Qu�>?\n",NOTIFY_ILL_ARG);
    }
    if(antorchas)
        return notify_fail("Las antorchas ya est�n encendidas.\n", NOTIFY_ILL_ARG);

    write("Por un impulso inusitado das dos fuertes palmadas.\n"
        "Ves como brota una llamarada de las antorchas.\n");
    say(CAP(TNAME) + " palmea las manos como pose�do.\n"
        "Ves como brota una llamarada de las antorchas.\n");
    SetIntBright(40);
    antorchas = 1;
    return 1;
}

public int cmd_apagar(string str)
{
    if(!str || (str != "antorcha" && str != "antorchas"))
        return notify_fail("�Apagar <Qu�>?\n");
    if(!antorchas)
        return notify_fail("Las antorchas ya est�n apagadas.\n", NOTIFY_ILL_ARG);

    write("Empiezas a taconear.\n"
        "Ves como poco a poco la llama de las antorchas se desvanece.\n");
    say(CAP(TNAME)+" golpea los pies contra el suelo.\n"
        "Ves como poco a poco la llama de las antorchas se desvanece.\n");
    SetIntBright(10);
    antorchas = 0;
    return 1;
}

public string f_estado_antorchas()
{
    if(antorchas) return ("Esparcen luz y calor creando multitud de claroscuros.\n");
    return ("Est�n apagadas.\n");
}
