{   BlokkJ.inc SILC }
EMBEDDED BLOCK BlokkJ "Síðasta starf"

   PARAMETERS
     IMPORT persóna : TPersóna

   EXTERNALS
     finnaÍstarf : ISTARF ('ISTARF')

    FIELDS
      JStatus (J01)
        "^haus@/^fsvar@/^strik@/
        Var^stu launþegi eða sjálfstætt starfandi í síðasta starfi?"
         "^haus@/^fsvar@/^strik@/
        ^Were_you a wage earner or self-employed in ^your last job?"
        /"Launþ sjálfst"
        : TStatus

      Jtímbnd
        "^haus@/^fsvar@/^strik@/
        Var^stu í fastri vinnu eða ráðin^n tímabundið í síðasta starfi?
        @/@/@GSpurt er um síðasta starf sem viðkomandi starfaði við."
         "^haus@/^fsvar@/^strik@/
        Did ^you have a regular job or was ^your last job temporary?
        @/@/@GSpurt er um síðasta starf sem viðkomandi starfaði við."
        /"Tímabundin vinna"
        : (
         fastri     "Í fastri vinnu" "Regular job",
         tímabundið "Ráðin^n tímabundið" "Temporary"
          )

      JSjstrf (J02)
        "^haus@/^fsvar@/^strik@/
        Var^stu með starfsmenn á launum?"
        "^haus@/^fsvar@/^strik@/
        Did ^you have paid employees working for you?"
        /"Launaða starfsm"
        : TJáNei
      JHvÁst (J03)
       "^haus@/^fsvar@/^strik@/
        Hver var staða þín?
        @/@/@GÞegar hingað er komið hefur líklega eitthvað komið upp á fyrr í spurningalistanum, þannig að þú myndir sennilega
        vilja @Ubakka héðan@U. Líkleg skýring er til dæmis að svarandi er í raun atvinnulaus, en merkt hefur verið við hann sem
        vinnandi áður. Hafðu einnig í huga að sjálfboðavinna telst ekki til launaðrar vinnu í spurningalistanum. @G"
        "^haus@/^fsvar@/^strik@/
        If neither, please give details?
        @/@/@GÞegar hingað er komið hefur líklega eitthvað komið upp á fyrr í spurningalistanum, þannig að þú myndir sennilega
        vilja @Ubakka héðan@U. Líkleg skýring er til dæmis að svarandi er í raun atvinnulaus, en merkt hefur verið við hann sem
        vinnandi áður. Hafðu einnig í huga að sjálfboðavinna telst ekki til launaðrar vinnu í spurningalistanum. @G"
        /"Hvorugt hvað"
        :String [80]
      JStaður (J04)
        "^haus@/^fsvar@/^strik@/
        Í hvaða sveitarfélagi vann^stu?"
        "^haus@/^fsvar@/^strik@/
        Which municipality did you work in?"
        /"Sveitarfélag"
        : TSveit
      JFirma (J05)
        "^haus@/^fsvar@/^strik@/
        Hjá hvaða fyrirtæki vann^stu?"
        "^haus@/^fsvar@/^strik@/
        Which company did ^you work for?"
        /"Hvaða fyrirtæki"
        :String [50]
      JIðja (J06)
        "^haus@/^fsvar@/^strik@/
        Hver er starfsemi fyrirtækisins aðallega
        @/@/@GEf fleiri en einn vinnustaður, miða við vinnustað svaranda?
        @/Vinnustaður er öll starfsemin á lóðinni, ekki bara deild viðkomandi@G"
         "^haus@/^fsvar@/^strik@/
        What is the company's main activity
        @/@/@GIf there is more than one workplace, refer to the respondent's workplace
        @/Workplace means all activity on the site, not just the respondent's department@G"
        /"Aðalstarfsemi"
        :String [80]
      JStarf (J07)
        "^haus@/^fsvar@/^strik@/
        Hvert var starfsheiti ^þitt, það er, nákvæmt starfsheiti?
        @/@/@Gt.d. umönnun aldraðra, ekki bara umönnun,  kynningarfulltrúi ekki bara fulltrúi,
         háseti á línubát en ekki bara sjómaður@G"
         "^haus@/^fsvar@/^strik@/
        What was ^your job title, that is, precise job title?
        @/@/@Ge.g. caring for the elderly (not just healthcare), PR representative (not just representative,
         first mate on longliner (not just seaman)@G"
         /"Starfsheiti"
        :string [50]
      JSKóti
        "^haus@/^fsvar@/^strik@/
        @GFlettu upp viðeigandi kóta með því að ýta á BILSTÖNGINA@G"
        "^haus@/^fsvar@/^strik@/
        @GCheck the relevant code by pressing the SPACEBAR@G"
        /"Starfakóti"
        : TIstarf
      JStLys (J08)
        "^haus@/^fsvar@/^strik@/
        Hver voru helstu verkefnin?"
        "^haus@/^fsvar@/^strik@/
        What were the main tasks in that job?"
        /"Helstu verkefni"
        :string [80]

      JEiga (J09)
       "^haus@/^fsvar@/^strik@/
        Var fyrirtækið í eigu einhvers á heimilinu?
        @/@/@GEf spyrill veit að fyrirtækið er ríkisstofnun, hlutafélag, sjálfseignarstofnun eða viss um að enginn á heimilinu
        eig það má sleppa að spyrja þessarar spurningar og svara nei"
        "^haus@/^fsvar@/^strik@/
        Is the company owned by someone at the home?"
        /"Eigandi fyrirtækisins"
        :TJáNei

      Jvrkstj
        "^haus@/^fsvar@/^strik@/
        Skipulagði^r ^þú eða stjórnaði^r verkum annarra starfsmanna?"
        "^haus@/^fsvar@/^strik@/
        Did ^you have supervisory responsibilities?"
        /"Eigandi fyrirtækisins"
        :(venjulega "Venjulega" "Yes, usually",
          stundum "stundum" "Sometimes",
          aldrei "aldrei" "No")


    AUXFIELDS
      sKóti : STRING

      stu     :(karl2p "stu",kona2p "stu",karl3p " hann",kona3p " hún",óvíst3p " hann/hún")
      Were_you : (karl2p "Were you",kona2p "Were you",karl3p "Was he",kona3p "Was she",óvíst3p "Was he/she")
      you     :  (karl2p "you",kona2p "you",karl3p "he",kona3p "she",óvíst3p "he/she")
      þitt    : (karl2p "þitt",kona2p "þitt",karl3p "hans",kona3p "hennar",óvíst3p "hans/hennar")
      your    : (karl2p "your",kona2p "your",karl3p "his",kona3p "her",óvíst3p "his/her")
      þú      : (karl2p "þú",kona2p "þú",karl3p "hann",kona3p "hún",óvíst3p "hann/hún")
      r       : (karl2p "r",kona2p "r",karl3p " ",kona3p " ", óvíst3p " ")
      
    RULES
      n:=persóna.ord
      ur:=persóna.ord
      stu:=persóna.ord
      Were_you:=persóna.ord
      you:=persóna.ord
      þitt:=persóna.ord
      your:=persóna.ord
      þú :=persóna.ord
      r  :=persóna.ord
      
    
      JStatus
      IF JStatus = sjálfstætt THEN JSjstrf ENDIF
      IF JStatus = Hvorugt THEN JHvÁst ENDIF
      Jtímbnd
      JStarf
      IF JStarf <> Refusal THEN
        JSKóti.KEEP |finnaÍstarf.LOOKUP(Tri:=(JStarf)).Starfakóti
        sKóti := ClassToStr(JSKóti)
      ENDIF
      JStLys
      Jvrkstj

ENDBLOCK
