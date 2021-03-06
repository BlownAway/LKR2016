{   BlokkB.inc SILC}

EMBEDDED BLOCK BlokkB "Starfsl�sing"
    PARAMETERS
        IMPORT AllarSpurningar, Vinnandi : TJ�Nei
        IMPORT tv�St�rf : TJ�Nei
        {IMPORT skylduli� : TJ�Nei}
        {EXPORT Status : TStatus
        EXPORT Fyrirt�ki : String}

    EXTERNALS
      finna�starf : ISTARF
      zveit       : SVEIT
      Finna�sat : isat2008
    AUXFIELDS
    Status : TStatus
    Fyrirt�ki : String
    spurtUmFirma, spurtUmStarf : TJ�Nei
    {(karl2p,kona2p,karl3p,kona3p,�v�st3p)}
    �itt : (karl2p "�itt",kona2p "�itt",karl3p "hans",kona3p "hennar",�v�st3p "hans/hennar")
    your : (karl2p "your",kona2p "your",karl3p "his",kona3p "her",�v�st3p "his/her")
    tu   :(karl2p "tu",kona2p "tu",karl3p " hann",kona3p " h�n",�v�st3p " hann/h�n")
    stu  :(karl2p "stu",kona2p "stu",karl3p " hann",kona3p " h�n",�v�st3p " hann/h�n")
    Are_you:  (karl2p "Are you",kona2p "Are you",karl3p "Is he",kona3p "Is she",�v�st3p "Is he/she")
    you :  (karl2p "you",kona2p "you",karl3p "he",kona3p "she",�v�st3p "he/she")
    you_:  (karl2p "you",kona2p "you",karl3p "him",kona3p "her",�v�st3p "him/her")
    ��   : (karl2p "��",kona2p "��",karl3p "hann",kona3p "h�n",�v�st3p "hann/h�n")
    do_you : (karl2p "do you",kona2p "do you",karl3p "does he",kona3p "does she",�v�st3p "does he/she")
    ��num  : (karl2p "��num",kona2p"��num",karl3p"hans",kona3p "hennar",�v�st3p"hans/hennar")
    ��n  : (karl2p "��n",kona2p"��n",karl3p"hans",kona3p "hennar",�v�st3p"hans/hennar")
    FIELDS
      BStatus (B01)
        "^haus@/^fsvar@/^strik@/
        ^EfTv�St�rf
        Er^tu laun�egi e�a sj�lfst�tt starfandi ?
        @/@/@GSj�lfst�tt starfandi eru �eir sem reka fyrirt�ki � eigin kennit�lu e�a � einkahlutaf�lagi sem �eir e�a fj�lskyldur
        �eirra eiga. S�mulei�is �eir sem eiga � sameignarf�l�gum me� ��rum, eins og l�gfr��ingar � l�gfr��istofu.
        �etta � �� ekki vi� nema f�lk s� � lykilst��um � fyrirt�kinu, h�r er ekki �tt vi� ungt f�lk sem vinnur hj� foreldrum s�num vi� afgrei�slu
        e�a annars konar hj�lp."
        "^haus@/^fsvar@/^strik@/
        ^IfTwoJobs
        ^Are_you a wage earner or self-employed?
        @/@/@GSj�lfst�tt starfandi eru �eir sem reka fyrirt�ki � eigin kennit�lu e�a � einkahlutaf�lagi sem �eir e�a fj�lskyldan
        �eirra eiga a� mestu e�a �llu leyti. S�mulei�is �eir sem eiga � sameignarf�l�gum me� ��rum, eins og l�gfr��ingar � l�gfr��istofu.
        �etta � �� ekki vi� nema f�lk s� � lykilst��um � fyrirt�kinu, h�r er ekki �tt vi� ungt f�lk sem vinnur hj� foreldrum s�num vi� afgrei�slu
        e�a annars konar hj�lp. Forstj�rar � hlutaf�l�gum (athugi� ekki einkahlutaf�lag) teljast laun�egar, �� svo �eir eigi allt e�a meirihluta hlutafj�r. "
        /"Laun�egi/sj�lfst�tt"
        : TStatus
      BSjStrf (B02)
        "^haus@/^fsvar@/^strik@/
        Var^stu me� starfsmenn � launum � s��ustu viku?"
         "^haus@/^fsvar@/^strik@/
        Did ^you have paid employees working for ^you_ ^last_week?"
        /"Launa�ir starfsmenn"
        : TJ�Nei
      BFjLaun (B03)
        "^haus@/^fsvar@/^strik@/
        Hversu marga starfsmenn er^tu me� � launum?"
        "^haus@/^fsvar@/^strik@/
        How many employees did ^you have working for ^you_?"
        /"Fj�ldi starfsmanna"
        :1..1000

     BfjLaun_gisk
        "^haus@/^fsvar@/^strik@/
        � hva�a bili er starfsmannafj�ldinn?"
        "^haus@/^fsvar@/^strik@/
        Was it ..?"
        /"Fj�ldi starfsmanna"
        : (
        til_10 "1-10 starfsmenn" "1-10 employees",
        til_19 "11-19 starfsmenn" "11-19 employees",
        til_29 "20-29 Starfsmenn" "20-29 employees",
        til_49 "30-49 starfsmenn" "30-49 employees",
        til_99 "50-99 Starfsmenn" "50-99 employees",
        til_199 "100-199 starfsmenn" "100-199 employees",
        til_499 "200-499 starfsmenn" "200-499 employees",
        fleiri  "500 starfsmenn e�a fleiri" "500 employees or more"
       )

      BHv�st (B04)
        "^haus@/^fsvar@/^strik@/
        Hver er sta�a ^��n?
        @/@/@G�egar hinga� er komi� hefur l�klega eitthva� komi� upp � fyrr � spurningalistanum, �annig a� �� myndir sennilega
        vilja @Ubakka h��an@U. L�kleg sk�ring er til d�mis a� svarandi er � raun atvinnulaus, en merkt hefur veri� vi� hann sem
        vinnandi ��ur. Haf�u einnig � huga a� sj�lfbo�avinna telst ekki til launa�rar vinnu � spurningalistanum. @G"
        "^haus@/^fsvar@/^strik@/
        If neither, please give details?
        @/@/@G�egar hinga� er komi� hefur l�klega eitthva� komi� upp � fyrr � spurningalistanum, �annig a� �� myndir sennilega
        vilja @Ubakka h��an@U. L�kleg sk�ring er til d�mis a� svarandi er � raun atvinnulaus, en merkt hefur veri� vi� hann sem
        vinnandi ��ur. Haf�u einnig � huga a� sj�lfbo�avinna telst ekki til launa�rar vinnu � spurningalistanum. @G"
        /"Hvorugt n�nar"
        :String [50]
      BFirma (B06)
        "^haus@/^fsvar@/^strik@/
        Hj� hva�a fyrirt�ki vinnur ^��?
        @/@/@GEinungis er spurt um nafn fyrirt�kis til a� au�velda atvinnugreinaflokkunina og er nafni� ekki nota� til annarra hluta."
        "^haus@/^fsvar@/^strik@/
        Which company ^do_you work for?
        @/@/@GEinungis er spurt um nafn fyrirt�kis til a� au�velda atvinnugreinaflokkunina og er nafni� ekki nota� til annarra hluta."
        /"Hva�a fyrirt�ki"
        :String [50]
      BEiga (B06a)
       "^haus@/^fsvar@/^strik@/
        Er fyrirt�ki� � eigu einhvers � heimilinu?
        @/@/@GEf spyrill veit a� fyrirt�ki� er r�kisstofnun, hlutaf�lag, sj�lfseignarstofnun e�a viss um a� enginn � heimilinu
        eig �a� m� sleppa a� spyrja �essarar spurningar og svara nei"
        "^haus@/^fsvar@/^strik@/
        Is the company owned by someone at the home?"
        /"Eigandi fyrirt�kisins"
        :TJ�Nei
      BI�ja (B07)
        "^haus@/^fsvar@/^strik@/
        Hver er starfsemi fyrirt�kisins a�allega?
        @/@/@GEf fyrirt�ki� er � m�rgum st��um mi�i� �� vi� vinnusta� svaranda.
        @/Vinnusta�ur er �ll starfsemin � l��inni, ekki bara deild vi�komandi@G"
        "^haus@/^fsvar@/^strik@/
        What is the company's main activity?
        @/@/@GIf ther is more than one workplace, refer to the respondent�s workplace
        @/Workplace means all activity on the site, not just the department@G"
        /"A�alstarfsemi"
        :String [80]
      BAK�ti2008 (B07b)
        "^haus@/^fsvar@/^strik@/
        @GFlettu upp vi�eigandi k�ta me� �v� a� �ta � BILST�NGINA@G"
        /"Atvinnugreinak�ti"
        : TIsat2008 {, nodontknow }
      BFjStm1 (B08)
         "^haus@/^fsvar@/^strik@/
         Hversu margir starfa � vinnusta� ^��num?
         @/@/@GVinnusta�ur er allt fyrirt�ki� ef �a� er � einum sta� annars skal mi�a vi� rekstrareininguna.
         Landsbanka starfsma�ur � Raufarh�fn telur hins vegar fj�lda starfsmanna � s�nu �tib�i@G.
         @/@/@GMuna ctrl + V ef vi�komandi veit ekki fj�ldann og �� kemur spurning um � hva�a bili starfsmannafj�ldinn er@G"
         "^haus@/^fsvar@/^strik@/
         How many people work at ^your workplace?
         @/@/@GVinnusta�ur er allt fyrirt�ki� ef �a� er � einum sta� annars skal mi�a vi� rekstrareininguna.
         D�mi: Hagstofan var starfr�kt � tveimur h�sum en � sama sv��i og teljast �v� starfsmenn � b��um h�sum til
         fj�lda starfsmanna � vinnusta�. Landsbanka starfsma�ur � Raufarh�fn telur hins vegar fj�lda starfsmanna � s�nu �tib�i@G.
         @/@/@GMuna ctrl + V ef vi�komandi veit ekki fj�ldann og �� kemur spurning um � hva�a bili starfsmannafj�ldinn er@G"
         /"Fj�ldi � vinnusta�"
         : 1..9999
      BFjStm2 (B08b)
         "^haus@/^fsvar@/^strik@/
         � hva�a bili er starfsmannafj�ldinn. Er hann..."
         "Choose the appropriate range for number of employees?"
         /"Fj�ldi starfsmanna (bil)"
         : (M1      "��1 - �10 starfsmenn"     "��1 - �10 employees",
            M2      "�11 - �19 starfsmenn"     "�11 - �19 employees",
            M20      "�20 - �49 starfsmenn"     "�20 - �49 employees",
            M50      "�50 e�a fleiri"           "�50 or more")
      BStarf (B09)
        "^haus@/^fsvar@/^strik@/
        Hvert er starfsheiti ^�itt?
        @/@/@GVi� starfaflokkun skiptir miklu m�li a� f� fram n�kv�mt starfsheiti.
        D�mi: um�nnun aldra�ra en ekki bara um�nnun, kynningarfulltr�i en ekki bara fulltr�i, h�seti � l�nub�t en ekki bara sj�ma�ur.@G"
        "^haus@/^fsvar@/^strik@/
         What is ^your job title?
        @/@/@GPrecise job title, for example: caring for the elderly (not just healthcare), PR representative ( not jus representative),
        first mate on longliner (not just seaman)@G"
         /"Starfsheiti"
        :String [80]
      BSK�ti
        "^haus@/^fsvar@/^strik@/
        @GFlettu upp vi�eigandi k�ta me� �v� a� �ta � BILST�NGINA@G"
        /"Starfak�ti"
        : TIstarf
      BStLys (B10)
        "^haus@/^fsvar@/^strik@/
        Hver eru helstu verkefnin?
        @/@/@GHelstu verkefni � starfi eru grundv�llur starfaflokkunarinnar. Rafeindavirki getur sinnt mj�g
        �l�kum st�rfum og starfsheiti� eitt og s�r dugar ekki til vi� starfaflokkunina.  Helstu verkefni
        rafeindavirkja getur til d�mis veri� sala og r��gj�f � t�lvub�na�i til fyrirt�kja og segir �v�
        starfsheiti� eitt og s�r takmarka�a s�gu."
        "^haus@/^fsvar@/^strik@/
        What are the main tasks in this job?
        @/@/@GHelstu verkefni � starfi eru grundv�llur starfaflokkunarinnar. Rafeindavirki getur sinnt mj�g
        �l�kum st�rfum og starfsheiti� eitt og s�r dugar ekki til vi� starfaflokkunina.  Helstu verkefni
        rafeindavirkja getur til d�mis veri� sala og r��gj�f � t�lvub�na�i til fyrirt�kja og segir �v�
        starfsheiti� eitt og s�r takmarka�a s�gu."
        /"Verkefni"
        :String [80]
     BVrkStj (B11)
        "^haus@/^fsvar@/^strik@/
        Skipuleggur ^�� e�a stj�rnar verkum annarra starfsmanna, venjulega, stundum e�a aldrei?
        @/@/@GH�r er �tt vi� �� sem bera formlega �byrg� � verkum annarra starfsmanna og skipuleggja verk �eirra.
        Stj�rnun �arf �� ekki a� vera eina verksvi� vi�komandi, d�mi skipstj�ri � l�nub�t sinnir almennum st�rfum
        � b�tnum samhli�a stj�rnun � mannskap og t�kjum. Starfsheiti geta �� veri� misv�sandi.  D�mi: augl�singastj�ri
        sem ekki st�rir ��rum starfsm�nnum innan fyrirt�kisins ber ekki sl�ka �byrg�."
         "^haus@/^fsvar@/^strik@/
        ^Do_you organize or manage other peoples work, usually, sometimes or never?
        @/@/@GH�r er �tt vi� �� sem bera formlega �byrg� � verkum annarra starfsmanna og skipuleggja verk �eirra.
        Stj�rnun �arf �� ekki a� vera eina verksvi� vi�komandi, d�mi skipstj�ri � l�nub�t sinnir almennum st�rfum
        � b�tnum samhli�a stj�rnun � mannskap og t�kjum. Starfsheiti geta �� veri� misv�sandi.  D�mi: augl�singastj�ri
        sem ekki st�rir ��rum starfsm�nnum innan fyrirt�kisins ber ekki sl�ka �byrg�.        "
        /"Stj�rnun"
        : TVenja
        
    CT�mbnd (C05)
        "^haus@/^fsvar@/^strik@/
        Er^tu r��in^n t�mabundi�?
        @/@/@GT�mabundin r��ning � til d�mis vi� um �� sem eru verkefnar��nir. Ef r��ningasamningur
        er ekki me� neinu �kv��i um a� hann taki enda er hann ekki t�mabundinn.
        Sumarst�rf n�msmanna eru oftast t�mabundin."
        "^haus@/^fsvar@/^strik@/
        ^Are_you employed on a temporary basis?
        @/@/@GT�mabundin r��ning � til d�mis vi� um �� sem eru verkefnar��nir. Ef r��ningasamningur
        er ekki me� neinu �kv��i um a� hann taki enda er hann ekki t�mabundinn.
        Sumarst�rf n�msmanna eru oftast t�mabundin."
        /"T�mabundin r��ning"
        : TJ�Nei

    AUXFIELDS
      EfTv�St�rf, IfTwoJobs : STRING
      s��ustu_viku, last_week : string
      Vi�mi�unarvika, Referenceweek : STRING
      zK�ti               : string
      sK�ti               : STRING
      iK�ti               : STRING
     text_BAKodi : string[8]


    RULES
      {kyngreiningarbreytur}
      Are_you  :=pers�na.ord
      tu       :=pers�na.ord
      your     :=pers�na.ord
      �itt     :=pers�na.ord
      stu      :=pers�na.ord
      you      :=pers�na.ord
      you_     :=pers�na.ord
      ��       :=pers�na.ord
      do_you   :=pers�na.ord
      ��num    :=pers�na.ord
      ��n      :=pers�na.ord
      n        :=pers�na.ord
      ur       :=pers�na.ord
        
      prc_vi�mi�unart�miuppl�st (vi�mi�unardagur - (0,0,6), vi�mi�unardagur, vi�mi�unarvika, Referenceweek)
      prc_vi�mi�unart�miSpurt (vi�mi�unardagur - (0,0,6), vi�mi�unardagur, s��ustu_viku, last_week)
      
      IF Tv�St�rf = J� THEN
        EfTv�St�rf := 'N� �tla �g a� spyrja n�nar um �a� sem �� telur vera a�alstarf ^�itt @/@/'
        IfTwoJobs  := 'I will now ask you about what you consider to be ^your main job @/@/'
      ELSE
        EfTv�St�rf := ''
        IfTwoJobs  := ''
      ENDIF
      
      IF (Vinnandi = J�) THEN
         spurtumfirma := j�
         spurtumstarf := j�
      ENDIF

      {IF Skylduli� <> J� THEN} {Fjarl�gt �v� breytunni skylduli� er hvergi gefi� gildi �MM des 2015}
        BStatus
        IF bStatus = Sj�lfst�tt THEN BSjStrf ENDIF
        IF BSjStrf = J� THEN
          {IF FyrraHmnr = 1 then} BFjLaun
            if BFjLaun = dk then BFjLaun_gisk
            endif
          {ENDIF}
        ENDIF
        IF bStatus = Hvorugt THEN BHv�st ENDIF
      {ENDIF Skylduli� <> J�}

      IF spurtUmFirma = J� THEN
        BFirma
        BI�ja
        IF 1=1 then {virkja �SAT-k��un}
            IF BI�ja <> Refusal THEN
                BAK�ti2008|Finna�sat.LOOKUP(Tri:=(BI�ja)).ISAT2008
                iK�ti := ClassToStr(BAK�ti2008)
            if len(text_BAKodi) < 8 then
                text_BAKodi := '0' + text_BAKodi
            endif
            ENDIF
        ENDIF {taka �t �SAT-k��un}
        IF 0=1 THEN
          BEiga
        ENDIF
        IF bStatus <> Sj�lfst�tt THEN BFjStm1 ENDIF
        IF BFjStm1 = DK THEN BFjStm2 ENDIF
      ENDIF {spurtUmFirma = J� }


      IF spurtUmStarf = J� THEN
        BStarf
        IF BStarf <> Refusal THEN
          BSK�ti.KEEP |Finna�starf.LOOKUP(Tri:=(BStarf)).Starfak�ti
          sk�ti := ClassToStr(BSK�ti)
        ENDIF
        BStLys
        IF bStatus = Laun�egi And bFjStm1 <> 1 THEN BVrkStj ENDIF
      ENDIF {spurtUmStarf = J� }
      Status := bStatus
      IF BFirma = DontKnow THEN
        Fyrirt�ki := 'Veit ekki heiti�'
      ELSEIF BFirma = Refusal THEN
        Fyrirt�ki := 'Neitar a� gefa upp heiti�'
      ELSE
        Fyrirt�ki := BFirma
      ENDIF

      IF Vinnandi = J� THEN
        CT�mbnd
      ENDIF  
ENDBLOCK
