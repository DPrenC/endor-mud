/* PNJ conserje del ayuntamiento de Nandor
 * [c] cheto
 *
 * 10-10-2001 Creacion
 *
 * [n] Castellanizado. (Oct'02)
 */

#include <properties.h>
inherit NPC;
create() {
    ::create();
    SetStandard("un funcionario", "humano", 9+d3(), GENDER_MALE);
    SetLong("El funcionario es un humano de complexi�n normal, pero con cara de "
    "aburrido y amargado.\n");
    AddId(({"hombre", "funcionario"}));
    SetCitizenship("gorat");
    Set(P_NOGET,"No alcanzas a cogerlo.\n");
    InitChats(4,({"El funcionario silba una canci�n.\n",
    "El funcionario te pregunta: '�Quieres algo?'\n"}));

    AddQuestion(({"informaci�n","informacion"}),
    "El hombre dice: 'Aqu� puedes cu�ar el impreso para obtener el JK23-H.'\n");
    AddQuestion(({"cu�ar","cunyar","ayuda"}),
    "El funcionario te dice cansinamente: 'Para cu�ar el impreso escribe 'cu�ar'.\n");
}
