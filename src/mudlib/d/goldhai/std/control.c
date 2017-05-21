/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 19-10-97                |
 |               Ultima Modificacion.. 13-05-99                |
 |                                                             |
 | 07-02-99 [w] Castellanizado, con e�es y dem�s.              |
 | 11-05-99 [w] Inutilizado el 'weather' del mud.              |
 | 12-05-99 [w] Introducidas nuevas descripciones.             |
 | 13-05-99 [w] Terminado de castellanizar y a�adidas algunas  |
 |              frases m�s.                                    |
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
      "El cielo est� totalmente libre de nubes y no corre el aire.\n",
      "El clima es caluroso pero corre una ligera brisa.\n",
      "Cada vez hace m�s calor y no parece que vaya a cambiar el clima.\n",
      "Un calor agobiante recorre tu sudoroso cuerpo.\n",
      "Hace un calor asfixiante y no puedes parar de sudar.\n",
      "Aparecen algunas peque�as nubes en el cielo.\n",
      "Cada vez hace m�s calor.\n",
      "El ambiente es caluroso.\n",
      "Un ligero frescor recorre tu cuerpo y te sientes mejor.\n",
      "Pese al calor te sientes agusto con la fresca brisa que hace.\n",
      "Un gratificante viento te permite aguantar este ambiente c�lido.\n",
      "Desaparecen las pocas nubes que habian y el cielo vuelve a estar claro.\n",
 }));

 /* Lluvia 1 */
  SetDayMessageForClimate(LLUVIA,({
      "El cielo est� claro y sopla un ligero viento.\n",
      "Aparecen algunas nubes en el cielo mientras el viento aumenta.\n",
      "El cielo est� nublado.\n",
      "El cielo est� muy nublado, parece que va a llover.\n",
      "Comienzan a caer algunas gotas.\n",
      "Est� lloviendo.\n",
      "Cae una lluvia desmesurada.\n",
      "La lluvia cae con ganas y sientes que es hora de ponerse a cubierto.\n",
      "La lluvia comienza a disminuir, poco a poco.\n",
      "Continua lloviendo, pero parece que amaina.\n",
      "Cae una lluvia fina.\n",
      "Ha parado de llover.\n",
 }));

 /* Niebla 2 */
 SetDayMessageForClimate(NIEBLA,({
      "Sopla una escasa brisa y el cielo est� claro.\n",
      "No hay nubes pero el viento sopla cada vez m�s.\n",
      "El cielo parece verse cada vez peor.\n",
      "Una ligera niebla te rodea.\n",
      "Notas que la niebla te rodea.\n",
      "Hay niebla.\n",
      "Hay una espesa niebla.\n",
      "La niebla te impide ver m�s alla de unos cuantos metros.\n",
      "La niebla te rodea.\n",
      "Parece que la niebla desaparece lentamente.\n",
      "La niebla casi ha desaparecido.\n",
      "El cielo est� claro otra vez y aparece una brisa fresca.\n",
 }));

 /* Tormenta con granizo 3 */
 SetDayMessageForClimate(TORMENTA,({
      "Un ligero viento frio aparece a pesar de que el cielo est� claro.\n",
      "Hay algunas nubes y corretea un viento frio.\n",
      "El cielo se oscurece y se nubla lentamente, parece que va a haber tormenta.\n",
      "Hace frio y humedad, la tormenta se acerca.\n",
      "El viento frio sopla en tu cara.\n",
      "Empieza una tormenta.\n",
      "La tormenta continua y adem�s est� cayendo granizo.\n",
      "El granizo cae sobre ti y parece que no vaya a parar.\n",
      "Lo que parec�a ser un hurac�n amaina lentamente.\n",
      "La tormenta est� parando y ya casi no cae granizo.\n",
      "Se ha ido la tormenta, pero a�n sigue un fuerte viento frio.\n",
      "El cielo puede verse de nuevo, solo sopla una fresca brisa.\n",
 }));

 /* Nieve 4 */
 SetDayMessageForClimate(NIEVE, ({
      "El cielo est� claro.\n",
      "Hay unas pocas nubes en el cielo.\n",
      "Se est� nublando.\n",
      "Todo hace suponer que va a nevar.\n",
      "Empiezan a caer los primeros copos de nieve.\n",
      "Est� nevando ligeramente.\n",
      "Est� nevando.\n",
      "Nieva bastante y solo ves nieve a tu alrededor.\n",
      "Nieva algo menos que antes.\n",
      "Nieva ligeramente, parece que esta parando.\n",
      "Solo caen unos cuantos copos de nieve.\n",
      "Ha parado de nevar, el cielo vuelve a estar claro.\n",
 }));

 /* Mensajes durante la noche */
 /* Calor 0 */
 SetNightMessageForClimate(CALOR, ({
      "Puedes ver miles de estrellas en esta noche c�lida y sin viento.\n",
      "Hace un poco de calor a pesar de ser de noche.\n",
      "La noche es fresca pero a�n as� el calor sigue haciendote sudar.\n",
      "Antes parec�a que el clima era m�s fresco que ahora.\n",
      "No hace apenas aire y tienes bastante calor en esta noche clara.\n",
      "Ves las estrellas en el oscuro cielo.\n",
      "El calor de la noche te hace sudar.\n",
      "Deseas que aparezca una fresca brisa para aliviarte del calor que sufres.\n",
      "Parece que haga un poco de fresco.\n",
      "El clima es c�lido pero una fresca brisa te da en la cara.\n",
      "El cielo est� lo suficientemente claro para que puedas ver las estrellas.\n",
      "Hace una temperatura c�lida con un poco de viento.\n",
 }));

 /* Lluvia 1 */
 SetNightMessageForClimate(LLUVIA, ({
      "La noche est� clara y hay una c�lida brisa.\n",
      "Unas pocas nubes pasean por el cielo mientras el viento aumenta.\n",
      "Se est� empezando a nublar la noche.\n",
      "Parece que va a llover.\n",
      "Hay un ambiente h�medo esta noche.\n",
      "Est� lloviendo.\n",
      "Empieza a llover de una forma m�s fuerte.\n",
      "Llueve muchisimo, ser� mejor que te pongas a cubierto.\n",
      "La lluvia empieza a amainar.\n",
      "Continua lloviendo ligeramente.\n",
      "La lluvia practicamente ha parado, solo caen algunas gotas.\n",
      "Ha parado de llover.\n",
 }));

 /* Niebla 2 */
 SetNightMessageForClimate(NIEBLA, ({
      "La noche est� clara pero sopla un viento fresco.\n",
      "No ves ninguna nube, pero el viento cada vez es m�s fuerte.\n",
      "Te cuesta ver las estrellas.\n",
      "Una ligera niebla da al ambiente un toque m�stico.\n",
      "La niebla empieza a rodearte poco a poco.\n",
      "La niebla est� en todas partes.\n",
      "Est�s agobiado por la niebla.\n",
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
      "El viento sopla con fuerza y el cielo est� nublado.\n",
      "Presientes que va a caer una gran tormenta.\n",
      "Un fuerte viento te golpea.\n",
      "Empieza a llover y hace frio.\n",
      "Te cae algo de granizo encima y llueve bastante.\n",
      "Est�s en medio de una tormenta y el granizo es enorme.\n",
      "El tiempo empeora, casi parece un hurac�n.\n",
      "El tama�o del granizo empieza a disminuir, aunque sigue el fuerte viento.\n",
      "Ha parado el granizo, pero continua el viento.\n",
      "El cielo vuelve a estar claro.\n",
 }));

 /* Nieve 4 */
 SetNightMessageForClimate(NIEVE, ({
      "Encima de ti ves una clara noche de invierno.\n",
      "Unas nubes recorren el oscuro cielo.\n",
      "Las estrellas empiezan a no verse por las nubes.\n",
      "El clima es muy frio.\n",
      "Est� empezando a nevar.\n",
      "Te caen los primeros copos de nieve.\n",
      "Est� nevando.\n",
      "Nieva bastante fuerte y hace frio.\n",
      "La nieve est� por todas partes.\n",
      "La nevada disminuye.\n",
      "Est�n cayendo los �ltimos copos de nieve de esta nevada.\n",
      "Ha parado de nevar, todo vuelve a estar como al principio.\n",
 }));

 SetGroundMessageForClimate(CALOR, ({
        "El suelo est� seco.\n",
        "A tus pies ves un suelo seco y caliente.\n",
        "Ves un suelo seco y polvoriento.\n",
        "Desde el suelo sube un calor agobiante.\n",
        "El suelo est� caliente y seco.\n",
        "Ves un suelo seco.\n",
   }));

   /* Lluvia */
 SetGroundMessageForClimate(LLUVIA, ({
   "El suelo no est� seco del todo.\n",
   "El suelo est� muy h�medo.\n",
   "Ves a tus pies un suelo completamente mojado.\n",
   "El agua corre por el suelo.\n",
   "El suelo est� muy mojado.\n",
   "Notas como el suelo empieza a secarse.\n",
   }));

   /* Niebla */
 SetGroundMessageForClimate(NIEBLA, ({
   "El suelo est� algo h�medo.\n",
   "El suelo est� h�medo.\n",
   "Un poco de niebla te impide verlo con claridad.\n",
   "Una espesa niebla no te deja verlo.\n",
   "Aun queda un poco de niebla en tus pies.\n",
   "Desaparecen los �ltimos restos de niebla.\n",
   }));

   /* Tormenta con granizo y hielo */
 SetGroundMessageForClimate(TORMENTA, ({
   "El suelo est� algo h�medo.\n",
   "El suelo comienza a estar frio.\n",
   "El suelo empieza a estar muy mojado y frio.\n",
   "Notas un suelo muy resbaladizo a tus pies.\n",
   "El suelo est� helado con mucho granizo a tu alrededor.\n",
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
     , "Es completamente de d�a en la isla de Goldhai.\n",
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


