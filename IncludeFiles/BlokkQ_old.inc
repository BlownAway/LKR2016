{   BlokkQ.inc
    SILC
    RJ (c) nóvember 2004
 }

EMBEDDED BLOCK BlokkQ "Staða á síðasta ári"
  PARAMETERS
  IMPORT viðmiðunardagur : datetype
  IMPORT persóna         : TPersóna
  import aldur           : integer
  import vinnandi        : TJáNei
   { Merkja þarf að minnsta kosti einu sinni við hvern mánuð ársins, annars er ekki hægt að halda áfram með viðtalið.} 

   

   FIELDS
      AÁrið (E02)  {SILC spurning}
        "Nú ætla ég að spyrja þig um stöðu ^þína síðasta ár, frá janúar til desember.
         Ég vil biðja þig um að nefna allt sem átti við um ^þig á síðasta ári,
         jafnvel þótt það hafi bara verið í stuttan tíma.
         Var^stu ...    
   @/@/@GEf vefst fyrir svaranda að greina á milli, þá telst hann vera
         í fullu starfi ef hann vinnur 35 klukkustundir eða meira á viku annars í hlutastarfi.@G
   @/@/@GMunið að setja - á milli valkosta ef þið notið lyklaborðið.@G
   @/@/@GSpyrlar, ef viðkomandi segist vera á milli starfa fáið þá nánari útskýringu á því.@G"

        "Now I will ask about ^your status over the course of last year, from january to december.
         In what position were ^you?
   @/@/@GEf vefst fyrir svaranda að greina á milli, þá telst hann vera
         í fullu starfi ef hann vinnur 35 klukkustundir eða meira á viku annars í hlutastarfi.@G
   @/@/@GMunið að setja - á milli valkosta ef þið notið lyklaborðið.@G
   @/@/@GSpyrlar, ef viðkomandi segist vera á milli starfa fáið þá nánari útskýringu á því.@G"
        /"Staða á árinu"
        : SET OF (starfandi        (11) "Launþegi í fullu starfi" "Full time employment",
                  í_hlutastarfi    (12) "Launþegi í hlutastarfi"  "Part time employment",
                  sjalfst_fullt    (13) "Sjálfstætt starfandi í fullu starfi" "Full time self-employed",  {nýtt fyrir SILC2010; AÖK 13.01.10}
                  sjalfst_hluta    (14) "Sjálfstætt starfandi í hlutastarfi" "Part time self-employed",   {nýtt fyrir SILC2010; AÖK 13.01.10}
                  atvinnulaus      (15) "atvinnulaus" "Unemployed",
                  í_fæðingarorlofi (16)  "^orlof" "^orlof_en",
                  í_námi           (17) "í námi" "In education",
                 {lífeyrisþegi (6) "elli- eða örorkulífeyrisþegi" "Pensioner, old age or disability allowance",}  {tekið úr úr SILC2010; AÖK 04.02.10}
                  ellilifeyrir      (18) "^ellilif" "^ellilif_en",  {nýtt fyrir SILC2010; AÖK 04.02.10}
                  ororkulifeyrir    (19) "örorkulífeyrisþegi" "Did you receive disability pension?",{nýtt fyrir SILC2010; AÖK 04.02.10}
                  heimavinnandi     (20)  "heimavinnandi" "working at home?",
                  veikur            (21) "Veik^ur" "Ill (unable to work)",
                  annað             (22) "annað" "Other")

      AMánuðir_fullt
        "Hvaða mánuði ^ársins var^st ^þú launþegi í fullu starfi?"
        "Which months last year w^ere ^you working full time?"
        / "Mánuðir fullt" :
        set of TMánuðir_allt_árið

      AMánuðir_hluta
        "Hvaða mánuði ^ársins var^st ^þú launþegi í hlutastarfi?"
        "Which months last year w^ere ^you working part time?"
        / "Mánuðir hlutastarf" :
        set of TMánuðir_allt_árið


      AMánuðir_fæðingarorlof
        "Hvaða mánuði ^ársins var^st ^þú í fæðingarorlofi?"
        "Which months last year w^ere ^you on maternity / paternity leave?"
        / "Mánuðir fæðingarorlof" :
        set of TMánuðir_allt_árið

      AMánuðir_atvinnulaus
        "Hvaða mánuði ^ársins var^st ^þú atvinnulaus?"
        "Which months last year w^ere ^you unemployed?"
        / "Mánuðir atvinnulaus" :
        set of TMánuðir_allt_árið

      AMánuðir_námi
        "Hvaða mánuði ^ársins var^st ^þú í námi?"
        "Which months last year w^ere ^you studying?"
        / "Mánuðir í námi" :
        set of TMánuðir_allt_árið

    {  AMánuðir_lífeyrisþegi
        "^haus@/^fsvar@/^strik@/
     Hvaða mánuði árið 2010 var^st ^þú lífeyrisþegi?"
        "^haus@/^fsvar@/^strik@/
     Which months last year ^were ^you retired from paid work?"
        / "Mánuðir lífeyrisþegi" :
        set of TMánuðir_allt_árið}

      AMánuðir_heimavinnandi
        "Hvaða mánuði ^ársins var^st ^þú heimavinnandi?"
        "Which months last year w^ere ^you working at home?"
        / "Mánuðir heimavinnandi" :
        set of TMánuðir_allt_árið

      AMánuðir_veikur
        "Hvaða mánuði ^ársins var^st ^þú veikur?"
        "Which months last year w^ere ^you sick or unable to work?"
        / "Mánuðir veikur" :
        set of TMánuðir_allt_árið

      AMánuðir_annað
        "Hvaða mánuði ^ársins var^st ^þú að gera eitthvað annað?"
        "Which months last year w^ere ^you doing something else?"
        / "Mánuðir  að gera eitthvað annað" :
        set of TMánuðir_allt_árið

      at_ful   {nýtt fyrir SILC2010; AÖK 13.01.10}
        "Hvaða mánuði ^ársins var^st ^þú sjálfstætt starfandi í fullu starfi?"
        "Which months last year w^ere ^you full time self-employed?"
        / "Mánuðir sjálfstætt starfandi fullt" :
        set of TMánuðir_allt_árið

      at_hlu   {nýtt fyrir SILC2010; AÖK 13.01.10}
        "Hvaða mánuði ^ársins var^st ^þú sjálfstætt starfandi í hlutastarfi?"
        "Which months last year w^ere ^you part time self-employed?"
        / "Mánuðir sjálfstætt starfandi hluta" :
        set of TMánuðir_allt_árið

      at_elli   {nýtt fyrir SILC2010; AÖK 04.02.10}
        "Hvaða mánuði ^ársins var^st ^þú ellilífeyrisþegi?"
        "Which months last year w^ere ^you receiving old age pension?"
        / "Mánuðir ellilífeyrir" :
        set of TMánuðir_allt_árið

      at_oror   {nýtt fyrir SILC2010; AÖK 04.02.10}
        "Hvaða mánuði ^ársins var^st ^þú örorkulífeyrisþegi?"
        "Which months last year w^ere ^you receiving disability pension?"
        / "Mánuðir örorka" :
        set of TMánuðir_allt_árið

     f_faedin   {nýtt fyrir SILC2010; AÖK 08.02.10}
        "Hvað var^st ^þú að gera áður en fæðingarorlofið hófst?"
        "What w^ere ^you before the maternity or paternity leave?"
        / "Fyrir fæðingarorlof" :
        SET OF (starfandi (11) "Starfsmaður í fullu starfi" "Full time employment",
                í_hlutastarfi (12) "Starfsmaður í hlutastarfi" "Part time employment",
                sjalfst_fullt (13) "Sjálfstætt starfandi í fullu starfi" "Full time self-employed",
                sjalfst_hluta (14) "Sjálfstætt starfandi í hlutastarfi" "Part time self-employed",
                atvinnulaus (15) "atvinnulaus" "Unemployed",
                í_námi (17) "í námi" "In education",
                ellilifeyrir (18) "ellilífeyrisþegi" "Did you receive old-age pension?",
                ororkulifeyrir (19) "örorkulífeyrisþegi" "Did you receive disability pension?",
                heimavinnandi (20)  "heimavinnandi" "Home working",
                veikur (21) "Veik/ur" "Ill (unable to work)",
                annað (22) "annað" "Other")


      ALífeyrir (L01)  {SILC spurning}
        "Fékk^stu greiddan lífeyri á síðasta ári, það er frá janúar til desember, frá Tryggingastofnun
      og / eða lífeyrissjóði ?"
        "Did ^you get pensions last year, that is from january to december, from Tryggingastofnun and / or
        a pensions fund?"
        /"Lífeyrir á árinu" :TJáNei

         ASjóður (L02)  {SILC spurning}
        "Hvort voru lífeyrisgreiðslurnar frá Tryggingastofnun, lífeyrissjóði eða frá báðum stöðum ?
      @/@/@GEf frá báðum stöðum, hakið þá bæði við 1 og 2@G"
        "Were they from Tryggingastofnun, a pension fund or both?"
        /"Sjóðir" :
        SET [2] OF (TR "Tryggingastofnun",
        LS "Lífeyrissjóði")

       ALSMán (L03)  {SILC spurning}
        "Í hve marga mánuði fékk^stu lífeyri frá lífeyrissjóði ?"
        "For how many months did ^you get a pension from a pension fund?"
        /"Mánuðir lífeyrissj"
        : 0..12

       ATRMán (L04)  {SILC spurning}
        "Í hve marga mánuði fékk^stu lífeyri frá Tryggingastofnun ?"
        "For how many months did ^you get a pension from Tryggingastofnun?"
        /"Mánuðir TR"
        : 0..12

        ALífTegund (L05)  {SILC spurning}
        "Hvaða lífeyrir er það?"
        "What type of pension is that?"
        /"Tegund lífeyris"
        : SET [6] OF(Endurhæfingarlífeyrir "Endurhæfingarlífeyrir" "rehabilitation allowance",
                     Örorkustyrkur "Örorkustyrkur" "invalidity allowance",
                     Örorkulífeyrir "Örorkulífeyrir" "invalidity pension",
                     Makalífeyrir "Makalífeyrir" "Spouse's pension",
                     Ellilífeyrir "Ellilífeyrir" "old age pension",
                     Annað "Annað" "Other type of pension")

        ALífAnnað (L06)  {SILC spurning}
        "Annað hvað ?
      @/@/@GMerkt var við annað í spurningunni hér að framan@G"
        "What other?"
        /"Aðrar lífeyrisgreiðslur"
        : STRING [50]

      Asérfa
      "Séreignarlífeyrissjóður er sjóður sem fólk leggur í reglulega umfram lögbundinn lífeyrissparnað. Ef undan er skilin tímabundin heimild til að ráðstafa séreignarsparnaði inn á húsnæðislán eða í húsnæðissparnað, fær^ðu greiddan lífeyri úr séreignarsjóði?"
      "Not including a temporary government scheme permitting using private pension plans to repay housing debts, ^do_you receive pension from individual private plans, where ^your private savings are kept?"
        /"Færðu séreignalífeyri"
        : TJáNei


      AsérfaUpphæð
      "Hversu háa upphæð fær^ðu á mánuði?
      @/@Gkrónur@G"
      "How much is that per month?
      @/@Gkrónur@G"
        /"Upphæð séreignalífeyris"
        : 1..10000000

      AsérfaUpphæð_gisk
      "En heldur þú að það sé ... ?
      @/@Gkrónur@G"
      "Do you think it is ...
      @/@Gkrónur@G"
        /"Upphæð séreignalífeyris"
        : (
        minna_en_5     "minna en 5 þúsund" "less than 5 thousand",
        minna_en_20    "minna en 20 þúsund" "less than 20 thousand",
        minna_en_50    "minna en 50 þúsund" "less than 50 thousand",
        minna_en_100   "minna en 100 þúsund" "less than 100 thousand",
        minna_en_200   "minna en 200 þúsund" "less than 200 thousand",
        minna_en_500   "minna en 500 þúsund" "less than 500 thousand",
        meira_en_500   "500 þúsund eða meira" "or 500 thousand or more"
        )


      Asérlíf
      "Greiðir ^þú mánaðarlega í séreignarlífeyrissparnað, það er sjóð sem geymir viðbótarlífeyrissparnað ^þinn?"
      "^do_you pay regularly into individual private saving plan, that is a fund that stores ^your savings for when ^you retire?."
        / "Greiðir í séreignalífeyrissjóð"
       : TJáNei

      AsérlífPrósent
      "Hversu háa prósentu af launum ^þínum á mánuði greiðir ^þú í viðbótarlífeyrissparnað?
        @/@/@gEf svarandi borgar fasta upphæð á mánuði, setjið veit-ekki svar og þá birtist spurning um upphæð á mánuði."
      "What is the amount you pay in percentage?"
        / "Prósent í séreignalífeyrissjóð"
       : string[6]

      AsérlífPrósent_gisk
      "Hversu há upphæð er það á mánuði ?"
      "But if you had to give your best guess, what amount a month is it?"
        / "Upphæð ágiskun í séreignalífeyrissjóð"
       : 1..100000

    {Þrjár nýjar spurningar frá SKS. Bætt við af AÖK 211107}
    Namslan
    "Tók^stu ^þér námslán til framfærslu vegna náms ^á_síðasta_ári?"
    "Did ^you take student loans ^last_year?"
      /"Námslán"
      : Tjánei

    Namsl_upph
       "Hversu háa upphæð fékk^st ^þú greidda í námslán í heildina ^á_síðasta_ári?"
       "Which amount did ^you receive ^last_year?"
       /"Upphæð námslána"
       :10000..9999999

    Namslan_man
       "Hversu marga mánuði ^ársins fékk^st ^þú greidd námslán?"
       "For how many months ^last_year did ^you receive student loans?"
       / "Fjöldi mánaða á námslánum"
       : 1..12

     {Nýjar spurningar þar sem fyrri svör fyrir B-blokk voru tekin úr sambandi}
     BSkipta
        "Hætti^r ^þú í starfi eða skipti^r um starf á síðasta ári?"
         "Did ^you quit a job or exchange jobs last year?"
        /"Skipta um starf"
        : TJáNei

     B01
        "Hvers vegna?...
        @/@/@gLestu upp svarkostina."
        "Why?...
        @/@/@gLestu upp svarkostina."
        /"Ástæða vinnuskipta"
        :(Betra "...Til að fá eða leita að betra starfi" "...To take or seek better job",
        Loka "...Vegna loka tímabundinnar ráðningar" "...End of temporary contract",
        Uppsögn "...Vegna þess að ^ÞérHonum var sagt upp starfi" "...Obliged to stop by employer",
        Lokun "...Vegna þess að fyrirtæki í ^þinni eigu var selt eða það lokaði" "...Sale or closure of your own business",
        Umönnun "...Vegna umönnunar barna eða annarra skyldmenna" "...Child care and care for other dependent",
        Flutningur "...Vegna þess að hjónaband ^þitt eða starf maka orsakaði flutning" "...Partner's job required us to move to another area or marriage",
        Eftirlaun  "...fór^stu á eftirlaun" "...did you retire",
        Nam (9) "...fór^stu í nám" "...did you go to school",
        Annað (8) "...Af öðrum ástæðum" "...other reasons")

     B01annad
        "Hvaða ástæða?
        @/@/@gLestu upp svarkostina."
        "What other reasons?
        @/@/@gLestu upp svarkostina."
        /"Önnur ástæða": string[120]


AUXFIELDS
  jan, feb, mar, apr, maímánuður, jún, júl, ágú, sep, okt, nóv, des : integer
  ellilif : string
  ellilif_en : string
  orlof:string
  orlof_en:string
  ÞérHonum : (karl2p "þér",kona2p "þér",karl3p "honum",kona3p "henni",óvíst3p "honum/henni")
  þinni    : (karl2p "þinni",kona2p "þinni", karl3p"hans",kona3p "hennar",óvíst3p "hans/hennar")
  þitt     : (karl2p "þitt",kona2p "þitt", karl3p "hans",kona3p "hennar",óvíst3p "hans/hennar")
  
  stu  :(karl2p "stu",kona2p "stu",karl3p "·hann",kona3p "·hún",óvíst3p "·hann/hún")
  þína :(karl2p "þína",kona2p "þína",karl3p "hans",kona3p "hennar",óvíst3p "hans/hennar")
  þínum :(karl2p "þínum",kona2p "þínum",karl3p "hans",kona3p "hennar",óvíst3p "hans/hennar")
  þig  :(karl2p "þig",kona2p "þig",karl3p "hann",kona3p "hann",óvíst3p "hann/hana")
  your : (karl2p "your",kona2p "your",karl3p "his",kona3p "her",óvíst3p "his/her")
  you :  (karl2p "you",kona2p "you",karl3p "he",kona3p "she",óvíst3p "he/she") 
  ere : (karl2p "ere",kona2p "ere",karl3p "as",kona3p "as",óvíst3p "as")
  st  :(karl2p "st",kona2p "st",karl3p "·hann",kona3p "·hún",óvíst3p "·hann/hún")
  þú   : (karl2p "þú",kona2p "þú",karl3p "hann",kona3p "hún",óvíst3p "hann/hún")
  n : (karl2p "n",kona2p " ",karl3p "n",kona3p " ", óvíst3p "/n")
  r : (karl2p "r",kona2p "r",karl3p " ",kona3p " ", óvíst3p " ")
  ðu   :(karl2p "ð þú",kona2p "ð þú",karl3p " hann",kona3p " hún",óvíst3p " hann/hún")
  do_you : (karl2p "do you",kona2p "do you",karl3p "does he",kona3p "does she",óvíst3p "does he/she")
  þinn   :(karl2p "þinn",kona2p "þinn",karl3p "hans",kona3p "hennar",óvíst3p "hans/hennar")
  þér  :    (karl2p "þér",kona2p "þér",karl3p "sér",kona3p "sér",óvíst3p "sér")
  ur: (karl2p "ur",kona2p " ",karl3p "ur",kona3p " ",óvíst3p "(ur)")
LOCALS 
    ársins,last_year,á_síðasta_ári:STRING
RULES
  ÞérHonum := persóna.ord
  þinni := persóna.ord
  þitt  :=persóna.ord
  you   :=persóna.ord 
  ere   :=persóna.ord
  þú    :=persóna.ord
  st   :=persóna.ord
  stu   :=persóna.ord
  þína  := persóna.ord
  þig   :=persóna.ord
  your  :=persóna.ord
  
  n     :=persóna.ord
  r     :=persóna.ord
  ðu    :=persóna.ord
  do_you:=persóna.ord
  þinn :=persóna.ord
  þér  :=persóna.ord
  ur   :=persóna.ord
  
  ársins := 'árið '+STR(YEAR(viðmiðunardagur))
  á_síðasta_ári:=ársins
  last_year:='in ' +STR(YEAR(viðmiðunardagur))
  
  if aldur > 59 then ellilif := 'Ellilífeyrisþegi'
                     ellilif_en := 'Did you receive old-age pension?'
  elseif aldur < 60 then ellilif := ''
                         ellilif_en := ''
  endif
  if aldur > 59 then orlof:= ''
                     orlof_en := ''
  elseif aldur < 60 then orlof := 'í fæðingarorlofi'
                         orlof_en := 'On maternity / paternity leave'
  endif

  AÁrið

  signal
  if (í_námi in AÁrið) then (AÁrið.cardinal > 1) "Varstu í námi alla 12 mánuði ársins, líka sumarmánuðina? @/@GSpyrill lagar svarið ef svarandi leiðréttir sig@G" endif

  if AÁrið.cardinal > 1 then
    if starfandi in AÁrið then
      AMánuðir_fullt
      check
      if allt_árið in AMánuðir_fullt then AMánuðir_fullt.cardinal = 1 "ekki er hægt að velja 'allt árið' með öðrum kostum" endif
    endif
    if í_hlutastarfi in AÁrið then
      AMánuðir_hluta
      check
      if allt_árið in AMánuðir_hluta then AMánuðir_hluta.cardinal = 1 "ekki er hægt að velja 'allt árið' með öðrum kostum" endif
    endif
    if í_fæðingarorlofi in AÁrið then
      AMánuðir_fæðingarorlof
      check
      if allt_árið in AMánuðir_fæðingarorlof then AMánuðir_fæðingarorlof.cardinal = 1 "ekki er hægt að velja 'allt árið' með öðrum kostum" endif
    endif
    if atvinnulaus in AÁrið then
      AMánuðir_atvinnulaus
      check
      if allt_árið in AMánuðir_atvinnulaus then AMánuðir_atvinnulaus.cardinal = 1 "ekki er hægt að velja 'allt árið' með öðrum kostum" endif
    endif
    if í_námi in AÁrið then
      AMánuðir_námi
      check
      if allt_árið in AMánuðir_námi then AMánuðir_námi.cardinal = 1 "ekki er hægt að velja 'allt árið' með öðrum kostum" endif
      signal
      if (allt_árið in AMánuðir_námi) or (AMánuðir_námi.cardinal = 12) then not ((allt_árið in AMánuðir_námi) or (AMánuðir_námi.cardinal = 12) ) "Varstu í námi alla 12 mánuði ársins, líka sumarmánuðina?" endif
    endif
    if sjalfst_fullt in AÁrið then
      at_ful
      check
      if allt_árið in at_ful then at_ful.cardinal = 1 "ekki er hægt að velja 'allt árið' með öðrum kostum" endif
    endif
    if sjalfst_hluta in AÁrið then
      at_hlu
      check
      if allt_árið in at_hlu then at_hlu.cardinal = 1 "ekki er hægt að velja 'allt árið' með öðrum kostum" endif
    endif
    if ellilifeyrir in AÁrið then
      at_elli
      check
      if allt_árið in at_elli then at_elli.cardinal = 1 "ekki er hægt að velja 'allt árið' með öðrum kostum" endif
    endif
    if ororkulifeyrir in AÁrið then
      at_oror
      check
      if allt_árið in at_oror then at_oror.cardinal = 1 "ekki er hægt að velja 'allt árið' með öðrum kostum" endif
    endif
    if heimavinnandi in AÁrið then
      AMánuðir_heimavinnandi
      check
      if allt_árið in AMánuðir_heimavinnandi then AMánuðir_heimavinnandi.cardinal = 1 "ekki er hægt að velja 'allt árið' með öðrum kostum" endif
    endif
    if veikur in AÁrið then
      AMánuðir_veikur
      check
      if allt_árið in AMánuðir_veikur then AMánuðir_veikur.cardinal = 1 "ekki er hægt að velja 'allt árið' með öðrum kostum" endif
    endif
    if annað in AÁrið then
      AMánuðir_annað
      check
      if allt_árið in AMánuðir_annað then AMánuðir_annað.cardinal = 1 "ekki er hægt að velja 'allt árið' með öðrum kostum" endif
    endif

    if not (
     (allt_árið in AMánuðir_fullt) or (allt_árið in AMánuðir_hluta) or (allt_árið in AMánuðir_fæðingarorlof) or
     (allt_árið in AMánuðir_atvinnulaus) or (allt_árið in AMánuðir_námi) or (allt_árið in at_elli) or (allt_árið in at_oror) or
     (allt_árið in AMánuðir_heimavinnandi) or (allt_árið in AMánuðir_veikur) or (allt_árið in AMánuðir_annað) or (allt_árið in at_ful) or (allt_árið in at_hlu)
           ) then
      jan := 0
      if (janúar in AMánuðir_fullt) then jan := 1 endif
      if (janúar in AMánuðir_hluta) then jan := jan + 1 endif
      if (janúar in AMánuðir_fæðingarorlof) then jan := jan + 1 endif
      if (janúar in AMánuðir_atvinnulaus) then jan := jan + 1 endif
      if (janúar in AMánuðir_námi) then jan := jan + 1 endif
      if (janúar in at_ful) then jan := jan + 1 endif
      if (janúar in at_hlu) then jan := jan + 1 endif
      if (janúar in at_elli) then jan := jan + 1 endif
      if (janúar in at_oror) then jan := jan + 1 endif
      if (janúar in AMánuðir_heimavinnandi) then jan := jan + 1 endif
      if (janúar in AMánuðir_veikur) then jan := jan + 1 endif
      if (janúar in AMánuðir_annað) then jan := jan + 1 endif
      check
      if (AÁrið.cardinal > 1) involving ( AMánuðir_fullt, AMánuðir_hluta, AMánuðir_fæðingarorlof, AMánuðir_atvinnulaus,
                                      AMánuðir_námi, at_elli, at_oror,
                                      AMánuðir_heimavinnandi, AMánuðir_veikur, AMánuðir_annað, at_ful, at_hlu)
      then ( jan >= 1 ) "janúar að minnsta kosti eini sinni"
      endif

      feb := 0
      if (febrúar in AMánuðir_fullt) then feb := 1 endif
      if (febrúar in AMánuðir_hluta) then feb := feb + 1 endif
      if (febrúar in AMánuðir_fæðingarorlof) then feb := feb + 1 endif
      if (febrúar in AMánuðir_atvinnulaus) then feb := feb + 1 endif
      if (febrúar in AMánuðir_námi) then feb := feb + 1 endif
      if (febrúar in at_ful) then feb := feb + 1 endif
      if (febrúar in at_hlu) then feb := feb + 1 endif
      if (febrúar in at_elli) then feb := feb + 1 endif
      if (febrúar in at_oror) then feb := feb + 1 endif
      if (febrúar in AMánuðir_heimavinnandi) then feb := feb + 1 endif
      if (febrúar in AMánuðir_veikur) then feb := feb + 1 endif
      if (febrúar in AMánuðir_annað) then feb := feb + 1 endif
      check
      if (AÁrið.cardinal > 1) involving ( AMánuðir_fullt, AMánuðir_hluta, AMánuðir_fæðingarorlof, AMánuðir_atvinnulaus,
                                      AMánuðir_námi, at_elli, at_oror,
                                      AMánuðir_heimavinnandi, AMánuðir_veikur, AMánuðir_annað, at_ful, at_hlu)
      then ( feb >= 1 ) "febrúar að minnsta kosti eini sinni"
      endif

      mar := 0
      if (mars in AMánuðir_fullt) then mar := 1 endif
      if (mars in AMánuðir_hluta) then mar := mar + 1 endif
      if (mars in AMánuðir_fæðingarorlof) then mar := mar + 1 endif
      if (mars in AMánuðir_atvinnulaus) then mar := mar + 1 endif
      if (mars in AMánuðir_námi) then mar := mar + 1 endif
      if (mars in at_ful) then mar := mar + 1 endif
      if (mars in at_hlu) then mar := mar + 1 endif
      if (mars in at_elli) then mar := mar + 1 endif
      if (mars in at_oror) then mar := mar + 1 endif
      if (mars in AMánuðir_heimavinnandi) then mar := mar + 1 endif
      if (mars in AMánuðir_veikur) then mar := mar + 1 endif
      if (mars in AMánuðir_annað) then mar := mar + 1 endif
      check
      if (AÁrið.cardinal > 1) involving ( AMánuðir_fullt, AMánuðir_hluta, AMánuðir_fæðingarorlof, AMánuðir_atvinnulaus,
                                      AMánuðir_námi, at_elli, at_oror,
                                      AMánuðir_heimavinnandi, AMánuðir_veikur, AMánuðir_annað, at_ful, at_hlu)
      then ( mar >= 1 ) "mars að minnsta kosti eini sinni"
      endif

      apr := 0
      if (apríl in AMánuðir_fullt) then apr := 1 endif
      if (apríl in AMánuðir_hluta) then apr := apr + 1 endif
      if (apríl in AMánuðir_fæðingarorlof) then apr := apr + 1 endif
      if (apríl in AMánuðir_atvinnulaus) then apr := apr + 1 endif
      if (apríl in AMánuðir_námi) then apr := apr + 1 endif
      if (apríl in at_ful) then apr := apr + 1 endif
      if (apríl in at_hlu) then apr := apr + 1 endif
      if (apríl in at_elli) then apr := apr + 1 endif
      if (apríl in at_oror) then apr := apr + 1 endif
      if (apríl in AMánuðir_heimavinnandi) then apr := apr + 1 endif
      if (apríl in AMánuðir_veikur) then apr := apr + 1 endif
      if (apríl in AMánuðir_annað) then apr := apr + 1 endif
      check
      if (AÁrið.cardinal > 1) involving ( AMánuðir_fullt, AMánuðir_hluta, AMánuðir_fæðingarorlof, AMánuðir_atvinnulaus,
                                      AMánuðir_námi, at_elli, at_oror,
                                      AMánuðir_heimavinnandi, AMánuðir_veikur, AMánuðir_annað, at_ful, at_hlu)
      then ( apr >= 1 ) "apríl að minnsta kosti eini sinni"
      endif

      maímánuður := 0
      if (maí in AMánuðir_fullt) then maímánuður := 1 endif
      if (maí in AMánuðir_hluta) then maímánuður := maímánuður + 1 endif
      if (maí in AMánuðir_fæðingarorlof) then maímánuður := maímánuður + 1 endif
      if (maí in AMánuðir_atvinnulaus) then maímánuður := maímánuður + 1 endif
      if (maí in AMánuðir_námi) then maímánuður := maímánuður + 1 endif
      if (maí in at_ful) then maímánuður := maímánuður + 1 endif
      if (maí in at_hlu) then maímánuður := maímánuður + 1 endif
      if (maí in at_elli) then maímánuður := maímánuður + 1 endif
      if (maí in at_oror) then maímánuður := maímánuður + 1 endif
      if (maí in AMánuðir_heimavinnandi) then maímánuður := maímánuður + 1 endif
      if (maí in AMánuðir_veikur) then maímánuður := maímánuður + 1 endif
      if (maí in AMánuðir_annað) then maímánuður := maímánuður + 1 endif
      check
      if (AÁrið.cardinal > 1) involving ( AMánuðir_fullt, AMánuðir_hluta, AMánuðir_fæðingarorlof, AMánuðir_atvinnulaus,
                                      AMánuðir_námi, at_elli, at_oror,
                                      AMánuðir_heimavinnandi, AMánuðir_veikur, AMánuðir_annað, at_ful, at_hlu)
      then ( maímánuður >= 1 ) "maí að minnsta kosti eini sinni"
      endif

      jún := 0
      if (júní in AMánuðir_fullt) then jún := 1 endif
      if (júní in AMánuðir_hluta) then jún := jún + 1 endif
      if (júní in AMánuðir_fæðingarorlof) then jún := jún + 1 endif
      if (júní in AMánuðir_atvinnulaus) then jún := jún + 1 endif
      if (júní in AMánuðir_námi) then jún := jún + 1 endif
      if (júní in at_ful) then jún := jún + 1 endif
      if (júní in at_hlu) then jún := jún + 1 endif
      if (júní in at_elli) then jún := jún + 1 endif
      if (júní in at_oror) then jún := jún + 1 endif
      if (júní in AMánuðir_heimavinnandi) then jún := jún + 1 endif
      if (júní in AMánuðir_veikur) then jún := jún + 1 endif
      if (júní in AMánuðir_annað) then jún := jún + 1 endif
      check
      if (AÁrið.cardinal > 1) involving ( AMánuðir_fullt, AMánuðir_hluta, AMánuðir_fæðingarorlof, AMánuðir_atvinnulaus,
                                      AMánuðir_námi, at_elli, at_oror,
                                      AMánuðir_heimavinnandi, AMánuðir_veikur, AMánuðir_annað, at_ful, at_hlu)
      then ( jún >= 1 ) "júní að minnsta kosti eini sinni"
      endif

      júl := 0
      if (júlí in AMánuðir_fullt) then júl := 1 endif
      if (júlí in AMánuðir_hluta) then júl := júl + 1 endif
      if (júlí in AMánuðir_fæðingarorlof) then júl := júl + 1 endif
      if (júlí in AMánuðir_atvinnulaus) then júl := júl + 1 endif
      if (júlí in AMánuðir_námi) then júl := júl + 1 endif
      if (júlí in at_ful) then júl := júl + 1 endif
      if (júlí in at_hlu) then júl := júl + 1 endif
      if (júlí in at_elli) then júl := júl + 1 endif
      if (júlí in at_oror) then júl := júl + 1 endif
      if (júlí in AMánuðir_heimavinnandi) then júl := júl + 1 endif
      if (júlí in AMánuðir_veikur) then júl := júl + 1 endif
      if (júlí in AMánuðir_annað) then júl := júl + 1 endif
      check
      if (AÁrið.cardinal > 1) involving ( AMánuðir_fullt, AMánuðir_hluta, AMánuðir_fæðingarorlof, AMánuðir_atvinnulaus,
                                      AMánuðir_námi, at_elli, at_oror,
                                      AMánuðir_heimavinnandi, AMánuðir_veikur, AMánuðir_annað, at_ful, at_hlu)
      then ( júl >= 1 ) "júlí að minnsta kosti eini sinni"
      endif

      ágú := 0
      if (ágúst in AMánuðir_fullt) then ágú := 1 endif
      if (ágúst in AMánuðir_hluta) then ágú := ágú + 1 endif
      if (ágúst in AMánuðir_fæðingarorlof) then ágú := ágú + 1 endif
      if (ágúst in AMánuðir_atvinnulaus) then ágú := ágú + 1 endif
      if (ágúst in AMánuðir_námi) then ágú := ágú + 1 endif
      if (ágúst in at_ful) then ágú := ágú + 1 endif
      if (ágúst in at_hlu) then ágú := ágú + 1 endif
      if (ágúst in at_elli) then ágú := ágú + 1 endif
      if (ágúst in at_oror) then ágú := ágú + 1 endif
      if (ágúst in AMánuðir_heimavinnandi) then ágú := ágú + 1 endif
      if (ágúst in AMánuðir_veikur) then ágú := ágú + 1 endif
      if (ágúst in AMánuðir_annað) then ágú := ágú + 1 endif
      check
      if (AÁrið.cardinal > 1) involving ( AMánuðir_fullt, AMánuðir_hluta, AMánuðir_fæðingarorlof, AMánuðir_atvinnulaus,
                                      AMánuðir_námi, at_elli, at_oror,
                                      AMánuðir_heimavinnandi, AMánuðir_veikur, AMánuðir_annað, at_ful, at_hlu)
      then ( ágú >= 1 ) "ágúst að minnsta kosti eini sinni"
      endif

      sep := 0
      if (september in AMánuðir_fullt) then sep := 1 endif
      if (september in AMánuðir_hluta) then sep := sep + 1 endif
      if (september in AMánuðir_fæðingarorlof) then sep := sep + 1 endif
      if (september in AMánuðir_atvinnulaus) then sep := sep + 1 endif
      if (september in AMánuðir_námi) then sep := sep + 1 endif
      if (september in at_ful) then sep := sep + 1 endif
      if (september in at_hlu) then sep := sep + 1 endif
      if (september in at_elli) then sep := sep + 1 endif
      if (september in at_oror) then sep := sep + 1 endif
      if (september in AMánuðir_heimavinnandi) then sep := sep + 1 endif
      if (september in AMánuðir_veikur) then sep := sep + 1 endif
      if (september in AMánuðir_annað) then sep := sep + 1 endif
      check
      if (AÁrið.cardinal > 1) involving ( AMánuðir_fullt, AMánuðir_hluta, AMánuðir_fæðingarorlof, AMánuðir_atvinnulaus,
                                      AMánuðir_námi, at_elli, at_oror,
                                      AMánuðir_heimavinnandi, AMánuðir_veikur, AMánuðir_annað, at_ful, at_hlu)
      then ( sep >= 1 ) "september að minnsta kosti eini sinni"
      endif

      okt := 0
      if (október in AMánuðir_fullt) then okt := 1 endif
      if (október in AMánuðir_hluta) then okt := okt + 1 endif
      if (október in AMánuðir_fæðingarorlof) then okt := okt + 1 endif
      if (október in AMánuðir_atvinnulaus) then okt := okt + 1 endif
      if (október in AMánuðir_námi) then okt := okt + 1 endif
      if (október in at_ful) then okt := okt + 1 endif
      if (október in at_hlu) then okt := okt + 1 endif
      if (október in at_elli) then okt := okt + 1 endif
      if (október in at_oror) then okt := okt + 1 endif
      if (október in AMánuðir_heimavinnandi) then okt := okt + 1 endif
      if (október in AMánuðir_veikur) then okt := okt + 1 endif
      if (október in AMánuðir_annað) then okt := okt + 1 endif
      check
      if (AÁrið.cardinal > 1) involving ( AMánuðir_fullt, AMánuðir_hluta, AMánuðir_fæðingarorlof, AMánuðir_atvinnulaus,
                                      AMánuðir_námi, at_elli, at_oror,
                                      AMánuðir_heimavinnandi, AMánuðir_veikur, AMánuðir_annað, at_ful, at_hlu)
      then ( okt >= 1 ) "október að minnsta kosti eini sinni"
      endif

      nóv := 0
      if (nóvember in AMánuðir_fullt) then nóv := 1 endif
      if (nóvember in AMánuðir_hluta) then nóv := nóv + 1 endif
      if (nóvember in AMánuðir_fæðingarorlof) then nóv := nóv + 1 endif
      if (nóvember in AMánuðir_atvinnulaus) then nóv := nóv + 1 endif
      if (nóvember in AMánuðir_námi) then nóv := nóv + 1 endif
      if (nóvember in at_ful) then nóv := nóv + 1 endif
      if (nóvember in at_hlu) then nóv := nóv + 1 endif
      if (nóvember in at_elli) then nóv := nóv + 1 endif
      if (nóvember in at_oror) then nóv := nóv + 1 endif
      if (nóvember in AMánuðir_heimavinnandi) then nóv := nóv + 1 endif
      if (nóvember in AMánuðir_veikur) then nóv := nóv + 1 endif
      if (nóvember in AMánuðir_annað) then nóv := nóv + 1 endif
      check
      if (AÁrið.cardinal > 1) involving ( AMánuðir_fullt, AMánuðir_hluta, AMánuðir_fæðingarorlof, AMánuðir_atvinnulaus,
                                      AMánuðir_námi, at_elli, at_oror,
                                      AMánuðir_heimavinnandi, AMánuðir_veikur, AMánuðir_annað, at_ful, at_hlu)
      then ( nóv >= 1 ) "nóvember að minnsta kosti eini sinni"
      endif

      des := 0
      if (desember in AMánuðir_fullt) then des := 1 endif
      if (desember in AMánuðir_hluta) then des := des + 1 endif
      if (desember in AMánuðir_fæðingarorlof) then des := des + 1 endif
      if (desember in AMánuðir_atvinnulaus) then des := des + 1 endif
      if (desember in AMánuðir_námi) then des := des + 1 endif
      if (desember in at_ful) then des := des + 1 endif
      if (desember in at_hlu) then des := des + 1 endif
      if (desember in at_elli) then des := des + 1 endif
      if (desember in at_oror) then des := des + 1 endif
      if (desember in AMánuðir_heimavinnandi) then des := des + 1 endif
      if (desember in AMánuðir_veikur) then des := des + 1 endif
      if (desember in AMánuðir_annað) then des := des + 1 endif
      check
      if (AÁrið.cardinal > 1) involving ( AMánuðir_fullt, AMánuðir_hluta, AMánuðir_fæðingarorlof, AMánuðir_atvinnulaus,
                                      AMánuðir_námi, at_elli, at_oror,
                                      AMánuðir_heimavinnandi, AMánuðir_veikur, AMánuðir_annað, at_ful, at_hlu)
      then ( des >= 1 ) "desember að minnsta kosti eini sinni"
      endif

  endif {
      if not (
     (allt_árið in AMánuðir_fullt) or (allt_árið in AMánuðir_hluta) or (allt_árið in AMánuðir_fæðingarorlof) or
     (allt_árið in AMánuðir_atvinnulaus) or (allt_árið in AMánuðir_námi) or (allt_árið in AMánuðir_lífeyrisþegi) or
     (allt_árið in AMánuðir_heimavinnandi) or (allt_árið in AMánuðir_veikur) or (allt_árið in AMánuðir_annað)
           ) then
        }

  endif
  IF ((í_fæðingarorlofi in Aárið) AND ((allt_árið in Amánuðir_fæðingarorlof) OR (janúar in Amánuðir_fæðingarorlof)))
        or ((í_fæðingarorlofi in Aárið) AND (Amánuðir_fæðingarorlof = empty)) then f_faedin endif {Nýtt fyrir SILC2010; AÖK 08.02.2010}

    IF (starfandi in Aárið) or (í_hlutastarfi in aárið) or (sjalfst_fullt in aárið) or (sjalfst_hluta in aárið) then Bskipta endif
    IF Bskipta = já
        then B01
            IF B01 = annað
                then B01annad
            endif
    endif

    alífeyrir
    IF Alífeyrir = já THEN
    Asjóður
        IF TR in Asjóður THEN ATRMán
        ENDIF
        IF LS in ASjóður THEN ALSMán
        ENDIF
            IF  ATRMán <> empty or ALSMán <> empty THEN
            ALífTegund
            ENDIF
                If annað in alíftegund then
                ALífAnnað
                ENDIF
    ENDIF

    {if (aldur >= 60) or (a.Aaðal = öryrki) or (ellilifeyrir in AÁrið) or (ororkulifeyrir in AÁrið) then}  {04.02.10; Dettur út tímabundið fyrir SILC2010}
      Asérfa
      if ASérfa = já then
        ASérfaUpphæð
        signal if (ASérfaUpphæð = response) and (ASérfaUpphæð > 500) then (ASérfaUpphæð > 500) "Ertu viss um að upphæðin sé meira en fimm hundruð þúsund á mánuði ?" endif
        signal if (ASérfaUpphæð = response) and (ASérfaUpphæð < 5000) then (ASérfaUpphæð < 5000) "Ertu viss um að upphæðin sé ekki í þúsundum ? Hún á að vera í krónum" endif
        if ASérfaUpphæð = dk then AsérfaUpphæð_gisk endif
      endif
{    endif}
    if vinnandi = já then
      ASérlíf
      if ASérlíf = já then
        ASérlífPrósent
        if ASérlífPrósent = dk then
          ASérlífPrósent_gisk
        endif
      endif
    endif

    IF í_námi IN aárið
    THEN Namslan
    ENDIF
    IF namslan = já
    THEN namsl_upph
         {namslan_man}
    ENDIF



 ENDBLOCK
