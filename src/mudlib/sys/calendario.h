/* 
DESCRIPCION  : Definiciones/constantes/etc.. para el calendario
FICHERO      : /sys/calendario.h
MODIFICACION : 14-02-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
NOTA: Por favor, las posibles modificaciones, notificadmelas e indicadlas con 
      fecha brevemente en esta cabecera, y mas extensamente en la cabecera de la
      funcion modificada. [Angor]
--------------------------------------------------------------------------------
*/

#ifndef _CALENDARIO_
#define _CALENDARIO_

// Fecha de inicio del calendario

#define C_DIA_INICIO_MUD        "22"
#define C_MES_INICIO_MUD        "Apr"
#define C_ANYO_INICIO_MUD       "1997"
#define C_ANYO_OFFSET           "4000"
#define C_DIAS_SIM_POR_DIA_REAL 4

// Parametros de las estaciones estandard

#define C_NUM_ESTACIONES    4   // estaciones por anyo
#define C_DURACION_ESTACION 1   // 1 mes real=1 estacion Simauria

#define C_INVIERNO          0
#define C_PRIMAVERA         1
#define C_VERANO            2
#define C_OTONYO            3

#define C_IDX_MESES ([\
"Jan":1,\
"Feb":2,\
"Mar":3,\
"Apr":4,\
"May":5,\
"Jun":6,\
"Jul":7,\
"Aug":8,\
"Sep":9,\
"Oct":10,\
"Nov":11,\
"Dec":12\
])


#define C_IDX_MESES_2 ({"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"})


/*
"1":"Jan","2":"Feb","3":"Mar","4":"Apr",\
"5":"May","6":"Jun","7":"Jul","8":"Aug",\
"9":"Sep","10":"Oct","11":"Nov","12":"Dec"\
])*/

#define C_DURACION_MESES ([\
"Jan":31,\
"Feb":28,\
"Mar":31,\
"Apr":30,\
"May":31,\
"Jun":30,\
"Jul":31,\
"Aug":31,\
"Sep":30,\
"Oct":31,\
"Nov":30,\
"Dec":31\
])

#endif
