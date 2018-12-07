#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <math.h>
#include <sstream>
#include <string>
#include <time.h>

using namespace std;

class Mainthing
{
    map<int,vector<vector<bool> > > MT; ///nem j� kiv�telre, �s kell, hogy mennyi van bel�le?
    vector<vector<unsigned short int> > CT;
    bool rotable;
    unsigned short int R,G,B;

public:
    void Mainthing()
    {
        unsigned short int amount;
        bool TB;
        vector<bool> TBV(4,0);
        vector<vector<bool> > TBM(3,TBV);
        fstream f(input.txt);
        if(f.fail()) {cout<<"Unsuccesful input loading: File missing"<<endl;
        return;}
        f>>rotable;
        f>>R;
        f>>G;
        f>>B;
        unsigned short int step=0;
        unsigned long long TileAn;
        while(!f.eof())
        {
            step++;
           f>>amount;
           for(int i=0; i<=3; i++)
           {
               TileAn= TileAn + i*10;
               for(int j=0; j<4; j++)
               {
                f>>TB;
                if(TB==1){TileAn++;
                TBV[j]=TB;}
               }
               if(TileAn%2!=0){cout<<"Unsuccesful input loading: Reading Tile "<<step<<" was unsuccesful. To many or not enough sides for color "<< i<< " ."<<endl;
               return;};
               if(TileAn%10!=0){TileAn=TileAn-i*10;}else {TileAn=TileAn-2;};
               TBM[i]=TBV;
           }
           ///Sz�m elemz�s mostanra kellene (1,2,3) _,_ _ _(mennyis�g),_ _ _(l�p�s) ez a map indexe

           ///lehetne m�g tulajdons�g:
           ///      Melyik sz�nre milyen: _ _ _-> R G B 1->6 lehet.
           ///      T�pus:
           ///       1-> egy sz�n egyenes
           ///       2-> egysz�n kanyar
           ///       3-> k�t sz�n f�ggtelen
           ///       4-> k�t sz�n egy azonos v�g
           ///       5-> k�t sz�n k�t azonos v�g
           ///       6-> h�rom sz�n egy f�ggtelen a t�bbit�l
           ///       7-> h�rom sz�n egy k�z�s v�g
           ///       8-> h�rom sz�n k�t v�g kevert, de nem azonos sz�nekkel   (lehet jobb lenne a 7-es hely�n)
           ///       9-> feh�r

           /// a mapban a f�ggetleneken meg �t el�sz�r, amjd a k�t sz�neseken, �s �gy tov�bb.

           /*for(int i=1; i<=amount; i++)
           {
               if(TileAn%30==0)
               {
                   MT[(TileAn/1000000000)+3000]=TBM;
                   TileAn=TileAn+1000000000;
               };
                if(TileAn%20==0)
               {
                   MT[((TileAn/1000000)-(TileAn/1000000000)*1000)+2000]=TBM;
                   TileAn=TileAn+1000000;
               };
                if(TileAn%10==0)
               {
                   MT[((TileAn/1000)-(TileAn/1000000)*1000)+1000]=TBM;
                   TileAn=TileAn+1000;
               };
           }*/

        }
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
