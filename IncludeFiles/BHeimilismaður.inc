{   BHeimilisfólk.inc SILC

    Eftirfarandi breytur şurfa ağ vera til stağar:
    haus      : Auğkenni könnunar
                Auğkenni şátttakanda
    fsvar     : Viğeigandi fyrra svar
    strik     : Strik sem ağskilur haus og spurningu
}

BLOCK BHeimilismağur "Annağ heimilisfólk"
  PARAMETERS
    IMPORT viğmiğunardagur : DateType
    IMPORT persóna     : TPersóna
    IMPORT saldur      : INTEGER
    IMPORT Nır         : TJáNei
    IMPORT Farinn      : TJáNei
    IMPORT Hjústétt    : THju
    EXPORT Vinnufær    : TJáNei
    IMPORT NúmerHeimilismanns :integer
    import umferd : integer {í fyrstu umferğ spyrjum viğ um persónu, í annari spyrjum viğ um tengsl}
    import kyn_seinni_hluti : TKyn {í seinni umferğ fáum viğ ağ vita kyn sem færibreytu }
    import hjusvar_1        : Integer
    import óskráğur_seinni_hluti : Tjánei

    FIELDS

    kennitala  (HM07)        : string[10], EMPTY
    aldur    (HM08)
     "^haus@/^fsvar@/^strik@/
       Hvağ er ^hhann ^ggamall ?@G"
      "^haus@/^fsvar@/^strik@/^preamble
       What age is this person ?@G"
      /"Aldur": 0..110, EMPTY
    nafn  (HM09)                 "^haus@/^fsvar@/^strik@/
       Hvağ heitir hann / hún ?
       @/@/@GEf nöfn eru forskráğ, lesiğ şá nafniğ og spyrjiğ Er şetta rétt nafn?
       @/Ef svo er, hlaupiğ şá yfir útfyllta reiti, en spyrjiğ viğ şá sem eru óútfylltir@G"
      "^haus@/^fsvar@/^strik@/^preamble
       What is this persons name ?
       @/@/@GEf nöfn eru forskráğ, lesiğ şá nafniğ og spyrjiğ Er şetta rétt nafn?
       @/Ef svo er, hlaupiğ şá yfir útfyllta reiti, en spyrjiğ viğ şá sem eru óútfylltir@G"
      /"Nafn" :string[31]
    fæğingarland       : string[2], EMPTY
    ríkisfang          : string[2], EMPTY
    maki               : string[10], EMPTY
    Brottfluttur       : TJáNei
    Óskráğur           : TJáNei

    Kennitoluleit {Nı spurning. AÖK 21. nóv. 2007}
     "^haus@/^fsvar@/^strik@/
     @GSpyrill, ef upplısingar um heimilismann eru litlar, reyndu ağ fá frekari upplısingar til ağ auğvelda kennitöluleit. @uBest er ağ fá afmælisdag.@u Ef svarandi veit
     bókstaflega ekkert um viğkomandi, fáğu hann til ağ spyrja annan heimilismann um upplısingar.@G"
     "^haus@/^fsvar@/^strik@/
     @GSpyrill, ef upplısingar um heimilismann eru litlar, reyndu ağ fá frekari upplısingar til ağ auğvelda kennitöluleit. @uBest er ağ fá afmælisdag.@u Ef svarandi veit
     bókstaflega ekkert um viğkomandi, fáğu hann til ağ spyrja annan heimilismann um upplısingar.@G": STRING[500], empty

    Kyn (Hm10)
      "^haus@/^fsvar@/^strik@/
       Hvert er kyn hans / hennar ?"
      "^haus@/^fsvar@/^strik@/^preamble
       Is the person male or female?"
      /"Kyn"
      : TKyn

    FæğÁr (Hm11)
      "^haus@/^fsvar@/^strik@/
       Hvağa ár er ^hhann fædd^ur ?"
      "^haus@/^fsvar@/^strik@/
       What year was ^hhe born ?"
      /"Fæğingarár"
      : TFæğÁr, dk
    Aldursbil (Hm11a)
      "^haus@/^fsvar@/^strik@/
       Á hvağa aldursbili er ^hhann ?
       @/@/@RMjög mikilvægt er ağ fá svar viğ şessari spurningu, reyndu ağ láta svaranda taka afstöğu og merkja í einhvern hóp. Ónákvæmt gisk er betra en ekkert svar!@R"
      "^haus@/^fsvar@/^strik@/
       Which agegroup does ^hhe belong to ?
       @/@/@RMjög mikilvægt er ağ fá svar viğ şessari spurningu, reyndu ağ láta svaranda taka afstöğu og merkja í einhvern hóp. Ónákvæmt gisk er betra en ekkert svar!@R"
      /"Aldursbil"
      : ( tilfimm "0-5 ára",
          sex     "6-12 ára",
          şrettán "13-15 ára",
          sextán  "16-19 ára",
          tuttugu "20-24 ára",
          t25     "25-29 ára",
          t30     "30-39 ára",
          t40     "40-49 ára",
          t50     "50-54 ára",
          t55     "55-59 ára",
          t60     "60-66 ára",
          t67     "67-74 ára",
          t75     "75-79 ára",
          t80     "80 og eldri"
         ), dk

    Afmæli (Hm12)
      "^haus@/^fsvar@/^strik@/
       Er ^hhann búin^n ağ eiga afmæli á árinu ?"
      "^haus@/^fsvar@/^strik@/
       Has ^hhe already had a birthday this year ?"
      /"Afmæli"
      : TJáNei
    VinAld (Hm13)
      "^haus@/^fsvar@/^strik@/
       Er ^hhann milli 16 og 74 ára ?"
      "^haus@/^fsvar@/^strik@/
       Is ^hhe aged between 16 and 74 ?"
      /"Vinnualdur"
      : TJáNei
    Tengsl (Hm14)
      "^haus@/^fsvar@/^strik@/
       Hvernig er ^hhann tengd^ur ^şér ?
       @/@/@GMeğ barni er bæği átt viğ eigin börn og börn maka.
       Meğ foreldri er átt viğ bæği blóğforeldra og stjúpforeldra.@G"
      "^haus@/^fsvar@/^strik@/
       What is ^hhis relation to ^you ?
       @/@/@GMeğ barni er bæği átt viğ eigin börn og börn maka.
       Meğ foreldri er átt viğ bæği blóğforeldra og stjúpforeldra. Ef svili / svilkona şá fært á mágur / mágkona.@G"
      /"Tengsl"
      : TTengsl
    Hjú (Hm15)
      "^haus@/^fsvar@/^strik@/
       Hver er hjúskaparstağa ^hhans ?"
      "^haus@/^fsvar@/^strik@/
       What is ^hhis marital status ?"
      /"Hjúskapur"
      : THju
    thjodskra_hju      :string[1]


    {HjúSpurt (Hm15)
      "^haus@/^fsvar@/^strik@/
       Hver er hjúskaparstağa ^hhans ?"
      "^haus@/^fsvar@/^strik@/
       What is ^hhis marital status ?"
      /"Hjúskapur"
      : THjuSpurt}

    HjúSvar (Hm17)
      "^haus@/^fsvar@/^strik@/
      Hver er hjúskaparstağa ^hhans?"
      "^haus@/^fsvar@/^strik@/
      What is ^your marital status ?"
      /"HjúskaparstağaSvaranda"
      : THjúsvar  {Kóperuğ Hjúsvar úr BFjölskylda 080108}

    pk_maka
      "^haus@/^fsvar@/^strik@/
       Şú sagğir mér áğan ağ ^Heimilismağur[NúmerHeimilismanns].nafn væri í sambúğ. Hver heimilismanna er í sambúğ meğ ^hhonum?
       @/@/@GEf hann er á heimilinu şá skráiğ númer heimilismanns.  Ef hann er ekki á heimilinu, skiljiğ reitinn eftir auğann@G"
      "^haus@/^fsvar@/^strik@/
       Who is the spouse ?
       @/@/@GEf hann er á heimilinu şá skráiğ númer heimilismanns.  Ef hann er ekki á heimilinu, skiljiğ reitinn eftir auğann@G"
      /"pk_maka"
      : (heim02(2)  "^maki_heimNafn2",
         heim03  "^maki_heimNafn3",
         heim04  "^maki_heimNafn4",
         heim05  "^maki_heimNafn5",
         heim06  "^maki_heimNafn6",
         heim07  "^maki_heimNafn7",
         heim08  "^maki_heimNafn8",
         heim09  "^maki_heimNafn9",
         heim10  "^maki_heimNafn10",
         heim11  "^maki_heimNafn11",
         heim12  "^maki_heimNafn12",
         heim13  "^maki_heimNafn13",
         heim14  "^maki_heimNafn14",
         heim15  "^maki_heimNafn15"), empty

    pk_fadir
      "^haus@/^fsvar@/^strik@/
       @GSpurt er um: ^Heimilismağur[NúmerHeimilismanns].nafn@/@/@G
       Er fağir ^hhans á heimilinu? Hver er şağ?
       @/@/@GEf hann er á heimilinu şá skráiğ númer heimilismanns.  Ef hann er ekki á heimilinu, skiljiğ reitinn eftir auğann@G"
      "^haus@/^fsvar@/^strik@/
       Who is his/her father ?
       @/@/@GEf hann er á heimilinu şá skráiğ númer heimilismanns.  Ef hann er ekki á heimilinu, skiljiğ reitinn eftir auğann@G"
      /"pk_fadir"
      : (heim02(2)  "^fadir_heimNafn2",
         heim03  "^fadir_heimNafn3",
         heim04  "^fadir_heimNafn4",
         heim05  "^fadir_heimNafn5",
         heim06  "^fadir_heimNafn6",
         heim07  "^fadir_heimNafn7",
         heim08  "^fadir_heimNafn8",
         heim09  "^fadir_heimNafn9",
         heim10  "^fadir_heimNafn10",
         heim11  "^fadir_heimNafn11",
         heim12  "^fadir_heimNafn12",
         heim13  "^fadir_heimNafn13",
         heim14  "^fadir_heimNafn14",
         heim15  "^fadir_heimNafn15"), empty
    pk_modir
      "^haus@/^fsvar@/^strik@/
       @GSpurt er um: ^Heimilismağur[NúmerHeimilismanns].nafn@/@/@G
       Er móğir ^hhans á heimilinu? Hver er şağ?
       @/@/@Ghún er á heimilinu şá skráiğ númer heimilismanns.  Ef hún er ekki á heimilinu, skiljiğ reitinn eftir auğann ?@G"
      "^haus@/^fsvar@/^strik@/
       Who is his/her mother ?
       @/@/@Ghún er á heimilinu şá skráiğ númer heimilismanns.  Ef hún er ekki á heimilinu, skiljiğ reitinn eftir auğann ?@G"
      /"pk_modir"
      : (heim02(2)  "^modir_heimNafn2",
         heim03  "^modir_heimNafn3",
         heim04  "^modir_heimNafn4",
         heim05  "^modir_heimNafn5",
         heim06  "^modir_heimNafn6",
         heim07  "^modir_heimNafn7",
         heim08  "^modir_heimNafn8",
         heim09  "^modir_heimNafn9",
         heim10  "^modir_heimNafn10",
         heim11  "^modir_heimNafn11",
         heim12  "^modir_heimNafn12",
         heim13  "^modir_heimNafn13",
         heim14  "^modir_heimNafn14",
         heim15  "^modir_heimNafn15"), empty

    nanar_oskyldur
      "^haus@/^fsvar@/^strik@/
       Er şessi heimilismağur í hjúskap eğa sambúğ meğ einhverjum á heimilinu ?
       @/@/@GEf já, şá şarf ağ bakka og laga merkingu í viğeigandi spurningu.@G"
      "^haus@/^fsvar@/^strik@/
       Is this person married to or living with a member of the household ?
       @/@/@GEf já, şá şarf ağ bakka og laga merkingu í viğeigandi spurningu.@G"
      /"nanar_oskyldur"
      : TJáNei


   Upphaflega (Hm17)
      "^haus@/^fsvar@/^strik@/
       FRAMKVÆMD Bjó hann á upphaflegu heimili ?"
      : TJánei

    Stağa_í_könnun (Hm18)
      "^haus@/^fsvar@/^strik@/
       FRAMKVÆMD Stağa í könnun ?"
      : STRING [1]

     Hvert_flutt (Hm20)
      "^haus@/^fsvar@/^strik@/
       FRAMKVÆMD Hvert flutt ?"
      : STRING [1]

     Mánuğur_flutt (Hm21)
      "^haus@/^fsvar@/^strik@/
       FRAMKVÆMD Mánuğur ?"
      : STRING [2]

     Ár_flutt (Hm22)
      "^haus@/^fsvar@/^strik@/
       FRAMKVÆMD Ár ?"
      : STRING [4]

     Mánuğur_inn (Hm23)
      "^haus@/^fsvar@/^strik@/
       FRAMKVÆMD Mánuğur inn ?"
      : STRING [2]

      Ár_inn (Hm24)
      "^haus@/^fsvar@/^strik@/
       FRAMKVÆMD Ár inn ?"
      : STRING [4]

       Fjöldi_mánağa (Hm25)
      "^haus@/^fsvar@/^strik@/
       FRAMKVÆMD Fjöldi mánağa  ?"
      : STRING [2]

      Stağa_heimilis (Hm26)
      "^haus@/^fsvar@/^strik@/
       FRAMKVÆMD Stağa heimilis ?"
      : STRING [1]

      HmNırMánuğur        "^haus@/^fsvar@/^strik@/
                            Í hvağa mánuği flutti ^Heimilismağur[NúmerHeimilismanns].nafn inn á heimiliğ ?
                            @/@/@GEf svarandi flutti inn á nıtt heimili şar sem fyrir voru allir heimilismenn sem hann hefur tilgreint til şessa,
                            şá skal skrá inn mánuğ og ár sem svarandi flutti inn á heimiliğ. Miğa skal viğ ağ skrá inn tímann şegar svarandi og
                            ağrir heimilismenn urğu ağ heimili.@G"
                          "^haus@/^fsvar@/^strik@/
                            Which month did ^Heimilismağur[NúmerHeimilismanns].nafn move into the household?
                            @/@/@GEf svarandi flutti inn á nıtt heimili şar sem fyrir voru allir heimilismenn sem hann hefur tilgreint til şessa,
                            şá skal skrá inn mánuğ og ár sem svarandi flutti inn á heimiliğ. Miğa skal viğ ağ skrá inn tímann şegar svarandi og
                            ağrir heimilismenn urğu ağ heimili.@G"
                           / "Hvağa mánuği"
                           : TMánuğir


      HmNırMánuğurGisk    "^haus@/^fsvar@/^strik@/
                            En ef şú ættir ağ segja şína bestu ágiskun. Í hvağa mánuği heldur şú ağ ^Heimilismağur[NúmerHeimilismanns].nafn hafi flutt inn á heimiliğ?
                            @/@/@GEf svarandi flutti inn á nıtt heimili şar sem fyrir voru allir heimilismenn sem hann hefur tilgreint til şessa,
                            şá skal skrá inn mánuğ og ár sem svarandi flutti inn á heimiliğ. Miğa skal viğ ağ skrá inn tímann şegar svarandi og
                            ağrir heimilismenn urğu ağ heimili.@G"
                          "^haus@/^fsvar@/^strik@/
                            But if you had to give your best guess. Which month do you think ^Heimilismağur[NúmerHeimilismanns].nafn moved into the household?
                            @/@/@GEf svarandi flutti inn á nıtt heimili şar sem fyrir voru allir heimilismenn sem hann hefur tilgreint til şessa,
                            şá skal skrá inn mánuğ og ár sem svarandi flutti inn á heimiliğ. Miğa skal viğ ağ skrá inn tímann şegar svarandi og
                            ağrir heimilismenn urğu ağ heimili.@G"
                           / "Hvağa mánuği gisk"
                           : TMánuğir


      HmNırÁr              "^haus@/^fsvar@/^strik@/
                            Hvağa ár flutti ^Heimilismağur[NúmerHeimilismanns].nafn inn á heimiliğ?
                            @/@/@GEf svarandi flutti inn á nıtt heimili şar sem fyrir voru allir heimilismenn sem hann hefur tilgreint til şessa,
                            şá skal skrá inn mánuğ og ár sem svarandi flutti inn á heimiliğ. Miğa skal viğ ağ skrá inn tímann şegar svarandi og
                            ağrir heimilismenn urğu ağ heimili.@G"
                            "^haus@/^fsvar@/^strik@/
                            Which year did ^Heimilismağur[NúmerHeimilismanns].nafn move into the household?
                            @/@/@GEf svarandi flutti inn á nıtt heimili şar sem fyrir voru allir heimilismenn sem hann hefur tilgreint til şessa,
                            şá skal skrá inn mánuğ og ár sem svarandi flutti inn á heimiliğ. Miğa skal viğ ağ skrá inn tímann şegar svarandi og
                            ağrir heimilismenn urğu ağ heimili.@G"
                           / "Hvağa ár" : Tártal150

    Fæğingardagur  : DateType
    Alias          : String[50]
    FyrraHmnr      : integer, empty {Fyrra númer heimilismanns}

  AUXFIELDS
    hhann          : STRING
    hhans          : STRING
    hhe            : string
    hhis           : STRING
    hhimself       : STRING
    MakaFj         : INTEGER
    fæğingarár     : INTEGER[4]
    fd             : TJáNei
    viğmiğunarár   : INTEGER[4]
    TnTexti        : string
    inngangur      : string
    preamble       : string
    ggamall        : string
    hhonum         : string
    maki_heimNafn1,maki_heimNafn2,maki_heimNafn3,maki_heimNafn4,maki_heimNafn5,
    maki_heimNafn6,maki_heimNafn7,maki_heimNafn8,maki_heimNafn9,
    maki_heimNafn10,maki_heimNafn11,maki_heimNafn12,maki_heimNafn13,
    maki_heimNafn14,maki_heimNafn15 :STRING

    fadir_heimNafn1,fadir_heimNafn2,fadir_heimNafn3,fadir_heimNafn4,fadir_heimNafn5,
    fadir_heimNafn6,fadir_heimNafn7,fadir_heimNafn8,fadir_heimNafn9,
    fadir_heimNafn10,fadir_heimNafn11,fadir_heimNafn12,fadir_heimNafn13,
    fadir_heimNafn14,fadir_heimNafn15 :STRING

    modir_heimNafn1,modir_heimNafn2,modir_heimNafn3,modir_heimNafn4,modir_heimNafn5,
    modir_heimNafn6,modir_heimNafn7,modir_heimNafn8,modir_heimNafn9,
    modir_heimNafn10,modir_heimNafn11,modir_heimNafn12,modir_heimNafn13,
    modir_heimNafn14,modir_heimNafn15 :STRING


   LOCALS
    öld           : STRING[1]
    fdate         : STRING
    şér, you       : string

   locals i : integer

   RULES

    kennitala.keep
    aldur.keep
    nafn.keep
    fæğingarland.keep
    ríkisfang.keep
    maki.keep
    Brottfluttur.keep
    Óskráğur.keep

    Kennitoluleit.keep
    Kyn.keep
    FæğÁr.keep
    Aldursbil.keep
    Afmæli.keep
    VinAld.keep
    {Tengsl.keep} {fært neğar. Viğ viljum geta breytt Tengsl og einnig mega tengsl brottfluttra heimilismanna ekki verğa eftir}
    Hjú.keep
    {HjúSvar.keep} {fært neğar}
    pk_maka.keep
    pk_fadir.keep
    pk_modir.keep
    nanar_oskyldur.keep
    Upphaflega.keep
    Stağa_í_könnun.keep
    Hvert_flutt.keep
    Mánuğur_flutt.keep
    Ár_flutt .keep
    Mánuğur_inn.keep
    Ár_inn.keep
    Fjöldi_mánağa.keep
    Stağa_heimilis.keep
    HmNırMánuğur.keep
    HmNırMánuğurGisk.keep
    HmNırÁr.keep
    Fæğingardagur.keep
    Alias.keep
    FyrraHmnr.keep

     IF NOT (Persóna IN [karl, kona]) THEN
       şér := fornafn
       you := fornafn
     ELSE
       şér := 'şér'
       you := 'you'
     ENDIF
     viğmiğunarár.keep
     viğmiğunarár := year(viğmiğunardagur)
     Brottfluttur.KEEP
     Brottfluttur := Farinn
     Óskráğur.keep
     Óskráğur  := Nır
     IF Farinn = Já THEN
       nafn.keep
       kennitala.keep
       kyn.keep
       aldur.keep
       fæğingarland.keep
       ríkisfang.keep
       maki.keep
       Fæğár.keep
       Afmæli.keep
       VinAld.keep
       {Tengsl.keep}
       Hjú.keep
       Alias.keep
       fæğingardagur.keep
       prc_Skyldleiki (Tengsl, Kyn, TnTexti)
       Alias := Nafn + ', ' + TnTexti+ ', ' + str(aldur) + ' ára'
     ELSEIF Nır = Já or Nır = Nei THEN {heimilismağur sem ekki er forskráğur}
       if Nır = nei and len(kennitala) > 0 then
         fsvar := '@c'+Nafn+'@c'
         Kennitala.KEEP
         IF Substring(Kennitala,10,1) < '8' THEN Öld := '2' ELSE Öld := '1' ENDIF
         aldur.keep
         fæğingarland.keep
         ríkisfang.keep
         maki.keep
         if (FæğÁr = empty) and (kennitala <> empty) then
           FæğÁr := Val(Öld + Substring(Kennitala,10,1) + Substring(Kennitala,5,2))
         endif
         IF aldur >= 16  THEN      {Spurt um alla 16 ára og eldri í SILC}
           VinAld := Já
         ELSE
           VinAld := Nei
         ENDIF
         prc_Skyldleiki (Tengsl, Kyn, TnTexti)
         Alias := Nafn + ', ' + TnTexti+ ', ' + str(aldur) + ' ára'
         if (fæğingardagur = empty) and (kennitala <> empty) then
           fæğingardagur := strToDate(Substring(Kennitala,1,2)+'.'+Substring(Kennitala,3,2)+'.'+Str(FæğÁr))
         endif
       endif
       fsvar := ''
       if umferd = 1 then
         Nafn {hér mætti spyrja um nafn heimilismannsins}
         Kyn {ef kennitala heimilismannsins finnst í şjóğskrá mætti úthluta kyninu}
       endif
       Kennitala.KEEP {hér mætti spyrja um kennitölu heimilismannsins}
       Brottfluttur.KEEP
       Óskráğur.KEEP

       fæğingarland.keep
       ríkisfang.keep
       maki.keep

       if umferd = 1 then
         IF Kyn = Karl THEN
           hhann       := 'hann'
           hhans       := 'hans'
           hhis        := 'his'
           hhe         := 'he'
           hhimself    := 'himself'
           n           := 'n'
           ur          := 'ur'
           ill         := 'ill'
           gifst       := 'kvænst'
           giftur      := 'Kvæntur'
           fsvar       := '@cKarlmağur@c'
           ggamall     := 'gamall'
           hhonum      := 'honum'
         ELSEIF Kyn = Kona THEN
           hhann       := 'hún'
           hhans       := 'hennar'
           hhe         := 'she'
           hhis        := 'her'
           hhimself    := 'herself'
           n           := ''
           ur          := ''
           ill         := 'ja'
           gifst       := 'gifst'
           giftur      := 'Gift'
           fsvar       := '@cKvenmağur@c'
           ggamall     := 'gömul'
           hhonum      := 'henni'
         ELSE
           hhann       := 'hann/hún'
           hhans       := 'hans/hennar'
           hhe         := 'he/she'
           hhis        := 'his/her'
           hhimself    := 'him/herself'
           n           := '/n'
           ur          := '/ur'
           ill         := 'ill/ja'
           gifst       := 'gifst'
           giftur      := 'Gift/ur'
           fsvar       := '@cKyn óvíst@c'
           ggamall      := 'gamall/gömul'
           hhonum      := 'honum/henni'
         ENDIF
       elseif umferd = 2 then
         IF Kyn_seinni_hluti = Karl THEN
           hhann       := 'hann'
           hhans       := 'hans'
           hhis        := 'his'
           hhe         := 'he'
           hhimself    := 'himself'
           n           := 'n'
           ur          := 'ur'
           ill         := 'ill'
           gifst       := 'kvænst'
           giftur      := 'Kvæntur'
           fsvar       := '@cKarlmağur@c'
           ggamall     := 'gamall'
           hhonum      := 'honum'
         ELSEIF Kyn_seinni_hluti = Kona THEN
           hhann       := 'hún'
           hhans       := 'hennar'
           hhe         := 'she'
           hhis        := 'her'
           hhimself    := 'herself'
           n           := ''
           ur          := ''
           ill         := 'ja'
           gifst       := 'gifst'
           giftur      := 'Gift'
           fsvar       := '@cKvenmağur@c'
           ggamall     := 'gömul'
           hhonum      := 'henni'
         ELSE
           hhann       := 'hann/hún'
           hhans       := 'hans/hennar'
           hhe         := 'he/she'
           hhis        := 'his/her'
           hhimself    := 'him/herself'
           n           := '/n'
           ur          := '/ur'
           ill         := 'ill/ja'
           gifst       := 'gifst'
           giftur      := 'Gift/ur'
           fsvar       := '@cKyn óvíst@c'
           ggamall      := 'gamall/gömul'
           hhonum      := 'honum/henni'
         ENDIF
       endif

       if umferd = 1 then
         FæğÁr

       {Hér şarf ağ koma Y2K tékk:}
       IF FæğÁr = RESPONSE THEN
         IF FæğÁr< 1000 THEN
           FæğÁr>= 1000 "Áriğ verğur ağ vera 4 tölustafir !"
         ENDIF
       ENDIF
       if FæğÁr = Response then
         aldur := max((year(viğmiğunardagur_aldurs) - FæğÁr),0)
       else
         aldur := 0  {setur sjálfgefiğ gildi, şyrfti ağ skoğa hvernir eru 0 ára}
       endif
       aldur.SHOW



       IF FæğÁr = Year(viğmiğunardagur) THEN
         Aldur   := 0
         VinAld := Nei
       ELSEIF FæğÁr = RESPONSE THEN
         IF Aldur >= 16 THEN  {Í SILCI geta allir 16 ára og eldri veriğ í vinnu}
           VinAld := Já
         ELSE
           VinAld := Nei
         ENDIF
         VinAld.show
       ELSE
         Aldursbil
         if (Aldursbil = tilfimm) then
           aldur := 5
           VinAld := Nei
         elseif (Aldursbil = sex ) then
           aldur := 12
           VinAld := Nei
         elseif (Aldursbil = şrettán) then
           Aldur := 13
           VinAld := Nei
         elseif (Aldursbil = sextán) or (Aldursbil = tuttugu) then
           Aldur := 16
           VinAld := Já
         elseif (Aldursbil = t25) or (Aldursbil = t30) or (Aldursbil = t40) or (Aldursbil = t50) or (Aldursbil = t55) or (Aldursbil = t60) then
           Aldur := 25
           VinAld := Já
         elseif (Aldursbil = t67) then
           Aldur := 67
           VinAld := Já
         elseif (Aldursbil = t75) or (Aldursbil = t80) then
           Aldur := 75
           VinAld := Nei
         else
           VinAld
           if VinAld = já then
             Aldur := 16
           else
             Aldur := dk
           endif
         endif
         if aldur <> dk then
           FæğÁr := year(viğmiğunardagur_aldurs) - aldur
         endif
       ENDIF

       {AÖK 211107}
       kennitoluleit
        if brottfluttur = já
        then tengsl := empty
             hjúsvar :=empty
        endif

        endif{endir á umferğ 1}
       if umferd = 1 then
         Tengsl
         tengsl.keep
       endif
       prc_Skyldleiki (Tengsl, Kyn, TnTexti)
       fsvar := '@c'+TnTexti+'@c'
       Hjú.show
       IF tengsl = maki and brottfluttur = nei
        then hjúsvar := sambud
             hjúsvar.show
        elseif tengsl <> maki and  umferd = 1 and (aldur > 15 or FæğÁr = dk) THEN
           Hjúsvar
        endif
       HjúSvar.keep
       if umferd = 2 then

        IF hjusvar_1 = 1
            then (heimilismağur[2].tengsl = maki and heimilismağur[2].brottfluttur = nei)
              or (heimilismağur[3].tengsl = maki and heimilismağur[3].brottfluttur = nei)
              or (heimilismağur[4].tengsl = maki and heimilismağur[4].brottfluttur = nei)
              or (heimilismağur[5].tengsl = maki and heimilismağur[5].brottfluttur = nei)
              or (heimilismağur[6].tengsl = maki and heimilismağur[6].brottfluttur = nei)
              or (heimilismağur[7].tengsl = maki and heimilismağur[7].brottfluttur = nei)
              or (heimilismağur[8].tengsl = maki and heimilismağur[8].brottfluttur = nei)
              or (heimilismağur[9].tengsl = maki and heimilismağur[9].brottfluttur = nei)
              or (heimilismağur[10].tengsl = maki and heimilismağur[10].brottfluttur = nei)
              or (heimilismağur[11].tengsl = maki and heimilismağur[11].brottfluttur = nei)
              or (heimilismağur[12].tengsl = maki and heimilismağur[12].brottfluttur = nei)
              or (heimilismağur[13].tengsl = maki and heimilismağur[13].brottfluttur = nei)
              or (heimilismağur[14].tengsl = maki and heimilismağur[14].brottfluttur = nei)
              or (heimilismağur[15].tengsl = maki and heimilismağur[15].brottfluttur = nei)
              "Einhver heimilismanna er í sambúğ meğ svaranda, en hann hefur ekki veriğ merktur sem maki hans."
        ENDIF


        IF hjusvar_1 = 0
            then (heimilismağur[2].tengsl <> maki or heimilismağur[2].brottfluttur = já)
              and (heimilismağur[3].tengsl <> maki  or heimilismağur[3].brottfluttur = já)
              and (heimilismağur[4].tengsl <> maki  or heimilismağur[4].brottfluttur = já)
              and (heimilismağur[5].tengsl <> maki  or heimilismağur[5].brottfluttur = já)
              and (heimilismağur[6].tengsl <> maki  or heimilismağur[6].brottfluttur = já)
              and (heimilismağur[7].tengsl <> maki  or heimilismağur[7].brottfluttur = já)
              and (heimilismağur[8].tengsl <> maki  or heimilismağur[8].brottfluttur = já)
              and (heimilismağur[9].tengsl <> maki  or heimilismağur[9].brottfluttur = já)
              and (heimilismağur[10].tengsl <> maki or heimilismağur[10].brottfluttur = já)
              and (heimilismağur[11].tengsl <> maki or heimilismağur[11].brottfluttur = já)
              and (heimilismağur[12].tengsl <> maki or heimilismağur[12].brottfluttur = já)
              and (heimilismağur[13].tengsl <> maki or heimilismağur[13].brottfluttur = já)
              and (heimilismağur[14].tengsl <> maki or heimilismağur[14].brottfluttur = já)
              and (heimilismağur[15].tengsl <> maki or heimilismağur[15].brottfluttur = já)
              "Einhver heimilismanna er skráğur í sambúğ meğ svaranda, svarandi virğist ekki vera í sambúğ."
        ENDIF


            IF ((NúmerHeimilismanns <> 2 )
                and (heimilismağur[2].aldur >= 16)
                and (heimilismağur[2].hjúsvar = sambud)
                and (heimilismağur[2].tengsl <> maki)
                and (heimilismağur[2].brottfluttur = nei))
                then maki_heimNafn2 := Heimilismağur[2].Nafn
                endif
            IF ((NúmerHeimilismanns <> 3 )
                and (heimilismağur[3].aldur >= 16)
                and (heimilismağur[3].hjúsvar = sambud)
                and (heimilismağur[3].tengsl <> maki)
                and (heimilismağur[3].brottfluttur = nei))
                then maki_heimNafn3 := Heimilismağur[3].Nafn
                endif
            IF ((NúmerHeimilismanns <> 4 )
                and (heimilismağur[4].aldur >= 16)
                and (heimilismağur[4].hjúsvar = sambud)
                and (heimilismağur[4].tengsl <> maki)
                and (heimilismağur[4].brottfluttur = nei))
                then maki_heimNafn4 := Heimilismağur[4].Nafn
                endif
            IF ((NúmerHeimilismanns <> 5 )
                and (heimilismağur[5].aldur >= 16)
                and (heimilismağur[5].hjúsvar = sambud)
                and (heimilismağur[5].tengsl <> maki)
                and (heimilismağur[5].brottfluttur = nei))
                then maki_heimNafn5 := Heimilismağur[5].Nafn
                endif
            IF ((NúmerHeimilismanns <> 6 )
                and (heimilismağur[6].aldur >= 16)
                and (heimilismağur[6].hjúsvar = sambud)
                and (heimilismağur[6].tengsl <> maki)
                and (heimilismağur[6].brottfluttur = nei))
                then maki_heimNafn6 := Heimilismağur[6].Nafn
                endif
            IF ((NúmerHeimilismanns <> 7 )
                and (heimilismağur[7].aldur >= 16)
                and (heimilismağur[7].hjúsvar = sambud)
                and (heimilismağur[7].tengsl <> maki)
                and (heimilismağur[7].brottfluttur = nei))
                then maki_heimNafn7 := Heimilismağur[7].Nafn
                endif
            IF ((NúmerHeimilismanns <> 8 )
                and (heimilismağur[8].aldur >= 16)
                and (heimilismağur[8].hjúsvar = sambud)
                and (heimilismağur[8].tengsl <> maki)
                and (heimilismağur[8].brottfluttur = nei))
                then maki_heimNafn8 := Heimilismağur[8].Nafn
                endif
            IF ((NúmerHeimilismanns <> 9 )
                and (heimilismağur[9].aldur >= 16)
                and (heimilismağur[9].hjúsvar = sambud)
                and (heimilismağur[9].tengsl <> maki)
                and (heimilismağur[9].brottfluttur = nei))
                then maki_heimNafn9 := Heimilismağur[9].Nafn
                endif
            IF ((NúmerHeimilismanns <> 10 )
                and (heimilismağur[10].aldur >= 16)
                and (heimilismağur[10].hjúsvar = sambud)
                and (heimilismağur[10].tengsl <> maki)
                and (heimilismağur[10].brottfluttur = nei))
                then maki_heimNafn10 := Heimilismağur[10].Nafn
                endif
            IF ((NúmerHeimilismanns <> 11 )
                and (heimilismağur[11].aldur >= 16)
                and (heimilismağur[11].hjúsvar = sambud)
                and (heimilismağur[11].tengsl <> maki)
                and (heimilismağur[11].brottfluttur = nei))
                then maki_heimNafn11 := Heimilismağur[11].Nafn
                endif
            IF ((NúmerHeimilismanns <> 12 )
                and (heimilismağur[12].aldur >= 16)
                and (heimilismağur[12].hjúsvar = sambud)
                and (heimilismağur[12].tengsl <> maki)
                and (heimilismağur[12].brottfluttur = nei))
                then maki_heimNafn12 := Heimilismağur[12].Nafn
                endif
            IF ((NúmerHeimilismanns <> 13 )
                and (heimilismağur[13].aldur >= 16)
                and (heimilismağur[13].hjúsvar = sambud)
                and (heimilismağur[13].tengsl <> maki)
                and (heimilismağur[13].brottfluttur = nei))
                then maki_heimNafn13 := Heimilismağur[13].Nafn
                endif
            IF ((NúmerHeimilismanns <> 14 )
                and (heimilismağur[14].aldur >= 16)
                and (heimilismağur[14].hjúsvar = sambud)
                and (heimilismağur[14].tengsl <> maki)
                and (heimilismağur[14].brottfluttur = nei))
                then maki_heimNafn14 := Heimilismağur[14].Nafn
                endif
            IF ((NúmerHeimilismanns <> 15 )
                and (heimilismağur[15].aldur >= 16)
                and (heimilismağur[15].hjúsvar = sambud)
                and (heimilismağur[15].tengsl <> maki)
                and (heimilismağur[15].brottfluttur = nei))
                then maki_heimNafn15 := Heimilismağur[15].Nafn
                endif


            IF ((NúmerHeimilismanns <> 2 )
                and (heimilismağur[2].kyn = karl)
                and ((heimilismağur[2].aldur - heimilismağur[NúmerHeimilismanns].aldur) > 15)
                and (((heimilismağur[2].brottfluttur = nei))))
                then fadir_heimNafn2 := Heimilismağur[2].Nafn
                endif
            IF ((NúmerHeimilismanns <> 3 )
                and (heimilismağur[3].kyn = karl)
                and ((heimilismağur[3].aldur - heimilismağur[NúmerHeimilismanns].aldur) > 15)
                and (((heimilismağur[3].brottfluttur = nei))))
                then fadir_heimNafn3 := Heimilismağur[3].Nafn
                endif
            IF ((NúmerHeimilismanns <> 4 )
                and (heimilismağur[4].kyn = karl)
                and ((heimilismağur[4].aldur - heimilismağur[NúmerHeimilismanns].aldur) > 15)
                and (((heimilismağur[4].brottfluttur = nei))))
                then fadir_heimNafn4 := Heimilismağur[4].Nafn
                endif
            IF ((NúmerHeimilismanns <> 5 )
                and (heimilismağur[5].kyn = karl)
                and ((heimilismağur[5].aldur - heimilismağur[NúmerHeimilismanns].aldur) > 15)
                and (((heimilismağur[5].brottfluttur = nei))))
                then fadir_heimNafn5 := Heimilismağur[5].Nafn
                endif
            IF ((NúmerHeimilismanns <> 6 )
                and (heimilismağur[6].kyn = karl)
                and ((heimilismağur[6].aldur - heimilismağur[NúmerHeimilismanns].aldur) > 15)
                and (((heimilismağur[6].brottfluttur = nei))))
                then fadir_heimNafn6 := Heimilismağur[6].Nafn
                endif
            IF ((NúmerHeimilismanns <> 7 )
                and (heimilismağur[7].kyn = karl)
                and ((heimilismağur[7].aldur - heimilismağur[NúmerHeimilismanns].aldur) > 15)
                and (((heimilismağur[7].brottfluttur = nei))))
                then fadir_heimNafn7 := Heimilismağur[7].Nafn
                endif
            IF ((NúmerHeimilismanns <> 8 )
                and (heimilismağur[8].kyn = karl)
                and ((heimilismağur[8].aldur - heimilismağur[NúmerHeimilismanns].aldur) > 15)
                and (((heimilismağur[8].brottfluttur = nei))))
                then fadir_heimNafn8 := Heimilismağur[8].Nafn
                endif
            IF ((NúmerHeimilismanns <> 9 )
                and (heimilismağur[9].kyn = karl)
                and ((heimilismağur[9].aldur - heimilismağur[NúmerHeimilismanns].aldur) > 15)
                and (((heimilismağur[9].brottfluttur = nei))))
                then fadir_heimNafn9 := Heimilismağur[9].Nafn
                endif
            IF ((NúmerHeimilismanns <> 10 )
                and (heimilismağur[10].kyn = karl)
                and ((heimilismağur[10].aldur - heimilismağur[NúmerHeimilismanns].aldur) > 15)
                and (((heimilismağur[10].brottfluttur = nei))))
                then fadir_heimNafn10 := Heimilismağur[10].Nafn
                endif
            IF ((NúmerHeimilismanns <> 11 )
                and (heimilismağur[11].kyn = karl)
                and ((heimilismağur[11].aldur - heimilismağur[NúmerHeimilismanns].aldur) > 15)
                and (((heimilismağur[11].brottfluttur = nei))))
                then fadir_heimNafn11 := Heimilismağur[11].Nafn
                endif
            IF ((NúmerHeimilismanns <> 12 )
                and (heimilismağur[12].kyn = karl)
                and ((heimilismağur[12].aldur - heimilismağur[NúmerHeimilismanns].aldur) > 15)
                and (((heimilismağur[12].brottfluttur = nei))))
                then fadir_heimNafn12 := Heimilismağur[12].Nafn
                endif
            IF ((NúmerHeimilismanns <> 13 )
                and (heimilismağur[13].kyn = karl)
                and ((heimilismağur[13].aldur - heimilismağur[NúmerHeimilismanns].aldur) > 15)
                and (((heimilismağur[13].brottfluttur = nei))))
                then fadir_heimNafn13 := Heimilismağur[13].Nafn
                endif
            IF ((NúmerHeimilismanns <> 14 )
                and (heimilismağur[14].kyn = karl)
                and ((heimilismağur[14].aldur - heimilismağur[NúmerHeimilismanns].aldur) > 15)
                and (((heimilismağur[14].brottfluttur = nei))))
                then fadir_heimNafn14 := Heimilismağur[14].Nafn
                endif
            IF ((NúmerHeimilismanns <> 15 )
                and (heimilismağur[15].kyn = karl)
                and ((heimilismağur[15].aldur - heimilismağur[NúmerHeimilismanns].aldur) > 15)
                and (((heimilismağur[15].brottfluttur = nei))))
                then fadir_heimNafn15 := Heimilismağur[15].Nafn
                endif


            IF ((NúmerHeimilismanns <> 2 )
                and (heimilismağur[2].kyn = kona)
                and ((heimilismağur[2].aldur - heimilismağur[NúmerHeimilismanns].aldur) > 15)
                and (((heimilismağur[2].brottfluttur = nei))))
                then modir_heimNafn2 := Heimilismağur[2].Nafn
                endif
            IF ((NúmerHeimilismanns <> 3 )
                and (heimilismağur[3].kyn = kona)
                and ((heimilismağur[3].aldur - heimilismağur[NúmerHeimilismanns].aldur) > 15)
                and (((heimilismağur[3].brottfluttur = nei))))
                then modir_heimNafn3 := Heimilismağur[3].Nafn
                endif
            IF ((NúmerHeimilismanns <> 4 )
                and (heimilismağur[4].kyn = kona)
                and ((heimilismağur[4].aldur - heimilismağur[NúmerHeimilismanns].aldur) > 15)
                and (((heimilismağur[4].brottfluttur = nei))))
                then modir_heimNafn4 := Heimilismağur[4].Nafn
                endif
            IF ((NúmerHeimilismanns <> 5 )
                and (heimilismağur[5].kyn = kona)
                and ((heimilismağur[5].aldur - heimilismağur[NúmerHeimilismanns].aldur) > 15)
                and (((heimilismağur[5].brottfluttur = nei))))
                then modir_heimNafn5 := Heimilismağur[5].Nafn
                endif
            IF ((NúmerHeimilismanns <> 6 )
                and (heimilismağur[6].kyn = kona)
                and ((heimilismağur[6].aldur - heimilismağur[NúmerHeimilismanns].aldur) > 15)
                and (((heimilismağur[6].brottfluttur = nei))))
                then modir_heimNafn6 := Heimilismağur[6].Nafn
                endif
            IF ((NúmerHeimilismanns <> 7 )
                and (heimilismağur[7].kyn = kona)
                and ((heimilismağur[7].aldur - heimilismağur[NúmerHeimilismanns].aldur) > 15)
                and (((heimilismağur[7].brottfluttur = nei))))
                then modir_heimNafn7 := Heimilismağur[7].Nafn
                endif
            IF ((NúmerHeimilismanns <> 8 )
                and (heimilismağur[8].kyn = kona)
                and ((heimilismağur[8].aldur - heimilismağur[NúmerHeimilismanns].aldur) > 15)
                and (((heimilismağur[8].brottfluttur = nei))))
                then modir_heimNafn8 := Heimilismağur[8].Nafn
                endif
            IF ((NúmerHeimilismanns <> 9 )
                and (heimilismağur[9].kyn = kona)
                and ((heimilismağur[9].aldur - heimilismağur[NúmerHeimilismanns].aldur) > 15)
                and (((heimilismağur[9].brottfluttur = nei))))
                then modir_heimNafn9 := Heimilismağur[9].Nafn
                endif
            IF ((NúmerHeimilismanns <> 10 )
                and (heimilismağur[10].kyn = kona)
                and ((heimilismağur[10].aldur - heimilismağur[NúmerHeimilismanns].aldur) > 15)
                and (((heimilismağur[10].brottfluttur = nei))))
                then modir_heimNafn10 := Heimilismağur[10].Nafn
                endif
            IF ((NúmerHeimilismanns <> 11 )
                and (heimilismağur[11].kyn = kona)
                and ((heimilismağur[11].aldur - heimilismağur[NúmerHeimilismanns].aldur) > 15)
                and (((heimilismağur[11].brottfluttur = nei))))
                then modir_heimNafn11 := Heimilismağur[11].Nafn
                endif
            IF ((NúmerHeimilismanns <> 12 )
                and (heimilismağur[12].kyn = kona)
                and ((heimilismağur[12].aldur - heimilismağur[NúmerHeimilismanns].aldur) > 15)
                and (((heimilismağur[12].brottfluttur = nei))))
                then modir_heimNafn12 := Heimilismağur[12].Nafn
                endif
            IF ((NúmerHeimilismanns <> 13 )
                and (heimilismağur[13].kyn = kona)
                and ((heimilismağur[13].aldur - heimilismağur[NúmerHeimilismanns].aldur) > 15)
                and (((heimilismağur[13].brottfluttur = nei))))
                then modir_heimNafn13 := Heimilismağur[13].Nafn
                endif
            IF ((NúmerHeimilismanns <> 14 )
                and (heimilismağur[14].kyn = kona)
                and ((heimilismağur[14].aldur - heimilismağur[NúmerHeimilismanns].aldur) > 15)
                and (((heimilismağur[14].brottfluttur = nei))))
                then modir_heimNafn14 := Heimilismağur[14].Nafn
                endif
            IF ((NúmerHeimilismanns <> 15 )
                and (heimilismağur[15].kyn = kona)
                and ((heimilismağur[15].aldur - heimilismağur[NúmerHeimilismanns].aldur) > 15)
                and (((heimilismağur[15].brottfluttur = nei))))
                then modir_heimNafn15 := Heimilismağur[15].Nafn
                endif

         IF heimilismağur[2].tengsl = maki
            then (heimilismağur[3].tengsl <> maki or heimilismağur[3].brottfluttur = já)
                 and (heimilismağur[4].tengsl <> maki or heimilismağur[4].brottfluttur = já)
                 and (heimilismağur[5].tengsl <> maki or heimilismağur[5].brottfluttur = já)
                 and (heimilismağur[6].tengsl <> maki or heimilismağur[6].brottfluttur = já)
                 and (heimilismağur[7].tengsl <> maki or heimilismağur[7].brottfluttur = já)
                 and (heimilismağur[8].tengsl <> maki or heimilismağur[8].brottfluttur = já)
                 and (heimilismağur[9].tengsl <> maki or heimilismağur[9].brottfluttur = já)
                 and (heimilismağur[10].tengsl <> maki or heimilismağur[10].brottfluttur = já)
                 and (heimilismağur[11].tengsl <> maki or heimilismağur[11].brottfluttur = já)
                 and (heimilismağur[12].tengsl <> maki or heimilismağur[12].brottfluttur = já)
                 and (heimilismağur[13].tengsl <> maki or heimilismağur[13].brottfluttur = já)
                 and (heimilismağur[14].tengsl <> maki or heimilismağur[14].brottfluttur = já)
                 and (heimilismağur[15].tengsl <> maki or heimilismağur[15].brottfluttur = já)
                 "Heimilismağur 1 getur ağeins átt einn maka" ENDIF

         IF heimilismağur[3].tengsl = maki
            then (heimilismağur[2].tengsl <> maki or heimilismağur[2].brottfluttur = já)
                 and (heimilismağur[4].tengsl <> maki or heimilismağur[4].brottfluttur = já)
                 and (heimilismağur[5].tengsl <> maki or heimilismağur[5].brottfluttur = já)
                 and (heimilismağur[6].tengsl <> maki or heimilismağur[6].brottfluttur = já)
                 and (heimilismağur[7].tengsl <> maki or heimilismağur[7].brottfluttur = já)
                 and (heimilismağur[8].tengsl <> maki or heimilismağur[8].brottfluttur = já)
                 and (heimilismağur[9].tengsl <> maki or heimilismağur[9].brottfluttur = já)
                 and (heimilismağur[10].tengsl <> maki or heimilismağur[10].brottfluttur = já)
                 and (heimilismağur[11].tengsl <> maki or heimilismağur[11].brottfluttur = já)
                 and (heimilismağur[12].tengsl <> maki or heimilismağur[12].brottfluttur = já)
                 and (heimilismağur[13].tengsl <> maki or heimilismağur[13].brottfluttur = já)
                 and (heimilismağur[14].tengsl <> maki or heimilismağur[14].brottfluttur = já)
                 and (heimilismağur[15].tengsl <> maki or heimilismağur[15].brottfluttur = já)
                 "Heimilismağur 1 getur ağeins átt einn maka" ENDIF

         IF heimilismağur[4].tengsl = maki
            then (heimilismağur[2].tengsl <> maki or heimilismağur[2].brottfluttur = já)
                 and (heimilismağur[3].tengsl <> maki or heimilismağur[3].brottfluttur = já)
                 and (heimilismağur[5].tengsl <> maki or heimilismağur[5].brottfluttur = já)
                 and (heimilismağur[6].tengsl <> maki or heimilismağur[6].brottfluttur = já)
                 and (heimilismağur[7].tengsl <> maki or heimilismağur[7].brottfluttur = já)
                 and (heimilismağur[8].tengsl <> maki or heimilismağur[8].brottfluttur = já)
                 and (heimilismağur[9].tengsl <> maki or heimilismağur[9].brottfluttur = já)
                 and (heimilismağur[10].tengsl <> maki or heimilismağur[10].brottfluttur = já)
                 and (heimilismağur[11].tengsl <> maki or heimilismağur[11].brottfluttur = já)
                 and (heimilismağur[12].tengsl <> maki or heimilismağur[12].brottfluttur = já)
                 and (heimilismağur[13].tengsl <> maki or heimilismağur[13].brottfluttur = já)
                 and (heimilismağur[14].tengsl <> maki or heimilismağur[14].brottfluttur = já)
                 and (heimilismağur[15].tengsl <> maki or heimilismağur[15].brottfluttur = já)
                 "Heimilismağur 1 getur ağeins átt einn maka" ENDIF

         IF heimilismağur[5].tengsl = maki
            then (heimilismağur[2].tengsl <> maki or heimilismağur[2].brottfluttur = já)
                 and (heimilismağur[3].tengsl <> maki or heimilismağur[3].brottfluttur = já)
                 and (heimilismağur[4].tengsl <> maki or heimilismağur[4].brottfluttur = já)
                 and (heimilismağur[6].tengsl <> maki or heimilismağur[6].brottfluttur = já)
                 and (heimilismağur[7].tengsl <> maki or heimilismağur[7].brottfluttur = já)
                 and (heimilismağur[8].tengsl <> maki or heimilismağur[8].brottfluttur = já)
                 and (heimilismağur[9].tengsl <> maki or heimilismağur[9].brottfluttur = já)
                 and (heimilismağur[10].tengsl <> maki or heimilismağur[10].brottfluttur = já)
                 and (heimilismağur[11].tengsl <> maki or heimilismağur[11].brottfluttur = já)
                 and (heimilismağur[12].tengsl <> maki or heimilismağur[12].brottfluttur = já)
                 and (heimilismağur[13].tengsl <> maki or heimilismağur[13].brottfluttur = já)
                 and (heimilismağur[14].tengsl <> maki or heimilismağur[14].brottfluttur = já)
                 and (heimilismağur[15].tengsl <> maki or heimilismağur[15].brottfluttur = já)
                 "Heimilismağur 1 getur ağeins átt einn maka" ENDIF

         IF heimilismağur[6].tengsl = maki
            then (heimilismağur[2].tengsl <> maki or heimilismağur[2].brottfluttur = já)
                 and (heimilismağur[3].tengsl <> maki or heimilismağur[3].brottfluttur = já)
                 and (heimilismağur[4].tengsl <> maki or heimilismağur[4].brottfluttur = já)
                 and (heimilismağur[5].tengsl <> maki or heimilismağur[5].brottfluttur = já)
                 and (heimilismağur[7].tengsl <> maki or heimilismağur[7].brottfluttur = já)
                 and (heimilismağur[8].tengsl <> maki or heimilismağur[8].brottfluttur = já)
                 and (heimilismağur[9].tengsl <> maki or heimilismağur[9].brottfluttur = já)
                 and (heimilismağur[10].tengsl <> maki or heimilismağur[10].brottfluttur = já)
                 and (heimilismağur[11].tengsl <> maki or heimilismağur[11].brottfluttur = já)
                 and (heimilismağur[12].tengsl <> maki or heimilismağur[12].brottfluttur = já)
                 and (heimilismağur[13].tengsl <> maki or heimilismağur[13].brottfluttur = já)
                 and (heimilismağur[14].tengsl <> maki or heimilismağur[14].brottfluttur = já)
                 and (heimilismağur[15].tengsl <> maki or heimilismağur[15].brottfluttur = já)
                 "Heimilismağur 1 getur ağeins átt einn maka" ENDIF

         IF heimilismağur[7].tengsl = maki
            then (heimilismağur[2].tengsl <> maki or heimilismağur[2].brottfluttur = já)
                 and (heimilismağur[3].tengsl <> maki or heimilismağur[3].brottfluttur = já)
                 and (heimilismağur[4].tengsl <> maki or heimilismağur[4].brottfluttur = já)
                 and (heimilismağur[5].tengsl <> maki or heimilismağur[5].brottfluttur = já)
                 and (heimilismağur[6].tengsl <> maki or heimilismağur[6].brottfluttur = já)
                 and (heimilismağur[8].tengsl <> maki or heimilismağur[8].brottfluttur = já)
                 and (heimilismağur[9].tengsl <> maki or heimilismağur[9].brottfluttur = já)
                 and (heimilismağur[10].tengsl <> maki or heimilismağur[10].brottfluttur = já)
                 and (heimilismağur[11].tengsl <> maki or heimilismağur[11].brottfluttur = já)
                 and (heimilismağur[12].tengsl <> maki or heimilismağur[12].brottfluttur = já)
                 and (heimilismağur[13].tengsl <> maki or heimilismağur[13].brottfluttur = já)
                 and (heimilismağur[14].tengsl <> maki or heimilismağur[14].brottfluttur = já)
                 and (heimilismağur[15].tengsl <> maki or heimilismağur[15].brottfluttur = já)
                 "Heimilismağur 1 getur ağeins átt einn maka" ENDIF

         IF heimilismağur[8].tengsl = maki
            then (heimilismağur[2].tengsl <> maki or heimilismağur[2].brottfluttur = já)
                 and (heimilismağur[3].tengsl <> maki or heimilismağur[3].brottfluttur = já)
                 and (heimilismağur[4].tengsl <> maki or heimilismağur[4].brottfluttur = já)
                 and (heimilismağur[5].tengsl <> maki or heimilismağur[5].brottfluttur = já)
                 and (heimilismağur[6].tengsl <> maki or heimilismağur[6].brottfluttur = já)
                 and (heimilismağur[7].tengsl <> maki or heimilismağur[7].brottfluttur = já)
                 and (heimilismağur[9].tengsl <> maki or heimilismağur[9].brottfluttur = já)
                 and (heimilismağur[10].tengsl <> maki or heimilismağur[10].brottfluttur = já)
                 and (heimilismağur[11].tengsl <> maki or heimilismağur[11].brottfluttur = já)
                 and (heimilismağur[12].tengsl <> maki or heimilismağur[12].brottfluttur = já)
                 and (heimilismağur[13].tengsl <> maki or heimilismağur[13].brottfluttur = já)
                 and (heimilismağur[14].tengsl <> maki or heimilismağur[14].brottfluttur = já)
                 and (heimilismağur[15].tengsl <> maki or heimilismağur[15].brottfluttur = já)
                 "Heimilismağur 1 getur ağeins átt einn maka" ENDIF

         IF heimilismağur[9].tengsl = maki
            then (heimilismağur[2].tengsl <> maki or heimilismağur[2].brottfluttur = já)
                 and (heimilismağur[3].tengsl <> maki or heimilismağur[3].brottfluttur = já)
                 and (heimilismağur[4].tengsl <> maki or heimilismağur[4].brottfluttur = já)
                 and (heimilismağur[5].tengsl <> maki or heimilismağur[5].brottfluttur = já)
                 and (heimilismağur[6].tengsl <> maki or heimilismağur[6].brottfluttur = já)
                 and (heimilismağur[7].tengsl <> maki or heimilismağur[7].brottfluttur = já)
                 and (heimilismağur[8].tengsl <> maki or heimilismağur[8].brottfluttur = já)
                 and (heimilismağur[10].tengsl <> maki or heimilismağur[10].brottfluttur = já)
                 and (heimilismağur[11].tengsl <> maki or heimilismağur[11].brottfluttur = já)
                 and (heimilismağur[12].tengsl <> maki or heimilismağur[12].brottfluttur = já)
                 and (heimilismağur[13].tengsl <> maki or heimilismağur[13].brottfluttur = já)
                 and (heimilismağur[14].tengsl <> maki or heimilismağur[14].brottfluttur = já)
                 and (heimilismağur[15].tengsl <> maki or heimilismağur[15].brottfluttur = já)
                 "Heimilismağur 1 getur ağeins átt einn maka" ENDIF

         IF heimilismağur[10].tengsl = maki
            then (heimilismağur[2].tengsl <> maki or heimilismağur[2].brottfluttur = já)
                 and (heimilismağur[3].tengsl <> maki or heimilismağur[3].brottfluttur = já)
                 and (heimilismağur[4].tengsl <> maki or heimilismağur[4].brottfluttur = já)
                 and (heimilismağur[5].tengsl <> maki or heimilismağur[5].brottfluttur = já)
                 and (heimilismağur[6].tengsl <> maki or heimilismağur[6].brottfluttur = já)
                 and (heimilismağur[7].tengsl <> maki or heimilismağur[7].brottfluttur = já)
                 and (heimilismağur[8].tengsl <> maki or heimilismağur[8].brottfluttur = já)
                 and (heimilismağur[9].tengsl <> maki or heimilismağur[9].brottfluttur = já)
                 and (heimilismağur[11].tengsl <> maki or heimilismağur[11].brottfluttur = já)
                 and (heimilismağur[12].tengsl <> maki or heimilismağur[12].brottfluttur = já)
                 and (heimilismağur[13].tengsl <> maki or heimilismağur[13].brottfluttur = já)
                 and (heimilismağur[14].tengsl <> maki or heimilismağur[14].brottfluttur = já)
                 and (heimilismağur[15].tengsl <> maki or heimilismağur[15].brottfluttur = já)
                 "Heimilismağur 1 getur ağeins átt einn maka" ENDIF

         IF heimilismağur[11].tengsl = maki
            then (heimilismağur[2].tengsl <> maki or heimilismağur[2].brottfluttur = já)
                 and (heimilismağur[3].tengsl <> maki or heimilismağur[3].brottfluttur = já)
                 and (heimilismağur[4].tengsl <> maki or heimilismağur[4].brottfluttur = já)
                 and (heimilismağur[5].tengsl <> maki or heimilismağur[5].brottfluttur = já)
                 and (heimilismağur[6].tengsl <> maki or heimilismağur[6].brottfluttur = já)
                 and (heimilismağur[7].tengsl <> maki or heimilismağur[7].brottfluttur = já)
                 and (heimilismağur[8].tengsl <> maki or heimilismağur[8].brottfluttur = já)
                 and (heimilismağur[9].tengsl <> maki or heimilismağur[9].brottfluttur = já)
                 and (heimilismağur[10].tengsl <> maki or heimilismağur[10].brottfluttur = já)
                 and (heimilismağur[12].tengsl <> maki or heimilismağur[12].brottfluttur = já)
                 and (heimilismağur[13].tengsl <> maki or heimilismağur[13].brottfluttur = já)
                 and (heimilismağur[14].tengsl <> maki or heimilismağur[14].brottfluttur = já)
                 and (heimilismağur[15].tengsl <> maki or heimilismağur[15].brottfluttur = já)
                 "Heimilismağur 1 getur ağeins átt einn maka" ENDIF

         IF heimilismağur[12].tengsl = maki
            then (heimilismağur[2].tengsl <> maki or heimilismağur[2].brottfluttur = já)
                 and (heimilismağur[3].tengsl <> maki or heimilismağur[3].brottfluttur = já)
                 and (heimilismağur[4].tengsl <> maki or heimilismağur[4].brottfluttur = já)
                 and (heimilismağur[5].tengsl <> maki or heimilismağur[5].brottfluttur = já)
                 and (heimilismağur[6].tengsl <> maki or heimilismağur[6].brottfluttur = já)
                 and (heimilismağur[7].tengsl <> maki or heimilismağur[7].brottfluttur = já)
                 and (heimilismağur[8].tengsl <> maki or heimilismağur[8].brottfluttur = já)
                 and (heimilismağur[9].tengsl <> maki or heimilismağur[9].brottfluttur = já)
                 and (heimilismağur[10].tengsl <> maki or heimilismağur[10].brottfluttur = já)
                 and (heimilismağur[11].tengsl <> maki or heimilismağur[11].brottfluttur = já)
                 and (heimilismağur[13].tengsl <> maki or heimilismağur[13].brottfluttur = já)
                 and (heimilismağur[14].tengsl <> maki or heimilismağur[14].brottfluttur = já)
                 and (heimilismağur[15].tengsl <> maki or heimilismağur[15].brottfluttur = já)
                 "Heimilismağur 1 getur ağeins átt einn maka" ENDIF

         IF heimilismağur[13].tengsl = maki
            then (heimilismağur[2].tengsl <> maki or heimilismağur[2].brottfluttur = já)
                 and (heimilismağur[3].tengsl <> maki or heimilismağur[3].brottfluttur = já)
                 and (heimilismağur[4].tengsl <> maki or heimilismağur[4].brottfluttur = já)
                 and (heimilismağur[5].tengsl <> maki or heimilismağur[5].brottfluttur = já)
                 and (heimilismağur[6].tengsl <> maki or heimilismağur[6].brottfluttur = já)
                 and (heimilismağur[7].tengsl <> maki or heimilismağur[7].brottfluttur = já)
                 and (heimilismağur[8].tengsl <> maki or heimilismağur[8].brottfluttur = já)
                 and (heimilismağur[9].tengsl <> maki or heimilismağur[9].brottfluttur = já)
                 and (heimilismağur[10].tengsl <> maki or heimilismağur[10].brottfluttur = já)
                 and (heimilismağur[11].tengsl <> maki or heimilismağur[11].brottfluttur = já)
                 and (heimilismağur[12].tengsl <> maki or heimilismağur[12].brottfluttur = já)
                 and (heimilismağur[14].tengsl <> maki or heimilismağur[14].brottfluttur = já)
                 and (heimilismağur[15].tengsl <> maki or heimilismağur[15].brottfluttur = já)
                 "Heimilismağur 1 getur ağeins átt einn maka" ENDIF

         IF heimilismağur[14].tengsl = maki
            then (heimilismağur[2].tengsl <> maki or heimilismağur[2].brottfluttur = já)
                 and (heimilismağur[3].tengsl <> maki or heimilismağur[3].brottfluttur = já)
                 and (heimilismağur[4].tengsl <> maki or heimilismağur[4].brottfluttur = já)
                 and (heimilismağur[5].tengsl <> maki or heimilismağur[5].brottfluttur = já)
                 and (heimilismağur[6].tengsl <> maki or heimilismağur[6].brottfluttur = já)
                 and (heimilismağur[7].tengsl <> maki or heimilismağur[7].brottfluttur = já)
                 and (heimilismağur[8].tengsl <> maki or heimilismağur[8].brottfluttur = já)
                 and (heimilismağur[9].tengsl <> maki or heimilismağur[9].brottfluttur = já)
                 and (heimilismağur[10].tengsl <> maki or heimilismağur[10].brottfluttur = já)
                 and (heimilismağur[11].tengsl <> maki or heimilismağur[11].brottfluttur = já)
                 and (heimilismağur[12].tengsl <> maki or heimilismağur[12].brottfluttur = já)
                 and (heimilismağur[13].tengsl <> maki or heimilismağur[13].brottfluttur = já)
                 and (heimilismağur[15].tengsl <> maki or heimilismağur[15].brottfluttur = já)
                 "Heimilismağur 1 getur ağeins átt einn maka" ENDIF

         IF heimilismağur[15].tengsl = maki
            then (heimilismağur[2].tengsl <> maki or heimilismağur[2].brottfluttur = já)
                 and (heimilismağur[3].tengsl <> maki or heimilismağur[3].brottfluttur = já)
                 and (heimilismağur[4].tengsl <> maki or heimilismağur[4].brottfluttur = já)
                 and (heimilismağur[5].tengsl <> maki or heimilismağur[5].brottfluttur = já)
                 and (heimilismağur[6].tengsl <> maki or heimilismağur[6].brottfluttur = já)
                 and (heimilismağur[7].tengsl <> maki or heimilismağur[7].brottfluttur = já)
                 and (heimilismağur[8].tengsl <> maki or heimilismağur[8].brottfluttur = já)
                 and (heimilismağur[9].tengsl <> maki or heimilismağur[9].brottfluttur = já)
                 and (heimilismağur[10].tengsl <> maki or heimilismağur[10].brottfluttur = já)
                 and (heimilismağur[11].tengsl <> maki or heimilismağur[11].brottfluttur = já)
                 and (heimilismağur[12].tengsl <> maki or heimilismağur[12].brottfluttur = já)
                 and (heimilismağur[13].tengsl <> maki or heimilismağur[13].brottfluttur = já)
                 and (heimilismağur[14].tengsl <> maki or heimilismağur[14].brottfluttur = já)
                 "Heimilismağur 1 getur ağeins átt einn maka" ENDIF




         IF heimilismağur[2].hjúsvar = sambud and heimilismağur[2].tengsl <> maki
            THEN heimilismağur[3].hjúsvar = sambud
            or heimilismağur[4].hjúsvar = sambud
            or heimilismağur[5].hjúsvar = sambud
            or heimilismağur[6].hjúsvar = sambud
            or heimilismağur[7].hjúsvar = sambud
            or heimilismağur[8].hjúsvar = sambud
            or heimilismağur[9].hjúsvar = sambud
            or heimilismağur[10].hjúsvar = sambud
            or heimilismağur[11].hjúsvar = sambud
            or heimilismağur[12].hjúsvar = sambud
            or heimilismağur[13].hjúsvar = sambud
            or heimilismağur[14].hjúsvar = sambud
            or heimilismağur[15].hjúsvar = sambud
            "Ağeins einn heimilismanna er skráğur í sambúğ!" ENDIF


         IF heimilismağur[3].hjúsvar = sambud
            and heimilismağur[3].tengsl <> maki
            THEN heimilismağur[2].hjúsvar = sambud
            or heimilismağur[4].hjúsvar = sambud
            or heimilismağur[5].hjúsvar = sambud
            or heimilismağur[6].hjúsvar = sambud
            or heimilismağur[7].hjúsvar = sambud
            or heimilismağur[8].hjúsvar = sambud
            or heimilismağur[9].hjúsvar = sambud
            or heimilismağur[10].hjúsvar = sambud
            or heimilismağur[11].hjúsvar = sambud
            or heimilismağur[12].hjúsvar = sambud
            or heimilismağur[13].hjúsvar = sambud
            or heimilismağur[14].hjúsvar = sambud
            or heimilismağur[15].hjúsvar = sambud
            "Ağeins einn heimilismanna er skráğur í sambúğ!" ENDIF

         IF heimilismağur[4].hjúsvar = sambud
            and heimilismağur[4].tengsl <> maki
            THEN heimilismağur[2].hjúsvar = sambud
            or heimilismağur[3].hjúsvar = sambud
            or heimilismağur[5].hjúsvar = sambud
            or heimilismağur[6].hjúsvar = sambud
            or heimilismağur[7].hjúsvar = sambud
            or heimilismağur[8].hjúsvar = sambud
            or heimilismağur[9].hjúsvar = sambud
            or heimilismağur[10].hjúsvar = sambud
            or heimilismağur[11].hjúsvar = sambud
            or heimilismağur[12].hjúsvar = sambud
            or heimilismağur[13].hjúsvar = sambud
            or heimilismağur[14].hjúsvar = sambud
            or heimilismağur[15].hjúsvar = sambud
            "Ağeins einn heimilismanna er skráğur í sambúğ!" ENDIF

         IF heimilismağur[5].hjúsvar = sambud
            and heimilismağur[5].tengsl <> maki
            THEN heimilismağur[2].hjúsvar = sambud
            or heimilismağur[3].hjúsvar = sambud
            or heimilismağur[4].hjúsvar = sambud
            or heimilismağur[6].hjúsvar = sambud
            or heimilismağur[7].hjúsvar = sambud
            or heimilismağur[8].hjúsvar = sambud
            or heimilismağur[9].hjúsvar = sambud
            or heimilismağur[10].hjúsvar = sambud
            or heimilismağur[11].hjúsvar = sambud
            or heimilismağur[12].hjúsvar = sambud
            or heimilismağur[13].hjúsvar = sambud
            or heimilismağur[14].hjúsvar = sambud
            or heimilismağur[15].hjúsvar = sambud
            "Ağeins einn heimilismanna er skráğur í sambúğ!" ENDIF

         IF heimilismağur[6].hjúsvar = sambud
            and heimilismağur[6].tengsl <> maki
            THEN heimilismağur[2].hjúsvar = sambud
            or heimilismağur[3].hjúsvar = sambud
            or heimilismağur[4].hjúsvar = sambud
            or heimilismağur[5].hjúsvar = sambud
            or heimilismağur[7].hjúsvar = sambud
            or heimilismağur[8].hjúsvar = sambud
            or heimilismağur[9].hjúsvar = sambud
            or heimilismağur[10].hjúsvar = sambud
            or heimilismağur[11].hjúsvar = sambud
            or heimilismağur[12].hjúsvar = sambud
            or heimilismağur[13].hjúsvar = sambud
            or heimilismağur[14].hjúsvar = sambud
            or heimilismağur[15].hjúsvar = sambud
            "Ağeins einn heimilismanna er skráğur í sambúğ!" ENDIF

         IF heimilismağur[7].hjúsvar = sambud
            and heimilismağur[7].tengsl <> maki
            THEN heimilismağur[2].hjúsvar = sambud
            or heimilismağur[3].hjúsvar = sambud
            or heimilismağur[4].hjúsvar = sambud
            or heimilismağur[5].hjúsvar = sambud
            or heimilismağur[6].hjúsvar = sambud
            or heimilismağur[8].hjúsvar = sambud
            or heimilismağur[9].hjúsvar = sambud
            or heimilismağur[10].hjúsvar = sambud
            or heimilismağur[11].hjúsvar = sambud
            or heimilismağur[12].hjúsvar = sambud
            or heimilismağur[13].hjúsvar = sambud
            or heimilismağur[14].hjúsvar = sambud
            or heimilismağur[15].hjúsvar = sambud
            "Ağeins einn heimilismanna er skráğur í sambúğ!" ENDIF

         IF heimilismağur[8].hjúsvar = sambud
            and heimilismağur[8].tengsl <> maki
            THEN heimilismağur[2].hjúsvar = sambud
            or heimilismağur[3].hjúsvar = sambud
            or heimilismağur[4].hjúsvar = sambud
            or heimilismağur[5].hjúsvar = sambud
            or heimilismağur[6].hjúsvar = sambud
            or heimilismağur[7].hjúsvar = sambud
            or heimilismağur[9].hjúsvar = sambud
            or heimilismağur[10].hjúsvar = sambud
            or heimilismağur[11].hjúsvar = sambud
            or heimilismağur[12].hjúsvar = sambud
            or heimilismağur[13].hjúsvar = sambud
            or heimilismağur[14].hjúsvar = sambud
            or heimilismağur[15].hjúsvar = sambud
            "Ağeins einn heimilismanna er skráğur í sambúğ!" ENDIF

         IF heimilismağur[9].hjúsvar = sambud
            and heimilismağur[9].tengsl <> maki
            THEN heimilismağur[2].hjúsvar = sambud
            or heimilismağur[3].hjúsvar = sambud
            or heimilismağur[4].hjúsvar = sambud
            or heimilismağur[5].hjúsvar = sambud
            or heimilismağur[6].hjúsvar = sambud
            or heimilismağur[7].hjúsvar = sambud
            or heimilismağur[8].hjúsvar = sambud
            or heimilismağur[10].hjúsvar = sambud
            or heimilismağur[11].hjúsvar = sambud
            or heimilismağur[12].hjúsvar = sambud
            or heimilismağur[13].hjúsvar = sambud
            or heimilismağur[14].hjúsvar = sambud
            or heimilismağur[15].hjúsvar = sambud
            "Ağeins einn heimilismanna er skráğur í sambúğ!" ENDIF

         IF heimilismağur[10].hjúsvar = sambud
            and heimilismağur[10].tengsl <> maki
            THEN heimilismağur[2].hjúsvar = sambud
            or heimilismağur[3].hjúsvar = sambud
            or heimilismağur[4].hjúsvar = sambud
            or heimilismağur[5].hjúsvar = sambud
            or heimilismağur[6].hjúsvar = sambud
            or heimilismağur[7].hjúsvar = sambud
            or heimilismağur[8].hjúsvar = sambud
            or heimilismağur[9].hjúsvar = sambud
            or heimilismağur[11].hjúsvar = sambud
            or heimilismağur[12].hjúsvar = sambud
            or heimilismağur[13].hjúsvar = sambud
            or heimilismağur[14].hjúsvar = sambud
            or heimilismağur[15].hjúsvar = sambud
            "Ağeins einn heimilismanna er skráğur í sambúğ!" ENDIF

         IF heimilismağur[11].hjúsvar = sambud
            and heimilismağur[11].tengsl <> maki
            THEN heimilismağur[2].hjúsvar = sambud
            or heimilismağur[3].hjúsvar = sambud
            or heimilismağur[4].hjúsvar = sambud
            or heimilismağur[5].hjúsvar = sambud
            or heimilismağur[6].hjúsvar = sambud
            or heimilismağur[7].hjúsvar = sambud
            or heimilismağur[8].hjúsvar = sambud
            or heimilismağur[9].hjúsvar = sambud
            or heimilismağur[10].hjúsvar = sambud
            or heimilismağur[12].hjúsvar = sambud
            or heimilismağur[13].hjúsvar = sambud
            or heimilismağur[14].hjúsvar = sambud
            or heimilismağur[15].hjúsvar = sambud
            "Ağeins einn heimilismanna er skráğur í sambúğ!" ENDIF

         IF heimilismağur[12].hjúsvar = sambud
            and heimilismağur[12].tengsl <> maki
            THEN heimilismağur[2].hjúsvar = sambud
            or heimilismağur[3].hjúsvar = sambud
            or heimilismağur[4].hjúsvar = sambud
            or heimilismağur[5].hjúsvar = sambud
            or heimilismağur[6].hjúsvar = sambud
            or heimilismağur[7].hjúsvar = sambud
            or heimilismağur[8].hjúsvar = sambud
            or heimilismağur[9].hjúsvar = sambud
            or heimilismağur[10].hjúsvar = sambud
            or heimilismağur[11].hjúsvar = sambud
            or heimilismağur[13].hjúsvar = sambud
            or heimilismağur[14].hjúsvar = sambud
            or heimilismağur[15].hjúsvar = sambud
            "Ağeins einn heimilismanna er skráğur í sambúğ!" ENDIF

         IF heimilismağur[12].hjúsvar = sambud
            and heimilismağur[12].tengsl <> maki
            THEN heimilismağur[2].hjúsvar = sambud
            or heimilismağur[3].hjúsvar = sambud
            or heimilismağur[4].hjúsvar = sambud
            or heimilismağur[5].hjúsvar = sambud
            or heimilismağur[6].hjúsvar = sambud
            or heimilismağur[7].hjúsvar = sambud
            or heimilismağur[8].hjúsvar = sambud
            or heimilismağur[9].hjúsvar = sambud
            or heimilismağur[10].hjúsvar = sambud
            or heimilismağur[11].hjúsvar = sambud
            or heimilismağur[13].hjúsvar = sambud
            or heimilismağur[14].hjúsvar = sambud
            or heimilismağur[15].hjúsvar = sambud
            "Ağeins einn heimilismanna er skráğur í sambúğ!" ENDIF

         IF heimilismağur[13].hjúsvar = sambud
            and heimilismağur[13].tengsl <> maki
            THEN heimilismağur[2].hjúsvar = sambud
            or heimilismağur[3].hjúsvar = sambud
            or heimilismağur[4].hjúsvar = sambud
            or heimilismağur[5].hjúsvar = sambud
            or heimilismağur[6].hjúsvar = sambud
            or heimilismağur[7].hjúsvar = sambud
            or heimilismağur[8].hjúsvar = sambud
            or heimilismağur[9].hjúsvar = sambud
            or heimilismağur[10].hjúsvar = sambud
            or heimilismağur[11].hjúsvar = sambud
            or heimilismağur[12].hjúsvar = sambud
            or heimilismağur[14].hjúsvar = sambud
            or heimilismağur[15].hjúsvar = sambud
            "Ağeins einn heimilismanna er skráğur í sambúğ!" ENDIF

         IF heimilismağur[14].hjúsvar = sambud
            and heimilismağur[14].tengsl <> maki
            THEN heimilismağur[2].hjúsvar = sambud
            or heimilismağur[3].hjúsvar = sambud
            or heimilismağur[4].hjúsvar = sambud
            or heimilismağur[5].hjúsvar = sambud
            or heimilismağur[6].hjúsvar = sambud
            or heimilismağur[7].hjúsvar = sambud
            or heimilismağur[8].hjúsvar = sambud
            or heimilismağur[9].hjúsvar = sambud
            or heimilismağur[10].hjúsvar = sambud
            or heimilismağur[11].hjúsvar = sambud
            or heimilismağur[12].hjúsvar = sambud
            or heimilismağur[13].hjúsvar = sambud
            or heimilismağur[15].hjúsvar = sambud
            "Ağeins einn heimilismanna er skráğur í sambúğ!" ENDIF

         IF heimilismağur[15].hjúsvar = sambud
            and heimilismağur[15].tengsl <> maki
            THEN heimilismağur[2].hjúsvar = sambud
            or heimilismağur[3].hjúsvar = sambud
            or heimilismağur[4].hjúsvar = sambud
            or heimilismağur[5].hjúsvar = sambud
            or heimilismağur[6].hjúsvar = sambud
            or heimilismağur[7].hjúsvar = sambud
            or heimilismağur[8].hjúsvar = sambud
            or heimilismağur[9].hjúsvar = sambud
            or heimilismağur[10].hjúsvar = sambud
            or heimilismağur[11].hjúsvar = sambud
            or heimilismağur[12].hjúsvar = sambud
            or heimilismağur[13].hjúsvar = sambud
            or heimilismağur[14].hjúsvar = sambud
            "Ağeins einn heimilismanna er skráğur í sambúğ!" ENDIF

         {if heimilismağur2[2].pk_maka.ord > 1  then
           IF heimilismağur2[2].pk_maka = heim03
              then heimilismağur2[3].pk_maka := heim02
              endif
           IF heimilismağur2[2].pk_maka = heim04
              then heimilismağur2[4].pk_maka := heim02
              endif
           IF heimilismağur2[2].pk_maka = heim05
              then heimilismağur2[5].pk_maka := heim02
              endif
           IF heimilismağur2[2].pk_maka = heim06
              then heimilismağur2[6].pk_maka := heim02
              endif
           IF heimilismağur2[2].pk_maka = heim07
              then heimilismağur2[7].pk_maka := heim02
              endif
           IF heimilismağur2[2].pk_maka = heim08
              then heimilismağur2[8].pk_maka := heim02
              endif
           IF heimilismağur2[2].pk_maka = heim09
              then heimilismağur2[9].pk_maka := heim02
              endif
           IF heimilismağur2[2].pk_maka = heim10
              then heimilismağur2[10].pk_maka := heim02
              endif
           IF heimilismağur2[2].pk_maka = heim11
              then heimilismağur2[11].pk_maka := heim02
              endif
           IF heimilismağur2[2].pk_maka = heim12
              then heimilismağur2[12].pk_maka := heim02
              endif
           IF heimilismağur2[2].pk_maka = heim13
              then heimilismağur2[13].pk_maka := heim02
              endif
           IF heimilismağur2[2].pk_maka = heim14
              then heimilismağur2[14].pk_maka := heim02
              endif
           IF heimilismağur2[2].pk_maka = heim15
              then heimilismağur2[15].pk_maka := heim02
              endif
         endif

         IF heimilismağur2[3].pk_maka = heim04
            then heimilismağur2[4].pk_maka := heim03
            endif
         IF heimilismağur2[3].pk_maka = heim05
            then heimilismağur2[5].pk_maka := heim03
            endif
         IF heimilismağur2[3].pk_maka = heim06
            then heimilismağur2[6].pk_maka := heim03
            endif
         IF heimilismağur2[3].pk_maka = heim07
            then heimilismağur2[7].pk_maka := heim03
            endif
         IF heimilismağur2[3].pk_maka = heim08
            then heimilismağur2[8].pk_maka := heim03
            endif
         IF heimilismağur2[3].pk_maka = heim09
            then heimilismağur2[9].pk_maka := heim03
            endif
         IF heimilismağur2[3].pk_maka = heim10
            then heimilismağur2[10].pk_maka := heim03
            endif
         IF heimilismağur2[3].pk_maka = heim11
            then heimilismağur2[11].pk_maka := heim03
            endif
         IF heimilismağur2[3].pk_maka = heim12
            then heimilismağur2[12].pk_maka := heim03
            endif
         IF heimilismağur2[3].pk_maka = heim13
            then heimilismağur2[13].pk_maka := heim03
            endif
         IF heimilismağur2[3].pk_maka = heim14
            then heimilismağur2[14].pk_maka := heim03
            endif
         IF heimilismağur2[3].pk_maka = heim15
            then heimilismağur2[15].pk_maka := heim03
            endif

         IF heimilismağur2[4].pk_maka = heim05
            then heimilismağur2[5].pk_maka := heim04
            endif
         IF heimilismağur2[4].pk_maka = heim06
            then heimilismağur2[6].pk_maka := heim04
            endif
         IF heimilismağur2[4].pk_maka = heim07
            then heimilismağur2[7].pk_maka := heim04
            endif
         IF heimilismağur2[4].pk_maka = heim08
            then heimilismağur2[8].pk_maka := heim04
            endif
         IF heimilismağur2[4].pk_maka = heim09
            then heimilismağur2[9].pk_maka := heim04
            endif
         IF heimilismağur2[4].pk_maka = heim10
            then heimilismağur2[10].pk_maka := heim04
            endif
         IF heimilismağur2[4].pk_maka = heim11
            then heimilismağur2[11].pk_maka := heim04
            endif
         IF heimilismağur2[4].pk_maka = heim12
            then heimilismağur2[12].pk_maka := heim04
            endif
         IF heimilismağur2[4].pk_maka = heim13
            then heimilismağur2[13].pk_maka := heim04
            endif
         IF heimilismağur2[4].pk_maka = heim14
            then heimilismağur2[14].pk_maka := heim04
            endif
         IF heimilismağur2[4].pk_maka = heim15
            then heimilismağur2[15].pk_maka := heim04
            endif


         IF heimilismağur2[5].pk_maka = heim06
            then heimilismağur2[6].pk_maka := heim05
            endif
         IF heimilismağur2[5].pk_maka = heim07
            then heimilismağur2[7].pk_maka := heim05
            endif
         IF heimilismağur2[5].pk_maka = heim08
            then heimilismağur2[8].pk_maka := heim05
            endif
         IF heimilismağur2[5].pk_maka = heim09
            then heimilismağur2[9].pk_maka := heim05
            endif
         IF heimilismağur2[5].pk_maka = heim10
            then heimilismağur2[10].pk_maka := heim05
            endif
         IF heimilismağur2[5].pk_maka = heim11
            then heimilismağur2[11].pk_maka := heim05
            endif
         IF heimilismağur2[5].pk_maka = heim12
            then heimilismağur2[12].pk_maka := heim05
            endif
         IF heimilismağur2[5].pk_maka = heim13
            then heimilismağur2[13].pk_maka := heim05
            endif
         IF heimilismağur2[5].pk_maka = heim14
            then heimilismağur2[14].pk_maka := heim05
            endif
         IF heimilismağur2[5].pk_maka = heim15
            then heimilismağur2[15].pk_maka := heim05
            endif

         IF heimilismağur2[6].pk_maka = heim07
            then heimilismağur2[7].pk_maka := heim06
            endif
         IF heimilismağur2[6].pk_maka = heim08
            then heimilismağur2[8].pk_maka := heim06
            endif
         IF heimilismağur2[6].pk_maka = heim09
            then heimilismağur2[9].pk_maka := heim06
            endif
         IF heimilismağur2[6].pk_maka = heim10
            then heimilismağur2[10].pk_maka := heim06
            endif
         IF heimilismağur2[6].pk_maka = heim11
            then heimilismağur2[11].pk_maka := heim06
            endif
         IF heimilismağur2[6].pk_maka = heim12
            then heimilismağur2[12].pk_maka := heim06
            endif
         IF heimilismağur2[6].pk_maka = heim13
            then heimilismağur2[13].pk_maka := heim06
            endif
         IF heimilismağur2[6].pk_maka = heim14
            then heimilismağur2[14].pk_maka := heim06
            endif
         IF heimilismağur2[6].pk_maka = heim15
            then heimilismağur2[15].pk_maka := heim06
            endif

         IF heimilismağur2[7].pk_maka = heim08
            then heimilismağur2[8].pk_maka := heim07
            endif
         IF heimilismağur2[7].pk_maka = heim09
            then heimilismağur2[9].pk_maka := heim07
            endif
         IF heimilismağur2[7].pk_maka = heim10
            then heimilismağur2[10].pk_maka := heim07
            endif
         IF heimilismağur2[7].pk_maka = heim11
            then heimilismağur2[11].pk_maka := heim07
            endif
         IF heimilismağur2[7].pk_maka = heim12
            then heimilismağur2[12].pk_maka := heim07
            endif
         IF heimilismağur2[7].pk_maka = heim13
            then heimilismağur2[13].pk_maka := heim07
            endif
         IF heimilismağur2[7].pk_maka = heim14
            then heimilismağur2[14].pk_maka := heim07
            endif
         IF heimilismağur2[7].pk_maka = heim15
            then heimilismağur2[15].pk_maka := heim07
            endif



         IF heimilismağur2[8].pk_maka = heim09
            then heimilismağur2[9].pk_maka := heim08
            endif
         IF heimilismağur2[8].pk_maka = heim10
            then heimilismağur2[10].pk_maka := heim08
            endif
         IF heimilismağur2[8].pk_maka = heim11
            then heimilismağur2[11].pk_maka := heim08
            endif
         IF heimilismağur2[8].pk_maka = heim12
            then heimilismağur2[12].pk_maka := heim08
            endif
         IF heimilismağur2[8].pk_maka = heim13
            then heimilismağur2[13].pk_maka := heim08
            endif
         IF heimilismağur2[8].pk_maka = heim14
            then heimilismağur2[14].pk_maka := heim08
            endif
         IF heimilismağur2[8].pk_maka = heim15
            then heimilismağur2[15].pk_maka := heim08
            endif

         IF heimilismağur2[9].pk_maka = heim10
            then heimilismağur2[10].pk_maka := heim09
            endif
         IF heimilismağur2[9].pk_maka = heim11
            then heimilismağur2[11].pk_maka := heim09
            endif
         IF heimilismağur2[9].pk_maka = heim12
            then heimilismağur2[12].pk_maka := heim09
            endif
         IF heimilismağur2[9].pk_maka = heim13
            then heimilismağur2[13].pk_maka := heim09
            endif
         IF heimilismağur2[9].pk_maka = heim14
            then heimilismağur2[14].pk_maka := heim09
            endif
         IF heimilismağur2[9].pk_maka = heim15
            then heimilismağur2[15].pk_maka := heim09
            endif

         IF heimilismağur2[10].pk_maka = heim11
            then heimilismağur2[11].pk_maka := heim10
            endif
         IF heimilismağur2[10].pk_maka = heim12
            then heimilismağur2[12].pk_maka := heim10
            endif
         IF heimilismağur2[10].pk_maka = heim13
            then heimilismağur2[13].pk_maka := heim10
            endif
         IF heimilismağur2[10].pk_maka = heim14
            then heimilismağur2[14].pk_maka := heim10
            endif
         IF heimilismağur2[10].pk_maka = heim15
            then heimilismağur2[15].pk_maka := heim10
            endif

         IF heimilismağur2[11].pk_maka = heim12
            then heimilismağur2[12].pk_maka := heim11
            endif
         IF heimilismağur2[11].pk_maka = heim13
            then heimilismağur2[13].pk_maka := heim11
            endif
         IF heimilismağur2[11].pk_maka = heim14
            then heimilismağur2[14].pk_maka := heim11
            endif
         IF heimilismağur2[11].pk_maka = heim15
            then heimilismağur2[15].pk_maka := heim11
            endif

         IF heimilismağur2[12].pk_maka = heim13
            then heimilismağur2[13].pk_maka := heim12
            endif
         IF heimilismağur2[12].pk_maka = heim14
            then heimilismağur2[14].pk_maka := heim12
            endif
         IF heimilismağur2[12].pk_maka = heim15
            then heimilismağur2[15].pk_maka := heim12
            endif


         IF heimilismağur2[13].pk_maka = heim14
            then heimilismağur2[14].pk_maka := heim13
            endif
         IF heimilismağur2[13].pk_maka = heim15
            then heimilismağur2[15].pk_maka := heim13
            endif


         IF heimilismağur2[14].pk_maka = heim15
            then heimilismağur2[15].pk_maka := heim14
            endif }



         IF heimilismağur[NúmerHeimilismanns].hjúsvar = sambud and heimilismağur[NúmerHeimilismanns].tengsl <> maki then
           if ErMaki[NúmerHeimilismanns] = empty then
             pk_maka {Spurning færğ á undan spurningum um móğur og föğur af AÖK 240108}
             for i := 1 to 15 do
               if ErMaki[i] = NúmerHeimilismanns then
                 ErMaki[i] := empty
               endif
             enddo
             if pk_maka <> empty then ErMaki [pk_maka.ord] := NúmerHeimilismanns endif
           else
             pk_maka := ErMaki[NúmerHeimilismanns]
             pk_maka.show
           endif
         endif

         IF (heimilismağur[NúmerHeimilismanns].tengsl <> maki
            and heimilismağur[NúmerHeimilismanns].tengsl <> barn
            and heimilismağur[NúmerHeimilismanns].tengsl <> systkini
            and heimilismağur[NúmerHeimilismanns].tengsl <> foreldri
            and heimilismağur[NúmerHeimilismanns].brottfluttur = nei)
            Then if heimilismağur[2].aldur - heimilismağur[NúmerHeimilismanns].aldur > 14 and heimilismağur[2].brottfluttur = nei and heimilismağur[2].kyn = karl
                    OR heimilismağur[3].aldur - heimilismağur[NúmerHeimilismanns].aldur > 14 and heimilismağur[3].brottfluttur = nei and heimilismağur[3].kyn = karl
                    OR heimilismağur[4].aldur - heimilismağur[NúmerHeimilismanns].aldur > 14 and heimilismağur[4].brottfluttur = nei and heimilismağur[4].kyn = karl
                    OR heimilismağur[5].aldur - heimilismağur[NúmerHeimilismanns].aldur > 14 and heimilismağur[5].brottfluttur = nei and heimilismağur[5].kyn = karl
                    OR heimilismağur[6].aldur - heimilismağur[NúmerHeimilismanns].aldur > 14 and heimilismağur[6].brottfluttur = nei and heimilismağur[6].kyn = karl
                    OR heimilismağur[7].aldur - heimilismağur[NúmerHeimilismanns].aldur > 14 and heimilismağur[7].brottfluttur = nei and heimilismağur[7].kyn = karl
                    OR heimilismağur[8].aldur - heimilismağur[NúmerHeimilismanns].aldur > 14 and heimilismağur[8].brottfluttur = nei and heimilismağur[8].kyn = karl
                    OR heimilismağur[9].aldur - heimilismağur[NúmerHeimilismanns].aldur > 14 and heimilismağur[9].brottfluttur = nei and heimilismağur[9].kyn = karl
                    OR heimilismağur[10].aldur - heimilismağur[NúmerHeimilismanns].aldur > 14 and heimilismağur[10].brottfluttur = nei and heimilismağur[10].kyn = karl
                    OR heimilismağur[11].aldur - heimilismağur[NúmerHeimilismanns].aldur > 14 and heimilismağur[11].brottfluttur = nei and heimilismağur[11].kyn = karl
                    OR heimilismağur[12].aldur - heimilismağur[NúmerHeimilismanns].aldur > 14 and heimilismağur[12].brottfluttur = nei and heimilismağur[12].kyn = karl
                    OR heimilismağur[13].aldur - heimilismağur[NúmerHeimilismanns].aldur > 14 and heimilismağur[13].brottfluttur = nei and heimilismağur[13].kyn = karl
                    OR heimilismağur[14].aldur - heimilismağur[NúmerHeimilismanns].aldur > 14 and heimilismağur[14].brottfluttur = nei and heimilismağur[14].kyn = karl
                    OR heimilismağur[15].aldur - heimilismağur[NúmerHeimilismanns].aldur > 14 and heimilismağur[15].brottfluttur = nei and heimilismağur[15].kyn = karl
            then pk_fadir
            endif
         endif


         IF (heimilismağur[NúmerHeimilismanns].tengsl <> maki
            and heimilismağur[NúmerHeimilismanns].tengsl <> barn
            and heimilismağur[NúmerHeimilismanns].tengsl <> systkini
            and heimilismağur[NúmerHeimilismanns].tengsl <> foreldri
            and heimilismağur[NúmerHeimilismanns].brottfluttur = nei)
            Then if heimilismağur[2].aldur - heimilismağur[NúmerHeimilismanns].aldur > 14 and heimilismağur[2].brottfluttur = nei and heimilismağur[2].kyn = kona
                    OR heimilismağur[3].aldur - heimilismağur[NúmerHeimilismanns].aldur > 14 and heimilismağur[3].brottfluttur = nei and heimilismağur[3].kyn = kona
                    OR heimilismağur[4].aldur - heimilismağur[NúmerHeimilismanns].aldur > 14 and heimilismağur[4].brottfluttur = nei and heimilismağur[4].kyn = kona
                    OR heimilismağur[5].aldur - heimilismağur[NúmerHeimilismanns].aldur > 14 and heimilismağur[5].brottfluttur = nei and heimilismağur[5].kyn = kona
                    OR heimilismağur[6].aldur - heimilismağur[NúmerHeimilismanns].aldur > 14 and heimilismağur[6].brottfluttur = nei and heimilismağur[6].kyn = kona
                    OR heimilismağur[7].aldur - heimilismağur[NúmerHeimilismanns].aldur > 14 and heimilismağur[7].brottfluttur = nei and heimilismağur[7].kyn = kona
                    OR heimilismağur[8].aldur - heimilismağur[NúmerHeimilismanns].aldur > 14 and heimilismağur[8].brottfluttur = nei and heimilismağur[8].kyn = kona
                    OR heimilismağur[9].aldur - heimilismağur[NúmerHeimilismanns].aldur > 14 and heimilismağur[9].brottfluttur = nei and heimilismağur[9].kyn = kona
                    OR heimilismağur[10].aldur - heimilismağur[NúmerHeimilismanns].aldur > 14 and heimilismağur[10].brottfluttur = nei and heimilismağur[10].kyn = kona
                    OR heimilismağur[11].aldur - heimilismağur[NúmerHeimilismanns].aldur > 14 and heimilismağur[11].brottfluttur = nei and heimilismağur[11].kyn = kona
                    OR heimilismağur[12].aldur - heimilismağur[NúmerHeimilismanns].aldur > 14 and heimilismağur[12].brottfluttur = nei and heimilismağur[12].kyn = kona
                    OR heimilismağur[13].aldur - heimilismağur[NúmerHeimilismanns].aldur > 14 and heimilismağur[13].brottfluttur = nei and heimilismağur[13].kyn = kona
                    OR heimilismağur[14].aldur - heimilismağur[NúmerHeimilismanns].aldur > 14 and heimilismağur[14].brottfluttur = nei and heimilismağur[14].kyn = kona
                    OR heimilismağur[15].aldur - heimilismağur[NúmerHeimilismanns].aldur > 14 and heimilismağur[15].brottfluttur = nei and heimilismağur[15].kyn = kona
            then pk_modir
            endif
         endif

         {if aldur <= 24 or FæğÁr = dk then }{pk_fadir} {endif}   {Leiğarstjórnun breytt, 080107 af AÖK}
         {if aldur <= 24 or FæğÁr = dk then }{pk_modir} {endif}   {Leiğarstjórnun breytt, 080107 af AÖK}

         {if aldur >= 16 or FæğÁr = dk then
           if Tengsl = maki then
             pk_maka := heim01
             pk_maka.show
           else
             if Hjúsvar = sambud then
               pk_maka
             endif
           endif
         endif }


         if Tengsl = Óskyldur then nanar_oskyldur endif

         Alias := Nafn + ', ' + TnTexti+ ', ' + str(aldur) + ' ára'

         if óskráğur_seinni_hluti = já then
           HmNırÁr
           check
           if HmNırÁr = response then HmNırÁr <= year(VidtalByrjarDags) "innflutningsár getur ekki veriğ hærra en áriğ í ár" endif
           IF HMNırÁr = 2014 or HMNırÁr = 2015 then
           HmNırMánuğur
           if HmNırMánuğur = dk then HmNırMánuğurGisk endif endif
{AÖK 180208}
           {HmNırMánuğur
           if HmNırMánuğur = dk then HmNırMánuğurGisk endif
           HmNırÁr
           check
           if HmNırÁr = response then HmNırÁr <= year(VidtalByrjarDags) "innflutningsár getur ekki veriğ hærra en áriğ í ár" endif}
         endif
       endif
     ENDIF

     fsvar := ''
LAYOUT
AT BLOCKSTART
INFOPANE Tofluskjar


ENDBLOCK
