{  Milliblokk.inc
    Lífskjararannsók
    RJ (c) nóvember 2003
 Í þessari blokk er ákvarðað hvort sá sem lenti í úrtaki heldur áfram að svara eða hvort hann þurfi að ná í annan í síman t.d.
 mömmu sína eða pabba eða einhvern annan forráðamann á heimilinu}

BLOCK Milliblokk "Inngangur að seinni hlutanum"
    PARAMETERS

        IMPORT Persóna : TPersóna
        IMPORT Heimili : TJáNei
        {IMPORT NöfnHeimilisfólks : STRING }
        IMPORT ErTilHöfuð : TJáNei
        IMPORT FjöldiHeimilismanna : THmFj

    AUXFIELDS
    heimNafn         : ARRAY [2..15] OF STRING[50]
    AFjöldiHeimilismanna : THmFJ

    LOCALS
    I            : INTEGER

    FIELDS                        {Ath setja hér inn nöfn og tengsl}

      HeimSv (1a)
        "^haus@/^fsvar@/^strik@/
       Nú er komið að þeim hluta rannsóknarinnar sem snýr að húsnæði og rekstri heimilisins ^Aðsetur.endanlegt_heimilisfang.  Treystir þú þér til að svara þeim
       spurningum eða vilt þú ná í forráðarmann eða einhvern sem þekkir hemilisaðstæður betur en þú?
       @/@/@GÝttu á enter til að halda áfram.@G"
        "^haus@/^fsvar@/^strik@/
        Now we are on to the part of the survey which regards housing and household expenditure for the household at ^Aðsetur.endanlegt_heimilisfang.
        Can you answer those questions or do you want to get someone who knows more about these things to answer?
       @/@/@GÝttu á enter til að halda áfram."
        /"Næsti hluti":
        (Úrtakspersóna "Treystir sér til að svara og viðtal heldur áfram" "Can answer, continue interview",
        AnnarEkkiVið "Annar svarandi er ekki við.  Fer í viðtalsbókun" "Other respondent is not available at this time, book interview",
        AnnarVið "Nær í annan svaranda og viðtal heldur áfram" "Gets other respondent, continue interview")

      HeimSvAfram (1b)
        "^haus@/^fsvar@/^strik@/
       Nú er komið að þeim hluta rannsóknarinnar sem snýr að húsnæði og heimilisrekstri heimilisins ^Aðsetur.endanlegt_heimilisfang.
       @/@/@GÝttu á enter til að halda áfram."
        "^haus@/^fsvar@/^strik@/
        Now we are on to the part of the survey which regards housing and household expenditure of the household at ^Aðsetur.endanlegt_heimilisfang.
       @/@/@GÝttu á enter til að halda áfram."
        /"Næsti hluti"
        : STRING [1], empty

       EkkiVið (2)
        "^haus@/^fsvar@/^strik@/
        @RFarið nú í viðtalsbókun og bókið hentugan tíma fyrir seinna viðtalið?  Spyrjið hvenær líklegast sé að ná í annan svaranda
        og nafn hans.  Skráið nafn nýs svaranda í viðtalsbókunina"
        "^haus@/^fsvar@/^strik@/
        Now book an appropriate time for a later interview. Ask the name of the other respondent and when you are most likely to reach them.
        Note down the name of other respondent when booking the interview. "
        /"Ávarp 1"
        : STRING [1], empty


       Ávarp1 (3)
        "^haus@/^fsvar@/^strik@/
        Góða kvöldið / Góðan dag.  Ég heiti -------- og hringi frá Hagstofu Íslands vegna rannsóknar á Lífskjörum íslendinga.
       @R- ^nafn -@R lenti í úrtaki og fékk sent bréf fyrir skömmu þar sem þessi rannsókn er kynnt.
       @/@/@R- ^nafn -@R er búin að svara spurningunum sem snúa að henni / honum en treystir sér ekki til að svara spurningum um
        húsnæði, rekstur heimilisins og störf annara á heimilinu. Værir þú tilbúin að svara þeim spurningum ?
       @/@/@GEf viðmælandi þinn hefur ekki séð bréfið útskýrðu þá rannsóknina í stuttu máli og fáðu hann til að svara rest@G"
        "^haus@/^fsvar@/^strik@/
        Good evening. My name is ------- and am calling from Statistics Iceland because of a survey of the quality of life in Iceland.
        @R- ^nafn -@R is in our sample and received a letter recently where the survey was described.
        @/@/@R- ^nafn -@R has answered the questions which regard him / her but does not think he / she can answer questions about
        housing, household expenditure and the work of others in the home. Could you answer those questions?
        @/@/@GIf the respondent has not seen the letter then explain the survey in a few words and get them to answer the rest@G"
        /"Ávarp 1"
        : TjáNei


        NýttNafn (1ac)
        "^haus@/^fsvar@/^strik@/
        Hvað heitir þú?"
        "^haus@/^fsvar@/^strik@/
        What is your name?"
        /"Tengsl við ":
        (heim02 (2)  "^heimNafn[2]",    {Fyrsti hér fær gildið 2 því sá sem lenti í úrtakinu er alltaf númer 2}
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

     fsv_húsnæði :STRING [80]
     fsv_heilsa  :INTEGER





  LOCALS
     vinnumaður, worker : string
     stu, tu : string
     þig : string
     þú : string
     ðu : string
     n, r  : string
     you, your, yourself, do_you, were : string

    RULES
    NEWPAGE
      {prc_viðmiðunartímiUpplýst (viðmiðunardagur - (0,0,6), viðmiðunardagur, viðmiðunarvika, referenceweek)
      prc_viðmiðunartímiSpurt (viðmiðunardagur - (0,0,6), viðmiðunardagur, SíðustuViku, LastWeek)  }
      prc_stuEnding  (persóna, stu)
      prc_tuEnding   (persóna, tu)
      prc_ðuEnding   (persóna, ðu)
      prc_ÞúHannHún  (Persóna, þú)
      prc_nEnding    (Persóna, n)
      prc_rEnding    (Persóna, r)
      prc_þigsig     (Persóna, þig)
      prc_YouDoDoes (Persóna, do_you)
      prc_YouHeShe   (Persóna, You)
      prc_YourHisHer (persóna, your)
      prc_WereWas    (Persóna, were)

      AFjöldiHeimilismanna := FjöldiHeimilismanna
      FOR I := 2 TO AFjöldiHeimilismanna DO
        IF Fjölskylda.Heimilismaður[I].Brottfluttur = Nei THEN
          heimNafn[I] := Fjölskylda.Heimilismaður[I].Nafn
          IF HeimNafn[I] > '' THEN
            IF Fjölskylda.Heimilismaður[I].Tengsl = Maki THEN
              heimNafn[I] := heimNafn[I] + ', - maki'
            ELSEIF Fjölskylda.Heimilismaður[I].Tengsl = Barn THEN
              heimNafn[I] := heimNafn[I] + ', - barn'
            ELSEIF Fjölskylda.Heimilismaður[I].Tengsl = Systkini THEN
              heimNafn[I] := heimNafn[I] + ', - systkini'
            ELSEIF Fjölskylda.Heimilismaður[I].Tengsl = Systkinabarn THEN
              heimNafn[I] := heimNafn[I] + ', - systkinabarn'
            ELSEIF Fjölskylda.Heimilismaður[I].Tengsl = Foreldri THEN
              heimNafn[I] := heimNafn[I] + ', - foreldri'
            ELSEIF Fjölskylda.Heimilismaður[I].Tengsl = AfiAmma THEN
              heimNafn[I] := heimNafn[I] + ', - afi eða amma'
            ELSEIF Fjölskylda.Heimilismaður[I].Tengsl = Tengdaforeldri THEN
              heimNafn[I] := heimNafn[I] + ', - tengdaforeldri'
            ELSEIF Fjölskylda.Heimilismaður[I].Tengsl = Tengdabarn THEN
              heimNafn[I] := heimNafn[I] + ', - tengdabarn'
            ELSEIF Fjölskylda.Heimilismaður[I].Tengsl = Mágur THEN
              heimNafn[I] := heimNafn[I] + ', - mágur'
            ELSEIF Fjölskylda.Heimilismaður[I].Tengsl = Barnabarn THEN
              heimNafn[I] := heimNafn[I] + ', - barnabarn'
            ELSEIF Fjölskylda.Heimilismaður[I].Tengsl = Ættingi THEN
              heimNafn[I] := heimNafn[I] + ', - ættingi'
            ELSEIF Fjölskylda.Heimilismaður[I].Tengsl = Óskyldur THEN
              heimNafn[I] := heimNafn[I] + ', - óskyldur'
            ENDIF
          ENDIF
        ENDIF
      ENDDO


IF ErTilHöfuð = Já THEN
  Heimsv
ELSE
  HeimSvAfram
ENDIF

IF Heimsv = AnnarEkkiVið THEN
ekkivið
ENDIF
IF Heimsv = AnnarVið THEN
  Ávarp1
  IF ávarp1=já THEN
  NýttNafn
  ENDIF
  SIGNAL (ávarp1 = já) "Ef viðkomandi vill ekki halda áfram farðu þá í brottfall og veldu ástæðu "
ENDIF
LAYOUT
AT BLOCKSTART
INFOPANE Adalskjar {adalskjarTveirdalkar}
ENDBLOCK
