// Comando zap para matar livings

#include <properties.h> // Sino el search.h peta, habra q arreglarlo.
#include <search.h> // Para el WSearchInvEnv
#include <wizlevels.h> // Para el IS_LEARNER
#include <sounds.h>
public int main(string str) {
  object ob, hab, *objs;
  string name;
  int    i;

  if (!TP) return 0;
  if (!str) return notify_fail("Uso: zap <nombre_objeto>\n");

  ob = TP->Search(lower_case(str), SEARCH_INV_ENV|SM_OBJECT|WizSearch());
  if (!ob) return notify_fail("No se encontró el objeto: " + str + ".\n");

  say(capitalize(TP->QueryName())+" alza su mano e invoca la ira de los cielos.\n");
  write("Alzas tu mano e invocas la ira de los cielos.\n");

  if (IS_LEARNER(ob) && ISPLAYER(ob)) {
    say("Los cielos no responden a tu mandato.\n");
    write("Los cielos no responden a tu mandato.\n");
    tell_object(ob, capitalize(TP->QueryName())+" ha intentado invocar la ira de los cielos sobre ti.\n");
    return notify_fail("No pudes desencadenar la ira de los cielos sobre otro vala.\n");
  }

  hab = environment( ob );

  if (living(ob) && (ob && hab == environment(TP))) {
    say("Los cielos estallan en cólera y un titánico rayo se abate desde lo alto.\n");
    play_sound(environment(TP), SND_SUCESOS("zap"));
    write("Los cielos estallan en cólera y un titánico rayo se abate desde lo alto.\n");
    name = "el cadáver de " + ob->QueryName();
    ob->SetHP(-100); //para q no recupere la consciencia...
    ob->Die();
    ob = 0;

    for ( i=sizeof(objs=all_inventory(hab)); i-- ; ) {
        if ( objs[i]->QueryShort() == name ) {
            ob = objs[i];
            break;
        }
    }

    if ( ob ) {
       ob->SetShort("unos restos calcinados y humeantes");
       ob->AddId("restos");
       ob->SetLong("Unos pocos restos de lo que antes fué algo y que ahora no es nada.\n");
       ob->SetSmell( "De los restos se desprende un desagradable olor a carne quemada.\n");
       ob->SetDecayTime(1);
       ob->SetDecay(-1);
    }
  }
  else
  {
   say("El rayo se desvanece en el aire antes de llegar al suelo.\n");
   write("El rayo se desvanece en el aire antes de llegar al suelo.\n");
  }
  return 1;
}