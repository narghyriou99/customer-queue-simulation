/*************************************************
Arxeio ylopoihshs	: ch6_Simulation.c
Syggrafeas			: Y. Cotronis 07/03/2016
Skopos				: Ylopoihsh ouras prosomoiwshs
Revision 			:  <Argyriou Nikolaos-23/3/18>
**************************************************/
#include <stdio.h>
#include "TStoixeiouOuras.h"

void TSOurasSetValue(TSOuras *stoixeioPtr, TSOuras data)
{   
	*stoixeioPtr = data;  /* basic type assignment */
}

void PelatisSetXronoEisodou(TSOuras *stoixeioPtr, int xronos)
{
	stoixeioPtr->XronosEisodou=xronos;
}

int PelatisGetXronoEksipiretisis(TSOuras *stoixeioPtr)
{
	return stoixeioPtr->XronosEksipiretisis;
}

int PelatisGetXronoEisodou(TSOuras stoixeio)
{
	return stoixeio.XronosEisodou;
}

void PelatisSetXronoEksipiretisis(TSOuras *stoixeioPtr, int xronos)
{
	stoixeioPtr->XronosEksipiretisis = xronos;
}
