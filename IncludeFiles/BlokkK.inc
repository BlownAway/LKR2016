{   BlokkK.inc SILC}
{Er rétt að spyrja þá sem eru tímabundið fjarverandi frá vinnu hvort þeir séu í atvinnuleit?}


EMBEDDED BLOCK BlokkK "Atvinnuleit"
    PARAMETERS
        IMPORT viðmiðunardagur: DateType
        IMPORT Persóna : TPersóna
    FIELDS
      KLeita (K01)
        "^haus@/^fsvar@/^strik@/
        Leitaði^r ^þú að vinnu á ^síðustu_fjórum_vikum?"
        "^haus@/^fsvar@/^strik@/
        Did ^you look for work during ^the_last_four_weeks?"
        /"Atvinnuleit"
        : TJáNei

      KByrja (K09)
        "^haus@/^fsvar@/^strik@/
        Gæti^r ^þú byrjað að vinna í nýju starfi innan tveggja vikna?"
        "^haus@/^fsvar@/^strik@/
        Can ^you start work within two weeks?"
        /"Hvenær hafið störf"
        : TJáNei


    AUXFIELDS
        samanlagt   : String
        síðustu_fjórum_vikum, the_last_four_weeks: String
        
        þú   : (karl2p "þú",kona2p "þú",karl3p "hann",kona3p "hún",óvíst3p "hann/hún")
        r    : (karl2p "r",kona2p "r",karl3p " ",kona3p " ", óvíst3p " ")
        n    : (karl2p "n",kona2p " ",karl3p "n",kona3p " ", óvíst3p "/n")
        ur   : (karl2p "ur",kona2p " ",karl3p "ur",kona3p " ",óvíst3p "(ur)")
        you  : (karl2p "you",kona2p "you",karl3p "he",kona3p "she",óvíst3p "he/she")

    RULES
      
      þú  :=persóna.ord
      r   :=persóna.ord
      n   :=persóna.ord
      ur  :=persóna.ord
      you :=persóna.ord

      prc_viðmiðunartímiSpurt (Viðmiðunardagur - (0,0,27), viðmiðunardagur, síðustu_fjórum_vikum, the_last_four_weeks)

      KLeita
      IF KLeita = já then KByrja endif
      
ENDBLOCK
