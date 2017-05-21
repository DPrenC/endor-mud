/**************************************************************************
fichero: sendero_base.c
Autor: kastwey
Creación: 23/07/2005
Descripción: Sendero base para el sendero de annufam
**************************************************************************/

#include "./path.h"

inherit KHA_ROOM;

public void create()
{
    ::create();
    SetIndoors(0);
    SetIntSmell("El olor a pino es intenso aquí.\n");
    SetIntNoise("Escuchas el susurro del viento.\n");
    AddDetail(({"pino","pinos"}),
              W("Son unos árboles con una hoja de tipo aguja. Piensas que "
                "son muy típicos de estas tierras, pues abundan en toda esta "
                "zona. Éstos particularmente parecen tener ya una edad "
                "considerable puesto que su tronco se ve bastante grueso.\n"));
  AddDetail(({"hayas","haya"}),
            W("Son las hayas que has visto en muchas ocasiones. Aunque son "
              "abundantes, quedan un poco deprimidas a causa de la gran "
              "presencia de los pinos.\n"));
    AddDetail(({"matorral","matorrales"}),
              W("Son plantas bajas que se encuentran casi a ras de suelo. "
                "Parece que dejan un caminito por donde podrías pasar.\n"));
    AddDetail("suelo",W("El suelo está repleto de hojas de pino.\n"));
    AddDetail("cielo",W("Apenas puedes ver el firmamento con la cantidad de "
                        "árboles que te lo impiden.\n"));
}
