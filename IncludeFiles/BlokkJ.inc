{   BlokkJ.inc SILC }
EMBEDDED BLOCK BlokkJ "S��asta starf"

   PARAMETERS
     IMPORT pers�na : TPers�na

   EXTERNALS
     finna�starf : ISTARF ('ISTARF')

    FIELDS
      JStatus (J01)
        "^haus@/^fsvar@/^strik@/
        Var^stu laun�egi e�a sj�lfst�tt starfandi � s��asta starfi?"
         "^haus@/^fsvar@/^strik@/
        ^Were_you a wage earner or self-employed in ^your last job?"
        /"Laun� sj�lfst"
        : TStatus

      Jt�mbnd
        "^haus@/^fsvar@/^strik@/
        Var^stu � fastri vinnu e�a r��in^n t�mabundi� � s��asta starfi?
        @/@/@GSpurt er um s��asta starf sem vi�komandi starfa�i vi�."
         "^haus@/^fsvar@/^strik@/
        Did ^you have a regular job or was ^your last job temporary?
        @/@/@GSpurt er um s��asta starf sem vi�komandi starfa�i vi�."
        /"T�mabundin vinna"
        : (
         fastri     "� fastri vinnu" "Regular job",
         t�mabundi� "R��in^n t�mabundi�" "Temporary"
          )

      JSjstrf (J02)
        "^haus@/^fsvar@/^strik@/
        Var^stu me� starfsmenn � launum?"
        "^haus@/^fsvar@/^strik@/
        Did ^you have paid employees working for you?"
        /"Launa�a starfsm"
        : TJ�Nei
      JHv�st (J03)
       "^haus@/^fsvar@/^strik@/
        Hver var sta�a ��n?
        @/@/@G�egar hinga� er komi� hefur l�klega eitthva� komi� upp � fyrr � spurningalistanum, �annig a� �� myndir sennilega
        vilja @Ubakka h��an@U. L�kleg sk�ring er til d�mis a� svarandi er � raun atvinnulaus, en merkt hefur veri� vi� hann sem
        vinnandi ��ur. Haf�u einnig � huga a� sj�lfbo�avinna telst ekki til launa�rar vinnu � spurningalistanum. @G"
        "^haus@/^fsvar@/^strik@/
        If neither, please give details?
        @/@/@G�egar hinga� er komi� hefur l�klega eitthva� komi� upp � fyrr � spurningalistanum, �annig a� �� myndir sennilega
        vilja @Ubakka h��an@U. L�kleg sk�ring er til d�mis a� svarandi er � raun atvinnulaus, en merkt hefur veri� vi� hann sem
        vinnandi ��ur. Haf�u einnig � huga a� sj�lfbo�avinna telst ekki til launa�rar vinnu � spurningalistanum. @G"
        /"Hvorugt hva�"
        :String [80]
      JSta�ur (J04)
        "^haus@/^fsvar@/^strik@/
        � hva�a sveitarf�lagi vann^stu?"
        "^haus@/^fsvar@/^strik@/
        Which municipality did you work in?"
        /"Sveitarf�lag"
        : TSveit
      JFirma (J05)
        "^haus@/^fsvar@/^strik@/
        Hj� hva�a fyrirt�ki vann^stu?"
        "^haus@/^fsvar@/^strik@/
        Which company did ^you work for?"
        /"Hva�a fyrirt�ki"
        :String [50]
      JI�ja (J06)
        "^haus@/^fsvar@/^strik@/
        Hver er starfsemi fyrirt�kisins a�allega
        @/@/@GEf fleiri en einn vinnusta�ur, mi�a vi� vinnusta� svaranda?
        @/Vinnusta�ur er �ll starfsemin � l��inni, ekki bara deild vi�komandi@G"
         "^haus@/^fsvar@/^strik@/
        What is the company's main activity
        @/@/@GIf there is more than one workplace, refer to the respondent's workplace
        @/Workplace means all activity on the site, not just the respondent's department@G"
        /"A�alstarfsemi"
        :String [80]
      JStarf (J07)
        "^haus@/^fsvar@/^strik@/
        Hvert var starfsheiti ^�itt, �a� er, n�kv�mt starfsheiti?
        @/@/@Gt.d. um�nnun aldra�ra, ekki bara um�nnun,  kynningarfulltr�i ekki bara fulltr�i,
         h�seti � l�nub�t en ekki bara sj�ma�ur@G"
         "^haus@/^fsvar@/^strik@/
        What was ^your job title, that is, precise job title?
        @/@/@Ge.g. caring for the elderly (not just healthcare), PR representative (not just representative,
         first mate on longliner (not just seaman)@G"
         /"Starfsheiti"
        :string [50]
      JSK�ti
        "^haus@/^fsvar@/^strik@/
        @GFlettu upp vi�eigandi k�ta me� �v� a� �ta � BILST�NGINA@G"
        "^haus@/^fsvar@/^strik@/
        @GCheck the relevant code by pressing the SPACEBAR@G"
        /"Starfak�ti"
        : TIstarf
      JStLys (J08)
        "^haus@/^fsvar@/^strik@/
        Hver voru helstu verkefnin?"
        "^haus@/^fsvar@/^strik@/
        What were the main tasks in that job?"
        /"Helstu verkefni"
        :string [80]

      JEiga (J09)
       "^haus@/^fsvar@/^strik@/
        Var fyrirt�ki� � eigu einhvers � heimilinu?
        @/@/@GEf spyrill veit a� fyrirt�ki� er r�kisstofnun, hlutaf�lag, sj�lfseignarstofnun e�a viss um a� enginn � heimilinu
        eig �a� m� sleppa a� spyrja �essarar spurningar og svara nei"
        "^haus@/^fsvar@/^strik@/
        Is the company owned by someone at the home?"
        /"Eigandi fyrirt�kisins"
        :TJ�Nei

      Jvrkstj
        "^haus@/^fsvar@/^strik@/
        Skipulag�i^r ^�� e�a stj�rna�i^r verkum annarra starfsmanna?"
        "^haus@/^fsvar@/^strik@/
        Did ^you have supervisory responsibilities?"
        /"Eigandi fyrirt�kisins"
        :(venjulega "Venjulega" "Yes, usually",
          stundum "stundum" "Sometimes",
          aldrei "aldrei" "No")


    AUXFIELDS
      sK�ti : STRING

      stu     :(karl2p "stu",kona2p "stu",karl3p " hann",kona3p " h�n",�v�st3p " hann/h�n")
      Were_you : (karl2p "Were you",kona2p "Were you",karl3p "Was he",kona3p "Was she",�v�st3p "Was he/she")
      you     :  (karl2p "you",kona2p "you",karl3p "he",kona3p "she",�v�st3p "he/she")
      �itt    : (karl2p "�itt",kona2p "�itt",karl3p "hans",kona3p "hennar",�v�st3p "hans/hennar")
      your    : (karl2p "your",kona2p "your",karl3p "his",kona3p "her",�v�st3p "his/her")
      ��      : (karl2p "��",kona2p "��",karl3p "hann",kona3p "h�n",�v�st3p "hann/h�n")
      r       : (karl2p "r",kona2p "r",karl3p " ",kona3p " ", �v�st3p " ")
      
    RULES
      n:=pers�na.ord
      ur:=pers�na.ord
      stu:=pers�na.ord
      Were_you:=pers�na.ord
      you:=pers�na.ord
      �itt:=pers�na.ord
      your:=pers�na.ord
      �� :=pers�na.ord
      r  :=pers�na.ord
      
    
      JStatus
      IF JStatus = sj�lfst�tt THEN JSjstrf ENDIF
      IF JStatus = Hvorugt THEN JHv�st ENDIF
      Jt�mbnd
      JStarf
      IF JStarf <> Refusal THEN
        JSK�ti.KEEP |finna�starf.LOOKUP(Tri:=(JStarf)).Starfak�ti
        sK�ti := ClassToStr(JSK�ti)
      ENDIF
      JStLys
      Jvrkstj

ENDBLOCK
