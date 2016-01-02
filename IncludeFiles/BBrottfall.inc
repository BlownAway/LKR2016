{   BBrottfall.inc
    ÓH (c) 17. nóvember 2002

}

BLOCK BBrottfall "Brottfall"

    FIELDS

        Ástæða
        "^haus@/^fsvar@/^strik@/
        Ástæða brottfallsins?
	@/··1·Svarar að hluta
        @/··2·Neitar að svara
        @/··3·Ófær um að svara
        @/··4·Fjarverandi næstu vikurnar
        @/··5·Búsett^ur erlendis
        @/··6.1·Dáin^n
        @/··7·Næst ekki samband"
        /"Ástæða brottfalls"
        : TBrottfall
        Athugasemd
        "^haus@/^fsvar@/^strik@/
        ^Hvaða_ástæður"
        /"Athugasemd"
        : STRING[80]

    spyrill: string
    BrottfallBokadDags : Datetype
    BrottfallBokadTimi : Timetype

    AUXFIELDS
        Hvaða_Ástæður, bKóti, honum   : STRING
        Vidbrogd "^haus@/^fsvar@/^strik@/ @GHver voru fyrst viðbrögð úrtakseiningar við þátttökubeiðninni?@g"/"Fyrstu viðbrögð" :
            TVidbrogd

    RULES
        {IF(Þ.Vidbrogd = EMPTY) THEN
            Vidbrogd.ASK
            Þ.Vidbrogd := Vidbrogd
        ENDIF}
        prc_ÞérHonumHenni (Persóna, Honum)
        Ástæða.CLASSIFY
        bKóti := ClassToStr(Ástæða)
        check
        if len(bKóti) > 0 involving (Ástæða) "Ástæða svarað" then
          position('.',bKóti) > 0 "Ástæða þarf að skrá á undirflokk"
        endif
        IF Substring(UpperCase(USERNAME),1,2) = 'V1' THEN
          IF Ástæða.Brottfall = K10 Or Ástæða.Brottfall = K11 THEN
             Ástæða.Brottfall <> K10 And Ástæða.Brottfall <> K11 "Sérmeðferð og skráning utan þýðis er aðeins fyrir umsjónarfólk!"
          ENDIF
        ENDIF
        IF Substring(bKóti,2,2)='.9' Or Substring(bKóti,3,2) = '.9' OR bKóti = '5.1' OR bKóti = '3.1'
		OR bKóti = '3.2'OR bkóti= '2.5' OR bkóti= '1.4' OR bkóti= '1.5' OR bkóti= '1.6' or bkóti = '11.4' or Substring(bKóti,1,1) = '2' THEN
          IF bKóti = '5.1' THEN
            Hvaða_Ástæður := 'Hvenær er von á ' + honum + '?'
          ELSEIF bKóti = '3.1' THEN
            Hvaða_Ástæður := 'Hvaða tungumál ? '
          ELSEIF bKóti = '3.2' THEN
            Hvaða_Ástæður := 'Skráðu hvort hægt sé að hafa samband t.d. með e-mail eða túlki?'
          ELSEIF bKóti = '2.5' THEN
            Hvaða_Ástæður := 'Ræddu þessa ákvörðun við umsjónarmann og skráið nánari útskýringar í athugasemdina?'
          ELSEIF bKóti = '1.4' THEN
            Hvaða_Ástæður := 'Hvers vegna hætti viðmælandinn að svara?'
          ELSEIF bKóti = '1.5' THEN
            Hvaða_Ástæður := 'Hvers vegna hætti viðmælandinn að svara?'
          ELSEIF bKóti = '1.6' THEN
            Hvaða_Ástæður := 'Hvers vegna hætti viðmælandinn að svara?'
          ELSE
            Hvaða_Ástæður := 'Hvaða aðrar ástæður?'
          ENDIF
          IF Substring(bKóti,1,1) = '2' AND bKóti <> '2.5' THEN Hvaða_Ástæður := 'Hvað sagði svarandi, orðrétt?'
          ENDIF
          Athugasemd
        ENDIF
    if (ástæða = response) then
        if spyrill = empty then spyrill := username endif
    endif
    if (ástæða = response) then
    if BrottfallBokadDags = empty then BrottfallBokadDags := sysdate endif
    if BrottfallBokadTimi = empty then BrottfallBokadTimi := systime endif
  endif



ENDBLOCK
