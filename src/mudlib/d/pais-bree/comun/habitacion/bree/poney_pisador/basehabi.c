/*
Fichero: basehabi.c
Autor: aulë
Fecha: 31/03/2013
Descripción:  base de las habitaciones de la posada. 
*/
#include "./path.h"
inherit BREE_ROOM;
create()
{
    ::create();
    	SetIntShort("una habitación");
    	    	    switch(d6()){
        case 1:
            SetIntLong("Estás en el interior de una habitación amueblada de forma simple "
            "pero funcional. Observas que suelo y paredes están forrados de madera "
            "pulimentada y una esterilla de gruesa lana blanca cubre el piso entre las "
            "dos confortables camas que se sitúan a ambos lados de una mesilla bajo la "
            "ventana del cuarto. Un par de gabetas de madera barnizada reposan al pie de "
            "las camas, y unos ganchos de latón situados en la pared sirven para colgar "
            "todo aquello que se desee.\n");
            AddDetail("camas",
            "El par de camas parecen confortables y mullidas, cubiertas con colchas impolutas y "
            "gruesas mantas de lana y con cabeceros sencillos de madera barnizada.\n");
            AddDetail("gabetas",
            "Son dos pequeños baúles de madera pulida y bien barnizada con cierres de "
            "latón que reposan al pie de las camas.\n");
            AddDetail("ganchos",
            "Ganchos de latón colocados en las paredes sirven para colgar prendas, "
            "petates o armas.\n");
            AddDetail("esterilla",
            "Es una sencilla esterilla de lana blanca.\n");
            break;
            case 2:
            	SetIntLong("Esta habitación ha sido acondicionada para hospedar un nutrido "
            	"grupo de huéspedes que deseen ahorrar costes. A ambos lados de un pasillo "
            	"central cubierto por una larga esterilla se sitúan dos juegos de "
            	"literas, con tres camas cada uno. No se ven armarios ni arcones por "
            	"ninguna parte.\n");
            	AddDetail(({"camas", "literas"}),
            	"Son dos juegos de literas de tres pisos. Soportadas por pilares de "
            	"madera pulida, las camas están cubiertas con colchas limpias y mantas de "
            	"lana que las hacen cálidas y confortables.\n");
            	AddDetail("esterilla",
            	"Una ancha esterilla de lana blanca que cubre el suelo entre las "
            	"literas.\n");
            	            	break;
            	case 3:
            		SetIntLong("En esta habitación pueden verse cuatro camas de tamaño más "
            		"pequeño para un humano. Un par de pesados arcones de madera reposan "
            		"bajo la ventana y unas gruesas esterillas guarnecen el suelo de madera.\n"
            		"Indudablemente, este cuarto ha sido acondicionado para enanos.\n");
            		AddDetail("camas",
            		"Son camas de pequeño tamaño, aunque grandes para un hobbit. Las mantas "
            		"que las cubren son gruesas y ásperas, y las almohadas están rellenas de "
            		"gravilla para hacerlas duras y confortables, al menos, para el gusto de "
            		"un enano.\n");
            		AddDetail("esterillas",
            		"Guresas esterillas de lana áspera cubren el suelo entre las literas.\n");
            		AddDetail("arcones",
            		"Son arcones de roble, con pesadas tapas arqueadas y grandes cerrojos, "
            		"del estilo que utilizan los enanos.\n");
            		break;
            		case 4:
            			SetIntLong("Una gran cama doble ocupa la mayor parte de la habitación.\n"
            			"Junto a esta hay una pequeña mesita y contra uno de los muros hay un "
            			"armario grande. Suelo y paredes están recubiertos de gruesa madera "
            			"barnizada que da calidez a la estancia.\n");
            			AddDetail("mesita",
            			"Sobre la pequeña mesita de madera reposa un candil.\n");
            			AddDetail("candil",
            			"Es un candil de cobre con una mecha que permite encenderlo para "
            			"iluminar la estancia.\n");
            			AddDetail("cama",
            			"Es una enorme cama doble cubierta con una gruesa colcha y con buenas "
            			"mantas de lana.\n");
            			AddDetail("armario",
            			"Es un armario grande, con dos puertas, hecho de madera de castaño bien "
            			"pulimentada y barnizada.\n");
            			break;
            				case 5:
            					SetIntLong("Este cuarto es indudablemente de los más baratos, "
            					"pues solo cuenta con una estrecha cama y una esterilla en el "
            					"suelo. No obstante, el Poney Pisador es una posada respetable y "
            					"todo parece limpio, suelos y paredes están forrados con planchas "
            					"de madera y la ventana cierra perfectamente.\n");
            					AddDetail("cama",
            					"La cama es baja y estrecha y parece dura. No obstante, la "
            					"colcha está impoluta y las mantas de gruesa lana parecen cálidas.\n");
            					AddDetail("esterilla",
            					"Es una simple y fina esterilla de lana blanca.\n");
            					case 6:
            						SetIntLong("La habitación en que te encuentras tiene un par de "
            						"camas y dos arcones junto a las paredes. Al pie de un muro han "
            						"colocado un colchón en el suelo de forma provisional. Sobre la "
            						"mesita hay un farol y unas esterillas de lana cubren el suelo.\n");
            						AddDetail("camas",
            						"Un par de camas de tamaño regular, cubiertas por limpias "
            						"colchas y forradas con mantas de lana.\n");
            						AddDetail("esterillas",
            						"Gruesasesterillas de lana blanca cubren el suelo.\n");
            						AddDetail("mesita",
            						"Una simple mesita de madera sobre la que hay un farol.\n");
            						AddDetail("farol",
            						"Un farol de latón con un asa para sujetarlo y una mecha para "
            						"regular la intensidad de la llama reposa sobre una mesita.\n");
            						AddDetail(({"colchon", "colchón"}),
            						"Es un colchón relleno de paja cubierto por una manta de lana.\n");
            						
            					
            					break;
            				}
            				AddDetail(({"suelo", "paredes", "muros", "muro", "pared"}),
            				"Suelo y paredes están forrados con buenos paneles de madera de "
            				"roble y castaño, pulidos y barnizados. Este revestimiento aisla la "
            				"habitación del frío y la hace cómoda y confortable.\n");
            				AddDetail("techo",
            				"El techo de madera está sustentado por pulidas vigas de "
            				"roble, cuya apariencia de antigüedad da testimonio de lo venerable "
            				"de esta posada.\n");
            				SetIntSmell("Huele a madera antigua, sábanas limpias y lana cálida, "
            				"todo ello mezclado con un leve olor a humo añejo.\n");

    	    SetIndoors(1);
    SetIntBright(25);
 }