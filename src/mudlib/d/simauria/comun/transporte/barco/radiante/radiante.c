/*
--------------------------------------------------------------------------------
DESCRIPCION : La goleta "Radiante" (ruta Simauria-Simauria)
FICHERO     : /d/simauria/comun/objeto/barco/radiante/radiante.c
*/

#include "./path.h"
#define NBARCO         "Radiante"
#define PUERTOSALIDA   "Berat"
#define PUERTOLLEGADA  "Gorat"
#define COSTE          50;
#define PUERTO_BERAT   SIMA("berat/muelle01")
#define PUERTO_GORAT   CNS("puerto")

inherit SHIP;

string *MensajesEntradaBarco(string puerto);
string *MensajesSalidaBarco(string puerto);

public void create()
{
    ::create();

    SetShort("la goleta " + NBARCO);
    SetLong("La goleta " + NBARCO + " es un velero de tres palos con cofas y vergas en "
        "todos ellos. Es un barco ligero, de poco calado y bordas poco elevadas, lo que "
        "hace que sea bastante rápido. Regularmente realiza el trayecto entre " +
        PUERTOSALIDA + " y " + PUERTOLLEGADA + ".\n");
    SetIds(({"radiante", NBARCO, "goleta", "barco"}));

    SetEnterMsgs(({"sube al " + NBARCO + ".",
                   "sube al barco.",
                   "Subes a la goleta " + NBARCO}));
    SetLeaveMsgs(({"baja del " + NBARCO + ".",
                   "abandona el barco por la rampa de estribor.",
                   "Abandonas el barco por la rampa de estribor."}));

    SetShipEnterMsgs(SF(MensajesEntradaBarco));
    SetShipLeaveMsgs(SF(MensajesSalidaBarco));

    AddMoveScene(PUERTO_BERAT, PUERTO_GORAT,
        "La goleta " + NBARCO + " navega ligera impulsada por un buen viento.\n", 10);
    AddMoveScene(PUERTO_BERAT, PUERTO_GORAT,
        "La barca vira hacia el oeste rodeando la península de Nyne.\n", 10);
    AddMoveScene(PUERTO_BERAT, PUERTO_GORAT,
        "La goleta " + NBARCO + " cambia de rumbo en dirección norte-nordeste, entrando "
        "en la ruta pesquera de Gorat.\n", 10);

    AddMoveScene(PUERTO_GORAT, PUERTO_BERAT,
        "La goleta " + NBARCO + " navega con rumbo sur-suroeste por la ruta pesquera de "
        "Gorat.\n", 10);
    AddMoveScene(PUERTO_GORAT, PUERTO_BERAT,
        "La barca vira hacia el este rodeando la península de Nyne.\n", 10);
    AddMoveScene(PUERTO_GORAT, PUERTO_BERAT,
        "La goleta " + NBARCO + " surca las aguas del golfo de Berat.\n", 10);

    SetMsgCost("No tienes suficiente dinero para viajar.\n");

    AddPort(PUERTOLLEGADA, PUERTO_GORAT);
    AddPort(PUERTOSALIDA, PUERTO_BERAT);

    AddDeck(RADIANTE("cubierta"));
    AddRoom(RADIANTE("camarote"));
    AddRoom(RADIANTE("bodega"));
}

string *MensajesEntradaBarco(string puerto)
{

    if(puerto == PUERTO_BERAT)
        return ({
            "\nEl vigía grita: '¡¡¡Puerto de " + PUERTOSALIDA + " a la vista!!!'\n",
            "La goleta " + NBARCO + " atraca en el muelle procedente de "
            "@@FromHarbour@@.\n"});

    if(puerto == PUERTO_GORAT)
        return ({
            "\nEscuchas un fuerte pitido y oyes como el capitán da a la tripulación las "
            "ordenes pertinentes para atracar en uno de los puertos de Simauria.\n",
            "La goleta " + NBARCO + " atraca en el muelle procedente de "
            "@@FromHarbour@@.\n"});

    return ({
        "El capitán grita: ¡Hemos llegado a @@Harbour@@!\n",
        "La goleta " + NBARCO + " atraca en el muelle.\n"});
}

string *MensajesSalidaBarco(string puerto)
{
    puerto=FromHarbour();
    if (puerto == PUERTOSALIDA)
        return ({
            "\nEl Capitán grita: Venga muchachos que nos vamos, izad las velas, soltad "
            "las amarras.. pongamos rumbo a @@Harbour@@.\n",
            "La goleta " + NBARCO + " abandona el muelle.\n"});

    return ({
        "El Capitán grita: Acabamos de dejar @@FromHarbour@@ y nos dirigimos rumbo a "
        "@@Harbour@@!\n",
        "La goleta Radiante abandona el muelle.\n"});
}

int QueryShipCost(){return COSTE;}
