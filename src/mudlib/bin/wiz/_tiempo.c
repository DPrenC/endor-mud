#include <config.h>
int main()
{
  write("Son las "+CHRONOS->QueryHour()+" horas "+CHRONOS->QueryMinute()+" minutos "+CHRONOS->QuerySecond()+" segundos del d�a "+CHRONOS->QueryDay()+" del mes "+CHRONOS->QueryMonth()+" del a�o "+CHRONOS->QueryYear()+".\n");
  return 1;
}
