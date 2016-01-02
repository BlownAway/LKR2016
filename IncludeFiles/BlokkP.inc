{   BlokkP.inc
    Samfelld vinnumarka�sranns�kn
    �H (c) n�vember 2002
 }

EMBEDDED BLOCK BlokkP "Menntun"
  PARAMETERS
    {IMPORT fsv_menntun : STRING}
    IMPORT vi�mi�unardagur : DateType
    import F���r : integer

  EXTERNALS
    FinnaMenntun : MENNTUN ('Menntun\MENNTUN')

  FIELDS
    PSkylda (P01)
      "^haus@/^fsvar@/^strik@/
      Hefur^�u loki� n�mi eftir skyldun�m?
      @/@/@G�tt er vi� �a� n�m sem var skyldun�m �egar vi�komandi var � sk�la@G"
      "^haus@/^fsvar@/^strik@/
      ^Have ^you completed studies after compulsory schooling?
      @/@/@G�tt er vi� �a� n�m sem var skyldun�m �egar vi�komandi var � sk�la@G"
      /"N�m eftir skyldun�m"
      : TJ�Nei
    PBarna (P02)
      "^haus@/^fsvar@/^strik@/
      Hva�a sk�lastigi hefur^�u loki�?"
      "^haus@/^fsvar@/^strik@/
      What level of schooling ^have ^you completed?"
      /"Loki� sk�lastig"
      : (
      Ekkert                          "< 12 �ra. Engu e�a yngra en 12 �ra"  "<12 years. None or younger than 12",
      Barnask�li                      "12-13 �ra. Barnask�lapr�f"           "12-13 years old",
      Unglingask�li                   "14-15 �ra. Unglingapr�f"             "14-15 years old",
      Mi�sk�li                        "15-16 �ra. Mi�sk�lapr�f / landspr�f" "15-16 years old. Old school leaving certificate",
      Grunnsk�li                      "15-16 �ra. Grunnsk�lapr�f"           "15-16 years old. Basic school certificate",
      Gagnfr��ask�li                  "16-17 �ra. Gagnfr��apr�f"            "16-17 years old. Old secondary school certificate",
      StuttFramhald                   "17+ �ra. Amk ein �nn � framhaldssk�la e�a verkn�mi"
                                      "17- years. At least one term in secondary or vocational school")
    PFrhn�m (P03)
      "^haus@/^fsvar@/^strik@/
      Hva�a n�mi hefur^�u loki�?
      @/@/@GH�r er ekki veri� a� leita eftir n�verandi/yfirstandandi n�mi heldur �v� n�mi sem loki� er me� �tskrift.
      Ekki er �tt vi� n�mskei� e�a styttra n�m utans hins formlega sk�lakerfis eins og � spurningum h�r a� framan um n�mskei� og r��stefnur.@G"
     "^haus@/^fsvar@/^strik@/
       Which education ^have ^you received?
      @/@/@GH�r er ekki veri� a� leita eftir n�verandi/yfirstandandi n�mi heldur �v� n�mi sem loki� er, heldur �a� n�m sem loki� er me� �tskrift.
      Ekki er �tt vi� n�mskei� e�a styttra n�m utans hins formlega sk�lakerfis eins og � spurningum h�r a� framan um n�mskei� og r��stefnur.@G"
       /"Loki� n�m"
      : (
      Gagnfr��apr�f                   "Gagnfr��apr�f"                                                              "16-17 years old. Old secondary school certificate",
      Framhaldspr�f                   "Framhaldsmenntun, i�n- e�a starfsmenntun  sem er ekki � h�sk�lastigi"       "Secondary school, vocational school (not university level)",
      St�dentspr�f                    "St�dentspr�f"                                                               "University entrant certificate",
      H�sk�lapr�f                     "H�sk�lamenntun"                                                             "University degree",
      Anna�Pr�f                       "�nnur menntun"                                                              "Other")

    PHva� (P04)
     "^haus@/^fsvar@/^strik@/
       � hva�a grein hefur^�u loki� n�mi?"
     "^haus@/^fsvar@/^strik@/
       Which field of education ^have ^you finished?"
     /"Svi� menntunar"
      : STRING[50]
    PK�ti (P04b)
     "^haus@/^fsvar@/^strik@/
       @G�ttu � BILST�NGINA til a� f� vi�eigandi menntunarflokka@G"
     /"Pr�f sem loki� er"
      : TMenntun
    PMeist (P05)
      "^haus@/^fsvar@/^strik@/
      Hefur^�u ��last meistarar�ttindi?"
      "^haus@/^fsvar@/^strik@/
      ^Have ^you acquired a master tradesman's papers?"
      /"Meistarar�ttindi"
      : TJ�Nei
    PMSK�li (P05b)
      "^haus@/^fsvar@/^strik@/
      Lauk^stu n�mi �r meistarask�la?"
      "^haus@/^fsvar@/^strik@/
      Did ^you complete studies at a master tradesmen's college?"
      /"Meistarask�li"
      : TJ�Nei
    PGr��a (P06)
      "^haus@/^fsvar@/^strik@/
      Hva�a pr�fgr��u hefur^�u loki�?"
      "^haus@/^fsvar@/^strik@/
      What examination or degree of studies ^have ^you completed?"
      /"Lokin pr�fgr��a"
      : (
      MinnaEnBA                       "Minna en BA e�a samb�rilegt n�m �n gr��u"    "Less than BA or comparable without a degree",
      StuttHagn�tt                    "Stutt hagn�tt n�m �r h�sk�la"            "Short 1 - 1� years diploma",
      BA                              "BA, BS, Bed e�a samb�rilegt"             "BA, BSc, BEd or comporable",
      Kandidat                        "Kandidats- e�a emb�ttispr�f"               "Candiate's examination",
      Master                          "Masterspr�f e�a samb�rilegt"             "Masters degree or comparable",
      Doktor                          "Doktorspr�f e�a samb�rilegt"             "Doctorate or comparable")
    P�r (P07)
      "^haus@/^fsvar@/^strik@/
      Hva�a �r lauk^stu �essu n�mi?"
      "^haus@/^fsvar@/^strik@/
      What year did ^you complete this exam or degree?"
      /"�r loki� n�mi"
      : T�rtal

    P�r_gisk
      "^haus@/^fsvar@/^strik@/
      En hva� heldur�u a� ^�� hafi veri� ^ggamall?"
      "^haus@/^fsvar@/^strik@/
      But how old do you think ^you was?"
      /"�r loki� n�mi �giskun"
      : 10..100

    PN�msk� (P08)
      "^haus@/^fsvar@/^strik@/
      Hefur^�u loki� starfstengdum n�mskei�um sem voru 100 klukkustundir e�a lengri?
      @/@/@GH�r er einkum �tt vi� 100 klst. e�a lengri starfsr�ttindan�mskei� e�a til a� undirb�a undir starf@G"
      "^haus@/^fsvar@/^strik@/
      ^Have ^you completed any courses which grant job qualification?
      @/@/@GThis refers especially to job oriented courses 100 hours or more@G"
      /"Starfsr�ttindan�mskei�"
      : TJ�Nei
    PHva�a (P09)
      "^haus@/^fsvar@/^strik@/
      Hva�a n�mskei�um?"
      "^haus@/^fsvar@/^strik@/
      Which courses?"
      /"Hva�a n�mskei�"
      :String [80]
      
PISCED (P10)
      "^haus@/^fsvar@/^strik@/
      Hvar mundir �� flokka menntun ^��na mi�a� vi� almenna sk�lakerfi� � �slandi?"
      "^haus@/^fsvar@/^strik@/
      How would you classify ^your education relative to the general Icelandic schooling system?"
      /"Menntaflokkun"
      : (
       Engin                        (1)   "Engin formleg menntun"
                                     "No formal education",
      Fullna�arpr�f                (2)  "Fullna�arpr�f (barnask�lapr�f)"
                                      "Old school leaving certificate (age 12 years)",
      Unglingapr�f                 (3)   "Unglingapr�f"
                                      "Old school leaving certificate (age 14 years)",
      Grunnsk�lapr�f               (4)   "Grunnsk�lapr�f"
                                     "Basic school leaving certificate",
      Gagnfr��apr�f                (5)   "Gagnfr��apr�f"
                                      "16-17 years old. Old secondary school certificate",
      StuttStarfsn�m               (6)   "Eins til tveggja �ra starfsn�m"
                                      "1-2 years' vocational training",
      MilliStarfsn�m               (15)   "Tveggja til �riggja �ra starfsn�m"
                                      "2-3 years' vocational training",
      LangtStarfsn�m               (7)   "�riggja �ra e�a lengra starfsn�m"
                                     "3 years' or longer vocational training",
      L�ngAlmenn                   (8)   "�riggja �ra almenn menntun �r framhaldssk�la"
                                      "3 years' general secondary education",
      Millistig                    (9)   "Eins til tveggja �ra menntun eftir framhaldssk�la"
                                      "1-2 years' education after secondary level",
      StuttHagn�tt                 (10)   "Stutt hagn�tt n�m � h�sk�lastigi"
                                      "Short 1 - 1� years diploma course at university level",
      StarfH�sk�li                 (11)   "Starfsn�m � h�sk�lastigi"
                                      "Vocational training at university level",
      GrunnH�sk�la                 (12)   "Grunnn�m (1. gr��a, td. BA) � h�sk�la"
                                      "First university degree (e.g. BA)",
      FramhH�sk�la                 (13)   "Framhaldspr�f (2. gr��a, td. MA) � h�sk�la"
                                      "Second university degree (e.g. MA)",
      Doktor                       (14)   "Doktorspr�f"
                                      "Doctorate")



  AUXFIELDS
    mK�ti : STRING

  RULES

    {IF fsv_menntun = '' THEN}
      PSkylda
{    ENDIF}
    IF PSkylda = Nei THEN
      PBarna
      IF PBarna = Barnask�li THEN
        P�r := F���r + 13
      ELSEIF PBarna = Unglingask�li THEN
        P�r := F���r + 15
      ELSEIF PBarna IN [Mi�sk�li, Grunnsk�li, StuttFramhald] THEN
        P�r := F���r + 16
      ELSEIF PBarna = Gagnfr��ask�li THEN
        P�r := F���r + 17
      ENDIF {PBarna = Barnask�li THEN}
    ELSE {PSkylda = Nei THEN}
      PFrhn�m
      IF PFrhN�m In [Framhaldspr�f, H�sk�lapr�f, Anna�Pr�f] THEN
        PHva�
        PK�ti|FinnaMenntun.LOOKUP(Tri:=(PHva�)).MenntunarK�ti
        mK�ti := ClassToStr(PK�ti)
        IF PFrhN�m = Framhaldspr�f OR Substring(mK�ti,1,3) = '3.3' THEN
          PMeist
          IF PMeist = J� THEN PMSK�li ENDIF
        ENDIF
      ENDIF {PFrhN�m In [Framhaldspr�f, H�sk�lapr�f, Anna�Pr�f] THEN}
      IF PFrhN�m = H�sk�lapr�f OR Substring(mK�ti,1,1) = '5' THEN PGr��a ENDIF
      IF PFrhN�m = Gagnfr��apr�f THEN
        P�r := F���r + 17
      ELSEIF PFrhN�m <> Refusal THEN
        P�r
      ENDIF
      if P�r = dk then P�r_gisk endif
      IF P�r = RESPONSE THEN
        {H�r �arf a� koma Y2K t�kk:   }
        IF P�r < 1000 THEN
           P�r >= 1000 "�ri� ver�ur a� vera 4 t�lustafir !"
        ENDIF
        IF (P�r - F���r)  < 0 THEN
          (P�r - F���r) >= 0 "Lauk n�mi ��ur en f�ddist!"
        ELSEIF (P�r - F���r) < 10 THEN
          (P�r - F���r) >= 10 "Lauk fyrir 10 �ra!"
        ENDIF
        IF P�r > YEAR(vi�mi�unardagur) THEN
          P�r <= Year(vi�mi�unardagur) "Ekki m� skr� �r fram � t�mann!"
        ENDIF
      ENDIF {P�r = RESPONSE THEN}

    ENDIF {PSkylda = Nei THEN}
    IF PSkylda = Nei Or PFrhN�m = Gagnfr��apr�f THEN
      PN�msk�
      IF PN�msk� = J� THEN PHva�a ENDIF
      ENDIF     
      IF PFrhN�m = DontKnow Or PK�ti = DontKnow OR Substring(mK�ti,1,1) = '9' THEN
        PISCED
    ENDIF

ENDBLOCK
