/*****************************************************************************************
 ARCHIVO:       gyrto-centauro.c
 AUTOR:         Ztico
 FECHA:         02-05-2005
 DESCRIPCIÓN:   Centauro del Bosque Central de Faeria.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"
#include <gremios.h>
#include <combat.h>
#include <properties.h>

inherit NPC;

create()
{
    if(::create()) return 1;

    SetStandard("gyrto", "centauro", ([GC_GUARDABOSQUE: 85]), GENERO_MASCULINO);
    SetShort("gyrto el Bárbaro");
    SetLong("Esta poderosa criatura es un centauro, un ser cuyo cuerpo posee dos mitades "
        "diferentes: la mitad inferior tiene la forma de un gran caballo de batalla, y "
        "la parte superior es la de un humano fuerte y musculoso. Su largo pelo se "
        "desliza por su espalda como una crin. El color de su mitad equina es una mezcla "
        "de rubio y moteado, el de su cabello es oscuro como la miel añeja, y su piel es "
        "de un moreno intenso. Tiene los ojos grandes, expresivos, y de un profundo "
        "color violeta. Lleva el cuerpo completamente decorado con infinidad de tatuajes "
        "de diversas tinturas vegetales, y su aspecto majestuoso se ve ampliado gracias "
        "a las joyas, flores y amuletos que lo adornan.\n");
    AddId(({"bárbaro", "barbaro", "centauro", "cent_faeria"}));

    //Me gustaría añadirle más ids pero no se la propiedad que hay que usar: P_EXTRALOOK?
    AddItem(WEAPON, REFRESH_REMOVE,
        ([
             P_WEAPON_TYPE: WT_ESPADA,
             P_SHORT: ("una espada corta"),
             P_LONG: "Es una espada corta de acero.\n",
             P_SIZE: P_SIZE_LARGE,
             P_MATERIAL: M_ACERO,
             P_WC: 5
         ]), SF(wieldme));

    //No sé si empuñarle también el arco, me parece excesivo.

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

public int QueryIsCentauro() { return 1; }

//Cuando un player empieza a atacar a un centauro, autománticamente el resto
//empiezan a atacarle.
public varargs int Defend(int dam, int dam_type, mixed flags, string *xtras)
{
    filter(all_inventory(environment()), 
           (: 
           	  $1->QueryIsCentauro() && member($2->QueryEnemies(), $1) < 0 ? 
           	  $1->AddEnemy($2) : 0 
           :), TP || PO);
    return ::Defend(dam, dam_type, flags, &xtras);
}
