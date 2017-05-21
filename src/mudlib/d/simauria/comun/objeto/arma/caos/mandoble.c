/****************************************************************************
Fichero: mandoble.c
Autor: Ratwor
Fecha: 04/11/2007
Descripci�n: Un gran mandoble para el jefe ogro.
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
    "rectos desde la enorme empu�adura  de  hierro hasta la  punta triangular.   "
    "Est�  mellada en algunas partes aunque pulida, y la empu�adura, sin adornos, "
    "est� burdamente forrada con cordel desilachado para mejorar el agarre. \n "
    "S�lo alguien poseedor de gran fuerza y pericia podr�a hacer de este mandoble un "
    "arma �til, y aprovechar totalmente su peso y  contundencia.\n");
    AddId(({"mandoble", "mandoble pesado"}));
    Set(P_GENDER,GENERO_MASCULINO);
    Set(P_NUMBER,NUMERO_SINGULAR);
}
