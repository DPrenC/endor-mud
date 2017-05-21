/*
 * Servidor de clima para  el dominio de Aman
 */

#include <weather.h>

#include <properties.h>

inherit "/obj/chronos";

#define ME TO


create() {
  ::create();

 /* Buen tiempo 0 */
  SetDayMessageForClimate(CALOR,({
 "El cielo esta claro. No hace calor ni hace viento.*\n",           /* 0 */
 "La temperatura es alta, pero de vez en cuando te llega una brisa fresca.*\n",  /* 1 */
 "Hace mas calor. Hay nubecillas blancas en el cielo.*\n",          /* 2 */
 "Hace calor de verdad. Empiezas a sudar.*\n",                      /* 3 */
 "Hace mucho calor. Estas sudando.*\n",                             /* 4 */
 "Hay unas delicadas nubes en el cielo.*\n",                        /* 5 */
 "Hace cada vez mas calor.*\n",                                     /* 6 */
 "Hace tanto calor que el aire riela.*\n",                          /* 7 */
 "La temperatura es mas fresca.*\n",                                /* 8 */
 "Hace mucho calor, pero notas una brisa fresca soplando.*\n",      /* 9 */
 "La temperatura es agradable y sopla un viento fresco.*\n",        /* 10 */
 "El viento se llevo las nubes y el cielo esta claro.*\n"           /* 11 */
 }));

 /* Lluvia 1 */
  SetDayMessageForClimate(LLUVIA,({
 "El cielo esta claro. Sopla un debil viento calido.*\n",           /* 0 */
 "Solo hay unas pocas nubes. El viento es cada vez mas fuerte.*\n", /* 1 */
 "Esta nublado.*\n",                                                /* 2 */
 "Va a llover.*\n",                                                 /* 3 */
 "Hay algunas gotas de lluvia en el aire.*\n",                      /* 4 */
 "Esta lloviendo.*\n",                                              /* 5 */
 "Llueve a cantaros. Mejor que busques cobijo.*\n",                 /* 6 */
 "Esta lloviendo a mares. Te has puesto como una sopa.*\n",         /* 7 */
 "Esta empezando a escampar.*\n",                                   /* 8 */
 "Aun esta lloviendo.*\n",                                          /* 9 */
 "Solo caen unas pocas gotas.*\n",                                  /* 10 */
 "Ha parado de llover.*\n"                                          /* 11 */
 }));

 /* Niebla 2 */
 SetDayMessageForClimate(NIEBLA,({
 "El cielo esta claro. Sopla un viento fresco.*\n",                 /* 0 */
 "No ves ninguna nube, pero el viento es cada vez mas fuerte.*\n",  /* 1 */
 "El cielo se oscurece.*\n",                                        /* 2 */
 "Ves un ligero velo de bruma.*\n",                                 /* 3 */
 "Notas un velo de bruma rodeandote.*\n",                           /* 4 */
 "Hay niebla.*\n",                                                  /* 5 */
 "La niebla es espesa.*\n",                                         /* 6 */
 "La niebla es tan espesa que no ves a 3 metros.*\n",               /* 7 */
 "Te rodea una espesa niebla.*\n",                                  /* 8 */
 "Hay algo menos de niebla.*\n",                                    /* 9 */
 "Solo queda un ligero velo de bruma.*\n",                          /* 10 */
 "El cielo vuelve a aclararse. Ha empezado a soplar un viento fresco.*\n"  /* 11 */
 }));

 /* Tormenta con granizo 3 */
 SetDayMessageForClimate(TORMENTA,({
 "El cielo esta claro. Sopla un debil viento frio.*\n",             /* 0 */
 "Solo hay unas pocas nubes. Sopla un ligero viento frio.*\n",      /* 1 */
 "El cielo esta encapotado. Parece que va a haber tormenta.*\n",    /* 2 */
 "Hace frio y mucho viento. Se prepara una tormenta.*\n",           /* 3 */
 "Un viento fuerte te sopla en la cara.*\n",                        /* 4 */
 "Ha empezado a granizar y la tormenta descarga su furia.*\n",      /* 5 */
 "La tormenta lanza granizos contra tu cara.*\n",                   /* 6 */
 "Caen granizos como huevos de avestruz. El huracan casi te arrastra.*\n", /* 7 */
 "Los granizos son mas pequenyos y el huracan ya no es tan fuerte.*\n", /* 8 */
 "La tormenta amaina. Ya solo caen algunos pequenyos granizos.*\n", /* 9 */
 "Ya no graniza, pero el viento es aun muy fuerte.*\n",             /* 10 */
 "El cielo vuelve a aclararse. Solo sopla una brisa fresca.*\n"     /* 11 */
 }));

 /* Nieve 4 */
 SetDayMessageForClimate(NIEVE, ({
 "El cielo esta claro.*\n",                                         /* 0 */
 "Solo hay unas pocas nubes.*\n",                                   /* 1 */
 "Esta nublado.*\n",	            				   /* 2 */
 "Va a nevar.*\n", 	          				   /* 3 */
 "Caen unos pequenyos copos de nieve.*\n",                          /* 4 */
 "Empieza a nevar ligeramente. Hace rasquilla.*\n",                 /* 5 */
 "Esta nevando.*\n",                                                /* 6 */
 "Esta nevando con fuerza. Casi no puedes ver nada.*\n",            /* 7 */
 "Esta nevando menos.*\n",					   /* 8 */
 "Solo nieva un poco.*\n",                                          /* 9 */
 "Aun quedan algunos copos de nieve en el aire.*\n",                /* 10 */
 "Ha dejado de nevar. El cielo se ha aclarado.*\n"                  /* 11 */
 }));

 /* Mensajes durante la noche */
 /* Calor 0 */
 SetNightMessageForClimate(CALOR, ({
 "Ves las estrellas brillar en el claro cielo. La temperatura es agradable\n\
y no sopla viento.*\n",                                                  /* 0 */
 "Aunque es de noche, la temperatura es alta. El viento, sin embargo, es\n\
fresco.*\n",                                                             /* 1 */
 "La temperatura es mas fresca, pero el calor aun te hace sudar.*\n",    /* 2 */
 "La temperatura es tan fresca como puede serlo.*\n",                    /* 3 */
 "Incluso las noches son calurosas estos dias. Empiezas a sudar.*\n",    /* 4 */
 "Ves las estrellas brillar en el claro cielo nocturno.*\n",             /* 5 */
 "El calor de la noche te hace sudar.*\n",                               /* 6 */
 "Hace calor. Ojala al menos las noches fueran mas frescas.*\n",         /* 7 */
 "Ahora hace mas fresco.*\n",                                            /* 8 */
 "La temperatura es alta, pero el viento es fresco.*\n",                 /* 9 */
 "La temperatura es agradable y sopla un viento fresco.*\n",            /* 10 */
 "El cielo esta lo bastante claro como para ver muchas estrellas.*\n"   /* 11 */
 }));

 /* Lluvia 1 */
 SetNightMessageForClimate(LLUVIA, ({
 /* Rain 1 */
 "El cielo esta claro esta noche. Sopla un debil viento calido.*\n", /* 0 */
 "Algunas nubes son arrastradas por el cielo debido al viento, que se vuelve\n\
mas fuerte.*\n",                                                    /* 1 */
 "El cielo esta tan nublado que apenas puedes ver ninguna estrella.*\n", /* 2 */
 "Va a llover.*\n",                                                 /* 3 */
 "Esta chispeando.*\n",                                             /* 4 */
 "Esta lloviendo.*\n",                                              /* 5 */
 "Llueve a cantaros. Mejor que busques cobijo.*\n",                 /* 6 */
 "Llueve a mares. Te das un buen remojon.*\n",                      /* 7 */
 "La lluvia amaina.*\n",                                            /* 8 */
 "Aun llueve un poco.*\n",                                          /* 9 */
 "Apenas caen unas gotas del cielo.*\n",                           /* 10 */
 "Ha parado de llover.*\n"                                         /* 11 */
 }));

 /* Niebla 2 */
 SetNightMessageForClimate(NIEBLA, ({
 "El cielo esta claro. Sopla un viento fresco.*\n",                 /* 0 */
 "No ves nubes, pero el viento arrecia.*\n",                        /* 1 */
 "Esta noche el cielo es negro como el carbon. No ves ni una estrella.*\n", /* 2 */
 "Ves un ligero velo de niebla.*\n",                                /* 3 */
 "Un leve velo de niebla te rodea.*\n",                             /* 4 */
 "Hay niebla.*\n",                                                  /* 5 */
 "La niebla es espesa.*\n",                                         /* 6 */
 "La niebla es tan espesa que no ves nada a 3 metros.*\n",          /* 7 */
 "Una espesa niebla te rodea.*\n",                                  /* 8 */
 "La niebla empieza a disiparse.*\n",                               /* 9 */
 "Solo queda un ligero velo de niebla.*\n",                         /* 10 */
 "El cielo nocturno vuelve a aclararse. Ha empezado a soplar un suave viento.*\n" /* 11 */
 }));

 /* Tormenta con granizo 3 */
 SetNightMessageForClimate(TORMENTA, ({
 "El cielo esta claro. Las estrellas brillan en lo alto. Sopla un debil viento\n\
helado.*\n",                                                        /* 1 */
 "Solo hay unas pocas nubes. Sopla un viento frio.*\n",
 "El cielo esta encapotado. Parece que va a haber tormenta.*\n",    /* 2 */
 "Sopla un viento muy frio. Se prepara una tormenta.*\n",           /* 3 */
 "Un fuerte viento sopla en tu cara.*\n",                           /* 4 */
 "Ha empezado a granizar y la tormenta descarga su furia.*\n",      /* 5 */
 "El viento lanza granizos contra tu cara.*\n",                     /* 6 */
 "Caen granizos como huevos de avestruz. El huracan casi te arrastra.*\n", /* 7 */
 "Los granizos son mas pequenyos y el huracan ya no es tan fuerte.*\n",    /* 8 */
 "La tormenta amaina. Pequenyos granizos caen del cielo.*\n",       /* 9 */
 "Ya no graniza, pero el viento es aun muy fuerte.*\n",            /* 10 */
 "El cielo se aclara y puedes ver algunas estrellas. Solo sopla una brisa fresca.*\n",
 }));

 /* Nieve 4 */
 SetNightMessageForClimate(NIEVE, ({
 "Ves en lo alto un hermoso cielo invernal con muchas estrellas brillantes.*\n",
 "El viento trae algunas nubes.*\n",
 "Las nubes empiezan a cubrir las estrellas.*\n",
 "Va a nevar.*\n",
 "Empiezan a caer algunos copos de nieve.*\n",
 "Nieva ligeramente. Hace una rasca del copon.*\n",
 "Esta nevando.*\n",
 "Nieva intensamente. Casi no puedes ver nada.*\n",
 "Empieza a nevar menos.*\n",
 "Solo nieva un poco.*\n",
 "Quedan algunos copos en el aire.*\n",
 "Ha dejado de nevar. El cielo se aclara y vuelven a brillar las estrellas.*\n",
 }));

 SetGroundMessageForClimate(CALOR, ({
   "El suelo esta seco.*\n",
   "El suelo esta caliente y seco.*\n",
   "El terreno esta seco y polvoriento.*\n",
   "El aire sobre el suelo riela.*\n",
   "El terreno esta seco y resquebrajado.*\n",
   "El suelo esta caliente y reseco.*\n",
   }));

   /* Lluvia */
 SetGroundMessageForClimate(LLUVIA, ({
   "El suelo no se ha secado aun.*\n",
   "El suelo se acaba de secar.*\n",
   "El suelo esta humedo.*\n",
   "Esta todo embarrado.*\n",
   "El suelo esta anegado.*\n",
   "El suelo empieza a secarse.*\n",
   }));

   /* Niebla */
 SetGroundMessageForClimate(NIEBLA, ({
   "El suelo esta un poco humedo.*\n",
   "El terreno esta humedo.*\n",
   "Nubes de niebla, retorciendose como si estuvieran vivas, planean sobre.*\n\
el suelo.*\n",
   "Una niebla impenetrable planea sobre el suelo.*\n",
   "Aun queda algo de niebla a tus pies.*\n",
   "Los ultimos restos de niebla desaparecen.*\n",
   }));

   /* Tormenta con granizo y hielo */
 SetGroundMessageForClimate(TORMENTA, ({
   "El suelo esta mojado debido al granizo derretido.*\n",
   "El suelo esta algo helado.*\n",
   "El suelo esta humedo y helado.*\n",
   "El suelo esta cubierto de hielo. Camina con cuidado!\n",
   "El suelo esta helado. Hay granizos por todas partes.*\n",
   "Granizos medio derretidos cubren el suelo.*\n",
   }));

   /* Nieve */
 SetGroundMessageForClimate(NIEVE, ({
   "Hay algunas manchas de nieve en el suelo.*\n",
   "Los ultimos restos de nieve empiezan a derretirse.*\n",
   "Hay una fina capa de nieve.*\n",
   "El suelo esta cubierto de nieve.*\n",
   "La nieve lo cubre todo.*\n",
   "La gruesa capa de nieve se hace algo mas fina.*\n",
   }));
}
