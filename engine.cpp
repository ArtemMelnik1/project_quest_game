#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;






int main() {
    vector<vector<int>> varities; // варианты ответов для каждой строки (по сути состоит из var1)
    vector<int> var1(0); // варианты ответов (всего 2 ячейки)
    int l = 0;
    vector<int> num_str; // вектор, состоящий из номеров строк (первое число в строке)

    string ffff;


    bool igra=true;
    ifstream f1;
    vector<string> stroka;
    string strochka;
    string chisletsa; // варианты ответов (на какую строку переход)





    f1.open("game.txt");
    if (!f1.is_open())
        cout << "do svidaniya!\n";




    while(!f1.eof()){
        getline(f1, strochka);
        ffff += strochka[0];
        int neww = atoi(ffff.c_str());
        num_str.push_back(neww); // добавление номера строки
        strochka.erase(strochka.begin(), strochka.begin()+2); // удаление этого номера из строки (чтобы вывод был без него)
        ffff.clear();
        int p = strochka.length();





        if (isdigit(strochka[p-1])){
            chisletsa += strochka.substr(strochka.length()-3, 3);
            strochka.erase(strochka.end()-3, strochka.end()); // удаление вариантов ответов из основного текста (чтобы выводился только основной текст)
        }




        for (char s : chisletsa){
            if (isdigit(s)){
                ffff += s;
                int neww1 = atoi(ffff.c_str());
                var1.push_back(neww1); // загоняем в вектор варианты ответов
                ffff.clear();
            }
        }




        varities.push_back(var1); // загоняем в основной вектор вариантов ответов
        var1.clear();
        chisletsa.clear();
        stroka.push_back(strochka);
    }






    while(igra){
        for (int n = 0; n <= stroka.size();){
            int inp;
            cout << stroka[n]<< endl; // вывод строки (уже без лишних чисел) n - номер строкип
            cin >> inp;
            if (inp == 1){
                n = varities[l][0]; //лучше проверить на debug, как это происходит
                l = varities[l][0]; //лучше проверить на debug, как это происходит
            }
            else if (inp == 2){
                n = varities[l][1]; //лучше проверить на debug, как это происходит
                l = varities[l][1]; //лучше проверить на debug, как это происходит
            }
        }
    }
}