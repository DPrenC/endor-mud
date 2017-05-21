/****************************************************************************
fichero: _hambre.c
Autor: kastwey@simauria
Descripción: Devuelve el nivel de hambre del player.
Creación: 19/11/2004
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
             comida =("Tu estómago ya no acepta más comida.");
             break;
        case 75.. 89:
             comida =("Estás suficientemente llen"+AO+".");
             break;
        case 50.. 74:
             comida =("No tienes hambre.");
             break;
        case 25.. 49:
             comida =("Sientes un ligero apetito.");
             break;
        case 10.. 24:
             comida =("Deberías comer algo.");
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
                      comida =("Podrías comerte un oso.");
                      break;
                 case -249 .. -50:
                      comida =("Te comerías las piedras.");
                      break;
                 case -499 .. -250:
                      comida =("Comienzas a ver visiones.");
                      break;
                 default:
                      comida =("Estás muy hambrient" + AO + " (" + i + ").");
             }
    }
    write((TP->QueryTiflo() ? MSG_SPEAK : "") + comida + "\n");
    return 1;
}