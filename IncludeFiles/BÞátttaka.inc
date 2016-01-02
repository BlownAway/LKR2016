{   Bþátttaka.inc

    ÓH des 2002

    Vísað er í eftirfarandi breytur:
      nafn    : Fullt nafn þátttakanda
      fornafn : Skírnarnafn þátttakanda
      haus    : Auðkenni könnunar
                Auðkenni þátttakanda
      fsvar   : Fyrri svör (ef e-r eru)
      strik   : Lína sem aðskilur haus og spurningu
}

EMBEDDED BLOCK BÞátttaka
  PARAMETERS
    IMPORT Kyn     : TKyn
    EXPORT Persóna : TPersóna


  FIELDS
    Sami (Þ01)
      "^haus@/^fsvar@/^strik@/
       Skráið hér hver viðmælandinn er"
      "^haus@/^fsvar@/^strik@/
       Statistics Iceland is conducting a survey of income and living conditions in Iceland.
       The survey is a part of larger research which is supervised by the European Union and
       will be used to compare living conditions and income across the continent.
       @/@GPlease register here who the respondent is@G"
      /"Hver svarar"
      : (Sjálfur     "^nafn",
         Annar       "Annar á heimilinu svarar fyrir ^fornafn",	{Breytt jan 2013 -Proxy viðtöl við aðra en heimilismenn eru ekki leyfileg. Því þarf að breyta möguleikanum „Annar svarar fyrir...“ í Þ01Sami í „Annar á heimilinu svarar fyrir...“ }
         Túlkur      "Túlkur aðstoðar ^fornafn",
         Adeins      "Vill aðeins svara um heimilismenn")

    HverSvarar "^haus@/^fsvar@/^strik@/
                Hvert er nafn þitt?
                @/@Rtaka niður fullt nafn svarandans@R"
                "^haus@/^fsvar@/^strik@/
                What is your name?"
                / "Heiti staðgengils"
                :  string[50]
    Vidbrogd "^haus@/^fsvar@/^strik@/ @GHver voru fyrst viðbrögð úrtakseiningar við þátttökubeiðninni?@g"/"Fyrstu viðbrögð" :
            TVidbrogd

   RULES
     Vidbrogd
     Sami
     IF Sami = Annar THEN
       HverSvarar
       IF Kyn = Karl THEN
         Persóna := AnnarKarl
       ELSE
         Persóna := AnnarKona
       ENDIF
     ELSE
       IF Kyn = Karl THEN
         Persóna := Karl
       ELSE
         Persóna := Kona
       ENDIF
     ENDIF

ENDBLOCK


