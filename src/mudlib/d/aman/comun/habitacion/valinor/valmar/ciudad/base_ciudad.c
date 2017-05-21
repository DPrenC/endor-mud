/*
Fichero: base_ciudad.c
Autor: Aul�
Fecha: 21/07/2013
Descripci�n: archivo base para las habitaciones exteriores de Valmar.
*/
#include "./path.h"
inherit STD_VALINOR("hab_valinor");
#include <sounds.h>



string f_sonidos(){
    switch(d10()){
        case 1:
            return "Escuchas las arg�nteas notas de un arpa �lfica.\n";
        case 2:
            return "El aureo ta�ir de las muchas campanas de Valmar desciende sobre ti "
            "como una lluvia primaveral en la superficie de un umbr�o estanque.\n";
        case 3:
            return "Las ramas de los �rboles de la avenida susurran movidas por una brisa c�lida.\n";
        case 4:
            return "Un coro de claras voces celestiales se alza en un hermoso canto.\n";
        case 5:
            return "Un viento fresco hace suspirar las hojas plateadas de los �rboles.\n";
        case 6:
            return "El ta�ir de las campanas de oro y plata de Valmar resuena por doquier.\n";
        case 7:
            return "Escuchas la clara llamada de un p�jaro jam�s o�do en tierras mortales.\n";
        case 8:
            return "Escuchas el leve suspiro de las ramas de los grandes �rboles de la "
            "avenida cuando una suave brisa los hace mecerse. .\n";
        case 9:
            return ".\n";
        case 10:
            return "Las voces cristalinas del pueblo de Valinor resuenan por doquier.\n";
    }
    return "";
}

string f_olores(){
    switch(d3()){
        case 1:
            return "Aspiras el aire m�s l�mpido y puro que imaginar se pueda.\n";
        case 2:
            return "Aspiras la leve fragancia de los maravillosos �rboles de la avenida.\n";
        case 3:
            return "Aspiras el fresco viento procedente de las nieves eternas de Taniquetil.\n";
    }
    return "";
}

create()
{    ::create();
SetLocate("ciudad de valmar");
    	SetIndoors(0);
    	SetIntBright(20);

    	SetIntShort("una resplandeciente avenida");

    switch(d3()){
        case 1:
            SetIntLong("Te encuentras en Valmar, la hermosa y legendaria ciudad "
   "capital de los Valar, donde muchos de ellos junto con una infinidad de Maiar y "
   "Eldar, habitan en la plena beatitud de Valinor.\n"
            "Esta ancha avenida est� magn�ficamente pavimentada con el m�s puro m�rmol "
            "blanco con vetas de lo que parecen ser minerales preciosos, "
            "gracias a las artes  del pueblo de Aul�.\n"
            "Todo alrededor se alzan los m�s grandiosos y majestuosos edificios que "
            "imaginar se puedan, hogar del pueblo celestial de Valinor.\n"
            "El mismo aire parece vibrar, puro y l�mpido como si nunca criatura "
            "viviente alguna lo hubiese respirado antes, y la luz di�fana parece fluir de "
            "la misma piedra resplandeciente de las torres, c�pulas y mansiones, no "
            "habiendo lugar en esta ciudad para la oscuridad.\n");
            break;
        case 2:
            SetIntLong("Te encuentras en Valmar, la ciudad de las muchas campanas, "
            "gloria de Valinor y hogar de los Valar y los Maiar.\n"
            "La ancha avenida por la que transitas se ve flanqueada por edificios de "
            "belleza sin par. Hermosos palacios y mansiones, altas torres de gr�cil "
            "esbeltez, magn�ficas c�pulas de oro, plata y bronce, columnas y atrios del "
            "m�s puro m�rmol veteado de oro y plata, todo ello hace de esta urbe "
            "surgida del seno  de la tierra por gracia de Aul� y su pueblo, una de las m�s "
            "maravillosas obras de los Valar en Arda.\n");
            break;
        case 3:
            SetIntLong("Circulas por Valmar, la ciudad constru�da por los Valar y "
            "Maiar hace muchas edades, tras la destrucci�n del antiguo hogar de Almaren "
            "a manos de Melkor y el establecimiento en Valinor.\n"
            "Cada Vala colabor� a realizar esta magn�fica ciudad con sus dones: Aul� y "
            "su pueblo hicieron surgir de la misma tierra sus muros, torres y palacios, "
            "Manw� orden� que sus l�mpidos vientos la pulieran hasta la perfecci�n y "
            "mantuvieran siempre un ambiente fresco y puro, las estrellas de Varda "
            "iluminaron con gran esplendor sus c�lidas noches y Yavanna la pobl� con "
            "maravillosas criaturas y decor� sus amplias avenidas con los m�s "
            "mmajestuosos �rboles que imaginar se puedan.\n"
            "La gran avenida en la que te hayas est� rodeada de grandiosos edificios "
            "de piedra blanca y c�pulas plateadas, doradas y bronc�neas, jalonadas por "
            "esbeltas torres y amplias puertas de oro macizo. En el centro y a cada "
            "cierto trecho, se alinean �rboles y porciones de verde c�sped cuajado de "
            "flores desconocidas.\n");

            break;
    }
    SetIntNoise(SF(f_sonidos));
    SetIntSmell(SF(f_olores));
                 SetSoundEnvironment(SOUND_AMBIENTES("aman"), 45);

    AddDetail("edificios",
    "Palacios, mansiones, torres, c�pulas y columnas, forman el conjunto "
    "arquitect�nico  m�s grandioso que ojos mortales hayan visto jam�s.\n");
    AddDetail(({"palacios", "mansiones"}),
    "Edificados con el m�s n�veo m�rmol, metales preciosos y magia, los "
    "grandes palacios de Valmar, hogar del pueblo celestial de Valinor,se "
    "alinean a lo largo de las amplias avenidas pavimentadas.\n");
    AddDetail("campanas",
    "Mirando hacia arriba distingues las innumerables campanas de oro y plata que dan "
    "nombre a la ciudad, situadas sobre torres y c�pulas, resplandeciendo con el fulgor "
    "del metal bru�ido.\n");
    AddDetail("torres",
    "Las altas torres de Valmar se ierguen gr�cilmente como agujas de n�car y plata "
    "coronadas por doradas c�pulas.\n");
    AddDetail(({"c�pulas", "cupulas"}),
    "Por doquier, adornando y coronando palacios y torres, se sit�an hermosas c�pulas de "
    "oro, plata y bronce.\n");
    AddDetail("maiar",
    "A tu alrededor, en sus idas y venidas, distingues al pueblo ang�lico de los Maiar, "
    "en cuyos rostros adviertes el poder, majestad y sabidur�a de los Ainur, cuyos "
    "ropajes resplandecen y en cuyos ojos atisbas la luz de Valinor que jam�s perecer�.\n");
    AddDetail("elfos",
    "La mayor�a de ellos pertenecen al dorado pueblo de los Vanyar, que pocos "
    "mortales han visto, pero entre ellos  hay no pocos Noldor de cabellos oscuros y "
    "ojos acerados e incluso algunos livianos Teleri venidos de sus puertos, m�s all� de "
    "las P�lori.\n");
    AddDetail("columnas",
    "Las columnas de p�rticos y edificios parecen estar cinceladas en una sola pieza de "
    "piedra blanca, cual si esta hubiese surgido de la misma tierra.\n");
    AddDetail("atrios",
    "Amplios atrios de m�rmol se levantan ante las puertas de mansiones y palacios.\n");
    AddDetail("m�rmol",
    "El m�rmol que pavimenta avenidas y edificios es el m�s puro que pueda encontrars"
    "en toda Arda y ha sido veteado con metales preciosos por el pueblo de Aul�.\n");
    AddDetail("piedra",
    "La piedra que constituye los edificios y muros de Valmar resplandece con pr�stina "
    "blancura bajo el Sol y las estrellas y ha sido sellada con magia\n");
    AddDetail("aire",
    "Hasta el mismo aire parece brillar en esta ciudad.\n");
    AddDetail("luz",
    "Sea de noche o de d�a, la luz existente en Valinor y especialmente en Valmar, no "
    "deja lugar a la oscuridad, pareciendo manar de la misma piedra.\n");
    AddDetail("puertas",
    "Las puertas de los edificios est�n magn�ficamente cinceladas en oro macizo.\n");
    AddDetail(({"c�sped", "cesped"}),
    "El c�sped que rodea los �rboles y adorna las avenidas exhibe un suave verdor.\n");
    AddDetail(({"arboles", "�rboles"}),
    "Distintos tipos de �rboles jalonan y adornan las avenidas:"
    	" altos, esbeltos y con hojas plateadas, de troncos gruesos y poderosos como "
    	"pilares y de corteza lisa... todos ellos cuidados por las doncellas de Yavanna.\n");
    	  }


     public void init()
     {
        ::init();
            call_out("entrada");
	}

	public void entrada(){
		switch(d20()){
			case 1:
				tell_room(TO, "Una cohorte de nobles damas Maiar del pueblo de Yavana avanzan por la "
				"avenida administrando cuidados a plantas y �rboles.\n");
				break;
				case 2:
					write("La ciudad de Valmar reposa, plena de beatitud bajo el luminoso cielo de Valinor.\n");
					break;
					case 3:
						write("La paz inunda las amplias avenidas de Valmar.\n");
						break;
						case 4:
							tell_room(TO, "Un grupo de Maiar, ataviados como el pueblo de Aul� pasan "
							"apresurados, dedicados a sus quehaceres.\n");
							break;
							case 5:
								tell_room(TO, "Un noble jinete vestido de verde, perteneciente al pueblo de Orom�, pasa cerca, "
								"al trote.\n");
								break;
							case 6:
				tell_room(TO, "Un grupo de Altos Elfos Vanyar pasan cerca, cantando alabanzas a los Valar.\n");
				break;
				case 7:
				 tell_room(TO, "Las campanas de las altas torres de la ciudad doblan con alegre ta�ir.\n");
					break;
					case 8:
					 tell_room(TO, "Una bella Maia del pueblo de Varda pasa cerca de ti.\n");
						break;
						case 9:
							tell_room(TO, "Un par de altos Maia del pueblo de Orom� cruzan la avenida y "
							"penetran en una de las blancas torres.\n");
							break;
							case 10:
								write("La luz de Valinor parece emanar del rostro del noble Maia que pasa a tu lado.\n");
								break;
								case 11:
									tell_room(TO, "Una de las enormes y nobles �guilas de Manw� sobrevuela la ciudad a gran altura.\n");
									break;
									case 12:
										write("La bondad, la belleza y la paz que se respiran en Valmar "
										"inundan tu coraz�n de sosiego.\n");
										break;


					}
					return;

				}