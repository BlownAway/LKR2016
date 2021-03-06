{   BlokkK.inc SILC}
{Er r�tt a� spyrja �� sem eru t�mabundi� fjarverandi fr� vinnu hvort �eir s�u � atvinnuleit?}


EMBEDDED BLOCK BlokkK "Atvinnuleit"
    PARAMETERS
        IMPORT vi�mi�unardagur: DateType
        IMPORT Pers�na : TPers�na
    FIELDS
      KLeita (K01)
        "^haus@/^fsvar@/^strik@/
        Leita�i^r ^�� a� vinnu � ^s��ustu_fj�rum_vikum?"
        "^haus@/^fsvar@/^strik@/
        Did ^you look for work during ^the_last_four_weeks?"
        /"Atvinnuleit"
        : TJ�Nei

      KByrja (K09)
        "^haus@/^fsvar@/^strik@/
        G�ti^r ^�� byrja� a� vinna � n�ju starfi innan tveggja vikna?"
        "^haus@/^fsvar@/^strik@/
        Can ^you start work within two weeks?"
        /"Hven�r hafi� st�rf"
        : TJ�Nei


    AUXFIELDS
        samanlagt   : String
        s��ustu_fj�rum_vikum, the_last_four_weeks: String
        
        ��   : (karl2p "��",kona2p "��",karl3p "hann",kona3p "h�n",�v�st3p "hann/h�n")
        r    : (karl2p "r",kona2p "r",karl3p " ",kona3p " ", �v�st3p " ")
        n    : (karl2p "n",kona2p " ",karl3p "n",kona3p " ", �v�st3p "/n")
        ur   : (karl2p "ur",kona2p " ",karl3p "ur",kona3p " ",�v�st3p "(ur)")
        you  : (karl2p "you",kona2p "you",karl3p "he",kona3p "she",�v�st3p "he/she")

    RULES
      
      ��  :=pers�na.ord
      r   :=pers�na.ord
      n   :=pers�na.ord
      ur  :=pers�na.ord
      you :=pers�na.ord

      prc_vi�mi�unart�miSpurt (Vi�mi�unardagur - (0,0,27), vi�mi�unardagur, s��ustu_fj�rum_vikum, the_last_four_weeks)

      KLeita
      IF KLeita = j� then KByrja endif
      
ENDBLOCK
