BLOCK BHeilsa

 PARAMETERS
 IMPORT AldurBarns : integer

AUXFIELDS
Heilsukynning           "^haus@/^fsvar@/^strik@/
                        N�st eru nokkrar spurningar um heilsufar ^�itt og not ^��n � heilbrig�is�j�nustu "
                        "^haus@/^fsvar@/^strik@/
                        Next are few questions on ^your health and ^your use of healthcare services?"
                        /"kynning": STRING [1],empty
FIELDS
  Heilsas��ast (HV0)              {Ef j� h�rna �� hoppa� � HV5a}
   "^haus@/^fsvar@/^strik@/
     @GHeilsufar  @|: ^fsv_HHeilsa @/@/@G
     �egar vi� t�lu�um vi� ^�ig fyrir �ri s��an sag�ir ^�� okkur a� ^�� v�ri vi� @R< ^fsv_HHeilsa >@R heilsu@/
     @/Er heilsufar ^�itt eins n�na ?"
    "^haus@/^fsvar@/^strik@/
     @GHealth      @|: ^fsv_HHeilsa @/@/@G
     When we spoke to you a year ago you informed us that you were in @R< ^fsv_HHeilsa >@R health @/
     @/Is your health the same now ?"
     /"Sama og s��ast"
     : TFsv_heilsa_sama

  HV1 (Heil1)        "^haus@/^fsvar@/^strik@/
                        Almennt s�� finnst ^��rhonum ^�� vera vi� mj�g g��a, g��a, s�milega, sl�ma e�a mj�g sl�ma heilsu?"
                        "^haus@/^fsvar@/^strik@/
                        How is your health in general? Is it..."
                        / "Heilsufar almennt":
                        (Mj�g "Mj�g g��a"  "...very good",
                        G�� "G��a" "...good",
                        S�milega "S�milega" "...fair",
                        Sl�ma "Sl�ma" "...poor",
                        Afleita "Mj�g sl�ma" "...very Poor")


  HV3 (Heil3)         "^haus@/^fsvar@/^strik@/
                        Ert ^�� me� einhver langvarandi veikindi e�a heilsufarsleg vandam�l. Me� langvarandi er �tt vi� veikindi e�a vandam�l sem
                        hafa vara� e�a er reikna� me� a� muni vara � 6 m�nu�i e�a lengur?"
                        "^haus@/^fsvar@/^strik@/
                        Do you have any longstanding illness or health problems? By longstanding I mean illness or health problems which have lasted or are expected to last for 6 months or more"
                        / "Vanl��an":
                        TJ�Nei
  HV4a                  "^haus@/^fsvar@/^strik@/
                        Undanfarna sex m�nu�i e�a lengur hefur heilsufarslegt vandam�l takmarka� ^�ighann � einhvern h�tt � einhverju sem reikna m� me�
                        a� flest f�lk geti gert?"
                        "^haus@/^fsvar@/^strik@/
                        For at least the past 6 months, have you been limited in activities people usually do because of a health problem?"
                         / "Hamlandi �stand j�/nei":
                         TJ�Nei

   HV4b         "^haus@/^fsvar@/^strik@/
                        Myndir �� segja a� �essar takmarkanir v�ru alvarlegar?"
                        "^haus@/^fsvar@/^strik@/
                        Would you say you have been strongly limited or somewhat limited?"
                        / "Hamlandi �stand":
                        (Miki� "J�, alvarlegar" "Strongly limited",
                        Nokku� "Nei, ekki alvarlegar" "Somewhat limited")

  HV5a (Heil5a)      "^haus@/^fsvar@/^strik@/
                        Voru einhver tilvik � s��ustu 12 m�nu�um �ar sem ^�� leita�ir ekki til l�knis, s�rfr��ings
                        e�a �ess h�ttar @uheilsu ^�innar vegna@u ��tt ^�� hafir �urft � �v� a� halda?"
                        "^haus@/^fsvar@/^strik@/
                        During the past 12 months did ^you need to go to a doctor, a specialist or simular because of @u ^your own health@u, but did not go?"
                        /  "L�knis��rf":
                        (j� "j�, einu sinni e�a oftar" "Yes, once or more often",
                        nei "nei, aldrei" "no, never")

  HV5b (Heil5b)      "^haus@/^fsvar@/^strik@/
                        Hver er a�al �st��an fyrir �v� a� ^�� leita�ir ekki til l�knis e�a s�rfr��ings?
                        @/@/@GEkki lesa upp svarkosti@G"
                        "^haus@/^fsvar@/^strik@/
                        What was the main reason that you did not to go?
                        @/@/@GEkki lesa upp svarkosti@G"
                        / "Hvers vegna ekki":
                        (D�rt "Haf�i ekki efni r�� � �v�, of d�rt" "Could not afford it, too expensive",
                        Bi�listi "Bi�listi" "Waiting list",
                        Vinna "Komst ekki fr� vinnu e�a b�rnum" "Could not get time off work / away from children",
                        Langt "Of langt fer�alag / Vantar samg�ngur" "Journey too long / insufficient transportation",
                        �tti "�tti vi� l�kna / sp�tala / ranns�knir e�a me�fer�ir" "Fear of physicians / hospitals / tests or treatments",
                        B��a "Vildi b��a og sj� hvort vandam�li� laga�ist ekki af sj�lfu s�r" "Wanted to wait and see whether the problem would heal by itself",
                        �vissa "Vissi ekki um g��an l�kni e�a s�rfr��ing" "Did not know of a good physician or specialist",
                        Anna� "A�rar �st��ur" "Other reasons")

  HV5c (Heil5c)      "^haus@/^fsvar@/^strik@/
                        Hva�a �st��a er �a�?"
                        "^haus@/^fsvar@/^strik@/
                        What was the reason?" / "�nnur �st��a": STRING [50]

  HV6a (Heil6a)      "^haus@/^fsvar@/^strik@/
                        Voru einhver tilvik � s��ustu 12 m�nu�um �ar sem ^�� leita�ir @Uekki@U til tannl�knis, vegna ^�innar eigin tannheilsu, ��tt ^�� hafir �urft � �v� a� halda?"
                        "^haus@/^fsvar@/^strik@/
                        During the past 12 months, did you need to go to a dentist but @udid not@u go?" / "Tannl�knir":
                        TJ�Nei

  HV6b (Heil6b)      "^haus@/^fsvar@/^strik@/
                        Hver var a�al�st��an fyrir �v� a� ^�� leita�ir ekki til tannl�knis
                        @/@/@GEkki lesa upp svarkosti@G"
                        "^haus@/^fsvar@/^strik@/
                        What was the main reason that you did not go to a dentist?
                        @/@/@GEkki lesa upp svarkosti@G"
                        / "Ekki tannl�knir":
                        (D�rt "Haf�i ekki r�� � �v�, of d�rt" "Could not afford it, too expensive",
                        Bi�listi "Bi�listi" "Waiting list",
                        Vinna "Komst ekki fr� vinnu e�a b�rnum" "Could not get time off work / away from children",
                        Langt "Of langt fer�alag / Vantar samg�ngur" "Journey too long / insufficient transportation",
                        �tti "�tti vi� tannl�kna" "Fear of dentists",
                        B��a "Vildi b��a og sj� hvort vandam�li� laga�ist ekki af sj�lfu s�r" "Wanted to wait and see whether the problem would be solved by itself",
                        �vissa "Vissi ekki um neinn tannl�kni" "Did not know of a dentist",
                        Anna� "A�rar �st��ur" "Other reasons")

  HV6c (Heil6c)      "^haus@/^fsvar@/^strik@/
                        Hva�a �st��a er �a�?"
                        "^haus@/^fsvar@/^strik@/
                        What was the reason?" / "�nnur �st��a": STRING [50]

LOCALS
     stu, tu, ttu : string
     �ig, ��r, �innar : string
     �ttu, ��, ��na, ��num, �itt, ��n, ��gast, st�rfum��num, heilsu��na, ��rhonum, �ighann: string
     �u : string
     n, r  : string
     you, your, yourself, do_you, were : string

RULES

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
   prc_��naHansHennar (Pers�na, ��na)
   prc_ttuEnding (pers�na, �ttu)
   prc_��rS�r (Pers�na, ��r)
   prc_��numHansHennar(Pers�na, ��num)
   prc_�ittHansHennar (Pers�na, �itt)
   prc_��nHansHennar (pers�na, ��n)
   prc_��Gast (pers�na, ��gast)
   prc_St�rfum��num (pers�na, st�rfum��num)
   prc_Heilsu��na (pers�na, heilsu��na)
   prc_��rHonumHenni (pers�na, ��rhonum)
   prc_�igHannHana  (pers�na, �ighann)
   prc_�innar     (pers�na, �innar)

  Heilsukynning
  HV1
  HV3
  HV4a
  if HV4a = j� then
    HV4b
  endif
  HV6a
  IF HV6a = j�
    THEN HV6b
            IF HV6b = anna�
                then HV6c
            ENDIF
  ENDIF
  HV5a
  IF HV5a = j�
    THEN HV5b
            IF HV5b = anna�
                then HV5c
            ENDIF
  ENDIF
ENDBLOCK
