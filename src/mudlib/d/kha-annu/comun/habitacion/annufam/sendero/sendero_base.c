/**************************************************************************
fichero: sendero_base.c
Autor: kastwey
Creaci�n: 23/07/2005
Descripci�n: Sendero base para el sendero de annufam
**************************************************************************/

#include "./path.h"

inherit KHA_ROOM;

public void create()
{
    ::create();
    SetIndoors(0);
    SetIntSmell("El olor a pino es intenso aqu�.\n");
    SetIntNoise("Escuchas el susurro del viento.\n");
    AddDetail(({"pino","pinos"}),
              W("Son unos �rboles con una hoja de tipo aguja. Piensas que "
                "son muy t�picos de estas tierras, pues abundan en toda esta "
                "zona. �stos particularmente parecen tener ya una edad "
                "considerable puesto que su tronco se ve bastante grueso.\n"));
  AddDetail(({"hayas","haya"}),
            W("Son las hayas que has visto en muchas ocasiones. Aunque son "
              "abundantes, quedan un poco deprimidas a causa de la gran "
              "presencia de los pinos.\n"));
    AddDetail(({"matorral","matorrales"}),
              W("Son plantas bajas que se encuentran casi a ras de suelo. "
                "Parece que dejan un caminito por donde podr�as pasar.\n"));
    AddDetail("suelo",W("El suelo est� repleto de hojas de pino.\n"));
    AddDetail("cielo",W("Apenas puedes ver el firmamento con la cantidad de "
                        "�rboles que te lo impiden.\n"));
}
