#include "blackjack.h"

// 5. 
// Написать перегрузку оператора вывода для класса Card.Если карта перевернута рубашкой вверх(мы ее не видим), 
// вывести ХХ, если мы ее видим, вывести масть и номинал карты.Также для класса GenericPlayer написать перегрузку 
// оператора вывода, который должен отображать имя игрока и его карты, а также общую сумму очков его карт.
//


ostream& operator << (ostream& out, const Card& card)
{
	const string ranks[] = { "", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
	// символы псевдографики:
	// \x3 - черви (hearts)
	// \x4 - буби (diamonds)
	// \x5 - крести (clubs)
	// \x6 - пики (spades)
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