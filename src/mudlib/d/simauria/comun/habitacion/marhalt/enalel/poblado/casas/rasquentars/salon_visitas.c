/*****************************************************************************
 AUTOR:		[t] Tyflos
 DETALLES:	Poblado Enanel
 *****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;

create() {
    ::create();

    SetIntBright(30);
    SetLocate("Poblado de Enalel");
    SetIntShort("el sal�n de visitas");
    SetIntLong("Est�s en un enorme pero acogedor sal�n dedicado a los invitados "
    "de la familia Rasquentar. Unos c�modos y bellos sillones junto con una delicada "
    "mesa forman el mobiliario del sal�n. Al este y al oeste se encuentran los "
    "dormitorios de la familia y al sur est� la puerta que da al comedor.\n");
    SetIntSmell("Un leve aroma a manzanas se percibe por todas partes.\n");
    AddDetail(({"sill�n","sillon","sofa","sof�","sof�s","sofas"}),"Son unos "
    "c�modos y elegantes sof�s de tonos oscuros.\n");
    AddExit("este",ENALHAB"poblado/casas/rasquentars/dormitorio_este");
    AddExit("oeste",ENALHAB"poblado/casas/rasquentars/dormitorio_oeste");
    AddExit("sur",ENALHAB"poblado/casas/rasquentars/comedor");
    AddDoor("este", "la puerta de un dormitorio",
    "Es una puerta normal para entrar en uno de los dormitorios.\n",
    ({"puerta", "puerta del este", "puerta del dormitorio del este"}));
    AddDoor("oeste", "la puerta de un dormitorio",
    "Es una puerta normal para entrar en uno de los dormitorios.\n",
    ({"puerta", "puerta del oeste", "puerta del dormitorio del oeste"}));
}
