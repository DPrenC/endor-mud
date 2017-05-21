/*****************************************************************************************
 ARCHIVO:       barca_glinnael.c
 AUTOR:         Ztico
 FECHA:         06-05-2005
 DESCRIPCI�N:   Barca que une el bosque de Faeria con la isla de los Druidas en el lago
                Glinnael.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"
#define PUERTO_DRIADAS   HAB_BOSQUE_DRIADAS("bosque64")
#define PUERTO_ISLA      HAB_BOSQUE_ISLA("robledal00")

inherit SHIP;

string *MensajesLlegadaDestino(string puerto);
string *MensajesSalidaOrigen(string puerto);

create()
{
    ::create();

    SetShort("la nube flotante");
    SetLong("Es una peque�a barca hecha de ramas trenzadas.\n");
    SetIds(({"barca", "bote", "nube", "nube flotante"}));

    SetEnterMsgs(({"sube a la barca.",
                   "sube a la barca con cuidado.",
                   "Te montas en la nube flotante"}));
    SetLeaveMsgs(({"baja de la barca.",
                   "abandona la barca cuidadosamente.",
                   "Abandonas la nube flotante"}));

    SetShipLeaveMsgs(SF(MensajesSalidaOrigen));
    SetShipEnterMsgs(SF(MensajesLlegadaDestino));

    AddMoveScene(PUERTO_DRIADAS, PUERTO_ISLA,
        "La barca avanza por el r�o Ellidan.\n", 10);
    AddMoveScene(PUERTO_DRIADAS, PUERTO_ISLA,
        "La barca se adentra en el lago Grinnael.\n", 10);
    AddMoveScene(PUERTO_ISLA, PUERTO_DRIADAS,
        "Est�s cruzando el lago Glinnael.\n", 10);
    AddMoveScene(PUERTO_ISLA, PUERTO_DRIADAS,
        "Dejas el lago y entras en el rio Ellidan.\n", 10);
    SetMsgCost("No tienes suficiente dinero para viajar.\n");

    AddPort("bosque de las Dr�adas", PUERTO_DRIADAS);
    AddPort("isla de los Druidas", PUERTO_ISLA);

    AddDeck(BARCO("barca_faeria/int_barca.c"));
}

string *MensajesSalidaOrigen(string puerto)
{
    puerto = FromHarbour();
    if (puerto == "bosque de las Dr�adas")
        return ({
            "\nAzoradamente el barquero toma los peque�os remos de madera y la barca"
            "comienza a alejarse del embarcadero. Te diriges a la isla que se encuentra"
            "en el centro del lago.\n",
            "La nube flotante se aleja lentamente del embarcadero.\n"});

    if (puerto == "isla de los Druidas")
        return ({
            "\nLa barca comienza a moverse gracias al impulso del barquero.\n"
            "Te diriges al bosque de las Driadas.\n",
            "La barca se aleja del embarcadero.\n"});

    return ({
        "La barca comienza a alejarse del embarcadero.\n ",
        "La nube flotante se aleja del embarcadero.\n"});
}

string *MensajesLlegadaDestino(string puerto)
{
     if (puerto == PUERTO_DRIADAS)
         return ({
             "\nHas llegado a las inmediaciones del bosque de las Driadas. La barca "
             "se aproxima lentamente al embarcadero y se para junto al peque�o muelle.\n",
             "Una peque�a barca de ramas y cuero se detiene en el embarcadero.\n"});

     if (puerto == PUERTO_ISLA)
         return ({
             "\nLlegas a un peque�o embarcadero situado al suroeste de la isla que se "
             "encuentra en el centro del lago Glinnael. Todo parece solitario y "
             "abandonado.\n",
             "Una barca se aproxima y se detiene en el embarcadero.\n"});

     return ({
         "La barca llega a @@Harbour@@!\n",
         "La barca atraca en el embarcadero.\n"});
}

int QueryShipCost()
{
    if(member(RAZASENEMIGAS, TP->QueryRace()) >= 0)
        return 50; // En caso de ser enemigo
    return 0; // Si eres raza amiga no pagas
}
