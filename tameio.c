#include "tameio.h"

void TameioDimiourgia(TTameio *tameio) //����������� �� ���� ��� struct ������
{
	tameio->TimeBusy = 0;
	tameio->TimeInactive = 0;
	tameio->enapomenonXronos = 0;
	tameio->ArithmoPleaton = 0;
}

// ������� ��� ������� ������� ��� ����������� ������������� ����� ������������
void TameioNewCustomer(TTameio *tameio, int Duration)
{
	tameio->ArithmoPleaton++;
	tameio->enapomenonXronos = Duration;
	TameioBusy(tameio);
}

// ������� ����� ������������ ���� 1
void TameioInService(TTameio *tameio)
{
	tameio->enapomenonXronos-=1;
}

void TameioNoWork(TTameio *tameio) // ������� ����� ���������
{
	tameio->TimeInactive+=1;
}

void TameioBusy(TTameio *tameio) // ������� ����� �����������
{
	tameio->TimeBusy+=1;
}

int TameioGetInactiveXronos(TTameio *tameio) // ���������� ����� ���������
{
	return tameio->TimeInactive;
}

int TameioGetBusyXronos(TTameio *tameio) // ���������� ����� �����������
{
	return tameio->TimeBusy;
}
int TameioFree(TTameio tameio) // ������� �� ����� ����������
{
	return tameio.enapomenonXronos == 0;
}

int TameioGetArithmosPelatwn(TTameio *tameio) // ���������� ������ �������
{
	return tameio->ArithmoPleaton;
}

