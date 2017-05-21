/***************************************************************************************
 ARCHIVO:	kimera.c
 AUTOR:		[k] Korsario
 FECHA:		07-11-1997
 COMENTARIOS:	La espada Kimera de Kendarg
 		[z] Zomax - La hago de tipo daga internamente para que puedan empuñarla
 		los conjuradores y hacer la quest. Por fuera sigue siendo espada y a dos
 		manos.
 		[h] Nyh - Facilita la interacción entre la espada, la gema y los pj
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit WEAPON;

create(){
  ::create();
  SetStandard(WT_ESPADA,6,P_SIZE_SMALL,M_ACERO);
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetNumberHands(2);
  SetValue(13000);
  SetIds(({"espada","espada corta","espada kimera","kimera","_espada_kimera_"}));
  SetAds(({"corta","kender"}));

  SetShort("la espada kimera");
  SetLong("Una espada corta kender. Es bastante ligera, pero parece estar "
  	"forjada con un metal muy resistente. Es bonita y brillante. Tiene una "
  	"inscripción en su empuñadura.\n");

  AddSubDetail(({"inscripcion","inscripción"}),"Lees la inscripcion que hay "
  	"en la empuñadura...\n\n"
	"             @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
	"             @     -> K_me_a <-                          @\n"
	"             @   Esp_da de_ ho_orable Ke_d_rg.           @\n"
	"             @   Forjada en Fl_nt__, en agr__eci__ento   @\n"
	"             @   a s_s ser_i_ios prest_dos.              @\n"
	"             @                                   ------. @\n"
	"             @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n"
	"Algunas letras estan borradas por el uso.\n");

}

init(){
  ::init();

  add_action("fdecir","decir");
  add_action("fencajar","encajar");
  add_action("fencajar","incrustar");
  add_action("fencajar","colocar");
  add_action("fencajar","usar");
  add_action("fencajar","poner");
}

fencajar(string str) {
  object piedra, espada;
  string what, where;

  if (!str || sscanf(str,"%s en %s",what,where)!=2) return notify_fail("¿"+capitalize(query_verb())+" <que> en <donde>?\n");
  if (!(piedra=present(what,TP))) return notify_fail("No tienes "+what+".\n");
  if (!(espada=present(where,TP))) return notify_fail("No tienes "+where+".\n");

  if (piedra->id("_piedra_verde_") && espada->id("_espada_kimera_")) {
    write("Encajas la piedra verde en la empuñadura y la gema "
    	     "empieza a brillar de tal forma que casi te deslumbra. "
     	     "En tu mente se oye el siguiente mensaje:\n[52m'Encuentra "
     	     "los anillos que reposan junto al lago, serán tu salvación!'[0m\n");
    say(CATP+" encaja una bonita gema verde en su espada Kimera.\n",TP);
	   TO->SetLong("Una espada corta kender. Es bastante ligera, pero "
	   "parece estar forjada con un material muy resistente. Es "
	   "bonita y brillante. Lleva una gema verde resplandeciente "
	   "en su empuñadura. Hay tambien una inscripción en ella.\n");
    piedra->remove();
    TO->AddId("kimera con piedra verde");
    return 1;
  }
  else return notify_fail("No puedes "+query_verb()+" "+what+" en "+where+".\n");
}

int fnormal(object espada)
{
	if (!espada) return 0;
	if (!TP) return 0;
	SetWC(8);
	write("Notas como la espada pierde poder y vuelve a la normalidad.\n");
	SetShort("una espada corta");
	SetLong("Una espada corta kender. Es bastante ligera, pero parece "
		"estar forjada con un metal muy resistente. Es bonita y brillante. "
		"Tiene una inscripción en su empuñadura.\n");
	return 1;
}

int fdecir(string str)
{
	if (!TP) return 0;
	if (!QueryEquipped()) return 0;
	if(TP->QueryRace()!="kender") return 0;
	if (str=="kimera")
	{
		SetWC(11);
		write("La espada comienza a brillar y a desprender destellos "
			"azules de luz. Te sientes poderoso al empuñar esta "
			"espada. La palabra 'kimera' aparece en tu mente.\n");
    		say("La espada que sostiene "+CATP+" comienza a desprender "
    			"destellos azules de luz.\n",TP);
		SetShort("espada corta azul");
		SetLong("Es una espada corta. Desprende destellos azules de "
			"luz. Es bastante ligera, pero parece estar forjada con "
			"un metal muy resistente. Tiene una inscripción en su "
			"empuñadura.\n");
		call_out("fnormal",120,TO);
		return 1;
	}
	return 0;
}

int fremove(object espada)
{
	if (!espada) return 0;
	if (!TP) return 0;
	write("De repente ¡Zas! la espada se deshace entre tus manos.\n");
	TO->remove();
	return 1;
}

public varargs void NotifyEquip(object liv, object what, int flags)
{
	SetWC(6); // Por si ha petado y vale 11, q el callout de vuelta es una chapuza
	if (!TP) return 0;
		
	if (liv->QueryRace()=="kender")
	{
		write("Al blandir el arma sientes que no es un arma corriente. "
          "Tienes un presentimiento sobre esta espada.\n");
    return ;
	}
	else
	{
		write("Cuando sostienes la espada empieza a brillar y a emitir "
		"un zumbido.\n");
		say("La espada de "+CATP+" empieza a brillar y a emitir un zumbido.\n");
		call_out("fremove",4,TO);
		return ;
	}
}
