{   BlokkP.inc
    Samfelld vinnumarkaðsrannsókn
    ÓH (c) nóvember 2002
 }

EMBEDDED BLOCK BlokkP "Menntun"
  PARAMETERS
    {IMPORT fsv_menntun : STRING}
    IMPORT viðmiðunardagur : DateType
    IMPORT persóna : TPersóna
    IMPORT FæðÁr : integer
    
  EMBEDDED BLOCK BFinnaMenntun
        FIELDS
            PHvað_b " @GÝttu á BILSTÖNGINA til að fá viðeigandi menntunarflokka@G
                       @/@/Verið er að leita að réttu skólastigi og námsgrein.
                       Ef þú finnur nokkrar svipaðar námsgreinar sem passa
                       skiptir ekki máli hver er valin ef allar er á sama stigi og sviði.@G": STRING[120]
            ROUTER leita ALIEN('LookupManager.msu','prc_menntunLookup')
        RULES
            PHvað_b 
    ENDBLOCK
    
  FIELDS
    FinnaMenntun : BFinnaMenntun 
    PSkylda (P01)
      "Hefur^ðu lokið námi eftir skyldunám?
      @/@/@GÁtt er við það nám sem var skyldunám þegar viðkomandi var í skóla@G"
      "H^ave_you completed studies after compulsory schooling?
      @/@/@GÁtt er við það nám sem var skyldunám þegar viðkomandi var í skóla@G"
      /"Nám eftir skyldunám"
      : TJáNei
    PBarna (P02)
      "Hvaða skólastigi hefur^ðu lokið?"
      "What level of schooling h^ave_you completed?"
      /"Lokið skólastig"
      : TBarnaskóli
      
    PFrhnám (P03)
      "Hvaða námi hefur^ðu lokið?
      @/@/@GHér er ekki verið að leita eftir núverandi/yfirstandandi námi heldur því námi sem lokið er með útskrift.
      Ekki er átt við námskeið eða styttra nám utans hins formlega skólakerfis eins og í spurningum hér að framan um námskeið og ráðstefnur.@G"
     "Which education h^ave_you received?
      @/@/@GHér er ekki verið að leita eftir núverandi/yfirstandandi námi heldur því námi sem lokið er, heldur það nám sem lokið er með útskrift.
      Ekki er átt við námskeið eða styttra nám utans hins formlega skólakerfis eins og í spurningum hér að framan um námskeið og ráðstefnur.@G"
       /"Lokið nám"
      : TFrhMenntun

    PHvað (P04)
     "Í hvaða grein hefur^ðu lokið námi?"
     "Which field of education h^ave_you finished?"
     /"Svið menntunar"
      : STRING[50]
    PKóti (P04b)
     "@GÝttu á BILSTÖNGINA til að fá viðeigandi menntunarflokka@G"
     /"Próf sem lokið er"
      : TMenntun
    PMenntNr "Fastanúmer menntunar:" : INTEGER
    PMeist (P05)
      "Hefur^ðu öðlast meistararéttindi?"
      "H^ave_you acquired a master tradesman's papers?"
      /"Meistararéttindi"
      : TJáNei
    PMSKóli (P05b)
      "Lauk^stu námi úr meistaraskóla?"
      "Did ^you complete studies at a master tradesmen's college?"
      /"Meistaraskóli"
      : TJáNei
    PGráða (P06)
      "Hvaða prófgráðu hefur^ðu lokið?"
      "What examination or degree of studies h^ave_you completed?"
      /"Lokin prófgráða"
      : TGráða
      
    PÁr (P07)
      "Hvaða ár lauk^stu þessu námi?"
      "What year did ^you complete this exam or degree?"
      /"Ár lokið námi"
      : TÁrtal

    PÁr_gisk
      "En hvað heldur^ðu að ^þú hafi verið ^ggamall?"
      "But how old do you think ^you was?"
      /"Ár lokið námi ágiskun"
      : 10..100

    PNámskð (P08)
      "Hefur^ðu lokið starfstengdum námskeiðum sem voru 100 klukkustundir eða lengri?
      @/@/@GHér er einkum átt við 100 klst. eða lengri starfsréttindanámskeið eða til að undirbúa undir starf@G"
      "H^ave_you completed any courses which grant job qualification?
      @/@/@GThis refers especially to job oriented courses 100 hours or more@G"
      /"Starfsréttindanámskeið"
      : TJáNei
    PHvaða (P09)
      "Hvaða námskeiðum?"
      "Which courses?"
      /"Hvaða námskeið"
      :String [80]

PISCED (P10)
      "Hvar mundir þú flokka menntun ^þína miðað við almenna skólakerfið á Íslandi?"
      "How would you classify ^your education relative to the general Icelandic schooling system?"
      /"Menntaflokkun"
      : TISCED 



  AUXFIELDS
    mKóti : STRING

    ðu   :(karl2p "ðu",kona2p "ðu",karl3p " hann",kona3p " hún",óvíst3p " hann/hún")
    ave_you: (karl2p "ave you",kona2p "ave you",karl3p "as he",kona3p "as she",óvíst3p "as he/she")
    stu  :(karl2p "stu",kona2p "stu",karl3p " hann",kona3p " hún",óvíst3p " hann/hún")
    you :  (karl2p "you",kona2p "you",karl3p "he",kona3p "she",óvíst3p "he/she")
    þú   : (karl2p "þú",kona2p "þú",karl3p "hann",kona3p "hún",óvíst3p "hann/hún")
    ggamall :  (karl2p "gamall",kona2p "gömul",karl3p "gamall",kona3p "gömul",óvíst3p "gamall")
    þína :(karl2p "þína",kona2p "þína",karl3p "hans",kona3p "hennar",óvíst3p "hans/hennar")
    your : (karl2p "your",kona2p "your",karl3p "his",kona3p "her",óvíst3p "his/her")
    
  RULES
    ðu := persóna.ord
    ave_you := persóna.ord
    stu := persóna.ord
    you :=persóna.ord
    þú :=persóna.ord
    ggamall:=persóna.ord
    þína:=persóna.ord
    your:=persóna.ord
    
    
    PSkylda
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
      ENDIF {PBarna = Barnaskóli}
      
    ELSE {PSkylda = Já,dk,rf}
      PFrhnám

      IF PFrhNám In [Framhaldspróf, Háskólapróf, AnnaðPróf] THEN
        PHvað
        FinnaMenntun.leita
        {PKóti|FinnaMenntun.LOOKUP(Tri:=(PHvað)).MenntunarKóti
        mKóti := ClassToStr(PKóti)}
        PMenntNr.show
        mKóti.show
        
        IF PFrhNám = Framhaldspróf OR Substring(mKóti,1,3) = '3.3' THEN
          PMeist
          IF PMeist = Já THEN
            PMSKóli
          ENDIF
        ENDIF
      ENDIF {PFrhNám In [Framhaldspróf, Háskólapróf, AnnaðPróf]}
      
      IF PFrhNám = Háskólapróf OR Substring(mKóti,1,1) = '5' THEN
         PGráða
      ENDIF
      
      IF PFrhNám = Gagnfræðapróf THEN
        PÁr := FæðÁr + 17
      ELSEIF PFrhNám <> REFUSAL THEN
        PÁr
        IF PÁr=RESPONSE THEN 
{UNLESS}  PÁr >= 1000         "Árið verður að vera 4 tölustafir!"
{UNLESS} (PÁr - FæðÁr) >= 0   "Lauk námi fyrir fæðingu!"
{UNLESS} (PÁr - FæðÁr) >= 10  "Lauk nám fyrir 10 ára aldur!"
{UNLESS}  PÁr <= Year(viðmiðunardagur) "Ekki má skrá ár fram í tímann!"
        ENDIF 
        IF PÁr = DONTKNOW THEN
            PÁr_gisk 
        ENDIF
      ENDIF {PFrhNám = Gagnfræðapróf}
    ENDIF {PSkylda = Nei}
    
    IF PSkylda = Nei OR PFrhNám = Gagnfræðapróf THEN
      PNámskð
      IF PNámskð = Já THEN
        PHvaða
        ENDIF
    ENDIF
    IF PFrhNám = DONTKNOW OR PKóti = DONTKNOW OR Substring(mKóti,1,1) = '9'
    THEN
        PISCED
    ENDIF

ENDBLOCK

