#ifndef WEATHER_H
#define WEATHER_H

#include <nightday.h>

  // Array indices into a state description

#define WD_LENGTH    0  // Duration of the state
#define WD_SUNLIGHT  1  // Sunlight (0..MAX_SUNBRIGHT)
#define WD_DESC      2  // State description
#define WD_CDESC     3  // Description of the change into this state

#define WD_USER      4  // First free entry

#define NORMAL		0
#define HEAT		1
#define COLD		2
#define RAIN		3
#define WIND		4
#define STORM		5
#define FOG		6
#define SNOW		7

#define CALOR		HEAT	//días calurosos
#define FRIO  		COLD	//días fríos
#define LLUVIA		RAIN	//llúvia (moderada)
#define VIENTO		WIND	//dia ventoso
#define TORMENTA	STORM	//tormenta 
#define NIEBLA		FOG	//niebla
#define NIEVE		SNOW	//nevada

#endif
