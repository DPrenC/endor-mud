/*****************************************************************************************
 ARCHIVO:       centauro.c
 AUTOR:         Ztico
 FECHA:         02-05-2005
 DESCRIPCIÓN:   Centauro del Bosque Central de Faeria.
 COMENTARIOS:   Ponerles lanza.
*****************************************************************************************/

#include "./path.h"
#include <combat.h>
#include <properties.h>
#include <gremios.h>

inherit NPC;

create()
{
    if(::create()) return 1;

    SetStandard("un centauro", "centauro", ([GC_GUERREROS: 50]), GENERO_MASCULINO);
    SetShort("un centauro");
    AddId("cent_faeria");
    SetLong("Ves a una elegante criatura que parece víctima de un encantamiento "
        "polimórfico. La parte superior de su cuerpo corresponde a un fornido humano de "
        "rasgos salvajes pero a la vez inteligentes, y de cintura para abajo, su cuerpo "
        "adopta la forma de un gran caballo percherón. \n");

    AddItem(WEAPON, REFRESH_REMOVE,
        ([
             P_WEAPON_TYPE: WT_ESPADA,
             P_SHORT: "una espada corta",
             P_LONG: "Es una espada corta de acero.\n",
             P_SIZE: P_SIZE_LARGE,
             P_MATERIAL: M_ACERO,
             P_WC: 10
         ]), SF(wieldme));

    AddItem("/obj/arco.c", REFRESH_REMOVE,
        ([
             P_SHORT: "un arco largo",
             P_LONG: "Es un arco largo de madera de tejo. El estrechamiento de las "
                 "palas no es lineal, sino en forma de látigo, lo que hace que se flecte "
                 "en forma de elipse y no en forma de arco.\n",
             P_WC: 5
         ]));
    AddItem("/obj/carcaj", REFRESH_REMOVE, 1);

}
/* esto es código antiguo, ahora se puede sustituir con lo de la herencia GUARD
public int QueryIsCentauro() { return 1; }

//Cuando un player empieza a atacar a un centauro, autománticamente el resto
//empiezan a atacarle.
public varargs int Defend(int dam, int dam_type, mixed flags, string *xtras)
{
    filter(all_inventory(environment()), 
           (: 
              $1->QueryIsCentauro() && member($2->QueryEnemies(), $1) < 0 ? 
              $1->AddEnemy($2) : 0; 
           :), TP || PO);
    return ::Defend(dam, dam_type, flags, &xtras);
}
*/