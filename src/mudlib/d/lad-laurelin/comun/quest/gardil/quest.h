/****************************************************************************
Fichero: quest.c
Autor: Kastwey
Fecha: 01/04/2006
Descripción: Defines para el quest de Gardil.
****************************************************************************/


#ifndef _QUESTGARDIL_H
#define _QUESTGARDIL_H

#define ATR_QUEST           "estado_quest_gardil"
#define ESTADO_QUEST(x)     (x->QueryAttribute(ATR_QUEST))
#define TQUEST              "gardil_quest"
#define SIN_HACER           0
#define CON_CARTA           1
#define BUSCANDO_VIAL 2
#define BUSCANDO_VINO       3
#define POCION_CONSEGUIDA 4


#endif




