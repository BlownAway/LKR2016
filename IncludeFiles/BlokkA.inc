{   BlokkA.inc SILC}

EMBEDDED BLOCK BlokkA "Vinna � s��ustu viku"
    PARAMETERS
        IMPORT AllarSpurningar : TJ�Nei
        IMPORT vi�mi�unardagur : DateType
        IMPORT pers�na  : Tpers�na
        EXPORT Tv�St�rf, Vinnandi : Tj�nei 
        {EXPORT Fjarverandi : TJ�Nei}
        EXPORT aa�al_b: Tsta�a
        EXPORT AFjarvst_b: TJ�NeiAFjarvst
        {EXPORT vaktavinna:Tj�Nei } {Byggir � breytunni fk�ti sem er hvergi gefi� gildi}
    AUXFIELDS
        
        ��na :(karl2p "��na",kona2p "��na",karl3p "hans",kona3p "hennar",�v�st3p "hans/hennar")
        stu  :(karl2p "stu",kona2p "stu",karl3p " hann",kona3p " h�n",�v�st3p " hann/h�n")
        tu   :(karl2p "tu",kona2p "tu",karl3p " hann",kona3p " h�n",�v�st3p " hann/h�n")
        �u   :(karl2p "�u",kona2p "�u",karl3p " hann",kona3p " h�n",�v�st3p " hann/h�n")
        �ig  :(karl2p "�ig",kona2p "�ig",karl3p "sig",kona3p "sig",�v�st3p "sig")
        ��   : (karl2p "��",kona2p "��",karl3p "hann",kona3p "h�n",�v�st3p "hann/h�n")
        ert_�� :(karl2p "Ert ��",kona2p "Ert ��",karl3p "Er hann",kona3p "Er h�n",�v�st3p "Er hann/h�n") 
        ere_you : (karl2p "ere you",kona2p "ere you",karl3p "as he",kona3p "as she",�v�st3p "as he/she")
        you :  (karl2p "you",kona2p "you",karl3p "he",kona3p "she",�v�st3p "he/she")
        Do_you : (karl2p "Do you",kona2p "Do you",karl3p "Does he",kona3p "Does she",�v�st3p "Does he/she")
        Are_you:  (karl2p "Are you",kona2p "Are you",karl3p "Is he",kona3p "Is she",�v�st3p "Is he/she")
        ave_you: (karl2p "ave you",kona2p "ave you",karl3p "as he",kona3p "as she",�v�st3p "as he/she")
        yourself : (karl2p "yourself",kona2p "yourself",karl3p "himself",kona3p "herself",�v�st3p)
        ggamall :  (karl2p "gamall",kona2p "g�mul",karl3p "gamall",kona3p "g�mul",�v�st3p "gamall")
        ��r  :    (karl2p "��r",kona2p "��r",karl3p "s�r",kona3p "s�r",�v�st3p "s�r")
        ir: (karl2p "ir",kona2p "ir",karl3p "i",kona3p "i",�v�st3p "i")
        n : (karl2p "n",kona2p " ",karl3p "n",kona3p " ", �v�st3p "/n")
        ur: (karl2p "ur",kona2p " ",karl3p "ur",kona3p " ",�v�st3p "(ur)")

        {Temporary addition}
        Fjarverandi : TJ�Nei
        
        
    FIELDS
         
      AVinna (A01)
        "^haus@/^fsvar@/^strik@/
        Fyrst er spurt um st��u ^��na � dag. Var^stu a� vinna fyrir launum @us��ustu sj� daga@u � eina klukkukstund e�a lengur?
        @/@/@GMe� launum er �tt vi� hverskonar atvinnutekjur@G"
        "^haus@/^fsvar@/^strik@/
        W^ere_you in paid employment during the last seven days for one hour or more?
        @/@G^referenceweek@G"
        /"Ertu vinnandi"
        : TJ�Nei

      AFjarvst (A02)
        "^haus@/^fsvar@/^strik@/
        Var^stu t�mabundi� fjarverandi fr� vinnu � vikunni vegna veikinda, fr�daga, f��ingarorlofs e�a annarra hluta...e�a er^tu ekki � vinnu?
        @/@/@GH�r er �tt vi� �� sem eru � vinnumarka�i en voru ekki � vinnunni s��ustu sj� daga.
        Ekki er �tt vi� �� sem eru utan hans, til d�mis �ryrkja e�a ellil�feyris�ega.@G"
        "^haus@/^fsvar@/^strik@/
        W^ere_you absent from work during the last seven days because of illness, holidays, maternity leave or other reasons?
        @/@/@GH�r er �tt vi� �� sem eru � vinnumarka�i en voru ekki � vinnunni s��ustu sj� daga.
        Ekki er �tt vi� �� sem eru utan hans, til d�mis �ryrkja e�a ellil�feyris�ega.@G"
        /"Fjarvera"
        :TJ�NeiAFjarvst

      AA�al (A03)
        "^haus@/^fsvar@/^strik@/
        L�tur^�u a�allega � ^�ig sem..."
        "^haus@/^fsvar@/^strik@/
        ^Do_you regard ^yourself mainly as..."
        /"Sta�a"
        : TSta�a


      AStarf2 (A08)
        "^haus@/^fsvar@/^strik@/
        Var^stu � fleiri en einu starfi s��ustu sj� daga e�a r��in^n � fleiri en eitt starf?"
         "^haus@/^fsvar@/^strik@/
        W^ere_you in more than one job last seven days?
        @/@/@G^referenceweek@G"
        /"Fleiri st�rf"
        : TJ�Nei

      Areynsla
        "^haus@/^fsvar@/^strik@/
         � n�stu spurningum �tla �g a� spyrja um fasta vinnu.
         @/Me� fastri vinnu er �tt vi� starf sem ^�� hefur haft � a� minnsta kosti 6 m�nu�i samfellt og unni� a� minnsta kosti 15 klukkustundir � viku.
         @/�
         @/^Ert_��, e�a hefur ^�� einhvern t�ma, veri� r��in^n � fasta vinnu?"
         "^haus@/^fsvar@/^strik@/
         In the next questions I will ask about a regular job.
         @/A regular job is a job that you have held for at least six consecutive months and working at least fifteen hours a week
         @/�
         @/^Are_you or h^ave_you ever been in a regular job?"
        /"Hve gamall"
        : TJ�Nei

      Agamall
        "^haus@/^fsvar@/^strik@/
         @/Hva� var^stu ^ggamall �egar ^�� byrja�^ir fyrst � fastri vinnu?"
         "^haus@/^fsvar@/^strik@/
         @/How old w^ere_you when ^you first started working a regular job?"
        /"Hve gamall"
        : 10..100

      Afjoldar
        "^haus@/^fsvar@/^strik@/
         Hefur ^�� veri� samfellt � fastri vinnu s��an ^�� byrja�^ir � fastri vinnu e�a hefur ^�� einhvern t�ma teki� ^��r hl�
         e�a veri� �n vinnu � �r e�a lengri t�ma?"
         "^haus@/^fsvar@/^strik@/
         H^ave_you consistently been in a regular job since ^you first started working regularly or h^ave_you taken a leave
         or been without work for a year or longer?"
        /"F�st vinna samfellt e�a hl�"
        :  (samfellt    "Hefur veri� � fastri vinnu samfellt" "Have been consistently in regular job",
            hl�         "Hefur teki� hl� � �r e�a lengri t�ma" "Have taken a leave for a year or longer"
            )

      AFjoldar_hle
        "^haus@/^fsvar@/^strik@/
         Hversu m�rg �r var^stu � hl�i e�a �n vinnu � heildina?
         @/@/@gN�mundi� upp e�a ni�ur � n�sta heila �r"
         "^haus@/^fsvar@/^strik@/
         For how many years in total w^ere_you on leave or without work?
         @/@/@gN�mundi� upp e�a ni�ur � n�sta heila �r"
        /"Fj�ldi �ra � hl�um" : 1..60




    AUXFIELDS
     fK�ti : STRING
     S��ustuViku, LastWeek : string[50]
     Vi�mi�unarvika, ReferenceWeek : string[50]

    RULES
        ��na     :=pers�na.ord
        stu      :=pers�na.ord
        tu       :=pers�na.ord
        �u       :=pers�na.ord
        �ig      :=pers�na.ord
        ��       :=pers�na.ord
        ere_you  :=pers�na.ord
        Do_you   :=pers�na.ord
        ave_you  :=pers�na.ord
        Are_you  :=pers�na.ord
        ert_��   :=pers�na.ord
        yourself :=pers�na.ord
        ggamall  :=pers�na.ord
        ��r      :=pers�na.ord
        n        :=pers�na.ord
        ur       :=pers�na.ord
        ir       :=pers�na.ord
        you      :=pers�na.ord
        prc_vi�mi�unart�miUppl�st (vi�mi�unardagur - (0,0,6), vi�mi�unardagur, vi�mi�unarvika, referenceweek)
        prc_vi�mi�unart�miSpurt (vi�mi�unardagur - (0,0,6), vi�mi�unardagur, S��ustuViku, LastWeek)

     AVinna
     IF AVinna <> J� THEN
       AFjarvst
     ENDIF
     AA�al
     IF AVinna = J� OR AFjarvst = J� THEN
       AStarf2
     ENDIF
     
     IF AVinna = J� OR AFjarvst = J� OR aa�al IN [ifullustarfi,ihalfustarfi] THEN
        Vinnandi := J�
        IF AFjarvst = J� THEN
            Fjarverandi := J�
        ELSE
            Fjarverandi := Nei
        ENDIF
        Tv�St�rf := AStarf2
     ELSE
        Vinnandi := Nei
        Fjarverandi := J�
        Tv�St�rf := Nei
     ENDIF
     
     {Fjarl�gt �v� breytunni fK�ti er hvergi gefi� gildi �MM des 2015}
     {IF (fK�ti='9.4' {vinnurVaktir}) THEN
       vaktavinna := J�
     ELSE
       vaktavinna := Nei
     ENDIF}
     
     IF (Allarspurningar = j�) AND (vinnandi = j�) THEN 
       Areynsla
       IF Areynsla = j� THEN
          AGamall
          Afjoldar
          IF AFjoldar = hl� THEN
             AFjoldar_hle
          ENDIF
       ENDIF {Areynsla = j�}
     ENDIF
     
     IF Afjarvst = RESPONSE  THEN 
        Afjarvst_b := Afjarvst
     ENDIF
     
     IF aa�al = RESPONSE THEN 
        aa�al_b := aa�al
     ENDIF
     
 ENDBLOCK
