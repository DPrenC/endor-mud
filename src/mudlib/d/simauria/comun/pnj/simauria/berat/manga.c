/*
DESCRIPCION : Kiloxa
FICHERO     : /d/simauria/comun/pnj/simauria/berat/manga.c
MODIFICACION: 4-11-99 [Jorus]
              30/05/00 Mirill@Simauria
			  2-6-00 Maler cambiado /std/npc por NPC.corregidas faltas
--------------------------------------------------------------------------------
*/
#include "./path.h"
#include <properties.h>
inherit NPC;

create() {
    ::create();

    SetStandard("Kiloxa","humano",10,GENDER_MALE);
    SetShort("el borracho Kiloxa");
    SetLong("Kiloxa es un humano totalmente ebrio que pulula por los muelles de Berat. "
    "Si esperas un poco quizás te deleite con alguna de sus canciones.\n");

    SetGoChance(10);
    SetMsgIn("viene tambaleándose");
    SetMsgOut("se va tambaleándose");
    SetAlign(-200);
    AddWalkZones(SIMA("berat/muelle"));
    SetCitizenship("berat");
    AddId(({"Kiloxa","kiloxa","borracho","humano"}));
    SetAlcohol(100);
    InitChats(6,({
    "Kiloxa eructa.\n",
    "Kiloxa pierde el equilibrio peligrosamente cerca del borde, pero justo en el "
    "último momento lo recupera con una felina maniobra digna de todo un guerrero.\n",
    "Kiloxa canta: Tres piratas sobre el cofre del muerto ron ron ron\n"
    "la botella de ron.\n" ,
    "Kiloxa para un momento, te observa y dice: '¿Y tú que  miras?'\n",
    "Kiloxa canta: Navegar sin temor por el mar es lo mejor, no hay razón para "
    "echarse a temblar....\n",
  }) );
}

