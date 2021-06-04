#include "blackjack.h"

// 5. 
// �������� ���������� ��������� ������ ��� ������ Card.���� ����� ����������� �������� �����(�� �� �� �����), 
// ������� ��, ���� �� �� �����, ������� ����� � ������� �����.����� ��� ������ GenericPlayer �������� ���������� 
// ��������� ������, ������� ������ ���������� ��� ������ � ��� �����, � ����� ����� ����� ����� ��� ����.
//


ostream& operator << (ostream& out, const Card& card)
{
	const string ranks[] = { "", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
	// ������� �������������:
	// \x3 - ����� (hearts)
	// \x4 - ���� (diamonds)
	// \x5 - ������ (clubs)
	// \x6 - ���� (spades)
	const string suits[] = { "\x5", "\x6", "\x4", "\x3" };
	if (card.m_isFaceUp)
		out << ranks[card.m_rank] << suits[card.m_suit] << endl;
	else
		out << "XX" << endl;
	return out;
}

ostream& operator << (ostream& out, const GenericPlayer& gp)
{
	out << gp.m_playerName << " cards:" << endl;
	if (!gp.m_cards.empty())
	{
		for (Card* c : gp.m_cards)
		{
			out << *c << " ";
		}
		out << endl;
		out << "Total: ";
		out << gp.getTotal() << endl;
	}
	else
		out << "Empty" << endl;
	return out;
}