/***
Fichero: puesto_guardias.c
Autor: kastwey@simauria
Descripción: Puesto de guardia de pueblo de Siempreunidos.
Creación: 05/12/2004
14/12/2004
Arreglado algunos movimientos y modificada otras cosillas de la puerta.
28/01/2005: [kastwey]: añado lo de poder pagar las multas.
***/

#include "path.h"
#include <moving.h>


#define V_MITH "/obj/money_demon"->QueryCoinValue("mithril")

inherit STD_FAERIA("hab_siempreunidos");
inherit "/lib/money";

int pPuertaAbierta = 0;

int ir_arriba();
int cmd_abrir(string str);
int ir_celdas();
int cmd_cerrar(string str);
string mirar_puerta();
public int SetPuertaAbierta(int valor);
int cmd_pagar(string str);

create()
{
    ::create();
    SetIntShort("la oficina del guardia");
    SetIntLong(W("Estás en lo que parece la oficina de los guardias de Siempreunidos.\n"
                 "Es una habitación más bien pequeña, que presenta como único "
                 "mobiliario una pequeña mesa que hace las funciones de "
                 "escritorio, y una silla ante ella.\n"
                 "Hacia el norte ves una puerta, y al sur una escalera que "
                 "asciende al piso superior.\n"
                 "También puedes ver un tablón, y al lado un cartel colgado de la pared.\n"));
    SetIndoors(1);
    SetIntBright(30);
    AddDetail(({"mesa", "escritorio"}), "Es un pequeño y desvencijado escritorio aplyado sobre una de las paredes de la pequeña oficina. No es nada del otro mundo.\n");
    AddDetail(({"puerta"}), SF(mirar_puerta));
    AddDetail(({"cartel","letrero"}),W("es un cartel colgado al lado del tablón.\n"
                                       "Quizás podrías leerlo.\n"));
    AddReadMsg(({"letrero","cartel"}),
        W("Información sobre multas:\n"
        "Si por alguna razón eres considerado no bienvenido en nuestro pueblo,"
        "puedes pagar una multa en relación a los delitos por los que eres "
        "no bienvenido.\n"
        "Actualmente, la multa es de 2 monedas de mithril por delito.\n"
        "Para pagar la multa, escribe pagar multa.\n"
    ));
    AddItem(PNJ_PUESTO("soldado_puesto"), REFRESH_HOME, 1);
    AddItem (OBJETO "otro/faeria/tablon",REFRESH_HOME,1);
    AddExit("este", HAB_PUESTO("calles/calle_02"));
    AddExit("arriba", SF(ir_arriba));
    AddExit("norte", SF(ir_celdas));
    AddRoomCmd("pagar","cmd_pagar");
    AddRoomCmd("abrir", "cmd_abrir");
    AddRoomCmd("cerrar", "cmd_cerrar");
}

int ir_arriba()
{
    if (present("guardia_faeria", TO) && living(present("guardia_faeria", TO)) && !TP->QueryIsGuardiaFaeria())
    {
        say(W(capitalize(TP->QueryName()) + " se dispone a subir a la planta de arriba, pero uno de los guardias le corta el paso y le dice: ¡Eh! a donde crees que vas?\n"), TP);
        return notify_fail("Un guardia te corta el paso y te dice: ¡Eh! a donde crees que vas!?\n");
    }
    else
    {
        TP->move(HAB_PUESTO("puesto_guardias/puesto_piso1"), M_GO);
        return 1;
    }
}


int ir_celdas()
{
    if (pPuertaAbierta)
    {
        TP->move(HAB_PUESTO("puesto_guardias/puesto_escaleras"), M_GO);
        (HAB_PUESTO("puesto_guardias/puesto_escaleras"))->SetPuertaAbierta(1);
        return 1;
    }
    else
    {
        write("Te das con la puerta en las narices... Quizás deberías abrirla primero.\n");
        say(W(capitalize(TP->QueryName()) + " se da con la puerta en las narices.\n"), TP);
        return 1;
    }
}

int cmd_abrir(string str)
{
    if (!str || str != "puerta") return 0;
    if (pPuertaAbierta)
    {
        write ("La puerta ya está abierta.\n");
        return 1;
    }
    if (!present("llave_puesto_faeria_celdas", TP))
    {
        write("Intentas abrir la puerta pero está cerrada con llave.\n");
        say(W(capitalize(TP->QueryName()) + " intenta abrir la puerta, pero parece cerrada con llave.\n"), TP);
        return 1;
    }
    else
    {
        write(W("Con ayuda de la llave consigues abrir la puerta.\n"
        "Al sacarla, se te resbala de entre los dedos y cae al suelo, con tan mala fortuna que se cuela por una de las grietas del piso.\n"));
        say(W(capitalize(TP->QueryName()) + " consigue abrir la puerta con ayuda de la llave. Al sacarla de la cerradura, se le escurre de entre los dedos, cayendo al suelo, donde desaparece en una de las grietas del piso.\n"), TP);
        present("llave_puesto_faeria_celdas", TP)->remove();
        pPuertaAbierta = 1;
        tell_room((HAB_PUESTO("puesto_guardias/puesto_escaleras")), "Se abre la puerta.\n");
        (HAB_PUESTO("puesto_guardias/puesto_escaleras"))->SetPuertaAbierta(1);
        return 1;
    }
}
int cmd_cerrar(string str)
{
    if (!str || str != "puerta") return 0;
    if (!pPuertaAbierta)
    {
        write("La puerta ya estaba cerrada.\n");
        return 1;
    }
    write("Cierras la puerta.\n");
    say(capitalize(TP->QueryName()) + " cierra la puerta.\n");
    pPuertaAbierta = 0;
    (HAB_PUESTO("puesto_guardias/puesto_escaleras"))->SetPuertaAbierta(0);
    tell_room((HAB_PUESTO("puesto_guardias/puesto_escaleras")), "La puerta se cierra.\n");
    return 1;
}
string mirar_puerta()
{
    string mensaje;
    mensaje = "Es una puerta de metal macizo, con una cerradura que parece muy resistente.\n";
    if (pPuertaAbierta) mensaje+="Está abierta.\n";
    else mensaje+= "Está cerrada.\n";
    return W(mensaje);
}

public int SetPuertaAbierta(int valor) { return pPuertaAbierta = valor; }
int cmd_pagar(string str)
{
  	int coste;
  	mixed dinpagado;
  	if (!str || str != "multa")
  	{
		    return notify_fail("¿Pagar qué?\n");
	  }
	if (!present("guardia_faeria",TO) || !living(present("guardia_faeria",TO)))
	{
		    return notify_fail("No hay nadie aquí para atenderte.\n");
    }
    if (!TABLON_ENEMIGOS->QueryNonGratas()[TP->QueryRealName()])
    {
    	  return notify_fail(W("El guardia te dice: Pero " + capitalize(TP->QueryName()) + ". "
                         	   "No tienes multa que pagar.\n"));
    }
    coste = TABLON_ENEMIGOS->QueryNonGratas()[TP->QueryRealName()] * 2;
    write(W("El guardia te mira y te dice: "
            "La multa que debes pagar es de " + coste + " monedas de mithril.\n"));
    coste = coste*V_MITH;
    if (QuerySomeonesValue(TP) < coste)
    {
        return notify_fail(W("Cuando vas a pagar, te das cuenta de que  no llevas "
                             "suficiente dinero.\n"));
    }
    dinpagado = PayValue2(TP, coste);
    if (intp(dinpagado))
    {
        write(W("Le pagas al guardia " + dinpagado + ".\n"));
    }
    else
    {
        write("Le pagas al guardia " +dinpagado[0]+(dinpagado[1] ? " y recibes "+dinpagado[1] : "")+".\n");
    }
    TABLON_ENEMIGOS->RemoveNonGrata(TP);
    write("El guardia te borra del tablón.\n");
    say(W("El guardia borra a " + capitalize(TP->QueryName()) + " del tablón.\n"),TP);
    return 1;
}
