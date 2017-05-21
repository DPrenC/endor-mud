/****************************************************************************
Fichero: entrada.c
Autor: Ratwor
Fecha: 28/12/2007
Descripción: La entrada del castillo.
****************************************************************************/

#include "./path.h"
#include <nightday.h>
inherit SCHEDULER_ROOM;
create(){
    ::create();
    SetIntShort("la entrada del castillo");
    SetIntLong("Te hallas bajo la arcada que forma la entrada del castillo de Nandor.\n"
    "Se trata de un corto pasaje abovedado que atraviesa la muralla de la fortaleza "
    "desembocando en el patio de armas al sur, y en el puente levadizo al norte.\n"
    "Contemplas los grandes sillares de piedra gris 	unidos apretadamente, los pesados "
    "batientes de la puerta justo al norte y el rastrillo de hierro actualmente "
    "levantado y que cierra la salida al patio de armas.\n");
    AddDetail(({"puerta", "puertas", "entrada"}), "Encajada  en el gran arco de la "
    "entrada, la puerta dividida en dos batientes está fabricada de gruesas vigas de "
    "roble reforzada por  bandas horizontales de hierro claveteado cubiertas de una "
    "respetable capa de óxido. Los goznes de acero corresponden su tamaño al de los "
    "batientes. Amplias abrazaderas colocadas en la parte interna de la puerta son "
    "usados para encajar trancas que mantienen los batientes cerrados desde dentro, "
    "aunque para ello son necesarios la fuerza de varios hombres.\n");
    AddDetail("rastrillo", "Una verja de hierro formada por barrotes verticales "
    "terminados en punta con tres travesaños horizontales que los conexionan: uno en "
    "la parte superior, otro en la media y otro en la inferiorr, justo antes de las "
    "puntas. El rastrillo se alza y se deja caer mediante una serie de poleas "
    "instaladas sobre la puerta. Resulta muy útil para cerrar el paso al enemigo sin "
    "perder la oportunidad de asaetearlo y hostigarlo por entre los barrotes, y debido  "
    "a su posición resguardada respecto a la puerta, resulta difícil de derribar "
    "con un ariete.\n");
    SetIntBright(30);
    AddExit("norte", "./puente");
    AddExit("sur", "./patio01");
    SetLocate("el castillo de Nandor");
    AddItem(PNJCASTILLO("centinela"), REFRESH_DESTRUCT);
    AddItem(PNJCASTILLO("centinela"), REFRESH_DESTRUCT);

    SetCloseTime(({ND_NIGHT, ND_PREDAWN}));
    SetLastDest("./puente");
    SetNotifyExits(({"sur", "norte"}));
    SetInformCloseMsg("Se oye una voz que grita desde lo alto del adarbe:\n La noche "
    "se aproxima, ¡venid y hechad una mano con el rastrillo, malditos holgazanes!\n");
    SetThrowOutMsg("Uno de los centinelas te hecha una hosca mirada y grita con "
    "exceso: ¡venga a dormir al foso!\n Media docena de hombres de armas con  rudos "
    "modales te empujan hacia el puente.\n");

    SetNotifyOpenMsg(({"El sonido de un cuerno saluda el amanecer y como respuesta "
      "varios hombres de armas se aproximan bostezando y desperezándose al mecanismo "
      "que alza el rastrillo.\n Otro grupo de hombres cruzan bajo el rastrillo  en "
      "movimiento y alzan las trancas que cierran las puertas y empujan los enormes "
      "batientes de roble tachonado hasta abrirlos de par en par.\n",
      "El sonido de un cuerno saluda el amanecer y como respuesta varios hombres "
      "de armas se aproximan bostezando y desperezándose al mecanismo que alza el "
      "rastrillo.\n Otro grupo de hombres cruzan bajo el rastrillo  en movimiento y "
      "alzan las trancas que cierran las puertas y empujan los enormes batientes "
      "de roble tachonado hasta abrirlos de par en par.\n"}));
    SetNotifyCloseMsg(({"En medio de un coro de gruñidos e imprecaciones el rastrillo "
      "comienza a bajar chirriando desagradablemente hasta que impacta contra el "
      "suelo con un estruendo metálico.\n Varios hombres de armas empujan los enormes "
      "batientes de roble de la puerta del castillo y dejan caer laspesadas trancas "
      "en sus abrazaderas dejando la fortaleza cerrada a cal y canto.\n",
    "En medio de un coro de gruñidos e imprecaciones el rastrillo comienza a bajar "
    "chirriando desagradablemente hasta que impacta contra el suelo con un estruendo "
    "metálico.\n Varios hombres de armas empujan los enormes batientes de roble "
    "de la puerta del castillo y dejan caer laspesadas trancas en sus abrazaderas "
    "dejando la fortaleza cerrada a cal y canto.\n"}));
    SetRoomClosedMsg("Las puertas cerradas y el rastrillo bajado bloquean el paso "
    "hasta el amanecer.\n");
    SetSchedulerID("centinela");
    SetNoSchedulerObject(0);

}


