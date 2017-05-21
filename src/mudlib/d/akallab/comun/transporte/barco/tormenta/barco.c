// DESCRIPCION : Carguero "Tormenta" (ruta Azzor-Morhugok)
// MODIFICACION: 26-05-2008 [Angor] Creacion

#include "./path.h"

#define COSTE          5;
#define PUERTO_AZZOR    AZ_PUERTO("muelle02")
#define PUERTO_MORHUGOK MORHUGOK("muelle")
#define N_BARCO	"Tormenta"

inherit SHIP;

string *MensajesEntradaBarco(string puerto);
string *MensajesSalidaBarco(string puerto);

public void create()
{
::create();
SetShort("el carguero "+N_BARCO);
SetLong(
"El viejo carguero "+N_BARCO+" es un barco lento, pesado, ancho y de "
"gran calado. Este carguero realiza el trayecto entre Azzor y Morhugok a"
"lo largo de la costa.\n");

SetIds(({"carguero", N_BARCO , "barco"}));

SetEnterMsgs(({"sube al carguero "+N_BARCO,
               "sube al barco.",
               "Subes al carguero"+N_BARCO}));
SetLeaveMsgs(({"baja del carguero "+N_BARCO,
               "abandona el barco por la rampa de estribor.",
               "Abandonas el barco por la rampa de estribor"}));

SetShipEnterMsgs(SF(MensajesEntradaBarco));
SetShipLeaveMsgs(SF(MensajesSalidaBarco));

    //Morhugok > Azzor
    AddMoveScene(PUERTO_MORHUGOK, PUERTO_AZZOR,
        "El carguero parte de la bahia de Morhugok.\n", 5);
    AddMoveScene(PUERTO_MORHUGOK, PUERTO_AZZOR,
        "El carguero avanza rumbo norte junto a la costa.\n", 5);
    AddMoveScene(PUERTO_MORHUGOK, PUERTO_AZZOR,
        "La madera del carguero cruje lastimosamente cuando las olas embisten.\n", 5);
    AddMoveScene(PUERTO_MORHUGOK, PUERTO_AZZOR,
        "El carguero "+N_BARCO+" navega pesadamente.\n", 5);
    AddMoveScene(PUERTO_MORHUGOK, PUERTO_AZZOR,
        "El puerto de Azzor aparece ante ti.\n", 5);

    //Morhugok < Azzor
    AddMoveScene(PUERTO_AZZOR, PUERTO_MORHUGOK,
        "El carguero deja atras el puerto de Azzor y navega en mar abierto.\n", 5);
    AddMoveScene(PUERTO_AZZOR, PUERTO_MORHUGOK,
        "El carguero avanza rumbo sur siguiendo la linea de la costa.\n", 5);
    AddMoveScene(PUERTO_AZZOR, PUERTO_MORHUGOK,
        "La madera del carguero cruje lastimosamente cuando las olas embisten.\n", 5);
    AddMoveScene(PUERTO_AZZOR, PUERTO_MORHUGOK,
        "El carguero "+N_BARCO+" navega pesadamente.\n", 5);
    AddMoveScene(PUERTO_AZZOR, PUERTO_MORHUGOK,
        "Divisas los acantilados de Morhugok.\n", 5);
          
    SetMsgCost("No tienes suficiente dinero para viajar.\n");

    AddPort("Azzor", PUERTO_AZZOR);
    AddPort("Morhugok", PUERTO_MORHUGOK);
    AddDeck(BAR_TORMENTA("cubierta"));
}

string *MensajesEntradaBarco(string puerto)
{
    if(puerto == PUERTO_AZZOR)
        return ({
            "\nEl vigía grita:'¡Puerto de Azzor a la vista!'\n"
            "La tripulación corre de un lado a otro del barco preparándose para la "
            "maniobra de atraque. Mientras el barco entra por la bocana del puerto, se "
            "arría parte del velamen del carguero para ralentizar el barco y así "
            "facilitar las maniobras. Al poco tiempo el carguero alcanza la dársena del "
            "puerto y algunos marineros lanzan cabos al muelle para el amarre. El barco "
            "se detiene junto al muelle.\nEl Capitán grita:'¡Ya hemos llegado a Azzor'!.\n",
            "El carguero "+N_BARCO+" atraca en el muelle procedente de @@FromHarbour@@.\n"});

    if(puerto == PUERTO_MORHUGOK)
        return ({
            "\nEscuchas como el capitán da entre gritos órdenes a la tripulación para "
            "\natracar en el muelle de la bahia\n",
            "El carguero "+N_BARCO+" atraca en el muelle procedente de @@FromHarbour@@.\n"});

    return ({
        "El capitán grita: ¡Hemos llegado a @@Harbour@@!\n",
        "El carguero "+N_BARCO+" atraca en el muelle.\n"});
}

string *MensajesSalidaBarco(string puerto)
{
    puerto = FromHarbour();
    if(puerto == "Azzor")
        return ({
"\nEl capitán grita: '¡Atajo de vagos! ¡izad las velas y tensad los cabos que\n"
"partimos rumbo a @@Harbour@@!. ¡Moveos o acabareis de comida para los peces!\n",
"El carguero abandona el muelle.\n"});

    return ({
"\nEl capitán grita: '¡Atajo de vagos! ¡izad las velas y tensad los cabos que\n"
"partimos rumbo a @@Harbour@@!. ¡Moveos o acabareis de comida para los peces!\n",
"El carguero abandona el muelle.\n"});

}

QueryShipCost(){return COSTE;}
