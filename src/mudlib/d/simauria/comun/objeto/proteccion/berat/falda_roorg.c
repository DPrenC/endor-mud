/****************************************************************************
Fichero: falda_roorg.c
Autor: Ratwor
Fecha: 29/06/2010
Descripción: una falda de piel de roorg para las ciudadanas de Berat
****************************************************************************/

#include <properties.h>
#include <combat.h>

inherit ARMOUR;

create(){
    ::create();
    SetStandard(AT_TROUSERS, 1, P_SIZE_LARGE, M_TELA);
    SetShort("una falda de piel de roorg");
    SetLong("Es una falda de corte sencillo que cubre hasta las rodillas.\n Está "
    "confeccionada en elástica piel escamosa de roorg, un gran pez carnívoro del "
    "delta del Raxal, cuya piel es muy utilizada en la confección de todo tipo de "
    "vestimentas por las gentes de Verat.\n");
    SetIds(({"falda", "ropa"}));
    AddAdjective(({"de", "piel", "roorg"}));
    SetWeight(400);
    Set(P_NUMBER, NUMBER_SINGULAR); 
    Set(P_GENDER, GENDER_FEMALE);
  }
  