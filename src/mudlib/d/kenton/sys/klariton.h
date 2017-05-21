/***************************************************************************
Fichero: klariton.h
Autor: [kastwey]
Creación: 19/07/2005
Descripción: Sacado del path.h, reescrito y movido al sys
Se que klariton no está abierto, pero prefiero que, ya que está subido, al
menos que estén las cosas en su sitio.
***************************************************************************/


// defines de Klariton

#define ROOMFA(x)    KLARHAB + "aldea_old/" +x
#define ROOMFB(x)    KLARHAB + "bosque_old/"+x
#define PNJSFF(x)    KLARPNJ	+x
#define PNJSFB(x)    KLARPNJ + "bosque_old/"+x
#define BKENTON(x)   ROOMFA("bosque/" + x)
// bosque base de la aldea
#define BOSBASE      ROOMFA("bosque/base")

#define PQUEST(x)    QUEST + "bruja/"+x
