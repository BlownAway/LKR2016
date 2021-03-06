{   BlokkD.inc SILC}

EMBEDDED BLOCK BlokkD "Vinnut�mi"
    PARAMETERS
        IMPORT Pers�na   : TPers�na
        IMPORT Tv�St�rf  : TJ�Nei
        EXPORT vinnut�mi : INTEGER
    FIELDS
      DVenja (D01)
        "^haus@/^fsvar@/^strik@/
        Hva� vinnur ^�� margar klukkustundir � viku a� jafna�i � ^��nu a�alstarfi?
        @/@/@GSetja 0 ef vinnut�mi er mj�g �reglulegur@G"
         "^haus@/^fsvar@/^strik@/
         How many hours ^doyou work in a normal week in ^your main job?
        @/@/@GSetja 0 ef vinnut�mi er mj�g �reglulegur@G"
        /"Venjulegur vinnut�mi"
        : 0..120, dontknow
        
      D�trek (D01�trek)
        "^haus@/^fsvar@/^strik@/
        Getur �� sagt � hva�a bili me�alvinnut�minn er � viku...
        @/@/@GLestu upp svarkostina@G"
        "^haus@/^fsvar@/^strik@/
        Can you give a range for ^your average working hours per week...
        @/@/@GLestu upp svarkostina@G"
        /"Me�alvinnut�mabil"
        : (
        EinnTil10                       "...1-10",
        Ellefutil20                     "...11-20",
        TuttuguogEinnTil30              "...21-30",
        �rj�t�uogeinnTil34              "...31-34",
        �rj�t�uogfimmTil45              "...35-45",
        Fj�rut�uogsexTil50              "...46-50",
        Fimmt�uogeinnTil60              "...51-60",
        Sext�uogeinnPl�s                "...61 e�a fleiri")

      GS��ast (G09)
        "^haus@/^fsvar@/^strik@/
        Hva� vinnur ^�� margar klukkustundir � viku a� jafna�i � aukastarfi e�a st�rfum?
        @/@/@G�tt er vi� heildarvinnut�ma � �llum aukast�rfum. Launa� aukastarf n�r l�ka
        yfir st�rf �ar sem tekjurnar koma me� ��rum h�tti, til d�mis rekstrarhagna�i.@G
        @/@/@GSetja 0 ef vinnut�mi er mj�g �reglulegur e�a starfi� ekki venjulegt@G"
        "^haus@/^fsvar@/^strik@/
        How many hours per week do you usually work in other jobs besides your regular job?
        @/@/@G�tt er vi� heildarvinnut�ma � �llum aukast�rfum. Launa� aukastarf n�r l�ka
        yfir st�rf sem �ar sem tekjurnar koma me� ��rum h�tti, til d�mis rekstrarhagna�i.@G
        @/@/@GSetja 0 ef vinnut�mi er mj�g �reglulegur e�a starfi� ekki venjulegt@G"
        /"Vinnut�mi"
        : 0..100

      G�trek
        "^haus@/^fsvar@/^strik@/
        Getur �� sagt � hva�a bili me�alvinnut�minn er � viku...
        @/@/@GLestu upp svarkostina@G"
        "^haus@/^fsvar@/^strik@/
        Per week, are ^your average working hours between...
        @/@/@GLestu upp svarkostina@G"
        /"Me�alvinnut�mabil"
        : (
        EinnTil10                       "...1-10",
        Ellefutil20                     "...11-20",
        TuttuguogEinnTil30              "...21-30",
        �rj�t�uogeinnTil34              "...31-34",
        �rj�t�uogfimmTil45              "...35-45",
        Fj�rut�uogsexTil50              "...46-50",
        Fimmt�uogeinnTil60              "...51-60",
        Sext�uogeinnPl�s                "...61 e�a fleiri")


    AUXFIELDS
      �_a�alstarfinu  : STRING
      MeirMinn : (Meira, Minna)
      
      ��      : (karl2p "��",kona2p "��",karl3p "hann",kona3p "h�n",�v�st3p "hann/h�n")
      �inn    : (karl2p "�inn",kona2p "�inn",karl3p "hans",kona3p "hennar",�v�st3p "hans/hennar")
      ��nu    : (karl2p "��nu",kona2p "��nu",karl3p "s�nu",kona3p "s�nu",�v�st3p "s�nu")
      ��r     : (karl2p "��r",kona2p "��r",karl3p "s�r",kona3p "s�r",�v�st3p "s�r")
      �ig     : (karl2p "�ig",kona2p "�ig",karl3p "hann",kona3p "hana",�v�st3p "hann/hana")
      stu     : (karl2p "stu",kona2p "stu",karl3p " hann",kona3p " h�n",�v�st3p " hann/h�n")
      n       : (karl2p "n",kona2p " ",karl3p "n",kona3p " ", �v�st3p "/n")
      ur      : (karl2p "ur",kona2p " ",karl3p "ur",kona3p " ", �v�st3p "ur")
      you     : (karl2p "you",kona2p "you",karl3p "he",kona3p "she",�v�st3p "he/she")
      your    : (karl2p "your",kona2p "your",karl3p "his",kona3p "her",�v�st3p "his/her")
      doyou   : (karl2p "Do you",kona2p "Do you",karl3p "Does he",kona3p "Does she",�v�st3p "Does he/she")


    LOCALS
      StarfN�Hafi� : STRING

    RULES
      ��:=pers�na.ord
      �ig:=pers�na.ord
      ��nu:=pers�na.ord
      �inn:=pers�na.ord
      stu:=pers�na.ord
      ��r:=pers�na.ord
      you:=pers�na.ord
      your:=pers�na.ord
      doyou:=pers�na.ord
      n:=pers�na.ord
      ur:=pers�na.ord

      {Vinnut�mi � a�alstarfi}
      
      DVenja

      IF DVenja = dontknow or DVenja = 0 THEN
        {DFlokk}
        D�trek
        IF D�trek = EinnTil10 THEN DVenja := 5
        ELSEIF D�trek = Ellefutil20  THEN DVenja := 15
        ELSEIF D�trek = TuttuguogEinnTil30 THEN DVenja := 25
        ELSEIF D�trek = �rj�t�uogeinnTil34 THEN DVenja := 33
        ELSEIF D�trek = �rj�t�uogfimmTil45 THEN DVenja := 40
        ELSEIF D�trek = Fj�rut�uogsexTil50 THEN DVenja := 48
        ELSEIF D�trek = Fimmt�uogeinnTil60 THEN DVenja := 55
        ELSEIF D�trek = Sext�uogeinnPl�s   THEN DVenja := 70
        ENDIF
      ENDIF
      vinnut�mi:=DVenja
      {Vinnut�mi � aukast�rfum}
      IF Tv�st�rf = J� THEN
         GS��ast
         if (GS��ast = dk) or (GS��ast = 0) then
           G�trek
           IF G�trek = EinnTil10 THEN GS��ast := 5
           ELSEIF G�trek = Ellefutil20  THEN GS��ast := 15
           ELSEIF G�trek = TuttuguogEinnTil30 THEN GS��ast := 25
           ELSEIF G�trek = �rj�t�uogeinnTil34 THEN GS��ast := 33
           ELSEIF G�trek = �rj�t�uogfimmTil45 THEN GS��ast := 40
           ELSEIF G�trek = Fj�rut�uogsexTil50 THEN GS��ast := 48
           ELSEIF G�trek = Fimmt�uogeinnTil60 THEN GS��ast := 55
           ELSEIF G�trek = Sext�uogeinnPl�s   THEN GS��ast := 70
           ENDIF
         ENDIF
         vinnut�mi:=DVenja+GS��ast
      ENDIF

ENDBLOCK
