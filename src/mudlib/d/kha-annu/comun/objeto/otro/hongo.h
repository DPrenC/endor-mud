
#include <properties.h>
#include <nightday.h>

#define HONGOCALLTIME 10
#define TJ environment(hongo)

public int HazApagado(object hongo) {
  int luz;

  luz = hongo->Query(P_LIGHT);
  
  if (luz > 0) {
     hongo->SetLight(luz - 1);
     switch(luz - 1) {
        case 40: tell_object(TJ, "Notas que el hongo en tu mano comienza " +
			     "a perder luminosidad.\n");
                 break;
        case 10: tell_object(TJ, "El hongo alumbra malamente la " +
			     "habitacion.\n");
		 break;
        }
     hongo->SetShort("un hongo luminoso: " + luz);
     call_out("HazApagado", HONGOCALLTIME, hongo);
     }
  else {
     tell_object(TJ, "El hongo que tenias en la mano se destruye!\n");
     if (hongo)
        destruct(hongo);
     }

  return 0;
}

/*----------------------------------------------------------------------------
** Description, Smell, Noise
*/

string QuerySmell() {
  return "No huele a nada que quisieras comer.\n";
}

string QueryNoise() {
  return "Al acercar mucho el oido, notas un debil latido\n";
}
