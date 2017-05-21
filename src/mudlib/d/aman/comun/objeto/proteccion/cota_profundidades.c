/*
Fichero: cota_profundidades.c
Autor: Aul�
Fecha: 21/07/2013
Descripci�n: la cota de malla de Ulmo, Se�or de las Aguas.
Inventada por m�, solo se la ve un poco en uno de los relatos de Tolkien.
*/

#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create()
{
    ::create();
    SetStandard(AT_CORAZA, 20, P_SIZE_LARGE, M_ESPECIAL);
    SetShort("la cota rutilante de las profundidades abisales");
    SetLong("Esta es la magn�fica cota de malla que Ulmo, vala Se�or de las Aguas viste "
    "como s�mbolo de su poder�o y majestad.\n"
    "Es una rutilante cota de diminutas escamas plateadas cinceladas de forma que "
    "imitan a la perfecci�n la piel de un poderoso pez marino, ajust�ndose prietamente "
    "al cuerpo de quien la porte.\n"
    "Un leve brillo plateado recubre toda su superficie y cuando recibe alguna luz, la "
    "refleja y devuelve como si estuviera salpicada de chispas doradas.\n"
    "Nadie sabe a ciencia cierta los poderes con que cuenta esta cota y ning�n mortal "
    "podr� saberlo ni vestirla jam�s, pues fue forjada en la noche de los tiempos para "
    "uno de los Se�ores de Arda.\n");
    SetIds(({"cota", "protecci�n", "proteccion","malla","armadura","cota_ulmo"}));
    SetAds(({"de","ulmo","las","profundidades"}));
            Set(P_GENDER, GENDER_FEMALE);
              //SetAPperQP(0);
                Set(P_NUMBER,NUMERO_SINGULAR);
    SetWeight(15324);
  SetValue(3000000);
  SetMagic(1);
 SetNoDrop("Ser�a un sacrilegio tirar un objeto sagrado como este.\n");
 Set(P_NOSELL,"No hay en toda Arda riquezas suficientes que puedan intercambiarse por "
 "esta poderosa cota.\n");
}