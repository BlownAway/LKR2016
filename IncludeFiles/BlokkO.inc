{   BlokkO.inc
    Samfelld vinnumarkaðsrannsókn
    ÓH (c) desember 2002
    ÓH (c) mars 2003 - útg. 1.2
 }

EMBEDDED BLOCK BlokkO "Skólaganga"
   PARAMETERS
      IMPORT viðmiðunardagur : DateType
      IMPORT persóna : TPersóna
      import FæðÁr : integer
      {EXPORT Menntun : TGMenntun
      EXPORT Skólakóti : TNAM}

   EXTERNALS
     námsbraut : Nám
     iðngrein  : Iðn
     skólar    : Skólar

    EMBEDDED BLOCK BSkolaLeit
        FIELDS
            OSkHvaða_b "@GFlettu upp viðeigandi skóla með því að ýta á BILSTÖNGINA" : STRING[50]
            ROUTER leita ALIEN('LookupManager.msu','prc_skoliLookup2')
        RULES
            OSkHvaða_b
    ENDBLOCK

    EMBEDDED BLOCK BNamLeit
        FIELDS
            ONamHvað_b "@GFlettu upp viðeigandi námsgrein með því að ýta á BILSTÖNGINA": STRING[120]
            ROUTER leita ALIEN('LookupManager.msu','prc_namLookup')
        RULES
            ONamHvað_b
    ENDBLOCK

    FIELDS
      OSkóli (o01)
        "^haus@/^fsvar@/^strik@/
        Var^stu í skóla eða á námssamningi á ^síðustufjórumvikum?"
        "^haus@/^fsvar@/^strik@/
        W^ere_you registered at school or on an apprenticeship in the ^lastfourweeks?"
        /"Skóli síðustu 4 vikur"
        : TSkóli2b

      OSkHvaða (o02a)
        "^haus@/^fsvar@/^strik@/
        Í hvaða skóla var^stu?"
        "^haus@/^fsvar@/^strik@/
        In what school w^ere_you?"
        /"Hvaða skóli"
        : STRING[80]
      OSklID     ""/"Fastanúmer" : INTEGER

      Namsstig
         "^haus@/^fsvar@/^strik@/
          Er þetta grunnskóli, framhaldsskóli, iðnskóli, háskóli eða annað nám?"
        "^haus@/^fsvar@/^strik@/
          What level of education is this?
          Is this a primary school, middle school, high school, vocational school, college, university
          or something else?"
        /"Grunnskóli"
        : TSkolastig

      ONamHvað (o02b)
        "^haus@/^fsvar@/^strik@/
        Í hvaða ^námsgrein?"
        "^haus@/^fsvar@/^strik@/
        In which ^field?"
        /"Hvaða námsgrein"
        : STRING[120]


      OSklKóti (o02c)
        "^haus@/^fsvar@/^strik@/
        @GFlettu upp viðeigandi skóla með því að ýta á BILSTÖNGINA
        @/@/Verið er að leita að réttu skólastigi og námsgrein.  Ef þú finnur ekki nákvæmlega
        þann skóla sem viðkomandi var í máttu velja námsgreinina í öðrum skóla svo fremi
        skólinn sé á sama skólastigi (ISCED).@G"
        /"Fastanúmer náms"
        : INTEGER


      {ONmsHvað (o03a)
        "^haus@/^fsvar@/^strik@/
        Í hvaða iðngrein var^stu á námssamningi?"
        "^haus@/^fsvar@/^strik@/
        In which trade/craft?"
        /"Hvaða iðngrein"
        : STRING[80]

      ONmsKóti (o03b)
        "^haus@/^fsvar@/^strik@/
        @GFlettu upp viðeigandi kóta með því að ýta á BILSTÖNGINA@G"
        /"Kóti iðngreinar"
        : TNam }
        
        
      ONamGrada (o04)
  	  "^haus@/^fsvar@/^strik@/
  	  Er^tu í..."
     "^haus@/^fsvar@/^strik@/
      ^Are_you studying for... "
  	/ "Gráða"
  	: (Studentsprof    	"Námi til stúdentspróf?"  "Matriculation?",
  	   Sveinsprof	    "Námi til sveinsprófs?"   "A journeyman examination?",
  	   Meistaraprof		"Námi til meistaraprófs?" "A master craft- or tradesman examination?",
       haskoli          "Háskólanámi?"            "A university degree?",
  	   Onnur		    "Eða öðru námi?"          "or other qualifications?")

     ONamHaskoli (o04b)
	"^haus@/^fsvar@/^strik@/
	Hvernig háskólanámi er^tu í? Er það..."
	"^haus@/^fsvar@/^strik@/
	What university degree are ^you studying for:"
	/ "Háskólapróf"
	: (Diploma		"Diplóma eða sambærilegu nám?" "Diploma or comparable?",
       BA			"BA/BS nám?" "BA/BS?",
       MA			"MA/MS nám?" "MA/MS?",
	   Doktor 		"Doktorsnám (Phd)?" "PhD?",
	   Annad	    "Eða annað nám?" "Another degree or no degree?")
         
      Skolaleit: BSkolaleit
      Nam_leit : BNamleit




    AUXFIELDS
      Menntun : TGMenntun
      Skólakóti : TNAM

      ONamLeit : TLeit

      sKóti    : String

      síðustufjórumvikum : STRING
      lastfourweeks : STRING


      stu  : (karl2p "stu",kona2p "stu",karl3p " hann",kona3p " hún",óvíst3p " hann/hún")
      ere_you : (karl2p "ere you",kona2p "ere you",karl3p "as he",kona3p "as she",óvíst3p "as he/she")
      n : (karl2p "n",kona2p " ",karl3p "n",kona3p " ", óvíst3p "/n")
      ur: (karl2p "ur",kona2p " ",karl3p "ur",kona3p " ",óvíst3p "(ur)")
      are_you:  (karl2p "Are you",kona2p "Are you",karl3p "Is he",kona3p "Is she",óvíst3p "Is he/she")
      tu   :(karl2p "tu",kona2p "tu",karl3p " hann",kona3p " hún",óvíst3p " hann/hún")
      you :  (karl2p "you",kona2p "you",karl3p "he",kona3p "she",óvíst3p "he/she")
      
    LOCALS
      iKóti    : String
      námsgrein : string
      field     :string

    RULES
      stu:=persóna.ord
      ere_you:=persóna.ord
      n:=persóna.ord
      ur:=persóna.ord
      are_you:=persóna.ord
      tu:=persóna.ord
      you:=persóna.ord
      
      prc_viðmiðunartímiSpurt (viðmiðunardagur - (0,0,27), viðmiðunardagur, SíðustuFjórumVikum, lastFourWeeks)

      OSkóli

      IF OSkóli IN [Skóli, bæði] THEN
        OSkHvaða
        Skolaleit.leita
        OSklID.show
      ENDIF
      námsgrein:='námsgrein'
      field :='field'
      IF OSkóli IN [námssamningur, bæði] THEN
         námsgrein:='iðngrein var námssamningurinn'
         field :='trade or craft is the apprenticeship'
      ENDIF
      Namsstig.keep
      IF OSkóli IN [námssamningur, bæði] THEN 
        Namsstig :=Sveinspróf
      ENDIF
      IF Namsstig > Grunnskólapróf THEN
         ONamHvað
         Nam_leit.leita
         OSklKóti.show
         sKóti.show
         {Skólakóti := OSklKóti}
      ENDIF
      IF     (SUBSTRING(sKóti,1,1) IN ['5','6'] ) Namsstig = Háskóli
      ELSEIF (SUBSTRING(sKóti,1,1) = '3' AND Namsstig = EMPTY) Namsstig = stúdentspróf
      IF Namsstig=EMPTY THEN
         
        Namsstig 
        IF (Namsstig = Háskóli) THEN
                ONamHaskoli
            ENDIF
      ENDIF
             


      {IF (year(viðmiðunardagur) - FæðÁr) <= 20 THEN
 
        ENDIF
      ELSEIF (year(viðmiðunardagur) - FæðÁr) <= 24 THEN
        IF Substring(sKóti,1,1)='5' THEN Menntun:= Stúdent ENDIF
      ELSE
        IF Substring(sKóti,1,1)='5' THEN Menntun:= Stúdent                             {ath hvort þetta á að vera svona}
        ELSEIF Substring(sKóti,1,1)='3' THEN Menntun := Grunnskóli
        ELSEIF Substring(iKóti,1,1)='3' THEN Menntun := Grunnskóli
        ELSEIF Substring(SKóti,1,1)='2' THEN Menntun := MinnaEnGrunnskóli
        ENDIF
      ENDIF }

ENDBLOCK

