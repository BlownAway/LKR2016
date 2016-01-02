{BHmFjöldi.inc
    Samfelld VMR
    ÓH (c) nóv. 2002}

EMBEDDED BLOCK BHmFjöldi "Fjöldi heimilismanna"

    PARAMETERS
       IMPORT persóna     : TPersóna
       EXPORT Fjöldi      : INTEGER

    FIELDS
      HeimFj (Hm01)
         "^haus@/^fsvar@/^strik@/
          Hversu margir eru á heimili ^þínu að ^þér ^meðtöldum ?
          @/@/@GLykilatriði er að viðkomandi annaðhvort afli og/eða nýti tekjur heimilisins og dveljist
          þar reglulega. Til dæmis, börn í heimavistarskólum, börn sem búa á tveimur heimilum, sjómenn
          eða þeir sem eru á sjúkrahúsi og þeir sem vinna langdvölum í burtu til dæmis á Kárahnjúkum.@G"
         "^haus@/^fsvar@/^strik@/
          How many persons are in ^your household, including ^yourself?
          @/@/@GLykilatriði er að viðkomandi annaðhvort afli og/eða nýti tekjur heimilisins og dveljist
          þar reglulega. Til dæmis, börn í heimavistarskólum, börn sem búa á tveimur heimilum, sjómenn
          eða þeir sem eru á sjúkrahúsi og þeir sem vinna langdvölum í burtu til dæmis á Kárahnjúkum.@G"
         /"Fjöldi heimilismanna"
           : THmFjB
       HeimTeg (Hm02)
         "^haus@/^fsvar@/^strik@/
           Hvers konar stofnun?"
         "^haus@/^fsvar@/^strik@/
           What kind of institution?"
         /"Hvers konar heimili"
         : (Heimavist   "Heimavist"
                        "Boarding school",
            Sjúkrahús   "Sjúkrahús"
                        "Hospital",
            Sambýli     "Hæli eða sambýli"
                        "Other welfare institutions",
            Klaustur    "Klaustur"
                        "Monastery/nunnery",
            Verbúð      "Verbúð eða vinnubúð"
                        "Workers' hostel",
            Annað   (9) "Annað (t.d. fangelsi, gistiheimili)"
                        "Other (e.g. prison, guesthosuse")

    LOCALS
      meðtöldum : string
      þínu, þér : string
      you, your, yourself : string
      i : integer

    RULES
       prc_ÞínuHansHennar (Persóna, þínu)
       prc_þérHonumHenni  (Persóna, þér)
       prc_youHeShe       (Persóna, you)
       prc_yourHisHer     (Persóna, your)
       prc_YourselfHimselfHerself (Persóna, yourself)
       prc_Meðtöldum      (Persóna, meðtöldum)

       fsvar := ''
       HeimFj  {Bæði með og án fyrri svara fá sp um fjölda á heimili}
       IF HeimFj = T0 THEN
            HeimTeg
       ENDIF
       Fjöldi := ORD(HeimFj)

{layout
  at HeimFj infopane AdalSkjar3Dalkar}

ENDBLOCK
