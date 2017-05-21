// Por Izet@Simauria, 20/03/2000
// Fichero: katnegra.c
// Descripcion:
//     Arma del gremio de asesinos. Se le concederá la habilidad
//     sólo a los privilegiados que alcancen nivel 30 dentro del
//     gremio. El arma en sí no debería de ser de tipo esgrima,
//     pero me pareció apropiado dado que para saber manejar una
//     katana con eficacia son necesarios varios años de entrena-
//     miento en 'kendo', considerado un arte marcial de esgrima
//     japonés.
// Modificado:
//       [Nemesis] 17-Oct-2001 ¿Por qué razón son mágicas?

#include <combat.h>
#include <properties.h>
#include "path.h"
#define CHANCE 15

inherit "/guilds/asesinos/std/weapon";

object arma;

void create() {
   ::create();
   SetStandard(WT_ESGRIMA,7,P_SIZE_MEDIUM,M_ACERO);
   SetIds( ({"katana","katana negra"}) );
   SetAds( ({"una","la"}) );
   SetShort("una katana negra");
   SetLong(W("Una katana larga y de color negro. Su filo parece\n"
           "realmente afilado. La empuñadura está recubierta por\n"
          "hilos de cañamo rojos y negros.\n"));
   Set(P_GENDER,GENDER_FEMALE);
   SetPoisoned(0);
}
