{   BBrottfall.inc
    �H (c) 17. n�vember 2002

}

BLOCK BBrottfall "Brottfall"

    FIELDS

        �st��a
        "^haus@/^fsvar@/^strik@/
        �st��a brottfallsins?
	@/��1�Svarar a� hluta
        @/��2�Neitar a� svara
        @/��3��f�r um a� svara
        @/��4�Fjarverandi n�stu vikurnar
        @/��5�B�sett^ur erlendis
        @/��6.1�D�in^n
        @/��7�N�st ekki samband"
        /"�st��a brottfalls"
        : TBrottfall
        Athugasemd
        "^haus@/^fsvar@/^strik@/
        ^Hva�a_�st��ur"
        /"Athugasemd"
        : STRING[80]

    spyrill: string
    BrottfallBokadDags : Datetype
    BrottfallBokadTimi : Timetype

    AUXFIELDS
        Hva�a_�st��ur, bK�ti, honum   : STRING
        Vidbrogd "^haus@/^fsvar@/^strik@/ @GHver voru fyrst vi�br�g� �rtakseiningar vi� ��ttt�kubei�ninni?@g"/"Fyrstu vi�br�g�" :
            TVidbrogd

    RULES
        {IF(�.Vidbrogd = EMPTY) THEN
            Vidbrogd.ASK
            �.Vidbrogd := Vidbrogd
        ENDIF}
        prc_��rHonumHenni (Pers�na, Honum)
        �st��a.CLASSIFY
        bK�ti := ClassToStr(�st��a)
        check
        if len(bK�ti) > 0 involving (�st��a) "�st��a svara�" then
          position('.',bK�ti) > 0 "�st��a �arf a� skr� � undirflokk"
        endif
        IF Substring(UpperCase(USERNAME),1,2) = 'V1' THEN
          IF �st��a.Brottfall = K10 Or �st��a.Brottfall = K11 THEN
             �st��a.Brottfall <> K10 And �st��a.Brottfall <> K11 "S�rme�fer� og skr�ning utan ���is er a�eins fyrir umsj�narf�lk!"
          ENDIF
        ENDIF
        IF Substring(bK�ti,2,2)='.9' Or Substring(bK�ti,3,2) = '.9' OR bK�ti = '5.1' OR bK�ti = '3.1'
		OR bK�ti = '3.2'OR bk�ti= '2.5' OR bk�ti= '1.4' OR bk�ti= '1.5' OR bk�ti= '1.6' or bk�ti = '11.4' or Substring(bK�ti,1,1) = '2' THEN
          IF bK�ti = '5.1' THEN
            Hva�a_�st��ur := 'Hven�r er von � ' + honum + '?'
          ELSEIF bK�ti = '3.1' THEN
            Hva�a_�st��ur := 'Hva�a tungum�l ? '
          ELSEIF bK�ti = '3.2' THEN
            Hva�a_�st��ur := 'Skr��u hvort h�gt s� a� hafa samband t.d. me� e-mail e�a t�lki?'
          ELSEIF bK�ti = '2.5' THEN
            Hva�a_�st��ur := 'R�ddu �essa �kv�r�un vi� umsj�narmann og skr�i� n�nari �tsk�ringar � athugasemdina?'
          ELSEIF bK�ti = '1.4' THEN
            Hva�a_�st��ur := 'Hvers vegna h�tti vi�m�landinn a� svara?'
          ELSEIF bK�ti = '1.5' THEN
            Hva�a_�st��ur := 'Hvers vegna h�tti vi�m�landinn a� svara?'
          ELSEIF bK�ti = '1.6' THEN
            Hva�a_�st��ur := 'Hvers vegna h�tti vi�m�landinn a� svara?'
          ELSE
            Hva�a_�st��ur := 'Hva�a a�rar �st��ur?'
          ENDIF
          IF Substring(bK�ti,1,1) = '2' AND bK�ti <> '2.5' THEN Hva�a_�st��ur := 'Hva� sag�i svarandi, or�r�tt?'
          ENDIF
          Athugasemd
        ENDIF
    if (�st��a = response) then
        if spyrill = empty then spyrill := username endif
    endif
    if (�st��a = response) then
    if BrottfallBokadDags = empty then BrottfallBokadDags := sysdate endif
    if BrottfallBokadTimi = empty then BrottfallBokadTimi := systime endif
  endif



ENDBLOCK
