#include "weight_4e.h"

// Acrónimos de las monedas
#define CP			"cp"
#define SP			"sp"
#define GP			"gp"
#define PP			"pp"
#define AD			"ad"

// Nombres de las monedas (largos)
#define CP_NAME		"pieza de cobre"
#define SP_NAME 	"pieza de plata"
#define GP_NAME 	"pieza de oro"
#define PP_NAME 	"pieza de platino"
#define AD_NAME		"diamante astral"

// Valores de las monedas en dnd4e pasado a UMS (unidad monetaria de Simauria, el cobre)
#define CP2UMS		1					// 1 CP dnd4e vale lo mismo que un cobre de Simauria

#define CP_VALUE	(1*CP2UMS)
#define SP_VALUE	(10*CP_VALUE)
#define GP_VALUE	(10*SP_VALUE)
#define PP_VALUE	(100*GP_VALUE)
#define AD_VALUE	(100*PP_VALUE)

// Pesos de las monedas pasados a gramos
#define CP_WEIGTH	(LB2GR*1/50)		// 1/50 libras	(~10gr)
#define SP_WEIGTH	(LB2GR*1/50)
#define GP_WEIGTH	(LB2GR*1/50)
#define PP_WEIGTH	(LB2GR*1/50)
#define AD_WEIGTH	(LB2GR*1/500)		// 1/500 libras	(~1gr)
