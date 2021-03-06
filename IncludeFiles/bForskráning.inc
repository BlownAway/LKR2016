{bForskr�ning.inc
 �H (c) mars 2003 v. 2. �tg. VMR-ey�ubla�s}


EMBEDDED BLOCK BForskr�ning "Athuga forskr�ningu � heimili"
  PARAMETERS
    IMPORT Pers�na         : TPers�na
           fj�ldiHeimili   : INTEGER     {fj�ldi heimilismanna}
           Fj�ldi          : INTEGER     {fj�ldi annarra heimilismanna}
    EXPORT Fj�ldi�tstrika�raHeimilismanna        : tHmFj       {skila fj�lda �tstrika�ra heimilismanna}

  FIELDS
    HmMed (Hm03)
      "^haus@/^fsvar@/^strik@/
       �� eru nokkrar spurningar um ^hina_heimilismennina og hvernig ^�eir ^tengjast ^��r^Ef_vi�_byrjum_�_�eim_fyrsta"
      "^haus@/^fsvar@/^strik@/
       Then there are few questions on other ^members of the household and how ^they ^are connected to ^you^Beginning_with_first"
      /"Form�li"
      : STRING[1], EMPTY
    HmSkr� (Hm04)
      "^haus@/^fsvar@/^strik@/
       Er einhver af eftirfarandi ekki � heimilinu ?
       @/@/@RSPYRILL!!! Merktu bara vi� �� sem b�a EKKI � heimilinu - Engin breyting = ENTER@R"
      "^haus@/^fsvar@/^strik@/
       Then, a few questions about who lives in the household and how they are connected to ^you@/
       Have any of the following left home? @/@/@G
       /@RSPYRILL!!! Merktu bara vi� �� sem b�a EKKI � heimilinu - Engin breyting = ENTER@R"
      /"Listi yfir heimilismenn"
       : SET OF
        (ENGINN  "B�R EKKI ME� NEINUM �ESSARA!",
         heim02  "^heimNafn[2]",
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

        HmHvorFlutti "^haus@/^fsvar@/^strik@/
                        @G^brottfluttnafn b�r ekki lengur me� svaranda@G
                        @/@/Fluttir �� af heimilinu, flutti ^brottfluttnafn e�a hafi� �i� aldrei b�i� � sama heimilinu?"
                        "^haus@/^fsvar@/^strik@/
                        @G^brottfluttnafn b�r ekki lengur me� svaranda@G
                        @/@/Did you move away from the home, did ^nafn_brottflutts move or has ^brottfluttnafn never lived with you?"
                        / "Hver flutti" : array[2..15] of
        ( svarandi      "Svarandi flutti",
          hinn          "Hann/h�n flutti",
          aldrei        "Hafa aldrei b�i� � sama heimili",
          latinn        "Hann/h�n l�st"
         )


        HmHvertFluttur "^haus@/^fsvar@/^strik@/
                        @G^brottfluttnafn b�r ekki lengur me� svaranda@G
                        @/@/^hm_txt_1"
                        "^haus@/^fsvar@/^strik@/
                        @G^brottfluttnafn b�r ekki lengur me� svaranda@G
                        @/@/Did ^nafn_brottflutts years old, move abroad, to another household within the country, to an institution or somewhere else?"
                        / "Hvert fluttur" : array[2..15] of
        ( til_�tlanda "Til �tlanda" "Abroad",
          anna�_innan "� (anna�) heimili innanlands" "To another household within the country",
          stofnun     "� stofnun e�a samb�li" "To an institution",
          anna�       "Anna�" "Somewhere else"
         )

        HmHvertAnna�  "^haus@/^fsvar@/^strik@/
                        @G^brottfluttnafn b�r ekki lengur me� svaranda@G
                        @/@/Anna�, hvert?"
                        "^haus@/^fsvar@/^strik@/
                        @G^brottfluttnafn b�r ekki lengur me� svaranda@G
                        @/@/Where?"
                        / "Anna� hvert" : array[2..15] of string[80]

        HmBrottM�n        "^haus@/^fsvar@/^strik@/
                        @G^brottfluttnafn b�r ekki lengur me� svaranda@G
                            @/@/� hva�a m�nu�i flutti ^hm_txt_2
                            @/@GEkki lesa upp valkosti@G"
                           "^haus@/^fsvar@/^strik@/
                        @G^brottfluttnafn b�r ekki lengur me� svaranda@G
                            @/@/Which month did ^nafn_brottflutts years old, move out of the household?
                            @/@GEkki lesa upp valkosti@G"
                            / "� hva�a m�nu�i"
                            : array[2..15] of TM�nu�ir

        HmBrottM�nGisk     "^haus@/^fsvar@/^strik@/
                        @G^brottfluttnafn b�r ekki lengur me� svaranda@G
                            @/@/En ef �� �ttir a� segja ��na bestu �giskun. � hva�a m�nu�i heldur �� a� ^hm_txt_3
                            @/@REkki lesa upp valkosti@R"
                           "^haus@/^fsvar@/^strik@/
                        @G^brottfluttnafn b�r ekki lengur me� svaranda@G
                            @/@/But if you had to give your best guess. Which month do you think ^nafn_brottflutts years old, moved?
                            @/@REkki lesa upp valkosti@R"
                            / "� hva�a m�nu�i, �giskun"
                            : array[2..15] of TM�nu�ir

       HmBrott�r            "^haus@/^fsvar@/^strik@/
                        @G^brottfluttnafn b�r ekki lengur me� svaranda@G
                            @/@/Hva�a �r ^hm_txt_2"
                            "^haus@/^fsvar@/^strik@/
                        @G^brottfluttnafn b�r ekki lengur me� svaranda@G
                            @/@/Which year?"
                             / "Hva�a �r flutt"
                             : array[2..15] of T�rtal50

       HmBrottStarf          "^haus@/^fsvar@/^strik@/
                        @G^brottfluttnafn b�r ekki lengur me� svaranda@G
                            @/@/Var ^nafn_brottflutts �ra, � vinnu, atvinnulaus, � eftirlaunum, � n�mi e�a eitthva� anna�?"
                             "^haus@/^fsvar@/^strik@/
                        @G^brottfluttnafn b�r ekki lengur me� svaranda@G
                            @/@/Was ^nafn_brottflutts years old, working, unemployed, in retirement, studying or something else?
                              "
                              / "Starf brottflutts"
                              : array[2..15] of
                              (
                                 �_vinnu      "� vinnu" "Working",
                                 atvinnulaus  "Atvinnulaus" "Unemployed",
                                 eftirlaun    "� eftirlaunum" "In retirement",
                                 �_n�mi       "� n�mi" "Studying",
                                 anna�        "Anna�" "Something else"
                              )

       HmBrottStarfAnna�     "^haus@/^fsvar@/^strik@/
                        @G^brottfluttnafn b�r ekki lengur me� svaranda@G
                            @/@/Anna�, hva� ?"
                             "^haus@/^fsvar@/^strik@/
                        @G^brottfluttnafn b�r ekki lengur me� svaranda@G
                            @/@/Something else, specify"
                              / "Anna� starf brottflutts"
                              : array[2..15] of string[80]


  AUXFIELDS
    heimNafn         : ARRAY [2..15] OF STRING[50]
    heimNafn_2       : ARRAY [2..15] OF STRING[50]
    �Fj              : THmFj
    Inngangur        : STRING
    Preamble         : STRING
    ��r, you         : string
    nafn_brottflutts : string
    hm_txt_1         : string
    hm_txt_2         : string
    hm_txt_3         : string
    brottfluttnafn   : string

  LOCALS
    fj           : INTEGER             {Fj�ldi �erirra sem er merkt vi� 'b�r ekki me� �essum' }
    chck         : INTEGER
    I            : INTEGER
    FJ1, FJ2     : STRING
    hina_heimilismennina, �eir, tengjast, members, they, are : string
    Ef_vi�_byrjum_�_�eim_fyrsta, Beginning_with_first : string
    F���r, aldur, �ld : integer


  RULES
    
    IF NOT (Pers�na IN [karl, kona]) THEN
      ��r := fornafn
      you := fornafn
    ELSE
      ��r := '��r'
      you := 'you'
    ENDIF
    
    �Fj := Fj�ldi + 1
    fsvar := ''
    IF Fj�ldi = 0 THEN
        IF Fj�ldiHeimili = 2 THEN
          hina_heimilismennina := 'hinn heimilismanninn'
          �eir := 'hann'
          members := 'member'
          they := 'he'
          are := 'is'
          tengjast := 'tengist'
          Ef_vi�_byrjum_�_�eim_fyrsta := '...'
          Beginning_with_first := '...'
        ELSE
          hina_heimilismennina := 'hina heimilismennina'
          �eir := '�eir'
          members := 'members'
          they := 'they'
          are  := 'are'
          tengjast := 'tengjast'
          Ef_vi�_byrjum_�_�eim_fyrsta := '@/Ef vi� byrjum � �eim fyrsta...'
          Beginning_with_first := '@/Beginning with first...'
        ENDIF
      {IF hmfj�ldi >1
      THEN HmMed endif}
      HmFj�ldi := Fj�ldiHeimili
    ELSE
      IF Fj�ldiHeimili = 2 THEN
        hina_heimilismennina := 'hinn heimilismanninn'
        �eir := 'hann'
        members := 'member'
        they := 'he'
        are := 'is'
        tengjast := 'tengist'
        Ef_vi�_byrjum_�_�eim_fyrsta := '...'
        Beginning_with_first := '...'
      ELSE
        hina_heimilismennina := 'hina heimilismennina'
        �eir := '�eir'
        members := 'members'
        they := 'they'
        are  := 'are'
        tengjast := 'tengjast'
        Ef_vi�_byrjum_�_�eim_fyrsta := '@/Ef vi� byrjum � �eim fyrsta...'
        Beginning_with_first := '@/Beginning with first...'
      ENDIF
      {IF hmfj�ldi >1
      THEN HmMed endif}
      FOR I := 2 TO 15 DO
        heimNafn[I] := Fj�lskylda.Heimilisma�ur[I].Nafn
        IF HeimNafn[I] > '' THEN
          heimNafn[I] := heimNafn[I] + ', ' + Str(Fj�lskylda.Heimilisma�ur[I].Aldur)
        ENDIF
      ENDDO
      FOR I := 2 TO 15 DO
        heimNafn_2[I] := Fj�lskylda.Heimilisma�ur[I].Nafn
        IF HeimNafn_2[I] > '' THEN
          heimNafn_2[I] := Fj�lskylda.Heimilisma�ur[I].Nafn
        ENDIF
      ENDDO
      if (HmFj�ldi = 1) then
        HmSkr� := [ENGINN]
      else
        HmSkr�
        check if Enginn in HmSkr� then HmSkr�.cardinal = 1 "Ef �� velur 'ENGINN' �� m� ekki merkja vi� a�ra kosti" endif
      endif
      IF ENGINN IN HmSkr� THEN
        if Fj�ldi = 1 then
          HmSkr� := [heim02]
        elseif Fj�ldi = 2 then
          HmSkr� := [heim02,heim03]
        elseif Fj�ldi = 3 then
          HmSkr� := [heim02,heim03,heim04]
        elseif Fj�ldi = 4 then
          HmSkr� := [heim02,heim03,heim04,heim05]
        elseif Fj�ldi = 5 then
          HmSkr� := [heim02,heim03,heim04,heim05,heim06]
        elseif Fj�ldi = 6 then
          HmSkr� := [heim02,heim03,heim04,heim05,heim06,heim07]
        elseif Fj�ldi = 7 then
          HmSkr� := [heim02,heim03,heim04,heim05,heim06,heim07,heim08]
        elseif Fj�ldi = 8 then
          HmSkr� := [heim02,heim03,heim04,heim05,heim06,heim07,heim08,heim09]
        elseif Fj�ldi = 9 then
          HmSkr� := [heim02,heim03,heim04,heim05,heim06,heim07,heim08,heim09,heim10]
        elseif Fj�ldi = 10 then
          HmSkr� := [heim02,heim03,heim04,heim05,heim06,heim07,heim08,heim09,heim10,heim11]
        elseif Fj�ldi = 11 then
          HmSkr� := [heim02,heim03,heim04,heim05,heim06,heim07,heim08,heim09,heim10,heim11,heim12]
        elseif Fj�ldi = 12 then
          HmSkr� := [heim02,heim03,heim04,heim05,heim06,heim07,heim08,heim09,heim10,heim11,heim12,heim13]
        elseif Fj�ldi = 13 then
          HmSkr� := [heim02,heim03,heim04,heim05,heim06,heim07,heim08,heim09,heim10,heim11,heim12,heim13,heim14]
        else {h�r �ttu menn ekki a� lenda, sett til vara}
          HmSkr� := [ENGINN]
        endif

        Fj := Fj�ldi
      ELSE
        Fj := HmSkr�.CARDINAL
      ENDIF
      FOR chck := 1 TO 14 DO
       IF HmSkr�[chck].ord > Fj�ldi + 1 {OR HmSkr�[chck].ord = 1} THEN
         HmSkr�[chck].ord > 1 AND HmSkr�[chck].ord <= Fj�ldi + 1 "�a� m� bara velja �� sem eru forskr��ir!"
       ENDIF
      ENDDO
      for chck := 2 to 15 do
        if (chck in HmSkr�) or ((HmFj�ldi = 1) and (heimNafn[chck] > '')) or ((ENGINN in HmSkr�) and (heimNafn[chck] > '')) then
          newpage
          nafn_brottflutts := heimNafn[chck]
          brottfluttnafn := heimNafn_2[chck]
          HmHvorFlutti [chck]
         IF HmHvorFlutti [chck]= svarandi
                then hm_txt_1 := 'B�r hann/h�n � �tl�ndum, � heimili innanlands, � stofnun e�a einhverjum ��rum sta�?'
                     hm_txt_2 := 'fluttir �� af heimilinu?'
                     hm_txt_3 := '�� hafir flutt?'
         endif
         if HmHvorFlutti [chck]= hinn then
                     hm_txt_1 := 'Flutti hann/h�n, til �tlanda, � anna� heimili innanlands, � stofnun e�a eitthvert anna�?'
                     hm_txt_2 := 'flutti hann/h�n, af heimilinu?'
                     hm_txt_3 := 'hann/h�n, hafi flutt?'
         ENDIF

         IF (HmHvorFlutti [chck] <> aldrei) AND (HmHvorFlutti [chck] <> latinn) then
            HmHvertFluttur[chck]
             if HmHvertFluttur[chck] = Anna� then HmHvertAnna�[chck] endif
             HmBrott�r[chck]
             check
             if (HmBrott�r[chck] = response) then HmBrott�r[chck] <= year(VidtalByrjarDags) "�r getur ekki veri� fram � t�mann" endif
             if (Fj�lskylda.Heimilisma�ur[chck].F���r = response) then
               Fj�lskylda.Heimilisma�ur[chck].Aldur := max(year(vi�mi�unardagur_aldurs) - Fj�lskylda.Heimilisma�ur[chck].F���r, 0)
             elseif (Fj�lskylda.Heimilisma�ur[chck].kennitala = response) then
               �ld := val(substring(Fj�lskylda.Heimilisma�ur[chck].kennitala,10,1))
               F���r := val(substring(Fj�lskylda.Heimilisma�ur[chck].kennitala,5,2))
               if �ld = 8 then
                 F���r := 1800 + F���r
               elseif �ld = 9 then
                 F���r := 1900 + F���r
               elseif �ld = 0 then
                 F���r := 2000 + F���r
               endif
               Fj�lskylda.Heimilisma�ur[chck].F���r := F���r
               Fj�lskylda.Heimilisma�ur[chck].Aldur := max(year(vi�mi�unardagur_aldurs) - F���r, 0)
             endif
             IF HmBrott�r[chck] > 2004 then
                HmBrottM�n[chck]
                    if HmBrottM�n[chck] = dk then HmBrottM�nGisk[chck] endif
             ENDIF
             if ((Fj�lskylda.Heimilisma�ur[chck].Aldur >= 16) and (Fj�lskylda.Heimilisma�ur[chck].Aldur <= 70)) then
               HmBrottStarf[chck]
             endif
             if HmBrottStarf[chck] = anna� then HmBrottStarfAnna�[chck] endif
         ENDIF
        endif
      enddo
      {Ef uppl�singar um fj�lda heimilismanna skv. fyrri spurningu og forskr�ningu stangast �}
      SIGNAL
      IF Fj�ldi - Fj >= Fj�ldiHeimili - 1 INVOLVING (HmFj.HeimFj, HmSkr�) "H�r g�ti veri� innsl�ttarvilla@/" THEN
        fj1 := Str(Fj�ldiHeimili)
        fj2 := Str(Fj�ldi - Fj + 1)
        Fj�ldi - Fj < Fj�ldiHeimili "Skv. �essu eru ^fj2 � heimili en skv. fyrri spurningu voru �a� ^fj1"
      ENDIF

      Fj�ldi�tstrika�raHeimilismanna := Fj
      {HmFj�ldi = fj�ldi forskr��ra + fj�ldi annarra heimilismanna}
{      IF Fj�ldi - Fj >= Fj�ldiHeimili - 1 THEN
         HmFj�ldi := Fj�ldi + 1
      ELSE
         HmFj�ldi := Fj�ldiHeimili - Fj
      ENDIF }
    ENDIF
  { LAYOUT
       AT HmSkr� INFOPANE adalskjartveirdalkar }

ENDBLOCK
