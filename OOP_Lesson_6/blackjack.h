#pragma once
#include <iostream>
#include <vector>

using namespace std;

enum eSuit { CLUBS, SPADES, DIAMONDS, HEARTS }; //крести, пики, буби, черви
enum eRank { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };

class Card
{
    eSuit m_suit;
    eRank m_rank;
    bool m_isFaceUp;
public:
    Card(eSuit suit, eRank value, bool pos) : m_suit(suit), m_rank(value), m_isFaceUp(pos) {}
    void flip() { m_isFaceUp = !m_isFaceUp; }
    int getValue() const
    {
        int value = 0;
        if (m_isFaceUp)
        {
            value = m_rank;
            if (value > 10)
            {
                value = 10;
            }
        }
        return value;
    }
};


class Hand
{
private:
    vector<Card*> m_cards; //колода карт
public:
    Hand() { m_cards.reserve(7); }
    virtual ~Hand() { clear(); }
    void add(Card* pCard) { m_cards.push_back(pCard); }
    void clear()
    {
        vector<Card*>::iterator iter = m_cards.begin();
        for (iter = m_cards.begin(); iter != m_cards.end(); ++iter)
        {
            delete* iter;
            *iter = 0;
        }
        m_cards.clear();
    }
    int getTotal() const
    {

        if (m_cards.empty())
        {
            return 0;
        }
        if (m_cards[0]->getValue() == 0)
        {
            return 0;
        }

        int s = 0;
        int acesNum = 0;
        for (Card* c : m_cards)
        {
            int val = c->getValue();
            if (val == ACE) acesNum++;
            s += val;
        }
        if (acesNum < 2) //Если вдруг тузов больше 1, нет смысла их считать как 11
        {
            if ((s + 10) <= 21) //Пробуем считать туз как 11, поэтому добавляем к общей сумме 10
                s += 10;
        }
        return s;
    }
};


class GenericPlayer : public Hand
{
private:
    string m_playerName;
public:
    virtual bool isHitting() = 0;
    bool isBoosted()
    {
        return getTotal() > 21;
    }

    void bust()
    {
        cout << m_playerName << " busted" << endl;
    }
};