#ifndef _FERIA_H_
#define _FERIA_H_

/*
mapping:
(["nombreprueba":puntos0;puntos1;... ])

#define NOMBRE "nombreprueba"
#define
*/
//Las kender:
#define PATOS		"Los Pescapatos"
#define ROBO		"Robo al Mu�eco"
#define HONDA		"Tiro con Honda"
#define SACO		"Salto con Saco"
#define CASETAS_KENDERS	({ PATOS, ROBO, HONDA, SACO })
//Las humanas:
#define PETANCA		"La Petanca"
#define POTRO		"El Potro Salvaje"
#define DUENDE		"La Barraca del Duende"
#define FUERZA		"Mide tu Fuerza"
#define CERDO		"Agarra el Cerdo"
#define BINGO		"El Bingo"
#define CASETAS_HUMANAS	({ PETANCA, POTRO, DUENDE, FUERZA, CERDO, BINGO })
//Las elfas:
#define ARCO		"Tiro con Arco"
#define CUCHILLOS	"Esquivar Cuchillos"
#define TRONCO		"Trepar Tronco"
#define DARDOS		"Lanzar Dardos"
#define CASETAS_ELFICAS	({ ARCO, CUCHILLOS, TRONCO, DARDOS })
//Las orcas:
#define CRANEOS		"Revienta Cr�neos"
#define VISCERAS	"Lanzamiento de V�sceras"
#define ELFO		"Tiro al Elfo"
#define GRUNYIO		"Er Gru�io"
#define CASETAS_ORCAS	({ CRANEOS, VISCERAS, ELFO, GRUNYIO })
//Las enanas
#define HACHAZO		"El Hachazo"
#define BIRRERIA	"Birreria"
#define QUIEN		"Quien es Quien"
#define TUMBAMUROS	"Tumbamuros"
#define CASETAS_ENANAS	({ HACHAZO, BIRRERIA, QUIEN, TUMBAMUROS })

#define CASETAS	(CASETAS_KENDERS+CASETAS_HUMANAS+CASETAS_ELFICAS+CASETAS_ORCAS+CASETAS_ENANAS)

#define ACIERTOS_0	0
#define ACIERTOS_1	1
#define ACIERTOS_2	2
#define ACIERTOS_3	3
#define ACIERTOS_4	4
#define ACIERTOS_5	5

#define PUESTO_1	1
#define PUESTO_2	2
#define PUESTO_3	3
#define PUESTO_OTRO	0

//zona kender:
#define PATO_0			0
#define PATO_1			1
#define PATO_2			2
#define PATO_3			3
#define PUNTOS_PATOS_0		1
#define PUNTOS_PATOS_1		2
#define PUNTOS_PATOS_2		3
#define PUNTOS_PATOS_3		4

#define ROBO_MAL		2
#define ROBO_REGULAR		3
#define ROBO_BIEN		4
#define PUNTOS_ROBO_MAL		0
#define PUNTOS_ROBO_REGULAR	1
#define PUNTOS_ROBO_BIEN	2

#define PUNTOS_HONDA_0		0 //aciertos
#define PUNTOS_HONDA_1		0
#define PUNTOS_HONDA_2		1
#define PUNTOS_HONDA_3		1
#define PUNTOS_HONDA_4		3
#define PUNTOS_HONDA_5		5

#define PUNTOS_SACO_1		5 //puesto
#define PUNTOS_SACO_2		2
#define PUNTOS_SACO_3		1
#define PUNTOS_SACO_OTRO	0

#define KENDERS	     ([ PATOS:	PUNTOS_PATOS_0;   PUNTOS_PATOS_1; PUNTOS_PATOS_2; PUNTOS_PATOS_3; 0;              0, \
			ROBO:	ROBO_MAL;         ROBO_REGULAR;   ROBO_BIEN;      0;              0;              0, \
			HONDA:	PUNTOS_HONDA_0;   PUNTOS_HONDA_1; PUNTOS_HONDA_2; PUNTOS_HONDA_3; PUNTOS_HONDA_4; PUNTOS_HONDA_5, \
			SACO:	PUNTOS_SACO_OTRO; PUNTOS_SACO_1;  PUNTOS_SACO_2;  PUNTOS_SACO_3;  0;              0, \
		      ])

//humanas
#define PUNTOS_PETANCA_1	4//puesto
#define PUNTOS_PETANCA_2	2
#define PUNTOS_PETANCA_3	1
#define PUNTOS_PETANCA_OTRO	0

#define PUNTOS_POTRO_0		0
#define PUNTOS_POTRO_1		0
#define PUNTOS_POTRO_2		0
#define PUNTOS_POTRO_3		3
#define PUNTOS_POTRO_4		3
#define PUNTOS_POTRO_5		5

#define PUNTOS_DUENDE_0		0 //aciertos
#define PUNTOS_DUENDE_1		1
#define PUNTOS_DUENDE_2		2
#define PUNTOS_DUENDE_3		3
#define PUNTOS_DUENDE_4		4
#define PUNTOS_DUENDE_5		5

#define FUERZA_METROS_0		0
#define FUERZA_METROS_1		1
#define FUERZA_METROS_2		2
#define FUERZA_METROS_3		3
#define FUERZA_METROS_4		4
#define FUERZA_METROS_5		5
#define PUNTOS_FUERZA_0		0
#define PUNTOS_FUERZA_1		0
#define PUNTOS_FUERZA_2		1
#define PUNTOS_FUERZA_3		2
#define PUNTOS_FUERZA_4		3
#define PUNTOS_FUERZA_5		5

#define CERDO_NO_ATRAPADO	0
#define CERDO_ATRAPADO		1
#define PUNTOS_CERDO_NO_ATRAPADO 0
#define PUNTOS_CERDO_ATRAPADO	5

#define BINGO_NADA		0
#define BINGO_LINEA		1
#define BINGO_BINGO		2
#define PUNTOS_BINGO_NADA	0
#define PUNTOS_BINGO_LINEA	10
#define PUNTOS_BINGO_BINGO	200

#define HUMANAS	     ([ PETANCA: PUNTOS_PETANCA_OTRO; PUNTOS_PETANCA_1; PUNTOS_PETANCA_2; PUNTOS_PETANCA_3; 0;               0, \
			POTRO:   PUNTOS_POTRO_0;      PUNTOS_POTRO_1;   PUNTOS_POTRO_2;   PUNTOS_POTRO_3;   PUNTOS_POTRO_4;  PUNTOS_POTRO_5, \
			DUENDE:  PUNTOS_DUENDE_0;     PUNTOS_DUENDE_1;  PUNTOS_DUENDE_2;  PUNTOS_DUENDE_3;  PUNTOS_DUENDE_4; PUNTOS_DUENDE_5, \
			FUERZA:  PUNTOS_FUERZA_0;     PUNTOS_FUERZA_1;  PUNTOS_FUERZA_2;  PUNTOS_FUERZA_3;  PUNTOS_FUERZA_4; PUNTOS_FUERZA_5, \
			CERDO:   PUNTOS_CERDO_NO_ATRAPADO; PUNTOS_CERDO_ATRAPADO; 0;      0;                0;               0, \
			BINGO:   PUNTOS_BINGO_NADA;   PUNTOS_BINGO_LINEA; PUNTOS_BINGO_BINGO; 0;            0;               0, \
		      ])
//elfa
#define PUNTOS_ARCO_0		0 //aciertos
#define PUNTOS_ARCO_1		0
#define PUNTOS_ARCO_2		1
#define PUNTOS_ARCO_3		1
#define PUNTOS_ARCO_4		2
#define PUNTOS_ARCO_5		5

#define PUNTOS_CUCHILLOS_0	0 //aciertos
#define PUNTOS_CUCHILLOS_1	0
#define PUNTOS_CUCHILLOS_2	1
#define PUNTOS_CUCHILLOS_3	1
#define PUNTOS_CUCHILLOS_4	2
#define PUNTOS_CUCHILLOS_5	5

#define TRONCO_PERDER		0
#define TRONCO_GANAR		1
#define PUNTOS_TRONCO_PERDER	0
#define PUNTOS_TRONCO_GANAR	5

#define PUNTOS_DARDOS_0		0 //aciertos
#define PUNTOS_DARDOS_1		0
#define PUNTOS_DARDOS_2		1
#define PUNTOS_DARDOS_3		1
#define PUNTOS_DARDOS_4		3
#define PUNTOS_DARDOS_5		5

#define ELFICAS	     ([	ARCO:      PUNTOS_ARCO_0;      PUNTOS_ARCO_1;      PUNTOS_ARCO_2;      PUNTOS_ARCO_3;      PUNTOS_ARCO_4;      PUNTOS_ARCO_5, \
			CUCHILLOS: PUNTOS_CUCHILLOS_0; PUNTOS_CUCHILLOS_1; PUNTOS_CUCHILLOS_2; PUNTOS_CUCHILLOS_3; PUNTOS_CUCHILLOS_4; PUNTOS_CUCHILLOS_5, \
			DARDOS:    PUNTOS_DARDOS_0;    PUNTOS_DARDOS_1;    PUNTOS_DARDOS_2;    PUNTOS_DARDOS_3;    PUNTOS_DARDOS_4;    PUNTOS_DARDOS_5, \
			TRONCO:    TRONCO_PERDER;      TRONCO_GANAR;       0;                  0;                  0;                  0 , \
		     ])

//orca
#define PUNTOS_CRANEOS_0	0 //aciertos
#define PUNTOS_CRANEOS_1	0
#define PUNTOS_CRANEOS_2	1
#define PUNTOS_CRANEOS_3	1
#define PUNTOS_CRANEOS_4	3
#define PUNTOS_CRANEOS_5	5

#define VISCERAS_METROS(x)	to_int(x/50)
#define PUNTOS_VISCERAS_0	0 //0-49
#define PUNTOS_VISCERAS_1	0 //50-99
#define PUNTOS_VISCERAS_2	1 //100-149
#define PUNTOS_VISCERAS_3	2 //150-199
#define PUNTOS_VISCERAS_4	3 //200-249
#define PUNTOS_VISCERAS_5	5 //250-

#define ELFO_MUERTO		4
#define ELFO_3			3
#define ELFO_2			2
#define ELFO_1			1
#define ELFO_0			0
#define PUNTOS_ELFO_MUERTO	5
#define PUNTOS_ELFO_3		3
#define PUNTOS_ELFO_2		2
#define PUNTOS_ELFO_1		1
#define PUNTOS_ELFO_0		0

#define GRUNYIO_NADIE		0
#define GRUNYIO_ALGUNOS		1
#define GRUNYIO_TODOS		2
#define PUNTOS_GRUNYIO_NADIE	0
#define PUNTOS_GRUNYIO_ALGUNOS	2
#define PUNTOS_GRUNYIO_TODOS	5

#define ORCAS	     ([	CRANEOS:  PUNTOS_CRANEOS_0;  PUNTOS_CRANEOS_1;  PUNTOS_CRANEOS_2;  PUNTOS_CRANEOS_3;  PUNTOS_CRANEOS_4;   PUNTOS_CRANEOS_5, \
			VISCERAS: PUNTOS_VISCERAS_0; PUNTOS_VISCERAS_1; PUNTOS_VISCERAS_2; PUNTOS_VISCERAS_3; PUNTOS_VISCERAS_4;  PUNTOS_VISCERAS_5, \
			ELFO:     PUNTOS_ELFO_0;     PUNTOS_ELFO_1;     PUNTOS_ELFO_2;     PUNTOS_ELFO_3;     PUNTOS_ELFO_MUERTO; 0, \
			GRUNYIO:  PUNTOS_GRUNYIO_NADIE; PUNTOS_GRUNYIO_ALGUNOS; PUNTOS_GRUNYIO_TODOS; 0;      0;                  0, \
		     ])

//enana
#define HACHAZO_NADA		0
#define HACHAZO_POCO		1
#define HACHAZO_MEDIO		2
#define HACHAZO_PARTIDO		3
#define PUNTOS_HACHAZO_NADA	0
#define PUNTOS_HACHAZO_POCO	1
#define PUNTOS_HACHAZO_MEDIO	3
#define PUNTOS_HACHAZO_PARTIDO	5

#define PUNTOS_BIRRERIA_OTRO	0 //puesto
#define PUNTOS_BIRRERIA_2	2
#define PUNTOS_BIRRERIA_1	5 //es el puesto en el que quedas

#define QUIEN_FALLO		0
#define QUIEN_ACIERTO		1
#define PUNTOS_QUIEN_FALLO	0
#define PUNTOS_QUIEN_ACIERTO	5

#define TUMBAMUROS_INTACTO	0
#define TUMBAMUROS_DERRUIDO	1
#define TUMBAMUROS_DERRIBADO	2
#define PUNTOS_TUMBAMUROS_INTACTO	0
#define PUNTOS_TUMBAMUROS_DERRUIDO	5
#define PUNTOS_TUMBAMUROS_DERRIBADO	10

#define ENANAS	     ([	HACHAZO: PUNTOS_HACHAZO_NADA; PUNTOS_HACHAZO_POCO; PUNTOS_HACHAZO_MEDIO; PUNTOS_HACHAZO_PARTIDO; 0; 0, \
			BIRRERIA: PUNTOS_BIRRERIA_OTRO; PUNTOS_BIRRERIA_1; PUNTOS_BIRRERIA_2; 0; 0; 0, \
			QUIEN: PUNTOS_QUIEN_FALLO; PUNTOS_QUIEN_ACIERTO; 0; 0; 0; 0, \
			TUMBAMUROS: PUNTOS_TUMBAMUROS_INTACTO; PUNTOS_TUMBAMUROS_DERRUIDO; PUNTOS_TUMBAMUROS_DERRIBADO; 0; 0; 0, \
		     ])

#define PUNTOS	(HUMANAS+ORCAS+ELFICAS+KENDERS+ENANAS)

#endif