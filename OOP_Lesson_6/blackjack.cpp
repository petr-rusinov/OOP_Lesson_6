#include "blackjack.h"

// 5. 
// Написать перегрузку оператора вывода для класса Card.Если карта перевернута рубашкой вверх(мы ее не видим), 
// вывести ХХ, если мы ее видим, вывести масть и номинал карты.Также для класса GenericPlayer написать перегрузку 
// оператора вывода, который должен отображать имя игрока и его карты, а также общую сумму очков его карт.
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