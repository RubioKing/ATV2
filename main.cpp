#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

bool busca(string str, vector<string> dicionario, int &index)
{
    for (int i = 0; i < dicionario.size(); i++)
    {
        if (dicionario[i] == str)
        {
            if (str.size() >= 1)
            {
                index = i+1;
            }
            return  true;
        }
    }
    return false;
}

int main()
{
    vector<string> dicionario;
    string entrada = "testeteste";
    string aux = "";
    int index = 0;

    for (int i = 0; i < entrada.length(); i++)
    {
        aux.push_back(entrada[i]);
        if (busca(aux, dicionario, index))
        {
            for (int j = i + 1; busca(aux, dicionario, index); j++)
            {
                aux.push_back(entrada[j]);
                i = j;
            }
        }
        else
            index = 0;
        if (aux[aux.size() - 1] == '\0')
        {
            cout << "(" << index << ", null)" << endl;
        }
        else
        {
            cout << "(" << index << ", " << aux[aux.size() - 1] << ")" << endl;
        }
        dicionario.push_back(aux);
        aux = "";
    }
    

    
    return 0;
}
