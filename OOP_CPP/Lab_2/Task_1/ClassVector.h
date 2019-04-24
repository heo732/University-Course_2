//---------------------------------------------------------------------------
#ifndef ClassH
#define ClassH

#include <Grids.hpp>
//---------------------------------------------------------------------------
class TVector{
    short *pointer;
    unsigned int cntElements;

    char stan; /*0 - good,
    1 - ����� �� ��� ������,
    2 - �������� ������ �������*/

    unsigned int ErrorPos;

    static unsigned int cntObjects;

  public:
    TVector(); //1el = 0;
    TVector(unsigned int); //[size]els=0;
    TVector(unsigned int, short); //[size]els=value;
    ~TVector();

    void Assign(unsigned int, short);//if(stan==1)look ErrorPos
    short GetElValue(unsigned int);//if(stan==1)look return

    unsigned int GetCntElements() const;
    unsigned int GetCntObjects() const;
    char GetStan() const;
    unsigned int GetErrorPos() const;

    void PrintToStg(TStringGrid *&) const;

    void AddToEl(unsigned int, short);//if(stan==1)look ErrorPos
    void SubFromEl(unsigned int, short);//if(stan==1)look ErrorPos
    void MultElOnValue(unsigned int, unsigned char);//if(stan==1)look ErrorPos
    bool ElMoreValue(unsigned int, short);//if(stan==1)look ErrorPos
    bool ElEqualValue(unsigned int, short);//if(stan==1)look ErrorPos
    bool ElNotEqualValue(unsigned int, short);//if(stan==1)look ErrorPos

    void AddVector(TVector*);//if(stan==2)write "ERROR"
    void SubVector(TVector*);//if(stan==2)write "ERROR"
    void MultVector(TVector*);//if(stan==2)write "ERROR"
    int MultVectors_Scalar(TVector*);//if(stan==2)write "ERROR"
    void MultVectorOnValue(unsigned char);
    bool VectorMoreVector(TVector*);//if(return false && stan==0)look ErrorPos
    bool VectorEqualVector(TVector*);//if(return false && stan==0)look ErrorPos
    bool VectorNotEqualVector(TVector*);//if(return false && stan==0)look ErrorPos

    char ReadFromStg(TStringGrid *);//if(return 1)write "fill the table"
    void RandomFilling();
    char ReadFromFile(String);//if(return 1)write "bad name file"

    TVector& operator = (const TVector& in);

};

#endif
