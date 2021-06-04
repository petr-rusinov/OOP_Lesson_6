#pragma once
#include <iostream>
#include <vector>

using namespace std;

enum eSuit { CLUBS, SPADES, DIAMONDS, HEARTS }; //������, ����, ����, �����
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
    friend ostream& operator << (ostream& out, const Card& card);
};


class Hand
{
protected:
    vector<Card*> m_cards; //������ ����
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
        if (acesNum < 2) //���� ����� ����� ������ 1, ��� ������ �� ������� ��� 11
        {
            if ((s + 10) <= 21) //������� ������� ��� ��� 11, ������� ��������� � ����� ����� 10
                s += 10;
        }
        return s;
    }
};


class GenericPlayer : public Hand
{
protected:
    string m_playerName;
public:
    GenericPlayer(const string& name) : m_playerName(name) { }
    virtual bool isHitting() const = 0;
    bool isBoosted() const
    {
        return getTotal() > 21;
    }

    void bust() const
    {
        cout << m_playerName << " busted" << endl;
    }
    friend ostream& operator << (ostream& out, const GenericPlayer& gp);
};

// 3.
// ����������� ����� Player, ������� ��������� �� ������ GenericPlayer.� ����� ������ ����� 4 ������:
// virtual bool IsHitting() const - ���������� ����� ����������� ������� �������� ������.
// ����� ���������� � ������������, ����� �� ��� ��� ���� ����� � ���������� ����� ������������ � ���� true ��� false.
// void Win() const - ������� �� ����� ��� ������ � ���������, ��� �� �������.
// void Lose() const - ������� �� ����� ��� ������ � ���������, ��� �� ��������.
// void Push() const - ������� �� ����� ��� ������ � ���������, ��� �� ������ ������.
class Player : public GenericPlayer
{
public:
    bool isHitting() const override
    {
        string yesNo = "";
        cout << "Do you need one more card? (y/n)" << endl;
        
        return (yesNo == "y" || yesNo == "Y") ? true : false;
    }
    void win() const
    {
        cout << "Player " << m_playerName << "won!" << endl;
    }
    void loose() const
    {
        cout << "Player " << m_playerName << "lost!" << endl;
    }
    void push() const
    {
        cout << "Player " << m_playerName << "drew!" << endl;
    }
};


// 4.
// ����������� ����� House, ������� ������������ ������.���� ����� ��������� �� ������ GenericPlayer.� ���� ���� 2 ������:
// virtual bool IsHitting() const - ����� ���������, ����� �� ������ ��� ���� �����.���� � ������ �� ������ 16 �����, �� �� ����� ��� ���� �����.
// void FlipFirstCard() - ����� �������������� ������ ����� ������.
//

class House : public GenericPlayer
{

public:
    bool isHitting() const override
    {
        return getTotal() < 16;
    }
    void flipFirstCard()
    {
        if (!m_cards.empty())
        {
            m_cards[0]->flip();
        }
    }
};

// 5. 
// �������� ���������� ��������� ������ ��� ������ Card.���� ����� ����������� �������� �����(�� �� �� �����), 
// ������� ��, ���� �� �� �����, ������� ����� � ������� �����.����� ��� ������ GenericPlayer �������� ���������� 
// ��������� ������, ������� ������ ���������� ��� ������ � ��� �����, � ����� ����� ����� ����� ��� ����.
//


