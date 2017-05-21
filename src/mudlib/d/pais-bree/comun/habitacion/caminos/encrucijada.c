/*
Fichero: encrucijada.c
Autor: Aule
fecha: 22/08/2012
Descripción: Cruce de caminos de Eriador.
*/
#include "./path.h"

inherit HABITACION+"caminos/base_camino";


create(){
    ::create();
    	SetLocate("el País de Bree");

    SetIntShort("cruce de caminos de Eriador");
    SetIntLong(" La antaño transitada e importante encrucijada de caminos de Eriador \n"
    "hace ya muchos siglos que no es más que un simple cruce de caminos cubierto de \n"
    "gravilla y hierbajos entre los cuales se forman pequeños charcos cuando llueve.\n"
    "Antaño una sección redondeada de firme empedrado, hoy no es más que un redondel \n"
    "con los bordes y las cercanías cubiertas por altas hierbas.\n"
    "Al norte, el camino procedente del sur se pierde en suaves curvas tras un alto \n"
    "risco de la colina de Bree, situada más al oeste, y hoy en día casi nadie lo \n"
    "transita, pues la antaño gran ciudad de Fornost a la que conduce, hoy solo es un \n"
    "montón de ruinas por las que vagan los tristes recuerdos de los Reyes de Los \n"
    "Hombres venidos del Mar desde el Oeste, quienes la edificaron tanto a ella como a \n"
    "los caminos y la encrucijada.\n"
    "Al oeste, el camino se pierde subiendo y bajando suaves lomas en dirección a la \n"
    "Comarca, distante a una jornada de viaje.\n"
    "Hacia el este una corta calzada apisonada conduce a la aldea de Bree, la más \n"
    "importante de las cuatro que forman el pequeño País de Bree.\n"
    "Muy lejos al norte, divisas apenas una línea oscura de elevaciones, mientras que al \n"
    "suroeste y al sureste puedes distinguir otros grupos de colinas.\n");
    AddDetail(({"hierba", "hierbas"}),
    "Una hierba alta y verde cubre los bordes y las cercanías de la encrucijada.\n");
    AddDetail("norte",
    "El llamado camino verde se dirige al norte hacia las lejanas Quebradas del Norte \n"
    "y las ruinas de Fornost.\n");
    AddDetail("risco",
    "Un espolón que surge de la colina en dirección oeste, cubierto de maleza y \n"
    "arbolillos y que el camino rodea antes de perderse en la distancia hacia el norte.\n");
    AddDetail("colina",
    "La colina de Bree es una elevación alta, amplia y parda que se eleva sobre las \n"
    "tierras de alrrededor.\n"
    "En la ladera oeste anida una aldea grande.\n");
    AddDetail(({"bree", "aldea"}),
    "Es una población de un centenar de casas de piedra y madera de hombres con una \n"
    "empalizada y un foso profundo que la rodean en algo más de medio círculo.\n"
    "En las partes más altas de la ladera se sitúan varios agujeros hobbits.\n");
AddDetail("gravilla",
    "Piedrecillas sueltas mezcladas con tierra que recubren y forman el suelo.\n");
    AddDetail("sur",
    "El llamado camino Verde serpentea por las tierras de Bree hacia el sur.\n");
    AddDetail("oeste",
    "El Camino del Este se desmadeja sobre suaves lomas en dirección a la Comarca.\n");
    AddDetail(({"este", "calzada"}),
    "Es una corta ruta de piedra y tierra apisonada que conduce recta hacia el este hasta el \n"
    "pie de la Colina de Bree y la puerta occidental de la aldea omónima.\n");
    AddDetail("casas",
    "Casas sencillas, de piedra y madera donde viven los hombres de Bree, en su \n"
    "mayoría situadas en la falda de la colina.\n"
    "Algunas disponen de más de una planta.\n");
    AddDetail(({"agujeros", "agujeros hobbits"}),
    "Crees distinguir desde aquí abajo las aberturas redondeadas que dan entrada a las \n"
    "viviendas subterráneas llamadas agujeros hobbits, y que esta raza prefiere a las \n"
    "casas levantadas sobre el suelo.\n");
    AddDetail("lomas",
    "Al oeste la tierra está constituida por suaves lomas cubiertas por matorrales o \n"
    "grupos de árboles dispersos.\n"
    "El gran Camino del Este las atraviesa en dirección a la Comarca.\n");
    AddDetail(({"elevaciones", "quebradas"}),
    "Apenas entrevistas, son las Quebradas del Norte donde antaño moraron muchos hombres \n"
    "poderosos y donde se alzaban los fuertes muros y torres de la ciudad de Fornost.\n"
    "Hoy en día son un páramo poco transitado por las gentes de bien.\n");
    AddDetail(({"Fornost", "fornost"}),
    "Desde aquí, ni el elfo con vista más penetrante acertaría a distinguir las \n"
    "antiguas ruinas de esta ciudad, que las gentes de Bree, no en vano llaman el Foso del Muerto.\n");
    AddDetail("colinas",
    "Tanto al suroeste como al sureste vislumbras cadenas de colinas.\n");
    AddDetail("suroeste",
    "Al suroeste observas una apretada cadena de colinas de cimas verdosas.\n"
    "Son las temidas Quebradas de los Túmulos, de infausta fama en la Comarca y Bree, \n"
    "morada de seres muertos que caminan bajo las neblinosas estrellas nocturnas a la \n"
    "caza de cualquier incauto que se extravíe en el intrincado laberinto de hondonadas, \n"
    "riscos y altas colinas que conforman la región.\n");
    AddDetail("sureste",
    "Al sureste distingues una lejana línea de colinas que van del suroeste al noreste.\n"
    "Son las Quebradas del Sur, elevaciones peladas y desnudas que se alzan en el centro \n"
    "de Eriador y actualmente poco habitadas a parte de las bestias y aves que en \n"
    "ellas moran.\n");
    AddExit("norte", "./encrucijadanorte");
    AddExit("sur", "./encrucijadasur");
    AddExit("oeste", "./encrucijadaoeste");
    AddExit("este", "./encrucijadaeste");
  }