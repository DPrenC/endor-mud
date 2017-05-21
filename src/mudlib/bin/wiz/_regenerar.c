#include <sounds.h>

int regenerar(string quien) {
  string str;
  object ob;

  if (!quien || sscanf(quien,"a %s", str) != 1 ) {
    return notify_fail("Uso: regenerar a <jugador>\n");
  }
  ob = find_object(lower_case(str));
  if (!ob) {
    write(capitalize(str)+" no vaga por Endor en este momento.\n");
    return 1;
  }
  write("Honras a "+capitalize(ob->QueryRealName())+" con el toque de tu mano e invocas tu poder sobre su cuerpo, poniendo fin a todos sus males.\n");
  tell_object(ob, "Un bienestar pleno se apodera de tu cuerpo, jamás te habías sentido tan bien.\n"+
                  TP->QueryRealName()+" te honra con el divino toque de su mano y pone fin a todos tus males.\n");
                      play_sound(environment(TP), SOUND_AINU("regenerar"));

  ob->SetTP(ob->QueryMaxTP());
  ob->SetHP(ob->QueryMaxHP());
  ob->SetSP(ob->QueryMaxSP());
  ob->SetDrink(ob->QueryMaxDrink());
  ob->SetFood(ob->QueryMaxFood());
  ob->SetAlcohol(0);

  return 1;
}
