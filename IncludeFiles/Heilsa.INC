BLOCK BHeilsa

 PARAMETERS
 IMPORT AldurBarns : integer

AUXFIELDS
Heilsukynning           "^haus@/^fsvar@/^strik@/
                        Næst eru nokkrar spurningar um heilsufar ^þitt og not ^þín á heilbrigðisþjónustu "
                        "^haus@/^fsvar@/^strik@/
                        Next are few questions on ^your health and ^your use of healthcare services?"
                        /"kynning": STRING [1],empty
FIELDS
  Heilsasíðast (HV0)              {Ef já hérna þá hoppað í HV5a}
   "^haus@/^fsvar@/^strik@/
     @GHeilsufar  @|: ^fsv_HHeilsa @/@/@G
     Þegar við töluðum við ^þig fyrir ári síðan sagðir ^þú okkur að ^þú væri við @R< ^fsv_HHeilsa >@R heilsu@/
     @/Er heilsufar ^þitt eins núna ?"
    "^haus@/^fsvar@/^strik@/
     @GHealth      @|: ^fsv_HHeilsa @/@/@G
     When we spoke to you a year ago you informed us that you were in @R< ^fsv_HHeilsa >@R health @/
     @/Is your health the same now ?"
     /"Sama og síðast"
     : TFsv_heilsa_sama

  HV1 (Heil1)        "^haus@/^fsvar@/^strik@/
                        Almennt séð finnst ^þérhonum ^þú vera við mjög góða, góða, sæmilega, slæma eða mjög slæma heilsu?"
                        "^haus@/^fsvar@/^strik@/
                        How is your health in general? Is it..."
                        / "Heilsufar almennt":
                        (Mjög "Mjög góða"  "...very good",
                        Góð "Góða" "...good",
                        Sæmilega "Sæmilega" "...fair",
                        Slæma "Slæma" "...poor",
                        Afleita "Mjög slæma" "...very Poor")


  HV3 (Heil3)         "^haus@/^fsvar@/^strik@/
                        Ert ^þú með einhver langvarandi veikindi eða heilsufarsleg vandamál. Með langvarandi er átt við veikindi eða vandamál sem
                        hafa varað eða er reiknað með að muni vara í 6 mánuði eða lengur?"
                        "^haus@/^fsvar@/^strik@/
                        Do you have any longstanding illness or health problems? By longstanding I mean illness or health problems which have lasted or are expected to last for 6 months or more"
                        / "Vanlíðan":
                        TJáNei
  HV4a                  "^haus@/^fsvar@/^strik@/
                        Undanfarna sex mánuði eða lengur hefur heilsufarslegt vandamál takmarkað ^þighann á einhvern hátt í einhverju sem reikna má með
                        að flest fólk geti gert?"
                        "^haus@/^fsvar@/^strik@/
                        For at least the past 6 months, have you been limited in activities people usually do because of a health problem?"
                         / "Hamlandi ástand já/nei":
                         TJáNei

   HV4b         "^haus@/^fsvar@/^strik@/
                        Myndir þú segja að þessar takmarkanir væru alvarlegar?"
                        "^haus@/^fsvar@/^strik@/
                        Would you say you have been strongly limited or somewhat limited?"
                        / "Hamlandi ástand":
                        (Mikið "Já, alvarlegar" "Strongly limited",
                        Nokkuð "Nei, ekki alvarlegar" "Somewhat limited")

  HV5a (Heil5a)      "^haus@/^fsvar@/^strik@/
                        Voru einhver tilvik á síðustu 12 mánuðum þar sem ^þú leitaðir ekki til læknis, sérfræðings
                        eða þess háttar @uheilsu ^þinnar vegna@u þótt ^þú hafir þurft á því að halda?"
                        "^haus@/^fsvar@/^strik@/
                        During the past 12 months did ^you need to go to a doctor, a specialist or simular because of @u ^your own health@u, but did not go?"
                        /  "Læknisþörf":
                        (já "já, einu sinni eða oftar" "Yes, once or more often",
                        nei "nei, aldrei" "no, never")

  HV5b (Heil5b)      "^haus@/^fsvar@/^strik@/
                        Hver er aðal ástæðan fyrir því að ^þú leitaðir ekki til læknis eða sérfræðings?
                        @/@/@GEkki lesa upp svarkosti@G"
                        "^haus@/^fsvar@/^strik@/
                        What was the main reason that you did not to go?
                        @/@/@GEkki lesa upp svarkosti@G"
                        / "Hvers vegna ekki":
                        (Dýrt "Hafði ekki efni ráð á því, of dýrt" "Could not afford it, too expensive",
                        Biðlisti "Biðlisti" "Waiting list",
                        Vinna "Komst ekki frá vinnu eða börnum" "Could not get time off work / away from children",
                        Langt "Of langt ferðalag / Vantar samgöngur" "Journey too long / insufficient transportation",
                        Ótti "Ótti við lækna / spítala / rannsóknir eða meðferðir" "Fear of physicians / hospitals / tests or treatments",
                        Bíða "Vildi bíða og sjá hvort vandamálið lagaðist ekki af sjálfu sér" "Wanted to wait and see whether the problem would heal by itself",
                        Óvissa "Vissi ekki um góðan lækni eða sérfræðing" "Did not know of a good physician or specialist",
                        Annað "Aðrar ástæður" "Other reasons")

  HV5c (Heil5c)      "^haus@/^fsvar@/^strik@/
                        Hvaða ástæða er það?"
                        "^haus@/^fsvar@/^strik@/
                        What was the reason?" / "Önnur ástæða": STRING [50]

  HV6a (Heil6a)      "^haus@/^fsvar@/^strik@/
                        Voru einhver tilvik á síðustu 12 mánuðum þar sem ^þú leitaðir @Uekki@U til tannlæknis, vegna ^þinnar eigin tannheilsu, þótt ^þú hafir þurft á því að halda?"
                        "^haus@/^fsvar@/^strik@/
                        During the past 12 months, did you need to go to a dentist but @udid not@u go?" / "Tannlæknir":
                        TJáNei

  HV6b (Heil6b)      "^haus@/^fsvar@/^strik@/
                        Hver var aðalástæðan fyrir því að ^þú leitaðir ekki til tannlæknis
                        @/@/@GEkki lesa upp svarkosti@G"
                        "^haus@/^fsvar@/^strik@/
                        What was the main reason that you did not go to a dentist?
                        @/@/@GEkki lesa upp svarkosti@G"
                        / "Ekki tannlæknir":
                        (Dýrt "Hafði ekki ráð á því, of dýrt" "Could not afford it, too expensive",
                        Biðlisti "Biðlisti" "Waiting list",
                        Vinna "Komst ekki frá vinnu eða börnum" "Could not get time off work / away from children",
                        Langt "Of langt ferðalag / Vantar samgöngur" "Journey too long / insufficient transportation",
                        Ótti "Ótti við tannlækna" "Fear of dentists",
                        Bíða "Vildi bíða og sjá hvort vandamálið lagaðist ekki af sjálfu sér" "Wanted to wait and see whether the problem would be solved by itself",
                        Óvissa "Vissi ekki um neinn tannlækni" "Did not know of a dentist",
                        Annað "Aðrar ástæður" "Other reasons")

  HV6c (Heil6c)      "^haus@/^fsvar@/^strik@/
                        Hvaða ástæða er það?"
                        "^haus@/^fsvar@/^strik@/
                        What was the reason?" / "Önnur ástæða": STRING [50]

LOCALS
     stu, tu, ttu : string
     þig, þér, þinnar : string
     Áttu, þú, þína, þínum, þitt, þín, þúgast, störfumþínum, heilsuþína, þérhonum, þighann: string
     ðu : string
     n, r  : string
     you, your, yourself, do_you, were : string

RULES

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
   prc_ÞínaHansHennar (Persóna, þína)
   prc_ttuEnding (persóna, Áttu)
   prc_ÞérSér (Persóna, þér)
   prc_ÞínumHansHennar(Persóna, þínum)
   prc_ÞittHansHennar (Persóna, þitt)
   prc_ÞínHansHennar (persóna, þín)
   prc_ÞúGast (persóna, þúgast)
   prc_StörfumÞínum (persóna, störfumþínum)
   prc_HeilsuÞína (persóna, heilsuþína)
   prc_ÞérHonumHenni (persóna, þérhonum)
   prc_ÞigHannHana  (persóna, þighann)
   prc_Þinnar     (persóna, þinnar)

  Heilsukynning
  HV1
  HV3
  HV4a
  if HV4a = já then
    HV4b
  endif
  HV6a
  IF HV6a = já
    THEN HV6b
            IF HV6b = annað
                then HV6c
            ENDIF
  ENDIF
  HV5a
  IF HV5a = já
    THEN HV5b
            IF HV5b = annað
                then HV5c
            ENDIF
  ENDIF
ENDBLOCK
