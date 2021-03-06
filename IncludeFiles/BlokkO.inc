{   BlokkO.inc
    Samfelld vinnumarka�sranns�kn
    �H (c) desember 2002
    �H (c) mars 2003 - �tg. 1.2
 }

EMBEDDED BLOCK BlokkO "Sk�laganga"
   PARAMETERS
      IMPORT vi�mi�unardagur : DateType
      IMPORT pers�na   : TPers�na
      IMPORT aldur : INTEGER
      {EXPORT Menntun : TGMenntun
      EXPORT Sk�lak�ti : TNAM}

   {EXTERNALS
     n�msbraut : N�m
     i�ngrein  : I�n
     sk�lar    : Sk�lar}

    EMBEDDED BLOCK BSkolaLeit
        FIELDS
            OSkHva�a_b "@GFlettu upp vi�eigandi sk�la me� �v� a� �ta � BILST�NGINA" : STRING[50]
            ROUTER leita ALIEN('LookupManager.msu','prc_skoliLookup')
        RULES
            OSkHva�a_b
    ENDBLOCK

    EMBEDDED BLOCK BNamLeit
        FIELDS
            ONamHva�_b "@GFlettu upp vi�eigandi n�msgrein me� �v� a� �ta � BILST�NGINA
                       @/@/Veri� er a� leita a� r�ttu sk�lastigi og n�msgrein.
                       Ef �� finnur nokkrar svipa�ar n�msgreinar sem passa
                       skiptir ekki m�li hver er valin ef allar er � sama stigi og svi�i.@G": STRING[120]
            ROUTER leita ALIEN('LookupManager.msu','prc_namLookup')
        RULES
            ONamHva�_b
    ENDBLOCK

    FIELDS
      OSk�li (o01)
        "Var^stu � sk�la e�a � n�mssamningi � ^s��ustufj�rumvikum?"
        "W^ere_you registered at school or on an apprenticeship in the ^lastfourweeks?"
        /"Sk�li s��ustu 4 vikur"
        : TSk�li2b

      OSkHva�a (o02a)
        "� hva�a sk�la var^stu?"
        "In what school w^ere_you?"
        /"Hva�a sk�li"
        : STRING[80]
      OSklID     ""/"Fastan�mer" : INTEGER

      OSkstig
         "Er �etta grunnsk�li e�a framhaldsn�m?"
         "Is this a part of compulsory schooling or studies beyond compulsory schooling?"
        /"Grunnsk�li"
        : TSkyldun�m

      ONamHva� (o02b)
        "� hva�a ^n�msgrein?"
        "In which ^field?"
        /"Hva�a n�msgrein"
        : STRING[120]


      OSklK�ti (o02c)
        " @GFlettu upp vi�eigandi sk�la me� �v� a� �ta � BILST�NGINA"
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


      ONamGrada (o04)
  	  "Er^tu �..."
      "^Are_you studying for... "
  	 /"Gr��a"
  	 : TFrhN�m

     ONamHaskoli (o04b)
  	  "Hva�a pr�fgr��u mi�ast n�mi� a�?"
  	  "What examination or degree are ^you studying for:"
  	/ "H�sk�lapr�f"
  	: TGr��a

    Skolaleit: BSkolaleit
    Nam_leit : BNamleit
  AUXFIELDS
    Menntun : TGMenntun
    Sk�lak�ti : TNAM

    s��ustufj�rumvikum : STRING
    lastfourweeks : STRING

    sK�ti    : String
    Sk�lastig : TSkyldun�m

    stu  : (karl2p "stu",kona2p "stu",karl3p " hann",kona3p " h�n",�v�st3p " hann/h�n")
    ere_you : (karl2p "ere you",kona2p "ere you",karl3p "as he",kona3p "as she",�v�st3p "as he/she")
    n : (karl2p "n",kona2p " ",karl3p "n",kona3p " ", �v�st3p "/n")
    ur: (karl2p "ur",kona2p " ",karl3p "ur",kona3p " ",�v�st3p "(ur)")
    are_you:  (karl2p "Are you",kona2p "Are you",karl3p "Is he",kona3p "Is she",�v�st3p "Is he/she")
    tu   :(karl2p "tu",kona2p "tu",karl3p " hann",kona3p " h�n",�v�st3p " hann/h�n")
    you :  (karl2p "you",kona2p "you",karl3p "he",kona3p "she",�v�st3p "he/she")


  LOCALS
    iK�ti    : String
    n�msgrein : string
    field     :string

  RULES
      stu:=pers�na.ord
      ere_you:=pers�na.ord
      n:=pers�na.ord
      ur:=pers�na.ord
      are_you:=pers�na.ord
      tu:=pers�na.ord
      you:=pers�na.ord

      prc_vi�mi�unart�miSpurt (vi�mi�unardagur - (0,0,27), vi�mi�unardagur, S��ustuFj�rumVikum, lastFourWeeks)

      OSk�li

      IF OSk�li IN [Sk�li, b��i] THEN
        OSkHva�a
        Skolaleit.leita
        OSklID.show
      ENDIF
      Sk�lastig.keep
      IF Sk�lastig=empty THEN
         IF (aldur<18) THEN
           OSkstig
         ELSE
           OSkstig:= Framhaldsn�m
           OSkstig.show
         ENDIF
      ELSE
        OSkstig:=Sk�lastig
        OSkstig.show
      ENDIF
      n�msgrein:='n�msgrein'
      field :='field'
      IF OSk�li IN [n�mssamningur, b��i] THEN
         n�msgrein := 'i�ngrein var n�mssamningurinn'
         field     := 'trade or craft is the apprenticeship'
      ENDIF
      IF OSkstig = Framhaldsn�m THEN
         ONamHva�
         Nam_leit.leita
         OSklK�ti.show
         sK�ti.show
         {Sk�lak�ti := OSklK�ti}
      ENDIF




      {IF (year(vi�mi�unardagur) - F���r) <= 20 THEN

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

