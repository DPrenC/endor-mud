/****************************************************************************
Fichero: manto_montaraz.c
Autor: Aulë
Fecha: 19/03/2013
Descripción: una capa para montaraces
****************************************************************************/

#include <properties.h>
#include <combat.h>

inherit ARMOUR;

create(){
    ::create();
    SetStandard(AT_MANTO, 2, P_SIZE_LARGE, M_TELA);
    SetShort("un pesado manto verde oliva");
    SetLong("Es un manto grueso y pesado, gastado por el tiempo y la intemperie.\n"
    "Es de un desvaído color verde oliva para confundirse con el terreno y su grosor y "
    "resistencia confieren un buen reparo contra el frío de las tierras salvajes.\n"
    "Estas prendas son usadas por los Montaraces del Norte, tejidas por sus nobles "
    "mujeres y utilizados en sus largos vagabundeos   por Eriador.\n");
    SetIds(({"manto", "capa"}));
    AddAdjective(({"verde", "verde oliva"}));
    SetWeight(765);
    Set(P_GENDER, GENDER_MALE);

}
