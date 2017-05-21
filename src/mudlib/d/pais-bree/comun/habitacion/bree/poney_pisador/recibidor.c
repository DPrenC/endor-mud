/*
Fichero: recibidor.c
Autor: aul�
Fecha: 15/03/2013
Descripci�n:  recibidor del Poney Pisador. 
*/
#include "./path.h"
inherit BREE_ROOM;
#include <moving.h>
#include <sounds.h>

string f_sonidos(){
    switch(d20(2)){
        case 1:        	return "Alguien golpea ruidosamente la mesa con una jarra "
        	"mientras grita pidiendo m�s cerveza\n";
        	case 2:
        		return "Resuena El estruendo de una monta�a de cacharros que se derrumba acompa�ado una retah�la  de blasfemias.\n";
        		case 3:
        			return "Oyes como alguien grita pidiendo vino.\n";
        			case 4:
        				return "Escuchas unos pasos en el piso de arriba.\n";
        				        				case 5:
        					return "Oyes que alguien grita en la cocina. �Eh, t�, pela algunas patatas m�s";
        					case 6:
        						return "Una puerta se cierra en alg�n lugar de la posada.\n";
        						case 7:
        							return "Oyes el sonido de cacerolas que entrechocan entre s�.\n";
        							case 8:
        								return "Alguien grita desde la sala com�n: �S�, trae un poco m�s de pan!\n";
        								case 9:
        									return "Escuchas un coro de risotadas procedente del oeste.\n";
        									case 10:
        										return "Oyes los golpes de un machete de cocina cortando carne.\n";
        										case 11:
        											return "Alguien grita en la cocina: �Llevad otra hogaza y un cuenco de sopa a la mesa de la esquina!\n";
        											case 13:
        												return "Alguien grita desde la cocina: �traed algunas cebollas y una cabeza de ajos!\n";
        												case 14:
        													return "Alguien grita desde la cocina: �Llevadle al montaraz del rinc�n una jarra de cerveza y una porci�n de queso con pan!\n";
        													case 15:
        														return "Un coro de voces se alza entonando una alegre canci�n de taberna.\n";
        														case 16:
        															return "Oyes que alguien llama desde el exteriorr "
        															"de la posada.\n";
        															case 17:
        																return "Alguien grita:traed   un tonel de vino de la bodega! �Por el amor del cielo, no puedo estar a todo a la vez!\n";
        																case 18:
        																return "Oyes el estruendo de le�os que son arrojados al fuego en la cocina.\n";
        																case 19:
        																return "Alguien grita en la cocina: �Llevad dos bandejas de carne, un queso de oveja y cinco jarras grandes de cerveza a los enanos de la mesa junto a la chimenea!\n";
        																	case 20:
        																		return "Alguien silba alegremente en la cocina.\n";
        																		case 21:
        																			return "Alguien grita desde la cocina: �Abrid otro par de barriles y sacad una olla de carne asada... y el queso de oveja grande! Ah... y el jam�n de la esquina! Tengo una maldita tropa de enanos hambrientos e impacientes esperando!\n";
        																			case 22:
        																				return "Alguien grita desde el este: �Cebadilla, �d�nde est� esa cerveza? �tenemos sed!\n";
        																				
 }
    return "";
}

string f_olores(){
    switch(d6()){
        case 1:
return "Huele a patatas asadas.\n";
case 2:
	return "Te llega una vaharada a pan reci�n horneado.\n";
	case 3:
		return "El olor a carne asada invade tus fosas nasales.\n";
		case 4:
			return "Hueles a sopa reci�n hecha.\n";
			case 5:
				return "Te llega olor a humo de le�a.\n";
			    }
    return "";
}


public int ir_cocina(){
write("Te internas en el c�lido ambiente de la cocina.\n");
    
    say(CAP(TNAME)+" entra en la cocina.\n");
    TP->move( HABITACION+"bree/poney_pisador/cocina1", M_SILENT);
    return 1;
}

create()
{
    ::create();
    	SetIntShort("entrada de la posada");
    	SetIntLong("Est�s en una especie de recibidor a cuyo alrededor se distribuyen "
    	"las dependencias de la posada del Poney Pisador.\n"
    	"El lugar est� iluminado por un par de faroles que cuelgan de la pared y por "
    	"la luz del fuego que viene de las puertas del este y el oeste.\n"
    	"El interior del edificio est� cuidado y bien constru�do, con pulidas vigas de "
    	"roble, limpios suelos de piedra y muros bien encalados.\n"
    	"Al sur se sale de la posada, al norte se extiende un pasillo, al este vislumbras "
    	"el interior de la cocina  y al oeste una nube de humo de tabaco, voces y risas "
    	"da a entender que hacia esa direcci�n se encuentra la sala com�n.\n");
    	AddDetail(({"cocina", "este"}),
    	"Desde aqu� atisbas el gran traj�n de la cocina de la posada.\n");
    	AddDetail(({"oeste", "sala", "sala comun", "sala com�n"}),
    	"Tras una amplia puerta siempre abierta y sostenida con tacos de madera, observas "
    	"una conglomeraci�n de mesas y bancos en los que se aposenta una variada "
    	"concurrencia de vagas figuras borrosas envueltas en una nube de humo de tabaco y "
    	"le�a. La sala est� iluminada por la d�bil luz de algunos faroles y el intenso "
    	"fulgor de un gran fuego.\n");
    AddDetail(({"norte", "pasillo"}),
    "Al norte un pasillo en penumbra se aleja hacia los aposentos interiores de la "
    "posada. La amortiguada luz de alg�n farol lo ilumina.\n");
    AddDetail(({"sur", "entrada"}),
    "Una gran puerta da acceso al patio de la posada");
             SetIntSmell(SF(f_olores));
            SetIntNoise(SF(f_sonidos));
    	    SetIndoors(1);
    SetIntBright(30);
                SetSoundEnvironment(SOUND_AMBIENTES("taberna"),10);

    	    AddExit("sur", "./arcada");
     AddExit("este", SF(ir_cocina));
     AddExit("oeste", "./salacomun1");
     AddExit("norte", "./pasillo1");
     AddDoor("sur", "la puerta de la posada",
     "Es una gran puerta de s�lidos tablones perfectamente encajados entre s� y cuya "
     "superficie pulimentada no denota la indudable antig�edad de su construcci�n.\n"
     "Mir�ndola desde este lado puedes ver un par de peque�as mirillas para atisbar el "
     "exterior, situadas a la altura de un hobbit y un humano respectivamente.\n",
     ({"puerta", "puerta del sur", "s", "sur"}));
      
    }
    
    
    
     


     public void init()
     {
        ::init();
            call_out("entrada");
	}

	public void entrada(){
		switch(d20(2)){
			case 1:
				tell_room(TO, "Un hombre borracho llega del este y sale tambale�ndose de la "
				"posada.\n");
				break;
				tell_room(TO, "Estalla una agria discusi�n en la cocina.\n");
				break;
				case 3:
					tell_room(TO, "Alguien grita: �aparta hombre! �no ves que voy cargado??"
					"Un hombre gordo sale de la cocina y entra en la sala com�n cargado con una "
					"bandeja colmada de jarras.\n");
					break;
						case 4:
						tell_room(TO, "Alguien grita en la cocina: �Sacad otro barril de la bodega!\n");
						break;
						case 5:
							tell_room(TO, "Los ecos de una canci�n coreada por el entrechocar de "
							"jarras y cubiertos sobre las mesas resuena al oeste de aqu�.\n");
							break;
							case 6:
								tell_room(TO, "Un enano entra en la posada y se va hacia el este.\n");
								break;
								case 7:
									tell_room(TO, "Alguien silba una canci�n en la cocina mientras los golpes de un machete partiendo una pieza de carne resuenan met�dicamente.\n");
									break;
									case 8:
										tell_room(TO, "Unos hombres salen de la sala com�n y se alejan por el pasillo charlando y riendo.\n");
										break;
										case 9:
											tell_room(TO, "Alguien grita: �Hay que preparar dos habitaciones "
											"en la primera planta de el ala sur!\n");
   break;
   case 10:
   	tell_room(TO, "Alguien grita: �Est�n ya listas esas s�banas limpias?\n");
   	break;
   	case 11:
   		tell_room(TO, "Alguien grita: �Hay que preparar unas cuantas habitaciones m�s... "
   		"tenemos aqu� una tropa de enanos que necesita albergue!\n");
   		break;
   		 case 12:
   			tell_room(TO, "Se escuchan las apresuradas pisadas de alguien en el planta de "
   			"arriba.\n");
   			break;
   			case 13:
   				tell_room(TO, "Alguien grita: �eh, Nob!�d�nde est�s, camastr�n de pies lanudos?\n");
   				break;
   				case 14:
   					tell_room(TO, "Un hombre gordo y calvo sale corriendo de la sala com�n y "
   					"entra en la cocina dando �rdenes.\n");
   					break;
   					case 15:
   						tell_room(TO, "Un mozo de la posada llega de fuera cargando un enorme "
   						"cesto repleto de le�a y entra en la cocina.\n");
   						break;
   						case 16:
   							tell_room(TO, "Un mozo de la posada llega del exterior cargando un "
   							"barril de cerveza y entra en la cocina, resoplando.\n");
   							break;
   							case 17:
   								tell_room(TO, "Un grupo de hobbits llega de fuera y entra en la sala com�n.\n");
   								break;
   								case 18:
   									tell_room(TO, "Un hombre y un hobbit salen charlando de la posada.\n");
   									break;
   									case 19:
   										tell_room(TO, "Un hombre gordo y calvo pasa corriendo a tu lado cargado con una bandeja llena de fuentes humeantes y desaparece en la nube de humo de la sala com�n.\n");
   										break;
   										case 20:
   											tell_room(TO, "Un viejo aldeano entra en la posada y se va "
   											"renqueando hacia la sala com�n.\n");
   											break;
   											case 21:
 tell_room(TO, "Alguien grita desde el este: �Ja, ja, ja.. no sabes beber!\n");
   												break;
   												case 22:
   													tell_room(TO, "Se escucha un portazo en la distancia.\n");
   													break;


					}
					return;

			}