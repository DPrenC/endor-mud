/* Creado el 04-06-01 por Nyh para el soporte de los grupos */

#ifndef __GRUPOS__
#define __GRUPOS__

/* --- RESPUESTAS --- */

#define INVITE_ALREADY		2
#define INVITE_OK		1
#define INVITE_ERROR		0
#define INVITE_OB_HAS_LIDER	-1
#define INVITE_OB_IS_LEADER	-2
#define INVITE_OB_HIGH_LEVEL	-3
#define INVITE_OB_LOW_LEVEL	-4

#define JOIN_ALREADY		2
#define JOIN_OK			1
#define JOIN_ERROR		0
#define JOIN_OB_NOT_INVITED	-1
#define JOIN_TO_HAS_LEADER	-2
#define JOIN_OB_HAS_LEADER	-3
#define JOIN_OB_IS_LEADER	-4
#define JOIN_OB_HIGH_LEVEL	-5
#define JOIN_OB_LOW_LEVEL	-6

#define UNVITE_OB_NOT_INVITED	2
#define UNVITE_OK		1
#define UNVITE_ERROR		0

#define FORCELEAVE_ERROR	0
#define FORCELEAVE_OK		1
#define FORCELEAVE_ISNT_LEADER	-1

#define LEAVE_OK	1
#define LEAVE_ERROR	0

#endif