/***********************************************************/
//	Mina estándard (para no programar la movida
//	de las trampas en todas las habitaciones!!)
//	11-12-01 : Creación -> Kodex
//	15-12-01 : Modificación -> Kodex
//	16-12-01 : Modificación -> Kodex
//
//	*He puesto una trampa que se activa al entrar en
//	 la habitación, hay 4 tipos de trampa: cuchillas,
//	 fuego, rocas y lanzas. modificar la variable
//	 prob para aumentar la posibilidad de que haya
//	 trampa. Actualmente 8%. (11-12-01) la subo a 10% total...
//						(05-02-02)
//
//	*(Añado los SetDieMsg que no había!!)->No funcionan
//	 lo dejo comentado. Cambio los colorines para que
//	 sean distintos en cada trampa.
//	 Añado encontrar minerales con muy poca probabilidad
// 	 actualmente 4% (15-12-01)
//	*Hay una forma para que funcione el SetDieMsg pero no
//	 se si merece la pena
//
//


#include <properties.h>
#include <combat.h>
#include <sounds.h>
#include <skills.h>
#include <colours.h>
#include "./path.h"
inherit SIM_ROOM;

#define PROB_TRAMPA 12
#define PROB_MINERAL 10

create() {
::create();
SetIndoors(1);
SetIntBright(25);
//Por lo visto no rulan si estan dentro de un if así que lo generalizo
SetDieMsg("#jug# murió presa de una trampa.");
//
SetIntNoise("Oyes pequeñas rocas precipitándose.\n");
SetIntSmell("El aire es irrespirable.\n");
SetLocate("Mina");
/* Encontrar mineral */

		if (random(100) < PROB_MINERAL)
			{
				switch (random(12))
					{
					case 0 .. 6: /*Un cristal de cuarzo*/
						AddItem("/std/thing",REFRESH_REMOVE,1,
						    ([P_SHORT: "un cristal de cuarzo",
						     	P_LONG: "Es un cristal semitransparente. El cuarzo no está muy bien valorado pero podrás sacar algo de dinero.\n",
     						     	P_IDS: ({"cristal","cuarzo","cristal de cuarzo"}),
     							P_WEIGHT: 800,
     							P_VALUE: 3000,
     							P_GENDER: GENERO_MASCULINO,
     							P_NUMBER: NUMERO_SINGULAR]));
     							break;
					case 7 .. 10: /*Una pepita de oro*/
						AddItem("/std/thing",REFRESH_REMOVE,1,
						    ([P_SHORT: "una pepita de oro",
						     	P_LONG: "Es una gran pepita de oro, su pureza es considerable y debe estar muy bien valorada.\n",
     						     	P_IDS: ({"pepita","pepita de oro"}),
     							P_WEIGHT: 100,
     							P_VALUE: 8000,
     							P_GENDER: GENERO_FEMENINO,
     							P_NUMBER: NUMERO_SINGULAR]));
     							break;
					case 11: /*Un pedazo de mithril*/
						AddItem("/std/thing",REFRESH_REMOVE,1,
						    ([P_SHORT: "un pedazo de mithril",
						     	P_LONG: "El mithril es un mineral muy codiciado, este pedazo de mithril debe valer mucho dinero.\n",
     						     	P_IDS: ({"pedazo","pedazo de mithril"}),
     							P_WEIGHT: 800,
     							P_VALUE: 30000,
     							P_GENDER: GENERO_MASCULINO,
     							P_NUMBER: NUMERO_SINGULAR]));
     							break;
     					default: break;
					}
			}


}

init()
{
	int skill;
	::init();

	/* Activar trampa */
	if (random(100)< PROB_TRAMPA)
	{
		switch (random(4))
		{
			case 0: /* cuchilla */
				//SetDieMsg("#jug# ha muerto cercenado por una cuchilla.");
				skill = TP->UseSkill(HAB_SALTAR,40);
				play_sound(environment(TP), SND_SUCESOS("cuchilla"));
				if (skill < -75)
					{
						write(TC_CYAN+"Una cuchilla sale de la pared dándote un gran tajo.n"+TC_NORMAL);
						say(capitalize(TP->QueryRealName()) + " da un mal paso activando una trampa, una cuchilla aparece de entre las rocas y le da un gran tajo.\n",TP);
						TP->Defend(30,DT_SLASH,DEFEND_NOMSG);
					}
				else if (skill < -25 && skill >= -75)
					{
						write(TC_CYAN+"Una cuchilla sale de la pared haciéndote un corte.\n"+TC_NORMAL);
						say(capitalize(TP->QueryRealName()) + " da un mal paso activando una trampa, una cuchilla aparece de entre las rocas y le hace un corte.\n",TP);
						TP->Defend(20,DT_SLASH,DEFEND_NOMSG);
					}
				else if (skill < 0 && skill >= -25)
					{
						write(TC_CYAN+"Una cuchilla sale de la pared haciéndote un ligero corte.\n"+TC_NORMAL);
						say(capitalize(TP->QueryRealName()) + " da un mal paso activando una trampa, una cuchilla aparece de entre las rocas y le hace un ligero corte.\n",TP);
						TP->Defend(10,DT_SLASH,DEFEND_NOMSG);
					}
				else
					{
					write(TC_CYAN+"Una cuchilla sale de la pared pero saltas en el momento oportuno y la esquivas.\n"+TC_NORMAL);
					say(capitalize(TP->QueryRealName()) + " da un mal paso activando una trampa, pero salta en el momento oportuno y esquiva una mortal cuchilla.\n",TP);
					}
				break;
			case 1: /* fuego */
				//SetDieMsg("#jug# ha muerto abrasado por una intensa llamarada.");
				skill = random(240) -100;
				play_sound(environment(TP), SND_MAGIA("lanza_fuego"));
				if (skill < -75)
					{
						write(TC_RED+"Una gran llamarada sale de una de las paredes y te da de lleno.\n"+TC_NORMAL);
						say(W("Un gran chorro de fuego sale de una pared hacia " + capitalize(TP->QueryRealName()) + " y le da de lleno.\n"),TP);
						TP->Defend(30,DT_FIRE,DEFEND_NOMSG);
					}
				else if (skill < -25 && skill >= -75)
					{
						write(TC_RED+"Una llamarada sale de una de las paredes y te da parcialmente.\n"+TC_NORMAL);
						say("Un chorro de fuego sale de una pared hacia " + capitalize(TP->QueryRealName()) + " y le da parcialmente.\n",TP);
						TP->Defend(20,DT_FIRE,DEFEND_NOMSG);
					}
				else if (skill < 0 && skill >= -25)
					{
						write(TC_RED+"Una llamarada sale de una de las paredes y te calienta un poco.\n"+TC_NORMAL);
						say("Un chorro de fuego sale de una pared hacia " + capitalize(TP->QueryRealName()) + " y le calienta un poco.\n",TP);
						TP->Defend(10,DT_FIRE,DEFEND_NOMSG);
					}
				else
					{
						write(TC_RED+"Una llamarada sale de una de las paredes y está a punto de quemarte, has tenido suerte.\n"+TC_NORMAL);
						say("Un chorro de fuego sale de una pared hacia " + capitalize(TP->QueryRealName()) + " y está a punto de alcanzarle.\n",TP);
					}
				break;
			case 2: /* rocas */
				//SetDieMsg("#jug# ha muerto aplastado por unas rocas.");
				skill = random(220) -100;
				play_sound(environment(TP), SND_SUCESOS("desprendimiento"));
				if (skill < -75)
					{
						write(TC_PURPLE+"Unas rocas se desprenden y todas caen sobre ti.\n"+TC_NORMAL);
						say("Unas rocas se desprenden y todas caen sobre " + capitalize(TP->QueryRealName()) + ".\n",TP);
						TP->Defend(30,DT_BLUDGEON,DEFEND_NOMSG);
					}
				else if (skill < -25 && skill >= -75)
					{
						write(TC_PURPLE+"Unas rocas se desprenden y algunas caen sobre ti.\n"+TC_NORMAL);
						say("Unas rocas se desprenden y algunas caen sobre " + capitalize(TP->QueryRealName()) + ".\n",TP);
						TP->Defend(20,DT_BLUDGEON,DEFEND_NOMSG);
					}
				else if (skill < 0 && skill >= -25)
					{
						write(TC_PURPLE+"Unas rocas se desprenden y te rozan.\n"+TC_NORMAL);
						say("Unas rocas se desprenden y rozan a " + capitalize(TP->QueryRealName()) + ".\n",TP);
						TP->Defend(10,DT_BLUDGEON,DEFEND_NOMSG);
					}
				else
					{
						write(TC_PURPLE+"Unas rocas se desprenden justo delante de ti.\n"+TC_NORMAL);
						say("Unas rocas se desprenden justo delante de " + capitalize(TP->QueryRealName()) + ".\n",TP);
					}
				break;
			case 3: /* lanzas */
				//SetDieMsg("#jug# ha muerto ensartado en una trampa de lanzas.");
				skill = TP->UseSkill(HAB_SALTAR,60);
				play_sound(environment(TP), SND_SUCESOS("lanza"), 0, 100, d2(2));
				if (skill < -75)
					{
						write(TC_YELLOW+"Unas lanzas se disparan sobre ti ensartándote.\n"+TC_NORMAL);
						say(capitalize(TP->QueryRealName()) + " activa una trampa y unas lanzas le ensartan.\n",TP);
						TP->Defend(30,DT_PIERCE,DEFEND_NOMSG);
					}
				else if (skill < -25 && skill >= -75)
					{
						write(TC_YELLOW+"Unas lanzas se disparan sobre ti haciéndote daño.\n"+TC_NORMAL);
						say(capitalize(TP->QueryRealName()) + " activa una trampa y unas lanzas le hacen daño.\n",TP);
						TP->Defend(20,DT_PIERCE,DEFEND_NOMSG);
					}
				else if (skill < 0 && skill >= -25)
					{
						write(TC_YELLOW+"Unas lanzas se disparan sobre ti rozándote.\n"+TC_NORMAL);
						say(capitalize(TP->QueryRealName()) + " activa una trampa y unas lanzas le rozan.\n",TP);
						TP->Defend(10,DT_PIERCE,DEFEND_NOMSG);
					}
				else
					{
						write(TC_YELLOW+"Unas lanzas se disparan sobre ti pero las esquivas con un gran salto.\n"+TC_NORMAL);
						say(capitalize(TP->QueryRealName()) + " activa una trampa de lanzas y las esquiva con un gran salto.\n",TP);
					}
				break;
			default: break;
		}
	}
}