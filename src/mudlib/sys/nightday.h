#ifndef NIGHTDAY_H
#define NIGHTDAY_H 1

#define NIGHTDAY "/obj/nightday"

  /* Day-States when asking the /obj/weather-server */

#define ND_NIGHT     0  /* Full night */
#define ND_PREDAWN   1  /* Almost dawn */
#define ND_DAWN      2  /* Morning dawns */
#define ND_SUNRISE   3  /* Sun barely above the horizon */
#define ND_PRENOON   4  /* Almost full day */
#define ND_DAY       5  /* Full day */
#define ND_POSTNOON  6  /* Shortly after noon */
#define ND_PREFALL   7  /* Sun heads towards the horizon */
#define ND_FALL      8  /* Sun just vanished */
#define ND_PRENIGHT  9  /* Almost night */

#define ND_NO_STATES 10

  /* Compute an absolute day state <s> into a relative day state of (0..m)
   * The second form is obsolete.
   */

#define ND_REL_STATE(s,m) (({0,10,20,40,70,100,70,40,20,10})[s]*(m)/100)
#define REL_STATE(s,m) (({0,10,20,40,70,100,70,40,20,10})[s]*(m)/100)

/* Nueva definición de los estados de visión */

#define ND_OSCTOTAL	-100
#define ND_OSCMEDIA	-40
#define ND_OSCURIDAD	-20

#define ND_NOCHE	0
#define ND_MADRUGADA	10
#define ND_ALBA		20
#define ND_AMANECER	40
#define ND_MANYANA	70
#define ND_DIA		100
#define ND_ATARDECER	70
#define ND_TARDE	40
#define ND_ANOCHECER	20
#define ND_PRENOCHE	10

#define ND_BRILLANTE	110
#define ND_DESLUMBRANTE	150

#endif
