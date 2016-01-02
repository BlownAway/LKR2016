
BLOCK BBarnagæsla
PARAMETERS
{  IMPORT Heimfj : THmFj {Fjöldi heimilismanna} }
  IMPORT NafnBarns : string
  IMPORT AldurBarns : integer
  import instancenumer_heimlismannsins : integer

LOCALS
Börn : STRING


AUXFIELDS
Kynning  "^haus@/^fsvar@/^strik@/ Næstu spurningar eru um ^NafnBarns sem er ^AldurBarns ára."
         "^haus@/^fsvar@/^strik@/ The next questions are about ^NafnBarns which is ^AldurBarns years old." / "Kynning": 0..1, empty

FIELDS

B_dagm      "^haus@/^fsvar@/^strik@/
                Er @C ^NafnBarns @C hjá dagmömmu eða húshjálp, svo sem au-pair?"
             "^haus@/^fsvar@/^strik@/
                Is @C ^NafnBarns @C with a nanny, a professional child minder or an au-pair?"
                / "Dagmamma": Tjánei
BG1baT     "^haus@/^fsvar@/^strik@/Hve margar klukkustundir á dag að meðaltali er @C ^NafnBarns @C hjá dagmömmu eða húshjálp?"
            "^haus@/^fsvar@/^strik@/How many hours a day per average is @C ^NafnBarns @C with the nanny or au-pair?"
                / "Klst hjá dagmömmu": 1..9

B_leiks      "^haus@/^fsvar@/^strik@/
                Er @C ^NafnBarns @C í leikskóla?"
             "^haus@/^fsvar@/^strik@/
                Is @C ^NafnBarns @C at kindergarten or play school?"
                / "Leikskóli": Tjánei

BG1bbT     "^haus@/^fsvar@/^strik@/Hve margar klukkustundir á dag að meðaltali er @C ^NafnBarns @C á leikskóla"
           "^haus@/^fsvar@/^strik@/How many hours a day per average is @C ^NafnBarns @C at kindergarten or play school?"
                / "Klst á leikskóla": 1..9

B_grunns      "^haus@/^fsvar@/^strik@/
                Er @C ^NafnBarns @C í grunnskóla?"
             "^haus@/^fsvar@/^strik@/
                Is the @C ^NafnBarns @C at school?"
                / "Grunnskóli": Tjánei

BG1bgT     "^haus@/^fsvar@/^strik@/Hve margar klukkustundir á dag að meðaltali er @C ^NafnBarns @C í skólanum?"
            "^haus@/^fsvar@/^strik@/How many hours a day per average is @C ^NafnBarns @C at school?"
                / "Klst í skólanum": 1..9

BG1bgT2    "^haus@/^fsvar@/^strik@/Hve margar klukkustundir á dag að meðaltali er @C ^NafnBarns @C í skólanum að undanskilinni lengdu viðverunni?"
            "^haus@/^fsvar@/^strik@/How many hours a day per average is @C ^NafnBarns @C at school, not counting child care services?"
                / "Klst í skólanum": 1..9

B_vistun      "^haus@/^fsvar@/^strik@/
                Er @C ^NafnBarns @C í lengdri viðveru á borð við frístundaheimili, skóladagheimili eða sambærilegu?"
             "^haus@/^fsvar@/^strik@/
                Is @C ^NafnBarns @C at a day care center or child care services at the school?"
                / "Heilsdagsvistun": Tjánei
BG1bdT     "^haus@/^fsvar@/^strik@/Hve margar klukkustundir á dag að meðaltali er @C ^NafnBarns @C í lengdu viðverunni?"
           "^haus@/^fsvar@/^strik@/How many hours per day on average is @C ^NafnBarns @C in the all day school / after school institution"
                / "Klst í heilsdagsskóla": 1..9

B_fjolsk      "^haus@/^fsvar@/^strik@/
                Er @C ^NafnBarns @C eitthvað á virkum dögum í gæslu hjá systkinum, vinum, ættingjum eða öðrum heimilismönnum en foreldrum?"
             "^haus@/^fsvar@/^strik@/
                Is @C ^NafnBarns @C looked after by siblings, friends or relatives other than the parents?"
                / "Fjölskyldugæsla": Tjánei
BG1bfT     "^haus@/^fsvar@/^strik@/Hve margar klukkustundir á dag að meðaltali er @C ^NafnBarns @C í gæslu hjá
             systkinum, vinum, ættingjum eða öðrum heimlismönnum en foreldrum?"
            "^haus@/^fsvar@/^strik@/How many hours per day on average is @C ^NafnBarns @C looked after by siblings, friends or relatives other than the parents"
                / "Klst hjá ættingjum": 1..9


instancenumer_heimilismanns "Númer heimilismanns úr fjölskyldukaflanum" : integer

RULES

instancenumer_heimilismanns.keep
instancenumer_heimilismanns := instancenumer_heimlismannsins

Börn := 'Barnsins/Barnanna'
Kynning
IF (AldurBarns < 6)  THEN
  B_leiks
    IF B_leiks = já
        THEN   BG1bbT
            if BG1bbT > 0 then
                signal
                if (BG1bbT = response) then (BG1bbT <= 9) "Ertu viss um að tímar séu fleiri en 9"
                endif
            else
                signal
                if (BG1bbT = response) then (BG1bbT > 0) "Ertu viss um að tímar séu færri en 1 ?"
                endif
            endif
    ENDIF {b_leiks = já}
ENDIF {Aldurbarns < 6}
IF ((Aldurbarns = 5 and B_leiks = nei) or ((Aldurbarns >= 6 AND Aldurbarns <= 12)))
    THEN B_grunns
ENDIF
IF B_grunns = já
        Then B_vistun
        IF B_vistun = já
            THEN BG1bgT2
                if BG1bgT2 > 0 then
                    signal
                    if (BG1bgT2 = response) then (BG1bgT2 <= 9) "Ertu viss um að tímar séu fleiri en 9"
                    endif
                else
                    signal
                    if (BG1bgT2 = response) then (BG1bgT2 > 0) "Ertu viss um að tímar séu færri en 1 ?"
                    endif
                endif
        ENDIF {B_vistun = já}
        IF B_vistun = nei
            THEN BG1bgT
                if BG1bgT > 0 then
                    signal
                    if (BG1bgT = response) then (BG1bgT <= 9) "Ertu viss um að tímar séu fleiri en 9"
                    endif
                else
                    signal
                    if (BG1bgT = response) then (BG1bgT > 0) "Ertu viss um að tímar séu færri en 1 ?"
                    endif
                endif
        ENDIF {B_vistun = nei}
        IF B_vistun = já
            THEN BG1bdT
                if BG1bdT > 0 then
                    signal
                    if (BG1bdT = response) then (BG1bdT <= 9) "Ertu viss um að tímar séu fleiri en 9"
                    endif
                else
                    signal
                    if (BG1bdT = response) then (BG1bdT > 0) "Ertu viss um að tímar séu færri en 1 ?"
                    endif
                endif
        ENDIF {B_vistun = já}
ENDIF {(Aldurbarns => 6 AND Aldurbarns <= 12) or (B_grunns = já)}
IF Aldurbarns >= 0 AND Aldurbarns <= 12
    THEN B_dagm
        IF B_dagm = já
            THEN   BG1baT
                if BG1baT > 0 then
                    signal
                    if (BG1baT = response) then (BG1baT <= 9) "Ertu viss um að tímar séu fleiri en 9"
                    endif
                else
                    signal
                    if (BG1baT = response) then (BG1baT > 0) "Ertu viss um að tímar séu færri en 1 ?"
                    endif
                endif
        ENDIF {b_dagm = já}
         B_fjolsk
        IF B_fjolsk = já
            THEN BG1bfT
                if BG1bfT > 0 then
                    signal
                    if (BG1bfT = response) then (BG1bfT <= 9) "Ertu viss um að tímar séu fleiri en 9"
                    endif
                else
                    signal
                    if (BG1bfT = response) then (BG1bfT > 0) "Ertu viss um að tímar séu færri en 1 ?"
                    endif
                endif
        ENDIF {B_fjolsk = já}
ENDIF {Aldurbarns => 0 AND Aldurbarns <= 12}

ENDBLOCK
