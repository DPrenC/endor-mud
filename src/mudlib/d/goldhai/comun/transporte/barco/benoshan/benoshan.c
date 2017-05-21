/*=============================================================*
 |           << GOLDHAI.Barcos [w] Woo@simauria >>             |
 *=============================================================*
 |              Creacion............. 28-10-98                 |
 |              Ultima Modificacion.. 17-11-98                 |
 |                                                             |
 *=============================================================*/

#include "./path.h"

#define PUERTO_GORAT     "/d/simauria/comun/habitacion/caminos/nandor-simauria/puerto"
#define MUELLE2_GOLDHAI  PUERTO("muelle2")

inherit SHIP;

string *MensajesEntradaBarco(string puerto);
string *MensajesSalidaBarco(string puerto);

public void create()
{
    ::create();

    seteuid(getuid(TO));

    SetShort("el Benoshan");
    SetLong("El Benoshan es un barco que parece salido de un cementerio de veleros. Su "
        "aspecto es bastante desagradable y no te da ninguna seguridad de llegar a buen "
        "puerto.\n");
    SetIds(({"benoshan", "Benoshan", "barco"}));

    SetEnterMsgs(({"sube al Benoshan.",
                   "sube al barco.",
                   "Subes al Benoshan"}));
    SetLeaveMsgs(({"baja del Benoshan.",
                   "abandona el barco por la rampa de proa.",
                   "Abandonas el barco por una peque�a rampa de la proa"}));

    SetShipEnterMsgs(SF(MensajesEntradaBarco));
    SetShipLeaveMsgs(SF(MensajesSalidaBarco));

    AddMoveScene(PUERTO_GORAT, MUELLE2_GOLDHAI,
        "El Benoshan navega con rumbo sur-suroeste por la ruta pesquera de "
        "Gorat evitando la pen�nsula de Nyne.\n", 10);
    AddMoveScene(PUERTO_GORAT, MUELLE2_GOLDHAI,
        "La embarcaci�n bordea la costa oeste de Akallab, dominio orco, y se interna en "
        "las aguas del sur.\n", 10);
    AddMoveScene(PUERTO_GORAT, MUELLE2_GOLDHAI,
        "La nave atraviesa el estrecho de Sbiat y vira en direcci�n este.\n", 5);
    AddMoveScene(PUERTO_GORAT, MUELLE2_GOLDHAI,
        "El Benoshan contin�a en direcci�n este.\n", 10);
    AddMoveScene(PUERTO_GORAT, MUELLE2_GOLDHAI,
        "El Benoshan navega ligero impulsado por un buen viento.\n", 5);

    AddMoveScene(MUELLE2_GOLDHAI, PUERTO_GORAT,
        "El Benoshan navega ligero impulsado por un buen viento.\n", 5);
    AddMoveScene(MUELLE2_GOLDHAI, PUERTO_GORAT,
        "El Benoshan avanza rumbo oeste.\n", 10);
    AddMoveScene(MUELLE2_GOLDHAI, PUERTO_GORAT,
        "La nave atraviesa el estrecho de Sbiat y vira en direcci�n nor-noroeste.\n", 5);
    AddMoveScene(MUELLE2_GOLDHAI, PUERTO_GORAT,
        "La embarcaci�n bordea la costa oeste de Akallab, dominio orco, y se interna "
        "en las aguas del norte.\n", 10);
    AddMoveScene(MUELLE2_GOLDHAI, PUERTO_GORAT,
        "El barco evita la pen�nsula de Nyne y entra en las rutas pesqueras de "
        "Gorat.\n", 10);

    SetMsgCost("No tienes suficiente dinero para viajar.\n");

    AddPort("Gorat", PUERTO_GORAT);
    AddPort("Goldhai Oeste", MUELLE2_GOLDHAI);

    AddDeck(BENOSHAN("int_benoshan"));
}

string *MensajesEntradaBarco(string puerto)
{

    if(puerto == PUERTO_GORAT)
       return ({
           "\nEl vig�a grita: ���Puerto de Gorat a la vista!!!\nLa tripulaci�n corre de "
           "un lado a otro del barco prepar�ndose para atracar en el puerto. Mientras "
           "unos arr�an las velas, otros se preparan para lanzar los cabos al muelle. El "
           "Benoshan poco a poco se detiene en el puerto.\nEl Capit�n grita: Ya hemos "
           "llegado a Gorat.\n",
           "El Benoshan atraca en el muelle procedente de @@FromHarbour@@.\n"});

    if(puerto == MUELLE2_GOLDHAI)
        return ({
            "\nEscuchas un fuerte pitido y oyes como el Capit�n da a la tripulaci�n las "
            "�rdenes pertinentes para atracar en lo que parece ser uno de los muelles "
            "del principal puerto de Goldhai, situado en la parte Oeste de la isla.\n",
            "El Benoshan atraca en el muelle procedente de @@FromHarbour@@.\n"});

    return ({
        "El Capit�n grita: Hemos llegado a @@Harbour@@!\n",
        "El Benoshan atraca en el muelle.\n"});
}

string *MensajesSalidaBarco(string puerto)
{
    puerto = FromHarbour();

    if (puerto == "Goldhai Oeste")
        return ({
            "\nEl Capit�n grita: Venga muchachos que nos vamos, izad las velas, soltad "
            "las amarras.. pongamos rumbo a @@Harbour@@.\n",
            "El Benoshan abandona el muelle.\n"});

     return ({
         "El Capit�n grita: Acabamos de dejar @@FromHarbour@@ y nos dirigimos rumbo a "
         "@@Harbour@@!\n ",
         "El Benoshan abandona el muelle.\n"});
}

int QueryShipCost() { return 15; }
