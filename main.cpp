//
//  main.cpp
//  BW
//
//  Created by João Miguel on 13/07/20.
//  Copyright © 2020 João Miguel. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <string>


using namespace std;

class BurrowsWheller
{
private:
    string palavra;
public:
    BurrowsWheller(string p_palavra)
    {
        palavra = p_palavra;
    }

    string getPalavra()
    {
        return palavra;
    }

    string passo1(string entrada)
    {
        string str;
        str.append("^");
        str.append(entrada);
        str.append("|");
        return str;
    }

    string* passo2(string entradaModif)
    {
        int n = int(entradaModif.length());
        string* rotacoes = new string[n];

        for(int i = 0; i < n; i++)
        {
            rotacoes[i].append(entradaModif, n-i, i);                   // "10 "
            rotacoes[i].append(entradaModif, 0, n-i);

            //cout << rotacoes[i] << endl;
        }

        return rotacoes;
    }

    string* passo3(string* rotacoes)
    {
        int n = (int)(rotacoes[0].length());

        for(int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if(rotacoes[i]>rotacoes[j])
                    rotacoes[i].swap(rotacoes[j]);
            }
            //cout << rotacoes[i] << endl;
        }

        return rotacoes;
    }

    string passo4(string* rotacoesOrdenadas)
    {
        string resultado;

        int n = (int)rotacoesOrdenadas[0].length();
        for (int i = 0; i < n; i++)
        {
            resultado.append(rotacoesOrdenadas[i], n-1, 1);
        }

        delete[] rotacoesOrdenadas;

        return resultado;
    }

    string transformadaBurroewsWheeler()
    {

        palavra = passo4(passo3(passo2(passo1(palavra))));
        return palavra;
    }
};

class BurrowsWhellerInversa{
private:
    string palavra;

public:
    BurrowsWhellerInversa(string p_palavra)
    {
        palavra = p_palavra;
    }

    string getPalavra()
    {
        return palavra;
    }

    string* ordena(string* rotacoes, int n)
    {
        for(int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if(rotacoes[i]>rotacoes[j])
                    rotacoes[i].swap(rotacoes[j]);
            }
            //cout << rotacoes[i] << endl;
        }

        return rotacoes;
    }


    string transformadaBurroewsWheelerInversa(){

        string* aux = new string[palavra.length()];
        for (int i = 0; i < palavra.length(); i++) aux[i].append(palavra, i, 1);

        for (int i = 0; i < palavra.length(); i++){
            for (int i = 0; i < palavra.length(); i++) cout << aux[i] << endl;
            cout << endl;
            ordena(aux, (int)(palavra.length()));
            for (int j = 0; j < palavra.length(); j++) aux[j].append(palavra, j, 1);
        }

        //achar ultimo cara
        for (int i = 0; i < palavra.length(); i++){
            if(aux[i][0] == '^'){
                return aux[i];
            }
        }
    }
};

int main()
{
    string Banana = "BANANA";

    BurrowsWheller BW(Banana);

    cout << BW.getPalavra() << endl;

    cout << BW.transformadaBurroewsWheeler() << endl;


    BurrowsWhellerInversa BWI(BW.getPalavra());

    cout << BWI.getPalavra() << endl;

    cout << BWI.transformadaBurroewsWheelerInversa() << endl;

    return 0;
}
