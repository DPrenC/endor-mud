/***
Fichero: taberna.c
Autor: kastwey@simauria
Descripción: La taberna de Siempreunidos.
Creación: 02/12/2004
***/

#include "path.h"
#include <moving.h>


#define T_ABIERTA 1
#define T_CERRADA 0

inherit PUB;
public string SetOficina(string ruta);
public string QueryOficina();
static string pOficina;
int pEstado = 1;
string mirar_mostrador();
public int SetEstado(int valor);
public int QueryEstado();
int cerrar_taberna();
int abrir_taberna();
int es_cliente(object ob);
int echar_clientes();
int ir_casa_tabernero();
void llamar_guardia(object enemigo);
string recompensa(object player);
int n_guardias;

public create()
{
    ::create();
    int horas, minutos, segundos;
    int i, h_cierre, s_cierre, h_apertura, s_apertura;
    SetIntShort("la taberna de Fearghal");
    SetIntLong("Te encuentras en la taberna de Siempreunidos.\n"
               "Es un local más bien pequeño, pero acogedor. Aquí y allá hay "
               "salpicadas algunas mesitas bajas, y en uno de los extremos "
               "de la taberna hay un mostrador tras el que suele estar "
               "Fearghal, sirviendo la comida a los clientes.\n"
               "Hacia el este está la salida y hacia arriba está la casa del "
               "tabernero.\n");
    SetOficina(HAB_PUESTO("calles/calle_01"));
    SetIntSmell("huele a buena comida");
    SetIntBright(45);

    AddDetail(({"mesas", "mesa", "mesitas", "mesilla", "mesillas",
                "mesas bajas", "mesillas bajas"}),
              "Son unas mesitas pequeñas, hechas de algún raro metal. "
              "Alrededor de ellas, hay unas sillas que parecen ideales para "
              "sentarse y tomarse algo.\n");

    AddDetail(({"sillas", "silla"}),
              "Son unas sillas que parecen muy confortables. Están colocadas "
              "alrededor de las mesas.\n");

    AddDetail(({"mostrador", "barra"}), SF(mirar_mostrador));

    AddFood("ensalada", "una", 10, 10, 0,
            "Te comes una fuente de ensalada enterita... Hmmm. la verdad es "
            "que estaba buenísima.");

    AddFood("conejo asado", "un plato de", 15, 20, 0,
            "Te comes un plato de conejo asado. Jugoso, tiernito, ¡delicioso!");

    AddDrink("cerveza", "una jarra de", 0, 8, 10, 0, 0);
    AddDrink("hidromiel", "un vaso de", 20, 0, 10, 0, 0);
    AddDrink("vino", "un vaso de", 3, 8, 13, 0, 0);
    AddItem(PNJ_PUESTO("fearghal"), REFRESH_HOME, 1);
    AddItem(PNJ_PUESTO("encubierto"), REFRESH_HOME, 1);
    // el número de guardias que quedan para poder ser llamados por el tabernero
    n_guardias = 1 + random(4);

    AddExit("este", HAB_PUESTO("calles/calle_01"));
    AddExit("arriba", SF(ir_casa_tabernero));

    // hora de cierre... las 3 de la mañana.
    // apertura: 10 de la mañana.
    if (!(CHRONOS->QueryHour() >= 3 && CHRONOS->QueryHour() < 10))
    {
        // está abierta.
        // calculamos las horas, minutos y segundos que faltan para el cierre.
        // luego lo convertiremos a segundos y lo dividiremos entre 4 para
        // obtener los segundos de call_out para llamar a la función cierre.
        // esto de dividirlo entre cuatro es porque un día normal, son cuatro
        // días de Simauria.
        h_cierre=CHRONOS->QueryHour();
        while (h_cierre != 3)
        {
            i++;
            h_cierre++;
            if (h_cierre == 24) h_cierre = 0;
        }
        i--;
        horas=i;
        // ahora calculamos los minutos:
        minutos = 60 - CHRONOS->QueryMinute();
        // y ahora los segundos:
        segundos = 60-CHRONOS->QuerySecond();
        // calculamos los segundos hasta el cierre
        s_cierre = horas*3600;
        s_cierre += minutos*60;
        s_cierre +=segundos;
        // llamamos al call_out con el s_cierre para cerrar la taberna.
        // ajustamos a los segundos del mud:
        s_cierre /= 4;
        call_out("cerrar_taberna", s_cierre);
    }
    else
    // está cerrada
    {
    	// calculamos las horas, minutos y segundos que faltan para la apertura.
        // luego lo convertiremos a segundos y lo dividiremos entre 4 para
        // obtener los segundos de call_out para llamar a la función abrir_taberna.
        h_apertura = CHRONOS->QueryHour();
        horas=10-h_apertura;
        horas--;
        // ahora calculamos los minutos:
        minutos = 60 - CHRONOS->QueryMinute();
        // y ahora los segundos:
        segundos = 60-CHRONOS->QuerySecond();
        // calculamos los segundos hasta la apertura
        s_apertura = horas*3600;
        s_apertura += minutos*60;
        s_apertura +=segundos;
        // llamamos al call_out con el s_apertura para cerrar la taberna.
        // ajustamos a los segundos del mud:
        s_apertura = s_apertura / 4;
        call_out("abrir_taberna", s_apertura);
        // debug tell_object(find_object("kastwey"),s_apertura + ".\n");
    }
}

string mirar_mostrador()
{
    if (present("fearghal", TO))
    {
        if (living(present("fearghal", TO)))
            return "Es un mostrador tras el que está Fearghal, el tabernero para atender a sus clientes.\n";
        else if (present("fearghal", TO)->QueryDecayTime())
            return W("Es un mostrador alargado, tras el que suele estar Fearghal atendiendo a sus clientes... aunque ahora que te fijas parece que no está.\n"
            "Miras a tu alrededor y descubres que el pobre Fearghal está tirado en el suelo, y muerto.\n");
    }
    else
    {
        return "Es un mostrador alargado tras el que suele sentarse Fearghal a atender a sus clientes, aunque ahora parece que no está.\n";
    }
}

int allow_enter(int method, mixed extra)
{
    if (QueryEstado() == T_CERRADA)
        return tell_object(PO, "Cuando vas a entrar a la taberna, te das cuenta de que la puerta está cerrada a cal y canto. Luego miras el cartel y lees que el horario de apertura es de 10 de la mañana a 3 de la madrugada...\n"), ME_NO_ENTER;
    else if (CHRONOS->QueryHour() >= 3 && CHRONOS->QueryHour() < 10)
    {
        SetEstado(T_CERRADA);
    return tell_object(PO, "Cuando vas a entrar a la taberna, te das cuenta de que la puerta está cerrada a cal y canto. Luego miras el cartel y lees que el horario de apertura es de 10 de la mañana a 3 de la madrugada...\n"), ME_NO_ENTER;
    }
    else
        return ME_OK;
}

public int SetEstado(int valor) { return pEstado = valor; }

public int QueryEstado() { return pEstado; }

int cerrar_taberna()
{
    reset();
    tell_room(TO, W("El tabernero grita: Eeeh! veenga! que ya es hora de cerrar!\n"
    "Toodos fuera! que ahora me tengo que quedar un rato más limpiando todo esto y mañana toca madrugar como siempre.\n"));
    call_out("echar_clientes", 10);
    return 1;
}


int es_cliente(object ob)
{
    if (living(ob) && ob != present("tabernero_faeria", TO) && !ob->QueryIsGuardia())
        return 1;
    return 0;
}


int echar_clientes()
{
    int i;
    object *inv;
    inv=all_inventory(TO);
    inv = filter(inv, "es_cliente");
    for (i=sizeof(inv);i--;)
    {
        if (inv[i]->Fighting())
        {
        	tell_object(inv[i], "De mala gana, abandonas la lucha para irte del establecimiento.\n");
        	inv[i]->StopAllHunting();
        }
        inv[i]->move(HAB_PUESTO("calles/calle_01"), M_SPECIAL, ({"sale de la taberna", "llega del oeste", "Rápidamente te diriges a la puerta y abandonas el local"}));
    }

    SetEstado(T_CERRADA);
    return 1;
}
int ir_casa_tabernero()
{
    if (present("tabernero_faeria", TO) && living(present("tabernero_faeria", TO)))
        write(W("El tabernero te cierra el paso y te dice:\n"
        "Eh! a donde crees que vas?\n"));
    else
        write(W("Comienzas a subir las escaleras, y te das cuenta que en mitad de ella hay una puerta sólidamente cerrada.\n"
        "Das la vuelta y vuelves a la taberna.\n"));
    return 1;
}


int _porder(string str)
{
    if (!present("tabernero_faeria", TO) || present("tabernero_faeria", TO)->QueryDecayTime()) return notify_fail("No hay nadie aquí para atenderte.\n");
    if (TABLON_ENEMIGOS->QueryEnemies()[TP->QueryRealName()])
    {
        write("El tabernero te mira y luego abre la boca sorprendido.\n");
        say(W("El tabernero mira a " + capitalize(TP->QueryName()) + " y dice:\n"), TP);
        tell_room(TO, W("¡que tu vas a venir a mi taberna a pedir algo???!!!\nNo se si sabes que en este pueblo se le ha puesto precio a tu cabeza. De hecho, que yo recuerde, ahora mismo ofrecen " + recompensa(TP) + "!\n"
        "Guardiaas! guardiaaaaas!\n"));
        if (find_call_out("llamar_guardia") == -1) call_out("llamar_guardia", 2+random(4), TP);
    }
    else if (member(RAZASENEMIGAS, TP->QueryRace()) != -1)
    {
        write(W("Feargal te grita: Yo no atiendo a los " + TP->QueryRace() + "s en mi taberna! Lo mejor que puedes hacer es largarte!\n"));
        say(W(capitalize(TP->QueryName()) + " va a pedirle algo al tabernero. Este grita:\n"
        "En mi taberna no se sirve nada a los " + TP->QueryRace() + "s! Lo mejor que puedes hacer es largarte si no quieres que avise a un guardia!\n"));
    }
    else if (TABLON_ENEMIGOS->QueryNonGratas()[TP->QueryRealName()])
    {
        write("El tabernero te mira y te dice: ");
        say (W(capitalize(TP->QueryName()) + " va a hablar con el tabernero. Este, l" + AO + " mira y le dice: "), TP);
        tell_room (TO, W("Vaya " + capitalize(TP->QueryName()) + ". No se lo qué habrás hecho y la verdad, no me interesa; pero la guardia dejó bien claro que no eras bienvenid" + AO + " en nuestro poblado... Así que, yo de tí me iría de aquí antes de que avise a uno de ellos.\n"));
    }
    else
    {
        return ::_porder(str);
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
    mensaje =    TABLON_ENEMIGOS->QueryEnemies()[player->QueryRealName()] * 20 + " mithriles";
    return mensaje;
}

reset()
{
    n_guardias = random(4);
    ::reset();
}
int abrir_taberna()
{
    reset();
    SetEstado(T_ABIERTA);
    tell_room(HAB_PUESTO("calles/calle_01"), "Fearghal llega y abre la taberna.\n");
    return 1;
}
public string SetOficina(string ruta) { return pOficina = ruta; }

public string QueryOficina() { return pOficina; }
