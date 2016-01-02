{   BlokkI.inc
    Samfelld vinnumarkaðsrannsókn
    ÓH (c) nóvember 2002
 }

EMBEDDED BLOCK BlokkI "Reynsla á vinnumarkaði"
    PARAMETERS
        {IMPORT fsv_status : Tfsv_status}
        {IMPORT AllarSpurningar : TJáNei}
        {IMPORT FæðÁr : integer}
        IMPORT Persóna : TPersóna
        {IMPORT Heimili : TJáNei }
        {TRANSIT Vinnandi : TJáNei}
        {EXPORT VinnandiSíðustuFjórarVikur  : TJáNei
        EXPORT HvenærHættur : DateType}
    AUXFIELDS
        VinnandiSíðustuFjórarVikur : Tjánei 
        HvenærHættur : DateType
        
         ggamall :  (karl2p "gamall",kona2p "gömul",karl3p "gamall",kona3p "gömul",óvíst3p "gamall")
         þú      : (karl2p "þú",kona2p "þú",karl3p "hann",kona3p "hún",óvíst3p "hann/hún")
         stu     : (karl2p "stu",kona2p "stu",karl3p " hann",kona3p " hún",óvíst3p " hann/hún")
         tu      : (karl2p "tu",kona2p "tu",karl3p " hann",kona3p " hún",óvíst3p " hann/hún")
         n       : (karl2p "n",kona2p " ",karl3p "n",kona3p " ", óvíst3p "/n")
         r       : (karl2p "r",kona2p "r",karl3p " ",kona3p " ", óvíst3p " ")
         ur      : (karl2p "ur",kona2p " ",karl3p "ur",kona3p " ", óvíst3p "ur")
         have    : (karl2p "have",kona2p "have",karl3p "has",kona3p "has", óvíst3p "has")
         you     : (karl2p "you",kona2p "you",karl3p "he",kona3p "she",óvíst3p "he/she")
         your    : (karl2p "your",kona2p "your",karl3p "his",kona3p "her",óvíst3p "his/her")
         doyou   : (karl2p "Do you",kona2p "Do you",karl3p "Does he",kona3p "Does she",óvíst3p "Does he/she")
         
    FIELDS
      IReynsla (I01)
        "^haus@/^fsvar@/^strik@/
        Með fastri vinnu er átt við starf sem ^þú hefur haft í að minnsta kosti 6 mánuði samfellt og unnið að minnsta kosti 15 klukkustundir á viku.
        @/Hefur ^þú einhvern tíman verið í fastri vinnu?"
        "^haus@/^fsvar@/^strik@/
        A regular job means that you have had a job for at least 6 months in a row and worked at least 15 hours a week.
        ^Have ^you ever had a regular job?"
        /"Verið á vinnumarkaði"
        : TJáNei

       Igamall
      "^haus@/^fsvar@/^strik@/
        Hvað var^stu ^ggamall þegar ^þú byrjaði^r fyrst í fastri vinnu?"
        "^haus@/^fsvar@/^strik@/
        How old were you when you first started a regular job?"
        /"Hve gamall"
        : 10..100

       Ifjoldar
      "^haus@/^fsvar@/^strik@/
        Hversu mörg ár samtals hefur ^þú verið í fastri vinnu?
         @/@/@gNámundið upp eða niður í næsta heila ár"
        "^haus@/^fsvar@/^strik@/
        How many years have you been in a regular job?
         @/@/@gNámundið upp eða niður í næsta heila ár"
        /"Hve mörg ár" : 0..100

      IÁr (I02)
        "^haus@/^fsvar@/^strik@/
        Hvaða ár var^stu síðast í vinnu?"
        "^haus@/^fsvar@/^strik@/
        Which year did ^you last work?"
        /"Ár síðast í vinnu"
        : Tártal150
      IMán (I03)
        "^haus@/^fsvar@/^strik@/
        Í hvaða mánuði?"
        "^haus@/^fsvar@/^strik@/
        Which month?"
        /"Mánuður síðast í vinnu"
        : Tmánuðir, EMPTY
      IDagur (I04)
        "^haus@/^fsvar@/^strik@/
        Hvað dag?"
        "^haus@/^fsvar@/^strik@/
        Which day?"
        /"Dagur síðast í vinnu"
        : 1..31, EMPTY
      IÁstæða (I05)
        "^haus@/^fsvar@/^strik@/
        Hver er aðalástæða þess að ^þú hætti^r í síðasta starfi?"
        "^haus@/^fsvar@/^strik@/
        What was the main reason ^you left ^your last job?"
        /"Ástæða hættir í starfi"
        : (
        Uppsögn                         "Var sagt upp starfi / fyrirtæki hætt rekstri"  "Made redundant",
        TímabundiðStarf                 "Var í tímabundnu starfi, þ.m.t. sumarstarf"    "Temporary job, including summer job",
        Verkefnaskortur                 "Vegna verkefnaskorts"                          "Lack of work to do in that job",
        Menntun                         "Fór í skóla"                                   "Went to school",
        Fæðingarorlof                   "Vegna fæðingarorlofs / meðgöngu"               "Maternity/paternity leave or pregnancy",
        SinnaBörnum                     "Til að sinna börnum eða fjölskyldumeðlimum"    "To look after children or other dependent family member",
        Eftirlaun                       "Fór á eftirlaun"                               "Retired",
        Veikindi                        "Vegna eigin veikinda eða fötlunar/örorku"      "Own illness or disability",
        Annað                           "Annað"                                         "Other")
      IRáðin (I06)
        "^haus@/^fsvar@/^strik@/
        Er^tu enn ráðin^n í þetta starf?"
        "^haus@/^fsvar@/^strik@/
        ^Doyou still hold that job?"
        /"Ennþá ráðinn"
        : TJáNei

    AUXFIELDS
      tími  : DateType
      

    LOCALS
      ár    : integer[4]
      mán   : integer[2]
      dagur : integer[2]


    RULES
      ggamall := persóna.ord
      þú:=persóna.ord
      stu:=persóna.ord
      tu:=persóna.ord
      r:=persóna.ord
      ur:=persóna.ord
      n:=persóna.ord
      have:=persóna.ord
      you:=persóna.ord
      doyou:=persóna.ord
      your:=persóna.ord
      
      IReynsla
      IF IReynsla = Já THEN
         Igamall
         Ifjoldar
       ENDIF

      IF IReynsla = Nei THEN
         VinnandiSíðustuFjórarVikur := Nei
         HvenærHættur := viðmiðunardagur - (9,0,0)
      ELSE
         IF tími <> EMPTY THEN
           IF tími + (0,0,28) <  viðmiðunardagur THEN
             VinnandiSíðustuFjórarVikur := Nei
           ELSE
             VinnandiSíðustuFjórarVikur := Já
           ENDIF
           HvenærHættur := Tími
         ELSE
           VinnandiSíðustuFjórarVikur := Nei
           HvenærHættur := viðmiðunardagur - (9,0,0)
         ENDIF
      ENDIF
 ENDBLOCK
