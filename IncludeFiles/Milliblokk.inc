{  Milliblokk.inc
    L�fskjararanns�k
    RJ (c) n�vember 2003
 � �essari blokk er �kvar�a� hvort s� sem lenti � �rtaki heldur �fram a� svara e�a hvort hann �urfi a� n� � annan � s�man t.d.
 m�mmu s�na e�a pabba e�a einhvern annan forr��amann � heimilinu}

BLOCK Milliblokk "Inngangur a� seinni hlutanum"
    PARAMETERS

        IMPORT Pers�na : TPers�na
        IMPORT Heimili : TJ�Nei
        {IMPORT N�fnHeimilisf�lks : STRING }
        IMPORT ErTilH�fu� : TJ�Nei
        IMPORT Fj�ldiHeimilismanna : THmFj

    AUXFIELDS
    heimNafn         : ARRAY [2..15] OF STRING[50]
    AFj�ldiHeimilismanna : THmFJ

    LOCALS
    I            : INTEGER

    FIELDS                        {Ath setja h�r inn n�fn og tengsl}

      HeimSv (1a)
        "^haus@/^fsvar@/^strik@/
       N� er komi� a� �eim hluta ranns�knarinnar sem sn�r a� h�sn��i og rekstri heimilisins ^A�setur.endanlegt_heimilisfang.  Treystir �� ��r til a� svara �eim
       spurningum e�a vilt �� n� � forr��armann e�a einhvern sem �ekkir hemilisa�st��ur betur en ��?
       @/@/@G�ttu � enter til a� halda �fram.@G"
        "^haus@/^fsvar@/^strik@/
        Now we are on to the part of the survey which regards housing and household expenditure for the household at ^A�setur.endanlegt_heimilisfang.
        Can you answer those questions or do you want to get someone who knows more about these things to answer?
       @/@/@G�ttu � enter til a� halda �fram."
        /"N�sti hluti":
        (�rtakspers�na "Treystir s�r til a� svara og vi�tal heldur �fram" "Can answer, continue interview",
        AnnarEkkiVi� "Annar svarandi er ekki vi�.  Fer � vi�talsb�kun" "Other respondent is not available at this time, book interview",
        AnnarVi� "N�r � annan svaranda og vi�tal heldur �fram" "Gets other respondent, continue interview")

      HeimSvAfram (1b)
        "^haus@/^fsvar@/^strik@/
       N� er komi� a� �eim hluta ranns�knarinnar sem sn�r a� h�sn��i og heimilisrekstri heimilisins ^A�setur.endanlegt_heimilisfang.
       @/@/@G�ttu � enter til a� halda �fram."
        "^haus@/^fsvar@/^strik@/
        Now we are on to the part of the survey which regards housing and household expenditure of the household at ^A�setur.endanlegt_heimilisfang.
       @/@/@G�ttu � enter til a� halda �fram."
        /"N�sti hluti"
        : STRING [1], empty

       EkkiVi� (2)
        "^haus@/^fsvar@/^strik@/
        @RFari� n� � vi�talsb�kun og b�ki� hentugan t�ma fyrir seinna vi�tali�?  Spyrji� hven�r l�klegast s� a� n� � annan svaranda
        og nafn hans.  Skr�i� nafn n�s svaranda � vi�talsb�kunina"
        "^haus@/^fsvar@/^strik@/
        Now book an appropriate time for a later interview. Ask the name of the other respondent and when you are most likely to reach them.
        Note down the name of other respondent when booking the interview. "
        /"�varp 1"
        : STRING [1], empty


       �varp1 (3)
        "^haus@/^fsvar@/^strik@/
        G��a kv�ldi� / G��an dag.  �g heiti -------- og hringi fr� Hagstofu �slands vegna ranns�knar � L�fskj�rum �slendinga.
       @R- ^nafn -@R lenti � �rtaki og f�kk sent br�f fyrir sk�mmu �ar sem �essi ranns�kn er kynnt.
       @/@/@R- ^nafn -@R er b�in a� svara spurningunum sem sn�a a� henni / honum en treystir s�r ekki til a� svara spurningum um
        h�sn��i, rekstur heimilisins og st�rf annara � heimilinu. V�rir �� tilb�in a� svara �eim spurningum ?
       @/@/@GEf vi�m�landi �inn hefur ekki s�� br�fi� �tsk�r�u �� ranns�knina � stuttu m�li og f��u hann til a� svara rest@G"
        "^haus@/^fsvar@/^strik@/
        Good evening. My name is ------- and am calling from Statistics Iceland because of a survey of the quality of life in Iceland.
        @R- ^nafn -@R is in our sample and received a letter recently where the survey was described.
        @/@/@R- ^nafn -@R has answered the questions which regard him / her but does not think he / she can answer questions about
        housing, household expenditure and the work of others in the home. Could you answer those questions?
        @/@/@GIf the respondent has not seen the letter then explain the survey in a few words and get them to answer the rest@G"
        /"�varp 1"
        : Tj�Nei


        N�ttNafn (1ac)
        "^haus@/^fsvar@/^strik@/
        Hva� heitir ��?"
        "^haus@/^fsvar@/^strik@/
        What is your name?"
        /"Tengsl vi� ":
        (heim02 (2)  "^heimNafn[2]",    {Fyrsti h�r f�r gildi� 2 �v� s� sem lenti � �rtakinu er alltaf n�mer 2}
         heim03  "^heimNafn[3]",
         heim04  "^heimNafn[4]",
         heim05  "^heimNafn[5]",
         heim06  "^heimNafn[6]",
         heim07  "^heimNafn[7]",
         heim08  "^heimNafn[8]",
         heim09  "^heimNafn[9]",
         heim10  "^heimNafn[10]",
         heim11  "^heimNafn[11]",
         heim12  "^heimNafn[12]",
         heim13  "^heimNafn[13]",
         heim14  "^heimNafn[14]",
         heim15  "^heimNafn[15]")

     fsv_h�sn��i :STRING [80]
     fsv_heilsa  :INTEGER





  LOCALS
     vinnuma�ur, worker : string
     stu, tu : string
     �ig : string
     �� : string
     �u : string
     n, r  : string
     you, your, yourself, do_you, were : string

    RULES
    NEWPAGE
      {prc_vi�mi�unart�miUppl�st (vi�mi�unardagur - (0,0,6), vi�mi�unardagur, vi�mi�unarvika, referenceweek)
      prc_vi�mi�unart�miSpurt (vi�mi�unardagur - (0,0,6), vi�mi�unardagur, S��ustuViku, LastWeek)  }
      prc_stuEnding  (pers�na, stu)
      prc_tuEnding   (pers�na, tu)
      prc_�uEnding   (pers�na, �u)
      prc_��HannH�n  (Pers�na, ��)
      prc_nEnding    (Pers�na, n)
      prc_rEnding    (Pers�na, r)
      prc_�igsig     (Pers�na, �ig)
      prc_YouDoDoes (Pers�na, do_you)
      prc_YouHeShe   (Pers�na, You)
      prc_YourHisHer (pers�na, your)
      prc_WereWas    (Pers�na, were)

      AFj�ldiHeimilismanna := Fj�ldiHeimilismanna
      FOR I := 2 TO AFj�ldiHeimilismanna DO
        IF Fj�lskylda.Heimilisma�ur[I].Brottfluttur = Nei THEN
          heimNafn[I] := Fj�lskylda.Heimilisma�ur[I].Nafn
          IF HeimNafn[I] > '' THEN
            IF Fj�lskylda.Heimilisma�ur[I].Tengsl = Maki THEN
              heimNafn[I] := heimNafn[I] + ', - maki'
            ELSEIF Fj�lskylda.Heimilisma�ur[I].Tengsl = Barn THEN
              heimNafn[I] := heimNafn[I] + ', - barn'
            ELSEIF Fj�lskylda.Heimilisma�ur[I].Tengsl = Systkini THEN
              heimNafn[I] := heimNafn[I] + ', - systkini'
            ELSEIF Fj�lskylda.Heimilisma�ur[I].Tengsl = Systkinabarn THEN
              heimNafn[I] := heimNafn[I] + ', - systkinabarn'
            ELSEIF Fj�lskylda.Heimilisma�ur[I].Tengsl = Foreldri THEN
              heimNafn[I] := heimNafn[I] + ', - foreldri'
            ELSEIF Fj�lskylda.Heimilisma�ur[I].Tengsl = AfiAmma THEN
              heimNafn[I] := heimNafn[I] + ', - afi e�a amma'
            ELSEIF Fj�lskylda.Heimilisma�ur[I].Tengsl = Tengdaforeldri THEN
              heimNafn[I] := heimNafn[I] + ', - tengdaforeldri'
            ELSEIF Fj�lskylda.Heimilisma�ur[I].Tengsl = Tengdabarn THEN
              heimNafn[I] := heimNafn[I] + ', - tengdabarn'
            ELSEIF Fj�lskylda.Heimilisma�ur[I].Tengsl = M�gur THEN
              heimNafn[I] := heimNafn[I] + ', - m�gur'
            ELSEIF Fj�lskylda.Heimilisma�ur[I].Tengsl = Barnabarn THEN
              heimNafn[I] := heimNafn[I] + ', - barnabarn'
            ELSEIF Fj�lskylda.Heimilisma�ur[I].Tengsl = �ttingi THEN
              heimNafn[I] := heimNafn[I] + ', - �ttingi'
            ELSEIF Fj�lskylda.Heimilisma�ur[I].Tengsl = �skyldur THEN
              heimNafn[I] := heimNafn[I] + ', - �skyldur'
            ENDIF
          ENDIF
        ENDIF
      ENDDO


IF ErTilH�fu� = J� THEN
  Heimsv
ELSE
  HeimSvAfram
ENDIF

IF Heimsv = AnnarEkkiVi� THEN
ekkivi�
ENDIF
IF Heimsv = AnnarVi� THEN
  �varp1
  IF �varp1=j� THEN
  N�ttNafn
  ENDIF
  SIGNAL (�varp1 = j�) "Ef vi�komandi vill ekki halda �fram far�u �� � brottfall og veldu �st��u "
ENDIF
LAYOUT
AT BLOCKSTART
INFOPANE Adalskjar {adalskjarTveirdalkar}
ENDBLOCK
