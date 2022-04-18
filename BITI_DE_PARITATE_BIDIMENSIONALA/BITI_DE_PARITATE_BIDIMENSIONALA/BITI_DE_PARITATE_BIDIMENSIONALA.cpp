#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void afisare (std::vector<std::vector<int>> mat)
{
    for (int i = 0 ; i < mat.size() ; i++)
    {
        for (int j = 0; j < mat[i].size(); j++)
            std::cout << mat[i][j]<<" ";
        std::cout << std::endl;

     }
}
int main()
{
   std::string s;
   std::ifstream f("Text.txt");
   std::getline(f, s);
   //std::cout << s.length();
   std::vector<std::vector<int>> matBiti;
   
   for (int index = 0; index < s.length(); index++)
       {
       if (s[index] != ' ')
       {
           std::vector<int> vect;
           int nr = 0;
           int val = int(s[index]);
           while (val > 0)
           {
               vect.push_back(val % 2);
               val = val / 2;
               nr++;
           }
           vect.push_back(0);
           if (nr == 7)
           {
               matBiti.push_back(vect);
           }
               
           else
               while (nr < 8)
               {
                   matBiti[index].push_back(0);
                   nr++;
               }
           
           }
               
              
         }
   std::cout << "Matricea initiala:" << std::endl;
   afisare(matBiti);
   std::cout << std::endl;
   std::vector<int> coloana;
   std::vector<int> linie;
 
   for (int i = 0; i < matBiti.size(); i++)
   {
       int nr1 = 0;
       for (int j = 0; j < matBiti[i].size(); j++)
           if (matBiti[i][j] == 1)
               nr1++;
       if (nr1 % 2 == 0)
           linie.push_back(0);
       else
           linie.push_back(1);
   }
   std::cout << "linie adaugata:" << std::endl;
   int nr1Linie = 0;
   for (int index = 0; index < linie.size(); index++)
   {
       std::cout << linie[index] << " ";
       if (linie[index] == 1)
           nr1Linie++;

   }
   std::cout<< std::endl;
   for (int j = 0; j < 7; j++)
   {
       int nr1 = 0;
       for (int i = 0; i < matBiti.size(); i++)
           if (matBiti[i][j] == 1)
               nr1++;
       if (nr1 % 2 == 0)
           coloana.push_back(0);
       else
           coloana.push_back(1);
   }
   std::cout << "coloana adaugata:" << std::endl;
   int nr1Coloana = 0;
   for (int index = 0; index < coloana.size(); index++)
   {
       if (coloana[index] == 1)
           nr1Coloana++;
       std::cout << coloana[index] << " ";
   }
   std::cout << std::endl;
   std::cout << "BITUL SEMNIFICATIV:";
   int bitSemnificativC;
   if (nr1Coloana % 2 == 0)
       bitSemnificativC = 0;
   else
       bitSemnificativC = 1;
   int bitSemnificatiL;
   if (nr1Linie % 2 == 0)
       bitSemnificatiL = 0;
   else
       bitSemnificatiL = 1;
   if(bitSemnificatiL== bitSemnificativC)
      coloana.push_back(bitSemnificativC);
   matBiti.push_back(coloana);
   
   std::cout<< bitSemnificativC << std::endl;
  
   for (int index = 0; index < linie.size(); index++)
       matBiti[index][7] = linie[index];
  
   std::cout << "matricea dupa adaugarea linia+coloana:" << std::endl;
   afisare(matBiti);
   
   int indexL, indexC;
   indexL = rand() % matBiti.size();
   indexC = rand() % 8;

   if (matBiti[indexL][indexC] == 0)
       matBiti[indexL][indexC] =1;
   else
   {
      
           matBiti[indexL][indexC] = 0;
   }
  
   std::cout<<"INDEX CORUPT RANDOM  " << indexL << " " << indexC<< std::endl;
   std::cout << std::endl << "MATRICEA DUPA CORUPERE:" << std::endl;
   afisare(matBiti);





   int indexCoruptL=-1, indexCoruptC=-1;
   int ok = 0;

   for (int j = 0; j <7 &&ok==0; j++)
   {

 
       int nr1 = 0;
       for (int i = 0; i < matBiti.size()-1; i++)
           if (matBiti[i][j] == 1)
               nr1++;
       if (nr1 % 2 == 0)
           nr1 = 0;
       else
           nr1 = 1;
       if (nr1 != matBiti[matBiti.size() - 1][j])
       {
           indexCoruptC = j;
           ok = 1;
       }
           
       
   }
   ok = 0;
   for (int i = 0; i < matBiti.size()&&ok==0; i++)
   {
       int nr1 = 0;
       for (int j = 0; j < 7; j++)
           if (matBiti[i][j] == 1)
               nr1++;
       if (nr1 % 2 == 0)
           nr1 = 0;
       else
           nr1 = 1;

       if (nr1 != matBiti[i][7])
       {
           indexCoruptL = i;
           ok = 1;
       }
   }
   
   std::cout << std::endl;
   std::cout << "POZITIILE BITULUI CORUPT:" << std::endl;
   std::cout << indexCoruptL << " " << indexCoruptC;
}

