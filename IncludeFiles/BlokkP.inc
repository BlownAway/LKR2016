{   BlokkP.inc
    Samfelld vinnumarka�sranns�kn
    �H (c) n�vember 2002
 }

EMBEDDED BLOCK BlokkP "Menntun"
  PARAMETERS
    {IMPORT fsv_menntun : STRING}
    IMPORT vi�mi�unardagur : DateType
    IMPORT pers�na : TPers�na
    IMPORT F���r : integer
    
  EMBEDDED BLOCK BFinnaMenntun
        FIELDS
            PHva�_b " @G�ttu � BILST�NGINA til a� f� vi�eigandi menntunarflokka@G
                       @/@/Veri� er a� leita a� r�ttu sk�lastigi og n�msgrein.
                       Ef �� finnur nokkrar svipa�ar n�msgreinar sem passa
                       skiptir ekki m�li hver er valin ef allar er � sama stigi og svi�i.@G": STRING[120]
            ROUTER leita ALIEN('LookupManager.msu','prc_menntunLookup')
        RULES
            PHva�_b 
    ENDBLOCK
    
  FIELDS
    FinnaMenntun : BFinnaMenntun 
    PSkylda (P01)
      "Hefur^�u loki� n�mi eftir skyldun�m?
      @/@/@G�tt er vi� �a� n�m sem var skyldun�m �egar vi�komandi var � sk�la@G"
      "H^ave_you completed studies after compulsory schooling?
      @/@/@G�tt er vi� �a� n�m sem var skyldun�m �egar vi�komandi var � sk�la@G"
      /"N�m eftir skyldun�m"
      : TJ�Nei
    PBarna (P02)
      "Hva�a sk�lastigi hefur^�u loki�?"
      "What level of schooling h^ave_you completed?"
      /"Loki� sk�lastig"
      : TBarnask�li
      
    PFrhn�m (P03)
      "Hva�a n�mi hefur^�u loki�?
      @/@/@GH�r er ekki veri� a� leita eftir n�verandi/yfirstandandi n�mi heldur �v� n�mi sem loki� er me� �tskrift.
      Ekki er �tt vi� n�mskei� e�a styttra n�m utans hins formlega sk�lakerfis eins og � spurningum h�r a� framan um n�mskei� og r��stefnur.@G"
     "Which education h^ave_you received?
      @/@/@GH�r er ekki veri� a� leita eftir n�verandi/yfirstandandi n�mi heldur �v� n�mi sem loki� er, heldur �a� n�m sem loki� er me� �tskrift.
      Ekki er �tt vi� n�mskei� e�a styttra n�m utans hins formlega sk�lakerfis eins og � spurningum h�r a� framan um n�mskei� og r��stefnur.@G"
       /"Loki� n�m"
      : TFrhMenntun

    PHva� (P04)
     "� hva�a grein hefur^�u loki� n�mi?"
     "Which field of education h^ave_you finished?"
     /"Svi� menntunar"
      : STRING[50]
    PK�ti (P04b)
     "@G�ttu � BILST�NGINA til a� f� vi�eigandi menntunarflokka@G"
     /"Pr�f sem loki� er"
      : TMenntun
    PMenntNr "Fastan�mer menntunar:" : INTEGER
    PMeist (P05)
      "Hefur^�u ��last meistarar�ttindi?"
      "H^ave_you acquired a master tradesman's papers?"
      /"Meistarar�ttindi"
      : TJ�Nei
    PMSK�li (P05b)
      "Lauk^stu n�mi �r meistarask�la?"
      "Did ^you complete studies at a master tradesmen's college?"
      /"Meistarask�li"
      : TJ�Nei
    PGr��a (P06)
      "Hva�a pr�fgr��u hefur^�u loki�?"
      "What examination or degree of studies h^ave_you completed?"
      /"Lokin pr�fgr��a"
      : TGr��a
      
    P�r (P07)
      "Hva�a �r lauk^stu �essu n�mi?"
      "What year did ^you complete this exam or degree?"
      /"�r loki� n�mi"
      : T�rtal

    P�r_gisk
      "En hva� heldur^�u a� ^�� hafi veri� ^ggamall?"
      "But how old do you think ^you was?"
      /"�r loki� n�mi �giskun"
      : 10..100

    PN�msk� (P08)
      "Hefur^�u loki� starfstengdum n�mskei�um sem voru 100 klukkustundir e�a lengri?
      @/@/@GH�r er einkum �tt vi� 100 klst. e�a lengri starfsr�ttindan�mskei� e�a til a� undirb�a undir starf@G"
      "H^ave_you completed any courses which grant job qualification?
      @/@/@GThis refers especially to job oriented courses 100 hours or more@G"
      /"Starfsr�ttindan�mskei�"
      : TJ�Nei
    PHva�a (P09)
      "Hva�a n�mskei�um?"
      "Which courses?"
      /"Hva�a n�mskei�"
      :String [80]

PISCED (P10)
      "Hvar mundir �� flokka menntun ^��na mi�a� vi� almenna sk�lakerfi� � �slandi?"
      "How would you classify ^your education relative to the general Icelandic schooling system?"
      /"Menntaflokkun"
      : TISCED 



  AUXFIELDS
    mK�ti : STRING

    �u   :(karl2p "�u",kona2p "�u",karl3p " hann",kona3p " h�n",�v�st3p " hann/h�n")
    ave_you: (karl2p "ave you",kona2p "ave you",karl3p "as he",kona3p "as she",�v�st3p "as he/she")
    stu  :(karl2p "stu",kona2p "stu",karl3p " hann",kona3p " h�n",�v�st3p " hann/h�n")
    you :  (karl2p "you",kona2p "you",karl3p "he",kona3p "she",�v�st3p "he/she")
    ��   : (karl2p "��",kona2p "��",karl3p "hann",kona3p "h�n",�v�st3p "hann/h�n")
    ggamall :  (karl2p "gamall",kona2p "g�mul",karl3p "gamall",kona3p "g�mul",�v�st3p "gamall")
    ��na :(karl2p "��na",kona2p "��na",karl3p "hans",kona3p "hennar",�v�st3p "hans/hennar")
    your : (karl2p "your",kona2p "your",karl3p "his",kona3p "her",�v�st3p "his/her")
    
  RULES
    �u := pers�na.ord
    ave_you := pers�na.ord
    stu := pers�na.ord
    you :=pers�na.ord
    �� :=pers�na.ord
    ggamall:=pers�na.ord
    ��na:=pers�na.ord
    your:=pers�na.ord
    
    
    PSkylda
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
      ENDIF {PBarna = Barnask�li}
      
    ELSE {PSkylda = J�,dk,rf}
      PFrhn�m

      IF PFrhN�m In [Framhaldspr�f, H�sk�lapr�f, Anna�Pr�f] THEN
        PHva�
        FinnaMenntun.leita
        {PK�ti|FinnaMenntun.LOOKUP(Tri:=(PHva�)).MenntunarK�ti
        mK�ti := ClassToStr(PK�ti)}
        PMenntNr.show
        mK�ti.show
        
        IF PFrhN�m = Framhaldspr�f OR Substring(mK�ti,1,3) = '3.3' THEN
          PMeist
          IF PMeist = J� THEN
            PMSK�li
          ENDIF
        ENDIF
      ENDIF {PFrhN�m In [Framhaldspr�f, H�sk�lapr�f, Anna�Pr�f]}
      
      IF PFrhN�m = H�sk�lapr�f OR Substring(mK�ti,1,1) = '5' THEN
         PGr��a
      ENDIF
      
      IF PFrhN�m = Gagnfr��apr�f THEN
        P�r := F���r + 17
      ELSEIF PFrhN�m <> REFUSAL THEN
        P�r
        IF P�r=RESPONSE THEN 
{UNLESS}  P�r >= 1000         "�ri� ver�ur a� vera 4 t�lustafir!"
{UNLESS} (P�r - F���r) >= 0   "Lauk n�mi fyrir f��ingu!"
{UNLESS} (P�r - F���r) >= 10  "Lauk n�m fyrir 10 �ra aldur!"
{UNLESS}  P�r <= Year(vi�mi�unardagur) "Ekki m� skr� �r fram � t�mann!"
        ENDIF 
        IF P�r = DONTKNOW THEN
            P�r_gisk 
        ENDIF
      ENDIF {PFrhN�m = Gagnfr��apr�f}
    ENDIF {PSkylda = Nei}
    
    IF PSkylda = Nei OR PFrhN�m = Gagnfr��apr�f THEN
      PN�msk�
      IF PN�msk� = J� THEN
        PHva�a
        ENDIF
    ENDIF
    IF PFrhN�m = DONTKNOW OR PK�ti = DONTKNOW OR Substring(mK�ti,1,1) = '9'
    THEN
        PISCED
    ENDIF

ENDBLOCK

