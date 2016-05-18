#include "stdio.h"
#include "stdlist.h"

typedef struct
{
	MaillonLARC* List
} LARC

typedef struct
{
	ARC arc
	MaillonLARC* suivant
} MaillonLARC

