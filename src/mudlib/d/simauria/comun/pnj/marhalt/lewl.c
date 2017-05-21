/****************************************************************************
Fichero: lewl.c
Autor: Ratwor
Fecha: 14/08/2007
Descripción: El responsable del censo totalmente arreglado.
****************************************************************************/

#include <properties.h>
inherit NPC;

create() {
    ::create();
   SetStandard("Lewl", "humano", 12, GENDER_MALE);
    SetShort("El responsable del censo");
    SetLong("Lewl es un hombre normal y corriente, como cualquier otro trabajador de la "
    "villa.\n");
    AddId(({"hombre","lewl", "oficinista", "funcionario", "Lewl", "responsable", "responsable del censo"}));
    Set(P_ALIGN,100);
    Set(P_NOGET,"No alcanzas a cogerlo.\n");
    InitChats(4,({"El oficinista silba una canción.\n",
    "El oficinista hojea el libro de censos.\n",
    "El oficinista se queja.\n",
    "El oficinista dice: 'Hmmm, a éste no lo he visto nunca...'\n",
    "El oficinista repasa el censo.\n",
    "Lewl te pregunta: '¿Necesitas algo?'\n",
    "Lewl dice: 'Vaya, éste me ha dado mal sus datos.'\n"
    "Y tira la ficha del censo a un cubo.\n"}));

    AddQuestion(({"informacion","censo","información"}),
        "Lewl dice: 'Para censarte escribe \"censar\", y para consultar "
        "el censo, \"consultar\".'\n");
}
