{   BlokkC.inc  SILC}

EMBEDDED BLOCK BlokkC "Ráðningarsamband"
    FIELDS
      CTímbnd (C05)
        "^haus@/^fsvar@/^strik@/
        Er^tu ráðin^n tímabundið?
        @/@/@GTímabundin ráðning á til dæmis við um þá sem eru verkefnaráðnir. Ef ráðningasamningur
        er ekki með neinu ákvæði um að hann taki enda er hann ekki tímabundinn.
        Sumarstörf námsmanna eru oftast tímabundin."
        "^haus@/^fsvar@/^strik@/
        ^Are ^you employed on a temporary basis?
        @/@/@GTímabundin ráðning á til dæmis við um þá sem eru verkefnaráðnir. Ef ráðningasamningur
        er ekki með neinu ákvæði um að hann taki enda er hann ekki tímabundinn.
        Sumarstörf námsmanna eru oftast tímabundin."
        /"Tímabundin ráðning"
        : TJáNei
    RULES
      CTímbnd
ENDBLOCK
