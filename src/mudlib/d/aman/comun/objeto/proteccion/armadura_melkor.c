/*
Fichero: armadura_melkor.c
Autor: Aul�
Fecha: 21/07/2013
Descripci�n: armadura de Morgoth.
*/

#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create()
{
    ::create();
    SetStandard(AT_CORAZA, 20, P_SIZE_LARGE, M_ESPECIAL);
    SetShort("la armadura negra de Angband");
    SetLong(
    "Esta enorme y pesada armadura est� fabricadacon el dur�simo hierro negro de las "
    "forjas de Angband y fue creada por Morgoth para las guerras de los D�asAntiguos.\n"
    "Los Balrogs ayudaron en su confecci�n y unas peque�as llamas parecen danzar sobre "
    "sus placas y anillos. Mediante el poder de su creador y sus criaturas, esta "
    "pesada armadura exuda un halo de lobreguez y desesperaci�n que afecta a quienes se "
    "encuentran a corta distancia, adem�s de inundarlos del m�s at�vico terror a la "
    "Oscuridad. Est� constituida por una pesada malla reforzada con placas pectorales, "
    "hombreras con una hilera de p�as sobresalientes y un largo fald�n de malla "
    "tachonada que cae hasta el suelo. Sin duda un atav�o de guerra digno de Melkor "
    "Morgoth, Se�or de Angband\n");
    SetIds(({"cota", "armadura", "protecci�n", "proteccion","malla", "armadura_melkor"}));
    SetAds(({"de","melkor","negra"}));
            Set(P_GENDER, GENDER_FEMALE);
              //SetAPperQP(0);
                Set(P_NUMBER,NUMERO_SINGULAR);
    SetWeight(20500);
  SetValue(3000000);
  SetMagic(1);
 Set(P_NOSELL,"Nadie comprar�a la armadura del Enemigo Oscuro.\n");
}