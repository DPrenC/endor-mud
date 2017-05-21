/****************************************************************************
Fichero: martillo_melkor.c
Autor: Aule
Fecha: 01/03/2012
Descripci�n: Grond el martillo con el que Morgoth mat� a Fingolfin.
****************************************************************************/

#include <properties.h>
#include <combat.h>
inherit WEAPON;
create()
{
    ::create();
    SetStandard(WT_MAZA, 15, P_SIZE_LARGE, M_ESPECIAL);
    SetShort("Grond, el martillo de los mundos subterr�neos");
    SetLong(
"Este es Grond, el pesado martillo de los mundos subterr�neos, la poderosa arma "
"esgrimida por Melkor Morgoth en los D�as Antiguos y con el que se enfrent� a "
"Fingolfin, Alto Rey de los Noldor en la Tierra Media.\n"
"Es un enorme martillo de grueso mango de la altura de un hombre sobre cuyo negro hierro "
"hay talladas multitud de inscripciones malignas en una antigua lengua perdida.\n"
"Una gruesa bola terminada en punta finaliza el mango que por el otro lado est� rematado "
"por una gran cabeza cil�ndrica coronada por gruesas y afiladas cuchillas que se "
"inclinan hacia dentro.\n"
"Un fulgor rojizo mortecino envuelve toda el arma y late como la luz de las forjas de "
"los antiguos infiernos de Utumno.\n\n");
    AddId(({"martillo", "mazo", "grond", "martillo_melkor"}));
    AddAdjective(({"gran", "grande", "pesado", "poderoso", "negro", "oscuro"}));

    Set(P_GENDER, GENDER_MALE);
    SetWeight(15500);
    SetNumberHands(1);
  SetValue(3000000);

  SetMagic(1);
 Set(P_NOSELL,"Nadie se atrever�a a ofrecerte dinero por este oscuro martillo.\n");
}