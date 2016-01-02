{   BlokkGD.inc
    SILC Lífskjararannsókn Rut og Kristinn
    Rut og Kristinn (c) mars 2003 - útg. 1.2
    Uppfært af ÞMM desember 2015
    ATH Orðalag DSkemur er mjög slæmt sérstaklega á ensku, fór þetta einhvern tímann í QAS yfirferð? ÞMM, des 2015
 }


EMBEDDED BLOCK BlokkGd "Skammur vinnutími og hlunnindi"
   PARAMETERS
      IMPORT AllarSpurningar : TJáNei
      IMPORT persóna         : TPersóna
      IMPORT TvöStörf        : TJáNei
      IMPORT Vinnutími       : INTEGER
      
    FIELDS
       DSkemur (D01c)     {SILC spurning}
        "^haus@/^fsvar@/^strik@/
        Nú starfar ^þú ekki í fullu starfi, hver er ástæða þess? Er^tu..."
        "^haus@/^fsvar@/^strik@/
        Why ^do_you work less than 30 hours a week?"
        /"Skemur en 30 stundir"
        : (
        Nám                     "...í námi eða þjálfun?"
                                "^Are ^you a student or trainee?",
        Heilsufar               "Er það vegna veikinda eða örorku?"
                                "^Do_you have health problems?",
        VinnaBýðstEkki          "Býðst ^þér ekki meiri vinna?"
                                "There is no more work available?",
        VillEkkiMeir            "^Viltu ekki lengri vinnutíma?"
                                "Don't want to work more?",
        ErFulltStarf            "Lítur ^þú á þennan vinnutíma sem fullt starf?"
                                "^Do_you consider this many working hours as full time?",
        Heimilisstörf           "Þarf^tu að sinna heimilisstörfum, börnum eða öðrum heimilismönnum?"
                                "Because of care responsibilities at home?",
        Annað                   "Eða eru aðrar ástæður?"
                                "Or for other reasons?")

      DSkemas
        "^haus@/^fsvar@/^strik@/
        Hvaða ástæður eru það?"
        "^haus@/^fsvar@/^strik@/
        What reasons?"
        /"Skemur en 30 stundir": STRING[120]


      

      Dfullt (D02)
        "^haus@/^fsvar@/^strik@/
        Nú vinnur ^þú minna en 35 stundir á viku, er þetta fullt starf?
        @/@/@GEf viðkomandi er í tveimur störfum er átt við vinnutímann samanlagðan í þeim báðum@G"
        "^haus@/^fsvar@/^strik@/
        Is this a full-time job?
        @/@/@GEf viðkomandi er í tveimur störfum er átt við vinnutímann samanlagðan í þeim báðum@G"
        /"Fullt starf"
        : TJáNei
        
      DFyrt_bill
        "^haus@/^fsvar@/^strik@/
        Er^tu með bíl á vegum vinnuveitanda ^í_aðal_eða_aukastarfi?"
        "^haus@/^fsvar@/^strik@/
        ^Do_you have access to a car owned by ^your employer for personal use?"
        /"Fyrirtækjabíll"
        : TjáNei
        
      DFyrt_billFridindi
        "^haus@/^fsvar@/^strik@/
         Fríðindi vegna bíls er kostnaður sem fyrirtækið greiðir af bílnum en ^þú hefðir þurft að bera sjálf^ur ef ^þú væri^r eigandi bílsins.
         Dæmi um slík fríðindi eru tryggingar, viðhald, viðgerðir og eldsneyti.
         @/Ef þú tekur saman þau fríðindi sem ^þú hefur vegna bílsins, hversu mikils virði í peningum telur þú þau vera á mánuði?"
        "^haus@/^fsvar@/^strik@/
        How much money would you say the benefits, the use and the costs of running the car, would be worth to ^YouHimHer in a normal month?"
        /"Fyrirtækjabíll fríðindi"
        : 1000..200000

      DFyrt_billFridiniItrekun
        "^haus@/^fsvar@/^strik@/
           Eru fríðindi sem tengjast bílnum minna virði en..."
        "^haus@/^fsvar@/^strik@/
          How much would you estimate the benefits are worth to ^you per month...."
         / "Fyrirtækisbíll, ítrekun"
         : (
         minna_en_10     "...10 þúsund krónur á mánuði" "less than 10 thousand?",
         minna_en_20     "...lægri en 20 þúsund" "less than 20 thousand?",
         minna_en_30     "...lægri en 30 þúsund" "less than 30 thousand?",
         minna_en_40     "...lægri en 40 þúsund" "less than 40 thousand?",
         minna_en_50     "...lægri en 50 þúsund" "less than 50 thousand?",
         minna_en_100    "...lægri en 100 þúsund" "less than 100 thousand?",
         meira_en_100    "eða 100 þúsund krónur eða hærri" "Or 100 thousand or more?"
         )


         DHlunnindi
          "^haus@/^fsvar@/^strik@/
           @/Vinnutengd fríðindi nýtast starfsmanni en eru ekki beinar peningagreiðslur.
           Til dæmis frír eða niðurgreiddur matur, GSM sími eða símreikningar, tölva, ADSL tenging,
           vörur eða þjónusta sem starfsmenn fá á sérstökum kjörum.
           @/·
           @/Er^tu með einhver vinnutengd fríðindi ^í_aðal_eða_aukastarfi?"
        "^haus@/^fsvar@/^strik@/
          @/Job related benefits are goods which the employee benefits from but are not direct payments in cash.
          For example, free or subsidized meals, mobile phone or phone bill payed by employer, computer, internet connection, goods,
          products or service from the company the employees get for free or at a reduced price.
          @/·
          @/^do_you receive any job related benefits?"
        / "DHlunnindi"
        : TJáNei

        DHlunnindiPeninga
          "^haus@/^fsvar@/^strik@/
           Ef þú hugsar um slík vinnutengd fríðindi hversu mikils virði í peningum á mánuði telur þú að þau séu fyrir ^þig?"
          "^haus@/^fsvar@/^strik@/
           If you think of such job related benefits ^you receive. How much in cash per month would you say it would be worth to ^YouHimHer?"
           / "Hlunnnidi virði"
           : 1..1000000

        DHlunnindiPeningaÍtreka
          "^haus@/^fsvar@/^strik@/
           Eru vinnutengd fríðindi minna virði en..."
          "^haus@/^fsvar@/^strik@/
           Is it ...?"
           / "Hlunnnidi virði, ítreka"
           :
           (
           minna_en_5   "...5 þúsund krónur á mánuði" "less than 5 thousand?",
           minna_en_10  "... lægri en 10 þús" "less than 10 thousand?",
           minna_en_20  "... lægri en 20 þús" "less than 20 thousand?",
           minna_en_50  "... lægra en 50 þús" "less than 50 thousand?",
           minna_en_100 "... lægra en 100 þús" "less than 100 thousand?",
           meira_en_100 "eða 100 þúsund krónur eða hærri ?" "or 100 thousand or more per month?"
           )

    AUXFIELDS
      í_aðal_eða_aukastarfi : string
      
      þú        : (karl2p "þú",kona2p "þú",karl3p "hann",kona3p "hún",óvíst3p "hann/hún")
      þig       : (karl2p "þig",kona2p "þig",karl3p "hann",kona3p "hana",óvíst3p "hann/hana")
      stu       : (karl2p "stu",kona2p "stu",karl3p " hann",kona3p " hún",óvíst3p " hann/hún")
      tu        : (karl2p "tu",kona2p "tu",karl3p " hann",kona3p " hún",óvíst3p " hann/hún")
      n         : (karl2p "n",kona2p " ",karl3p "n",kona3p " ", óvíst3p "/n")
      ur        : (karl2p "ur",kona2p " ",karl3p "ur",kona3p " ",óvíst3p "(ur)")
      do_you    : (karl2p "Do you",kona2p "Do you",karl3p "Does he",kona3p "Does she",óvíst3p "Does he/she")
      your      : (karl2p "your",kona2p "your",karl3p "his",kona3p "her",óvíst3p "his/her")
      you       : (karl2p "you",kona2p "you",karl3p "he",kona3p "she",óvíst3p "he/she")
      have      : (karl2p "have",kona2p "have",karl3p "has",kona3p "has",óvíst3p "has")
      are       : (karl2p "are",kona2p "are",karl3p "is",kona3p "is",óvíst3p "is")
      YouHimHer : (karl2p "you",kona2p "you",karl3p "him",kona3p "her",óvíst3p "him/her")
      þér       : (karl2p "þér",kona2p "þér",karl3p "honum",kona3p "henni",óvíst3p "honum/henni")
      Viltu     : (karl2p "Viltu",kona2p "Viltu",karl3p "Vill hann",kona3p "Vill hún",óvíst3p "Vill hann/hún")
      r       : (karl2p "r",kona2p "r",karl3p " ",kona3p " ", óvíst3p " ")
      
    RULES
      þú:=persóna.ord
      þig:=persóna.ord
      stu:=persóna.ord
      tu:=persóna.ord
      n:=persóna.ord
      ur:=persóna.ord
      do_you:=persóna.ord
      your:=persóna.ord
      you:=persóna.ord
      have:=persóna.ord
      are:=persóna.ord
      YouHimHer:=persóna.ord
      þér:=persóna.ord
      r:=persóna.ord
      viltu:=persóna.ord
      
      IF (AllarSpurningar = Já) THEN
        IF TvöStörf = Já THEN
          í_aðal_eða_aukastarfi := 'í aðal eða aukastarfi'
        ELSE
          í_aðal_eða_aukastarfi := ''
        ENDIF
        IF (Vinnutími < 35) THEN
        {ef samanlagður vinnutími er skemur en 35 tímar á að spyrja hvort starfið/störfin jafngildi fullu starfi}
          DFullt
          IF DFullt = Nei THEN
            DSkemur
            IF DSkemur = Annað THEN
              Dskemas
            ENDIF
          ENDIF
        ENDIF
      ENDIF
      
      {Einfaldað til að forðast vísan í breytur utan blokkarinnar}
      {Heildarvinnutími er nú reiknaður í blokk D og fluttur inn í breytunar vinnutími. ÞMM, des 2015}
      DFyrt_bill
      if DFyrt_bill = já then
        DFyrt_billFridindi
        if DFyrt_billFridindi = dk then
                DFyrt_billFridiniItrekun
        endif
      endif
      DHlunnindi
      if DHlunnindi = Já then
        DHlunnindiPeninga
        if DHlunnindiPeninga = dk then DHlunnindiPeningaÍtreka endif
      endif

ENDBLOCK
