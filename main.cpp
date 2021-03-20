#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

bool busca(string str, vector<string> dicionario, int &index)
{
    // PERCORRE O DICIONARIO
    for (int i = 0; i < dicionario.size(); i++)
    {
        // SE ENCONTRAR A PALAVRA NO DICIONARIO
        if (dicionario[i] == str)
        {
            // INDICE É ATUALIZADO COM A POSIÇÃO NO QUAL A PALAVRA SE ENCONTRA NO DICIONARIO
            index = i+1;
            return  true;
        }
    }
    return false;
}

int main()
{
    vector<string> dicionario;
    string entrada;
    string aux = "";
    int index = 0;
    ifstream arq;

    arq.open("entrada.txt", ios::in);
    getline(arq, entrada);

    for (int i = 0; i < entrada.length(); i++)
    {
        aux.push_back(entrada[i]);
        // VERIFICA SE HÁ A PALAVRA NO DICIONÁRIO
        if (busca(aux, dicionario, index))
        {
            // SE HOUVER IRÁ FAZER A BUSCA COM UMA STRING
            //  1 SÍMBOLO MAIOR ATÉ GERAR UMA PALAVRA NOVA NO DICIONÁRIO
            for (int j = i + 1; busca(aux, dicionario, index); j++)
            {
                aux.push_back(entrada[j]);
                // ATUALIZA O INDICE i PARA A ULTIMA POSIÇÃO PERCORRIDA NA STRING
                i = j;
            }
        }
        // SE A PALAVRA NÃO EXISTIR NO DICIONÁRIO INDICE = 0
        else
            index = 0;

        // TRATAMENTO PARA O CASO NO QUAL A STRING ACABA E NÃO É ENCONTRADA UMA NOVA PALAVRA PRA INSERÇÃO NO DICIONÁRIO    
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
    

    arq.close();
    return 0;
}
