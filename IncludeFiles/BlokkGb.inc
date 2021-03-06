{   BlokkGb.inc SILC}

EMBEDDED BLOCK BlokkGb "Vinnut�mi � aukast�rfum"
    FIELDS
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

    RULES
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
ENDBLOCK
