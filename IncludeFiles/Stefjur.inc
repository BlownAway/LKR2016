{   Stefjur.inc
    Samfelld vinnumarka�sranns�kn
    �H (c) n�vember 2002
    }

 PROCEDURE prc_f���r
 PARAMETERS
    IMPORT kennitala : STRING
    EXPORT f���r : INTEGER
    RULES
        IF (SUBSTRING(kennitala,9,1)='0') THEN
            f���r  := 2000 + VAL(SUBSTRING(kennitala,5,2))
        ELSE
            f���r  := 1900 + VAL(SUBSTRING(kennitala,5,2))
        ENDIF
 ENDPROCEDURE

 PROCEDURE prc_aldur
 PARAMETERS
    IMPORT kennitala : STRING
    IMPORT vi�mi�unardagur : DateType
    EXPORT aldur : INTEGER

    LOCALS f���r: INTEGER
    RULES
        prc_f���r(kennitala,f���r)
        aldur := YEAR(vi�mi�unardagur) - f���r
 ENDPROCEDURE

 PROCEDURE prc_f��ingardagur
 PARAMETERS
    IMPORT kennitala : STRING
    EXPORT f��ingardagur: DATETYPE
    EXPORT aldur : INTEGER

    LOCALS f���r,fm�nu�ur,fdagur: INTEGER
    RULES
        prc_f���r(kennitala,f���r)
        fm�nu�ur := VAL(SUBSTRING(kennitala,3,2))
        fdagur := VAL(SUBSTRING(kennitala,1,2))
        f��ingardagur := (f���r,fm�nu�ur ,fdagur)
        aldur := YEAR(SYSDATE) - 1 - f���r
 ENDPROCEDURE



 PROCEDURE prc_M�nu�ur
    PARAMETERS
      Vi�mi�unardagur : DateType
      EXPORT M�nu�ur, Mnth : String

    RULES
      IF Month(Vi�mi�unardagur) = 1 THEN M�nu�ur := 'jan.'  Mnth := 'Jan.'
      ELSEIF Month(Vi�mi�unardagur) = 2 THEN  M�nu�ur := 'feb.' Mnth := 'Feb.'
      ELSEIF Month(Vi�mi�unardagur) =  3 THEN  M�nu�ur := 'mar.' Mnth := 'Mar.'
      ELSEIF Month(Vi�mi�unardagur) =  4 THEN  M�nu�ur := 'apr.' Mnth := 'Apr.'
      ELSEIF Month(Vi�mi�unardagur) =  5 THEN  M�nu�ur := 'ma�' Mnth := 'May'
      ELSEIF Month(Vi�mi�unardagur) =  6 THEN  M�nu�ur := 'j�n.' Mnth := 'June'
      ELSEIF Month(Vi�mi�unardagur) =  7 THEN  M�nu�ur := 'j�l.' Mnth := 'July'
      ELSEIF Month(Vi�mi�unardagur) =  8 THEN  M�nu�ur := '�g�.' Mnth := 'Aug.'
      ELSEIF Month(Vi�mi�unardagur) =  9 THEN  M�nu�ur := 'sep.' Mnth := 'Sep.'
      ELSEIF Month(Vi�mi�unardagur) =  10 THEN  M�nu�ur := 'okt.' Mnth := 'Oct.'
      ELSEIF Month(Vi�mi�unardagur) =  11 THEN  M�nu�ur := 'n�v.' Mnth := 'Nov.'
      ELSEIF Month(Vi�mi�unardagur) =  12 THEN  M�nu�ur := 'des.' Mnth := 'Dec.'
      ELSE M�nu�ur := '?'
      ENDIF
   ENDPROCEDURE

 PROCEDURE prc_T�malengd
    PARAMETERS
      upphafsdagur, vi�mi�unardagur : DateType
      EXPORT t�mi : Integer

    RULES
      t�mi := year(vi�mi�unardagur)*12 + month(vi�mi�unardagur) - (year(upphafsdagur)*12 + month(upphafsdagur))
 ENDPROCEDURE

 Procedure prc_Vi�mi�unart�miUppl�st
    PARAMETERS
      upphafsdagur, vi�mi�unardagur : DateType
      EXPORT vi�mi�unarvika, referenceweek : String

    AUXFIELDS
      Dagur1, Dagur2     : integer
      M�nu�ur1, m�nu�ur2, month1, month2: string

    RULES
      dagur1 := Day(Upphafsdagur)
      dagur2 := day(Vi�mi�unardagur)
      prc_m�nu�ur(Upphafsdagur, m�nu�ur1, month1)
      prc_m�nu�ur(Vi�mi�unardagur, m�nu�ur2, month2)
      Vi�mi�unarvika := 'M�nudaginn ' + str(dagur1) + '. '+ m�nu�ur1 + ' - sunnudagsins ' + str(dagur2) + '. '+m�nu�ur2
      ReferenceWeek := 'Monday ' + str(dagur1) + '. '+ month1 + ' - Sunday ' + str(dagur2) + '. '+month2
 ENDPROCEDURE

 PROCEDURE prc_Vi�mi�unart�miSpurt
   PARAMETERS
      upphafsdagur, vi�mi�unardagur : DateType
      EXPORT S��ustuViku, LastWeek : String

    AUXFIELDS
      Dagur1, Dagur2     : integer
      M�nu�ur1, m�nu�ur2, month1, month2 : string

    RULES
      dagur1 := Day(Upphafsdagur)
      dagur2 := day(Vi�mi�unardagur)
      prc_m�nu�ur(Upphafsdagur, m�nu�ur1, month1)
      prc_m�nu�ur(Vi�mi�unardagur, m�nu�ur2, month2)

    IF upphafsdagur + (0,0,6) = vi�mi�unardagur THEN
      IF vi�mi�unardagur + (0,0,5) < sysdate THEN
        S��ustuViku := 'vikunni ' + str(dagur1) + '. '+ m�nu�ur1 + ' til ' + str(dagur2) + '. '+m�nu�ur2
        LastWeek := 'the week ' + str(dagur1) + '. '+ month1 + ' to ' + str(dagur2) + '. '+month2
      ELSEIF vi�mi�unardagur = sysdate THEN
        S��ustuviku := 'vikunni sem l�kur � dag'
        LastWeek := 'week ending today'
      ELSE
        S��ustuviku := 's��ustu viku'
        LastWeek := 'past week'
      ENDIF
    ELSEIF upphafsdagur + (0,0,27) = vi�mi�unardagur THEN
      IF vi�mi�unardagur + (0,0,5) < sysdate THEN
        S��ustuViku := 't�mabilinu m�nud. ' + str(dagur1) + '. '+ m�nu�ur1 +' til sunnud. ' + str(dagur2) + '. '+m�nu�ur2
        LastWeek := 'the period Monday ' + str(dagur1) + '. '+ month1 +' to Sunday ' + str(dagur2) + '. '+month2
      ELSE
        S��ustuviku := 's��ustu fj�rum vikum'
        LastWeek := 'the past four weeks'
      ENDIF
    ENDIF
 ENDPROCEDURE

 PROCEDURE prc_Trimma
    PARAMETERS
       S�mi : String
       EXPORT nS�mi : String

    AUXFIELDS
        L       : Integer

    LOCALS
        i       : Integer

    RULES
      L := Len(S�mi)
      IF L > 0 THEN
        For i:= 1 To 80 DO
          IF I <= L THEN
            IF Position(Substring(S�mi,i,1),'0123456789/')>0 THEN nS�mi := nS�mi + Substring(S�mi,i,1) ENDIF
          ENDIF
        ENDDO
      ENDIF


 ENDPROCEDURE

 PROCEDURE prc_B�taVi�A�raS�ma
    PARAMETERS
      s�mi, as�mar : String
      EXPORT ns�mar : String

    AUXFIELDS
      tS�mi, tAs�mar : STRING

    RULES
      prc_Trimma (s�mi, tS�mi)
      prc_Trimma (as�mar, tAs�mar)
      IF (Len(tS�mi) >= 7) And (Position ( tS�mi, tAs�mar) = 0) THEN
        IF tAS�mar > '' THEN
            nS�mar := S�mi + ' / ' + aS�mar
        ELSE
            nS�mar := S�mi
        ENDIF
      ELSE
        nS�mar := aS�mar
      ENDIF

 ENDPROCEDURE

 PROCEDURE prc_��Gast
    PARAMETERS
        Pers�na : TPers�na
        EXPORT ��gast : String

    RULES
        IF Pers�na IN [karl, kona] THEN
            ��gast:= '�� gast'
        ELSEIF Pers�na = annarKarl THEN
            ��gast:= 'hann gat'
        ELSEIF Pers�na = annarKona THEN
            ��gast:= 'h�n gat'
        ELSE
            ��gast:= 'hann/h�n gat'
        ENDIF

 ENDPROCEDURE

  PROCEDURE prc_St�rfum��num
    PARAMETERS
        Pers�na : TPers�na
        EXPORT st�rfum��num : String

    RULES
        IF Pers�na IN [karl, kona] THEN
            st�rfum��num := 'st�rfum ��num'
        ELSEIF Pers�na = annarKarl THEN
            st�rfum��num := 'st�rfum s�num'
        ELSEIF Pers�na = annarKona THEN
            st�rfum��num := 'st�rfum s�num'
        ELSE
            st�rfum��num := 'st�rfum s�num'
        ENDIF

 ENDPROCEDURE


   PROCEDURE prc_��num
    PARAMETERS
        Pers�na : TPers�na
        EXPORT st�rfum��num : String

    RULES
        IF Pers�na IN [karl, kona] THEN
            st�rfum��num := '��num'
        ELSEIF Pers�na = annarKarl THEN
            st�rfum��num := 's�num'
        ELSEIF Pers�na = annarKona THEN
            st�rfum��num := 's�num'
        ELSE
            st�rfum��num := 's�num'
        ENDIF

 ENDPROCEDURE

  PROCEDURE prc_Heilsu��na
    PARAMETERS
        Pers�na : TPers�na
        EXPORT heilsu��na: String

    RULES
        IF Pers�na IN [karl, kona] THEN
            heilsu��na:= 'heilsu ��na'
        ELSEIF Pers�na = annarKarl THEN
            heilsu��na:= 'heilsu s�na'
        ELSEIF Pers�na = annarKona THEN
            heilsu��na:= 'heilsu s�na'
        ELSE
            heilsu��na:= 'heilsu s�na'
        ENDIF

 ENDPROCEDURE


   PROCEDURE prc_�innar
    PARAMETERS
        Pers�na : TPers�na
        EXPORT heilsu��na: String

    RULES
        IF Pers�na IN [karl, kona] THEN
            heilsu��na:= '�innar'
        ELSEIF Pers�na = annarKarl THEN
            heilsu��na:= 'sinnar'
        ELSEIF Pers�na = annarKona THEN
            heilsu��na:= 'sinnar'
        ELSE
            heilsu��na:= 'sinnar'
        ENDIF

 ENDPROCEDURE


 PROCEDURE prc_��HannH�n
    PARAMETERS
        Pers�na : TPers�na
        EXPORT hhann : String

    RULES
        IF Pers�na IN [karl, kona] THEN
            hhann := '��'
        ELSEIF Pers�na = annarKarl THEN
            hhann := 'hann'
        ELSEIF Pers�na = annarKona THEN
            hhann := 'h�n'
        ELSE
            hhann := 'hann/h�n'
        ENDIF

 ENDPROCEDURE

 PROCEDURE prc_radin_radinn
    PARAMETERS
        Pers�na : TPers�na
        EXPORT radinn : String

    RULES
        IF Pers�na = karl THEN
            radinn := 'r��inn'
        ELSEIF Pers�na = kona THEN
            radinn := 'r��in'
        ELSEIF Pers�na = annarKarl THEN
            radinn := 'r��inn'
        ELSEIF Pers�na = annarKona THEN
            radinn := 'r��in'
        ELSE
            radinn := 'r��in/n'
        ENDIF

 ENDPROCEDURE


 PROCEDURE prc_Varvor
    PARAMETERS
        Pers�na : TPers�na
        EXPORT var_vor : String

    RULES
        IF Pers�na = karl THEN
            var_vor := 'var'
        ELSEIF Pers�na = kona THEN
            var_vor := 'v�r'
        ELSEIF Pers�na = annarKarl THEN
            var_vor := 'var'
        ELSEIF Pers�na = annarKona THEN
            var_vor := 'v�r'
        ELSE
            var_vor := 'var/v�r'
        ENDIF

 ENDPROCEDURE


  PROCEDURE prc_Gaeti
    PARAMETERS
        Pers�na : TPers�na
        EXPORT hhann : String

    RULES
        IF Pers�na IN [karl, kona] THEN
            hhann := 'G�tir'
        ELSEIF Pers�na = annarKarl THEN
            hhann := 'G�ti'
        ELSEIF Pers�na = annarKona THEN
            hhann := 'G�ti'
        ELSE
            hhann := 'G�ti'
        ENDIF

 ENDPROCEDURE


 PROCEDURE prc_tokstu
    PARAMETERS
        Pers�na : TPers�na
        EXPORT hhann : String

    RULES
        IF Pers�na IN [karl, kona] THEN
            hhann := 't�kstu ��r'
        ELSEIF Pers�na = annarKarl THEN
            hhann := 't�k hann s�r'
        ELSEIF Pers�na = annarKona THEN
            hhann := 't�k h�n s�r'
        ELSE
            hhann := 't�k hann/h�n s�r'
        ENDIF

 ENDPROCEDURE



  PROCEDURE prc_�inni
    PARAMETERS
        Pers�na : TPers�na
        EXPORT hhann : String

    RULES
        IF Pers�na IN [karl, kona] THEN
            hhann := '�inni'
        ELSEIF Pers�na = annarKarl THEN
            hhann := 'hans'
        ELSEIF Pers�na = annarKona THEN
            hhann := 'hennar'
        ELSE
            hhann := 'hans/hennar'
        ENDIF

 ENDPROCEDURE


   PROCEDURE prc_f�rstu
    PARAMETERS
        Pers�na : TPers�na
        EXPORT hhann : String

    RULES
        IF Pers�na IN [karl, kona] THEN
            hhann := 'F�rst ��'
        ELSEIF Pers�na = annarKarl THEN
            hhann := 'F�r hann'
        ELSEIF Pers�na = annarKona THEN
            hhann := 'F�r h�n'
        ELSE
            hhann := 'F�r hann/h�n'
        ENDIF

 ENDPROCEDURE


  PROCEDURE prc_fekkstu
    PARAMETERS
        Pers�na : TPers�na
        EXPORT hhann : String

    RULES
        IF Pers�na IN [karl, kona] THEN
            hhann := 'f�kkst ��'
        ELSEIF Pers�na = annarKarl THEN
            hhann := 'f�kk hann'
        ELSEIF Pers�na = annarKona THEN
            hhann := 'f�kk h�n'
        ELSE
            hhann := 'f�kk hann/h�n'
        ENDIF

 ENDPROCEDURE



   PROCEDURE prc_haettirdu
    PARAMETERS
        Pers�na : TPers�na
        EXPORT hhann : String

    RULES
        IF Pers�na IN [karl, kona] THEN
            hhann := 'H�ttir ��'
        ELSEIF Pers�na = annarKarl THEN
            hhann := 'H�tti hann'
        ELSEIF Pers�na = annarKona THEN
            hhann := 'H�tti h�n'
        ELSE
            hhann := 'H�tti hann/h�n'
        ENDIF

 ENDPROCEDURE


   PROCEDURE prc_skiptirdu
    PARAMETERS
        Pers�na : TPers�na
        EXPORT hhann : String

    RULES
        IF Pers�na IN [karl, kona] THEN
            hhann := 'skiptir ��'
        ELSEIF Pers�na = annarKarl THEN
            hhann := 'skipti hann'
        ELSEIF Pers�na = annarKona THEN
            hhann := 'skipti h�n'
        ELSE
            hhann := 'skipti hann/h�n'
        ENDIF

 ENDPROCEDURE



 PROCEDURE prc_�igHannHana
    PARAMETERS
        Pers�na : TPers�na
        EXPORT hhann : String

    RULES
        IF Pers�na IN [karl, kona] THEN
            hhann := '�ig'
        ELSEIF Pers�na = annarKarl THEN
            hhann := 'hann'
        ELSEIF Pers�na = annarKona THEN
            hhann := 'hana'
        ELSE
            hhann := 'hann/hana'
        ENDIF

 ENDPROCEDURE

  PROCEDURE prc_skipulagdi_hann_hun_thu
    PARAMETERS
        Pers�na : TPers�na
        EXPORT skipulagdi: String

    RULES
        IF Pers�na IN [karl, kona] THEN
            skipulagdi:= 'Skipulag�ir �� e�a stj�rna�ir'
        ELSEIF Pers�na = annarKarl THEN
            skipulagdi:= 'Skipulag�i hann e�a stj�rna�i'
        ELSEIF Pers�na = annarKona THEN
            skipulagdi:= 'Skipulag�i h�n e�a stj�rna�i'
        ELSE
            skipulagdi:= 'Skipulag�i hann/h�n e�a stj�rna�i'
        ENDIF

 ENDPROCEDURE

   PROCEDURE prc_for_hann_hun_thu
    PARAMETERS
        Pers�na : TPers�na
        EXPORT for_med: String

    RULES
        IF Pers�na IN [karl, kona] THEN
            for_med:= 'F�rst �� me�'
        ELSEIF Pers�na = annarKarl THEN
            for_med:= 'F�r hann me�'
        ELSEIF Pers�na = annarKona THEN
            for_med:= 'F�r h�n me�'
        ELSE
            for_med:= 'F�r hann/h�n me�'
        ENDIF

 ENDPROCEDURE


 PROCEDURE prc_�ittHannHana
    PARAMETERS
        Pers�na : TPers�na
        EXPORT hhann : String

    RULES
        IF Pers�na IN [karl, kona] THEN
            hhann := '�itt'
        ELSEIF Pers�na = annarKarl THEN
            hhann := 'hann'
        ELSEIF Pers�na = annarKona THEN
            hhann := 'hana'
        ELSE
            hhann := 'hann/hana'
        ENDIF

 ENDPROCEDURE


  PROCEDURE prc_�innHansHennar
    PARAMETERS
        Pers�na : TPers�na
        EXPORT hhana : String

    RULES
        IF Pers�na IN [karl, kona] THEN
            hhana := '�inn'
        ELSEIF Pers�na = annarKarl THEN
            hhana := 'hans'
        ELSEIF Pers�na = annarKona THEN
            hhana := 'hennar'
        ELSE
            hhana := 'hans/hennar'
        ENDIF

 ENDPROCEDURE

  PROCEDURE prc_ferdthu
    PARAMETERS
        Pers�na : TPers�na
        EXPORT ferdthu : String

    RULES
        IF Pers�na IN [karl, kona] THEN
            ferdthu := 'Fer� ��'
        ELSEIF Pers�na = annarKarl THEN
            ferdthu := 'Fer hann'
        ELSEIF Pers�na = annarKona THEN
            ferdthu := 'Fer h�n'
        ELSE
            ferdthu := 'Fer hann/h�n'
        ENDIF

 ENDPROCEDURE

   PROCEDURE prc_sjalf_ur
    PARAMETERS
        Pers�na : TPers�na
        EXPORT sjalf_ur : String

    RULES
        IF Pers�na in [kona, annarKona] THEN
            sjalf_ur := 'sj�lf'
        ELSEIF Pers�na in [karl, annarKarl] THEN
            sjalf_ur := 'sj�lfur'
        ELSE
            sjalf_ur := 'Sj�lf/ur'
        ENDIF

 ENDPROCEDURE

    PROCEDURE prc_thu_vaerir
    PARAMETERS
        Pers�na : TPers�na
        EXPORT thu_vaerir : String

    RULES
        IF Pers�na in [karl, kona] THEN
            thu_vaerir := '�� v�rir'
        ELSEIF Pers�na in [annarKarl] THEN
            thu_vaerir := 'hann v�ri'
        ELSEIF Pers�na in [annarKona] THEN
            thu_vaerir := 'h�n v�ri'
        ELSE
            thu_vaerir := 'hann/h�n v�ri'
        ENDIF

 ENDPROCEDURE

  PROCEDURE prc_��naHansHennar
    PARAMETERS
        Pers�na : TPers�na
        EXPORT ��na : String

    RULES
        IF Pers�na IN [karl, kona] THEN
            ��na := '��na'
        ELSEIF Pers�na = annarKarl THEN
            ��na := 'hans'
        ELSEIF Pers�na = annarKona THEN
            ��na := 'hennar'
        ELSE
            ��na := 'hans/hennar'
        ENDIF

 ENDPROCEDURE

 PROCEDURE prc_��numHansHennar
    PARAMETERS
        Pers�na : TPers�na
        EXPORT hhans : String

    RULES
        IF Pers�na IN [karl, kona] THEN
            hhans := '��num'
        ELSEIF Pers�na = annarKarl THEN
            hhans := 'hans'
        ELSEIF Pers�na = annarKona THEN
            hhans := 'hennar'
        ELSE
            hhans := 'hans/hennar'
        ENDIF

 ENDPROCEDURE

 PROCEDURE prc_��nuHansHennar
    PARAMETERS
        Pers�na : TPers�na
        EXPORT hhans : String

    RULES
        IF Pers�na IN [karl, kona] THEN
            hhans := '��nu'
        ELSEIF Pers�na = annarKarl THEN
            hhans := 'hans'
        ELSEIF Pers�na = annarKona THEN
            hhans := 'hennar'
        ELSE
            hhans := 'hans/hennar'
        ENDIF

 ENDPROCEDURE

 PROCEDURE prc_rEnding
    PARAMETERS
      IMPORT Pers�na : TPers�na
      EXPORT r : String

    RULES
      IF Pers�na IN [karl, kona] THEN
          r := 'r'
      ELSE
          r := ''
      ENDIF
 ENDPROCEDURE

 PROCEDURE prc_��rHonumHenni
    PARAMETERS
        Pers�na : TPers�na
        EXPORT ��rhonum : String

    RULES
        IF Pers�na IN [karl, kona] THEN
            ��rhonum := '��r'
        ELSEIF Pers�na = annarKarl THEN
            ��rhonum := 'honum'
        ELSEIF Pers�na = annarKona THEN
            ��rhonum := 'henni'
        ELSE
            ��rhonum := 'honum/henni'
        ENDIF

 ENDPROCEDURE

 PROCEDURE prc_��nHansHennar
    PARAMETERS
        Pers�na : TPers�na
        EXPORT ��r : String

    RULES
        IF Pers�na IN [karl, kona] THEN
            ��r := '��n'
        ELSEIF Pers�na = annarKarl THEN
            ��r := 'hans'
        ELSEIF Pers�na = annarKona THEN
            ��r := 'hennar'
        ELSE
            ��r := 'hans/hennar'
        ENDIF

 ENDPROCEDURE

 PROCEDURE prc_��rS�r
    PARAMETERS
      IMPORT Pers�na : TPers�na
      EXPORT ��r : String

    RULES
      IF Pers�na IN [karl, kona] THEN
          ��r := '��r'
      ELSE
          ��r := 's�r'
      ENDIF
 ENDPROCEDURE

 PROCEDURE prc_��nuS�nu
    PARAMETERS
      IMPORT Pers�na : TPers�na
      EXPORT ��nu: String

    RULES
      IF Pers�na IN [karl, kona] THEN
          ��nu:= '��nu'
      ELSE
          ��nu:= 's�nu'
      ENDIF
 ENDPROCEDURE


 PROCEDURE prc_�igSig
    PARAMETERS
      IMPORT Pers�na : TPers�na
      EXPORT �ig : String

    RULES
      IF Pers�na IN [karl, kona] THEN
          �ig := '�ig'
      ELSE
          �ig := 'sig'
      ENDIF
 ENDPROCEDURE

 PROCEDURE prc_��naS�na
    PARAMETERS
      IMPORT Pers�na : TPers�na
      EXPORT ��na: String

    RULES
      IF Pers�na IN [karl, kona] THEN
          ��na:= '��na'
      ELSE
          ��na:= 's�na'
      ENDIF
 ENDPROCEDURE

  PROCEDURE prc_�ittHansHennar
    PARAMETERS
        Pers�na : TPers�na
        EXPORT hhana : String

    RULES
        IF Pers�na IN [karl, kona] THEN
            hhana := '�itt'
        ELSEIF Pers�na = annarKarl THEN
            hhana := 'hans'
        ELSEIF Pers�na = annarKona THEN
            hhana := 'hennar'
        ELSE
            hhana := 'hans/hennar'
        ENDIF

 ENDPROCEDURE


  PROCEDURE prc_ErErt
    PARAMETERS
        Pers�na : TPers�na
        EXPORT Ert : String

    RULES
        IF Pers�na IN [karl, kona] THEN
            Ert := 'Ert'
        ELSE
            Ert := 'Er'
        ENDIF

 ENDPROCEDURE

  PROCEDURE prc_urEnding
    PARAMETERS
        Pers�na : TPers�na
        EXPORT ur : String

    RULES
        IF Pers�na IN [kona, annarkona] THEN
            ur := ''
        ELSE
            ur := 'ur'
        ENDIF

 ENDPROCEDURE

  PROCEDURE prc_fatlkyn
    PARAMETERS
        Pers�na : TPers�na
        EXPORT fatla�ur : String

    RULES
        IF Pers�na IN [kona, annarkona] THEN
            fatla�ur := 'f�tlu�'
        ELSE
            fatla�ur := 'fatla�ur '
        ENDIF

 ENDPROCEDURE

  PROCEDURE prc_Me�t�ldum
    PARAMETERS
        Pers�na : TPers�na
        EXPORT Me�t�ldum : String

    RULES
        IF Pers�na IN [kona, annarkona] THEN
            Me�t�ldum := 'me�talinni'
        ELSE
            Me�t�ldum := 'me�t�ldum'
        ENDIF

 ENDPROCEDURE

  PROCEDURE prc_ggamall
    PARAMETERS
        Pers�na : TPers�na
        EXPORT ggamall : String

    RULES
        IF Pers�na IN [kona, annarkona] THEN
            ggamall := 'g�mul'
        ELSE
            ggamall := 'gamall'
        ENDIF

 ENDPROCEDURE

  PROCEDURE prc_stuEnding
    PARAMETERS
        Pers�na : TPers�na
        EXPORT Varstu : String

    RULES
        IF Pers�na IN [karl, kona] THEN
            Varstu:= 'stu'
        ELSEIF Pers�na = annarKarl THEN
            Varstu:= '�hann'
        ELSEIF Pers�na = annarKona THEN
            Varstu:= '�h�n'
        ELSE
            Varstu:= '�hann/h�n'
        ENDIF

 ENDPROCEDURE

   PROCEDURE prc_ttuEnding
    PARAMETERS
        Pers�na : TPers�na
        EXPORT �ttu: String

    RULES
        IF Pers�na IN [karl, kona] THEN
            �ttu:= '�ttu'
        ELSEIF Pers�na = annarKarl THEN
            �ttu:= '� hann'
        ELSEIF Pers�na = annarKona THEN
            �ttu:= '� h�n'
        ELSE
            �ttu:= '� hann/h�n'
        ENDIF

 ENDPROCEDURE

  PROCEDURE prc_stEnding
    PARAMETERS
        Pers�na : TPers�na
        EXPORT st: String

    RULES
        IF Pers�na IN [karl, kona] THEN
            st:= 'st'
        ELSE
            st:= ''
        ENDIF

 ENDPROCEDURE

  PROCEDURE prc_tuEnding
    PARAMETERS
        Pers�na : TPers�na
        EXPORT Varstu : String

    RULES
        IF Pers�na IN [karl, kona] THEN
            Varstu:= 'tu'
        ELSEIF Pers�na = annarKarl THEN
            Varstu:= '�hann'
        ELSEIF Pers�na = annarKona THEN
            Varstu:= '�h�n'
        ELSE
            Varstu:= '�hann/h�n'
        ENDIF

 ENDPROCEDURE

  PROCEDURE prc_�uEnding
    PARAMETERS
        Pers�na : TPers�na
        EXPORT Varstu : String

    RULES
        IF Pers�na IN [karl, kona] THEN
            Varstu:= '�u'
        ELSEIF Pers�na = annarKarl THEN
            Varstu:= '�hann'
        ELSEIF Pers�na = annarKona THEN
            Varstu:= '�h�n'
        ELSE
            Varstu:= '�hann/h�n'
        ENDIF
ENDPROCEDURE

  PROCEDURE prc_sjalfur
    PARAMETERS
        Pers�na : TPers�na
        EXPORT sjalfur : String
    RULES
        IF Pers�na IN [karl, annarKarl] THEN
            sjalfur:= 'sj�lfan'
        ELSEIF Pers�na IN [kona, annarKona] THEN
            sjalfur:= '�sj�lfa'
        ELSE
            sjalfur:= '�sj�lfan/sj�lfa'
        ENDIF


 ENDPROCEDURE

  PROCEDURE prc_�Ending
    PARAMETERS
        Pers�na : TPers�na
        EXPORT Varstu : String

    RULES
        IF Pers�na IN [karl, kona] THEN
            Varstu:= '�'
        ELSE
            Varstu:= ''
        ENDIF

 ENDPROCEDURE

  PROCEDURE prc_ltuEnding
    PARAMETERS
        Pers�na : TPers�na
        EXPORT Varstu : String

    RULES
        IF Pers�na IN [karl, kona] THEN
            Varstu:= 'ltu'
        ELSEIF Pers�na = annarKarl THEN
            Varstu:= 'll�hann'
        ELSEIF Pers�na = annarKona THEN
            Varstu:= 'll�h�n'
        ELSE
            Varstu:= 'll�hann/h�n'
        ENDIF

 ENDPROCEDURE


  PROCEDURE prc_nEnding
    PARAMETERS
        Pers�na : TPers�na
        EXPORT n : String
    RULES
        IF Pers�na IN [karl, annarkarl] THEN
           n := 'n'
        ELSEIF Pers�na = annar�v�st THEN
           n := '/n'
        ELSE
           n := ''
        ENDIF
  ENDPROCEDURE

  PROCEDURE prc_YouHeShe
    PARAMETERS
      Pers�na : TPers�na
      EXPORT you : String
    RULES
      IF Pers�na IN [karl, kona] THEN
        you := 'you'
      ELSEIF Pers�na = annarkarl THEN
         you := 'he'
      ELSE
         you := 'she'
      ENDIF
  ENDPROCEDURE

  PROCEDURE prc_YouHimHer
    PARAMETERS
      Pers�na : TPers�na
      EXPORT you : String
    RULES
      IF Pers�na IN [karl, kona] THEN
        you := 'you'
      ELSEIF Pers�na = annarkarl THEN
         you := 'him'
      ELSE
         you := 'her'
      ENDIF
  ENDPROCEDURE

  PROCEDURE prc_YourselfHimselfHerself
    PARAMETERS
      Pers�na : TPers�na
      EXPORT yourself : String
    RULES
      IF Pers�na IN [karl, kona] THEN
        yourself := 'yourself'
      ELSEIF Pers�na = annarkarl THEN
        yourself := 'himself'
      ELSE
        yourself := 'herself'
      ENDIF
  ENDPROCEDURE

  PROCEDURE prc_MyselfHimselfHerself
    PARAMETERS
      Pers�na : TPers�na
      EXPORT Myself : String
    RULES
      IF Pers�na IN [karl, kona] THEN
        Myself := 'myself'
      ELSEIF Pers�na = annarkarl THEN
        Myself := 'himself'
      ELSE
        Myself := 'herself'
      ENDIF
  ENDPROCEDURE

  PROCEDURE prc_YourHisHer
    PARAMETERS
      Pers�na : TPers�na
      EXPORT your : String
    RULES
      IF Pers�na IN [karl, kona] THEN
        your := 'your'
      ELSEIF Pers�na = annarkarl THEN
         your := 'his'
      ELSE
         your := 'her'
      ENDIF
  ENDPROCEDURE

  PROCEDURE prc_HaveHas
    PARAMETERS
      Pers�na : TPers�na
      EXPORT have : String
    RULES
      IF Pers�na IN [karl, kona] THEN
        have := 'have'
      ELSE
        have := 'has'
      ENDIF
  ENDPROCEDURE

  PROCEDURE prc_WereWas
    PARAMETERS
      Pers�na : TPers�na
      EXPORT were : String
    RULES
      IF Pers�na IN [karl, kona] THEN
        were := 'were'
      ELSE
        were := 'was'
      ENDIF
  ENDPROCEDURE

  PROCEDURE prc_YouDoDoes
    PARAMETERS
      Pers�na : TPers�na
      EXPORT doh : String
    RULES
      IF Pers�na IN [karl, kona] THEN
        doh := 'Do you'
      ELSEIF Pers�na = AnnarKarl THEN
        doh := 'Does he'
      ELSE
        doh := 'Does she'
      ENDIF
  ENDPROCEDURE

  PROCEDURE prc_DoDoes
    PARAMETERS
      Pers�na : TPers�na
      EXPORT doh : String
    RULES
      IF Pers�na IN [karl, kona] THEN
        doh := 'do'
      ELSE
        doh := 'does'
      ENDIF
  ENDPROCEDURE

  PROCEDURE prc_DontDoesnt
    PARAMETERS
      Pers�na : TPers�na
      EXPORT doh : String
    RULES
      IF Pers�na IN [karl, kona] THEN
        doh := 'don''t'
      ELSE
        doh := 'doesn''t'
      ENDIF
  ENDPROCEDURE

  PROCEDURE prc_AreIs
    PARAMETERS
      Pers�na : TPers�na
      EXPORT Are : String
    RULES
      IF Pers�na IN [karl, kona] THEN
        Are := 'are'
      ELSE
        Are := 'is'
      ENDIF
  ENDPROCEDURE

  PROCEDURE prc_Skyldleiki
    PARAMETERS
        HMTN2  : TTengsl
        HMKYN2 : TKyn
        EXPORT nafn : STRING

    RULES
        IF HmTn2 = Maki THEN
          NAFN := 'Maki'
        ELSEIF HmTn2 = Barn THEN
          IF HmKyn2 = Karl THEN Nafn := 'Sonur'
          ELSEIF HmKyn2 = Kona THEN Nafn := 'D�ttir'
          ELSE  NAFN := 'Barn'
          ENDIF
        ELSEIF HmTn2 = Systkini THEN
          IF HmKyn2 = Karl THEN Nafn := 'Br��ir'
          ELSEIF HmKyn2 = Kona THEN Nafn := 'Systir'
          ELSE  NAFN := 'Systkini'
          ENDIF
        ELSEIF HmTn2 = Systkinabarn THEN
          IF HmKyn2 = Karl THEN Nafn := 'Systkinasonur'
          ELSEIF HmKyn2 = Kona THEN Nafn := 'Systkinad�ttir'
          ELSE  NAFN := 'Systkinabarn'
          ENDIF
        ELSEIF HmTn2 = Foreldri THEN
          IF HmKyn2 = Karl THEN Nafn := 'Fa�ir'
          ELSEIF HmKyn2 = Kona THEN Nafn := 'M��ir'
          ELSE  NAFN := 'Foreldri'
          ENDIF
        ELSEIF HmTn2 = AfiAmma THEN
          IF HmKyn2 = Karl THEN Nafn := 'Afi'
          ELSEIF HmKyn2 = Kona THEN Nafn := 'Amma'
          ELSE  NAFN := 'Afi/amma'
          ENDIF
        ELSEIF HmTn2 = Tengdaforeldri THEN
          IF HmKyn2 = Karl THEN Nafn := 'Tengdafa�ir'
          ELSEIF HmKyn2 = Kona THEN Nafn := 'Tengdam��ir'
          ELSE  NAFN := 'Tengdaforeldri'
          ENDIF
        ELSEIF HmTn2 = Tengdabarn THEN
          IF HmKyn2 = Karl THEN Nafn := 'Tengdasonur'
          ELSEIF HmKyn2 = Kona THEN Nafn := 'Tengdad�ttir'
          ELSE  NAFN := 'Tengdabarn'
          ENDIF
        ELSEIF HmTn2 = M�gur THEN
          IF HmKyn2 = Karl THEN Nafn := 'M�gur'
          ELSEIF HmKyn2 = Kona THEN Nafn := 'M�gkona'
          ELSE  NAFN := 'M�gur / m�gkona'
          ENDIF
        ELSEIF HmTn2 = Barnabarn THEN
          IF HmKyn2 = Karl THEN Nafn := 'Barnabarn, karl'
          ELSEIF HmKyn2 = Kona THEN Nafn := 'Barnabarn, kona'
          ELSE  NAFN := 'Barnabarn'
          ENDIF
        ELSEIF HmTn2 = �ttingi THEN
          IF HmKyn2 = Karl THEN Nafn := 'Fr�ndi'
          ELSEIF HmKyn2 = Kona THEN Nafn := 'Fr�nka'
          ELSE  NAFN := 'Annar �ttingi'
          ENDIF
        ELSEIF HmTn2 = �skyldur THEN
          IF HmKyn2 = Kona THEN Nafn := '�skyld'
          ELSE  NAFN := '�skyldur'
          ENDIF
        ELSE
          NAFN := ''
        ENDIF
 ENDPROCEDURE

 PROCEDURE prc_InngangurA�Hm
    PARAMETERS
        r�� : INTEGER
        EXPORT inngangur, preamble : STRING
    RULES
     IF R�� = 0 THEN
       Inngangur := 'Ef vi� byrjum � �eim fyrsta ...@/@/'
       Preamble  := 'Beginning with the first ...@/@/'
     ELSEIF R�� = 2 THEN
       Inngangur := '�� �arf a� spyrja um �� heimilismenn sem �taldir eru. Ef vi� byrjum � �eim fyrsta ...@/@/'
       Preamble  := 'We need now to ask about the household member yet unaccouned for. Beginning with the first ...@/@/'
     ELSEIF R�� = 3 THEN
       Inngangur := '�� n�sti heimilisma�ur ...@/@/'
       Preamble  := 'Then the next household member ...@/@/'
     ELSE
       Inngangur := ''
       Preamble  := ''
     ENDIF
 ENDPROCEDURE

 PROCEDURE prc_Handah�f
    PARAMETERS
        slembitala      : real
        efrim�rk        : integer
        EXPORT heiltala : integer

    RULES
      IF int(slembitala * efrim�rk) = efrim�rk THEN   {�etta � ekki a� geta gerst}
        heiltala := int(slembitala * efrim�rk)
      ELSE
        heiltala := int(slembitala * efrim�rk) + 1
      ENDIF
 ENDPROCEDURE

 PROCEDURE prc_Fr��sluNefnis
    PARAMETERS
        Fr��sla                     : TFr��sla
        EXPORT Nefni, Identifier    : STRING

    RULES
      IF Fr��sla = n�mskei� THEN
        Nefni      := 'n�mskei�sins'
        Identifier := 'course'
      ELSEIF Fr��sla = r��stefna THEN
        Nefni      := 'r��stefnunnar'
        Identifier := 'conference'
      ELSEIF Fr��sla = m�l�ing THEN
        Nefni      := 'm�l�ingsins'
        Identifier := 'seminar'
      ELSEIF Fr��sla = fyrirlestur THEN
        Nefni      := 'fyrirlestursins'
        Identifier := 'lecture'
      ELSEIF Fr��sla = anna� THEN
        Nefni      := 'fr��slunnar'
        Identifier := 'instruction'
      ENDIF
 ENDPROCEDURE

 PROCEDURE prc_Fr��sluNefni�
    PARAMETERS
        Fr��sla                     : TFr��sla
        EXPORT Nefni, identifier    : STRING

    RULES
      IF Fr��sla = n�mskei� THEN
        Nefni      := 'n�mskei�i�'
        Identifier := 'course'
      ELSEIF Fr��sla = r��stefna THEN
        Nefni      := 'r��stefnan'
        Identifier := 'conference'
      ELSEIF Fr��sla = m�l�ing THEN
        Nefni      := 'm�l�ingi�'
        Identifier := 'seminar'
      ELSEIF Fr��sla = fyrirlestur THEN
        Nefni      := 'fyrirlesturinn'
        Identifier := 'lecture'
      ELSEIF Fr��sla = anna� THEN
        Nefni      := 'fr��slan'
        Identifier := 'instruction'
      ENDIF
 ENDPROCEDURE

 PROCEDURE prc_Fr��sluNefninu
    PARAMETERS
        Fr��sla                     : TFr��sla
        EXPORT Nefni, identifier    : STRING

    RULES
      IF Fr��sla = n�mskei� THEN
        Nefni      := 'n�mskei�inu'
        Identifier := 'course'
      ELSEIF Fr��sla = r��stefna THEN
        Nefni      := 'r��stefnunni'
        Identifier := 'conference'
      ELSEIF Fr��sla = m�l�ing THEN
        Nefni      := 'm�l�inginu'
        Identifier := 'seminar'
      ELSEIF Fr��sla = fyrirlestur THEN
        Nefni      := 'fyrirlestrinum'
        Identifier := 'lecture'
      ELSEIF Fr��sla = anna� THEN
        Nefni      := 'annarri fr��slu'
        Identifier := 'instruction'
      ENDIF
 ENDPROCEDURE

 PROCEDURE prc_Fr��sluNefnin
    PARAMETERS
        Fr��sla                    : TFr��sla
        Fj                         : INTEGER
        EXPORT Nefni, identifier   : STRING

    LOCALS
      b��i, both  : STRING
    RULES
      IF Fj = 2 THEN
        both := 'both '
      ELSEIF Fj = 3 THEN
        both := 'all '
      ELSE
        both := 'last three'
      ENDIF
      IF Fr��sla = n�mskei� THEN
        IF Fj = 2 THEN
          b��i := 'b��i '
        ELSEIF Fj = 3 THEN
          b��i := '�ll '
        ELSE
          b��i := 's��ustu �rj� '
        ENDIF
        Nefni      := b��i +'n�mskei�in'
        Identifier := both +'courses'
      ELSEIF Fr��sla = r��stefna THEN
        IF Fj = 2 THEN
          b��i := 'b��ar '
        ELSEIF Fj = 3 THEN
          b��i := 'allar �rj�r '
        ELSE
          b��i := 's��ustu �rj�r '
        ENDIF
        Nefni      := b��i + 'r��stefnurnar'
        Identifier := both + 'conferences'
      ELSEIF Fr��sla = m�l�ing THEN
        IF Fj = 2 THEN
          b��i := 'b��i '
        ELSEIF Fj = 3 THEN
          b��i := '�ll �rj� '
        ELSE
          b��i := 's��ustu �rj� '
        ENDIF
        Nefni      := b��i + 'm�l�ingin'
        Identifier := both + 'seminars'
      ELSEIF Fr��sla = fyrirlestur THEN
        IF Fj = 2 THEN
          b��i := 'b��a '
        ELSEIF Fj = 3 THEN
          b��i := 'alla �rj� '
        ELSE
          b��i := 's��ustu �rj� '
        ENDIF
        Nefni      := b��i + 'fyrirlestrana'
        Identifier := both + 'lectures'
      ELSEIF Fr��sla = anna� THEN
        IF Fj = 2 THEN
          b��i := 'b��a '
        ELSEIF Fj = 3 THEN
          b��i := 'alla �rj� '
        ELSE
          b��i := 's��ustu �rj� '
        ENDIF
        Nefni      := b��i + 'fr��sluvi�bur�ina'
        Identifier := both + 'taught activities'
      ENDIF
 ENDPROCEDURE


PROCEDURE prc_fsvSamaStarf
  PARAMETERS
    IMPORT fsv00    : Tfsv_sama
    EXPORT SpurtUmFirma, SpurtUmStarf : TJ�Nei

  RULES
      IF fsv00 = RESPONSE THEN    {ATH! H�r var skilyr�um breytt �annig a� alltaf er spurt um fyrirt�ki� sem vi�komandi vinnur hj�; SpurtUmFirma � alltaf a� vera J� til a� f� �rugglega tv�k��un � �SAT fyrir SIL2008. A�K 040208}
        IF fsv00 IN [Nei, SamaEnRangt, Anna�EnRangt] THEN
          spurtUmFirma := J�
          spurtUmStarf := J�
        ELSEIF fsv00 = J�Anna�Starf THEN
          spurtUmFirma := J�
          spurtUmStarf := J�
        ELSEIF fsv00 = J�Anna�Firma THEN
          spurtUmFirma := J�
          spurtUmStarf := J�
        ELSE
          spurtUmFirma := J�
          spurtUmStarf := J�
        ENDIF
      ELSE
        spurtUmFirma := J�
        spurtUmStarf := J�
      ENDIF
ENDPROCEDURE

 PROCEDURE prc_��Nafn
    PARAMETERS
        Pers�na : TPers�na
        Nafn : String
        EXPORT ��Nafn: String

    RULES
        IF Pers�na IN [karl, kona] THEN
            ��Nafn:= '��'
        ELSEIF Pers�na = annarKarl THEN
            ��Nafn:= '@C' + nafn + '@C'
        ELSEIF Pers�na = annarKona THEN
            ��Nafn:= '@C' + nafn + '@C'
        ELSE
            ��Nafn:= '��/hann/h�n'
        ENDIF
 ENDPROCEDURE


 PROCEDURE prc_dapur_d�pur            {sett inn jan 2013 SILC2013 vi�hengi }
    PARAMETERS
        Pers�na : TPers�na
        EXPORT dapur : String

    RULES
        IF Pers�na = karl THEN
            dapur := 'dapur'
        ELSEIF Pers�na = kona THEN
            dapur := 'd�pur'
        ELSEIF Pers�na = annarKarl THEN
            dapur := 'dapur'
        ELSEIF Pers�na = annarKona THEN
            dapur := 'd�pur'
        ELSE
            dapur := 'dapur/d�pur'
        ENDIF

 ENDPROCEDURE

 PROCEDURE prc_gla�ur_gl��            {sett inn jan 2013 SILC2013 vi�hengi }
    PARAMETERS
        Pers�na : TPers�na
        EXPORT gla�ur : String

    RULES
        IF Pers�na = karl THEN
            gla�ur := 'gla�ur'
        ELSEIF Pers�na = kona THEN
            gla�ur := 'gl��'
        ELSEIF Pers�na = annarKarl THEN
            gla�ur := 'gla�ur'
        ELSEIF Pers�na = annarKona THEN
            gla�ur := 'gl��'
        ELSE
            gla�ur := 'gla�ur/gl��'
        ENDIF

 ENDPROCEDURE
