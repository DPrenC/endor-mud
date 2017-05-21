/***
Fichero: puesto_escaleras.c
Autor: kastwey@simauria
Descripci�n: Escaleras a las celdas del puesto de guardia de Siempreunidos.
Creaci�n: 05/12/2004
06/12/2004
Le pongo la acci�n de abrir la puerta con una ganz�a.
***/

#include "path.h"
#include <moving.h>

inherit HAB_PUESTO("puesto_guardias/celdas/pasillos_base");

int pPuertaAbierta = 0;
int ir_sur();
int cmd_abrir(string str);
int SetPuertaAbierta(int valor);
void cerrar_puerta();

create()
{
    ::create();
    SetIntShort("unas escaleras");
    SetIntLong(W("Te encuentras en unas escaleras que descienden a lo que parece un s�tano.\n"
    "Hacia el sur, puedes ver    la puerta que comunica con la oficina del guardia.\n"));
    SetIntBright(25);
    AddExit("sur", SF(ir_sur));
    AddExit("abajo", HAB_PUESTO("puesto_guardias/celdas/pasillo1"));
    AddRoomCmd("abrir", "cmd_abrir");
}


int SetPuertaAbierta(int valor)
{
    return pPuertaAbierta = valor;
}

int ir_sur()
{
    if (!pPuertaAbierta)
    {
        write("Te das con la puerta en las narices.\n");
        return 1;
    }
    else
    {
        TP->move(HAB_PUESTO("puesto_guardias/puesto_guardias"), M_GO);
        return 1;
    }
}

public varargs void notify_enter(mixed from, int method, mixed extra)
{
    ::notify_enter(from, method, extra);
    if (query_once_interactive(PO) && pPuertaAbierta) call_out("cerrar_puerta", random(3));
}

void cerrar_puerta()
{
    tell_room(TO, "Un golpe de viento hace que la puerta se cierre.\n");
    pPuertaAbierta = 0;
    (HAB_PUESTO("puesto_guardias/puesto_guardias"))->SetPuertaAbierta(0);
    tell_room((HAB_PUESTO("puesto_guardias/puesto_guardias")), "Un golpe de viento cierra la puerta.\n");
}


int cmd_abrir(string str)
{
    if (!str || str != "puerta") return 0;
    if (pPuertaAbierta)
    {
        write ("La puerta ya est� abierta.\n");
        return 1;
    }
    else if (!present("ganzua", TP))
    {
        write("Intentas abrir la puerta pero parece firmemente cerrada.\n");
        say(W(capitalize(TP->QueryName()) + " intenta abrir la puerta, pero parece firmemente cerrada.\n"), TP);
        return 1;
    }
    else if (present("ganzua", TP) && !present("ganzua_puesto_celdas", TP))
    {
        write ("Introduces la ganz�a en la cerradura e intentas forzarla. Desgraciadamente parece que esta ganz�a no termina de entrar bien en el mecanismo, y lo �nico que consigues es cansarte.\n");
        say (W(capitalize(TP->QueryName()) + " introduce la ganz�a en la cerradura e intenta forzarla. Desgraciadamente parece que esta ganz�a no termina de entrar bien en el mecanismo, y lo �nico que consigue es cansarse.\n"), TP);
        return 1;
    }
    else if (present("ganzua_puesto_celdas", TP))
    {
        if (TP->QueryDex() + random(40) >= 40)
        {
            write(W("Con cuidado introduces la ganz�a en la cerradura. Calculando tus movimientos, comienzas a girar el mecanismo para abrir el pestillo. Al poco, eres recompensado con un �click!, y la puerta queda abierta.\n"
            "Con la emoci�n del momento, la ganz�a se te cae por las escaleras y la pierdes de vista.\n"));
            say(W(capitalize(TP->QueryName()) + " introduce con cuidado la ganz�a en la cerradura. Calculando los movimientos comienza a girar el mecanismo para abrir el pestillo. Al poco, escuchas un d�bil �click!, y la puerta queda abierta.\n"
            "Con la emoci�n del momento, se le cae la ganz�a que sale rodando por las escaleras.\n"), TP);
            present("ganzua_puesto_celdas", TP)->remove();
            pPuertaAbierta = 1;
            tell_room((HAB_PUESTO("puesto_guardias/puesto_guardias")), "La puerta se abre.\n");
            (HAB_PUESTO("puesto_guardias/puesto_guardias"))->SetPuertaAbierta(1);
        }
        else
        {
            write("Con cuidado introduces la ganz�a en la cerradura e intentas girar el mecanismo que abre el pestillo. Sin embargo, tras un rato intent�ndolo te das por vencido... Quiz�s deber�as seguir intent�ndolo.\n");
            say(W(capitalize(TP->QueryName()) + " introduce la ganz�a en la cerradura para intentar abrir la puerta. Tras un rato d�ndole vueltas, no consigue abrirla.\n"), TP);
        }
    }
    return 1;
}

