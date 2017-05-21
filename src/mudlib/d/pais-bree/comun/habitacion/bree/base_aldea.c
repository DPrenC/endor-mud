/*
Fichero: bbase_aldea.c
Autor: aulë
Fecha: 22/09/2014
Descripción:  base de las rooms externas de la aldea de Bree.
*/
#include "./path.h"
inherit BREE_ROOM;
#include <moving.h>
#include <sounds.h>



string f_sonidos(){
    switch(d20(2)){

    	case 2:
    		return "Unas gallinas cloquean en un corral cercano.\n";
    		case 3:
    			return "Alguien llama a lo lejos.\n";
    			case 4:
    				return "Se escucha el estridente canto de un gallo.\n";
    				case 5:
    					return "Un gato maulla melancólicamente.\n";
    					case 6:
    						return "Una ventana se cierra en una de las casas.\n";
    						case 7:
    							return "Unos lechones chillan y alborotan en una pocilga cercana.\n";
    							case 8:
    								return "Un burro rebuzna perezosamente en una cuadra cercana.\n";
    								case 9:
    return "Una puerta se abre y cierra en una de las casas.\n";
    case 10:
    	return "Alguien llama en una de las casas y otra voz contesta un poco más lejos.\n";
    	case 11:
    		return "Un perro ladra furiosamente y una voz ruda le ordena callar.\n";
    		case 12:
    			return "Una vaca muge mansamente en un establo cercano.\n";
    			case 13:
    				return "Alguien blasfema y a continuación se escucha alboroto de aves desde uno de los corrales cercanos.\n";
    			case 14:
    				return "Unos gansos graznan.\n";
    				case 15:
    					return "Alguien grita: ¡Maldita sea, ierra la puerta cuando salgas o la "
    					"corriente apagará el fuego!.\n";
    					case 16:
    						return "Una voz femenina se alza cerca de aquí canturreando una canción popular.\n";
    						    case 20:
    	return "Oyes un portazo a lo lejos.\n";
    	case 21:
    		return "Oyes como alguien silba mientras martillea algo cerca de aquí.\n";
    		case 22-24:
    			return "Un bebé llora desconsoladamente cerca de aquí.\n";
    			case 25:
    				return "Unas ovejas balan en un establo de las cercanías.\n";
    				case 26:
    					return "Unos cerdos gruñen y chillan.\n";
    					case 27:
    						return "escuchas una furibunda pelea de gatos detrás de una de las casas.\n";
    						case 28:
    							return "El viento susurra en los aleros de un tejado.\n";
    							case 29:
    								return "Una suave brisa hace suspirar las hierbas.\n";
    								case 30:
    									return "Se oyen los rítmicos golpes de una azada cavando la tierra de un huerto cercano.\n";
    									case 31:
    										return "La risa de una mujer joven llega procedente del piso superior de una casa cercana.\n";
    										case 32:
    											return "Alguien tose y carraspea ásperamente en una casa cercana.\n";
    											case 33:
    												return "Se escucha el pesado rascar de una pala sobre el suelo de piedra.\n";
    												case 34:
    													return "Un ternero muge mansamente.\n";
    													case 35:
    														return "Una voz masculina azuza al ganado.\n";
    														case 36:
    															return "Unos polluelos pían cerca de aquí.\n";
    															case 37:
    																return "Escuchas el ladrido de un perro de gran tamaño.\n";
    																case 38:
    																	return "Un caballo relincha cerca de aquí.\n";
    									
 }
    return "";
}

string f_olores(){
    switch(d6()){
        case 1:
    return "Huele a estiércol de vaca.\n";
    case 2:
    	return "Te llega una vaharada de olor a ovejas.\n";
    	case 3:
    		return "Una ráfaga de aire trae olor a pan recién hecho y guiso de carne.\n";
    		case 4:
    			return "Huele a humo de leña.\n";
    			case 5:
    				return "Te llega el dulce olor de tarta recién sacada del horno.\n";
}
    return "";
}



create()
{
    ::create();
    	SetIntShort("una callejuela de Bree");
    	SetIntLong(
    	"Estás en una de las callejuelas que recorren la aldea de Bree, ascendiendo la "
    	"ladera de la colina  entre las casas de piedra de los Hombres y los agujeros de "
    	"los Hobbits. La aldea se acurruca contra la alta colina y allá abajo distingues la "
    	"empalizada y el foso que la defienden.El suelo es irregular y algunos hierbajos "
    	"crecen en los intersticios\n");
    	AddDetail(({"casas", "casas de piedra", "casas de hombres"}),
    	"Las casas en que habitan los hombres de Bree son sólidos edificios de muros de "
    	"piedra, más o menos tallada, sacada de la misma ladera de la colina. Muchas son "
    	"de una sola planta pero algunas aprovechan el plano inclinado de la aldea para "
    	"tener dos o incluso tres pisos, estando a veces parte de los mismos socavada en la "
    	"ladera. El tejado suele ser a dos aguas no escesivamente inclinadas y en su mayor "
    	"parte las cubiertas son de tejas pardas.\n"
    	"Casi todas disponen de un pequeño jardín delantero y muchas cuentan con un huerto, "
    	"establo u otros edificios anexos.\n");
    	AddDetail(({"agujeros", "agujeros hobbits", "smials", "agujeros-hobbit"}),
    	"En la parte más alta de la aldea, donde la ladera se empina hasta llegar casi a "
    	"la verticalidad, se distinguen unos cuantos orificios redondos. Son las puertas y "
    	"ventanas de las moradas de los hobbits de Bree.\n");
    	AddDetail(({"empalizada", "cerca", "seto"}),
    	"Una cerca de madera de la altura de un hombre  rodea en forma semicircular la "
    	"parte inferior de la aldea, reforzada por un espeso seto espinoso.Estaempalizada "
    	"cubre los flancos sur y oeste de Bree y puede ser atravesada por dos puertas de "
    	"trancas localizadas en cada uno de dichos lados.\n");
    	AddDetail(({"suelo", "piso"}),
    	"El suelo es algo irregular y está formado por un conglomerado de gravilla, "
    	"algunas piedras y tierra batida en cuyos baches se crean charcos cuando llueve.\n"
    	"En los bordes del camino y en pequeños parches ocasionales crece hierba menuda.\n");
    	AddDetail(({"hierba", "hierba menuda", "hierbajos", "hierbas"}),
    	"Unos parches de fina hierba corta y poco poblada salpican el suelo y a los "
    	"lados del camino algunos manojos de hierba más larga crecen entre la gravilla.\n");
    	AddDetail("foso"),
    	"Es una profunda zanja de bordes irregulares y en pendiente que discurre "
    	"paralela a la cerca que defiende la aldea.\n";
    	AddDetail(({"colina", "loma", "colina de bree", "colina de Bree"}),
    	"La alta colina de Bree es una masa oscura de roca cuya pendiente es suave en la "
    	"falda y se va empinándo más hasta convertirse en una serie de terrazas y "
    	"acantilados de roca que forman la ancha cumbre.\n"
    	"En torno a ella florecen las cuatro aldeas del País de Bree, hogar de hombres "
    	"y hobbits.\n");
    	        SetIntSmell(SF(f_olores));
            SetIntNoise(SF(f_sonidos));
                         SetSoundEnvironment(SOUND_AMBIENTES("aldea"), 60);


 }




     public void init()
     {
        ::init();
            call_out("entrada");
	}

	public void entrada(){
		switch(d20(3)){

				case 5:
				tell_room(TO, "Unas jovenes aldeanas pasan a tu lado charlando y riendo, "
				"cargadas con sendos cestos de ropa.\n");
				break;
				case 8:
					tell_room(TO, "Un aldeano pasa cerca, cargado con algunos aperos de labranza.\n");
					break;
					case 11:
						tell_room(TO, "Un gato blanco y negro pasa raudo como una flecha, "
						"persiguiendo algo.\n");
						break;
						case 13:
							tell_room(TO, "Unos gorriones revolotean sobre tu cabeza chachareando y peleando.\n");
							case 15:
								tell_room(TO, "Unos hobbit se alejan caminando a trompicones, riendo y "
								"hablando en voz algo más alta de lo debido. Parece que vuelven de hacer "
								"una visita al Poney.\n");
								break;
								case 17:
									tell_room(TO, "Las voces de un hombre y una mujer que discuten "
									"ágriamente llegan hasta la calle procedentes de la ventana de una "
									"casa cercana.\n");
									break;
									case 19:
										tell_room(TO, "Un perro mediano pasa a la carrera ladrando "
										"furiosamente en persecución de un gato que bufa mientras corre.\n");
										break;
										case 22:
											tell_room(TO, "Un grupo de niños hobbits y humanos pasa corriendo "
											"entre risas y gritos de alborozo.\n");
											break;
											case 25:
												tell_room(TO, "Un aldeano y su hijo pasan arreando unas cuantas "
				"ovejas hacia los pastos de las afueras de la aldea.\n");
												break;
												case 27:
													tell_room(TO, "Una regordeta mozuela hobbit te sonríe al pasar.\n");
													break;
													case 28:
														tell_room(TO, "La puerta de una de las casas se abre y un "
														"aldeano sale y se aleja calle abajo silbando entre dientes.\n");
														break;
														case 30:
															tell_room(TO, "Una vieja hobbit se cruza contigo y te "
															"lanza una afilada mirada suspicaz mientras refunfuña entre dientes.\n");
															break;
															case 32:
																tell_room(TO, "Un hobbit se aleja arreando unos cuantos "
																"gansos hacia un corral.\n");
																break;
																case 35:
																	tell_room(TO, "Alguien grita cerca de aquí: ¿cuántas veces tengo que decirte que cierres la puerta del gallinero\n");
				  													break;
case 39:
				tell_room(TO, "UUn par de viejas cotillean entre susurros a la vera del camino.\n");
				  													break;
case 40:
				tell_room(TO, "Un objeto de loza se hace pedazos y una contundente retaíla de "
				"imprecaciones surge de una ventana.\n");
								  													break;
case 41:
				tell_room(TO, "Se oyen gritos y risas infantiles en las cercanías.\n");
								  													break;
case 43:
				tell_room(TO, "Unos hombres pasan empujando una carretilla cargada de leña.\n");
								  													break;
case 45:
				tell_room(TO, "Te cruzas con una mujer hobbit de mediana edad cargada con una "
				"cesta de verduras recién arrancadas.\n");
								  													break;
case 46:
				tell_room(TO, "Alguien canta una tonada popular cerca de aquí.\n");
								  													break;
case 48:
				tell_room(TO, "Una azada ggolpetea la tierra rítmicamente cerca de aquí.\n");
								  													break;
case 49:
				tell_room(TO, "Unhombre y un hobbit se cruzan contigo y temiran con curiosidad.\n");
								  													break;
case 50:
				tell_room(TO, "El viento sisea entre las hierbas que bordean el camino.\n");
				break;
				case 51:
										tell_room(TO, "Un pájaro pasa volando sobre tu cabeza y desaparece tras un tejado.\n");
										break;
										case 52:
																tell_room(TO, "Te cruzas con un fornido granjero hobbit cargado con una brazada de largas varas de madera.\n");
																break;
																case 53:
																						tell_room(TO, "Un grupo de mozalbetes hobbit vestidos con ropas rústicas pasan charlando animadamente.\n");
																						break;
																						case 54:
																												tell_room(TO, "Un gorrión se posa en un alero cercano piando de formaintermitente.\n");
																												break;
																												case 55:
																																		tell_room(TO, "Escuchas como alguien arrea el ganado a lo lejos.\n");
																																		break;
																																		case 56:
		tell_room(TO, "Un hombre alto encapuchado y vestido con andrajosas ropas pardas"
		"pasa a tu lado a grandes trancos.\n");
		break;
		case 57:
			tell_room(TO, "Una aldeana pasa a todo correr recogiéndose las faldas mientras murmura que se le va a quemar el pan.\n");
			break;

					}
					return;

				}