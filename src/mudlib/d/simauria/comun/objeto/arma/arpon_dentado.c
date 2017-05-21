/****************************************************************************
Fichero: arpon_dentado.c
Autor: Ratwor
Fecha: 08/05/2010
Descripción: un arpón dentado con distintas descripciones.
****************************************************************************/


#include <properties.h>
#include <combat.h>
inherit WEAPON;

create()
{
    ::create();
    SetStandard(WT_LANZA, 6, P_SIZE_MEDIUM, M_HIERRO);
    SetShort("un arpón dentado");
    switch(d3()){
        case 1:
          SetLong("Es un arpón de mango corto y grueso rematado por una hoja ancha "
          "de forma triangular con el filo provisto de dientes que apuntan hacia "
          "el mango con el objeto de agravar las heridas del objetivo al extraer el "
          "arma.\n");
        break;
    case 2:
        SetLong("Es un arpón constituido por un grueso mango de madera que se estrecha "
        "en los extremos encajado en una punta con cuatro filos dispuestos en forma "
        "de X.\n Los extremos posteriores de los cuatro filos del arma se alargan "
        "hacia el mango proporcionando mayor superficie de corte y haciendo que "
        "la extracción del arma agrande la herida causada en el objetivo.\n");
        break;
    case 3:
        SetLong("Se trata de un arpón de mango grueso y pesado para proporcionarle "
        "más potencia al ser arrojado.\n Está rematado por una larga hoja triangular "
        "dotada de filos dentados que provocan aparatosos desgarrones en la carne "
        "de la víctima.\n");
        break;
    }
    SetLong(QueryLong()+"Estas armas provienen de los arpones de pesca que las "
    "tribus de los Verati utilizaban antaño en la caza de los roorgs, grandes peces "
    "carnívoros que aún sobreviven en los diversos canales del delta del río Raxal.\n"
    "Tras la fundación del puerto de Verat por los sobrevivientes de los Verati, "
    "ayudados por los ishtrios, estos arpones fueron adaptados al combate aunque aún "
    "se siguen utilizando como utensilio de pesca.\n");


    AddId(({"arpon", "arpón", "arpón dentado"}));
    Set(P_GENDER, GENDER_MALE);
    SetWeight(2750);
    SetNumberHands(1);
}

