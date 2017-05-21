/*
Fichero: cocina2.c
Autor: aulë
Fecha: 18/03/2013
Descripción:  cocina del Poney Pisador. 
*/
#include "./path.h"
inherit BREE_ROOM;
#include <moving.h>


string f_sonidos(){
    switch(d20(2)){
        case 1:        	return "Se escucha el rítmico golpeteo de un mortero machacando algo.\n";
        	case 2:
        		return "Resuena El estruendo de una montaña de cacharros que se derrumba acompañado una retahíla  de blasfemias.\n";
        		case 3:
        			return "Se escucha el ruido de desperdicios cayendo en el barril de la "
        			"esquina.\n";
        			case 4:
        				return "Alguien exclama: ¡maldita sea... esta olla abrasa!\n";
        				        				case 5:
        					return "Alguien grita: ¡Eh, tú, pela algunas patatas más";
        					case 6:
        						return "Se escucha el tintineo de de cubiertos que son colocados en una valda.\n";
        						case 7:
        							return "Oyes el sonido de cacerolas que entrechocan entre sí.\n";
        							case 8:
        								return "Alguien grita: ¡traed más leña!\n";
        								case 9:
        									return "Alguien grita: ¡atizad el fuego... esa carne va a cocerse en vez de asarse!.\n";
        									case 10:
        										return "Oyes los golpes de un machete de cocina cortando carne.\n";
        										case 11:
        											return "Alguien grita: ¡Llevad otra hogaza y un cuenco de sopa a la mesa de la esquina!\n";
        											case 13:
        												return "Alguien grita: ¡traed algunas cebollas y una cabeza de ajos!.\n";
        												case 14:
        													return "Alguien grita: ¡Llevadle al montaraz del rincón una jarra de cerveza y una porción de queso con pan!\n";
        													case 15:
        														return "Un coro de voces se alza entonando desde la "
        														"sala común una alegre canción de taberna.\n";
        														case 16:
        															return "Oyes que alguien llama desde el patio.\n";
        															case 17:
        																return "Alguien grita:traed   un tonel de vino de la bodega! ¡Por el amor del cielo, no puedo estar a todo a la vez!\n";
        																case 18:
        																return "Oyes el estruendo de leños que son arrojados al fuego.\n";
        																case 19:
        																return "Alguien grita: ¡Llevad dos bandejas de carne, un queso de oveja y cinco jarras grandes de cerveza a los enanos de la mesa junto a la chimenea!\n";
        																	case 20:
        																		return "Alguien silba alegremente mientras "
        																		"machaca algo en un mortero.\n";
        																		case 21:
        																			return "Alguien grita: ¡Abrid otro par de barriles y sacad una olla de carne asada... y el queso de oveja grande! Ah... y el jamón de la esquina! Tengo una maldita tropa de enanos hambrientos e impacientes esperando!\n";
        																			case 22:
        																				return "Alguien grita: ¡Preparad otras "
        																				"seis jarras de cerveza negra!\n";
        																				
 }
    return "";
}

string f_olores(){
    switch(d6()){
        case 1:
return "Huele a patatas asadas.\n";
case 2:
	return "Huele a pan recién horneado.\n";
	case 3:
		return "El olor a carne asada invade tus fosas nasales.\n";
		case 4:
			return "Hueles a sopa recién hecha.\n";
			case 5:
				return "Huele a nabos con mantequilla.\n";
			    }
    return "";
}


create()
{
    ::create();
    	SetIntShort("cocina de la posada");
    	SetIntLong("La cocina del Poney Pisador es una larga estancia cuyas ventanas dan "
    	"al patio situado entre ambas alas de la posada.\n"
    	"Largas valdas recorren las paredes a diferentes alturas sobre mesetas de piedra "
    	"pulida y una larga mesa recorre la zona central. El enfebrecido trajín que se "
    	"desarrolla a tu alrededor se une al intenso calor que mana de los fogones.\n"
    	"En la pared este hay una puerta de la que de vez en cuando sale alguien cargado "
    	"con alimentos, botellas o algún barril repleto.\n");
    	
    	    	    	AddDetail("ventanas",
    	"A través de las ventanas ves el patio con una gran pila de leña y algunos barriles vacíos.\n");
    AddDetail(({"utensilios", "utensilios de cocina"}),
    "Cazos, cacerolas, ollas de todos los tamaños, cuchillos, tenedores, cucharas, cucharones "
    "y demás instrumentos de cocina cuelgan de las paredes y reposan sobre la mesa "
    "central y las diversas mesetas de las paredes.\n");
    AddDetail(({"pared", "muro", "muros", "paredes"}),
    "Las paredes de piedra están encaladas y la condensación las humedece.\n");
    AddDetail("techo",
    "Pese a estar encalado, distingues gruesas vigas de roble que lo recorren y la "
    "humedad producida por la condensación del ambiente que lo recubre.\n");
    AddDetail("valdas",
    "Largos tablones sujetos en los muros soportan gran cantidad de utensilios de cocina.\n");
    AddDetail("mesa",
    "Una gran mesa de roble de pulida superficie recorre la parte central de la cocina y "
    "sirve para que el personal elabore y prepare comidas y bebidas.\n");
  AddDetail(({"trajin", "trajín"}),
  "Pinches, mozos y demás personal van de aquí para allá portando comida y bebida, "
  "pelando patatas, cortando carne y preparando platos en un bullicioso trajín.\n");
  AddDetail("meseta",
  "Son largas losas de piedra pulida que surgen de los muros y que sirven para que el "
  "personal  prepare los platos y bebidas y apoye los diversos utensilios de cocina.\n");
  AddDetail("faroles",
  "Dos grandes faroles de aceite cuelgan del techo proporcionando una suave luz a "
  "través de sus vidrios empañados.\n");
  AddDetail("fogones",
  "Los troncos rugen bajo los fogones sobre los que cuelgan un par de enormes ollas y un "
  "espetón de carne. La luz y el calor manan del fuego calentando toda la cocina y provocando condensación sobre las paredes y el techo.\n");
  AddDetail("ollas",
  "Un par de enormes ollas cuelgan sobre el fuego. Una parece contener sopa humeante y "
  "otra carne guisada.\n");
AddDetail(({"espeton", "espetón", "espetón de carne", "carne"}),
  "Un gran pedazo de carne se asa lentamente al fuego, ensartada en una larga vara "
  "metálica.\n");
  AddDetail("suelo",
  "El suelo está cubierto de losetas de piedra de superficie irregular para evitar los "
  "resbalones debidos a la humedad producida por la condensación.\n");
    	    SetIndoors(1);
    SetIntBright(30);
                 SetIntSmell(SF(f_olores));
            SetIntNoise(SF(f_sonidos));
     AddExit("oeste", "./cocina1");
     AddExit("este", "./despensa");
     AddDoor("este", "la puerta de la despensa",
     "Es una vieja puerta de madera, baja y ancha, con un sencillo pestillo para "
     "cerrarla y una argolla de hierro para abrirla y sujetarla a la pared, "
     "evitando que se cierre.\n"
     "El calor de los fogones de la cocina ha abombado y desconchado su superficie.\n",
     ({"e", "este", "despensa", "puerta de la despensa", "puerta"}));
    }
    


    
    
    
     


     public void init()
     {
        ::init();
            call_out("entrada");
	}

	public void entrada(){
		switch(d20(2)){
			case 1:
				tell_room(TO, "Un pinche de cocina pela patatas y las deja caer en una pequeña cesta.\n");
				break;
				tell_room(TO, "Estalla una agria discusión entre dos mozos de la posada que se estorban en su trabajo.\n");
				break;
				case 3:
					tell_room(TO, "Un hombre gordo y calvo entra corriendo en la cocina, coge una "
					"gran bandeja colmada de jarras yplatos y se va corriendo hacia el este.\n");
					break;
						case 4:
						tell_room(TO, "Alguien grita: ¡Sacad otro barril de la bodega!\n");
						break;
						case 5:
							tell_room(TO, "Los ecos de una canción coreada por el entrechocar de "
							"jarras y cubiertos sobre las mesas resuena al oeste de aquí.\n");
							break;
							case 6:
								tell_room(TO, "Un hobbit de la posada echa una brazada de leña al fuego.\n");
								break;
								case 7:
									tell_room(TO, "Alguien silba una canción en la cocina al ritmo de los golpes de un machete partiendo una pieza de carne.\n");
									break;
									case 8:
										tell_room(TO, "Un par de hobbits salen de la bodega cargando un barril y un jamón curado.\n");
										break;
										case 9:
											tell_room(TO, "Alguien grita: ¡otro cuenco de sopa para los forasteros del sur!\n");
   break;
   case 10:
   	tell_room(TO, "Alguien grita: ¡Lavad esa pila de platos, casi no quedan limpios!\n");
   	break;
   	case 11:
   		tell_room(TO, "Alguien grita: ¡Preparad un queso curado y cinco platos de carne asada para esos hombres de Archet!\n");
   		break;
   		 case 12:
   			tell_room(TO, "Se escuchan las apresuradas pisadas de alguien en el planta de "
   			"arriba.\n");
   			break;
   			case 13:
   				tell_room(TO, "Alguien grita: ¡eh, Nob!¿dónde estás, camastrón de pies lanudos?\n");
   				break;
   				case 14:
   					tell_room(TO, "Un gran ajetreo se desarrolla a tu alrededor.\n");
   					break;
   					case 15:
   						tell_room(TO, "Un mozo de la posada llega de fuera cargando un enorme "
   						"cesto repleto de leña y alimenta el fuego con unos cuantos troncos.\n");
   						break;
   						case 16:
   							tell_room(TO, "Un mozo de la posada llega del exterior cargando un "
   							"barril de cerveza y entra en la despensa, resoplando por el esfuerzo.\n");
   							break;
   							case 17:
   								tell_room(TO, "Un joven pinche remueve el contenido de una de las ollas para evitar que se queme.\n");
   								break;
   								case 18:
   									tell_room(TO, "Un pinche hobbit sazona la olla de carne que se guisa sobre el  fuego.\n");
   									break;
   									case 19:
   										tell_room(TO, "Un hombre gordo y calvo pasa corriendo a tu lado cargado con una bandeja llena de fuentes humeantes.\n");
   										break;
   										case 20:
   											tell_room(TO, "Un pinche pica una cebolla sobre la mesa central.\n");
   											break;
   											case 21:
 tell_room(TO, "Un pinche machaca ajos en un mortero mientras silba alegremente.\n");
   												break;
   												case 22:
   													tell_room(TO, "Un joven pinche da vueltas al espetón de "
   													"carne que se asa sobre los fogones.\n");
   													break;


					}
					return;

				}