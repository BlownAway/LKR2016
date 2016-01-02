{   BlokkB.inc SILC}

EMBEDDED BLOCK BlokkB "Starfslýsing"
    PARAMETERS
        IMPORT AllarSpurningar, Vinnandi : TJáNei
        IMPORT tvöStörf : TJáNei
        {IMPORT skyldulið : TJáNei}
        {EXPORT Status : TStatus
        EXPORT Fyrirtæki : String}

    EXTERNALS
      finnaÍstarf : ISTARF
      zveit       : SVEIT
      FinnaÍsat : isat2008
    AUXFIELDS
    Status : TStatus
    Fyrirtæki : String
    spurtUmFirma, spurtUmStarf : TJáNei
    {(karl2p,kona2p,karl3p,kona3p,óvíst3p)}
    þitt : (karl2p "þitt",kona2p "þitt",karl3p "hans",kona3p "hennar",óvíst3p "hans/hennar")
    your : (karl2p "your",kona2p "your",karl3p "his",kona3p "her",óvíst3p "his/her")
    tu   :(karl2p "tu",kona2p "tu",karl3p " hann",kona3p " hún",óvíst3p " hann/hún")
    stu  :(karl2p "stu",kona2p "stu",karl3p " hann",kona3p " hún",óvíst3p " hann/hún")
    Are_you:  (karl2p "Are you",kona2p "Are you",karl3p "Is he",kona3p "Is she",óvíst3p "Is he/she")
    you :  (karl2p "you",kona2p "you",karl3p "he",kona3p "she",óvíst3p "he/she")
    you_:  (karl2p "you",kona2p "you",karl3p "him",kona3p "her",óvíst3p "him/her")
    þú   : (karl2p "þú",kona2p "þú",karl3p "hann",kona3p "hún",óvíst3p "hann/hún")
    do_you : (karl2p "do you",kona2p "do you",karl3p "does he",kona3p "does she",óvíst3p "does he/she")
    þínum  : (karl2p "þínum",kona2p"þínum",karl3p"hans",kona3p "hennar",óvíst3p"hans/hennar")
    þín  : (karl2p "þín",kona2p"þín",karl3p"hans",kona3p "hennar",óvíst3p"hans/hennar")
    FIELDS
      BStatus (B01)
        "^haus@/^fsvar@/^strik@/
        ^EfTvöStörf
        Er^tu launþegi eða sjálfstætt starfandi ?
        @/@/@GSjálfstætt starfandi eru þeir sem reka fyrirtæki á eigin kennitölu eða í einkahlutafélagi sem þeir eða fjölskyldur
        þeirra eiga. Sömuleiðis þeir sem eiga í sameignarfélögum með öðrum, eins og lögfræðingar á lögfræðistofu.
        Þetta á þó ekki við nema fólk sé í lykilstöðum í fyrirtækinu, hér er ekki átt við ungt fólk sem vinnur hjá foreldrum sínum við afgreiðslu
        eða annars konar hjálp."
        "^haus@/^fsvar@/^strik@/
        ^IfTwoJobs
        ^Are_you a wage earner or self-employed?
        @/@/@GSjálfstætt starfandi eru þeir sem reka fyrirtæki á eigin kennitölu eða í einkahlutafélagi sem þeir eða fjölskyldan
        þeirra eiga að mestu eða öllu leyti. Sömuleiðis þeir sem eiga í sameignarfélögum með öðrum, eins og lögfræðingar á lögfræðistofu.
        Þetta á þó ekki við nema fólk sé í lykilstöðum í fyrirtækinu, hér er ekki átt við ungt fólk sem vinnur hjá foreldrum sínum við afgreiðslu
        eða annars konar hjálp. Forstjórar í hlutafélögum (athugið ekki einkahlutafélag) teljast launþegar, þó svo þeir eigi allt eða meirihluta hlutafjár. "
        /"Launþegi/sjálfstætt"
        : TStatus
      BSjStrf (B02)
        "^haus@/^fsvar@/^strik@/
        Var^stu með starfsmenn á launum í síðustu viku?"
         "^haus@/^fsvar@/^strik@/
        Did ^you have paid employees working for ^you_ ^last_week?"
        /"Launaðir starfsmenn"
        : TJáNei
      BFjLaun (B03)
        "^haus@/^fsvar@/^strik@/
        Hversu marga starfsmenn er^tu með á launum?"
        "^haus@/^fsvar@/^strik@/
        How many employees did ^you have working for ^you_?"
        /"Fjöldi starfsmanna"
        :1..1000

     BfjLaun_gisk
        "^haus@/^fsvar@/^strik@/
        Á hvaða bili er starfsmannafjöldinn?"
        "^haus@/^fsvar@/^strik@/
        Was it ..?"
        /"Fjöldi starfsmanna"
        : (
        til_10 "1-10 starfsmenn" "1-10 employees",
        til_19 "11-19 starfsmenn" "11-19 employees",
        til_29 "20-29 Starfsmenn" "20-29 employees",
        til_49 "30-49 starfsmenn" "30-49 employees",
        til_99 "50-99 Starfsmenn" "50-99 employees",
        til_199 "100-199 starfsmenn" "100-199 employees",
        til_499 "200-499 starfsmenn" "200-499 employees",
        fleiri  "500 starfsmenn eða fleiri" "500 employees or more"
       )

      BHvÁst (B04)
        "^haus@/^fsvar@/^strik@/
        Hver er staða ^þín?
        @/@/@GÞegar hingað er komið hefur líklega eitthvað komið upp á fyrr í spurningalistanum, þannig að þú myndir sennilega
        vilja @Ubakka héðan@U. Líkleg skýring er til dæmis að svarandi er í raun atvinnulaus, en merkt hefur verið við hann sem
        vinnandi áður. Hafðu einnig í huga að sjálfboðavinna telst ekki til launaðrar vinnu í spurningalistanum. @G"
        "^haus@/^fsvar@/^strik@/
        If neither, please give details?
        @/@/@GÞegar hingað er komið hefur líklega eitthvað komið upp á fyrr í spurningalistanum, þannig að þú myndir sennilega
        vilja @Ubakka héðan@U. Líkleg skýring er til dæmis að svarandi er í raun atvinnulaus, en merkt hefur verið við hann sem
        vinnandi áður. Hafðu einnig í huga að sjálfboðavinna telst ekki til launaðrar vinnu í spurningalistanum. @G"
        /"Hvorugt nánar"
        :String [50]
      BFirma (B06)
        "^haus@/^fsvar@/^strik@/
        Hjá hvaða fyrirtæki vinnur ^þú?
        @/@/@GEinungis er spurt um nafn fyrirtækis til að auðvelda atvinnugreinaflokkunina og er nafnið ekki notað til annarra hluta."
        "^haus@/^fsvar@/^strik@/
        Which company ^do_you work for?
        @/@/@GEinungis er spurt um nafn fyrirtækis til að auðvelda atvinnugreinaflokkunina og er nafnið ekki notað til annarra hluta."
        /"Hvaða fyrirtæki"
        :String [50]
      BEiga (B06a)
       "^haus@/^fsvar@/^strik@/
        Er fyrirtækið í eigu einhvers á heimilinu?
        @/@/@GEf spyrill veit að fyrirtækið er ríkisstofnun, hlutafélag, sjálfseignarstofnun eða viss um að enginn á heimilinu
        eig það má sleppa að spyrja þessarar spurningar og svara nei"
        "^haus@/^fsvar@/^strik@/
        Is the company owned by someone at the home?"
        /"Eigandi fyrirtækisins"
        :TJáNei
      BIðja (B07)
        "^haus@/^fsvar@/^strik@/
        Hver er starfsemi fyrirtækisins aðallega?
        @/@/@GEf fyrirtækið er á mörgum stöðum miðið þá við vinnustað svaranda.
        @/Vinnustaður er öll starfsemin á lóðinni, ekki bara deild viðkomandi@G"
        "^haus@/^fsvar@/^strik@/
        What is the company's main activity?
        @/@/@GIf ther is more than one workplace, refer to the respondent´s workplace
        @/Workplace means all activity on the site, not just the department@G"
        /"Aðalstarfsemi"
        :String [80]
      BAKóti2008 (B07b)
        "^haus@/^fsvar@/^strik@/
        @GFlettu upp viðeigandi kóta með því að ýta á BILSTÖNGINA@G"
        /"Atvinnugreinakóti"
        : TIsat2008 {, nodontknow }
      BFjStm1 (B08)
         "^haus@/^fsvar@/^strik@/
         Hversu margir starfa á vinnustað ^þínum?
         @/@/@GVinnustaður er allt fyrirtækið ef það er á einum stað annars skal miða við rekstrareininguna.
         Landsbanka starfsmaður á Raufarhöfn telur hins vegar fjölda starfsmanna í sínu útibúi@G.
         @/@/@GMuna ctrl + V ef viðkomandi veit ekki fjöldann og þá kemur spurning um á hvaða bili starfsmannafjöldinn er@G"
         "^haus@/^fsvar@/^strik@/
         How many people work at ^your workplace?
         @/@/@GVinnustaður er allt fyrirtækið ef það er á einum stað annars skal miða við rekstrareininguna.
         Dæmi: Hagstofan var starfrækt í tveimur húsum en á sama svæði og teljast því starfsmenn í báðum húsum til
         fjölda starfsmanna á vinnustað. Landsbanka starfsmaður á Raufarhöfn telur hins vegar fjölda starfsmanna í sínu útibúi@G.
         @/@/@GMuna ctrl + V ef viðkomandi veit ekki fjöldann og þá kemur spurning um á hvaða bili starfsmannafjöldinn er@G"
         /"Fjöldi á vinnustað"
         : 1..9999
      BFjStm2 (B08b)
         "^haus@/^fsvar@/^strik@/
         Á hvaða bili er starfsmannafjöldinn. Er hann..."
         "Choose the appropriate range for number of employees?"
         /"Fjöldi starfsmanna (bil)"
         : (M1      "··1 - ·10 starfsmenn"     "··1 - ·10 employees",
            M2      "·11 - ·19 starfsmenn"     "·11 - ·19 employees",
            M20      "·20 - ·49 starfsmenn"     "·20 - ·49 employees",
            M50      "·50 eða fleiri"           "·50 or more")
      BStarf (B09)
        "^haus@/^fsvar@/^strik@/
        Hvert er starfsheiti ^þitt?
        @/@/@GVið starfaflokkun skiptir miklu máli að fá fram nákvæmt starfsheiti.
        Dæmi: umönnun aldraðra en ekki bara umönnun, kynningarfulltrúi en ekki bara fulltrúi, háseti á línubát en ekki bara sjómaður.@G"
        "^haus@/^fsvar@/^strik@/
         What is ^your job title?
        @/@/@GPrecise job title, for example: caring for the elderly (not just healthcare), PR representative ( not jus representative),
        first mate on longliner (not just seaman)@G"
         /"Starfsheiti"
        :String [80]
      BSKóti
        "^haus@/^fsvar@/^strik@/
        @GFlettu upp viðeigandi kóta með því að ýta á BILSTÖNGINA@G"
        /"Starfakóti"
        : TIstarf
      BStLys (B10)
        "^haus@/^fsvar@/^strik@/
        Hver eru helstu verkefnin?
        @/@/@GHelstu verkefni í starfi eru grundvöllur starfaflokkunarinnar. Rafeindavirki getur sinnt mjög
        ólíkum störfum og starfsheitið eitt og sér dugar ekki til við starfaflokkunina.  Helstu verkefni
        rafeindavirkja getur til dæmis verið sala og ráðgjöf á tölvubúnaði til fyrirtækja og segir því
        starfsheitið eitt og sér takmarkaða sögu."
        "^haus@/^fsvar@/^strik@/
        What are the main tasks in this job?
        @/@/@GHelstu verkefni í starfi eru grundvöllur starfaflokkunarinnar. Rafeindavirki getur sinnt mjög
        ólíkum störfum og starfsheitið eitt og sér dugar ekki til við starfaflokkunina.  Helstu verkefni
        rafeindavirkja getur til dæmis verið sala og ráðgjöf á tölvubúnaði til fyrirtækja og segir því
        starfsheitið eitt og sér takmarkaða sögu."
        /"Verkefni"
        :String [80]
     BVrkStj (B11)
        "^haus@/^fsvar@/^strik@/
        Skipuleggur ^þú eða stjórnar verkum annarra starfsmanna, venjulega, stundum eða aldrei?
        @/@/@GHér er átt við þá sem bera formlega ábyrgð á verkum annarra starfsmanna og skipuleggja verk þeirra.
        Stjórnun þarf þó ekki að vera eina verksvið viðkomandi, dæmi skipstjóri á línubát sinnir almennum störfum
        á bátnum samhliða stjórnun á mannskap og tækjum. Starfsheiti geta þó verið misvísandi.  Dæmi: auglýsingastjóri
        sem ekki stýrir öðrum starfsmönnum innan fyrirtækisins ber ekki slíka ábyrgð."
         "^haus@/^fsvar@/^strik@/
        ^Do_you organize or manage other peoples work, usually, sometimes or never?
        @/@/@GHér er átt við þá sem bera formlega ábyrgð á verkum annarra starfsmanna og skipuleggja verk þeirra.
        Stjórnun þarf þó ekki að vera eina verksvið viðkomandi, dæmi skipstjóri á línubát sinnir almennum störfum
        á bátnum samhliða stjórnun á mannskap og tækjum. Starfsheiti geta þó verið misvísandi.  Dæmi: auglýsingastjóri
        sem ekki stýrir öðrum starfsmönnum innan fyrirtækisins ber ekki slíka ábyrgð.        "
        /"Stjórnun"
        : TVenja
        
    CTímbnd (C05)
        "^haus@/^fsvar@/^strik@/
        Er^tu ráðin^n tímabundið?
        @/@/@GTímabundin ráðning á til dæmis við um þá sem eru verkefnaráðnir. Ef ráðningasamningur
        er ekki með neinu ákvæði um að hann taki enda er hann ekki tímabundinn.
        Sumarstörf námsmanna eru oftast tímabundin."
        "^haus@/^fsvar@/^strik@/
        ^Are_you employed on a temporary basis?
        @/@/@GTímabundin ráðning á til dæmis við um þá sem eru verkefnaráðnir. Ef ráðningasamningur
        er ekki með neinu ákvæði um að hann taki enda er hann ekki tímabundinn.
        Sumarstörf námsmanna eru oftast tímabundin."
        /"Tímabundin ráðning"
        : TJáNei

    AUXFIELDS
      EfTvöStörf, IfTwoJobs : STRING
      síðustu_viku, last_week : string
      Viðmiðunarvika, Referenceweek : STRING
      zKóti               : string
      sKóti               : STRING
      iKóti               : STRING
     text_BAKodi : string[8]


    RULES
      {kyngreiningarbreytur}
      Are_you  :=persóna.ord
      tu       :=persóna.ord
      your     :=persóna.ord
      þitt     :=persóna.ord
      stu      :=persóna.ord
      you      :=persóna.ord
      you_     :=persóna.ord
      þú       :=persóna.ord
      do_you   :=persóna.ord
      þínum    :=persóna.ord
      þín      :=persóna.ord
      n        :=persóna.ord
      ur       :=persóna.ord
        
      prc_viðmiðunartímiupplýst (viðmiðunardagur - (0,0,6), viðmiðunardagur, viðmiðunarvika, Referenceweek)
      prc_viðmiðunartímiSpurt (viðmiðunardagur - (0,0,6), viðmiðunardagur, síðustu_viku, last_week)
      
      IF TvöStörf = Já THEN
        EfTvöStörf := 'Nú ætla ég að spyrja nánar um það sem þú telur vera aðalstarf ^þitt @/@/'
        IfTwoJobs  := 'I will now ask you about what you consider to be ^your main job @/@/'
      ELSE
        EfTvöStörf := ''
        IfTwoJobs  := ''
      ENDIF
      
      IF (Vinnandi = Já) THEN
         spurtumfirma := já
         spurtumstarf := já
      ENDIF

      {IF Skyldulið <> Já THEN} {Fjarlægt því breytunni skyldulið er hvergi gefið gildi ÞMM des 2015}
        BStatus
        IF bStatus = Sjálfstætt THEN BSjStrf ENDIF
        IF BSjStrf = Já THEN
          {IF FyrraHmnr = 1 then} BFjLaun
            if BFjLaun = dk then BFjLaun_gisk
            endif
          {ENDIF}
        ENDIF
        IF bStatus = Hvorugt THEN BHvÁst ENDIF
      {ENDIF Skyldulið <> Já}

      IF spurtUmFirma = Já THEN
        BFirma
        BIðja
        IF 1=1 then {virkja ÍSAT-kóðun}
            IF BIðja <> Refusal THEN
                BAKóti2008|FinnaÍsat.LOOKUP(Tri:=(BIðja)).ISAT2008
                iKóti := ClassToStr(BAKóti2008)
            if len(text_BAKodi) < 8 then
                text_BAKodi := '0' + text_BAKodi
            endif
            ENDIF
        ENDIF {taka út ÍSAT-kóðun}
        IF 0=1 THEN
          BEiga
        ENDIF
        IF bStatus <> Sjálfstætt THEN BFjStm1 ENDIF
        IF BFjStm1 = DK THEN BFjStm2 ENDIF
      ENDIF {spurtUmFirma = Já }


      IF spurtUmStarf = Já THEN
        BStarf
        IF BStarf <> Refusal THEN
          BSKóti.KEEP |FinnaÍstarf.LOOKUP(Tri:=(BStarf)).Starfakóti
          skóti := ClassToStr(BSKóti)
        ENDIF
        BStLys
        IF bStatus = Launþegi And bFjStm1 <> 1 THEN BVrkStj ENDIF
      ENDIF {spurtUmStarf = Já }
      Status := bStatus
      IF BFirma = DontKnow THEN
        Fyrirtæki := 'Veit ekki heitið'
      ELSEIF BFirma = Refusal THEN
        Fyrirtæki := 'Neitar að gefa upp heitið'
      ELSE
        Fyrirtæki := BFirma
      ENDIF

      IF Vinnandi = Já THEN
        CTímbnd
      ENDIF  
ENDBLOCK
