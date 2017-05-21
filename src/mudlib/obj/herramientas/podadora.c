/* Fichero: podadora.c 
Autor: Aulë
Fecha: 13/09/2014
Descripción: grandes tijeras genéricas para cortar el cesped y recortar setos.*/
#include <combat.h>
#include <properties.h>

inherit WEAPON;

create()
{
 ::create();
 SetStandard(WT_IMPROVISADA,2,P_SIZE_LARGE,M_HIERRO);
 SetShort("unas tijeras de podar");
AddAdjective(({"de", "hierro"}));
 AddId(({"tijeras", "podadora", "tijeras de podar",  "herramienta"}));
    SetLong(
    "Son unas enormes tijeras con mangos de madera y dos hojas largas y anchas.\n"
    "Se usan para recortar el césped y los setos de los jardines y parcelas más cuidadas.\n");
        SetWeight(1000);
        Set(P_NUMBER, NUMERO_PLURAL);
        Set(P_GENDER,GENERO_FEMENINO);
        
        
}