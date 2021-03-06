{   BFj�lskylda.inc SILC

    Eftirfarandi breytur �urfa a� vera til sta�ar:
    haus      : Au�kenni k�nnunar
                Au�kenni ��tttakanda
    fsvar     : Vi�eigandi fyrra svar
    strik     : Strik sem a�skilur haus og spurningu
}

TABLE BFj�lskylda
  PARAMETERS
    IMPORT vi�mi�unardagur  : DateType
    IMPORT Pers�na          : TPers�na
    IMPORT aldur            : INTEGER
    IMPORT Hj�st�tt         : THju
    IMPORT Fj�ldi, Hmfj�ldi : THmFj
    EXPORT Fj�ldiVinnuf�rra : THmFj
    EXPORT Hjusvar_1        : Integer

  INCLUDE "IncludeFiles\BHeimilisma�ur.inc"
  FIELDS
      Heimilisma�ur : ARRAY [1..15] OF BHeimilisma�ur
      Heimilisma�ur2 : ARRAY [1..15] OF BHeimilisma�ur
      ErMaki : array[1..15] of 1..15,empty

      A�_Heiman (Hm16)
      "^haus@/^fsvar@/^strik@/
      Er einhver heimilismanna t�mabundi� a� heimann? �� er �tt vi� lengri dv�l utan heimilis.
      @/@/@GSkyldu eftir au�ann reit ef engin heimilismanna er t�mabundi� a� heiman@G"
      "^haus@/^fsvar@/^strik@/
      Are any of the residents in your household temporary away from home ?
      @/@/@GSkyldu eftir au�ann reit ef engin heimilismanna er t�mabundi� a� heiman@G"
      /"T�mabundi� a� heiman"
      :   SET [14] OF
        (heim02 (2) "^heimNafn[2]",
         heim03  "^heimNafn[3]",
         heim04  "^heimNafn[4]",
         heim05  "^heimNafn[5]",
         heim06  "^heimNafn[6]",
         heim07  "^heimNafn[7]",
         heim08  "^heimNafn[8]",
         heim09  "^heimNafn[9]",
         heim10  "^heimNafn[10]",
         heim11  "^heimNafn[11]",
         heim12  "^heimNafn[12]",
         heim13  "^heimNafn[13]",
         heim14  "^heimNafn[14]",
         heim15  "^heimNafn[15]"),EMPTY

  Hj�Svar (Hm17)
      "^haus@/^fsvar@/^strik@/
      Hver er hj�skaparsta�a ^��n?"
      "^haus@/^fsvar@/^strik@/
      What is ^your marital status ?"
      /"Hj�skaparsta�aSvaranda"
      : THj�svar  {THjuSpurt AOK_151107}

      HverSvararHeimilisma�ur
      "^haus@/^fsvar@/^strik@/
      K�ri spyrill, n� �arft �� a� merkja hver er vi�m�landinn ^�.HverSvarar"
      / "Merkja vi� hver annar svarar"
      :
        (heim02 (2) "^heimNafn[2]",
         heim03  "^heimNafn[3]",
         heim04  "^heimNafn[4]",
         heim05  "^heimNafn[5]",
         heim06  "^heimNafn[6]",
         heim07  "^heimNafn[7]",
         heim08  "^heimNafn[8]",
         heim09  "^heimNafn[9]",
         heim10  "^heimNafn[10]",
         heim11  "^heimNafn[11]",
         heim12  "^heimNafn[12]",
         heim13  "^heimNafn[13]",
         heim14  "^heimNafn[14]",
         heim15  "^heimNafn[15]"),EMPTY

  AUXFIELDS
    N�r         : TJ�Nei
    Farinn      : TJ�Nei
    M           : THmFj
    Vinnuf�r    : TJ�Nei
    heimNafn         : ARRAY [2..15] OF STRING[50]
    hj�st�ttin  : THju
    ��n,your    : string[11]
    avarp_heimilismenn       "^haus@/^fsvar@/^strik@/
                              N� �tla �g a� f� hj� ��r uppl�singar um �� sem b�a � heimilinu.
                              Ef vi� byrjum � �eim elsta og endum � �eim yngsta.
                              @/@/@G�ttu � einhvern lykil til a� byrja@G"
                             "^haus@/^fsvar@/^strik@/
                              Next I will ask you series of questions about other people living in the household.
                              If we could start with the oldest and end with the youngest.
                              @/@/@G�ttu � einhvern lykil til a� byrja@G"
                              : string, EMPTY

  LOCALS
      I : INTEGER
      A : INTEGER
      fj�ldi_�_samb�� : integer
      er_til_maki : integer
  RULES
    prc_��nHansHennar(pers�na,��n)
    prc_YourHisHer   (pers�na,your)
  NEWPAGE
    M := HmFj�ldi
    farinn := nei
    n�r := nei
    Heimilisma�ur[1].KEEP (vi�mi�unardagur, pers�na, aldur, n�r, farinn, hj�st�tt, Vinnuf�r, 1,1,Heimilisma�ur[1].kyn, hjusvar_1, heimilisma�ur[1].�skr��ur)
    Heimilisma�ur[1].KEEP (vi�mi�unardagur, pers�na, aldur, n�r, farinn, hj�st�tt, Vinnuf�r, 1,2,Heimilisma�ur[1].kyn, hjusvar_1, heimilisma�ur[1].�skr��ur)
    IF aldur >= 16
    THEN Hj�Svar
    ENDIF
    IF Hj�svar = sambud
        then hjusvar_1 := 1  endif
    IF hj�svar <> sambud then hjusvar_1 := 0
        endif
    avarp_heimilismenn
    FOR I := 2 TO M DO
      Farinn := j�     {20070222}
      IF (I In Forskr�ning.HmSkr� OR 1 IN Forskr�ning.HmSkr�) {AND I <= Fj�ldi + 1 } THEN {20070222}
        Farinn := J�
      ELSE
        Farinn := Nei
      ENDIF
      hj�st�ttin := hj�st�tt
      IF I <= Fj�ldi + 1 THEN
        N�r := Nei
      ELSE
        N�r := J�
        hj�st�ttin := empty
      ENDIF
      Heimilisma�ur[I] (vi�mi�unardagur, pers�na, aldur, n�r, farinn, hj�st�ttin, Vinnuf�r, 1,1,Heimilisma�ur[I].kyn, hjusvar_1, heimilisma�ur[I].�skr��ur) {fyrsta umfer�}
      IF vinnuf�r = J� THEN
        Fj�ldiVinnuf�rra := Fj�ldiVinnuf�rra + 1
      ENDIF
      IF (Heimilisma�ur[I].Brottfluttur = J�) THEN
        heimNafn[I] := ''
      ELSE
        heimNafn[I] := Heimilisma�ur[I].Nafn
        IF HeimNafn[I] > '' THEN
          heimNafn[I] := heimNafn[I] + ', ' + Str(Heimilisma�ur[I].Aldur)
        ENDIF
      ENDIF
      if Heimilisma�ur[I].Hj�Svar = Sambud then
        fj�ldi_�_samb�� := fj�ldi_�_samb�� + 1
      endif
      if Heimilisma�ur[I].Tengsl = maki then
        er_til_maki := 1
      endif
    ENDDO

    check
    if Heimilisma�ur[M].Hj�Svar = response then
      ((fj�ldi_�_samb�� + er_til_maki) / 2.0) = round( (fj�ldi_�_samb�� + er_til_maki) / 2.0)
        "Stemmir ekki fj�ldi � samb��"
    endif
    FOR A := 2 TO M DO
      if Heimilisma�ur[A].brottfluttur = nei then n�r :=j� else n�r := nei endif
      Heimilisma�ur2[A] (vi�mi�unardagur, pers�na, aldur, n�r, farinn, hj�st�ttin, Vinnuf�r, A,2,Heimilisma�ur[A].kyn, hjusvar_1, heimilisma�ur[A].�skr��ur) {�nnur umfer�}
    ENDDO

ENDTABLE
