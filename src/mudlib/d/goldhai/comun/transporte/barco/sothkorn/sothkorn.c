/*=============================================================*
 |           << GOLDHAI.Barcos [w] Woo@simauria >>             |
 *=============================================================*
 |              Creacion............. 23-08-98                 |
 |              Ultima Modificacion.. 05-10-98                 |
 |                                                             |
 *=============================================================*/

#include "./path.h"

#define PUERTO_GLUCKSFALL  GLUCKSFALL("muelle")
#define PUERTO_GOLDHAI     PUERTO("muelle3")

inherit SHIP;

string *MensajesEntradaBarco(string puerto);
string *MensajesSalidaBarco(string puerto);

public void create()
{
    ::create();
   	
    
    SetShort("el Sothkorn");
    SetLong("El Sothkorn es un pequeño velero de color rojo que realiza el recorrido "
        "Goldhai Oeste - Glucksfall. Su aspecto es ruinoso pero parece más o menos "
        "seguro para poder viajar en él.\n");
    AddId("sothkorn");

    SetEnterMsgs(({"sube al Sothkorn.",
                   "sube al barco.",
                   "Subes al Sothkorn"}));
    SetLeaveMsgs(({"baja del Sothkorn.",
                   "abandona el barco por la rampa de proa.",
                   "Abandonas el barco por una pequeña rampa de la proa"}));

    SetShipEnterMsgs(SF(MensajesEntradaBarco));
    SetShipLeaveMsgs(SF(MensajesSalidaBarco));
    
    AddMoveScene(PUERTO_GOLDHAI, PUERTO_GLUCKSFALL,
        "El Sothkorn rodea la costa norte de la isla de Goldhai.\n", 5);
    AddMoveScene(PUERTO_GOLDHAI, PUERTO_GLUCKSFALL,
        "La nave vira en dirección este continuando su viaje.\n", 5);
    AddMoveScene(PUERTO_GOLDHAI, PUERTO_GLUCKSFALL,
        "El Sothkorn se acerca al puerto de Glucksfall.\n", 10);
    
    AddMoveScene(PUERTO_GLUCKSFALL, PUERTO_GOLDHAI,
        "El Sothkorn navega con rumbo norte rodeando la isla de Goldhai.\n", 10);
    AddMoveScene(PUERTO_GLUCKSFALL, PUERTO_GOLDHAI,
        "La embarcación vira hacia el oeste y prosigue su camino.\n", 5);
    AddMoveScene(PUERTO_GLUCKSFALL, PUERTO_GOLDHAI,
        "La nave vira de nuevo en dirección sur y se acerca al muelle Oeste de la "
        "isla.\n", 5);    
        
    SetMsgCost("No tienes suficiente dinero para viajar.\n");

    AddPort("Glucksfall", PUERTO_GLUCKSFALL);
    AddPort("Goldhai Oeste", PUERTO_GOLDHAI);

    AddDeck(SOTHKORN("int_sothkorn")); 
}

string *MensajesEntradaBarco(string puerto)
{
    if(puerto == PUERTO_GLUCKSFALL)
        return ({
            "\nEl vigia grita: ¡¡¡Puerto de Glucksfall a la vista!!!\nLa tripulación "
            "corre de un lado a otro del barco preparándose para atracar en Glucksfall. "
            "Mientras unos arrían las velas, otros se preparan para lanzar los cabos al "
            "muelle. El Sothkorn poco a poco se detiene en el puerto.\nEl Capitán "
            "grita: ¡Ya hemos llegado a Glucksfall!\n",
            "El Sothkorn atraca en el muelle procedente de @@FromHarbour@@.\n"});

    if(puerto == PUERTO_GOLDHAI)
        return ({
            "\nEscuchas un fuerte pitido y oyes cómo el Capitán da a la tripulación las "
            "ordenes pertinentes para atracar en lo que parece ser uno de los muelles "
            "del principal puerto de Goldhai situado en la parte Oeste de la isla.\n",
            "El Sothkorn atraca en el muelle procedente de @@FromHarbour@@.\n"});

    return ({
        "El Capitán grita: Hemos llegado a @@Harbour@@!\n",
        "El Sothkorn atraca en el muelle.\n"});
}

string *MensajesSalidaBarco(string puerto)
{
    puerto = FromHarbour();
    
    if(puerto == "Goldhai Oeste")
        return ({
            "\nEl Capitán grita: Venga muchachos que nos vamos, izad las velas, soltad "
            "las amarras.. pongamos rumbo a @@Harbour@@.\n",
            "El Sothkorn abandona el muelle.\n"});

    if(puerto == "Glucksfall")
        return ({
            "\nEl Capitán grita: Alejemonos de este apestoso puerto, próxima parada "
            "@@Harbour@@, si no nos topamos con alguno de esos piratas. El Sothkorn "
            "parte del puerto en dirección a @@Harbour@@.\n",
            "El Sothkorn abandona el muelle.\n"});

    return ({
        "El Capitán grita: Acabamos de dejar @@FromHarbour@@ y nos dirigimos rumbo a "
        "@@Harbour@@!\n ",
        "El Sothkorn abandona el muelle.\n"});
}

int QueryShipCost() { return 20; }
