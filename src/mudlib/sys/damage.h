/**
 * /sys/damage.h
 */

#ifndef __DAMAGE_H__
#define __DAMAGE_H__

// Damage types (Tipos de daño)
// Los tipos negativos afectan a la victima entera

#define TD_INTR             0

#define TD_CORTE            1   // d20 Espadas, etc
#define TD_APLASTAMIENTO    2   // d20 Mazas, golpes en general...
#define TD_PENETRACION      3   // d20 Dagas, lanzas, flechas...
#define TD_LACERACION       4   //nuevo para endor
#define TD_ABRASIVO         5  //nuevo para endor
#define TD_FUEGO            6   // d20 Fuego/Calor (Bola de fuego)
#define TD_CALOR            TD_FUEGO
#define TD_FRIO             7   // d20 Frio (rayo de escarcha)
#define TD_ELECTRICIDAD     8   // d20 Electricidad (relampago)
#define TD_ACIDO            9   // d20 Acido (flecha acida de melf)
#define TD_SONICO           10   // d20 Sonico (alarido)
#define TD_AGUA             11   // NO  Agua bendita
#define TD_GAS              12  // NO  Gas venenoso
#define TD_ZAP              13  // NO  Dedo de la muerte
#define TD_VENENO           14  // NO  Todo tipo de veneno
#define TD_PSIQUICO         15  // NO  Ataques mentales
#define TD_VACIO            16  // NO  Falta de aire (suffocation)

//tipos de daño y sus textos
#define TD_CORTE_TXT            "cortante"
#define TD_APLASTAMIENTO_TXT    "aplastante"
#define TD_PENETRACION_TXT      "penetrante"
#define TD_LACERACION_TXT       "lacerante"
#define TD_ABRASIVO_TXT         "abrasivo"


//#define TD_CONV            5 //numero de daños convencionales
//#define TD_MAGICO          6 //primer daño no convencional
//cambio la definicion TD_MAGICO

#define TD_NORMAL   0    // base de daños normales
#define TD_MAGICO 100    //base de daños magicos
#define TD_CONV    99    //ultimo daño convencional...

#define TD_CONVENCIONALES   TD_CONV

//Daños mágicos:
#define TM_INTR             TD_MAGICO+TD_INTR

#define TM_CORTE            TD_MAGICO+TD_CORTE    // Espadas, etc
#define TM_APLASTAMIENTO    TD_MAGICO+TD_APLASTAMIENTO    // Mazas, golpes en general...
#define TM_PENETRACION      TD_MAGICO+TD_PENETRACION    // Dagas, lanzas, flechas...
#define TM_LACERACION       TD_MAGICO+TD_LACERACION  // nuevo para endor.
#define TM_CALOR            TD_MAGICO+TD_CALOR    // Calor (bola de fuego)
#define TM_FRIO             TD_MAGICO+TD_FRIO    // Frio (rayo de escarcha)
#define TM_AGUA             TD_MAGICO+TD_AGUA    // Agua bendita
#define TM_GAS              TD_MAGICO+TD_GAS    // Gas venenoso
#define TM_ZAP              TD_MAGICO+TD_ZAP    // Dedo de la muerte
#define TM_ELECTRICIDAD     TD_MAGICO+TD_ELECTRICIDAD    // Contra electricidad
#define TM_ACIDO            TD_MAGICO+TD_ACIDO    // Contra acido
#define TM_VENENO           TD_MAGICO+TD_VENENO    // Todo tipo de veneno
#define TM_PSIQUICO         TD_MAGICO+TD_PSIQUICO    // Ataques mentales
#define TM_VACIO            TD_MAGICO+TD_VACIO    // Falta de aire (suffocation)

//compatibilidad...
#define DT_INTR         TD_INTR
#define DT_SLASH        TD_CORTE
#define DT_BLUDGEON     TD_APLASTAMIENTO
#define DT_PIERCE       TD_PENETRACION
#define DT_FIRE         TD_CALOR
#define DT_COLD         TD_FRIO
#define DT_WATER        TD_AGUA
#define DT_GAS          TD_GAS
#define DT_ZAP          TD_ZAP
#define DT_ELECTRO      TD_ELECTRICIDAD
#define DT_ACID         TD_ACIDO
#define DT_POISON       TD_VENENO
#define DT_PSYCHO       TD_PSIQUICO
#define DT_NOAIR        TD_VACIO

#define MT_INTR         TM_INTR
#define MT_SLASH        TM_CORTE
#define MT_BLUDGEON     TM_APLASTAMIENTO
#define MT_PIERCE       TM_PENETRACION
#define MT_FIRE         TM_CALOR
#define MT_COLD         TM_FRIO
#define MT_WATER        TM_AGUA
#define MT_GAS          TM_GAS
#define MT_ZAP          TM_ZAP
#define MT_ELECTRO      TM_ELECTRICIDAD
#define MT_ACID         TM_ACIDO
#define MT_POISON       TM_VENENO
#define MT_PSYCHO       TM_PSIQUICO
#define MT_NOAIR        TM_VACIO

#define DT_CONV         TD_CONV   // Number of 'conventional' damages
#define DT_MAGIC        TD_MAGICO // First non-conventional damage

#define DT_CONVENTIONALS TD_CONV
//fin compatibilidad

#endif