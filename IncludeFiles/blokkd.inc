{   BlokkD.inc SILC}

EMBEDDED BLOCK BlokkD "Vinnutími"
    PARAMETERS
        IMPORT Persóna   : TPersóna
        IMPORT TvöStörf  : TJáNei
        EXPORT vinnutími : INTEGER
    FIELDS
      DVenja (D01)
        "^haus@/^fsvar@/^strik@/
        Hvað vinnur ^þú margar klukkustundir á viku að jafnaði í ^þínu aðalstarfi?
        @/@/@GSetja 0 ef vinnutími er mjög óreglulegur@G"
         "^haus@/^fsvar@/^strik@/
         How many hours ^doyou work in a normal week in ^your main job?
        @/@/@GSetja 0 ef vinnutími er mjög óreglulegur@G"
        /"Venjulegur vinnutími"
        : 0..120, dontknow
        
      Dítrek (D01ítrek)
        "^haus@/^fsvar@/^strik@/
        Getur þú sagt á hvaða bili meðalvinnutíminn er á viku...
        @/@/@GLestu upp svarkostina@G"
        "^haus@/^fsvar@/^strik@/
        Can you give a range for ^your average working hours per week...
        @/@/@GLestu upp svarkostina@G"
        /"Meðalvinnutímabil"
        : (
        EinnTil10                       "...1-10",
        Ellefutil20                     "...11-20",
        TuttuguogEinnTil30              "...21-30",
        ÞrjátíuogeinnTil34              "...31-34",
        ÞrjátíuogfimmTil45              "...35-45",
        FjörutíuogsexTil50              "...46-50",
        FimmtíuogeinnTil60              "...51-60",
        SextíuogeinnPlús                "...61 eða fleiri")

      GSíðast (G09)
        "^haus@/^fsvar@/^strik@/
        Hvað vinnur ^þú margar klukkustundir á viku að jafnaði í aukastarfi eða störfum?
        @/@/@GÁtt er við heildarvinnutíma í öllum aukastörfum. Launað aukastarf nær líka
        yfir störf þar sem tekjurnar koma með öðrum hætti, til dæmis rekstrarhagnaði.@G
        @/@/@GSetja 0 ef vinnutími er mjög óreglulegur eða starfið ekki venjulegt@G"
        "^haus@/^fsvar@/^strik@/
        How many hours per week do you usually work in other jobs besides your regular job?
        @/@/@GÁtt er við heildarvinnutíma í öllum aukastörfum. Launað aukastarf nær líka
        yfir störf sem þar sem tekjurnar koma með öðrum hætti, til dæmis rekstrarhagnaði.@G
        @/@/@GSetja 0 ef vinnutími er mjög óreglulegur eða starfið ekki venjulegt@G"
        /"Vinnutími"
        : 0..100

      Gítrek
        "^haus@/^fsvar@/^strik@/
        Getur þú sagt á hvaða bili meðalvinnutíminn er á viku...
        @/@/@GLestu upp svarkostina@G"
        "^haus@/^fsvar@/^strik@/
        Per week, are ^your average working hours between...
        @/@/@GLestu upp svarkostina@G"
        /"Meðalvinnutímabil"
        : (
        EinnTil10                       "...1-10",
        Ellefutil20                     "...11-20",
        TuttuguogEinnTil30              "...21-30",
        ÞrjátíuogeinnTil34              "...31-34",
        ÞrjátíuogfimmTil45              "...35-45",
        FjörutíuogsexTil50              "...46-50",
        FimmtíuogeinnTil60              "...51-60",
        SextíuogeinnPlús                "...61 eða fleiri")


    AUXFIELDS
      í_aðalstarfinu  : STRING
      MeirMinn : (Meira, Minna)
      
      þú      : (karl2p "þú",kona2p "þú",karl3p "hann",kona3p "hún",óvíst3p "hann/hún")
      þinn    : (karl2p "þinn",kona2p "þinn",karl3p "hans",kona3p "hennar",óvíst3p "hans/hennar")
      þínu    : (karl2p "þínu",kona2p "þínu",karl3p "sínu",kona3p "sínu",óvíst3p "sínu")
      þér     : (karl2p "þér",kona2p "þér",karl3p "sér",kona3p "sér",óvíst3p "sér")
      þig     : (karl2p "þig",kona2p "þig",karl3p "hann",kona3p "hana",óvíst3p "hann/hana")
      stu     : (karl2p "stu",kona2p "stu",karl3p " hann",kona3p " hún",óvíst3p " hann/hún")
      n       : (karl2p "n",kona2p " ",karl3p "n",kona3p " ", óvíst3p "/n")
      ur      : (karl2p "ur",kona2p " ",karl3p "ur",kona3p " ", óvíst3p "ur")
      you     : (karl2p "you",kona2p "you",karl3p "he",kona3p "she",óvíst3p "he/she")
      your    : (karl2p "your",kona2p "your",karl3p "his",kona3p "her",óvíst3p "his/her")
      doyou   : (karl2p "Do you",kona2p "Do you",karl3p "Does he",kona3p "Does she",óvíst3p "Does he/she")


    LOCALS
      StarfNýHafið : STRING

    RULES
      þú:=persóna.ord
      þig:=persóna.ord
      þínu:=persóna.ord
      þinn:=persóna.ord
      stu:=persóna.ord
      þér:=persóna.ord
      you:=persóna.ord
      your:=persóna.ord
      doyou:=persóna.ord
      n:=persóna.ord
      ur:=persóna.ord

      {Vinnutími í aðalstarfi}
      
      DVenja

      IF DVenja = dontknow or DVenja = 0 THEN
        {DFlokk}
        Dítrek
        IF Dítrek = EinnTil10 THEN DVenja := 5
        ELSEIF Dítrek = Ellefutil20  THEN DVenja := 15
        ELSEIF Dítrek = TuttuguogEinnTil30 THEN DVenja := 25
        ELSEIF Dítrek = ÞrjátíuogeinnTil34 THEN DVenja := 33
        ELSEIF Dítrek = ÞrjátíuogfimmTil45 THEN DVenja := 40
        ELSEIF Dítrek = FjörutíuogsexTil50 THEN DVenja := 48
        ELSEIF Dítrek = FimmtíuogeinnTil60 THEN DVenja := 55
        ELSEIF Dítrek = SextíuogeinnPlús   THEN DVenja := 70
        ENDIF
      ENDIF
      vinnutími:=DVenja
      {Vinnutími í aukastörfum}
      IF Tvöstörf = Já THEN
         GSíðast
         if (GSíðast = dk) or (GSíðast = 0) then
           Gítrek
           IF Gítrek = EinnTil10 THEN GSíðast := 5
           ELSEIF Gítrek = Ellefutil20  THEN GSíðast := 15
           ELSEIF Gítrek = TuttuguogEinnTil30 THEN GSíðast := 25
           ELSEIF Gítrek = ÞrjátíuogeinnTil34 THEN GSíðast := 33
           ELSEIF Gítrek = ÞrjátíuogfimmTil45 THEN GSíðast := 40
           ELSEIF Gítrek = FjörutíuogsexTil50 THEN GSíðast := 48
           ELSEIF Gítrek = FimmtíuogeinnTil60 THEN GSíðast := 55
           ELSEIF Gítrek = SextíuogeinnPlús   THEN GSíðast := 70
           ENDIF
         ENDIF
         vinnutími:=DVenja+GSíðast
      ENDIF

ENDBLOCK
