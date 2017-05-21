/****************************************************************************
Fichero: mandoble.c
Autor: Ratwor
Fecha: 04/11/2007
Descripción: Un gran mandoble para el jefe ogro.
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <combat.h>

inherit "/std/weapon";

create()
{
    ::create();
    SetStandard(WT_ESPADA,13,P_SIZE_LARGE,M_ACERO);

    SetNumberHands(2);
    SetShort("un mandoble pesado");
    SetLong("Es un enorme mandoble con una hoja larga, gruesa y pesada, de  filos "
    "rectos desde la enorme empuñadura  de  hierro hasta la  punta triangular.   "
    "Está  mellada en algunas partes aunque pulida, y la empuñadura, sin adornos, "
    "está burdamente forrada con cordel desilachado para mejorar el agarre. \n "
    "Sólo alguien poseedor de gran fuerza y pericia podría hacer de este mandoble un "
    "arma útil, y aprovechar totalmente su peso y  contundencia.\n");
    AddId(({"mandoble", "mandoble pesado"}));
    Set(P_GENDER,GENERO_MASCULINO);
    Set(P_NUMBER,NUMERO_SINGULAR);
}
