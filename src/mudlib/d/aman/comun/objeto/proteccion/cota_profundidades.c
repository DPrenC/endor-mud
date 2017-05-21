/*
Fichero: cota_profundidades.c
Autor: Aulë
Fecha: 21/07/2013
Descripción: la cota de malla de Ulmo, Señor de las Aguas.
Inventada por mí, solo se la ve un poco en uno de los relatos de Tolkien.
*/

#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create()
{
    ::create();
    SetStandard(AT_CORAZA, 20, P_SIZE_LARGE, M_ESPECIAL);
    SetShort("la cota rutilante de las profundidades abisales");
    SetLong("Esta es la magnífica cota de malla que Ulmo, vala Señor de las Aguas viste "
    "como símbolo de su poderío y majestad.\n"
    "Es una rutilante cota de diminutas escamas plateadas cinceladas de forma que "
    "imitan a la perfección la piel de un poderoso pez marino, ajustándose prietamente "
    "al cuerpo de quien la porte.\n"
    "Un leve brillo plateado recubre toda su superficie y cuando recibe alguna luz, la "
    "refleja y devuelve como si estuviera salpicada de chispas doradas.\n"
    "Nadie sabe a ciencia cierta los poderes con que cuenta esta cota y ningún mortal "
    "podrá saberlo ni vestirla jamás, pues fue forjada en la noche de los tiempos para "
    "uno de los Señores de Arda.\n");
    SetIds(({"cota", "protección", "proteccion","malla","armadura","cota_ulmo"}));
    SetAds(({"de","ulmo","las","profundidades"}));
            Set(P_GENDER, GENDER_FEMALE);
              //SetAPperQP(0);
                Set(P_NUMBER,NUMERO_SINGULAR);
    SetWeight(15324);
  SetValue(3000000);
  SetMagic(1);
 SetNoDrop("Sería un sacrilegio tirar un objeto sagrado como este.\n");
 Set(P_NOSELL,"No hay en toda Arda riquezas suficientes que puedan intercambiarse por "
 "esta poderosa cota.\n");
}