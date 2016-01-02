{   BlokkGb.inc SILC}

EMBEDDED BLOCK BlokkGb "Vinnutími í aukastörfum"
    FIELDS
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

    RULES
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
ENDBLOCK
