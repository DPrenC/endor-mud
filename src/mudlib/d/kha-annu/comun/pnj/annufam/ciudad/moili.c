/**************************************************************************
fichero: moili.c
Autor: Riberales
Creaci�n: 03/10/2005
Descripci�n: La mujer de Altriv, en la plaza.
**************************************************************************/

#include "path.h"
#include <properties.h>


inherit NPC;
string chats();

public void create()
{
    ::create();
    SetStandard("Moili","enano",15,GENDER_FEMALE);
    SetLong(W("Es una de las enanas que frecuentan la Plaza Belthain mientras "
              "su marido est� entrenando. Muestra una cara afable, y en la "
              "mano lleva una bolsa. No para de charlar con sus amigas de los "
              "escasos cotilleos de la ciudad.\n"));
    SetIds(({"moili_annufam","moili","amiga_posadera"}));

    InitChats(2,({W("Moili dice: Hum... no est� mal el entrenamiento de estos "
                    "enanos, pero yo les impondr�a mayor disciplina.\n"),
                  W("Moili dice: Mi marido me ha dicho que ha llegado un enano "
                "nuevo, y que es joven, apuesto y fuerte.\n")}));

}


