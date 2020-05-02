// exception.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.


#include <iostream> 
#include <fstream>
#include <vector>
#include <locale>

using namespace std;

int main()
{
    //C++ Дуже сложна мова програмування, потрібно мінімум 3 роки щоб освоїти її!!!
    //i love python

    //Структурне програмування легше за ООП

    //А ще проблема із українською мовою у консолі...

    //wcout<<L і <locale> --- не допомагає, тому попередні лабкии були на ENG|

    //unicode свій напсати?

    //...

    setlocale(LC_ALL, "Russian");
    int k = 0,max;
    vector<string>q;
    vector<string> str;
    string data; 
    string temp;
    cout << "Введіть розмір складу продуктів (від 2 до 5): " << endl;
    cin >> max;
    cout << "'put' --- для добавлення продуктів на склад " << endl;
    cout << "'get' --- отримати продукти зі складу : " << endl;
    cout << "'cook' --- приготувати страву : " << endl;
    cout << "Введіть 'exit' для виходу" << endl;
    cout << "ДЛЯ ПРИГОТУВАННЯ СТРАВИ ВИ ПОВИННІ ОТРИМАТИ ПРОДУКТИ ІЗ СКЛАДУ!" << endl;
        string choice = "put"; //'x','p','c' або 'g'
        do //цикл 
        {
            try //
            {
                cout << "cook*?>";
                cin >> choice;
                if (choice == "put")
                {
                    cout << "Введіть назву продукта:";
                    cin >> data;
                    k++;
                    if (k > max) 
                    {
                        throw k;
                    }
                    q.push_back(data);
                    cout << data << " - Успішно добавлено на склад" << endl;
                }
                if (choice == "get")
                {
                    if (q.empty())
                    {
                        throw - 1;
                    }
                    str.push_back(q[0]);
                    q.erase(q.begin());
                    cout << "Вибрані продукти зі складу:" << endl;
                    for (int i = 0; i < str.size(); i++)
                    {
                        cout << str[i] << endl;
                    }
                }
                if (choice == "cook")
                {
                    cout << "Страва приготовлена із таких продуктів: " << endl;
                    for (int i = 0; i < str.size(); i++)
                    {
                        cout << str[i] << endl;
                    }
                    ofstream file("dishes.txt",ios::app);
                    if (file.is_open())
                    {
                        for (int i = 0; i < str.size(); i++)
                        {
                            file << str[i] << endl;
                        }
                        file << "-------------------" << endl;
                    }
                }
            } 
            catch (int n)
            {
                if (n > max)
                    cout << "Помилка: склад переповнений!" << endl;
                if (n == -1)
                    cout << "Помилка: склад пустий." << endl;
            }
        } while (choice != "exit");
   system("pause");
    return 0;
}
