/****************************************************************************
Fichero: soldado_posada.c
Autor: Kastwey
Creación: 24/08/2005
Descripción: El soldado que está...  ejem... en la habitación de la posada
con la enana...
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <guild.h>


inherit NPC;


string chat()
{
    object *enemigos = QueryEnemies();
    object enemigo = sizeof(enemigos) && enemigos[random(sizeof(enemigos))];
    string en_gender, mensaje;
    if (!enemigo) return "";
    en_gender = enemigo->QueryGender() == GENDER_FEMALE ? "a" : "o";
    switch(random(100))
    {
        case 0..49:
            mensaje = W("El soldado grita: 'Maldit" + en_gender + " " +
                        (enemigo->QueryGender() == GENDER_MALE ? "mirón" :
                        "mirona") + ". Te va a costar cara la indiscreción!'");
        break;

        default:
            mensaje = W("El soldado grita: '¡Así aprenderás, maldit" +
                        en_gender + " entrometid" + en_gender + "!'\n");
            break;
    }
    return mensaje;
}


public void create()
{
    if (::create()) return;

    SetStandard("un soldado","enano",([GC_LUCHADOR:80]),GENDER_MALE);
    AddId(({"soldado","soldado desnudo","soldado_en_el_lio"}));
    SetLong(W("Se trata de un enano del Centro de Adiestramiento, No "
              "parece que esté muy contento de verte. Va totalmente "
              "desnudo y en sus ojos ves la ira en su máximo "
              "esplendor.\n"));

    InitAChats(8,#'chat);
}
