/***************************************************************************
Fichero: klariton.h
Autor: [kastwey]
Creaci�n: 19/07/2005
Descripci�n: Sacado del path.h, reescrito y movido al sys
Se que klariton no est� abierto, pero prefiero que, ya que est� subido, al
menos que est�n las cosas en su sitio.
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
