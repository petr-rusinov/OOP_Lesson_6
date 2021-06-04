#include <iostream>
#include "blackjack.h"

using namespace std;

// 1.
// Создать программу, которая считывает целое число типа int.И поставить «защиту от дурака» : 
// если пользователь вводит что - то кроме одного целочисленного значения, нужно вывести сообщение 
// об ошибке и предложить ввести число еще раз.Пример неправильных введенных строк :
// rbtrb
// nj34njkn
// 1n

bool inputIntNumber(int& number)
{
    cin >> number;
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(32767, '\n');
        return false;
    }
    else
        return true;
}


void task_1()
{
    int numberToInput = 0;

    cout << "Input int number:" << endl;
    while (!inputIntNumber(numberToInput))
    {
        cout << "try again" << endl;
    }
    cout << "Your number: " << numberToInput << endl;
}

// 2.
// Создать собственный манипулятор endll для стандартного потока вывода, который выводит два перевода строки и сбрасывает буфер.
//

ostream& endll(ostream& out)
{
    out << endl << endl;
    return out;
}

// 3.
// Реализовать класс Player, который наследует от класса GenericPlayer.У этого класса будет 4 метода:
// virtual bool IsHitting() const - реализация чисто виртуальной функции базового класса.
// Метод спрашивает у пользователя, нужна ли ему еще одна карта и возвращает ответ пользователя в виде true или false.
// void Win() const - выводит на экран имя игрока и сообщение, что он выиграл.
// void Lose() const - выводит на экран имя игрока и сообщение, что он проиграл.
// void Push() const - выводит на экран имя игрока и сообщение, что он сыграл вничью.
//
// 4.
// Реализовать класс House, который представляет дилера.Этот класс наследует от класса GenericPlayer.У него есть 2 метода:
// virtual bool IsHitting() const - метод указывает, нужна ли дилеру еще одна карта.Если у дилера не больше 16 очков, то он берет еще одну карту.
// void FlipFirstCard() - метод переворачивает первую карту дилера.
//
// 5. 
// Написать перегрузку оператора вывода для класса Card.Если карта перевернута рубашкой вверх(мы ее не видим), 
// вывести ХХ, если мы ее видим, вывести масть и номинал карты.Также для класса GenericPlayer написать перегрузку 
// оператора вывода, который должен отображать имя игрока и его карты, а также общую сумму очков его карт.
//



int main()
{
    //task_1();
    cout << "Test message1 " << endl << "Test message2" << endll << "Test message3" << endl;


    Card c(CLUBS, QUEEN, true);
    cout << c;

    Player p("Peter");
    if (p.isHitting())
        cout << true << endl;
    else
        cout << false << endl;
    p.win();
    p.loose();
    p.push();
    p.bust();
}
