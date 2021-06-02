#include "blackjack.h"

// 5. 
// �������� ���������� ��������� ������ ��� ������ Card.���� ����� ����������� �������� �����(�� �� �� �����), 
// ������� ��, ���� �� �� �����, ������� ����� � ������� �����.����� ��� ������ GenericPlayer �������� ���������� 
// ��������� ������, ������� ������ ���������� ��� ������ � ��� �����, � ����� ����� ����� ����� ��� ����.
//


ostream& operator << (ostream& out, const Card& card)
{
	if (card.m_isFaceUp)
		out << "XX" << endl;
	else
		out << card.m_suit <<" "<< card.m_rank << endl;
	return out;
}

ostream& operator << (ostream& out, const GenericPlayer& gp)
{
	out << gp.m_playerName << " cards:" << endl;
	out << gp.getTotal() << endl;
	return out;
	
}