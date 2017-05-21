/*
Fichero: bpasillo.c
Autor: aul�
Fecha: 31/03/2013
Descripci�n:  base de los pasillos de la posada.
*/
#include "./path.h"
inherit BREE_ROOM;
#include <moving.h>


string f_sonidos(){
    switch(d20()){
    case 1:
    	return "Oyes un portazo en la planta inferior.\n";
    	case 2:
    		return "Se oyen r�pidas pisadas en una de lashabitaciones contiguas.\n";
    		case 3:
    			return "Oyes voces roncas que discuten en una de las habitaciones.\n";
    			case 4:
    				return "Oyes risas lejanas procedentes de la sala com�n.\n";
    				case 5:
    					return "Escuchas los apresurados pasos de alguien que corre por otra "
    					"parte del pasillo.\n";
    					case 6:
    						return "Escuchas los ecos de una lejana canci�n de taberna.\n";
    						case 7:
    							return "Oyes como un mueble es arrastrado en una de las habitaciones contiguas.\n";
    							case 8:
    								return "Oyes ronquidos procedentes de det�r�s de una de las puertas del pasillo.\n";
    								case 9:
    return "Una puerta se abre y cierra cerca de aqu�.\n";
    case 10:
    	return "Escuchas como alguien abre una puerta con llave.\n";
    	case 11:
    		return "Escuchas toses y carraspeos que vienen de una de las puertas del "
    		"pasillo.\n";
    		case 12:
    			return "Escuchas como uno de los faroles que iluminan el pasillo chisporrotea suavemente.\n";
    			case 13:
    				return "Se escucha el estropicio de algo met�lico que cae al suelo en una de "
    				"las habitaciones, seguido de un horrendo chorro de blasfemias.\n";
    			case 14:
    				return "Alguien silba alegremente en una de las habitaciones.\n";
    				case 15:
    					return "El suelo de madera cruje suavemente cuando alguien camina por una habitaci�n contigua.\n";
    					case 16:
    						return "Alguien cierra una puerta con llave cerca de aqu�.\n";
 }
    return "";
}

string f_olores(){
    switch(d6()){
        case 1:
    return "Hueles a madera antigua.\n";
    case 2:
    	return "Hueles a mantas de lana y s�banas limpias.\n";
    	case 3:
    		return "Te llega un leve olor a comida.\n";
    		case 4:
    			return "Hueles al aceite de los faroles.\n";
    			case 5:
    				return "Te llega un leve olor a humo de le�a.\n";
}
    return "";
}



create()
{
    ::create();
    	SetIntShort("un pasillo");
    	    switch(d4()){
        case 1:
            SetIntLong("Te encuentras en un largo pasillo que recorre una de las "
            "plantas de la posada del Poney Pisador.\n"
            "A ambos lados se encuentran las puertas de las distintas habitaciones para "
            "hu�spedes. El suelo de madera, aunque envejecido por los largos a�os, "
            "aparece limpio y pulimentado y tanto las paredes encaladas como el techo "
            "soportado por gruesas vigas de roble, presentan un aspecto hogare�o y "
            "acogedor.\n");
            break;
            case 2:
            	SetIntLong("El largo pasillo por el que avanzas recorre una de las plantas "
            	"de la posada destinada al alojamiento de los viajeros que en ella se "
            	"hospedan.\n"
            	"A ambos lados se distribuyen las puertas de las habitaciones y todo "
            	"presenta un aspecto limpio y cuidado, aunque peque�os detalles revelan "
            	"que se trata de una construcci�n antigua.\n");
            	AddDetail("detalles",
            	"El crujido del suelo al moverte, lo pulido de la tablaz�n por el roce de "
            	"incontables pies, el liger�simo abombamiento del techo y el "
            	"oscurecimiento de las vigas denuncian la antig�edad de la posada.\n");
            	break;
            	case 3:
            		SetIntLong("Est�s en un largo pasillo de techo alto sostenido por "
            		"oscuras vigas, pulidos de madera y muros encalados.\n"
            		"A ambos lados se distribuyen las puertas que dan acceso a las "
            		"habitaciones en las que se hospedan los viajeros que llegan al "
            		"Poney Pisador.\n"
            		"De una viga situada sobre tu cabeza pende un farol que ilumina los "
            		"alrededores.\n");
            		AddDetail("farol",
            		"Es un gran farol constituido por un armaz�n met�lico cubierto por "
            		"gruesos vidrios.\n");
            		break;
            		case 4:
            			SetIntLong("Las dos plantas superiores de la posada est�n destinadas a "
            			"las habitaciones para hu�spedes. Anta�o el Poney Pisador sol�a estar "
            			"ocupada en forma casi continua pero con la disminuci�n del tr�fico "
            			"por los caminos, ahora sus largos pasillos suelen mantenerse en "
            			"silencio, aunque tanto el suelo de madera como las paredes encaladas "
            			"y el alto techo de vigas presentan un aspecto cuidado y limpio.\n"
            			"A ambos lados se localizan las puertas de las habitaciones y junto a "
            			"una de ellas ves un gancho en la pared.\n");
            			AddDetail("gancho",
            			"Es un gancho de hierro curvado del que podr�a colgarse un petate o "
            			"alguna prenda de vestir.\n");
            			break;
            			case 5:
            				SetIntLong("El silencio del largo pasillo en que te encuentras se ve "
            				"solo interrumpido por las pisadas de alg�n hu�sped y el lejano "
            				"sonido de risas y canciones procedentes de la sala com�n.\n"
            				"Todo presenta un aspecto limpio y cuidado, con el suelo de gruesa "
            				"madera y las vigas de roble que sostienen el alto techo muy "
            				"pulimentadas y las paredes bien encaladas.\n"
          "Las puertas de las habitaciones se alinean a ambos lados y puedes ver que una "
          "de las tablas del suelo est� algo levantada con respecto al resto.\n");
          AddDetail(({"suelo", "tabla"}),
          "Uno de los gruesos tablones que conforman el suelo se ha arqueado durante los "
          "largos a�os en los que lleva colocado en la tablaz�n del suelo y al pisarlo "
          "roza con los tablones cercanos emitiendo un profundo crujido.\n");
          break;
          SetIntLong("Un largo pasillo recorre esta planta de la posada conectando las "
          "distintas habitaciones para hu�spedes.\n"
          "A ambos lados se alinean numerosas puertas. El suelo de madera, las altas "
          "vigas del techo y las paredes encaladas dan al lugar un aspecto acogedor, "
          "antiguo pero cuidado.\n"
          "A trechos regulares, una serie de faroles de aceite cuelgan de las vigas del "
          "techo iluminando el pasillo.\n");
          AddDetail("faroles",
          "Son faroles de aceite cuyo armaz�n met�lico est� cerrado por gruesos "
          "vidrios.\n");
          break;
        }
        AddDetail(({"muros", "paredes"}),
        "Los muros est�n hechos de piedra recubierta de un compuesto de cal que los hace "
        "adquirir un color blanquecino.\n");

AddDetail("puertas",
"Resistentes puertas de madera que se alinean a lo largo del pasillo y dan acceso a las distintas habitaciones.\n");
AddDetail("suelo",
"El suelo est� formado por tablas de roble bien pulidas que se ensamblan entre s�.\n");
AddDetail("techo",
"El techo ligeramente oscurecido por el tiempo est� soportado por fuertes vigas de roble de las que atrechos equidistantes cuelgan faroles de aceite que iluminan el pasillo.\n");
AddDetail("vigas",
"Pesadas vigas de roble oscurecidas por el tiempo que soportan el techo.\n");
    	    SetIndoors(1);
    SetIntBright(25);
        SetIntSmell(SF(f_olores));
            SetIntNoise(SF(f_sonidos));

 }




     public void init()
     {
        ::init();
            call_out("entrada");
	}

	public void entrada(){
		switch(d20(2)){

				case 5:
				tell_room(TO, "Un hombre alto vestido en tonos pardos pasa a tu lado y entra en una de las habitaciones.\n");
				break;
				case 8:
					tell_room(TO, "Alguien tose y carraspea en una de las habitaciones.\n");
					break;
					case 11:
						tell_room(TO, "Se escuchan ronquidos en una de las habitaciones.\n");
						break;
						case 13:
							tell_room(TO, "�speras voces discuten en una de las habitaciones.\n");
							case 15:
								tell_room(TO, "El arrastrar de algo pesado se escucha procedente de una de las habitaciones.\n");
								break;
								case 17:
									tell_room(TO, "Se escucha un largo y perezoso bostezo procedente de una habitaci�n cercana.\n");
									break;
									case 19:
										tell_room(TO, "Un gato pasa raudo como una flecha roz�ndote las piernas.\n");
										break;
										case 22:
											tell_room(TO, "Un gato maulla en alg�n lugar de la posada.\n");
											break;
											case 25:
												tell_room(TO, "El suelo cruje cuando alguien camina en una de las habitaciones.\n");
												break;
												case 27:
													tell_room(TO, "La puerta de una habitaci�n se abre y un grupo de enanos sale y se aleja charlando y refunfu�ando.\n");
													break;;
													case 28:
														tell_room(TO, "Unos enanos pasan junto a ti y entran en una habitaci�n cerrando de un portazo.\n");
														break;
														case 30:
															tell_room(TO, "Un hobbit pasa al trote, casi enterrado bajo la brazada de mantas de lana con la que carga.\n");
															break;
															case 32:
																tell_room(TO, "Un enano llega y se aleja caminando por el pasillo.\n");
																break;
																case 35:
																	tell_room(TO, "Alguien grita cerca de aqu�: �Hay que traer m�s mantas para esta cama!\n");
				  													break;
case 39:
				tell_room(TO, "Un hombre malencarado sale de una de las habitaciones y se aleja pasillo adelante.\n");
				break;

					}
					return;

				}