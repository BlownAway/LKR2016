{   BlokkA.inc SILC}

EMBEDDED BLOCK BlokkA "Vinna í síðustu viku"
    PARAMETERS
        IMPORT AllarSpurningar : TJáNei
        IMPORT viðmiðunardagur : DateType
        IMPORT persóna  : Tpersóna
        EXPORT TvöStörf, Vinnandi : Tjánei 
        {EXPORT Fjarverandi : TJáNei}
        EXPORT aaðal_b: Tstaða
        EXPORT AFjarvst_b: TJáNeiAFjarvst
        {EXPORT vaktavinna:TjáNei } {Byggir á breytunni fkóti sem er hvergi gefið gildi}
    AUXFIELDS
        
        þína :(karl2p "þína",kona2p "þína",karl3p "hans",kona3p "hennar",óvíst3p "hans/hennar")
        stu  :(karl2p "stu",kona2p "stu",karl3p " hann",kona3p " hún",óvíst3p " hann/hún")
        tu   :(karl2p "tu",kona2p "tu",karl3p " hann",kona3p " hún",óvíst3p " hann/hún")
        ðu   :(karl2p "ðu",kona2p "ðu",karl3p " hann",kona3p " hún",óvíst3p " hann/hún")
        þig  :(karl2p "þig",kona2p "þig",karl3p "sig",kona3p "sig",óvíst3p "sig")
        þú   : (karl2p "þú",kona2p "þú",karl3p "hann",kona3p "hún",óvíst3p "hann/hún")
        ert_þú :(karl2p "Ert þú",kona2p "Ert þú",karl3p "Er hann",kona3p "Er hún",óvíst3p "Er hann/hún") 
        ere_you : (karl2p "ere you",kona2p "ere you",karl3p "as he",kona3p "as she",óvíst3p "as he/she")
        you :  (karl2p "you",kona2p "you",karl3p "he",kona3p "she",óvíst3p "he/she")
        Do_you : (karl2p "Do you",kona2p "Do you",karl3p "Does he",kona3p "Does she",óvíst3p "Does he/she")
        Are_you:  (karl2p "Are you",kona2p "Are you",karl3p "Is he",kona3p "Is she",óvíst3p "Is he/she")
        ave_you: (karl2p "ave you",kona2p "ave you",karl3p "as he",kona3p "as she",óvíst3p "as he/she")
        yourself : (karl2p "yourself",kona2p "yourself",karl3p "himself",kona3p "herself",óvíst3p)
        ggamall :  (karl2p "gamall",kona2p "gömul",karl3p "gamall",kona3p "gömul",óvíst3p "gamall")
        þér  :    (karl2p "þér",kona2p "þér",karl3p "sér",kona3p "sér",óvíst3p "sér")
        ir: (karl2p "ir",kona2p "ir",karl3p "i",kona3p "i",óvíst3p "i")
        n : (karl2p "n",kona2p " ",karl3p "n",kona3p " ", óvíst3p "/n")
        ur: (karl2p "ur",kona2p " ",karl3p "ur",kona3p " ",óvíst3p "(ur)")

        {Temporary addition}
        Fjarverandi : TJáNei
        
        
    FIELDS
         
      AVinna (A01)
        "^haus@/^fsvar@/^strik@/
        Fyrst er spurt um stöðu ^þína í dag. Var^stu að vinna fyrir launum @usíðustu sjö daga@u í eina klukkukstund eða lengur?
        @/@/@GMeð launum er átt við hverskonar atvinnutekjur@G"
        "^haus@/^fsvar@/^strik@/
        W^ere_you in paid employment during the last seven days for one hour or more?
        @/@G^referenceweek@G"
        /"Ertu vinnandi"
        : TJáNei

      AFjarvst (A02)
        "^haus@/^fsvar@/^strik@/
        Var^stu tímabundið fjarverandi frá vinnu í vikunni vegna veikinda, frídaga, fæðingarorlofs eða annarra hluta...eða er^tu ekki í vinnu?
        @/@/@GHér er átt við þá sem eru á vinnumarkaði en voru ekki í vinnunni síðustu sjö daga.
        Ekki er átt við þá sem eru utan hans, til dæmis öryrkja eða ellilífeyrisþega.@G"
        "^haus@/^fsvar@/^strik@/
        W^ere_you absent from work during the last seven days because of illness, holidays, maternity leave or other reasons?
        @/@/@GHér er átt við þá sem eru á vinnumarkaði en voru ekki í vinnunni síðustu sjö daga.
        Ekki er átt við þá sem eru utan hans, til dæmis öryrkja eða ellilífeyrisþega.@G"
        /"Fjarvera"
        :TJáNeiAFjarvst

      AAðal (A03)
        "^haus@/^fsvar@/^strik@/
        Lítur^ðu aðallega á ^þig sem..."
        "^haus@/^fsvar@/^strik@/
        ^Do_you regard ^yourself mainly as..."
        /"Staða"
        : TStaða


      AStarf2 (A08)
        "^haus@/^fsvar@/^strik@/
        Var^stu í fleiri en einu starfi síðustu sjö daga eða ráðin^n í fleiri en eitt starf?"
         "^haus@/^fsvar@/^strik@/
        W^ere_you in more than one job last seven days?
        @/@/@G^referenceweek@G"
        /"Fleiri störf"
        : TJáNei

      Areynsla
        "^haus@/^fsvar@/^strik@/
         Í næstu spurningum ætla ég að spyrja um fasta vinnu.
         @/Með fastri vinnu er átt við starf sem ^þú hefur haft í að minnsta kosti 6 mánuði samfellt og unnið að minnsta kosti 15 klukkustundir á viku.
         @/·
         @/^Ert_þú, eða hefur ^þú einhvern tíma, verið ráðin^n í fasta vinnu?"
         "^haus@/^fsvar@/^strik@/
         In the next questions I will ask about a regular job.
         @/A regular job is a job that you have held for at least six consecutive months and working at least fifteen hours a week
         @/·
         @/^Are_you or h^ave_you ever been in a regular job?"
        /"Hve gamall"
        : TJáNei

      Agamall
        "^haus@/^fsvar@/^strik@/
         @/Hvað var^stu ^ggamall þegar ^þú byrjað^ir fyrst í fastri vinnu?"
         "^haus@/^fsvar@/^strik@/
         @/How old w^ere_you when ^you first started working a regular job?"
        /"Hve gamall"
        : 10..100

      Afjoldar
        "^haus@/^fsvar@/^strik@/
         Hefur ^þú verið samfellt í fastri vinnu síðan ^þú byrjað^ir í fastri vinnu eða hefur ^þú einhvern tíma tekið ^þér hlé
         eða verið án vinnu í ár eða lengri tíma?"
         "^haus@/^fsvar@/^strik@/
         H^ave_you consistently been in a regular job since ^you first started working regularly or h^ave_you taken a leave
         or been without work for a year or longer?"
        /"Föst vinna samfellt eða hlé"
        :  (samfellt    "Hefur verið í fastri vinnu samfellt" "Have been consistently in regular job",
            hlé         "Hefur tekið hlé í ár eða lengri tíma" "Have taken a leave for a year or longer"
            )

      AFjoldar_hle
        "^haus@/^fsvar@/^strik@/
         Hversu mörg ár var^stu í hléi eða án vinnu í heildina?
         @/@/@gNámundið upp eða niður í næsta heila ár"
         "^haus@/^fsvar@/^strik@/
         For how many years in total w^ere_you on leave or without work?
         @/@/@gNámundið upp eða niður í næsta heila ár"
        /"Fjöldi ára í hléum" : 1..60




    AUXFIELDS
     fKóti : STRING
     SíðustuViku, LastWeek : string[50]
     Viðmiðunarvika, ReferenceWeek : string[50]

    RULES
        þína     :=persóna.ord
        stu      :=persóna.ord
        tu       :=persóna.ord
        ðu       :=persóna.ord
        þig      :=persóna.ord
        þú       :=persóna.ord
        ere_you  :=persóna.ord
        Do_you   :=persóna.ord
        ave_you  :=persóna.ord
        Are_you  :=persóna.ord
        ert_þú   :=persóna.ord
        yourself :=persóna.ord
        ggamall  :=persóna.ord
        þér      :=persóna.ord
        n        :=persóna.ord
        ur       :=persóna.ord
        ir       :=persóna.ord
        you      :=persóna.ord
        prc_viðmiðunartímiUpplýst (viðmiðunardagur - (0,0,6), viðmiðunardagur, viðmiðunarvika, referenceweek)
        prc_viðmiðunartímiSpurt (viðmiðunardagur - (0,0,6), viðmiðunardagur, SíðustuViku, LastWeek)

     AVinna
     IF AVinna <> Já THEN
       AFjarvst
     ENDIF
     AAðal
     IF AVinna = Já OR AFjarvst = Já THEN
       AStarf2
     ENDIF
     
     IF AVinna = Já OR AFjarvst = Já OR aaðal IN [ifullustarfi,ihalfustarfi] THEN
        Vinnandi := Já
        IF AFjarvst = Já THEN
            Fjarverandi := Já
        ELSE
            Fjarverandi := Nei
        ENDIF
        TvöStörf := AStarf2
     ELSE
        Vinnandi := Nei
        Fjarverandi := Já
        TvöStörf := Nei
     ENDIF
     
     {Fjarlægt því breytunni fKóti er hvergi gefið gildi ÞMM des 2015}
     {IF (fKóti='9.4' {vinnurVaktir}) THEN
       vaktavinna := Já
     ELSE
       vaktavinna := Nei
     ENDIF}
     
     IF (Allarspurningar = já) AND (vinnandi = já) THEN 
       Areynsla
       IF Areynsla = já THEN
          AGamall
          Afjoldar
          IF AFjoldar = hlé THEN
             AFjoldar_hle
          ENDIF
       ENDIF {Areynsla = já}
     ENDIF
     
     IF Afjarvst = RESPONSE  THEN 
        Afjarvst_b := Afjarvst
     ENDIF
     
     IF aaðal = RESPONSE THEN 
        aaðal_b := aaðal
     ENDIF
     
 ENDBLOCK
