/****************************************************************************
fichero: _hambre.c
Autor: kastwey@simauria
Descripci�n: Devuelve el nivel de hambre del player.
Creaci�n: 19/11/2004
****************************************************************************/

#define MSG_SPEAK "all_speak:"
#define AO TP->QueryGenderEndString()

public int main()
{
    int i = (TP->QueryFood()*100) / (TP->QueryMaxFood()||1);
    string comida;
    switch(i)
    {
        case 90..101:
             comida =("Tu est�mago ya no acepta m�s comida.");
             break;
        case 75.. 89:
             comida =("Est�s suficientemente llen"+AO+".");
             break;
        case 50.. 74:
             comida =("No tienes hambre.");
             break;
        case 25.. 49:
             comida =("Sientes un ligero apetito.");
             break;
        case 10.. 24:
             comida =("Deber�as comer algo.");
             break;
        case  0.. 9:
             comida =("Tienes hambre.");
             break;
        default:
             i = TP->QueryFood();
             switch(i)
             {
                 case -9.. -1:
                      comida =("Tienes mucha hambre.");
                      break;
                 case -49 .. -10:
                      comida =("Podr�as comerte un oso.");
                      break;
                 case -249 .. -50:
                      comida =("Te comer�as las piedras.");
                      break;
                 case -499 .. -250:
                      comida =("Comienzas a ver visiones.");
                      break;
                 default:
                      comida =("Est�s muy hambrient" + AO + " (" + i + ").");
             }
    }
    write((TP->QueryTiflo() ? MSG_SPEAK : "") + comida + "\n");
    return 1;
}