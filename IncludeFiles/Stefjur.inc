{   Stefjur.inc
    Samfelld vinnumarkaðsrannsókn
    ÓH (c) nóvember 2002
    }

 PROCEDURE prc_fæðÁr
 PARAMETERS
    IMPORT kennitala : STRING
    EXPORT fæðÁr : INTEGER
    RULES
        IF (SUBSTRING(kennitala,9,1)='0') THEN
            fæðár  := 2000 + VAL(SUBSTRING(kennitala,5,2))
        ELSE
            fæðár  := 1900 + VAL(SUBSTRING(kennitala,5,2))
        ENDIF
 ENDPROCEDURE

 PROCEDURE prc_aldur
 PARAMETERS
    IMPORT kennitala : STRING
    IMPORT viðmiðunardagur : DateType
    EXPORT aldur : INTEGER

    LOCALS fæðÁr: INTEGER
    RULES
        prc_fæðÁr(kennitala,fæðÁr)
        aldur := YEAR(viðmiðunardagur) - fæðÁr
 ENDPROCEDURE

 PROCEDURE prc_fæðingardagur
 PARAMETERS
    IMPORT kennitala : STRING
    EXPORT fæðingardagur: DATETYPE
    EXPORT aldur : INTEGER

    LOCALS fæðÁr,fmánuður,fdagur: INTEGER
    RULES
        prc_fæðÁr(kennitala,fæðÁr)
        fmánuður := VAL(SUBSTRING(kennitala,3,2))
        fdagur := VAL(SUBSTRING(kennitala,1,2))
        fæðingardagur := (fæðár,fmánuður ,fdagur)
        aldur := YEAR(SYSDATE) - 1 - fæðÁr
 ENDPROCEDURE



 PROCEDURE prc_Mánuður
    PARAMETERS
      Viðmiðunardagur : DateType
      EXPORT Mánuður, Mnth : String

    RULES
      IF Month(Viðmiðunardagur) = 1 THEN Mánuður := 'jan.'  Mnth := 'Jan.'
      ELSEIF Month(Viðmiðunardagur) = 2 THEN  Mánuður := 'feb.' Mnth := 'Feb.'
      ELSEIF Month(Viðmiðunardagur) =  3 THEN  Mánuður := 'mar.' Mnth := 'Mar.'
      ELSEIF Month(Viðmiðunardagur) =  4 THEN  Mánuður := 'apr.' Mnth := 'Apr.'
      ELSEIF Month(Viðmiðunardagur) =  5 THEN  Mánuður := 'maí' Mnth := 'May'
      ELSEIF Month(Viðmiðunardagur) =  6 THEN  Mánuður := 'jún.' Mnth := 'June'
      ELSEIF Month(Viðmiðunardagur) =  7 THEN  Mánuður := 'júl.' Mnth := 'July'
      ELSEIF Month(Viðmiðunardagur) =  8 THEN  Mánuður := 'ágú.' Mnth := 'Aug.'
      ELSEIF Month(Viðmiðunardagur) =  9 THEN  Mánuður := 'sep.' Mnth := 'Sep.'
      ELSEIF Month(Viðmiðunardagur) =  10 THEN  Mánuður := 'okt.' Mnth := 'Oct.'
      ELSEIF Month(Viðmiðunardagur) =  11 THEN  Mánuður := 'nóv.' Mnth := 'Nov.'
      ELSEIF Month(Viðmiðunardagur) =  12 THEN  Mánuður := 'des.' Mnth := 'Dec.'
      ELSE Mánuður := '?'
      ENDIF
   ENDPROCEDURE

 PROCEDURE prc_Tímalengd
    PARAMETERS
      upphafsdagur, viðmiðunardagur : DateType
      EXPORT tími : Integer

    RULES
      tími := year(viðmiðunardagur)*12 + month(viðmiðunardagur) - (year(upphafsdagur)*12 + month(upphafsdagur))
 ENDPROCEDURE

 Procedure prc_ViðmiðunartímiUpplýst
    PARAMETERS
      upphafsdagur, viðmiðunardagur : DateType
      EXPORT viðmiðunarvika, referenceweek : String

    AUXFIELDS
      Dagur1, Dagur2     : integer
      Mánuður1, mánuður2, month1, month2: string

    RULES
      dagur1 := Day(Upphafsdagur)
      dagur2 := day(Viðmiðunardagur)
      prc_mánuður(Upphafsdagur, mánuður1, month1)
      prc_mánuður(Viðmiðunardagur, mánuður2, month2)
      Viðmiðunarvika := 'Mánudaginn ' + str(dagur1) + '. '+ mánuður1 + ' - sunnudagsins ' + str(dagur2) + '. '+mánuður2
      ReferenceWeek := 'Monday ' + str(dagur1) + '. '+ month1 + ' - Sunday ' + str(dagur2) + '. '+month2
 ENDPROCEDURE

 PROCEDURE prc_ViðmiðunartímiSpurt
   PARAMETERS
      upphafsdagur, viðmiðunardagur : DateType
      EXPORT SíðustuViku, LastWeek : String

    AUXFIELDS
      Dagur1, Dagur2     : integer
      Mánuður1, mánuður2, month1, month2 : string

    RULES
      dagur1 := Day(Upphafsdagur)
      dagur2 := day(Viðmiðunardagur)
      prc_mánuður(Upphafsdagur, mánuður1, month1)
      prc_mánuður(Viðmiðunardagur, mánuður2, month2)

    IF upphafsdagur + (0,0,6) = viðmiðunardagur THEN
      IF viðmiðunardagur + (0,0,5) < sysdate THEN
        SíðustuViku := 'vikunni ' + str(dagur1) + '. '+ mánuður1 + ' til ' + str(dagur2) + '. '+mánuður2
        LastWeek := 'the week ' + str(dagur1) + '. '+ month1 + ' to ' + str(dagur2) + '. '+month2
      ELSEIF viðmiðunardagur = sysdate THEN
        Síðustuviku := 'vikunni sem lýkur í dag'
        LastWeek := 'week ending today'
      ELSE
        Síðustuviku := 'síðustu viku'
        LastWeek := 'past week'
      ENDIF
    ELSEIF upphafsdagur + (0,0,27) = viðmiðunardagur THEN
      IF viðmiðunardagur + (0,0,5) < sysdate THEN
        SíðustuViku := 'tímabilinu mánud. ' + str(dagur1) + '. '+ mánuður1 +' til sunnud. ' + str(dagur2) + '. '+mánuður2
        LastWeek := 'the period Monday ' + str(dagur1) + '. '+ month1 +' to Sunday ' + str(dagur2) + '. '+month2
      ELSE
        Síðustuviku := 'síðustu fjórum vikum'
        LastWeek := 'the past four weeks'
      ENDIF
    ENDIF
 ENDPROCEDURE

 PROCEDURE prc_Trimma
    PARAMETERS
       Sími : String
       EXPORT nSími : String

    AUXFIELDS
        L       : Integer

    LOCALS
        i       : Integer

    RULES
      L := Len(Sími)
      IF L > 0 THEN
        For i:= 1 To 80 DO
          IF I <= L THEN
            IF Position(Substring(Sími,i,1),'0123456789/')>0 THEN nSími := nSími + Substring(Sími,i,1) ENDIF
          ENDIF
        ENDDO
      ENDIF


 ENDPROCEDURE

 PROCEDURE prc_BætaViðAðraSíma
    PARAMETERS
      sími, asímar : String
      EXPORT nsímar : String

    AUXFIELDS
      tSími, tAsímar : STRING

    RULES
      prc_Trimma (sími, tSími)
      prc_Trimma (asímar, tAsímar)
      IF (Len(tSími) >= 7) And (Position ( tSími, tAsímar) = 0) THEN
        IF tASímar > '' THEN
            nSímar := Sími + ' / ' + aSímar
        ELSE
            nSímar := Sími
        ENDIF
      ELSE
        nSímar := aSímar
      ENDIF

 ENDPROCEDURE

 PROCEDURE prc_ÞúGast
    PARAMETERS
        Persóna : TPersóna
        EXPORT Þúgast : String

    RULES
        IF Persóna IN [karl, kona] THEN
            Þúgast:= 'þú gast'
        ELSEIF Persóna = annarKarl THEN
            Þúgast:= 'hann gat'
        ELSEIF Persóna = annarKona THEN
            Þúgast:= 'hún gat'
        ELSE
            Þúgast:= 'hann/hún gat'
        ENDIF

 ENDPROCEDURE

  PROCEDURE prc_StörfumÞínum
    PARAMETERS
        Persóna : TPersóna
        EXPORT störfumþínum : String

    RULES
        IF Persóna IN [karl, kona] THEN
            störfumþínum := 'störfum þínum'
        ELSEIF Persóna = annarKarl THEN
            störfumþínum := 'störfum sínum'
        ELSEIF Persóna = annarKona THEN
            störfumþínum := 'störfum sínum'
        ELSE
            störfumþínum := 'störfum sínum'
        ENDIF

 ENDPROCEDURE


   PROCEDURE prc_Þínum
    PARAMETERS
        Persóna : TPersóna
        EXPORT störfumþínum : String

    RULES
        IF Persóna IN [karl, kona] THEN
            störfumþínum := 'þínum'
        ELSEIF Persóna = annarKarl THEN
            störfumþínum := 'sínum'
        ELSEIF Persóna = annarKona THEN
            störfumþínum := 'sínum'
        ELSE
            störfumþínum := 'sínum'
        ENDIF

 ENDPROCEDURE

  PROCEDURE prc_HeilsuÞína
    PARAMETERS
        Persóna : TPersóna
        EXPORT heilsuþína: String

    RULES
        IF Persóna IN [karl, kona] THEN
            heilsuþína:= 'heilsu þína'
        ELSEIF Persóna = annarKarl THEN
            heilsuþína:= 'heilsu sína'
        ELSEIF Persóna = annarKona THEN
            heilsuþína:= 'heilsu sína'
        ELSE
            heilsuþína:= 'heilsu sína'
        ENDIF

 ENDPROCEDURE


   PROCEDURE prc_Þinnar
    PARAMETERS
        Persóna : TPersóna
        EXPORT heilsuþína: String

    RULES
        IF Persóna IN [karl, kona] THEN
            heilsuþína:= 'þinnar'
        ELSEIF Persóna = annarKarl THEN
            heilsuþína:= 'sinnar'
        ELSEIF Persóna = annarKona THEN
            heilsuþína:= 'sinnar'
        ELSE
            heilsuþína:= 'sinnar'
        ENDIF

 ENDPROCEDURE


 PROCEDURE prc_ÞúHannHún
    PARAMETERS
        Persóna : TPersóna
        EXPORT hhann : String

    RULES
        IF Persóna IN [karl, kona] THEN
            hhann := 'þú'
        ELSEIF Persóna = annarKarl THEN
            hhann := 'hann'
        ELSEIF Persóna = annarKona THEN
            hhann := 'hún'
        ELSE
            hhann := 'hann/hún'
        ENDIF

 ENDPROCEDURE

 PROCEDURE prc_radin_radinn
    PARAMETERS
        Persóna : TPersóna
        EXPORT radinn : String

    RULES
        IF Persóna = karl THEN
            radinn := 'ráðinn'
        ELSEIF Persóna = kona THEN
            radinn := 'ráðin'
        ELSEIF Persóna = annarKarl THEN
            radinn := 'ráðinn'
        ELSEIF Persóna = annarKona THEN
            radinn := 'ráðin'
        ELSE
            radinn := 'ráðin/n'
        ENDIF

 ENDPROCEDURE


 PROCEDURE prc_Varvor
    PARAMETERS
        Persóna : TPersóna
        EXPORT var_vor : String

    RULES
        IF Persóna = karl THEN
            var_vor := 'var'
        ELSEIF Persóna = kona THEN
            var_vor := 'vör'
        ELSEIF Persóna = annarKarl THEN
            var_vor := 'var'
        ELSEIF Persóna = annarKona THEN
            var_vor := 'vör'
        ELSE
            var_vor := 'var/vör'
        ENDIF

 ENDPROCEDURE


  PROCEDURE prc_Gaeti
    PARAMETERS
        Persóna : TPersóna
        EXPORT hhann : String

    RULES
        IF Persóna IN [karl, kona] THEN
            hhann := 'Gætir'
        ELSEIF Persóna = annarKarl THEN
            hhann := 'Gæti'
        ELSEIF Persóna = annarKona THEN
            hhann := 'Gæti'
        ELSE
            hhann := 'Gæti'
        ENDIF

 ENDPROCEDURE


 PROCEDURE prc_tokstu
    PARAMETERS
        Persóna : TPersóna
        EXPORT hhann : String

    RULES
        IF Persóna IN [karl, kona] THEN
            hhann := 'tókstu þér'
        ELSEIF Persóna = annarKarl THEN
            hhann := 'tók hann sér'
        ELSEIF Persóna = annarKona THEN
            hhann := 'tók hún sér'
        ELSE
            hhann := 'tók hann/hún sér'
        ENDIF

 ENDPROCEDURE



  PROCEDURE prc_þinni
    PARAMETERS
        Persóna : TPersóna
        EXPORT hhann : String

    RULES
        IF Persóna IN [karl, kona] THEN
            hhann := 'þinni'
        ELSEIF Persóna = annarKarl THEN
            hhann := 'hans'
        ELSEIF Persóna = annarKona THEN
            hhann := 'hennar'
        ELSE
            hhann := 'hans/hennar'
        ENDIF

 ENDPROCEDURE


   PROCEDURE prc_fórstu
    PARAMETERS
        Persóna : TPersóna
        EXPORT hhann : String

    RULES
        IF Persóna IN [karl, kona] THEN
            hhann := 'Fórst þú'
        ELSEIF Persóna = annarKarl THEN
            hhann := 'Fór hann'
        ELSEIF Persóna = annarKona THEN
            hhann := 'Fór hún'
        ELSE
            hhann := 'Fór hann/hún'
        ENDIF

 ENDPROCEDURE


  PROCEDURE prc_fekkstu
    PARAMETERS
        Persóna : TPersóna
        EXPORT hhann : String

    RULES
        IF Persóna IN [karl, kona] THEN
            hhann := 'fékkst þú'
        ELSEIF Persóna = annarKarl THEN
            hhann := 'fékk hann'
        ELSEIF Persóna = annarKona THEN
            hhann := 'fékk hún'
        ELSE
            hhann := 'fékk hann/hún'
        ENDIF

 ENDPROCEDURE



   PROCEDURE prc_haettirdu
    PARAMETERS
        Persóna : TPersóna
        EXPORT hhann : String

    RULES
        IF Persóna IN [karl, kona] THEN
            hhann := 'Hættir þú'
        ELSEIF Persóna = annarKarl THEN
            hhann := 'Hætti hann'
        ELSEIF Persóna = annarKona THEN
            hhann := 'Hætti hún'
        ELSE
            hhann := 'Hætti hann/hún'
        ENDIF

 ENDPROCEDURE


   PROCEDURE prc_skiptirdu
    PARAMETERS
        Persóna : TPersóna
        EXPORT hhann : String

    RULES
        IF Persóna IN [karl, kona] THEN
            hhann := 'skiptir þú'
        ELSEIF Persóna = annarKarl THEN
            hhann := 'skipti hann'
        ELSEIF Persóna = annarKona THEN
            hhann := 'skipti hún'
        ELSE
            hhann := 'skipti hann/hún'
        ENDIF

 ENDPROCEDURE



 PROCEDURE prc_ÞigHannHana
    PARAMETERS
        Persóna : TPersóna
        EXPORT hhann : String

    RULES
        IF Persóna IN [karl, kona] THEN
            hhann := 'þig'
        ELSEIF Persóna = annarKarl THEN
            hhann := 'hann'
        ELSEIF Persóna = annarKona THEN
            hhann := 'hana'
        ELSE
            hhann := 'hann/hana'
        ENDIF

 ENDPROCEDURE

  PROCEDURE prc_skipulagdi_hann_hun_thu
    PARAMETERS
        Persóna : TPersóna
        EXPORT skipulagdi: String

    RULES
        IF Persóna IN [karl, kona] THEN
            skipulagdi:= 'Skipulagðir þú eða stjórnaðir'
        ELSEIF Persóna = annarKarl THEN
            skipulagdi:= 'Skipulagði hann eða stjórnaði'
        ELSEIF Persóna = annarKona THEN
            skipulagdi:= 'Skipulagði hún eða stjórnaði'
        ELSE
            skipulagdi:= 'Skipulagði hann/hún eða stjórnaði'
        ENDIF

 ENDPROCEDURE

   PROCEDURE prc_for_hann_hun_thu
    PARAMETERS
        Persóna : TPersóna
        EXPORT for_med: String

    RULES
        IF Persóna IN [karl, kona] THEN
            for_med:= 'Fórst þú með'
        ELSEIF Persóna = annarKarl THEN
            for_med:= 'Fór hann með'
        ELSEIF Persóna = annarKona THEN
            for_med:= 'Fór hún með'
        ELSE
            for_med:= 'Fór hann/hún með'
        ENDIF

 ENDPROCEDURE


 PROCEDURE prc_ÞittHannHana
    PARAMETERS
        Persóna : TPersóna
        EXPORT hhann : String

    RULES
        IF Persóna IN [karl, kona] THEN
            hhann := 'þitt'
        ELSEIF Persóna = annarKarl THEN
            hhann := 'hann'
        ELSEIF Persóna = annarKona THEN
            hhann := 'hana'
        ELSE
            hhann := 'hann/hana'
        ENDIF

 ENDPROCEDURE


  PROCEDURE prc_ÞinnHansHennar
    PARAMETERS
        Persóna : TPersóna
        EXPORT hhana : String

    RULES
        IF Persóna IN [karl, kona] THEN
            hhana := 'þinn'
        ELSEIF Persóna = annarKarl THEN
            hhana := 'hans'
        ELSEIF Persóna = annarKona THEN
            hhana := 'hennar'
        ELSE
            hhana := 'hans/hennar'
        ENDIF

 ENDPROCEDURE

  PROCEDURE prc_ferdthu
    PARAMETERS
        Persóna : TPersóna
        EXPORT ferdthu : String

    RULES
        IF Persóna IN [karl, kona] THEN
            ferdthu := 'Ferð þú'
        ELSEIF Persóna = annarKarl THEN
            ferdthu := 'Fer hann'
        ELSEIF Persóna = annarKona THEN
            ferdthu := 'Fer hún'
        ELSE
            ferdthu := 'Fer hann/hún'
        ENDIF

 ENDPROCEDURE

   PROCEDURE prc_sjalf_ur
    PARAMETERS
        Persóna : TPersóna
        EXPORT sjalf_ur : String

    RULES
        IF Persóna in [kona, annarKona] THEN
            sjalf_ur := 'sjálf'
        ELSEIF Persóna in [karl, annarKarl] THEN
            sjalf_ur := 'sjálfur'
        ELSE
            sjalf_ur := 'Sjálf/ur'
        ENDIF

 ENDPROCEDURE

    PROCEDURE prc_thu_vaerir
    PARAMETERS
        Persóna : TPersóna
        EXPORT thu_vaerir : String

    RULES
        IF Persóna in [karl, kona] THEN
            thu_vaerir := 'þú værir'
        ELSEIF Persóna in [annarKarl] THEN
            thu_vaerir := 'hann væri'
        ELSEIF Persóna in [annarKona] THEN
            thu_vaerir := 'hún væri'
        ELSE
            thu_vaerir := 'hann/hún væri'
        ENDIF

 ENDPROCEDURE

  PROCEDURE prc_ÞínaHansHennar
    PARAMETERS
        Persóna : TPersóna
        EXPORT þína : String

    RULES
        IF Persóna IN [karl, kona] THEN
            þína := 'þína'
        ELSEIF Persóna = annarKarl THEN
            þína := 'hans'
        ELSEIF Persóna = annarKona THEN
            þína := 'hennar'
        ELSE
            þína := 'hans/hennar'
        ENDIF

 ENDPROCEDURE

 PROCEDURE prc_ÞínumHansHennar
    PARAMETERS
        Persóna : TPersóna
        EXPORT hhans : String

    RULES
        IF Persóna IN [karl, kona] THEN
            hhans := 'þínum'
        ELSEIF Persóna = annarKarl THEN
            hhans := 'hans'
        ELSEIF Persóna = annarKona THEN
            hhans := 'hennar'
        ELSE
            hhans := 'hans/hennar'
        ENDIF

 ENDPROCEDURE

 PROCEDURE prc_ÞínuHansHennar
    PARAMETERS
        Persóna : TPersóna
        EXPORT hhans : String

    RULES
        IF Persóna IN [karl, kona] THEN
            hhans := 'þínu'
        ELSEIF Persóna = annarKarl THEN
            hhans := 'hans'
        ELSEIF Persóna = annarKona THEN
            hhans := 'hennar'
        ELSE
            hhans := 'hans/hennar'
        ENDIF

 ENDPROCEDURE

 PROCEDURE prc_rEnding
    PARAMETERS
      IMPORT Persóna : TPersóna
      EXPORT r : String

    RULES
      IF Persóna IN [karl, kona] THEN
          r := 'r'
      ELSE
          r := ''
      ENDIF
 ENDPROCEDURE

 PROCEDURE prc_ÞérHonumHenni
    PARAMETERS
        Persóna : TPersóna
        EXPORT þérhonum : String

    RULES
        IF Persóna IN [karl, kona] THEN
            þérhonum := 'þér'
        ELSEIF Persóna = annarKarl THEN
            þérhonum := 'honum'
        ELSEIF Persóna = annarKona THEN
            þérhonum := 'henni'
        ELSE
            þérhonum := 'honum/henni'
        ENDIF

 ENDPROCEDURE

 PROCEDURE prc_ÞínHansHennar
    PARAMETERS
        Persóna : TPersóna
        EXPORT þér : String

    RULES
        IF Persóna IN [karl, kona] THEN
            þér := 'þín'
        ELSEIF Persóna = annarKarl THEN
            þér := 'hans'
        ELSEIF Persóna = annarKona THEN
            þér := 'hennar'
        ELSE
            þér := 'hans/hennar'
        ENDIF

 ENDPROCEDURE

 PROCEDURE prc_ÞérSér
    PARAMETERS
      IMPORT Persóna : TPersóna
      EXPORT þér : String

    RULES
      IF Persóna IN [karl, kona] THEN
          þér := 'þér'
      ELSE
          þér := 'sér'
      ENDIF
 ENDPROCEDURE

 PROCEDURE prc_ÞínuSínu
    PARAMETERS
      IMPORT Persóna : TPersóna
      EXPORT þínu: String

    RULES
      IF Persóna IN [karl, kona] THEN
          þínu:= 'þínu'
      ELSE
          þínu:= 'sínu'
      ENDIF
 ENDPROCEDURE


 PROCEDURE prc_ÞigSig
    PARAMETERS
      IMPORT Persóna : TPersóna
      EXPORT þig : String

    RULES
      IF Persóna IN [karl, kona] THEN
          þig := 'þig'
      ELSE
          þig := 'sig'
      ENDIF
 ENDPROCEDURE

 PROCEDURE prc_ÞínaSína
    PARAMETERS
      IMPORT Persóna : TPersóna
      EXPORT Þína: String

    RULES
      IF Persóna IN [karl, kona] THEN
          Þína:= 'þína'
      ELSE
          Þína:= 'sína'
      ENDIF
 ENDPROCEDURE

  PROCEDURE prc_ÞittHansHennar
    PARAMETERS
        Persóna : TPersóna
        EXPORT hhana : String

    RULES
        IF Persóna IN [karl, kona] THEN
            hhana := 'þitt'
        ELSEIF Persóna = annarKarl THEN
            hhana := 'hans'
        ELSEIF Persóna = annarKona THEN
            hhana := 'hennar'
        ELSE
            hhana := 'hans/hennar'
        ENDIF

 ENDPROCEDURE


  PROCEDURE prc_ErErt
    PARAMETERS
        Persóna : TPersóna
        EXPORT Ert : String

    RULES
        IF Persóna IN [karl, kona] THEN
            Ert := 'Ert'
        ELSE
            Ert := 'Er'
        ENDIF

 ENDPROCEDURE

  PROCEDURE prc_urEnding
    PARAMETERS
        Persóna : TPersóna
        EXPORT ur : String

    RULES
        IF Persóna IN [kona, annarkona] THEN
            ur := ''
        ELSE
            ur := 'ur'
        ENDIF

 ENDPROCEDURE

  PROCEDURE prc_fatlkyn
    PARAMETERS
        Persóna : TPersóna
        EXPORT fatlaður : String

    RULES
        IF Persóna IN [kona, annarkona] THEN
            fatlaður := 'fötluð'
        ELSE
            fatlaður := 'fatlaður '
        ENDIF

 ENDPROCEDURE

  PROCEDURE prc_Meðtöldum
    PARAMETERS
        Persóna : TPersóna
        EXPORT Meðtöldum : String

    RULES
        IF Persóna IN [kona, annarkona] THEN
            Meðtöldum := 'meðtalinni'
        ELSE
            Meðtöldum := 'meðtöldum'
        ENDIF

 ENDPROCEDURE

  PROCEDURE prc_ggamall
    PARAMETERS
        Persóna : TPersóna
        EXPORT ggamall : String

    RULES
        IF Persóna IN [kona, annarkona] THEN
            ggamall := 'gömul'
        ELSE
            ggamall := 'gamall'
        ENDIF

 ENDPROCEDURE

  PROCEDURE prc_stuEnding
    PARAMETERS
        Persóna : TPersóna
        EXPORT Varstu : String

    RULES
        IF Persóna IN [karl, kona] THEN
            Varstu:= 'stu'
        ELSEIF Persóna = annarKarl THEN
            Varstu:= '·hann'
        ELSEIF Persóna = annarKona THEN
            Varstu:= '·hún'
        ELSE
            Varstu:= '·hann/hún'
        ENDIF

 ENDPROCEDURE

   PROCEDURE prc_ttuEnding
    PARAMETERS
        Persóna : TPersóna
        EXPORT Áttu: String

    RULES
        IF Persóna IN [karl, kona] THEN
            Áttu:= 'Áttu'
        ELSEIF Persóna = annarKarl THEN
            Áttu:= 'Á hann'
        ELSEIF Persóna = annarKona THEN
            Áttu:= 'Á hún'
        ELSE
            Áttu:= 'Á hann/hún'
        ENDIF

 ENDPROCEDURE

  PROCEDURE prc_stEnding
    PARAMETERS
        Persóna : TPersóna
        EXPORT st: String

    RULES
        IF Persóna IN [karl, kona] THEN
            st:= 'st'
        ELSE
            st:= ''
        ENDIF

 ENDPROCEDURE

  PROCEDURE prc_tuEnding
    PARAMETERS
        Persóna : TPersóna
        EXPORT Varstu : String

    RULES
        IF Persóna IN [karl, kona] THEN
            Varstu:= 'tu'
        ELSEIF Persóna = annarKarl THEN
            Varstu:= '·hann'
        ELSEIF Persóna = annarKona THEN
            Varstu:= '·hún'
        ELSE
            Varstu:= '·hann/hún'
        ENDIF

 ENDPROCEDURE

  PROCEDURE prc_ðuEnding
    PARAMETERS
        Persóna : TPersóna
        EXPORT Varstu : String

    RULES
        IF Persóna IN [karl, kona] THEN
            Varstu:= 'ðu'
        ELSEIF Persóna = annarKarl THEN
            Varstu:= '·hann'
        ELSEIF Persóna = annarKona THEN
            Varstu:= '·hún'
        ELSE
            Varstu:= '·hann/hún'
        ENDIF
ENDPROCEDURE

  PROCEDURE prc_sjalfur
    PARAMETERS
        Persóna : TPersóna
        EXPORT sjalfur : String
    RULES
        IF Persóna IN [karl, annarKarl] THEN
            sjalfur:= 'sjálfan'
        ELSEIF Persóna IN [kona, annarKona] THEN
            sjalfur:= '·sjálfa'
        ELSE
            sjalfur:= '·sjálfan/sjálfa'
        ENDIF


 ENDPROCEDURE

  PROCEDURE prc_ðEnding
    PARAMETERS
        Persóna : TPersóna
        EXPORT Varstu : String

    RULES
        IF Persóna IN [karl, kona] THEN
            Varstu:= 'ð'
        ELSE
            Varstu:= ''
        ENDIF

 ENDPROCEDURE

  PROCEDURE prc_ltuEnding
    PARAMETERS
        Persóna : TPersóna
        EXPORT Varstu : String

    RULES
        IF Persóna IN [karl, kona] THEN
            Varstu:= 'ltu'
        ELSEIF Persóna = annarKarl THEN
            Varstu:= 'll·hann'
        ELSEIF Persóna = annarKona THEN
            Varstu:= 'll·hún'
        ELSE
            Varstu:= 'll·hann/hún'
        ENDIF

 ENDPROCEDURE


  PROCEDURE prc_nEnding
    PARAMETERS
        Persóna : TPersóna
        EXPORT n : String
    RULES
        IF Persóna IN [karl, annarkarl] THEN
           n := 'n'
        ELSEIF Persóna = annaróvíst THEN
           n := '/n'
        ELSE
           n := ''
        ENDIF
  ENDPROCEDURE

  PROCEDURE prc_YouHeShe
    PARAMETERS
      Persóna : TPersóna
      EXPORT you : String
    RULES
      IF Persóna IN [karl, kona] THEN
        you := 'you'
      ELSEIF Persóna = annarkarl THEN
         you := 'he'
      ELSE
         you := 'she'
      ENDIF
  ENDPROCEDURE

  PROCEDURE prc_YouHimHer
    PARAMETERS
      Persóna : TPersóna
      EXPORT you : String
    RULES
      IF Persóna IN [karl, kona] THEN
        you := 'you'
      ELSEIF Persóna = annarkarl THEN
         you := 'him'
      ELSE
         you := 'her'
      ENDIF
  ENDPROCEDURE

  PROCEDURE prc_YourselfHimselfHerself
    PARAMETERS
      Persóna : TPersóna
      EXPORT yourself : String
    RULES
      IF Persóna IN [karl, kona] THEN
        yourself := 'yourself'
      ELSEIF Persóna = annarkarl THEN
        yourself := 'himself'
      ELSE
        yourself := 'herself'
      ENDIF
  ENDPROCEDURE

  PROCEDURE prc_MyselfHimselfHerself
    PARAMETERS
      Persóna : TPersóna
      EXPORT Myself : String
    RULES
      IF Persóna IN [karl, kona] THEN
        Myself := 'myself'
      ELSEIF Persóna = annarkarl THEN
        Myself := 'himself'
      ELSE
        Myself := 'herself'
      ENDIF
  ENDPROCEDURE

  PROCEDURE prc_YourHisHer
    PARAMETERS
      Persóna : TPersóna
      EXPORT your : String
    RULES
      IF Persóna IN [karl, kona] THEN
        your := 'your'
      ELSEIF Persóna = annarkarl THEN
         your := 'his'
      ELSE
         your := 'her'
      ENDIF
  ENDPROCEDURE

  PROCEDURE prc_HaveHas
    PARAMETERS
      Persóna : TPersóna
      EXPORT have : String
    RULES
      IF Persóna IN [karl, kona] THEN
        have := 'have'
      ELSE
        have := 'has'
      ENDIF
  ENDPROCEDURE

  PROCEDURE prc_WereWas
    PARAMETERS
      Persóna : TPersóna
      EXPORT were : String
    RULES
      IF Persóna IN [karl, kona] THEN
        were := 'were'
      ELSE
        were := 'was'
      ENDIF
  ENDPROCEDURE

  PROCEDURE prc_YouDoDoes
    PARAMETERS
      Persóna : TPersóna
      EXPORT doh : String
    RULES
      IF Persóna IN [karl, kona] THEN
        doh := 'Do you'
      ELSEIF Persóna = AnnarKarl THEN
        doh := 'Does he'
      ELSE
        doh := 'Does she'
      ENDIF
  ENDPROCEDURE

  PROCEDURE prc_DoDoes
    PARAMETERS
      Persóna : TPersóna
      EXPORT doh : String
    RULES
      IF Persóna IN [karl, kona] THEN
        doh := 'do'
      ELSE
        doh := 'does'
      ENDIF
  ENDPROCEDURE

  PROCEDURE prc_DontDoesnt
    PARAMETERS
      Persóna : TPersóna
      EXPORT doh : String
    RULES
      IF Persóna IN [karl, kona] THEN
        doh := 'don''t'
      ELSE
        doh := 'doesn''t'
      ENDIF
  ENDPROCEDURE

  PROCEDURE prc_AreIs
    PARAMETERS
      Persóna : TPersóna
      EXPORT Are : String
    RULES
      IF Persóna IN [karl, kona] THEN
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
          ELSEIF HmKyn2 = Kona THEN Nafn := 'Dóttir'
          ELSE  NAFN := 'Barn'
          ENDIF
        ELSEIF HmTn2 = Systkini THEN
          IF HmKyn2 = Karl THEN Nafn := 'Bróðir'
          ELSEIF HmKyn2 = Kona THEN Nafn := 'Systir'
          ELSE  NAFN := 'Systkini'
          ENDIF
        ELSEIF HmTn2 = Systkinabarn THEN
          IF HmKyn2 = Karl THEN Nafn := 'Systkinasonur'
          ELSEIF HmKyn2 = Kona THEN Nafn := 'Systkinadóttir'
          ELSE  NAFN := 'Systkinabarn'
          ENDIF
        ELSEIF HmTn2 = Foreldri THEN
          IF HmKyn2 = Karl THEN Nafn := 'Faðir'
          ELSEIF HmKyn2 = Kona THEN Nafn := 'Móðir'
          ELSE  NAFN := 'Foreldri'
          ENDIF
        ELSEIF HmTn2 = AfiAmma THEN
          IF HmKyn2 = Karl THEN Nafn := 'Afi'
          ELSEIF HmKyn2 = Kona THEN Nafn := 'Amma'
          ELSE  NAFN := 'Afi/amma'
          ENDIF
        ELSEIF HmTn2 = Tengdaforeldri THEN
          IF HmKyn2 = Karl THEN Nafn := 'Tengdafaðir'
          ELSEIF HmKyn2 = Kona THEN Nafn := 'Tengdamóðir'
          ELSE  NAFN := 'Tengdaforeldri'
          ENDIF
        ELSEIF HmTn2 = Tengdabarn THEN
          IF HmKyn2 = Karl THEN Nafn := 'Tengdasonur'
          ELSEIF HmKyn2 = Kona THEN Nafn := 'Tengdadóttir'
          ELSE  NAFN := 'Tengdabarn'
          ENDIF
        ELSEIF HmTn2 = Mágur THEN
          IF HmKyn2 = Karl THEN Nafn := 'Mágur'
          ELSEIF HmKyn2 = Kona THEN Nafn := 'Mágkona'
          ELSE  NAFN := 'Mágur / mágkona'
          ENDIF
        ELSEIF HmTn2 = Barnabarn THEN
          IF HmKyn2 = Karl THEN Nafn := 'Barnabarn, karl'
          ELSEIF HmKyn2 = Kona THEN Nafn := 'Barnabarn, kona'
          ELSE  NAFN := 'Barnabarn'
          ENDIF
        ELSEIF HmTn2 = Ættingi THEN
          IF HmKyn2 = Karl THEN Nafn := 'Frændi'
          ELSEIF HmKyn2 = Kona THEN Nafn := 'Frænka'
          ELSE  NAFN := 'Annar ættingi'
          ENDIF
        ELSEIF HmTn2 = Óskyldur THEN
          IF HmKyn2 = Kona THEN Nafn := 'Óskyld'
          ELSE  NAFN := 'Óskyldur'
          ENDIF
        ELSE
          NAFN := ''
        ENDIF
 ENDPROCEDURE

 PROCEDURE prc_InngangurAðHm
    PARAMETERS
        röð : INTEGER
        EXPORT inngangur, preamble : STRING
    RULES
     IF Röð = 0 THEN
       Inngangur := 'Ef við byrjum á þeim fyrsta ...@/@/'
       Preamble  := 'Beginning with the first ...@/@/'
     ELSEIF Röð = 2 THEN
       Inngangur := 'Þá þarf að spyrja um þá heimilismenn sem ótaldir eru. Ef við byrjum á þeim fyrsta ...@/@/'
       Preamble  := 'We need now to ask about the household member yet unaccouned for. Beginning with the first ...@/@/'
     ELSEIF Röð = 3 THEN
       Inngangur := 'Þá næsti heimilismaður ...@/@/'
       Preamble  := 'Then the next household member ...@/@/'
     ELSE
       Inngangur := ''
       Preamble  := ''
     ENDIF
 ENDPROCEDURE

 PROCEDURE prc_Handahóf
    PARAMETERS
        slembitala      : real
        efrimörk        : integer
        EXPORT heiltala : integer

    RULES
      IF int(slembitala * efrimörk) = efrimörk THEN   {þetta á ekki að geta gerst}
        heiltala := int(slembitala * efrimörk)
      ELSE
        heiltala := int(slembitala * efrimörk) + 1
      ENDIF
 ENDPROCEDURE

 PROCEDURE prc_FræðsluNefnis
    PARAMETERS
        Fræðsla                     : TFræðsla
        EXPORT Nefni, Identifier    : STRING

    RULES
      IF Fræðsla = námskeið THEN
        Nefni      := 'námskeiðsins'
        Identifier := 'course'
      ELSEIF Fræðsla = ráðstefna THEN
        Nefni      := 'ráðstefnunnar'
        Identifier := 'conference'
      ELSEIF Fræðsla = málþing THEN
        Nefni      := 'málþingsins'
        Identifier := 'seminar'
      ELSEIF Fræðsla = fyrirlestur THEN
        Nefni      := 'fyrirlestursins'
        Identifier := 'lecture'
      ELSEIF Fræðsla = annað THEN
        Nefni      := 'fræðslunnar'
        Identifier := 'instruction'
      ENDIF
 ENDPROCEDURE

 PROCEDURE prc_FræðsluNefnið
    PARAMETERS
        Fræðsla                     : TFræðsla
        EXPORT Nefni, identifier    : STRING

    RULES
      IF Fræðsla = námskeið THEN
        Nefni      := 'námskeiðið'
        Identifier := 'course'
      ELSEIF Fræðsla = ráðstefna THEN
        Nefni      := 'ráðstefnan'
        Identifier := 'conference'
      ELSEIF Fræðsla = málþing THEN
        Nefni      := 'málþingið'
        Identifier := 'seminar'
      ELSEIF Fræðsla = fyrirlestur THEN
        Nefni      := 'fyrirlesturinn'
        Identifier := 'lecture'
      ELSEIF Fræðsla = annað THEN
        Nefni      := 'fræðslan'
        Identifier := 'instruction'
      ENDIF
 ENDPROCEDURE

 PROCEDURE prc_FræðsluNefninu
    PARAMETERS
        Fræðsla                     : TFræðsla
        EXPORT Nefni, identifier    : STRING

    RULES
      IF Fræðsla = námskeið THEN
        Nefni      := 'námskeiðinu'
        Identifier := 'course'
      ELSEIF Fræðsla = ráðstefna THEN
        Nefni      := 'ráðstefnunni'
        Identifier := 'conference'
      ELSEIF Fræðsla = málþing THEN
        Nefni      := 'málþinginu'
        Identifier := 'seminar'
      ELSEIF Fræðsla = fyrirlestur THEN
        Nefni      := 'fyrirlestrinum'
        Identifier := 'lecture'
      ELSEIF Fræðsla = annað THEN
        Nefni      := 'annarri fræðslu'
        Identifier := 'instruction'
      ENDIF
 ENDPROCEDURE

 PROCEDURE prc_FræðsluNefnin
    PARAMETERS
        Fræðsla                    : TFræðsla
        Fj                         : INTEGER
        EXPORT Nefni, identifier   : STRING

    LOCALS
      bæði, both  : STRING
    RULES
      IF Fj = 2 THEN
        both := 'both '
      ELSEIF Fj = 3 THEN
        both := 'all '
      ELSE
        both := 'last three'
      ENDIF
      IF Fræðsla = námskeið THEN
        IF Fj = 2 THEN
          bæði := 'bæði '
        ELSEIF Fj = 3 THEN
          bæði := 'öll '
        ELSE
          bæði := 'síðustu þrjú '
        ENDIF
        Nefni      := bæði +'námskeiðin'
        Identifier := both +'courses'
      ELSEIF Fræðsla = ráðstefna THEN
        IF Fj = 2 THEN
          bæði := 'báðar '
        ELSEIF Fj = 3 THEN
          bæði := 'allar þrjár '
        ELSE
          bæði := 'síðustu þrjár '
        ENDIF
        Nefni      := bæði + 'ráðstefnurnar'
        Identifier := both + 'conferences'
      ELSEIF Fræðsla = málþing THEN
        IF Fj = 2 THEN
          bæði := 'bæði '
        ELSEIF Fj = 3 THEN
          bæði := 'öll þrjú '
        ELSE
          bæði := 'síðustu þrjú '
        ENDIF
        Nefni      := bæði + 'málþingin'
        Identifier := both + 'seminars'
      ELSEIF Fræðsla = fyrirlestur THEN
        IF Fj = 2 THEN
          bæði := 'báða '
        ELSEIF Fj = 3 THEN
          bæði := 'alla þrjá '
        ELSE
          bæði := 'síðustu þrjá '
        ENDIF
        Nefni      := bæði + 'fyrirlestrana'
        Identifier := both + 'lectures'
      ELSEIF Fræðsla = annað THEN
        IF Fj = 2 THEN
          bæði := 'báða '
        ELSEIF Fj = 3 THEN
          bæði := 'alla þrjá '
        ELSE
          bæði := 'síðustu þrjá '
        ENDIF
        Nefni      := bæði + 'fræðsluviðburðina'
        Identifier := both + 'taught activities'
      ENDIF
 ENDPROCEDURE


PROCEDURE prc_fsvSamaStarf
  PARAMETERS
    IMPORT fsv00    : Tfsv_sama
    EXPORT SpurtUmFirma, SpurtUmStarf : TJáNei

  RULES
      IF fsv00 = RESPONSE THEN    {ATH! Hér var skilyrðum breytt þannig að alltaf er spurt um fyrirtækið sem viðkomandi vinnur hjá; SpurtUmFirma á alltaf að vera Já til að fá örugglega tvíkóðun á ÍSAT fyrir SIL2008. AÖK 040208}
        IF fsv00 IN [Nei, SamaEnRangt, AnnaðEnRangt] THEN
          spurtUmFirma := Já
          spurtUmStarf := Já
        ELSEIF fsv00 = JáAnnaðStarf THEN
          spurtUmFirma := Já
          spurtUmStarf := Já
        ELSEIF fsv00 = JáAnnaðFirma THEN
          spurtUmFirma := Já
          spurtUmStarf := Já
        ELSE
          spurtUmFirma := Já
          spurtUmStarf := Já
        ENDIF
      ELSE
        spurtUmFirma := Já
        spurtUmStarf := Já
      ENDIF
ENDPROCEDURE

 PROCEDURE prc_ÞúNafn
    PARAMETERS
        Persóna : TPersóna
        Nafn : String
        EXPORT ÞúNafn: String

    RULES
        IF Persóna IN [karl, kona] THEN
            ÞúNafn:= 'þú'
        ELSEIF Persóna = annarKarl THEN
            ÞúNafn:= '@C' + nafn + '@C'
        ELSEIF Persóna = annarKona THEN
            ÞúNafn:= '@C' + nafn + '@C'
        ELSE
            ÞúNafn:= 'þú/hann/hún'
        ENDIF
 ENDPROCEDURE


 PROCEDURE prc_dapur_döpur            {sett inn jan 2013 SILC2013 viðhengi }
    PARAMETERS
        Persóna : TPersóna
        EXPORT dapur : String

    RULES
        IF Persóna = karl THEN
            dapur := 'dapur'
        ELSEIF Persóna = kona THEN
            dapur := 'döpur'
        ELSEIF Persóna = annarKarl THEN
            dapur := 'dapur'
        ELSEIF Persóna = annarKona THEN
            dapur := 'döpur'
        ELSE
            dapur := 'dapur/döpur'
        ENDIF

 ENDPROCEDURE

 PROCEDURE prc_glaður_glöð            {sett inn jan 2013 SILC2013 viðhengi }
    PARAMETERS
        Persóna : TPersóna
        EXPORT glaður : String

    RULES
        IF Persóna = karl THEN
            glaður := 'glaður'
        ELSEIF Persóna = kona THEN
            glaður := 'glöð'
        ELSEIF Persóna = annarKarl THEN
            glaður := 'glaður'
        ELSEIF Persóna = annarKona THEN
            glaður := 'glöð'
        ELSE
            glaður := 'glaður/glöð'
        ENDIF

 ENDPROCEDURE
