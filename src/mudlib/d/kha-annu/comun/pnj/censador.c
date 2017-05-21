/* PNJ del censo de Nandor
* [c] cheto
* [g] Gorthem para Kha-annu
* 15/10/98 Creacion   19/10/98 Gorthem Plagia por Orden de Chetin
* El nombre lo ha generado el genial asi que no me echeis la culpa!!!
* [Woo] Modificado
*/

#include "./path.h"
#include <properties.h>

inherit KBASE;

public create()
{
    ::create();
   SetStandard("Gorin","enano",5,GENDER_MALE);
    SetShort("El responsable del censo");
    SetLong(W("Gorin es un enano de complexión fuerte, pero que le falta la "
              "mano izquierda.\n"
              "Es sin duda un veterano de guerra.\n"));
    AddId("enano","gorin","enano","oficinista");
    Set(P_ALIGN,200);
    SetAC(1);
    InitChats(4,({"El oficinista habla consigo mismo sobre una batalla.\n",
                  "El oficinista hojea el libro de censos.\n",
                  "El oficinista se queja.\n",
                  "El oficinista dice: Hmmm, a este no lo he visto nunca.... "
                  "o ... ¿tal vez si?\n",
                  "El oficinista repasa el censo\n",
                  "El enano te pregunta: ¿quieres algo chato?\n",
                  "El enano dice: Hmm, este me ha dado mal sus datos,\n"
                  "acto seguido hace una bola y tira la ficha del censo "
                  "a un cubo.\n"}));

    AddQuestion(({"nombre"}), "El enano dice sin girarse: Me llamo Gorin.\n");
    AddQuestion(({"informacion","censo","información"}),
                W("El enano dice: para censarte escribe censar, y para "
                "consultar el censo, consultar, sin parámetros, pues sólo "
                "puede censarse o consultar uno mismo.\n"));
}
