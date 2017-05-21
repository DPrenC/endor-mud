/*
DESCRIPCION : La goleta "Audaz" (ruta Azzor-Simauria)
FICHERO     : /d/akallab/comun/objeto/barco/audaz/audaz
*/

#include "./path.h"

#define COSTE          35;
#define PUERTO_AZZOR   AZ_PUERTO("muelle00")
#define PUERTO_GORAT   "/d/simauria/comun/habitacion/caminos/nandor-simauria/puerto"

inherit SHIP;

string *MensajesEntradaBarco(string puerto);
string *MensajesSalidaBarco(string puerto);

public void create()
{
    ::create();


    SetShort("la goleta 'Audaz'");
    SetLong("La goleta 'Audaz' es un velero de tres palos con cofas y vergas en cada uno "
        "de ellos. Es un barco ligero, de poco calado y bordas poco elevadas, lo que "
        "hace que sea bastante rápido. Regularmente realiza el trayecto entre Azzor y "
        "Simauria.\n");
    SetIds(({"audaz", "Audaz", "goleta", "barco"}));

    SetEnterMsgs(({"sube al Audaz.",
                   "sube al barco.",
                   "Subes a la goleta Audaz"}));
    SetLeaveMsgs(({"baja del Audaz.",
                   "abandona el barco por la rampa de estribor.",
                   "Abandonas el barco por la rampa de estribor"}));

    SetShipEnterMsgs(SF(MensajesEntradaBarco));
    SetShipLeaveMsgs(SF(MensajesSalidaBarco));

    AddMoveScene(PUERTO_GORAT, PUERTO_AZZOR,
        "La goleta Audaz navega con rumbo sur-suroeste por la ruta pesquera de "
        "Gorat evitando la península de Nyne.\n", 10);
    AddMoveScene(PUERTO_GORAT, PUERTO_AZZOR,
        "La embarcación bordea la costa oeste de Akallab, dominio orco, y se interna en "
        "las aguas del sur.\n", 10);
    AddMoveScene(PUERTO_GORAT, PUERTO_AZZOR,
        "La nave atraviesa el estrecho de Sbiat y vira en dirección nor-nordeste.\n", 5);
    AddMoveScene(PUERTO_GORAT, PUERTO_AZZOR,
        "La goleta Audaz avanza rumbo norte.\n", 10);
    AddMoveScene(PUERTO_GORAT, PUERTO_AZZOR,
        "La goleta Audaz navega ligera impulsada por un buen viento.\n", 5);

    AddMoveScene(PUERTO_AZZOR, PUERTO_GORAT,
        "La goleta Audaz navega ligera impulsada por un buen viento.\n", 5);
    AddMoveScene(PUERTO_AZZOR, PUERTO_GORAT,
        "La goleta Audaz avanza rumbo sur.\n", 10);
    AddMoveScene(PUERTO_AZZOR, PUERTO_GORAT,
        "La nave atraviesa el estrecho de Sbiat y vira en dirección nor-noroeste.\n", 5);
    AddMoveScene(PUERTO_AZZOR, PUERTO_GORAT,
        "La embarcación bordea la costa oeste de Akallab, dominio orco, y se interna "
        "en las aguas del norte.\n", 10);
    AddMoveScene(PUERTO_AZZOR, PUERTO_GORAT,
        "La goleta evita la península de Nyne y entra en las rutas pesqueras de "
        "Gorat.\n", 10);

    SetMsgCost("No tienes suficiente dinero para viajar.\n");

    AddPort("Azzor", PUERTO_AZZOR);
    AddPort("Simauria", PUERTO_GORAT);

    AddDeck(BAR_AUDAZ("cubierta"));
}

string *MensajesEntradaBarco(string puerto)
{
    if(puerto == PUERTO_AZZOR)
        return ({
            "\nEl vigía grita:'Puerto de Azzor a la vista!!!'\n"
            "La tripulación corre de un lado a otro del barco preparándose para la "
            "maniobra de atraque. Mientras el barco entra por la bocana del puerto, se "
            "arría parte del velamen de la goleta para ralentizar el barco y así "
            "facilitar las maniobras. Al poco tiempo la 'Audaz' alcanza la dársena del "
            "puerto y algunos marineros lanzan cabos al muelle para el amarre. La goleta "
            "se detiene junto al muelle.\nEl Capitán grita:'Ya hemos llegado a Azzor'.\n",
            "La goleta 'Audaz' atraca en el muelle procedente de @@FromHarbour@@.\n"});

    if(puerto == PUERTO_GORAT)
        return ({
            "\nEscuchas un fuerte pitido y oyes como el capitán da a la tripulación las "
            "órdenes pertinentes para atracar en uno de los puertos de Simauria.\n",
            "La goleta 'Audaz' atraca en el muelle procedente de @@FromHarbour@@.\n"});

    return ({
        "El capitán grita: ¡Hemos llegado a @@Harbour@@!\n",
        "La goleta Audaz atraca en el muelle.\n"});
}

string *MensajesSalidaBarco(string puerto)
{
    puerto = FromHarbour();
    if(puerto == "Azzor")
        return ({
            "\nEl Capitán grita: Venga muchachos que nos vamos, izad las velas, soltad "
            "las amarras.. pongamos rumbo a @@Harbour@@.\n",
            "La goleta Audaz abandona el muelle.\n"});

    return ({
        "El Capitán grita: Acabamos de dejar @@FromHarbour@@ y nos dirigimos rumbo a "
        "@@Harbour@@!\n",
        "La goleta Audaz abandona el muelle.\n"});
}

QueryShipCost(){return COSTE;}
