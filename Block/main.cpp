﻿// Block.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Block.h"

int main()
{

    Block a; // default
    Block b{ 4, new int[4]{0, 1, 2, 3}}; //my ctor
    Block c{ Block{ 4, new int[4]{0, 1, 2, 3} } }; // move ctor
    Block d{ b }; //copy ctor

    a = Block{ 4, new int[4]{0, 1, 2, 3} }; // оператор присваивания переносом
    a = Block{ 4, new int[4]{0, 1, 2, 3} };

    std::cout << b + 14;
    std::cout << b + c;
    std::cout << b - 0;
    std::cout << b - d;
    std::cout << b * 2;
    std::cout << c * b;
    std::cout << c / 2;
    std::cout << c / 3;
    std::cout << --c;
    std::cout << c--;
    std::cout << c;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
