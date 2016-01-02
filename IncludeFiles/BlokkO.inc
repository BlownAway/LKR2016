{   BlokkO.inc
    Samfelld vinnumarka�sranns�kn
    �H (c) desember 2002
    �H (c) mars 2003 - �tg. 1.2
 }

EMBEDDED BLOCK BlokkO "Sk�laganga"
   PARAMETERS
      IMPORT vi�mi�unardagur : DateType
      IMPORT pers�na : TPers�na
      import F���r : integer
      {EXPORT Menntun : TGMenntun
      EXPORT Sk�lak�ti : TNAM}

   EXTERNALS
     n�msbraut : N�m
     i�ngrein  : I�n
     sk�lar    : Sk�lar

    EMBEDDED BLOCK BSkolaLeit
        PARAMETERS
        EXPORT dialogueResult : TLeit
        FIELDS
            OSkLeit : TLeit
            ROUTER leita ALIEN('LookupManager.msu','prc_skoliLookup')
        RULES
            OSkLeit
            dialogueResult:=OSkLeit
    ENDBLOCK

    EMBEDDED BLOCK BNamLeit
        PARAMETERS
        EXPORT dialogueResult : TLeit
        FIELDS
            OSkLeit : TLeit
            ROUTER leita ALIEN('LookupManager.msu','prc_namLookup')
        RULES
            OSkLeit
            dialogueResult:=OSkLeit
    ENDBLOCK

    FIELDS
      OSk�li (o01)
        "^haus@/^fsvar@/^strik@/
        Var^stu � sk�la e�a � n�mssamningi � ^s��ustufj�rumvikum?"
        "^haus@/^fsvar@/^strik@/
        W^ere_you registered at school or on an apprenticeship in the ^lastfourweeks?"
        /"Sk�li s��ustu 4 vikur"
        : TSk�li2b

      OSkHva�a (o02a)
        "^haus@/^fsvar@/^strik@/
        � hva�a sk�la var^stu?"
        "^haus@/^fsvar@/^strik@/
        In what school w^ere_you?"
        /"Hva�a sk�li"
        : STRING[80]
      OSkHva�a_b ""/"Heiti"      : STRING[80]
      OSklID     ""/"Fastan�mer" : INTEGER

      Namsstig
         "^haus@/^fsvar@/^strik@/
          Er �etta grunnsk�li, framhaldssk�li, i�nsk�li, h�sk�li e�a anna� n�m?"
        "^haus@/^fsvar@/^strik@/
          What level of education is this?
          Is this a primary school, middle school, high school, vocational school, college, university
          or something else?"
        /"Grunnsk�li"
        : TSkolastig

      ONamHva� (o02b)
        "^haus@/^fsvar@/^strik@/
        � hva�a ^n�msgrein?"
        "^haus@/^fsvar@/^strik@/
        In which ^field?"
        /"Hva�a n�msgrein"
        : STRING[120]
      ONamHva�_b: STRING[120]

      OSklK�ti (o02c)
        "^haus@/^fsvar@/^strik@/
        @GFlettu upp vi�eigandi k�ta me� �v� a� �ta � BILST�NGINA
        @/@/Veri� er a� leita a� r�ttu sk�lastigi og n�msgrein.  Ef �� finnur ekki n�kv�mlega
        �ann sk�la sem vi�komandi var � m�ttu velja n�msgreinina � ��rum sk�la svo fremi
        sk�linn s� � sama sk�lastigi (ISCED).@G"
        /"Fastan�mer n�ms"
        : INTEGER


      {ONmsHva� (o03a)
        "^haus@/^fsvar@/^strik@/
        � hva�a i�ngrein var^stu � n�mssamningi?"
        "^haus@/^fsvar@/^strik@/
        In which trade/craft?"
        /"Hva�a i�ngrein"
        : STRING[80]

      ONmsK�ti (o03b)
        "^haus@/^fsvar@/^strik@/
        @GFlettu upp vi�eigandi k�ta me� �v� a� �ta � BILST�NGINA@G"
        /"K�ti i�ngreinar"
        : TNam }
      Skolaleit: BSkolaleit
      Nam_leit : BNamleit
      



    AUXFIELDS
      Menntun : TGMenntun
      Sk�lak�ti : TNAM

      OSkLeit  : TLeit
      ONamLeit : TLeit
      
      sK�ti    : String

      s��ustufj�rumvikum : STRING
      lastfourweeks : STRING


      stu  : (karl2p "stu",kona2p "stu",karl3p " hann",kona3p " h�n",�v�st3p " hann/h�n")
      ere_you : (karl2p "ere you",kona2p "ere you",karl3p "as he",kona3p "as she",�v�st3p "as he/she")
      n : (karl2p "n",kona2p " ",karl3p "n",kona3p " ", �v�st3p "/n")
      ur: (karl2p "ur",kona2p " ",karl3p "ur",kona3p " ",�v�st3p "(ur)")
      
    LOCALS
      iK�ti    : String
      n�msgrein : string
      field     :string

    RULES
      stu:=pers�na.ord
      ere_you:=pers�na.ord
      n:=pers�na.ord
      ur:=pers�na.ord

      prc_vi�mi�unart�miSpurt (vi�mi�unardagur - (0,0,27), vi�mi�unardagur, S��ustuFj�rumVikum, lastFourWeeks)

      OSk�li

      IF OSk�li IN [Sk�li, b��i] THEN
        OSkHva�a
        Skolaleit.leita(OskLeit)
        OSklID.show
        OSkHva�a_b.show
        IF(OskLeit<>Fannst)  THEN
            Namsstig
        ELSE
            Namsstig.show
        ENDIF
      ENDIF
      n�msgrein:='n�msgrein'
      field :='field'
      IF OSk�li IN [n�mssamningur, b��i] THEN
         n�msgrein:='i�ngrein var n�mssamningurinn'
         field :='trade or craft is the apprenticeship'
      ENDIF
      IF Namsstig > grunnsk�li or OSk�li IN [n�mssamningur, b��i]  THEN 
         ONamHva�
         Nam_leit.leita(ONamLeit)
         OSklK�ti.show
         ONamHva�_b.show
         sK�ti.show
         {Sk�lak�ti := OSklK�ti}
      ENDIF


      {IF (year(vi�mi�unardagur) - F���r) <= 20 THEN
        IF Substring(sK�ti,1,1)='5' THEN Menntun:= St�dent
        ELSEIF Substring(sK�ti,1,1)='3' THEN Menntun := Grunnsk�li
        ELSEIF Substring(iK�ti,1,1)='3' THEN Menntun := Grunnsk�li
        ELSEIF Substring(SK�ti,1,1)='2' THEN Menntun := MinnaEnGrunnsk�li
        ENDIF
      ELSEIF (year(vi�mi�unardagur) - F���r) <= 24 THEN
        IF Substring(sK�ti,1,1)='5' THEN Menntun:= St�dent ENDIF
      ELSE
        IF Substring(sK�ti,1,1)='5' THEN Menntun:= St�dent                             {ath hvort �etta � a� vera svona}
        ELSEIF Substring(sK�ti,1,1)='3' THEN Menntun := Grunnsk�li
        ELSEIF Substring(iK�ti,1,1)='3' THEN Menntun := Grunnsk�li
        ELSEIF Substring(SK�ti,1,1)='2' THEN Menntun := MinnaEnGrunnsk�li
        ENDIF
      ENDIF }

ENDBLOCK
