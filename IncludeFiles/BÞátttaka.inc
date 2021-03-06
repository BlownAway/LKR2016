{   B��tttaka.inc

    �H des 2002

    V�sa� er � eftirfarandi breytur:
      nafn    : Fullt nafn ��tttakanda
      fornafn : Sk�rnarnafn ��tttakanda
      haus    : Au�kenni k�nnunar
                Au�kenni ��tttakanda
      fsvar   : Fyrri sv�r (ef e-r eru)
      strik   : L�na sem a�skilur haus og spurningu
}

EMBEDDED BLOCK B��tttaka
  PARAMETERS
    IMPORT Kyn     : TKyn
    EXPORT Pers�na : TPers�na


  FIELDS
    Sami (�01)
      "^haus@/^fsvar@/^strik@/
       Skr�i� h�r hver vi�m�landinn er"
      "^haus@/^fsvar@/^strik@/
       Statistics Iceland is conducting a survey of income and living conditions in Iceland.
       The survey is a part of larger research which is supervised by the European Union and
       will be used to compare living conditions and income across the continent.
       @/@GPlease register here who the respondent is@G"
      /"Hver svarar"
      : (Sj�lfur     "^nafn",
         Annar       "Annar � heimilinu svarar fyrir ^fornafn",	{Breytt jan 2013 -Proxy vi�t�l vi� a�ra en heimilismenn eru ekki leyfileg. �v� �arf a� breyta m�guleikanum �Annar svarar fyrir...� � �01Sami � �Annar � heimilinu svarar fyrir...� }
         T�lkur      "T�lkur a�sto�ar ^fornafn",
         Adeins      "Vill a�eins svara um heimilismenn")

    HverSvarar "^haus@/^fsvar@/^strik@/
                Hvert er nafn �itt?
                @/@Rtaka ni�ur fullt nafn svarandans@R"
                "^haus@/^fsvar@/^strik@/
                What is your name?"
                / "Heiti sta�gengils"
                :  string[50]
    Vidbrogd "^haus@/^fsvar@/^strik@/ @GHver voru fyrst vi�br�g� �rtakseiningar vi� ��ttt�kubei�ninni?@g"/"Fyrstu vi�br�g�" :
            TVidbrogd

   RULES
     Vidbrogd
     Sami
     IF Sami = Annar THEN
       HverSvarar
       IF Kyn = Karl THEN
         Pers�na := AnnarKarl
       ELSE
         Pers�na := AnnarKona
       ENDIF
     ELSE
       IF Kyn = Karl THEN
         Pers�na := Karl
       ELSE
         Pers�na := Kona
       ENDIF
     ENDIF

ENDBLOCK


