#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//su konst neiseina tai be jo dariau
//const int max=1000;

class Tekstas
{
  private:
  string word[1000]; //zodziu masyvas
  string line[1000]; //eiluciu masyvas
  string sentences[1000]; //sakiniu masyvas
  int skaiciaiS[1000]; //sakinyje esanciu skaiciu masyvas 
  int skaiciaiE[1000]; //eiluteje esanciu skaiciu masyvas
  int n=0, n1=0, n2=0; //n yra dydis, kuris nusako kiekvieno zodzio, eilutes, sakinio skaiciu
  int m1=0, m2=0; //m yra dydis , kuris nusako eilutese ir sakiniuose esanciu dvizenkliu skaiciu skaiciu

  public:
  Tekstas():word(), line(), sentences(), skaiciaiS(), skaiciaiE(){}
  Tekstas(string w[], string l[], string s[], int sks[], int ske[])
  {
    word=w;
    line=l;
    sentences=l;
    skaiciaiS=sks;
    skaiciaiE=ske;
  }
  //sukuriame draugiskas funkcija
  friend int nuskaitymasS(Tekstas);
  
  //nuskaitome pagal teksta pagal zodzius
  void nuskaitymasZ()
  {
    ifstream fd;
    fd.open("duom.txt");
    string zodis;
    while(!fd.eof())
    {
      fd>>word[n];
      n++;
    }
    fd.close();
  }
  //nuskaitome kiekvienama sakini ir skaiciupjame jame dvizenklius skaicius
  void nuskaitymasS()
  {
    ifstream fd;
    fd.open("duom.txt");
    ofstream fr;
    fr.open("rez.txt");
    fr<<"Skaiciai sakiniuose "<<endl;
    cout<<"Skaiciai sakiniuose "<<endl;
    string sentence;
    while(!fd.eof())
    {

      getline(fd, sentence, '.');
      sentences[n1]=sentence;
      
      stringstream ss;
      ss<<sentences[n1];
      string temp;
      int found;
      if(n1!=6)
      {
        fr<<n1+1<<" : ";
        cout<<n1+1<<" : ";
      }
      int sksk[100]={0};
      while(!ss.eof())
      {
        ss>>temp;
        if(stringstream(temp)>>found)
        {
          
          if(found>9 && found<100)
          {
            skaiciaiS[m1]=found;
            fr<<skaiciaiS[m1]<<" ";
            cout<<skaiciaiS[m1]<<" ";
            sksk[m1]++;
            m1++;
          }     
        }
        temp="";
        
      }
      n1++;
      fr<<endl;
      cout<<endl;
    }
    fr<<"**********************"<<endl;
    cout<<"**********************"<<endl;
    fd.close();
    fr.close();
  }
  //nuskaitome eilutes ir kiekvienoje eiluteje esancius elementus
  void nuskaitymasE()
  {
    ifstream fd;
    fd.open("duom.txt");
    ofstream fr;
    fr.open("rez.txt", ios::app);
    fr<<"Skaiciai eilutese "<<endl;
    cout<<"Skaiciai eilutese "<<endl;
    string sentence;
    while(!fd.eof())
    {
      getline(fd, sentence);
      line[n2]=sentence;

      stringstream ss;
      ss<<line[n2];
      string temp;
      int found;
      if(n2!=4)
      {
        fr<<n2+1<<" : ";
        cout<<n2+1<<" : ";
      }
      while(!ss.eof())
      {
        
        ss>>temp;
        if(stringstream(temp)>>found)
        {
          if(found>9 && found<100)
          {
            skaiciaiS[m2]=found;
            fr<<skaiciaiS[m2]<<" ";
            cout<<skaiciaiS[m2]<<" ";
            m2++;
          }
          
        }
        temp="";
        
      }
      n2++;
      fr<<endl;
      cout<<endl;

    }
    fr<<"**********************"<<endl;
    cout<<"**********************"<<endl;
    fd.close();
    fr.close();
    
  }
 //isvedame ir faile ir ekrane rastus duomenis 
 //isvedame pagal zodzius
  void rodyk()
  {
    ofstream fr;
    fr.open("rez.txt", ios::app);
    cout<<"Nuskaitymas per zodzius"<<endl;
    fr<<"**************************"<<endl;
    fr<<"Nuskaitymas per zodzius"<<endl;
    cout<<"**************************"<<endl;
    for(int i=0; i<n-1; i++)
    {
      cout<<i+1<<" : "<<word[i]<<endl;
      fr<<i+1<<" : "<<word[i]<<endl;
    }
    //isvedame pagal sakinius
    cout<<"Nuskaitymas per sakinius"<<endl;
    cout<<"**************************"<<endl;
    fr<<"Nuskaitymas per sakinius"<<endl;
    fr<<"**************************"<<endl;
    //isvedame pagal eilutes
    for(int i=0; i<n1-1; i++)
    {
      cout<<i+1<<" : "<<sentences[i]<<"."<<endl;
      fr<<i+1<<" : "<<sentences[i]<<"."<<endl;
    }
    cout<<"Nuskaitymas per eilutes"<<endl;
    cout<<"**************************"<<endl;
    fr<<"Nuskaitymas per eilutes"<<endl;
    fr<<"**************************"<<endl;
    for(int i=0; i<n2; i++)
    {
      cout<<i+1<<" : "<<line[i]<<endl;
      cout<<"------------------"<<endl;
    }
    fr.close();
  }
  
  //ikiuojame dvizenklius skaicius nuo maziausio iki didziausio
  //taip pat isvedame i faila ir ekrana nauja seka masyvo elementu
  void rikiuoti()
  {
    ofstream fr;
    fr.open("rez.txt", ios::app);
    for(int i=0; i<m1-1; i++)
    {
      for(int j=i+1; j<m1; j++)
      {
        if(skaiciaiS[i]>skaiciaiS[j])
        {
        int temp;
        temp=skaiciaiS[i];
        skaiciaiS[i]=skaiciaiS[j];
        skaiciaiS[j]=temp;
        }
      }
    }
    cout<<"Rikiavimas"<<endl;
    cout<<"**********************"<<endl;
    fr<<"Rikiavimas"<<endl;
    fr<<"**********************"<<endl;
    for(int i=0; i<m1; i++)
    {
      cout<<skaiciaiS[i]<<" ";
      fr<<skaiciaiS[i]<<" ";
    }
    cout<<endl;
    fr<<endl;
    cout<<"Skaiciu is viso yra: "<<m1<<endl;
    fr<<"Skaiciu is viso yra: "<<m1<<endl;
    fr.close();
  }

//Destruktorius
~Tekstas()
{
  cout << "Programos galas."<< endl;
};

};

int main()
{
  Tekstas T;
  T.nuskaitymasZ();
  T.nuskaitymasS();
  T.nuskaitymasE();
  T.rodyk();
  T.rikiuoti();
}