/*
Fichero: armadura_melkor.c
Autor: Aulë
Fecha: 21/07/2013
Descripción: armadura de Morgoth.
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
    "Esta enorme y pesada armadura está fabricadacon el durísimo hierro negro de las "
    "forjas de Angband y fue creada por Morgoth para las guerras de los DíasAntiguos.\n"
    "Los Balrogs ayudaron en su confección y unas pequeñas llamas parecen danzar sobre "
    "sus placas y anillos. Mediante el poder de su creador y sus criaturas, esta "
    "pesada armadura exuda un halo de lobreguez y desesperación que afecta a quienes se "
    "encuentran a corta distancia, además de inundarlos del más atávico terror a la "
    "Oscuridad. Está constituida por una pesada malla reforzada con placas pectorales, "
    "hombreras con una hilera de púas sobresalientes y un largo faldón de malla "
    "tachonada que cae hasta el suelo. Sin duda un atavío de guerra digno de Melkor "
    "Morgoth, Señor de Angband\n");
    SetIds(({"cota", "armadura", "protección", "proteccion","malla", "armadura_melkor"}));
    SetAds(({"de","melkor","negra"}));
            Set(P_GENDER, GENDER_FEMALE);
              //SetAPperQP(0);
                Set(P_NUMBER,NUMERO_SINGULAR);
    SetWeight(20500);
  SetValue(3000000);
  SetMagic(1);
 Set(P_NOSELL,"Nadie compraría la armadura del Enemigo Oscuro.\n");
}