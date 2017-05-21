/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 19-10-97                |
 |               Ultima Modificacion.. 13-05-99                |
 |                                                             |
 | 07-02-99 [w] Castellanizado, con eñes y demás.              |
 | 11-05-99 [w] Inutilizado el 'weather' del mud.              |
 | 12-05-99 [w] Introducidas nuevas descripciones.             |
 | 13-05-99 [w] Terminado de castellanizar y añadidas algunas  |
 |              frases más.                                    |
 | 04-10-99 [t] Hereda el nuevo /obj/chronos y se cambian sus  |
 |		frases por las del dominio		       |
 *=============================================================*/

inherit "/obj/chronos";

#include <weather.h>
//#include <chronos.h>

#include <properties.h>

#define ME TO
public mixed *statedata;
create() {
  ::create();

 /* Buen tiempo 0 */
  SetDayMessageForClimate(CALOR,({
      "El cielo está totalmente libre de nubes y no corre el aire.\n",
      "El clima es caluroso pero corre una ligera brisa.\n",
      "Cada vez hace más calor y no parece que vaya a cambiar el clima.\n",
      "Un calor agobiante recorre tu sudoroso cuerpo.\n",
      "Hace un calor asfixiante y no puedes parar de sudar.\n",
      "Aparecen algunas pequeñas nubes en el cielo.\n",
      "Cada vez hace más calor.\n",
      "El ambiente es caluroso.\n",
      "Un ligero frescor recorre tu cuerpo y te sientes mejor.\n",
      "Pese al calor te sientes agusto con la fresca brisa que hace.\n",
      "Un gratificante viento te permite aguantar este ambiente cálido.\n",
      "Desaparecen las pocas nubes que habian y el cielo vuelve a estar claro.\n",
 }));

 /* Lluvia 1 */
  SetDayMessageForClimate(LLUVIA,({
      "El cielo está claro y sopla un ligero viento.\n",
      "Aparecen algunas nubes en el cielo mientras el viento aumenta.\n",
      "El cielo está nublado.\n",
      "El cielo está muy nublado, parece que va a llover.\n",
      "Comienzan a caer algunas gotas.\n",
      "Está lloviendo.\n",
      "Cae una lluvia desmesurada.\n",
      "La lluvia cae con ganas y sientes que es hora de ponerse a cubierto.\n",
      "La lluvia comienza a disminuir, poco a poco.\n",
      "Continua lloviendo, pero parece que amaina.\n",
      "Cae una lluvia fina.\n",
      "Ha parado de llover.\n",
 }));

 /* Niebla 2 */
 SetDayMessageForClimate(NIEBLA,({
      "Sopla una escasa brisa y el cielo está claro.\n",
      "No hay nubes pero el viento sopla cada vez más.\n",
      "El cielo parece verse cada vez peor.\n",
      "Una ligera niebla te rodea.\n",
      "Notas que la niebla te rodea.\n",
      "Hay niebla.\n",
      "Hay una espesa niebla.\n",
      "La niebla te impide ver más alla de unos cuantos metros.\n",
      "La niebla te rodea.\n",
      "Parece que la niebla desaparece lentamente.\n",
      "La niebla casi ha desaparecido.\n",
      "El cielo está claro otra vez y aparece una brisa fresca.\n",
 }));

 /* Tormenta con granizo 3 */
 SetDayMessageForClimate(TORMENTA,({
      "Un ligero viento frio aparece a pesar de que el cielo esté claro.\n",
      "Hay algunas nubes y corretea un viento frio.\n",
      "El cielo se oscurece y se nubla lentamente, parece que va a haber tormenta.\n",
      "Hace frio y humedad, la tormenta se acerca.\n",
      "El viento frio sopla en tu cara.\n",
      "Empieza una tormenta.\n",
      "La tormenta continua y además está cayendo granizo.\n",
      "El granizo cae sobre ti y parece que no vaya a parar.\n",
      "Lo que parecía ser un huracán amaina lentamente.\n",
      "La tormenta está parando y ya casi no cae granizo.\n",
      "Se ha ido la tormenta, pero aún sigue un fuerte viento frio.\n",
      "El cielo puede verse de nuevo, solo sopla una fresca brisa.\n",
 }));

 /* Nieve 4 */
 SetDayMessageForClimate(NIEVE, ({
      "El cielo está claro.\n",
      "Hay unas pocas nubes en el cielo.\n",
      "Se está nublando.\n",
      "Todo hace suponer que va a nevar.\n",
      "Empiezan a caer los primeros copos de nieve.\n",
      "Está nevando ligeramente.\n",
      "Está nevando.\n",
      "Nieva bastante y solo ves nieve a tu alrededor.\n",
      "Nieva algo menos que antes.\n",
      "Nieva ligeramente, parece que esta parando.\n",
      "Solo caen unos cuantos copos de nieve.\n",
      "Ha parado de nevar, el cielo vuelve a estar claro.\n",
 }));

 /* Mensajes durante la noche */
 /* Calor 0 */
 SetNightMessageForClimate(CALOR, ({
      "Puedes ver miles de estrellas en esta noche cálida y sin viento.\n",
      "Hace un poco de calor a pesar de ser de noche.\n",
      "La noche es fresca pero aún así el calor sigue haciendote sudar.\n",
      "Antes parecía que el clima era más fresco que ahora.\n",
      "No hace apenas aire y tienes bastante calor en esta noche clara.\n",
      "Ves las estrellas en el oscuro cielo.\n",
      "El calor de la noche te hace sudar.\n",
      "Deseas que aparezca una fresca brisa para aliviarte del calor que sufres.\n",
      "Parece que haga un poco de fresco.\n",
      "El clima es cálido pero una fresca brisa te da en la cara.\n",
      "El cielo está lo suficientemente claro para que puedas ver las estrellas.\n",
      "Hace una temperatura cálida con un poco de viento.\n",
 }));

 /* Lluvia 1 */
 SetNightMessageForClimate(LLUVIA, ({
      "La noche está clara y hay una cálida brisa.\n",
      "Unas pocas nubes pasean por el cielo mientras el viento aumenta.\n",
      "Se está empezando a nublar la noche.\n",
      "Parece que va a llover.\n",
      "Hay un ambiente húmedo esta noche.\n",
      "Está lloviendo.\n",
      "Empieza a llover de una forma más fuerte.\n",
      "Llueve muchisimo, será mejor que te pongas a cubierto.\n",
      "La lluvia empieza a amainar.\n",
      "Continua lloviendo ligeramente.\n",
      "La lluvia practicamente ha parado, solo caen algunas gotas.\n",
      "Ha parado de llover.\n",
 }));

 /* Niebla 2 */
 SetNightMessageForClimate(NIEBLA, ({
      "La noche está clara pero sopla un viento fresco.\n",
      "No ves ninguna nube, pero el viento cada vez es más fuerte.\n",
      "Te cuesta ver las estrellas.\n",
      "Una ligera niebla da al ambiente un toque místico.\n",
      "La niebla empieza a rodearte poco a poco.\n",
      "La niebla está en todas partes.\n",
      "Estás agobiado por la niebla.\n",
      "Te cuesta ver lo que te rodea por la niebla.\n",
      "Poco a poco empiezas a vislumbrar mejor las cosas.\n",
      "La niebla se va poco a poco.\n",
      "Solo quedan algunos restos de la niebla.\n",
      "El ambiente vuelve a estar calmado.\n",
 }));

 /* Tormenta con granizo 3 */
 SetNightMessageForClimate(TORMENTA, ({
      "Una noche clara con estrellas y un ligero viento fresco.\n",
      "Hay algunas nubes cerca de la luna que te dan mala espina.\n",
      "El viento sopla con fuerza y el cielo está nublado.\n",
      "Presientes que va a caer una gran tormenta.\n",
      "Un fuerte viento te golpea.\n",
      "Empieza a llover y hace frio.\n",
      "Te cae algo de granizo encima y llueve bastante.\n",
      "Estás en medio de una tormenta y el granizo es enorme.\n",
      "El tiempo empeora, casi parece un huracán.\n",
      "El tamaño del granizo empieza a disminuir, aunque sigue el fuerte viento.\n",
      "Ha parado el granizo, pero continua el viento.\n",
      "El cielo vuelve a estar claro.\n",
 }));

 /* Nieve 4 */
 SetNightMessageForClimate(NIEVE, ({
      "Encima de ti ves una clara noche de invierno.\n",
      "Unas nubes recorren el oscuro cielo.\n",
      "Las estrellas empiezan a no verse por las nubes.\n",
      "El clima es muy frio.\n",
      "Está empezando a nevar.\n",
      "Te caen los primeros copos de nieve.\n",
      "Está nevando.\n",
      "Nieva bastante fuerte y hace frio.\n",
      "La nieve está por todas partes.\n",
      "La nevada disminuye.\n",
      "Están cayendo los últimos copos de nieve de esta nevada.\n",
      "Ha parado de nevar, todo vuelve a estar como al principio.\n",
 }));

 SetGroundMessageForClimate(CALOR, ({
        "El suelo está seco.\n",
        "A tus pies ves un suelo seco y caliente.\n",
        "Ves un suelo seco y polvoriento.\n",
        "Desde el suelo sube un calor agobiante.\n",
        "El suelo está caliente y seco.\n",
        "Ves un suelo seco.\n",
   }));

   /* Lluvia */
 SetGroundMessageForClimate(LLUVIA, ({
   "El suelo no está seco del todo.\n",
   "El suelo está muy húmedo.\n",
   "Ves a tus pies un suelo completamente mojado.\n",
   "El agua corre por el suelo.\n",
   "El suelo está muy mojado.\n",
   "Notas como el suelo empieza a secarse.\n",
   }));

   /* Niebla */
 SetGroundMessageForClimate(NIEBLA, ({
   "El suelo está algo húmedo.\n",
   "El suelo está húmedo.\n",
   "Un poco de niebla te impide verlo con claridad.\n",
   "Una espesa niebla no te deja verlo.\n",
   "Aun queda un poco de niebla en tus pies.\n",
   "Desaparecen los últimos restos de niebla.\n",
   }));

   /* Tormenta con granizo y hielo */
 SetGroundMessageForClimate(TORMENTA, ({
   "El suelo está algo húmedo.\n",
   "El suelo comienza a estar frio.\n",
   "El suelo empieza a estar muy mojado y frio.\n",
   "Notas un suelo muy resbaladizo a tus pies.\n",
   "El suelo está helado con mucho granizo a tu alrededor.\n",
   "El granizo cubre el suelo.\n",
   }));

   /* Nieve */
 SetGroundMessageForClimate(NIEVE, ({
   "Ves algunos copos de nieve en el suelo.\n",
   "La nieve comienza a cuajarse.\n",
   "El suelo empieza a tener un color blanco a causa de la nieve.\n",
   "Lo ves todo cubierto de nieve.\n",
   "La nieve no te deja verlo.\n",
   "Poco a poco la nieve que cubre el suelo empieza a derretirse.\n",
   }));
}

// Inutilizamos el statedata de '/obj/nightday'
public void InitStates(){
  int dawnlen, dawnlen2, daylen, nightmalus, i;

  dawnlen = DAY_LENGTH / 48;
  dawnlen2 = (3 * dawnlen) / 2;
  daylen = (DAY_LENGTH - 4 * dawnlen - 4 * dawnlen2) / 2;
  nightmalus = daylen / 4;

  statedata = ({
    ({ // ND_NIGHT
       daylen-nightmalus, ND_REL_STATE(0, MAX_SUNBRIGHT)
     , ""
     , "Ya es noche cerrada en Goldhai.\n",
    })
  , ({ // ND_PREDAWN
       dawnlen2, ND_REL_STATE(1, MAX_SUNBRIGHT)
     , ""
     , ""
    })
  , ({ // ND_DAWN
       dawnlen, ND_REL_STATE(2, MAX_SUNBRIGHT)
     , ""
     , "Se comienza a ver cierta luz en el horizonte.\n",
    })
  , ({ // ND_SUNRISE
       dawnlen, ND_REL_STATE(3, MAX_SUNBRIGHT)
     , ""
     , ""
    })
  , ({ // ND_PRENOON
       dawnlen2, ND_REL_STATE(4, MAX_SUNBRIGHT)
     , ""
     , ""
    })
  , ({ // ND_DAY
       daylen+nightmalus, ND_REL_STATE(5, MAX_SUNBRIGHT)
     , ""
     , "Es completamente de día en la isla de Goldhai.\n",
    })
  , ({ // ND_POSTNOON
       dawnlen2, ND_REL_STATE(6, MAX_SUNBRIGHT)
     , ""
     , ""
    })
  , ({ // ND_PREFALL
       dawnlen, ND_REL_STATE(7, MAX_SUNBRIGHT)
     , ""
     , "Comienza a oscurecer.\n",
    })
  , ({ // ND_FALL
       dawnlen, ND_REL_STATE(8, MAX_SUNBRIGHT)
     , ""
     , ""
    })
  , ({ // ND_PRENIGHT
       dawnlen2, ND_REL_STATE(9, MAX_SUNBRIGHT)
     , ""
     , ""
    })
              });

  if (pointerp(statedata))
    {
      statedata = statedata + ({});
      for (i=sizeof(statedata); i--; )
        if (pointerp(statedata[i]))
          statedata[i] = statedata[i]+({});
    }
}


