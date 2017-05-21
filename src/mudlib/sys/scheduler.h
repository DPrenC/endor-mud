#ifndef _SCHEDULER_
#define _SCHEDULER_

#include <nightday.h>

#define S_UNKNOWN         0
#define S_OPENED          1
#define S_CLOSED          2
#define S_CLOSING         3
#define TIME_TO_INFORM    60
#define IS_SCHEDULER(x)   (member(inherit_list(x), SCHEDULER_ROOM ".c") >= 0)
#define S_CLOSED_AT_NIGHT ({ND_NIGHT, ND_PREDAWN, ND_DAWN, ND_SUNRISE})
#endif
