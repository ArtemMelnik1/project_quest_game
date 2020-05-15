#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;






int main() {
    vector<vector<int>> varities;
    vector<int> var1(0);
    int l = 0;
    vector<int> num_str;

    string ffff;


    bool igra=true;
    ifstream f1;
    vector<string> stroka;
    string strochka;
    string chisletsa;





    f1.open("game.txt");
    if (!f1.is_open())
        cout << "do svidaniya!\n";




    while(!f1.eof()){
        getline(f1, strochka);
        ffff += strochka[0];
        int neww = atoi(ffff.c_str());
        num_str.push_back(neww);
        strochka.erase(strochka.begin(), strochka.begin()+2);
        ffff.clear();
        int p = strochka.length();





        if (isdigit(strochka[p-1])){
            chisletsa += strochka.substr(strochka.length()-3, 3);
            strochka.erase(strochka.end()-3, strochka.end());
        }




        for (char s : chisletsa){
            if (isdigit(s)){
                ffff += s;
                int neww1 = atoi(ffff.c_str());
                var1.push_back(neww1);
                ffff.clear();
            }
        }




        varities.push_back(var1);
        var1.clear();
        chisletsa.clear();
        stroka.push_back(strochka);
    }






    while(igra){
        for (int n = 0; n <= stroka.size();){
            int inp;
            cout << stroka[n]<< endl;
            cin >> inp;
            if (inp == 1){
                n = varities[l][0];
                l = varities[l][0];
            }
            else if (inp == 2){
                n = varities[l][1];
                l = varities[l][1];
            }
        }
    }
}