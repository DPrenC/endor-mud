/****************************************************************************
Fichero: sable_corto.c
Autor: Ratwor
Fecha: 08/05/2010
Descripción: un sable corto 
****************************************************************************/

#include <properties.h>
#include <combat.h>

inherit WEAPON;

create(){
    ::create();
    SetStandard(WT_ESPADA, 7, P_SIZE_GENERIC, M_ACERO);
    SetShort("un sable corto");
    SetLong("Es una especie de machete de  hoja ancha, corta y gruesa.\n  Posee "
    "un sólo filo curvado que termina en una punta afilada por ambas partes y que "
    "se curva hacia arriba.\n El primer tercio del filo es aserrado y en el anverso "
    "de la hoja, dividiéndolo en tres, hay dos sobresalientes triangulares con "
    "la punta aguzada.\n La empuñadura está constituída por un mango forrado de "
    "la más fina piel de roorg, que con sus diminutas escamas impide el deslizamiento "
    "de la mano.\n Bajo el mango y desde el comienzo del filo al extremo de la "
    "empuñadura, hay una guarda de bronce semicircular trabajada con intrincados "
    "diseños que defiende los nudillos de los golpes enemigos.\n");

    SetWeight(1500);
    AddId(({"espada", "sable"}));
    AddAdjective("corto");
    
  }
  
