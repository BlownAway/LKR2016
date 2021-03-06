
BLOCK BBarnag�sla
PARAMETERS
{  IMPORT Heimfj : THmFj {Fj�ldi heimilismanna} }
  IMPORT NafnBarns : string
  IMPORT AldurBarns : integer
  import instancenumer_heimlismannsins : integer

LOCALS
B�rn : STRING


AUXFIELDS
Kynning  "^haus@/^fsvar@/^strik@/ N�stu spurningar eru um ^NafnBarns sem er ^AldurBarns �ra."
         "^haus@/^fsvar@/^strik@/ The next questions are about ^NafnBarns which is ^AldurBarns years old." / "Kynning": 0..1, empty

FIELDS

B_dagm      "^haus@/^fsvar@/^strik@/
                Er @C ^NafnBarns @C hj� dagm�mmu e�a h�shj�lp, svo sem au-pair?"
             "^haus@/^fsvar@/^strik@/
                Is @C ^NafnBarns @C with a nanny, a professional child minder or an au-pair?"
                / "Dagmamma": Tj�nei
BG1baT     "^haus@/^fsvar@/^strik@/Hve margar klukkustundir � dag a� me�altali er @C ^NafnBarns @C hj� dagm�mmu e�a h�shj�lp?"
            "^haus@/^fsvar@/^strik@/How many hours a day per average is @C ^NafnBarns @C with the nanny or au-pair?"
                / "Klst hj� dagm�mmu": 1..9

B_leiks      "^haus@/^fsvar@/^strik@/
                Er @C ^NafnBarns @C � leiksk�la?"
             "^haus@/^fsvar@/^strik@/
                Is @C ^NafnBarns @C at kindergarten or play school?"
                / "Leiksk�li": Tj�nei

BG1bbT     "^haus@/^fsvar@/^strik@/Hve margar klukkustundir � dag a� me�altali er @C ^NafnBarns @C � leiksk�la"
           "^haus@/^fsvar@/^strik@/How many hours a day per average is @C ^NafnBarns @C at kindergarten or play school?"
                / "Klst � leiksk�la": 1..9

B_grunns      "^haus@/^fsvar@/^strik@/
                Er @C ^NafnBarns @C � grunnsk�la?"
             "^haus@/^fsvar@/^strik@/
                Is the @C ^NafnBarns @C at school?"
                / "Grunnsk�li": Tj�nei

BG1bgT     "^haus@/^fsvar@/^strik@/Hve margar klukkustundir � dag a� me�altali er @C ^NafnBarns @C � sk�lanum?"
            "^haus@/^fsvar@/^strik@/How many hours a day per average is @C ^NafnBarns @C at school?"
                / "Klst � sk�lanum": 1..9

BG1bgT2    "^haus@/^fsvar@/^strik@/Hve margar klukkustundir � dag a� me�altali er @C ^NafnBarns @C � sk�lanum a� undanskilinni lengdu vi�verunni?"
            "^haus@/^fsvar@/^strik@/How many hours a day per average is @C ^NafnBarns @C at school, not counting child care services?"
                / "Klst � sk�lanum": 1..9

B_vistun      "^haus@/^fsvar@/^strik@/
                Er @C ^NafnBarns @C � lengdri vi�veru � bor� vi� fr�stundaheimili, sk�ladagheimili e�a samb�rilegu?"
             "^haus@/^fsvar@/^strik@/
                Is @C ^NafnBarns @C at a day care center or child care services at the school?"
                / "Heilsdagsvistun": Tj�nei
BG1bdT     "^haus@/^fsvar@/^strik@/Hve margar klukkustundir � dag a� me�altali er @C ^NafnBarns @C � lengdu vi�verunni?"
           "^haus@/^fsvar@/^strik@/How many hours per day on average is @C ^NafnBarns @C in the all day school / after school institution"
                / "Klst � heilsdagssk�la": 1..9

B_fjolsk      "^haus@/^fsvar@/^strik@/
                Er @C ^NafnBarns @C eitthva� � virkum d�gum � g�slu hj� systkinum, vinum, �ttingjum e�a ��rum heimilism�nnum en foreldrum?"
             "^haus@/^fsvar@/^strik@/
                Is @C ^NafnBarns @C looked after by siblings, friends or relatives other than the parents?"
                / "Fj�lskyldug�sla": Tj�nei
BG1bfT     "^haus@/^fsvar@/^strik@/Hve margar klukkustundir � dag a� me�altali er @C ^NafnBarns @C � g�slu hj�
             systkinum, vinum, �ttingjum e�a ��rum heimlism�nnum en foreldrum?"
            "^haus@/^fsvar@/^strik@/How many hours per day on average is @C ^NafnBarns @C looked after by siblings, friends or relatives other than the parents"
                / "Klst hj� �ttingjum": 1..9


instancenumer_heimilismanns "N�mer heimilismanns �r fj�lskyldukaflanum" : integer

RULES

instancenumer_heimilismanns.keep
instancenumer_heimilismanns := instancenumer_heimlismannsins

B�rn := 'Barnsins/Barnanna'
Kynning
IF (AldurBarns < 6)  THEN
  B_leiks
    IF B_leiks = j�
        THEN   BG1bbT
            if BG1bbT > 0 then
                signal
                if (BG1bbT = response) then (BG1bbT <= 9) "Ertu viss um a� t�mar s�u fleiri en 9"
                endif
            else
                signal
                if (BG1bbT = response) then (BG1bbT > 0) "Ertu viss um a� t�mar s�u f�rri en 1 ?"
                endif
            endif
    ENDIF {b_leiks = j�}
ENDIF {Aldurbarns < 6}
IF ((Aldurbarns = 5 and B_leiks = nei) or ((Aldurbarns >= 6 AND Aldurbarns <= 12)))
    THEN B_grunns
ENDIF
IF B_grunns = j�
        Then B_vistun
        IF B_vistun = j�
            THEN BG1bgT2
                if BG1bgT2 > 0 then
                    signal
                    if (BG1bgT2 = response) then (BG1bgT2 <= 9) "Ertu viss um a� t�mar s�u fleiri en 9"
                    endif
                else
                    signal
                    if (BG1bgT2 = response) then (BG1bgT2 > 0) "Ertu viss um a� t�mar s�u f�rri en 1 ?"
                    endif
                endif
        ENDIF {B_vistun = j�}
        IF B_vistun = nei
            THEN BG1bgT
                if BG1bgT > 0 then
                    signal
                    if (BG1bgT = response) then (BG1bgT <= 9) "Ertu viss um a� t�mar s�u fleiri en 9"
                    endif
                else
                    signal
                    if (BG1bgT = response) then (BG1bgT > 0) "Ertu viss um a� t�mar s�u f�rri en 1 ?"
                    endif
                endif
        ENDIF {B_vistun = nei}
        IF B_vistun = j�
            THEN BG1bdT
                if BG1bdT > 0 then
                    signal
                    if (BG1bdT = response) then (BG1bdT <= 9) "Ertu viss um a� t�mar s�u fleiri en 9"
                    endif
                else
                    signal
                    if (BG1bdT = response) then (BG1bdT > 0) "Ertu viss um a� t�mar s�u f�rri en 1 ?"
                    endif
                endif
        ENDIF {B_vistun = j�}
ENDIF {(Aldurbarns => 6 AND Aldurbarns <= 12) or (B_grunns = j�)}
IF Aldurbarns >= 0 AND Aldurbarns <= 12
    THEN B_dagm
        IF B_dagm = j�
            THEN   BG1baT
                if BG1baT > 0 then
                    signal
                    if (BG1baT = response) then (BG1baT <= 9) "Ertu viss um a� t�mar s�u fleiri en 9"
                    endif
                else
                    signal
                    if (BG1baT = response) then (BG1baT > 0) "Ertu viss um a� t�mar s�u f�rri en 1 ?"
                    endif
                endif
        ENDIF {b_dagm = j�}
         B_fjolsk
        IF B_fjolsk = j�
            THEN BG1bfT
                if BG1bfT > 0 then
                    signal
                    if (BG1bfT = response) then (BG1bfT <= 9) "Ertu viss um a� t�mar s�u fleiri en 9"
                    endif
                else
                    signal
                    if (BG1bfT = response) then (BG1bfT > 0) "Ertu viss um a� t�mar s�u f�rri en 1 ?"
                    endif
                endif
        ENDIF {B_fjolsk = j�}
ENDIF {Aldurbarns => 0 AND Aldurbarns <= 12}

ENDBLOCK
