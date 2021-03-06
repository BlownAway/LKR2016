{BHmFj�ldi.inc
    Samfelld VMR
    �H (c) n�v. 2002}

EMBEDDED BLOCK BHmFj�ldi "Fj�ldi heimilismanna"

    PARAMETERS
       IMPORT pers�na     : TPers�na
       EXPORT Fj�ldi      : INTEGER

    FIELDS
      HeimFj (Hm01)
         "^haus@/^fsvar@/^strik@/
          Hversu margir eru � heimili ^��nu a� ^��r ^me�t�ldum ?
          @/@/@GLykilatri�i er a� vi�komandi anna�hvort afli og/e�a n�ti tekjur heimilisins og dveljist
          �ar reglulega. Til d�mis, b�rn � heimavistarsk�lum, b�rn sem b�a � tveimur heimilum, sj�menn
          e�a �eir sem eru � sj�krah�si og �eir sem vinna langdv�lum � burtu til d�mis � K�rahnj�kum.@G"
         "^haus@/^fsvar@/^strik@/
          How many persons are in ^your household, including ^yourself?
          @/@/@GLykilatri�i er a� vi�komandi anna�hvort afli og/e�a n�ti tekjur heimilisins og dveljist
          �ar reglulega. Til d�mis, b�rn � heimavistarsk�lum, b�rn sem b�a � tveimur heimilum, sj�menn
          e�a �eir sem eru � sj�krah�si og �eir sem vinna langdv�lum � burtu til d�mis � K�rahnj�kum.@G"
         /"Fj�ldi heimilismanna"
           : THmFjB
       HeimTeg (Hm02)
         "^haus@/^fsvar@/^strik@/
           Hvers konar stofnun?"
         "^haus@/^fsvar@/^strik@/
           What kind of institution?"
         /"Hvers konar heimili"
         : (Heimavist   "Heimavist"
                        "Boarding school",
            Sj�krah�s   "Sj�krah�s"
                        "Hospital",
            Samb�li     "H�li e�a samb�li"
                        "Other welfare institutions",
            Klaustur    "Klaustur"
                        "Monastery/nunnery",
            Verb��      "Verb�� e�a vinnub��"
                        "Workers' hostel",
            Anna�   (9) "Anna� (t.d. fangelsi, gistiheimili)"
                        "Other (e.g. prison, guesthosuse")

    LOCALS
      me�t�ldum : string
      ��nu, ��r : string
      you, your, yourself : string
      i : integer

    RULES
       prc_��nuHansHennar (Pers�na, ��nu)
       prc_��rHonumHenni  (Pers�na, ��r)
       prc_youHeShe       (Pers�na, you)
       prc_yourHisHer     (Pers�na, your)
       prc_YourselfHimselfHerself (Pers�na, yourself)
       prc_Me�t�ldum      (Pers�na, me�t�ldum)

       fsvar := ''
       HeimFj  {B��i me� og �n fyrri svara f� sp um fj�lda � heimili}
       IF HeimFj = T0 THEN
            HeimTeg
       ENDIF
       Fj�ldi := ORD(HeimFj)

{layout
  at HeimFj infopane AdalSkjar3Dalkar}

ENDBLOCK
