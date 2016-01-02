{ BLeiðrétta.INC
  ÓH (c) des. 2002

  Eftirfarandi breytur þurfa að vera fyrir hendi:
  haus        :  Heiti könnunar og dagsetning
                 Auðkenni þátttakanda
  fsvar       :  Fyrra svar (ef til er)
  strik       :  Strikalína sem aðskilur haus og spurningu

}

BLOCK BLeiðrétta "Leiðrétta síma og heimilisföng"

 FIELDS
   Sími  "^haus@/^fsvar@/^strik@/
          Annað símanúmer?"
         /"Aðalsími"
         : STRING[12],EMPTY
   ASímar"^haus@/^fsvar@/^strik@/
          Önnur símanúmer "
         /"Aðrir símar"
         : STRING[150],EMPTY
   Aths1 "^haus@/^fsvar@/^strik@/
          Athugasemd"
         /"Athugasemd"
         : STRING[250]
   Staðsetning
         "^haus@/^fsvar@/^strik@/
          Heimilisfang"
         /"Heimilisfang"
         : STRING[50],EMPTY
   AnnarViðmælandi
         "^haus@/^fsvar@/^strik@/
          Hvert er nafn þess sem á að tala við næst þegar hringt er til að fá svör við seinni hlutanum?"
         /"Annar viðmælandi"
         : STRING[50],EMPTY

    AUXFIELDS
      nSími, nSímar : String

RULES
    Sími
    ASímar
    prc_Trimma(Sími, nSími)
    prc_BætaViðAðraSíma (Sími, aSímar, nSímar)
    IF nSímar <> ASímar And (Len(nSími)> 7 Or (Len(nSími) = 7 And Position(Substring(nSími,1,1),'4568')>0)) THEN
      ASímar := nSímar
    ENDIF
    Aths1
    AnnarViðmælandi
    Staðsetning
    IF (Len(nSími)>0 And Len(nSími)< 7) Or (Len(nSími)=7 AND Position(Substring(nSími,1,1),'45678')=0) INVOLVING (Sími) THEN
        Len(nSími)> 7 Or (Len(nSími) = 7 And Position(Substring(nSími,1,1),'45678')>0) "Ógilt símanúmer!"
    ENDIF
LAYOUT
  At ASímar
    FIELDPANE tvofoldLongLina
ENDBLOCK

