/* obj/nightday
**
** The default server for night and day in rooms. It is also _the_ reference
** for night and day for other servers.
**
**  28-Sep-92 [Mateese]
**  29-Sep-92 [Mateese] Some tweaks.
**  01-Oct-92 [Mateese] Substantial improvements.
**  04-Oct-92 [Randyandy] Just a small correction.
**                        (Replaced next_state() with NextState() :-)
**  06-Oct-92 [Mateese] generalized the call to SetDayState()
**  20-Oct-92 [Mateese] lengthened the daytime a bit
**  28-Dec-92 [Killroy] Fixed a few typos and gramar errors...
**  18-Jun-93 [Mateese] renamed from obj/nightday and made it
**                      a child of /std/weather
**  11-Aug-94 [Mateese] InitStateData()
**  08-Seb-94 [Mateese] Separated /obj/nightday /std/weather.
**
**  27-05-97  [Angor]   Traduccion y adaptacion para Simauria
**  10-11-97  [Nemesis] Revision de la Traduccion
**    Mar'99  [Nemesis] Castellanizado
**  16-04-99  [Nemesis] Mete un\n en lo de "desaparece por momentos"
*/

#include <config.h>
#include <properties.h>
#include <weather.h>
#include <nightday.h>

inherit "/std/weather";

/*-------------------------------------------------------------------------*/
/* Initialize the statedata table.
 * /std/weather depends on us!
 */

public void InitStates()
{
  int dawnlen, dawnlen2, daylen, nightmalus;

  dawnlen = DAY_LENGTH / 48;
  dawnlen2 = (3 * dawnlen) / 2;
  daylen = (DAY_LENGTH - 4 * dawnlen - 4 * dawnlen2) / 2;
  nightmalus = daylen / 4;

    // This is huge, this is big, this is not Skunk.
  statedata = ({
    ({ // ND_NIGHT
       daylen-nightmalus, ND_REL_STATE(0, MAX_SUNBRIGHT)
     , "Es de noche. Sobre ti ves el cielo oscuro y miles de estrellas.\n"
     , "Los últimos rayos del sol desaparecen. Ahora está completamente oscuro.\n"
    })
  , ({ // ND_PREDAWN
       dawnlen2, ND_REL_STATE(1, MAX_SUNBRIGHT)
     , "Es de noche, pero en el cielo ya se aprecia una cierta luminosidad.\n"
     , "En el horizonte aparece una cierta luminosidad.\n"
    })
  , ({ // ND_DAWN
       dawnlen, ND_REL_STATE(2, MAX_SUNBRIGHT),
"En el horizonte el brillo de un nuevo día se hace mas fuerte y apaga la\n\
luz de las estrellas.\n"
     , "La luminosidad aumenta en el horizonte anunciando el amanecer. Las estrellas\n desaparecen.\n"
    })
  , ({ // ND_SUNRISE
       dawnlen, ND_REL_STATE(3, MAX_SUNBRIGHT)
     , "El sol aparece sobre el horizonte proporcionado los primeros rayos\n de luz.\n"
     , "Lentamente el sol aparece tras el horizonte, iluminando el cielo.\n"
    })
  , ({ // ND_PRENOON
       dawnlen2, ND_REL_STATE(4, MAX_SUNBRIGHT)
     , "Es una mañana agradable.\n"
     , "El sol se ha elevado sobre el horizonte. Cada vez brilla más.\n"
    })
  , ({ // ND_DAY
       daylen+nightmalus, ND_REL_STATE(5, MAX_SUNBRIGHT)
     , "Es de día.\n"
     , "El sol se aproxima al zénit y brilla con fuerza.\n"
    })
  , ({ // ND_POSTNOON
       dawnlen2, ND_REL_STATE(6, MAX_SUNBRIGHT)
     , "El sol ha pasado el zénit e ilumina una agradable tarde.\n"
     , "Una vez pasado el zénit, el sol comienza a descender.\n"
    })
  , ({ // ND_PREFALL
       dawnlen, ND_REL_STATE(7, MAX_SUNBRIGHT)
     , "El sol está cerca del horizonte, creando una bella puesta de sol.\n"
     , "El sol se aproxima al horizonte, el cielo se tiñe de tonos ocres con\n la puesta de sol.\n"
    })
  , ({ // ND_FALL
       dawnlen, ND_REL_STATE(8, MAX_SUNBRIGHT)
     , "La noche cae y el sol desaparece.\n"
     , "El sol empieza a desaparecer tras el horizonte. Está oscureciendo.\n"
	 })
  , ({ // ND_PRENIGHT
       dawnlen2, ND_REL_STATE(9, MAX_SUNBRIGHT)
     , "El cielo está casi totalmente oscuro excepto por una cierta luminosidad\n"
	  +"que desaparece por momentos.\n"
     , "El sol se acaba de ocultar tras el horizonte, dejando tras de sí sólo\n"
	  +"la luz de una puesta de sol que se desvanece.\n"
    })
              });
}

/*-------------------------------------------------------------------------*/
/* Initialize and start service.
*/

public void create () {
  if (object_name(TO) != NIGHTDAY)
  {
    CHANNELMASTER->SendStr("error",
      sprintf("[error] %O: Inheriting or cloning /obj/nightday is fatal!"
             , TO));
    destruct(TO);
    return;
  }
  ::create();
}

/***************************************************************************/
