/* Habilidad de cocinar alimentos/cadáveres
   Theuzifan, 11-03-99
   06-06-00 [t] Cambio el stuff y el heal que da, añado soak y la dificultad
   		es la hablidad/2-peso del bicho/1000
   28-06-00 [t] Arreglo un fallo. Antes de destruir el objeto cojo el short
   		y lo muestro al final...
*/
#include <properties.h>

#define NTF(x) notify_fail(x)
#define AoO(x) (x->Query(P_GENDER)==GENDER_FEMALE?"a":"o")


private int do_cook(object ob, int deg)
{
  object ob2;
  string rc,obshort;

  seteuid(getuid());

  switch (deg) {
    case -100..-80: ob2=clone_object("/std/thing");
    		    ob2->SetShort("Un montoncito de carne calcinada");
    		    ob2->SetLong("Ves un montón de cenizas de algo que alguien intentó torpemente cocinar.\n");
    		    ob2->SetIds(({"cenizas", "ceniza", "monton de cenizas", "montón de cenizas",
    		    		"monton de ceniza", "montón de ceniza"}));
    		    ob2->SetWeight(100);
    		    ob2->SetNoGet("Intentas coger un montón de cenizas pero se te caen por entre los dedos.\n");
    		    ob2->Set(P_COOKED, 1);
    		    ob2->move(environment(ob));
    		    obshort=ob->QueryShort();
    		    ob->remove();
    		    return NTF("Calcinas totalmente "+obshort+"...\n");

    case -79..-50: rc="Chamuscas "+ob->QueryShort()+"...\n";
      		   ob->SetFood(0);
    		   ob->SetDrink(0);
                   ob->SetShort(ob->QueryShort()+" chamuscad"+AoO(ob));
    		   ob->SetLong(ob->QueryLong()+"Está totalmente chamuscad"+AoO(ob)+".\n");
                   ob->Set(P_COOKED, 1);
                   return NTF(rc);
    case -49..0: rc="Intentas cocinar "+ob->QueryShort()+" pero lo máximo "
    			"que consigues es\nestropearl"+AoO(ob)+".\n";
    		 ob->SetFood(0);
    		 ob->SetDrink(0);
    		 ob->SetShort(ob->QueryShort()+" mal cocinad"+AoO(ob));
    		 ob->SetLong(ob->QueryLong()+"Alguien l"+AoO(ob)+" ha intentado cocinar, estropeando lo que podría haber\nsido comida.\n");
                 ob->Set(P_COOKED, 1);
                 return NTF(rc);
    case 1..89: write("Cocinas "+ob->QueryShort()+".\n");
    		break;
    case 90..100: write("Cocinas "+ob->QueryShort()+
    		" de una manera que tan sólo los chefs podrían hacer.\n");
    		break;
    default: return NTF("Fallas al cocinar a "+ob->QueryShort()+" ("+deg+").\n");
  }
  return 1;
}


int cook_food(object ob)
{
  int deg;
  object b;

  if (!ob->QueryFood()) return NTF("No puedes cocinar "+ob->QueryShort()+".\n");
  if (!b=present("bolsa de cocinero", TP))
    return NTF("No tienes las herramientas de cocina necesarias para cocinar.\n");
  if (ob->Query(P_COOKED))
    return NTF(capitalize(ob->QueryShort())+" ya está cocinad"+AoO(ob)+".\n");

// más dificil cuanto más grande...
  deg=TP->UseSkill("cocinar",
  	(TP->QuerySkillLevel("cocinar")/2)-(ob->QueryWeight()/1000));

  b->Set(P_AUX1, b->Query(P_AUX1)-1);
  if (b->Query(P_AUX1)<1)
  {
    write("Has gastado tu bolsa de cocinero.\n");
    b->remove();
  }
  if (!do_cook(ob, deg)) return 0;

  ob->Set(P_COOKED, 1);
  ob->SetFoodStuff(ob->QueryFoodStuff()+ob->QueryFoodStuff()*deg/30);
  ob->SetFoodHeal(ob->QueryFoodHeal()+ob->QueryFoodHeal()*deg/30);
  ob->SetFoodAlc(ob->QueryFoodAlc()-ob->QueryFoodAlc()*deg/30);
  ob->SetFoodSoak(ob->QueryFoodSoak()+ob->QueryFoodSoak()*deg/30);
  ob->SetSmell("Huele a comida bien cocinada.\n");
  ob->SetShort(ob->QueryShort()+" cocinad"+AoO(ob));
  ob->SetLong(ob->QueryLong()+"Está cocinad"+AoO(ob)+".\n");

  return 1;
}

int cook_corpse(object ob)
{
  int deg, stuff;
  object ob2, b;

  seteuid(getuid());
  if (!b=present("bolsa de cocinero", TP))
    return NTF("No tienes las herramientas de cocina necesarias para cocinar.\n");
  if (ob->Query(P_COOKED))
    return NTF(capitalize(ob->QueryShort())+" ya está cocinad"+AoO(ob)+".\n");

  deg=TP->UseSkill("cocinar");
  b->Set(P_AUX1, b->Query(P_AUX1)-1);
  if (b->Query(P_AUX1)<1)
  {
    write("Has gastado tu bolsa de cocinero.\n");
    b->remove();
  }

  if (!do_cook(ob, deg)) return 0;

  ob2=clone_object("/std/food");
  ob2->SetShort(ob->QueryShort()+" cocinad"+AoO(ob));
  ob2->SetLong(ob->QueryLong()+"Está cocinad"+AoO(ob)+".\n");
  ob2->SetIds(ob->QueryIds());
  ob2->SetAds(ob->QueryAds());
  ob2->SetSmell("Huele a comida bien cocinada.\n");
  ob2->SetFood(1);
  ob2->SetWeight(ob->QueryWeight());

/* un foodstuff de 140 equivale a la comida de 1 día */

  stuff=(140*ob2->QueryWeight())/(101-deg);
  if (stuff<10) stuff=10;
  if (stuff>350) stuff=350;

  ob2->SetFoodStuff(stuff);
  ob2->SetFoodSoak(stuff/2);
  ob2->SetFoodHeal(stuff/5);

  ob2->Set(P_COOKED, 1);
  ob2->Set(P_GENDER, ob->Query(P_GENDER));
  ob2->Set(P_NUMBER, ob->Query(P_NUMBER));
  ob2->move(environment(ob));
  ob->remove();

  return 1;
}

int main(string what)
{
  object ob;

  if (!what) return NTF("¿Cocinar qué?\n");
  ob=present(what, TP);
  if (!ob) ob=present(what, environment(TP));

  if (!ob) return notify_fail("No encuentras "+what+" para cocinar.\n");
  if (member(inherit_list(ob), "/std/corpse.c")!=-1)
    return cook_corpse(ob);
  if (member(inherit_list(ob), "/std/food.c")!=-1)
    return cook_food(ob);

  return NTF("No puedes cocinar "+ob->QueryShort()+".\n");
}