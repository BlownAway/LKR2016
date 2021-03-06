{   BlokkGD.inc
    SILC L�fskjararanns�kn Rut og Kristinn
    Rut og Kristinn (c) mars 2003 - �tg. 1.2
    Uppf�rt af �MM desember 2015
    ATH Or�alag DSkemur er mj�g sl�mt s�rstaklega � ensku, f�r �etta einhvern t�mann � QAS yfirfer�? �MM, des 2015
 }


EMBEDDED BLOCK BlokkGd "Skammur vinnut�mi og hlunnindi"
   PARAMETERS
      IMPORT AllarSpurningar : TJ�Nei
      IMPORT pers�na         : TPers�na
      IMPORT Tv�St�rf        : TJ�Nei
      IMPORT Vinnut�mi       : INTEGER
      
    FIELDS
       DSkemur (D01c)     {SILC spurning}
        "^haus@/^fsvar@/^strik@/
        N� starfar ^�� ekki � fullu starfi, hver er �st��a �ess? Er^tu..."
        "^haus@/^fsvar@/^strik@/
        Why ^do_you work less than 30 hours a week?"
        /"Skemur en 30 stundir"
        : (
        N�m                     "...� n�mi e�a �j�lfun?"
                                "^Are ^you a student or trainee?",
        Heilsufar               "Er �a� vegna veikinda e�a �rorku?"
                                "^Do_you have health problems?",
        VinnaB��stEkki          "B��st ^��r ekki meiri vinna?"
                                "There is no more work available?",
        VillEkkiMeir            "^Viltu ekki lengri vinnut�ma?"
                                "Don't want to work more?",
        ErFulltStarf            "L�tur ^�� � �ennan vinnut�ma sem fullt starf?"
                                "^Do_you consider this many working hours as full time?",
        Heimilisst�rf           "�arf^tu a� sinna heimilisst�rfum, b�rnum e�a ��rum heimilism�nnum?"
                                "Because of care responsibilities at home?",
        Anna�                   "E�a eru a�rar �st��ur?"
                                "Or for other reasons?")

      DSkemas
        "^haus@/^fsvar@/^strik@/
        Hva�a �st��ur eru �a�?"
        "^haus@/^fsvar@/^strik@/
        What reasons?"
        /"Skemur en 30 stundir": STRING[120]


      

      Dfullt (D02)
        "^haus@/^fsvar@/^strik@/
        N� vinnur ^�� minna en 35 stundir � viku, er �etta fullt starf?
        @/@/@GEf vi�komandi er � tveimur st�rfum er �tt vi� vinnut�mann samanlag�an � �eim b��um@G"
        "^haus@/^fsvar@/^strik@/
        Is this a full-time job?
        @/@/@GEf vi�komandi er � tveimur st�rfum er �tt vi� vinnut�mann samanlag�an � �eim b��um@G"
        /"Fullt starf"
        : TJ�Nei
        
      DFyrt_bill
        "^haus@/^fsvar@/^strik@/
        Er^tu me� b�l � vegum vinnuveitanda ^�_a�al_e�a_aukastarfi?"
        "^haus@/^fsvar@/^strik@/
        ^Do_you have access to a car owned by ^your employer for personal use?"
        /"Fyrirt�kjab�ll"
        : Tj�Nei
        
      DFyrt_billFridindi
        "^haus@/^fsvar@/^strik@/
         Fr��indi vegna b�ls er kostna�ur sem fyrirt�ki� grei�ir af b�lnum en ^�� hef�ir �urft a� bera sj�lf^ur ef ^�� v�ri^r eigandi b�lsins.
         D�mi um sl�k fr��indi eru tryggingar, vi�hald, vi�ger�ir og eldsneyti.
         @/Ef �� tekur saman �au fr��indi sem ^�� hefur vegna b�lsins, hversu mikils vir�i � peningum telur �� �au vera � m�nu�i?"
        "^haus@/^fsvar@/^strik@/
        How much money would you say the benefits, the use and the costs of running the car, would be worth to ^YouHimHer in a normal month?"
        /"Fyrirt�kjab�ll fr��indi"
        : 1000..200000

      DFyrt_billFridiniItrekun
        "^haus@/^fsvar@/^strik@/
           Eru fr��indi sem tengjast b�lnum minna vir�i en..."
        "^haus@/^fsvar@/^strik@/
          How much would you estimate the benefits are worth to ^you per month...."
         / "Fyrirt�kisb�ll, �trekun"
         : (
         minna_en_10     "...10 ��sund kr�nur � m�nu�i" "less than 10 thousand?",
         minna_en_20     "...l�gri en 20 ��sund" "less than 20 thousand?",
         minna_en_30     "...l�gri en 30 ��sund" "less than 30 thousand?",
         minna_en_40     "...l�gri en 40 ��sund" "less than 40 thousand?",
         minna_en_50     "...l�gri en 50 ��sund" "less than 50 thousand?",
         minna_en_100    "...l�gri en 100 ��sund" "less than 100 thousand?",
         meira_en_100    "e�a 100 ��sund kr�nur e�a h�rri" "Or 100 thousand or more?"
         )


         DHlunnindi
          "^haus@/^fsvar@/^strik@/
           @/Vinnutengd fr��indi n�tast starfsmanni en eru ekki beinar peningagrei�slur.
           Til d�mis fr�r e�a ni�urgreiddur matur, GSM s�mi e�a s�mreikningar, t�lva, ADSL tenging,
           v�rur e�a �j�nusta sem starfsmenn f� � s�rst�kum kj�rum.
           @/�
           @/Er^tu me� einhver vinnutengd fr��indi ^�_a�al_e�a_aukastarfi?"
        "^haus@/^fsvar@/^strik@/
          @/Job related benefits are goods which the employee benefits from but are not direct payments in cash.
          For example, free or subsidized meals, mobile phone or phone bill payed by employer, computer, internet connection, goods,
          products or service from the company the employees get for free or at a reduced price.
          @/�
          @/^do_you receive any job related benefits?"
        / "DHlunnindi"
        : TJ�Nei

        DHlunnindiPeninga
          "^haus@/^fsvar@/^strik@/
           Ef �� hugsar um sl�k vinnutengd fr��indi hversu mikils vir�i � peningum � m�nu�i telur �� a� �au s�u fyrir ^�ig?"
          "^haus@/^fsvar@/^strik@/
           If you think of such job related benefits ^you receive. How much in cash per month would you say it would be worth to ^YouHimHer?"
           / "Hlunnnidi vir�i"
           : 1..1000000

        DHlunnindiPeninga�treka
          "^haus@/^fsvar@/^strik@/
           Eru vinnutengd fr��indi minna vir�i en..."
          "^haus@/^fsvar@/^strik@/
           Is it ...?"
           / "Hlunnnidi vir�i, �treka"
           :
           (
           minna_en_5   "...5 ��sund kr�nur � m�nu�i" "less than 5 thousand?",
           minna_en_10  "... l�gri en 10 ��s" "less than 10 thousand?",
           minna_en_20  "... l�gri en 20 ��s" "less than 20 thousand?",
           minna_en_50  "... l�gra en 50 ��s" "less than 50 thousand?",
           minna_en_100 "... l�gra en 100 ��s" "less than 100 thousand?",
           meira_en_100 "e�a 100 ��sund kr�nur e�a h�rri ?" "or 100 thousand or more per month?"
           )

    AUXFIELDS
      �_a�al_e�a_aukastarfi : string
      
      ��        : (karl2p "��",kona2p "��",karl3p "hann",kona3p "h�n",�v�st3p "hann/h�n")
      �ig       : (karl2p "�ig",kona2p "�ig",karl3p "hann",kona3p "hana",�v�st3p "hann/hana")
      stu       : (karl2p "stu",kona2p "stu",karl3p " hann",kona3p " h�n",�v�st3p " hann/h�n")
      tu        : (karl2p "tu",kona2p "tu",karl3p " hann",kona3p " h�n",�v�st3p " hann/h�n")
      n         : (karl2p "n",kona2p " ",karl3p "n",kona3p " ", �v�st3p "/n")
      ur        : (karl2p "ur",kona2p " ",karl3p "ur",kona3p " ",�v�st3p "(ur)")
      do_you    : (karl2p "Do you",kona2p "Do you",karl3p "Does he",kona3p "Does she",�v�st3p "Does he/she")
      your      : (karl2p "your",kona2p "your",karl3p "his",kona3p "her",�v�st3p "his/her")
      you       : (karl2p "you",kona2p "you",karl3p "he",kona3p "she",�v�st3p "he/she")
      have      : (karl2p "have",kona2p "have",karl3p "has",kona3p "has",�v�st3p "has")
      are       : (karl2p "are",kona2p "are",karl3p "is",kona3p "is",�v�st3p "is")
      YouHimHer : (karl2p "you",kona2p "you",karl3p "him",kona3p "her",�v�st3p "him/her")
      ��r       : (karl2p "��r",kona2p "��r",karl3p "honum",kona3p "henni",�v�st3p "honum/henni")
      Viltu     : (karl2p "Viltu",kona2p "Viltu",karl3p "Vill hann",kona3p "Vill h�n",�v�st3p "Vill hann/h�n")
      r       : (karl2p "r",kona2p "r",karl3p " ",kona3p " ", �v�st3p " ")
      
    RULES
      ��:=pers�na.ord
      �ig:=pers�na.ord
      stu:=pers�na.ord
      tu:=pers�na.ord
      n:=pers�na.ord
      ur:=pers�na.ord
      do_you:=pers�na.ord
      your:=pers�na.ord
      you:=pers�na.ord
      have:=pers�na.ord
      are:=pers�na.ord
      YouHimHer:=pers�na.ord
      ��r:=pers�na.ord
      r:=pers�na.ord
      viltu:=pers�na.ord
      
      IF (AllarSpurningar = J�) THEN
        IF Tv�St�rf = J� THEN
          �_a�al_e�a_aukastarfi := '� a�al e�a aukastarfi'
        ELSE
          �_a�al_e�a_aukastarfi := ''
        ENDIF
        IF (Vinnut�mi < 35) THEN
        {ef samanlag�ur vinnut�mi er skemur en 35 t�mar � a� spyrja hvort starfi�/st�rfin jafngildi fullu starfi}
          DFullt
          IF DFullt = Nei THEN
            DSkemur
            IF DSkemur = Anna� THEN
              Dskemas
            ENDIF
          ENDIF
        ENDIF
      ENDIF
      
      {Einfalda� til a� for�ast v�san � breytur utan blokkarinnar}
      {Heildarvinnut�mi er n� reikna�ur � blokk D og fluttur inn � breytunar vinnut�mi. �MM, des 2015}
      DFyrt_bill
      if DFyrt_bill = j� then
        DFyrt_billFridindi
        if DFyrt_billFridindi = dk then
                DFyrt_billFridiniItrekun
        endif
      endif
      DHlunnindi
      if DHlunnindi = J� then
        DHlunnindiPeninga
        if DHlunnindiPeninga = dk then DHlunnindiPeninga�treka endif
      endif

ENDBLOCK
