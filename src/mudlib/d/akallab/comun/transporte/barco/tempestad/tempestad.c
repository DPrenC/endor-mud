/*
DESCRIPCION : La goleta "Tempestad" (ruta Azzor-Goldhai)
FICHERO     : /d/akallab/comun/objeto/barco/tempestad/tempestad.c
MODIFICACION: 01-11-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"

#define COSTE            35;
#define PUERTO_AZZOR     AZ_PUERTO("muelle01")
#define PUERTO_GOLDHAI   "/d/goldhai/comun/habitacion/puerto/muelle4"

inherit SHIP;

string *MensajesEntradaBarco(string puerto);
string *MensajesSalidaBarco(string puerto);

public void create()
{
    ::create();


    SetShort("la goleta 'Tempestad'");
    SetLong("La goleta 'Tempestad' es un velero de tres palos con cofas y vergas en "
        "todos ellos. Es un barco ligero, de poco calado y bordas poco elevadas, lo que "
        "hace que sea bastante rápido. Regularmente realiza el trayecto entre Azzor y "
        "Goldhai.\n");
    SetIds(({"tempestad", "Tempestad", "goleta", "barco"}));

    SetEnterMsgs(({"sube al Tempestad.",
                   "sube al barco.",
                   "Subes a la goleta Tempestad"}));
    SetLeaveMsgs(({"baja del Tempestad.",
                   "abandona el barco por la rampa de estribor.",
                   "Abandonas el barco por la rampa de estribor"}));

    SetShipEnterMsgs(SF(MensajesEntradaBarco));
    SetShipLeaveMsgs(SF(MensajesSalidaBarco));

    AddMoveScene(PUERTO_AZZOR, PUERTO_GOLDHAI,
        "La goleta Tempestad navega ligera impulsada por un buen viento.\n", 10);
    AddMoveScene(PUERTO_AZZOR, PUERTO_GOLDHAI,
        "La goleta Tempestad avanza rumbo sur-sureste.\n", 15);
    AddMoveScene(PUERTO_GOLDHAI, PUERTO_AZZOR,
        "La goleta Tempestad avanza rumbo nor-noroeste.\n", 15);
    AddMoveScene(PUERTO_GOLDHAI, PUERTO_AZZOR,
        "La goleta Tempestad navega ligera impulsada por un buen viento.\n", 10);

    SetMsgCost("No tienes suficiente dinero para viajar.\n");

    AddPort("Azzor", PUERTO_AZZOR);
    AddPort("Goldhai", PUERTO_GOLDHAI);

    AddDeck(BAR_TEMPEST("cubierta"));
}

string *MensajesEntradaBarco(string puerto)
{
    if(puerto == PUERTO_AZZOR)
        return ({
            "\nEl vigía grita: 'Puerto de Azzor a la vista!!!'\n"
            "La tripulación corre de un lado a otro del barco preparándose para la "
            "maniobra atraque. Mientras el barco entra por la bocana del puerto, se "
            "arría parte del velamen de la goleta para ralentizar el barco y así "
            "facilitar las maniobras. Al poco tiempo la 'Tempestad' alcanza la dársena "
            "del puerto y algunos marineros lanzan cabos al muelle para el amarre. La "
            "goleta se detiene junto al muelle.\nEl capitán grita:'Ya hemos llegado a "
            "Azzor'.\n",
            "La goleta 'Tempestad' atraca en el muelle procedente de "
            "@@FromHarbour@@.\n"});

    if(puerto == PUERTO_GOLDHAI)
        return ({
            "\nEscuchas un fuerte pitido y oyes como el capitán da a la tripulación las "
            "ordenes pertinentes para atracar en uno de los puertos de Goldhai.\n",
            "La goleta 'Tempestad' atraca en el muelle procedente de "
            "@@FromHarbour@@.\n"});

    return ({
        "El capitán grita: Hemos llegado a @@Harbour@@!\n",
        "La goleta 'Tempestad' atraca en el muelle.\n"});
}

string *MensajesSalidaBarco(string puerto)
{
    puerto = FromHarbour();

    if(puerto == "Azzor")
        return ({
            "\nEl Capitán grita: Venga muchachos que nos vamos, izad las velas, soltad "
            "las amarras.. pongamos rumbo a @@Harbour@@.\n",
            "La goleta 'Tempestad' abandona el muelle.\n"});

    return ({
        "El Capitán grita: Acabamos de dejar @@FromHarbour@@ y nos dirigimos rumbo a "
        "@@Harbour@@!\n",
        "La goleta 'Tempestad' abandona el muelle.\n"});
}

QueryShipCost(){ return COSTE; }
