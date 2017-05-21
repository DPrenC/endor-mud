/*
Fichero: encrucijada.c
Autor: Aule
fecha: 22/08/2012
Descripci�n: Cruce de caminos de Eriador.
*/
#include "./path.h"

inherit HABITACION+"caminos/base_camino";


create(){
    ::create();
    	SetLocate("el Pa�s de Bree");

    SetIntShort("cruce de caminos de Eriador");
    SetIntLong(" La anta�o transitada e importante encrucijada de caminos de Eriador \n"
    "hace ya muchos siglos que no es m�s que un simple cruce de caminos cubierto de \n"
    "gravilla y hierbajos entre los cuales se forman peque�os charcos cuando llueve.\n"
    "Anta�o una secci�n redondeada de firme empedrado, hoy no es m�s que un redondel \n"
    "con los bordes y las cercan�as cubiertas por altas hierbas.\n"
    "Al norte, el camino procedente del sur se pierde en suaves curvas tras un alto \n"
    "risco de la colina de Bree, situada m�s al oeste, y hoy en d�a casi nadie lo \n"
    "transita, pues la anta�o gran ciudad de Fornost a la que conduce, hoy solo es un \n"
    "mont�n de ruinas por las que vagan los tristes recuerdos de los Reyes de Los \n"
    "Hombres venidos del Mar desde el Oeste, quienes la edificaron tanto a ella como a \n"
    "los caminos y la encrucijada.\n"
    "Al oeste, el camino se pierde subiendo y bajando suaves lomas en direcci�n a la \n"
    "Comarca, distante a una jornada de viaje.\n"
    "Hacia el este una corta calzada apisonada conduce a la aldea de Bree, la m�s \n"
    "importante de las cuatro que forman el peque�o Pa�s de Bree.\n"
    "Muy lejos al norte, divisas apenas una l�nea oscura de elevaciones, mientras que al \n"
    "suroeste y al sureste puedes distinguir otros grupos de colinas.\n");
    AddDetail(({"hierba", "hierbas"}),
    "Una hierba alta y verde cubre los bordes y las cercan�as de la encrucijada.\n");
    AddDetail("norte",
    "El llamado camino verde se dirige al norte hacia las lejanas Quebradas del Norte \n"
    "y las ruinas de Fornost.\n");
    AddDetail("risco",
    "Un espol�n que surge de la colina en direcci�n oeste, cubierto de maleza y \n"
    "arbolillos y que el camino rodea antes de perderse en la distancia hacia el norte.\n");
    AddDetail("colina",
    "La colina de Bree es una elevaci�n alta, amplia y parda que se eleva sobre las \n"
    "tierras de alrrededor.\n"
    "En la ladera oeste anida una aldea grande.\n");
    AddDetail(({"bree", "aldea"}),
    "Es una poblaci�n de un centenar de casas de piedra y madera de hombres con una \n"
    "empalizada y un foso profundo que la rodean en algo m�s de medio c�rculo.\n"
    "En las partes m�s altas de la ladera se sit�an varios agujeros hobbits.\n");
AddDetail("gravilla",
    "Piedrecillas sueltas mezcladas con tierra que recubren y forman el suelo.\n");
    AddDetail("sur",
    "El llamado camino Verde serpentea por las tierras de Bree hacia el sur.\n");
    AddDetail("oeste",
    "El Camino del Este se desmadeja sobre suaves lomas en direcci�n a la Comarca.\n");
    AddDetail(({"este", "calzada"}),
    "Es una corta ruta de piedra y tierra apisonada que conduce recta hacia el este hasta el \n"
    "pie de la Colina de Bree y la puerta occidental de la aldea om�nima.\n");
    AddDetail("casas",
    "Casas sencillas, de piedra y madera donde viven los hombres de Bree, en su \n"
    "mayor�a situadas en la falda de la colina.\n"
    "Algunas disponen de m�s de una planta.\n");
    AddDetail(({"agujeros", "agujeros hobbits"}),
    "Crees distinguir desde aqu� abajo las aberturas redondeadas que dan entrada a las \n"
    "viviendas subterr�neas llamadas agujeros hobbits, y que esta raza prefiere a las \n"
    "casas levantadas sobre el suelo.\n");
    AddDetail("lomas",
    "Al oeste la tierra est� constituida por suaves lomas cubiertas por matorrales o \n"
    "grupos de �rboles dispersos.\n"
    "El gran Camino del Este las atraviesa en direcci�n a la Comarca.\n");
    AddDetail(({"elevaciones", "quebradas"}),
    "Apenas entrevistas, son las Quebradas del Norte donde anta�o moraron muchos hombres \n"
    "poderosos y donde se alzaban los fuertes muros y torres de la ciudad de Fornost.\n"
    "Hoy en d�a son un p�ramo poco transitado por las gentes de bien.\n");
    AddDetail(({"Fornost", "fornost"}),
    "Desde aqu�, ni el elfo con vista m�s penetrante acertar�a a distinguir las \n"
    "antiguas ruinas de esta ciudad, que las gentes de Bree, no en vano llaman el Foso del Muerto.\n");
    AddDetail("colinas",
    "Tanto al suroeste como al sureste vislumbras cadenas de colinas.\n");
    AddDetail("suroeste",
    "Al suroeste observas una apretada cadena de colinas de cimas verdosas.\n"
    "Son las temidas Quebradas de los T�mulos, de infausta fama en la Comarca y Bree, \n"
    "morada de seres muertos que caminan bajo las neblinosas estrellas nocturnas a la \n"
    "caza de cualquier incauto que se extrav�e en el intrincado laberinto de hondonadas, \n"
    "riscos y altas colinas que conforman la regi�n.\n");
    AddDetail("sureste",
    "Al sureste distingues una lejana l�nea de colinas que van del suroeste al noreste.\n"
    "Son las Quebradas del Sur, elevaciones peladas y desnudas que se alzan en el centro \n"
    "de Eriador y actualmente poco habitadas a parte de las bestias y aves que en \n"
    "ellas moran.\n");
    AddExit("norte", "./encrucijadanorte");
    AddExit("sur", "./encrucijadasur");
    AddExit("oeste", "./encrucijadaoeste");
    AddExit("este", "./encrucijadaeste");
  }