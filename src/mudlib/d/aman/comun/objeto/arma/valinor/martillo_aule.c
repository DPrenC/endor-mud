/****************************************************************************
Fichero: martillo_aule.c
Autor: Aule
Fecha: 01/03/2012
Descripci�n: el poderoso martillo con el que Aule trabaja sobre Arda, inventado por m�.
****************************************************************************/

#include <properties.h>
#include <combat.h>
inherit WEAPON;
create()
{
    ::create();
    SetStandard(WT_MAZA, 15, P_SIZE_LARGE, M_ESPECIAL);
    SetShort("El gran martillo de Aul�");
    SetLong("�ste es el legendario martillo de Aul�, el vala Herrero, un poderoso "
    "artefacto que ha sido utilizado por �l en multitud de fatigosos trabajos desde la "
    "creaci�n de Arda, incluyendo las cosas m�s bellas y maravillosas que ojos de "
    "mortales o Valar hayan visto jam�s.\n"
    "Sus m�ltiples poderes hacen tambi�n de este martillo una potente arma que su "
    "propietario ha esgrimido en las guerras que los Valar sostuvieron con Melkor en el "
    "pasado.\n"
    "El robusto mango de la longitud de un brazo est� tallado con complicadas filigranas "
    " y sostiene una enorme cabeza dorada de forma cil�ndrica por un lado y cuadrada "
    "por el otro con intrincados grabados que laten de forma intermitente debido al "
    "gran poder que alberga.\n");
    AddId(({"martillo", "mazo", "martillo_aule"}));
    AddAdjective(({"gran", "grande", "pesado", "poderoso"}));

    Set(P_GENDER, GENDER_MALE);
    SetWeight(10500);
    SetNumberHands(1);
  SetValue(3000000);

  SetMagic(1);
 SetNoDrop("Ser�a un sacrilegio tirar el martillo con el que Aul� di� forma a Arda.\n");
 Set(P_NOSELL,"No hay en toda Arda riquezas suficientes que puedan intercambiarse por "
 "este poderoso martillo.\n");
}