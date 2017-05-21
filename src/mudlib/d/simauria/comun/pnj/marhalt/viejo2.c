        /****************************************************************************
        Fichero: viejo2.c
        Autor: Ratwor
        Fecha: 14/08/2007
        Descripci�n: Roalf totalmente arreglado.
        ****************************************************************************/

#include "./path.h"
#include <properties.h>

inherit NPC;

create() {
    ::create();
    SetStandard("Roalf", "humano", 11, GENDER_MALE);
    SetShort("Roalf");
    SetLong("Es un anciano de cara flaca, con barba de tres d�as y cara de paleto. "
    "A pesar de todo, inspira ternura y tiene presencia de gran experiencia "
    "que debe tener de la vida. Quiz� le puedas preguntar algo sobre la villa.\n");
    AddId(({"roalf","anciano", "viejo"}));
    AddQuestion(({"nandor", "Nandor", "villa"}),
        "Roalf dice: 'En un principio vivieron aqu� elfos, pero despu�s se fueron a "
        "su bosques y nuestros antepasados la ocuparon devolvi�ndola a la vida.'\n");
    AddQuestion("elfos",
        "Roalf dice: 'Son criaturas de los bosques. Se creen superiores a nosotros "
        "porque dominan la magia, pero si les sacas de ah� son bastante mediocres. "
        "Adem�s son muy orgullosos y, si no fuera por los orcos, les habr�amos dado "
        "un escarmiento hace tiempo.'\n");
    AddQuestion("orcos",
        "Roalf dice: 'Las razas de la luz estamos en guerra con ellos desde hace mucho. "
        "De vez en cuando hacen incursiones, pero no te preocupes, eso es por el sur, "
        "aqu� estamos a salvo de esas bestias.'\n");
    AddQuestion(({"primo", "primo rombrat", "primo Rombrat", "rombrat", "Rombrat"}),
        "Roalf te dice: ummm mi primo Rombrat s�, hace a�os que se fu� a vivir "
        "al poblado de Enalel, parece que all� se vive bien.\n",1);
    InitChats(2,({
        "Roalf dice: 'Espero que este a�o no nieve tanto como el pasado.'\n",
        "Roalf dice: mi primo Rombrat me comenta que a menudo suelen merodear ogros "
        "por los campos de manzanos.\n",
        "Roalf dice: '�ltimamente parece que Nandor tiene mucha afluencia de viajeros.'\n",
        "Roalf dice: 'Dicen que va a haber otra guerra. Ojal� pudiera ir, "
        "pero ya no soy joven...'\n"}));
    InitAChats(10,({
    "Roalf gru�e: '�Qu� juventud! �En mis tiempos te ibas a enterar! �Gamberro!'\n"}));
    SetCitizenship("nandor");
}
