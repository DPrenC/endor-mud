/*******************************************************************************
12345678901234567890123456789012345678901234567890123456789012345678901234567890
       OBJETO PARA INCLUIR HABILIDADES DE COMBATES A LOS PNJ

  Fichero: usahab.c
  Creacion (fusilado): 17-5-00
  Ultima revision: 24-5-00
  Version: 3.1

Notas: **Todas las pruebas estan hechas con MI ANTIGUA version del simauria**

V 1.0: El objeto simplemente funciona, no tiene ninguna pollada
	extra ni nada por el estilo, cuando la hab se usa con exito
	solo dice El bicho feo te hace pupa
V 2.0: Se depura el objeto, deja de ser una armadura para ser una cosa.
	Se autodestruye cuando no lo lleva un PNJ (teoricamente al menos)
	Añadidas distintas frases dependiendo del exito de la habilidad.
	Se hacen pruebas de combate para ver que fuerza se pone; como al
	 parecer los guerreros todavia no tienen bien hecha las habilidades
	 de combate (solo usan el golpe critico, no la habilidad) la pruebo
	 con un conjurata, con igualdad de stats (30), de armas (cintias)
	 (**En mi version los conjuratas aun usabas espadas, pero esto importa )
	 ( relativamente poco, porque la habilidad es la misma pero cambiada de)
	 ( nombre, y como a partir de 65% de exito pasa por completo del WC del)
	 ( arma y le he puesto la hab al 100, "casi" no se nota...**           )
	 y de habilidad (100) lo regulo para que el conjurata practicamente
	 siempre por los pelos (hay que tener en cuenta el factor suerte...)
	 Nota: En habilidad con armas de los conjuratas me parece una sobrada
	  que se pase por el forro el WC del arma... y que de semejantes Hostias
V 3.0: Se hace al objeto invisible.
	Se añaden distintas frases para los distintos tipos de ataques,
	 DT_SLASH, DT_PIERCE, DT_BLUDGEON.
	Intento que valga para el combate sin armas, pero al parecer (o
	 esa es la impresion que me ha dado), si no tiene armas no llama
	 al weaponhit, con lo que pasa de todo.
	Habra que investigar que pasa si toco el do_hit...
	Aumento, un poquito, el efecto de la habilidad, pues teoricamente un
	 conjurata en combate debe ser muuuuuuucho peor que un bicho (que puede
	 que sea guerrero, y que si no lo es con ponerle menos en el AddSkill
	 se resuelve el problema, ahora gana el bicho :) (el conjurata no usa
	 ningun conjuro en a prueba, y los dos sin armadura). Si alguien opina
	 que es muy furra es que no ha visto los procentajes altos de las habs
	 de los pj, en especial la de los conjuratas..., y si aun asi lo sigue
	 pensando, pos no le pongas 100 en le addskill, cortate un pelo y baja.
	(**Lo que realmente creo es que haria falta rebajar ese peazo de	)
	( max(({enemy->QueryMaxHP()/2,250})) de daño que llegan ha hacer	)
	( los conjuratas...	**						    	)

Nota: He localizado el problema para los ataques sin armas, lo que pasa es que
	en el combate se llama a la funcion attack, que hace un do_hit por cada arma
	y por cada mano libre, si es un arma llama a querydamage, este a weaponhit y
	luego este llama a calcdamage, pero si es una mano el propio do_hit lo
	resuelve sin llamar a nada por lo que pasa por completo de mi weaponhit...
	habra que hacer un propio do_hit a ver como tira...

  ** Por cierto, ¿donde esta definida la weaponhit estandard?, no la encuentro...

	Me parece que es que la funcion weaponhit solo se llama cuando se define
	un hitobj, con lo cual en condiciones normales llama solo a calcdamage, y
	si has definido un hitobj llama a weaponhit, que habras de haber definido
	tu aparte (donde lo logico es que dentro de ella llames luego al calcdam,
	aunque quien sabe, depende de lo que quieras hacer...)

  ** Nemy, realmente hacian falta los Notify para los Hitobj!! :)

	Vale, problemas gordos: la única forma de poder meter mano a un ataque
	hecho con la mano es modificar directamente el do_hit, he intentado
	definir mi propio do_hit aqui dentro, pero se lo pasa por el forro y usa
	el que esta definido en el combat.c (en/std/living/) asin que no puedo
	interceptarlo de ninguna forma (o al menos ahora no se me ocurre nada),
	y me parece peligroso sugerir cambios en el combat.c porque ya sabemos
	lo que pasa cuando un wiz nuevo dice esas cosas... pero seria necesario
	alguna manera de poder interceptar ese ataque...
	Tambien he probado a darle un arma invisible a ver como reacciona, pero
	hay un BUG en el codigo, y es que aunque le des la cintia invisible, si
	lo miras te pone que empuña una cintia como si nada, y cuando te ataca
	dice nosequien te intenta rajar (o como sea) con una cintia...
	Asi que tampoco se puede ahcer el "truco" de darle un arma contundente
	invisible para que parezca que pega con la mano, porque aunque el
	mensaje de ataque da igual (le pones de short brazo derecho) que apa-
	rezca empuña un brazo derecho en su brazo derecho no queda demasiado
	bien, el unico consuelo es que los pj casi nunca miran a los pnj, y
	si lo hacen es solo para ver si estan heridos o atrudidos, y en esto no
	se fijan demasiado... (puede que ya se haya arreglado este bug, pero en
	mi version esta, aun asi puede que siga y se arregle, pero no por ello
	voy a cambiar este mensaje, asi que tened en cuenta que este bug puede
	no existir en realidad)

 V3.1   Le pongo invisibilidad 10, pa que ningun player lo vea...

Y porque me apetece, y me esa llevando muuuuuuchas horas un solo objeto, voy
a poner agradecimientos :)), no ya por el objeto este (que los hay) si no mas
por hacer un rato el paria. Especial zanks de esas:
(No estan en ningun orden especial)

A Khelben, pues fue el primero en echarle un vistazo y me abrio los ojos:
	¡En el create no puedes llamar al environment(TO) porque
	todavia no existe el objeto, como coño quieres que tenga environment!
A Nemesis, por ser el segundo en echarle un vistazo y liarme :) con eso de
	los notifywield y notifyunwield
A Mirill, por hacer lo que hace y ser quien es (mi padrino) :)
A el resto de zorras que componen el grupo de gods, porque sin ellos no habria
	mud y no podria haberlo hecho
A Adamas, por ser la mascota del mud :)) y el Wiz-Ocioso por excelencia XDD
A Spoek, por ser siempre el que mas da la nota (menudos colorcitos), el que
	antes	saluda (¿es un trigger?) y el que mas crackea :)
A Parsi, por conseguir calmar los animos con ese arte
A Aven, que lastima que coincidamos tan poco en el mud
A Chanti, como nombrar a Aven sin nombrarle a el :)
A March, por esas rayantes discusiones :) y por mostrarse tan ansioso con esto
A Tvar, ¿para cuando eso de wiz?
Al resto de wizs, faltan algunos que conozco, y otros muchos que no, pero es
	que no es plan de nombrarlos a todos
Y finalmente: A Maler, siempre jodiendo, siempre quejandose, siempre en el
	ordenador menos malo (porque bueno no hay ninguno), siempre llamandome
	esclavo y cosas de esas, siempre pasandose de la raya, siempre
	desmesurado, siempre codeando cosas (ya sean utiles o no), siempre
	echandome cables por todos lados en esto del mud.

***SE ACEPTAN Y ESPERAN SUGERENCIAS, AYUDAS, CRITICAS (CONSTRUCTIVAS),
***	 O LO QUE SEA... mi correo propio es fjvalle@alum.etsii.upv.es

Por fin se acabo el megarrollo del plasta este, siii!!, si has llegado hasta
aqui te has ganado un bonochoco, puedes canjear tus bonochocos por
fantasticos regalos!! :P
						NYH
******************************************************************************/

#include <properties.h>
#include <guild.h>
#include <skills.h>
#include <colours.h>
#include <combat.h>
#include <moving.h>

#define P_LAST_ENEMY "LastEnemy" //logging
#define P_LAST_HP "LastHP" // logging

#define HAB_COMBATE ({HAB_ALABARDA, HAB_HACHA, HAB_CADENA, HAB_MAZA,\
                      HAB_CUCHILLO, HAB_LANZA, HAB_VARA, HAB_LATIGO,\
                      HAB_MANGUAL, HAB_ESGRIMA, HAB_ESPADA, HAB_MANOPLA,\
                      HAB_BARBARO, HAB_SINARMAS })


#define skillweapon ([WT_ALABARDA:HAB_ALABARDA,WT_HACHA:HAB_HACHA,\
	WT_CADENA:HAB_CADENA,WT_MAZA:HAB_MAZA,WT_CUCHILLO:HAB_CUCHILLO,\
	WT_LANZA:HAB_LANZA,WT_VARA:HAB_VARA,WT_ESPADA:HAB_ESPADA,\
	WT_ESGRIMA:HAB_ESGRIMA,WT_LATIGO:HAB_LATIGO,WT_MANGUAL:HAB_MANGUAL,\
	WT_MANOPLA:HAB_MANOPLA,"CsHands":HAB_SINARMAS])

inherit THING;
inherit "/std/living/combat";

private object Owner()
{
  object pnj;
  pnj = environment(TO);
  if (!pnj) return 0;
  return pnj;
}

public varargs int UseSkill(string name, int chance, int percentage)
{
if (!name) return 0;
// if (!HasSkill(name)) return 0;
 if (member(HAB_COMBATE,name)==-1)
 {
   percentage=Owner()->UseSkill(name,chance);
   if (percentage>0) return 1;
   else return 0;
 }
 percentage=Owner()->UseSkill(name,chance);
 if (percentage>0) return 1;
 else return 0;
 return 0;
}

void NotifyUnequip(object liv, object ob,int flags) {
object hitob;
  if (!liv || !ob || liv!=Owner()) return;
  hitob=ob->Query("P_Hitobject");
  ob->Set("P_Hitobject",0);
  if (ob->QueryHitObj()==TO) ob->SetHitObj(hitob);
}

void NotifyEquip(object liv, object weapon, int is_weap) {
  weapon->SetHitObj(TO);
}

public int WeaponHit(object enemy) {
  object pnj,weapon,o;
  status skillsuccess;
  int percent,per,dam,level,chance,orgdam;
  string sk,txt;
  string mhab,mene;
 //dtell("diox"," uso weaponhit ");
 if ((pnj = Owner()) && (weapon = pnj->Query(P_LAST_ENEMY)))
    {
      pnj->Set(P_LAST_ENEMY,0);
    }

 weapon=PO;
 if (!weapon) return 0;

 if (o=weapon->Query("P_Hitobject")) orgdam=(int)o->WeaponHit(enemy);
 else orgdam=weapon->CalcDamage(enemy);

 if (!pnj) return orgdam;

 if (objectp(weapon)) {sk=skillweapon[weapon->QueryWeaponType()];} else {return orgdam;}
// antes en ver de return orgdam estaba sk=HAB_SINARMAS...
//tell("nyh","SK: "+sk);
 chance = (pnj->QueryDex()*4+pnj->QueryStr()*2+pnj->QueryInt())/7-(enemy->QueryDex()*3+enemy->QueryCon())/4;
 if (chance > 10 ) chance=10;
 if (chance <-10) chance=-10;
 if ((per=(percent=pnj->UseSkill(sk,chance)))>0)
 {
   while(per>95) percent += (per=(pnj->UseSkill(sk,chance)));
   dam=orgdam*((percent+15)/15);
   skillsuccess = 1;
// antes aqui habia un if sk=HAB_SINARMAS donde estaban sus frases, y el resto
// estaba en el else...
	switch (weapon->QueryDamType()) {
   	case DT_BLUDGEON:
		switch (percent) {
		case 1..10:  mhab="   "+capitalize(Owner()->QueryName())+" pilla desprevenido a "+capitalize(enemy->QueryName())+".\n";
		     mene="   "+capitalize(Owner()->QueryName())+" te pilla desprevenido.\n";
		     break;
		case 11..20: mhab="   "+capitalize(Owner()->QueryName())+" golpea habilmente a "+capitalize(enemy->QueryName())+".\n";
		     mene="   "+capitalize(Owner()->QueryName())+" te golpea habilmente.\n";
		     break;
		case 21..30: mhab="   "+TC_YELLOW+capitalize(Owner()->QueryName())+" alcanza con un doloroso golpe a "+capitalize(enemy->QueryName())+".\n";
		     mene="   "+TC_YELLOW+capitalize(Owner()->QueryName())+" te alcanza con un doloroso golpe.\n";
		     break;
		case 31..40: mhab="   "+TC_YELLOW+capitalize(Owner()->QueryName())+" golpea furiosamente a "+capitalize(enemy->QueryName())+".\n";
		     mene="   "+TC_YELLOW+capitalize(Owner()->QueryName())+" te golpea furiosamente.\n";
		     break;
		case 41..50: mhab="   "+TC_YELLOW+capitalize(Owner()->QueryName())+" alcanza en el plexo solar a "+capitalize(enemy->QueryName())+".\n";
		     mene="   "+TC_YELLOW+capitalize(Owner()->QueryName())+" te alcanza en el plexo solar.\n";
		     break;
		case 51..60: mhab="   "+TC_RED+capitalize(Owner()->QueryName())+" cruje vivo a "+capitalize(enemy->QueryName())+".\n";
		     mene="   "+TC_RED+capitalize(Owner()->QueryName())+" te cruje vivo.\n";
		     break;
		case 61..70: mhab="   "+TC_RED+capitalize(Owner()->QueryName())+" destroza a "+capitalize(enemy->QueryName())+".\n";
		     mene="   "+TC_RED+capitalize(Owner()->QueryName())+" te destroza.\n";
		     break;
		case 71..80: mhab="   "+TC_RED+"Oyes como los huesos de "+capitalize(enemy->QueryName())+" crujen bajo el poderoso golpe de "+Owner()->QueryName()+".\n";
		     mene="   "+TC_RED+"Oyes tus huesos crujir bajo el poderoso golpe de "+Owner()->QueryName()+".\n";
		     break;
		case 81..90: mhab="   "+TC_BOLD+TC_RED+capitalize(Owner()->QueryName())+" AGRRRIETA EL CRRRANEO de"+capitalize(enemy->QueryName())+" .\n";
		       mene="   "+TC_BOLD+TC_RED+capitalize(Owner()->QueryName())+" te AGRRRIETA EL CRRRANEO.\n";
		       break;
		case 91..100: mhab="   "+TC_BOLD+TC_BLINK+TC_BG_RED+TC_CYAN+capitalize(Owner()->QueryName())+" PULVERIZA LOS HUESOS a "+capitalize(enemy->QueryName())+".\n";
		     mene="   "+TC_BOLD+TC_BLINK+TC_BG_RED+TC_CYAN+capitalize(Owner()->QueryName())+" te PULVERIZA LOS HUESOS.\n";
		     break;
		case 101..1000: mhab="          "+TC_BOLD+TC_BLINK+TC_UNDERL+TC_BG_PURPLE+TC_CYAN+capitalize(Owner()->QueryName())+" REDUCE A "+capitalize(enemy->QueryName())+" A UNA PULPA GELATINOSA.\n";
		      mene="          "+TC_BOLD+TC_BLINK+TC_UNDERL+TC_BG_PURPLE+TC_CYAN+capitalize(Owner()->QueryName())+" TE REDUCE A UNA PULPA GELATINOSA.\n";
		      break;
		}
	break;
  	case DT_PIERCE:
		switch (percent) {
		case 1..10:  mhab="   "+capitalize(Owner()->QueryName())+" pilla desprevenido a "+capitalize(enemy->QueryName())+".\n";
		     mene="   "+capitalize(Owner()->QueryName())+" te pilla desprevenido.\n";
		     break;
		case 11..20: mhab="   "+capitalize(Owner()->QueryName())+" ataca habilmente a "+capitalize(enemy->QueryName())+".\n";
		     mene="   "+capitalize(Owner()->QueryName())+" te ataca habilmente.\n";
		     break;
		case 21..30: mhab="   "+TC_YELLOW+capitalize(Owner()->QueryName())+" alcanza con una dolorosa punzada a "+capitalize(enemy->QueryName())+".\n";
		     mene="   "+TC_YELLOW+capitalize(Owner()->QueryName())+" te alcanza con una dolorosa punzada.\n";
		     break;
		case 31..40: mhab="   "+TC_YELLOW+capitalize(Owner()->QueryName())+" ataca furiosamente a "+capitalize(enemy->QueryName())+".\n";
		     mene="   "+TC_YELLOW+capitalize(Owner()->QueryName())+" te ataca furiosamente.\n";
		     break;
		case 41..50: mhab="   "+TC_YELLOW+capitalize(Owner()->QueryName())+" alcanza en el abdomen a "+capitalize(enemy->QueryName())+".\n";
		     mene="   "+TC_YELLOW+capitalize(Owner()->QueryName())+" te alcanza en el abdomen.\n";
		     break;
		case 51..60: mhab="   "+TC_RED+capitalize(Owner()->QueryName())+" peta el cacas a "+capitalize(enemy->QueryName())+".\n";
		     mene="   "+TC_RED+capitalize(Owner()->QueryName())+" te peta el cacas.\n";
		     break;
		case 61..70: mhab="   "+TC_RED+capitalize(Owner()->QueryName())+" agujerea a "+capitalize(enemy->QueryName())+".\n";
		     mene="   "+TC_RED+capitalize(Owner()->QueryName())+" te agujerea.\n";
		     break;
		case 71..80: mhab="   "+TC_BOLD+TC_RED+capitalize(Owner()->QueryName())+" EMPALA a "+capitalize(enemy->QueryName())+".\n";
		     mene="   "+TC_BOLD+TC_RED+capitalize(Owner()->QueryName())+" te EMPALA.\n";
		     break;
		case 81..90: mhab="   "+TC_BOLD+TC_RED+capitalize(Owner()->QueryName())+" PERRRFORA EL CRRRANEO a "+capitalize(enemy->QueryName())+".\n";
		     mene="   "+TC_BOLD+TC_RED+capitalize(Owner()->QueryName())+" te PERRRFORA EL CRRRANEO.\n";
		     break;
		case 91..100: mhab="   "+TC_BOLD+TC_BLINK+TC_BG_RED+TC_CYAN+capitalize(Owner()->QueryName())+" ATRAVIESA EL CORAZON de "+capitalize(enemy->QueryName())+".\n";
		      mene="   "+TC_BOLD+TC_BLINK+TC_BG_RED+TC_CYAN+capitalize(Owner()->QueryName())+" ATRAVIESA EL CORAZON.\n";
		      break;
		case 101..1000: mhab="          "+TC_BOLD+TC_BLINK+TC_UNDERL+TC_BG_PURPLE+TC_CYAN+capitalize(Owner()->QueryName())+" CONVIERTE A "+capitalize(enemy->QueryName())+" EN UN COLADOR.\n";
		      mene="          "+TC_BOLD+TC_BLINK+TC_UNDERL+TC_BG_PURPLE+TC_CYAN+capitalize(Owner()->QueryName())+" TE CONVIERTE EN UN COLADOR.\n";
		      break;
			}
	break;
  	case DT_SLASH:
		switch (percent) {
		case 1..10:  mhab="   "+capitalize(Owner()->QueryName())+" pilla desprevenido a "+capitalize(enemy->QueryName())+".\n";
		     mene="   "+capitalize(Owner()->QueryName())+" te pilla desprevenido.\n";
		     break;
		case 11..20: mhab="   "+capitalize(Owner()->QueryName())+" corta habilmente a "+capitalize(enemy->QueryName())+".\n";
		     mene="   "+capitalize(Owner()->QueryName())+" te corta habilmente.\n";
		     break;
		case 21..30: mhab="   "+TC_YELLOW+capitalize(Owner()->QueryName())+" hace un feo corte a "+capitalize(enemy->QueryName())+".\n";
		     mene="   "+TC_YELLOW+capitalize(Owner()->QueryName())+" te hace un feo corte.\n";
		     break;
		case 31..40: mhab="   "+TC_YELLOW+capitalize(Owner()->QueryName())+" corta furiosamente a "+capitalize(enemy->QueryName())+".\n";
		     mene="   "+TC_YELLOW+capitalize(Owner()->QueryName())+" te corta furiosamente.\n";
		     break;
		case 41..50: mhab="   "+TC_YELLOW+capitalize(Owner()->QueryName())+" alcanza en el costado a "+capitalize(enemy->QueryName())+".\n";
		     mene="   "+TC_YELLOW+capitalize(Owner()->QueryName())+" te alcanza en el costado.\n";
		     break;
		case 51..60: mhab="   "+TC_RED+capitalize(Owner()->QueryName())+" le hace el Hara-Kiri a "+capitalize(enemy->QueryName())+".\n";
		     mene="   "+TC_RED+capitalize(Owner()->QueryName())+" te hace el Hara-Kiri.\n";
		     break;
		case 61..70: mhab="   "+TC_RED+capitalize(Owner()->QueryName())+" secciona una pierna a "+capitalize(enemy->QueryName())+".\n";
		     mene="   "+TC_RED+capitalize(Owner()->QueryName())+" te secciona una pierna.\n";
		     break;
		case 71..80: mhab="   "+TC_BOLD+TC_RED+capitalize(Owner()->QueryName())+" AMPUTA UN BRAZO a "+capitalize(enemy->QueryName())+".\n";
		     mene="   "+TC_BOLD+TC_RED+capitalize(Owner()->QueryName())+" te AMPUTA UN BRAZO.\n";
		     break;
		case 81..90: mhab="   "+TC_BOLD+TC_RED+capitalize(Owner()->QueryName())+" CORTA EN DOS a "+capitalize(enemy->QueryName())+".\n";
		     mene="   "+TC_BOLD+TC_RED+capitalize(Owner()->QueryName())+" te CORTA EN DOS.\n";
		     break;
		case 91..100: mhab="   "+TC_BOLD+TC_BLINK+TC_BG_RED+TC_CYAN+capitalize(Owner()->QueryName())+" DESTRIPA A "+capitalize(enemy->QueryName())+".\n";
		      mene="   "+TC_BOLD+TC_BLINK+TC_BG_RED+TC_CYAN+capitalize(Owner()->QueryName())+" TE DESTRIPA.\n";
		      break;
		case 101..1000: mhab="          "+TC_BOLD+TC_BLINK+TC_UNDERL+TC_BG_RED+TC_CYAN+capitalize(Owner()->QueryName())+" CERCENA EL ALMA A "+capitalize(enemy->QueryName())+".\n";
		       mene="          "+TC_BOLD+TC_BLINK+TC_UNDERL+TC_BG_RED+TC_CYAN+capitalize(Owner()->QueryName())+" TE CERCENA EL ALMA.\n";
		       break;
		}
	break;
  	default:
		switch (percent) {
		case 1..10:  mhab="   "+capitalize(Owner()->QueryName())+" pilla desprevenido a "+capitalize(enemy->QueryName())+".\n";
		     mene="   "+capitalize(Owner()->QueryName())+" te pilla desprevenido.\n";
		     break;
		case 11..20: mhab="   "+capitalize(Owner()->QueryName())+" golpea habilmente a "+capitalize(enemy->QueryName())+".\n";
		     mene="   "+capitalize(Owner()->QueryName())+" te golpea habilmente.\n";
		     break;
		case 21..30: mhab="   "+TC_YELLOW+capitalize(Owner()->QueryName())+" alcanza con un doloroso golpe a "+capitalize(enemy->QueryName())+".\n";
		     mene="   "+TC_YELLOW+capitalize(Owner()->QueryName())+" te alcanza con un doloroso golpe.\n";
		     break;
		case 31..40: mhab="   "+TC_YELLOW+capitalize(Owner()->QueryName())+" golpea furiosamente a "+capitalize(enemy->QueryName())+".\n";
		     mene="   "+TC_YELLOW+capitalize(Owner()->QueryName())+" te golpea furiosamente.\n";
		     break;
		case 41..50: mhab="   "+TC_YELLOW+capitalize(Owner()->QueryName())+" alcanza en el plexo solar a "+capitalize(enemy->QueryName())+".\n";
		     mene="   "+TC_YELLOW+capitalize(Owner()->QueryName())+" te alcanza en el plexo solar.\n";
		     break;
		case 51..60: mhab="   "+TC_RED+capitalize(Owner()->QueryName())+" cruje vivo a "+capitalize(enemy->QueryName())+".\n";
		     mene="   "+TC_RED+capitalize(Owner()->QueryName())+" te cruje vivo.\n";
		     break;
		case 61..70: mhab="   "+TC_RED+capitalize(Owner()->QueryName())+" destroza a "+capitalize(enemy->QueryName())+".\n";
		     mene="   "+TC_RED+capitalize(Owner()->QueryName())+" te destroza.\n";
		     break;
		case 71..80: mhab="   "+TC_RED+"Oyes como los huesos de "+capitalize(enemy->QueryName())+" crujen bajo el poderoso golpe de "+Owner()->QueryName()+".\n";
		     mene="   "+TC_RED+"Oyes tus huesos crujir bajo el poderoso golpe de "+Owner()->QueryName()+".\n";
		     break;
		case 81..90: mhab="   "+TC_BOLD+TC_RED+capitalize(Owner()->QueryName())+" ANIKKILA a "+capitalize(enemy->QueryName())+".\n";
		     mene="   "+TC_BOLD+TC_RED+capitalize(Owner()->QueryName())+" te ANIKKILA.\n";
		     break;
		case 91..100: mhab="   "+TC_BOLD+TC_BLINK+TC_BG_RED+TC_CYAN+capitalize(Owner()->QueryName())+" ERRADICA A "+capitalize(enemy->QueryName())+".\n";
		       mene="   "+TC_BOLD+TC_BLINK+TC_BG_RED+TC_CYAN+capitalize(Owner()->QueryName())+" TE ERRADICA.\n";
		       break;
		case 101..1000: mhab="          "+TC_BOLD+TC_BLINK+TC_UNDERL+TC_BG_PURPLE+TC_CYAN+capitalize(Owner()->QueryName())+" SE HACE UN COLLAR CON LOS INTESTINOS DE "+capitalize(enemy->QueryName())+".\n";
		      mene="          "+TC_BOLD+TC_BLINK+TC_UNDERL+TC_BG_PURPLE+TC_CYAN+capitalize(Owner()->QueryName())+" SE HACE UN COLLAR CON TUS INTESTINOS.\n";
		      break;
		} //switch percent
	} //swith querydamtype
   if (dam>5)
   {
	     tell_object(enemy,mene+TC_NORMAL);
           tell_room(environment(Owner()),mhab+TC_NORMAL,({Owner(),enemy}));
   } // if(dam>5)
 } //if per>0
 else
 {
	dam=orgdam;
 } //else de if per>0
 dtell("nyh","Orgdam: "+orgdam+"  Percent: "+percent+"  Le crujo "+dam+" pv.\n");
 dtell("diox","Orgdam: "+orgdam+"  Percent: "+percent+"   Le crujo "+dam+" pv.\n");
 return dam;
}

/* como pasa de el lo quito, pero no lo borro por si acaso
cuidado al descomentarlo, hay que reañadir los comentarios de antes...
cambiar FIN por *

do_hit(x) {
  int damage, damage_type, chance, orgdam, percent, per;
  string how, hows, mhab, mene;
  object enemy;
  string xshort;
//dtell("diox","MI do_hit,x=object ");
  if (!enemies || !sizeof(enemies)) return 0;
  enemy = enemies[random(sizeof(enemies))];
  if (!enemy || enemy->QueryHP() < 0
		|| (query_once_interactive(enemy) && !interactive(enemy))
	  )
	 { StopHunting(enemy); return 0; }
  if (!present(enemy)) { StartHunting(enemy); return 0; }

  /* HBSTAT FIN/
  if (query_once_interactive(TO))
  {
	 hbstat[to_string(enemy), 0]++;
  }
  if (objectp(x)) {
//	 dtell("diox","do_hit,x=object ");
	 xshort = x->QueryShort(); /* counter self-destructing weapons FIN/
	 damage = x->QueryDamage(enemy);
	 damage_type = x->QueryDamageType();
	 if (x->QueryOldCombat())
	 {
		switch (damage_type) {
	case DT_BLUDGEON: how = TC_BOLD" Cargas sobre "TC_NORMAL; hows = " carga sobre"; break;
	case DT_PIERCE: how = TC_BOLD" Intentas pinchar a "TC_NORMAL; hows = " intenta pinchar"; break;
	case DT_SLASH: how = TC_BOLD" Intentas rajar a "TC_NORMAL; hows = " intenta rajar"; break;
	default: how = TC_BOLD"Atacas a "TC_NORMAL; hows = " ataca";
		}
		if (!enemy) return;
		tell_object(TO, ""+how+enemy->QueryName() +" con "+xshort); //NO BORRAR

		switch (damage_type) {
	case DT_BLUDGEON: tell_object(enemy,""+capitalize(QueryName())+hows+" tí con "
		  +xshort); break;

	case DT_PIERCE: tell_object(enemy, ""+capitalize(QueryName())+ " te "+hows+" con "
		  +xshort); break;

	case DT_SLASH: tell_object(enemy, ""+capitalize(QueryName())+" te "+hows+" con "
		  +xshort);
		}

		switch (damage_type) {
	case DT_BLUDGEON: say(STR->RemoveColors("  "+capitalize(QueryName())+" "+hows+" a "+enemy->QueryName()+" con "
	  +xshort),({TO, enemy})); break;

	case DT_PIERCE: say(STR->RemoveColors("  "+capitalize(QueryName())+" "+hows+" a "+enemy->QueryName()+" con "
	  +xshort),({TO, enemy})); break;

	case DT_SLASH: say(STR->RemoveColors("  "+capitalize(QueryName())+" "+hows+" a "+enemy->QueryName()+" con "
	  +xshort),({TO, enemy})); break;

	}
	 }
  }
  else {	 //dtell("diox","do_hit,x=norob ");
	 /* Magic formula for hand attacks FIN/
	 orgdam = random(3*hands[x][HAND_WC]/5+QueryDex()/5 + QueryStr()/5);
	 damage_type = DT_BLUDGEON;

	chance = (Owner()->QueryDex()*4+Owner()->QueryStr()*2+Owner()->QueryInt())/7-(enemy->QueryDex()*3+enemy->QueryCon())/4;
	 if (chance > 10 ) chance=10;
	 if (chance <-10) chance=-10;
	 if ((per=(percent=Owner()->UseSkill(HAB_SINARMAS,chance)))>0)
	 {
	   while(per>95) percent += (per=(Owner()->UseSkill(HAB_SINARMAS,chance)));
	   damage=orgdam*((percent+15)/15);
		switch (percent) {
 		case 1..10:  mhab="   "+capitalize(Owner()->QueryName())+" pilla desprevenido a "+capitalize(enemy->QueryName())+".\n";
 		     mene="   "+capitalize(Owner()->QueryName())+" te pilla desprevenido.\n";
 		     break;
 		case 11..20: mhab="   "+capitalize(Owner()->QueryName())+" golpea habilmente a "+capitalize(enemy->QueryName())+".\n";
 		     mene="   "+capitalize(Owner()->QueryName())+" te golpea habilmente.\n";
 		     break;
 		case 21..30: mhab="   "+TC_YELLOW+capitalize(Owner()->QueryName())+" propina un doloroso golpe a "+capitalize(enemy->QueryName())+".\n";
 		     mene="   "+TC_YELLOW+capitalize(Owner()->QueryName())+" te propina con un doloroso golpe.\n";
 		     break;
 		case 31..40: mhab="   "+TC_YELLOW+capitalize(Owner()->QueryName())+" golpea furiosamente a "+capitalize(enemy->QueryName())+".\n";
 		     mene="   "+TC_YELLOW+capitalize(Owner()->QueryName())+" te golpea furiosamente.\n";
 		     break;
 		case 41..50: mhab="   "+TC_YELLOW+capitalize(Owner()->QueryName())+" alcanza en el plexo solar a "+capitalize(enemy->QueryName())+".\n";
 		     mene="   "+TC_YELLOW+capitalize(Owner()->QueryName())+" te alcanza en el plexo solar.\n";
 		     break;
 		case 51..60: mhab="   "+TC_RED+capitalize(Owner()->QueryName())+" cruje vivo a "+capitalize(enemy->QueryName())+".\n";
 		     mene="   "+TC_RED+capitalize(Owner()->QueryName())+" te cruje vivo.\n";
 		     break;
 		case 61..70: mhab="   "+TC_RED+capitalize(Owner()->QueryName())+" destroza a "+capitalize(enemy->QueryName())+".\n";
 		     mene="   "+TC_RED+capitalize(Owner()->QueryName())+" te destroza.\n";
 		     break;
 		case 71..80: mhab="   "+TC_RED+"Oyes como los huesos de "+capitalize(enemy->QueryName())+" crujen bajo el poderoso golpe de "+Owner()->QueryName()+".\n";
 		     mene="   "+TC_RED+"Oyes tus huesos crujir bajo el poderoso golpe de "+Owner()->QueryName()+".\n";
 		     break;
 		case 81..90: mhab="   "+TC_BOLD+TC_RED+capitalize(Owner()->QueryName())+" ANIKKILA a "+capitalize(enemy->QueryName())+".\n";
 		     mene="   "+TC_BOLD+TC_RED+capitalize(Owner()->QueryName())+" te ANIKKILA.\n";
 		     break;
 		case 91..100: mhab="   "+TC_BOLD+TC_BLINK+TC_UNDERL+TC_BG_PURPLE+TC_CYAN+capitalize(Owner()->QueryName())+" SE HACE UN COLLAR CON LOS INTESTINOS DE "+capitalize(enemy->QueryName())+".\n";
 		      mene="   "+TC_BOLD+TC_BLINK+TC_UNDERL+TC_BG_PURPLE+TC_CYAN+capitalize(Owner()->QueryName())+" SE HACE UN COLLAR CON TUS INTESTINOS.\n";
 		      break;
 		case 101..1000: mhab="          "+TC_BOLD+TC_BLINK+TC_UNDERL+TC_BG_RED+TC_CYAN+capitalize(enemy->QueryName())+" CREE MORIR.\n";
 		       mene="          "+TC_BOLD+TC_BLINK+TC_UNDERL+TC_BG_RED+TC_CYAN+"CREES MORIR.\n";
 		       break;
    		}
	if (damage>5)
	   {
		     tell_object(enemy,mene+TC_NORMAL);
	           tell_room(environment(Owner()),mhab+TC_NORMAL,({Owner(),enemy}));
	   } // if(dam>5)
 	} else damage=orgdam;
	tell_object(TO,TC_BOLD" Atacas a "TC_NORMAL+enemy->QueryName()
		+" con "+hands[x][HAND_SHORT]);
	 tell_object(enemy, "  "+capitalize(QueryName())+" te ataca con "
		+hands[x][HAND_SHORT]);
	 say(STR->RemoveColors("  "+capitalize(QueryName())+" ataca a "+enemy->QueryName()+" con "
	+hands[x][HAND_SHORT]),({TO, enemy}));
  }

  if (enemy)
  {
	 damage = enemy->Defend(damage, damage_type, objectp(x)?x:0);
	 AddXP(damage);
  }
  return enemy;
}
*/


public create()
{
   int i;
   object *armas;

   thing::create();
   if (!clonep()) return;
  seteuid(getuid());
  SetShort("Un objeto");
  SetIds(({"objeto"}));
  SetAds(({"un"}));
  SetLong("Un objeto SOLO para PNJ.\n");
  SetValue(0);
  SetWeight(0);
  SetNoDrop("¡He!, que no\n");
  SetNoGive("¡He!, que no\n");
  Set(P_INVIS,10);
   // Comprueba que el gremio del tipo/a que lleva esta vara es del gremio
   // de quiero usar hab! :).
/* esto lo comento para poder cogerlo, pero que luego vuelve
   if(PO)
   {
      if(PO->QueryIsPlayer()) call_out( "remove", 1 );
   }
*/
   // Comprueba las armas que actualmente se estan empunyando.
   armas = (PO->QueryWeapons() || (({})) );
   for( i = 0; i < sizeof( armas ); i++ )
      if( armas[i] && armas[i]->QueryWC() > 0 ) NotifyEquip( PO, armas[i], 0 );
}


public void init()
{
  object ob;
  (::init());
  if (!Owner()) return;
  ob=Owner();
  if (ob && ob==Owner()) ob->AddEquipObj(TO);
  if(ob->QueryIsPlayer() || !living(ob)) call_out( "remove", 1 );
}

