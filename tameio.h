/*************************************************
Arxeio ylopoihshs	: ch6_Simulation.c
Syggrafeas			: Y. Cotronis 07/03/2016
Skopos				: Ylopoihsh ouras prosomoiwshs
Revision 			:  <Argyriou Nikolaos-23/3/18>
**************************************************/
#ifndef TAMEIO_H
#define TAMEIO_H

#include <stdio.h>

typedef struct TTameio {
	int TimeBusy; /* Xronos pou itan apasxolimenos */
	int TimeInactive; /* Xronos itan adranis */
	int ArithmoPleaton; /* Arithmos pelatwn pou eksipiretise */
	int enapomenonXronos; /* Enapomenon xronos gia eksipiretisi pelati */
} TTameio;

void TameioDimiourgia(TTameio *); //����������� �� ���� ��� struct ������
void TameioNoWork(TTameio *); // ������� ����� ���������
void TameioNewCustomer(TTameio *, int Duration); // ������� ��� ������� ������� ��� ����������� ������������� ����� ������������
void TameioInService(TTameio *); // ������� ����� ������������ ���� 1
void TameioBusy(TTameio *); // ������� ����� �����������
int TameioGetArithmosPelatwn(TTameio *); // ���������� ��� ������ �������
int TameioGetInactiveXronos(TTameio *); // ���������� ����� ���������
int TameioFree(TTameio); // ������� �� ����� ���������
int TameioGetBusyXronos(TTameio *); // ���������� ����� �����������

#endif
