/****************************************************************************
Fichero: zorro.c
Autor: Riberales
Fecha: 28/02/2006
Descripci�n: Un zorro para el gremio de las Kisalas.
****************************************************************************/


#include "./path.h"
#include <properties.h>
#include <damage.h>

inherit DEPREDADOR;


private string DescLarga()
{
    string msg;
    if (!TP) return "";
    msg = "Se trata de un peque�o zorro de piel rojiza y una siniestra "
          "sonrisa en su boca. ";

    if (QueryEnemies() && member(QueryEnemies(),TP) >= 0)
    {
        return msg + "Mientras pelea, te clava sus fr�os ojillos con intensidad "
               "asesina.\n";
    }
    return msg + " No dudas de que en cualquier momento podr�a avalanzarse "
           "sobre ti.\n";
}

create()
{
    ::create();
    SetStandard("un zorro","zorro",9+random(3),GENDER_MALE);
    SetShort("un zorro");
    SetLong(SF(DescLarga));
    SetIds(({"zorro","peque�o zorro","pequenyo zorro"}));

    AddPrey(({"ardilla", "conejo"}));
    SetHands(({({"los dientes",DT_PIERCE,3})}));

    InitChats(2,({"El zorro olfatea a tu alrededor.\n"}));
}