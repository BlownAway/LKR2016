{   BlokkI.inc
    Samfelld vinnumarka�sranns�kn
    �H (c) n�vember 2002
 }

EMBEDDED BLOCK BlokkI "Reynsla � vinnumarka�i"
    PARAMETERS
        {IMPORT fsv_status : Tfsv_status}
        {IMPORT AllarSpurningar : TJ�Nei}
        {IMPORT F���r : integer}
        IMPORT Pers�na : TPers�na
        {IMPORT Heimili : TJ�Nei }
        {TRANSIT Vinnandi : TJ�Nei}
        {EXPORT VinnandiS��ustuFj�rarVikur  : TJ�Nei
        EXPORT Hven�rH�ttur : DateType}
    AUXFIELDS
        VinnandiS��ustuFj�rarVikur : Tj�nei 
        Hven�rH�ttur : DateType
        
         ggamall :  (karl2p "gamall",kona2p "g�mul",karl3p "gamall",kona3p "g�mul",�v�st3p "gamall")
         ��      : (karl2p "��",kona2p "��",karl3p "hann",kona3p "h�n",�v�st3p "hann/h�n")
         stu     : (karl2p "stu",kona2p "stu",karl3p " hann",kona3p " h�n",�v�st3p " hann/h�n")
         tu      : (karl2p "tu",kona2p "tu",karl3p " hann",kona3p " h�n",�v�st3p " hann/h�n")
         n       : (karl2p "n",kona2p " ",karl3p "n",kona3p " ", �v�st3p "/n")
         r       : (karl2p "r",kona2p "r",karl3p " ",kona3p " ", �v�st3p " ")
         ur      : (karl2p "ur",kona2p " ",karl3p "ur",kona3p " ", �v�st3p "ur")
         have    : (karl2p "have",kona2p "have",karl3p "has",kona3p "has", �v�st3p "has")
         you     : (karl2p "you",kona2p "you",karl3p "he",kona3p "she",�v�st3p "he/she")
         your    : (karl2p "your",kona2p "your",karl3p "his",kona3p "her",�v�st3p "his/her")
         doyou   : (karl2p "Do you",kona2p "Do you",karl3p "Does he",kona3p "Does she",�v�st3p "Does he/she")
         
    FIELDS
      IReynsla (I01)
        "^haus@/^fsvar@/^strik@/
        Me� fastri vinnu er �tt vi� starf sem ^�� hefur haft � a� minnsta kosti 6 m�nu�i samfellt og unni� a� minnsta kosti 15 klukkustundir � viku.
        @/Hefur ^�� einhvern t�man veri� � fastri vinnu?"
        "^haus@/^fsvar@/^strik@/
        A regular job means that you have had a job for at least 6 months in a row and worked at least 15 hours a week.
        ^Have ^you ever had a regular job?"
        /"Veri� � vinnumarka�i"
        : TJ�Nei

       Igamall
      "^haus@/^fsvar@/^strik@/
        Hva� var^stu ^ggamall �egar ^�� byrja�i^r fyrst � fastri vinnu?"
        "^haus@/^fsvar@/^strik@/
        How old were you when you first started a regular job?"
        /"Hve gamall"
        : 10..100

       Ifjoldar
      "^haus@/^fsvar@/^strik@/
        Hversu m�rg �r samtals hefur ^�� veri� � fastri vinnu?
         @/@/@gN�mundi� upp e�a ni�ur � n�sta heila �r"
        "^haus@/^fsvar@/^strik@/
        How many years have you been in a regular job?
         @/@/@gN�mundi� upp e�a ni�ur � n�sta heila �r"
        /"Hve m�rg �r" : 0..100

      I�r (I02)
        "^haus@/^fsvar@/^strik@/
        Hva�a �r var^stu s��ast � vinnu?"
        "^haus@/^fsvar@/^strik@/
        Which year did ^you last work?"
        /"�r s��ast � vinnu"
        : T�rtal150
      IM�n (I03)
        "^haus@/^fsvar@/^strik@/
        � hva�a m�nu�i?"
        "^haus@/^fsvar@/^strik@/
        Which month?"
        /"M�nu�ur s��ast � vinnu"
        : Tm�nu�ir, EMPTY
      IDagur (I04)
        "^haus@/^fsvar@/^strik@/
        Hva� dag?"
        "^haus@/^fsvar@/^strik@/
        Which day?"
        /"Dagur s��ast � vinnu"
        : 1..31, EMPTY
      I�st��a (I05)
        "^haus@/^fsvar@/^strik@/
        Hver er a�al�st��a �ess a� ^�� h�tti^r � s��asta starfi?"
        "^haus@/^fsvar@/^strik@/
        What was the main reason ^you left ^your last job?"
        /"�st��a h�ttir � starfi"
        : (
        Upps�gn                         "Var sagt upp starfi / fyrirt�ki h�tt rekstri"  "Made redundant",
        T�mabundi�Starf                 "Var � t�mabundnu starfi, �.m.t. sumarstarf"    "Temporary job, including summer job",
        Verkefnaskortur                 "Vegna verkefnaskorts"                          "Lack of work to do in that job",
        Menntun                         "F�r � sk�la"                                   "Went to school",
        F��ingarorlof                   "Vegna f��ingarorlofs / me�g�ngu"               "Maternity/paternity leave or pregnancy",
        SinnaB�rnum                     "Til a� sinna b�rnum e�a fj�lskyldume�limum"    "To look after children or other dependent family member",
        Eftirlaun                       "F�r � eftirlaun"                               "Retired",
        Veikindi                        "Vegna eigin veikinda e�a f�tlunar/�rorku"      "Own illness or disability",
        Anna�                           "Anna�"                                         "Other")
      IR��in (I06)
        "^haus@/^fsvar@/^strik@/
        Er^tu enn r��in^n � �etta starf?"
        "^haus@/^fsvar@/^strik@/
        ^Doyou still hold that job?"
        /"Enn�� r��inn"
        : TJ�Nei

    AUXFIELDS
      t�mi  : DateType
      

    LOCALS
      �r    : integer[4]
      m�n   : integer[2]
      dagur : integer[2]


    RULES
      ggamall := pers�na.ord
      ��:=pers�na.ord
      stu:=pers�na.ord
      tu:=pers�na.ord
      r:=pers�na.ord
      ur:=pers�na.ord
      n:=pers�na.ord
      have:=pers�na.ord
      you:=pers�na.ord
      doyou:=pers�na.ord
      your:=pers�na.ord
      
      IReynsla
      IF IReynsla = J� THEN
         Igamall
         Ifjoldar
       ENDIF

      IF IReynsla = Nei THEN
         VinnandiS��ustuFj�rarVikur := Nei
         Hven�rH�ttur := vi�mi�unardagur - (9,0,0)
      ELSE
         IF t�mi <> EMPTY THEN
           IF t�mi + (0,0,28) <  vi�mi�unardagur THEN
             VinnandiS��ustuFj�rarVikur := Nei
           ELSE
             VinnandiS��ustuFj�rarVikur := J�
           ENDIF
           Hven�rH�ttur := T�mi
         ELSE
           VinnandiS��ustuFj�rarVikur := Nei
           Hven�rH�ttur := vi�mi�unardagur - (9,0,0)
         ENDIF
      ENDIF
 ENDBLOCK
