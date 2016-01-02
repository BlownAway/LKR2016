{   BlokkP.inc
    Samfelld vinnumarkaðsrannsókn
    ÓH (c) nóvember 2002
 }

EMBEDDED BLOCK BlokkP "Menntun"
  PARAMETERS
    {IMPORT fsv_menntun : STRING}
    IMPORT viðmiðunardagur : DateType
    import FæðÁr : integer

  EXTERNALS
    FinnaMenntun : MENNTUN ('Menntun\MENNTUN')

  FIELDS
    PSkylda (P01)
      "^haus@/^fsvar@/^strik@/
      Hefur^ðu lokið námi eftir skyldunám?
      @/@/@GÁtt er við það nám sem var skyldunám þegar viðkomandi var í skóla@G"
      "^haus@/^fsvar@/^strik@/
      ^Have ^you completed studies after compulsory schooling?
      @/@/@GÁtt er við það nám sem var skyldunám þegar viðkomandi var í skóla@G"
      /"Nám eftir skyldunám"
      : TJáNei
    PBarna (P02)
      "^haus@/^fsvar@/^strik@/
      Hvaða skólastigi hefur^ðu lokið?"
      "^haus@/^fsvar@/^strik@/
      What level of schooling ^have ^you completed?"
      /"Lokið skólastig"
      : (
      Ekkert                          "< 12 ára. Engu eða yngra en 12 ára"  "<12 years. None or younger than 12",
      Barnaskóli                      "12-13 ára. Barnaskólapróf"           "12-13 years old",
      Unglingaskóli                   "14-15 ára. Unglingapróf"             "14-15 years old",
      Miðskóli                        "15-16 ára. Miðskólapróf / landspróf" "15-16 years old. Old school leaving certificate",
      Grunnskóli                      "15-16 ára. Grunnskólapróf"           "15-16 years old. Basic school certificate",
      Gagnfræðaskóli                  "16-17 ára. Gagnfræðapróf"            "16-17 years old. Old secondary school certificate",
      StuttFramhald                   "17+ ára. Amk ein önn í framhaldsskóla eða verknámi"
                                      "17- years. At least one term in secondary or vocational school")
    PFrhnám (P03)
      "^haus@/^fsvar@/^strik@/
      Hvaða námi hefur^ðu lokið?
      @/@/@GHér er ekki verið að leita eftir núverandi/yfirstandandi námi heldur því námi sem lokið er með útskrift.
      Ekki er átt við námskeið eða styttra nám utans hins formlega skólakerfis eins og í spurningum hér að framan um námskeið og ráðstefnur.@G"
     "^haus@/^fsvar@/^strik@/
       Which education ^have ^you received?
      @/@/@GHér er ekki verið að leita eftir núverandi/yfirstandandi námi heldur því námi sem lokið er, heldur það nám sem lokið er með útskrift.
      Ekki er átt við námskeið eða styttra nám utans hins formlega skólakerfis eins og í spurningum hér að framan um námskeið og ráðstefnur.@G"
       /"Lokið nám"
      : (
      Gagnfræðapróf                   "Gagnfræðapróf"                                                              "16-17 years old. Old secondary school certificate",
      Framhaldspróf                   "Framhaldsmenntun, iðn- eða starfsmenntun  sem er ekki á háskólastigi"       "Secondary school, vocational school (not university level)",
      Stúdentspróf                    "Stúdentspróf"                                                               "University entrant certificate",
      Háskólapróf                     "Háskólamenntun"                                                             "University degree",
      AnnaðPróf                       "Önnur menntun"                                                              "Other")

    PHvað (P04)
     "^haus@/^fsvar@/^strik@/
       Í hvaða grein hefur^ðu lokið námi?"
     "^haus@/^fsvar@/^strik@/
       Which field of education ^have ^you finished?"
     /"Svið menntunar"
      : STRING[50]
    PKóti (P04b)
     "^haus@/^fsvar@/^strik@/
       @GÝttu á BILSTÖNGINA til að fá viðeigandi menntunarflokka@G"
     /"Próf sem lokið er"
      : TMenntun
    PMeist (P05)
      "^haus@/^fsvar@/^strik@/
      Hefur^ðu öðlast meistararéttindi?"
      "^haus@/^fsvar@/^strik@/
      ^Have ^you acquired a master tradesman's papers?"
      /"Meistararéttindi"
      : TJáNei
    PMSKóli (P05b)
      "^haus@/^fsvar@/^strik@/
      Lauk^stu námi úr meistaraskóla?"
      "^haus@/^fsvar@/^strik@/
      Did ^you complete studies at a master tradesmen's college?"
      /"Meistaraskóli"
      : TJáNei
    PGráða (P06)
      "^haus@/^fsvar@/^strik@/
      Hvaða prófgráðu hefur^ðu lokið?"
      "^haus@/^fsvar@/^strik@/
      What examination or degree of studies ^have ^you completed?"
      /"Lokin prófgráða"
      : (
      MinnaEnBA                       "Minna en BA eða sambærilegt nám án gráðu"    "Less than BA or comparable without a degree",
      StuttHagnýtt                    "Stutt hagnýtt nám úr háskóla"            "Short 1 - 1½ years diploma",
      BA                              "BA, BS, Bed eða sambærilegt"             "BA, BSc, BEd or comporable",
      Kandidat                        "Kandidats- eða embættispróf"               "Candiate's examination",
      Master                          "Masterspróf eða sambærilegt"             "Masters degree or comparable",
      Doktor                          "Doktorspróf eða sambærilegt"             "Doctorate or comparable")
    PÁr (P07)
      "^haus@/^fsvar@/^strik@/
      Hvaða ár lauk^stu þessu námi?"
      "^haus@/^fsvar@/^strik@/
      What year did ^you complete this exam or degree?"
      /"Ár lokið námi"
      : TÁrtal

    PÁr_gisk
      "^haus@/^fsvar@/^strik@/
      En hvað heldurðu að ^þú hafi verið ^ggamall?"
      "^haus@/^fsvar@/^strik@/
      But how old do you think ^you was?"
      /"Ár lokið námi ágiskun"
      : 10..100

    PNámskð (P08)
      "^haus@/^fsvar@/^strik@/
      Hefur^ðu lokið starfstengdum námskeiðum sem voru 100 klukkustundir eða lengri?
      @/@/@GHér er einkum átt við 100 klst. eða lengri starfsréttindanámskeið eða til að undirbúa undir starf@G"
      "^haus@/^fsvar@/^strik@/
      ^Have ^you completed any courses which grant job qualification?
      @/@/@GThis refers especially to job oriented courses 100 hours or more@G"
      /"Starfsréttindanámskeið"
      : TJáNei
    PHvaða (P09)
      "^haus@/^fsvar@/^strik@/
      Hvaða námskeiðum?"
      "^haus@/^fsvar@/^strik@/
      Which courses?"
      /"Hvaða námskeið"
      :String [80]
      
PISCED (P10)
      "^haus@/^fsvar@/^strik@/
      Hvar mundir þú flokka menntun ^þína miðað við almenna skólakerfið á Íslandi?"
      "^haus@/^fsvar@/^strik@/
      How would you classify ^your education relative to the general Icelandic schooling system?"
      /"Menntaflokkun"
      : (
       Engin                        (1)   "Engin formleg menntun"
                                     "No formal education",
      Fullnaðarpróf                (2)  "Fullnaðarpróf (barnaskólapróf)"
                                      "Old school leaving certificate (age 12 years)",
      Unglingapróf                 (3)   "Unglingapróf"
                                      "Old school leaving certificate (age 14 years)",
      Grunnskólapróf               (4)   "Grunnskólapróf"
                                     "Basic school leaving certificate",
      Gagnfræðapróf                (5)   "Gagnfræðapróf"
                                      "16-17 years old. Old secondary school certificate",
      StuttStarfsnám               (6)   "Eins til tveggja ára starfsnám"
                                      "1-2 years' vocational training",
      MilliStarfsnám               (15)   "Tveggja til þriggja ára starfsnám"
                                      "2-3 years' vocational training",
      LangtStarfsnám               (7)   "Þriggja ára eða lengra starfsnám"
                                     "3 years' or longer vocational training",
      LöngAlmenn                   (8)   "Þriggja ára almenn menntun úr framhaldsskóla"
                                      "3 years' general secondary education",
      Millistig                    (9)   "Eins til tveggja ára menntun eftir framhaldsskóla"
                                      "1-2 years' education after secondary level",
      StuttHagnýtt                 (10)   "Stutt hagnýtt nám á háskólastigi"
                                      "Short 1 - 1½ years diploma course at university level",
      StarfHáskóli                 (11)   "Starfsnám á háskólastigi"
                                      "Vocational training at university level",
      GrunnHáskóla                 (12)   "Grunnnám (1. gráða, td. BA) í háskóla"
                                      "First university degree (e.g. BA)",
      FramhHáskóla                 (13)   "Framhaldspróf (2. gráða, td. MA) í háskóla"
                                      "Second university degree (e.g. MA)",
      Doktor                       (14)   "Doktorspróf"
                                      "Doctorate")



  AUXFIELDS
    mKóti : STRING

  RULES

    {IF fsv_menntun = '' THEN}
      PSkylda
{    ENDIF}
    IF PSkylda = Nei THEN
      PBarna
      IF PBarna = Barnaskóli THEN
        PÁr := FæðÁr + 13
      ELSEIF PBarna = Unglingaskóli THEN
        PÁr := FæðÁr + 15
      ELSEIF PBarna IN [Miðskóli, Grunnskóli, StuttFramhald] THEN
        PÁr := FæðÁr + 16
      ELSEIF PBarna = Gagnfræðaskóli THEN
        PÁr := FæðÁr + 17
      ENDIF {PBarna = Barnaskóli THEN}
    ELSE {PSkylda = Nei THEN}
      PFrhnám
      IF PFrhNám In [Framhaldspróf, Háskólapróf, AnnaðPróf] THEN
        PHvað
        PKóti|FinnaMenntun.LOOKUP(Tri:=(PHvað)).MenntunarKóti
        mKóti := ClassToStr(PKóti)
        IF PFrhNám = Framhaldspróf OR Substring(mKóti,1,3) = '3.3' THEN
          PMeist
          IF PMeist = Já THEN PMSKóli ENDIF
        ENDIF
      ENDIF {PFrhNám In [Framhaldspróf, Háskólapróf, AnnaðPróf] THEN}
      IF PFrhNám = Háskólapróf OR Substring(mKóti,1,1) = '5' THEN PGráða ENDIF
      IF PFrhNám = Gagnfræðapróf THEN
        PÁr := FæðÁr + 17
      ELSEIF PFrhNám <> Refusal THEN
        PÁr
      ENDIF
      if PÁr = dk then PÁr_gisk endif
      IF PÁr = RESPONSE THEN
        {Hér þarf að koma Y2K tékk:   }
        IF PÁr < 1000 THEN
           PÁr >= 1000 "Árið verður að vera 4 tölustafir !"
        ENDIF
        IF (PÁr - FæðÁr)  < 0 THEN
          (PÁr - FæðÁr) >= 0 "Lauk námi áður en fæddist!"
        ELSEIF (PÁr - FæðÁr) < 10 THEN
          (PÁr - FæðÁr) >= 10 "Lauk fyrir 10 ára!"
        ENDIF
        IF PÁr > YEAR(viðmiðunardagur) THEN
          PÁr <= Year(viðmiðunardagur) "Ekki má skrá ár fram í tímann!"
        ENDIF
      ENDIF {PÁr = RESPONSE THEN}

    ENDIF {PSkylda = Nei THEN}
    IF PSkylda = Nei Or PFrhNám = Gagnfræðapróf THEN
      PNámskð
      IF PNámskð = Já THEN PHvaða ENDIF
      ENDIF     
      IF PFrhNám = DontKnow Or PKóti = DontKnow OR Substring(mKóti,1,1) = '9' THEN
        PISCED
    ENDIF

ENDBLOCK

