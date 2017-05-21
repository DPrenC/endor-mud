/***
Fichero: posada.c
Autor: kastwey@simauria
Descripción: Posada de Siempreunidos.
Creación: 02/12/2004
***/
#include "path.h"
#include <money.h>
#include <moving.h>



#define COSTE 2000
#define COSTE_HAB "2 platino"
inherit STD_FAERIA("hab_siempreunidos");
inherit "/lib/money";

string mirar_mostrador();
int cmd_alquilar(string str);
void llamar_guardia(object enemigo);
string recompensa(object player);
int cmd_reiniciar();
int n_guardias;

create()
{
    ::create();
    SetIntShort("la posada de Siempreunidos");
    SetIntLong(W("Te encuentras en la posada del pueblo de Siempreunidos.\n"
    "Aquí podrás alquilar una habitación por un precio moderado.\n"
    "Detrás del pequeño mostrador suele estar Engelbergt, el dueño de la posada.\n"
    "Hacia el norte está la escalera que sube hacia las habitaciones, hacia el este un salón, y hacia el oeste la salida a la calle.\n"));
    SetOficina(HAB_PUESTO("calles/calle_01"));
    SetIndoors(1);
    SetIntBright(30);
    AddDetail(({"mostrador"}), SF(mirar_mostrador));
    AddItem(PNJ_PUESTO("engelbergt"), REFRESH_HOME, 1);
    AddExit("oeste", HAB_PUESTO("calles/calle_01"));
    AddExit("este", HAB_PUESTO("posada/posada_salon"));
    AddExit("norte", HAB_PUESTO("posada/posada_escaleras"));
    AddRoomCmd("alquilar", "cmd_alquilar");
    AddRoomCmd("pedir", "cmd_alquilar");
    AddRoomCmd("reiniciar", "cmd_reiniciar");
    n_guardias=random(3);
}


string mirar_mostrador()
{
    if (present("posadero_faeria", TO))
    {
        if (living(present("posadero_faeria", TO)))
            return "Es un pequeño mostrador tras el que está Engelbergt el posadero para atender a sus clientes.\n";
        else if (present("posadero_faeria", TO)->QueryDecayTime())
            return W("Es un pequeño mostrador, tras el que suele estar Engelbergt atendiendo a sus clientes... aunque ahora que te fijas parece que no está.\n"
            "Miras a tu alrededor y descubres que el pobre Engelbergt está tirado en el suelo, y muerto.\n");
    }
    else
    {
        return "Es un pequeño mostrador tras el que suele sentarse Engelbergt a atender a sus clientes, aunque ahora parece que no está.\n";
    }
}

int cmd_alquilar(string str)
{
    if (!present("posadero_faeria", TO) || !living(present("posadero_faeria", TO))) return notify_fail("No hay nadie aquí para atenderte.\n");
    if (TABLON_ENEMIGOS->QueryEnemies()[TP->QueryRealName()])
    {
        write("El posadero te mira y luego abre la boca sorprendido.\n");
        say(W("El posadero mira a " + capitalize(TP->QueryName()) + " y dice:\n"), TP);
        tell_room(TO, W("¡que tu vas a venir a mi posada a pedir algo???!!!\nNo se si sabes que en este pueblo se le ha puesto precio a tu cabeza. De hecho, que yo recuerde, ahora mismo ofrecen " + recompensa(TP) + "!\n"
        "Guardiaas! guardiaaaaas!\n"));
        if (find_call_out("llamar_guardia") == -1) call_out("llamar_guardia", 2+random(4), TP);
    }
    else if (member(RAZASENEMIGAS, TP->QueryRace()) != -1)
    {
        write(W("Engelbergt te grita: Yo no atiendo a los " + TP->QueryRace() + "s en mi posada! Lo mejor que puedes hacer es largarte!\n"));
        say(W(capitalize(TP->QueryName()) + " va a pedirle algo al posadero. Este grita:\n"
        "En mi posada no se alquilan habitaciones a los " + TP->QueryRace() + "s! Lo mejor que puedes hacer es largarte si no quieres que avise a un guardia!\n"));
    }
    else if (TABLON_ENEMIGOS->QueryNonGratas()[TP->QueryRealName()])
    {
        write("El posadero te mira y te dice: ");
        say (W(capitalize(TP->QueryName()) + " va a hablar con el posadero. Este, l" + AO + " mira y le dice: "), TP);
        tell_room (TO, W("Vaya " + capitalize(TP->QueryName()) + ". No se lo que habrás hecho y la verdad, no me interesa; pero la guardia dejó bien claro que no eras bienvenid" + AO + " en nuestro poblado... Así que, yo de tí me iría de aquí antes de que avise a uno de ellos.\n"));
    }
    else
    {
        object libro, llave;
        int hab, dinero, val;
        mixed dinpagado;
        if (!str) return notify_fail("Qué es lo que deseas alquilar?\n");
        else if (str != "habitacion" && str != "una habitacion") return notify_fail("Qué es lo que deseas alquilar?\n");
        libro = clone_object(OBJETO + "otro/faeria/libro_habitaciones");
        if (libro->QueryHuespedes()[TP->QueryRealName()]) return notify_fail(W("Engelbergt te dice: Lo siento " + capitalize(TP->QueryName()) + ", pero tu ya tienes una habitación alquilada.\n"
        "No puedo alqilarte otra habitación más.\n"));
        hab = libro->compruebaHabitaciones();
        if (hab == 0) return notify_fail(W("Engelbergt te dice: Lo siento " + capitalize(TP->QueryName()) + ". Ahora no me quedan habitaciones libres.\n"));
        dinero = QuerySomeonesValue(TP);
        if (dinero < COSTE) return notify_fail(W("Engelbergt te dice: Lo siento " + capitalize(TP->QueryName()) + ", pero no llevas encima " + COSTE_HAB + ", que es lo que cuesta alquilar una habitación.\n"));
        dinpagado = PayValue2(TP, COSTE);
        if (intp(dinpagado))
            write(W("Le pagas a Engelbergt " + dinpagado + ".\n"));
        else
            write("Le pagas a Engelbergt " +dinpagado[0]+(dinpagado[1] ? " y recibes "+dinpagado[1] : "")+".\n");
        llave = clone_object(OBJETO + "otro/faeria/llave_posada");
        llave->AddId("llave_posada_faeria_" + hab);
        llave->SetLong("Es una llave metálica, enganchada a un gran llavero en el que puedes leer: Habitación " + hab + ".\n");
        val = llave->move(TP);
        if (val == ME_OK)
        {
            write(W("Engelbergt te da una llave y te dice: Ahi tienes. Es la habitación " + hab + ".\n"
            "Que disfrutes de tu estancia.\n"));
            say(W("Engelbergt le da una llave a " + capitalize(TP->QueryName()) + ".\n"), TP);
        }
        else
        {
            llave->move(TO);
            write(W("Engelbergt te da una llave y te dice: Aquí tienes. Es la habitación " + hab + ".\n"
            "Sin poder evitarlo, la llave se te cae al suelo.\n"));
            say(W("Engelbergt le da una llave a "+ capitalize(TP->QueryName()) + " pero se le cae al suelo.\n"), TP);
        }
        libro->AddHuesped(TP->QueryRealName());
    }
    return 1;
}



void llamar_guardia(object enemigo)
{
    object guardia;
    if (!present(enemigo, TO) || n_guardias==0) return;
    switch(random(3))
    {
        case 0: // un soldado
            guardia = clone_object(PNJ_PUESTO("soldado"));
            break;
        case 1: // sargento
            guardia = clone_object(PNJ_PUESTO("sargento"));
            break;
        case 2: // conjurador
            guardia = clone_object(PNJ_PUESTO("conjurador"));
            break;
    }
    guardia->move(TO, M_GO);
    n_guardias--;
}

string recompensa(object player)
{
    string mensaje;
    mensaje = TABLON_ENEMIGOS->QueryEnemies()[player->QueryRealName()] * 20 + " mithriles";
    return mensaje;
}

reset()
{
    n_guardias = random(4);
    ::reset();
}


void notify_leave(mixed from, int method, mixed extra)
{
    if (PO->QueryIsPlayer() && present("llave_posada_faeria", PO) && (extra == "oeste" || method == M_TELEPORT || (!extra && method == M_SILENT)))
    {
        object libro;
        if (present("posadero") && living(present("posadero")))
        {
            tell_object(PO, W("El posadero te dice: Eih " + capitalize(PO->QueryName()) + "! antes de salir haz el favor de devolverme la llave de la habitación.\n"
              "Le devuelves la llave a Engelbergt y abandonas la posada.\n"));
            say(W(capitalize(PO->QueryName()) + " le devuelve la llave de su habitación al posadero.\n"), PO);
        }
        else
        {
            tell_object(PO,"Antes de salir, colocas la llave encima del mostrador.\n");
            say(W("Antes de salir, " + capitalize(PO->QueryName()) + ", coloca la llave de su habitación en el mostrador.\n"),PO);
        }
        present("llave_posada_faeria", PO)->remove();
        libro = clone_object(OBJETO + "otro/faeria/libro_habitaciones");
        libro->RemoveHuesped(PO->QueryRealName());
        libro->remove();
    }
    return ::notify_leave(from, method, extra);
}



int cmd_reiniciar()
{
    object libro;
    if (!present("llave_posada_faeria",TP)) return 0;
    tell_object(TP, W("El posadero te dice: Eih " + capitalize(PO->QueryName()) + "! antes de reiniciar haz el favor de devolverme la llave de la habitación.\n"
    "Le devuelves la llave a Engelbergt.\n"));
    say(W(capitalize(PO->QueryName()) + " le devuelve la llave de su habitación al posadero.\n"), TP);
    present("llave_posada_faeria", TP)->remove();
    libro = clone_object(OBJETO + "otro/faeria/libro_habitaciones");
    libro->RemoveHuesped(TP->QueryRealName());
    libro->remove();
    return 0;
}


