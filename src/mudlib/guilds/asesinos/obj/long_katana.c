// Por Izet@Simauria, 20/03/2000
// Fichero: long_katana.c
// Descripcion:
//     Arma del gremio de asesinos. Se le conceder� la habilidad
//     s�lo a los privilegiados que alcancen nivel 30 dentro del
//     gremio. El arma en s� no deber�a de ser de tipo esgrima,
//     pero me pareci� apropiado dado que para saber manejar una
//     katana con eficacia son necesarios varios a�os de entrena-
//     miento en 'kendo', considerado un arte marcial de esgrima
//     japon�s.
//       [Nemesis] 17-Oct-2001 �Por qu� raz�n son m�gicas?

#include <combat.h>
#include <properties.h>
#include "path.h"

#define CHANCE 15

inherit "/guilds/asesinos/std/weapon";


void create() {
   ::create();
   SetStandard(WT_ESGRIMA,10,P_SIZE_MEDIUM,M_ACERO);
   SetIds( ({"katana","katana larga"}) );
   SetAds( ({"una","la"}) );
   SetShort("una katana larga");
   SetLong(W("Esta katana es m�s larga que las katanas normales, y "
              "en combate es necesario su manejo a dos manos para "
              "alcanzar un mejor equilibro. Su filo parece muy afilado, "
              "y tiene un brillo plateado. El mango esta recubierto con "
              "hilos de ca�amo rojos y negros.\n"));
   SetNumberHands(2);
   Set(P_GENDER,GENDER_FEMALE);
   SetPoisoned(0);
}
