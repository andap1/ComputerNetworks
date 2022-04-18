#include <iostream>
#include <fstream>
#include <vector>
std::ifstream f("date.txt");
void citire(std::vector<int> &vec, int l)
{
    f >> l;
    int binar;
    for (int index = 0; index < l; index++)
    {
        f >> binar;
        vec.push_back(binar);
    }
}
void afisare(std::vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
}
int verificare_binar(std::vector<int> v)
{
    int ok = 1;
    for (int index = 0; index < v.size()&&ok==1; index++)
        if (v[index] == 0 || v[index] == 1)
            ok = 1;
        else
            ok = 0;
    return ok;
}
int XOR(int bin1, int bin2)
{
    
    if (bin1 == 0 && bin2 == 0)
        return 0;
    if (bin1 == 0 && bin2 == 1)
        return  1;
    if (bin1 == 1 && bin2 == 0)
        return  1;
    if (bin1 == 1 && bin2 == 1)
        return  0;
    

}
void intoarcere(std::vector<int> &v)
{
    std::vector<int> v2;
    for (int index = v.size() - 1; index >= 0; index--)
        v2.push_back(v[index]);
    for (int index = 0; index < v2.size(); index++)
        v[index] = v2[index];
}
int main()
{
    //declarari
    int binar;
    int gradMesajInitial = 0;
    std::vector<int> mesajInitial;
    int gradPolinomGenerator, nrPolinomGenerator = 0;
    std::vector<int> polinomGenerator;
    std::vector<int> mesajExtins;
    std::vector<int> mesajRest; 



    //citiri
    citire(mesajInitial, gradMesajInitial);
    verificare_binar(mesajInitial);
    citire(polinomGenerator, nrPolinomGenerator);
    f >> gradPolinomGenerator;

    if (verificare_binar(mesajInitial) == 1 && verificare_binar(polinomGenerator) == 1)
    {
        //creare mesaj extins
        for (int index = 0; index < mesajInitial.size(); index++)
            mesajExtins.push_back(mesajInitial[index]);

        while (gradPolinomGenerator != 0)
        {
            mesajExtins.push_back(0);
            gradPolinomGenerator = gradPolinomGenerator - 1;
        }

        //prima data mesajul rest=mesaj extins
        for (int index = 0; index < mesajExtins.size(); index++)
            mesajRest.push_back(mesajExtins[index]);

        afisare(mesajRest);
        std::cout << std::endl;

        while (mesajRest.size() > polinomGenerator.size())
        {
            if (mesajRest[0] == 0)
            {
                intoarcere(mesajRest);
                while (mesajRest[mesajRest.size() - 1] == 0)
                {
                    mesajRest.pop_back();
                }
                intoarcere(mesajRest);
            }
            if (mesajRest.size() > polinomGenerator.size())
            {
                std::vector<int> aux;
                for (int index = 0; index < polinomGenerator.size(); index++)
                    aux.push_back(mesajRest[index]);


                for (int index = 0; index < polinomGenerator.size(); index++)
                {
                    mesajRest[index] = XOR(aux[index], polinomGenerator[index]);
                }
            }
            afisare(mesajRest);
            std::cout << std::endl;

        }
        std::vector<int> mesajFinal;
        for (int index = 0; index < mesajExtins.size(); index++)
            mesajFinal.push_back(mesajExtins[index]);
        int index2 = 0;
        for (int index = mesajExtins.size() - mesajRest.size(); index < mesajExtins.size(); index++)
        {
            mesajFinal[index] = XOR(mesajExtins[index], mesajRest[index2]);
            index2++;
        }
        afisare(mesajFinal);
        std::cout << std::endl;

    }
    else
        std::cout << "nu sunt in binar";
}

