{   BAðsetur.INC
    ÓH des 2002

    Eftirfarandi breytur þurfa að vera fyrir hendi:
    haus      : Auðkenni könnunar
                Auðkenni þátttakanda
    fsvar     : Viðeigandi fyrra svar
    strik     : Strik milli hauss og spurninga

    Sveitarfélag  : Sveitarfélag lögheimilis (með forsetningu)
    ASímar        : Allir símar
    UpphafsSími   : Öll símanúmer í upphafi könnunar


}

EMBEDDED BLOCK BAðsetur     "Aðsetur þátttakanda"
  PARAMETERS
    IMPORT  Persóna : TPersóna

  FIELDS
    Aðsetur (X01)
      "^haus@/^fsvar@/^strik@/
       Þá er komið að spurningum um heimilið og heimilismenn.
       @/·
       @/
       Er ^Leiðrétta.Staðsetning rétt heimilisfang?"
      "^haus@/^fsvar@/^strik@/
       Next I will ask questions about the household and householdmembers.
       @/·
       @/
       ^Do_you still live at ^Leiðrétta.Staðsetning  ?"
      /"Rétt aðsetur"
      : TJáNei
    NýSveit (X02)
      "^haus@/^fsvar@/^strik@/
       Hvaða sveitarfélagi?"
      "^haus@/^fsvar@/^strik@/
       What town or municipality ?"
      /"Hvaða sveitarfélag"
      : STRING[30]
    SvfKóti (X03)
        "^haus@/^fsvar@/^strik@/
        @GFlettu upp viðeigandi kóta með því að ýta á BILSTÖNGINA@G"
        /"Sveitarfélagskóti"
      : TSveit

    Gata  (X04)
     "^haus@/^fsvar@/^strik@/
       Hvert er rétta heimilisfangið?
       @/@/@GSkráið nákvæmt götuheiti og íbúðarnúmer ef í fjölbýli.  Þessar upplýsingar verða notaðar til að reikna út
       fasteignagjöldin.@G"
      "^haus@/^fsvar@/^strik@/
       What is your address?"
      /"Gata og húsnúmer"
      : STRING[50]

    AdseturByrjarDags : Datetype
    AdseturByrjarTimi : Timetype
    endanlegt_heimilisfang: string[50]


  LOCALS
   do_you: STRING

  EXTERNALS
    zveit: SVEIT ('Sveit\SVEIT')

  RULES

   
    prc_YouDoDoes   (persóna, do_you)

    Aðsetur
    AdseturByrjarDags.keep
    AdseturByrjarTimi.keep
    IF Aðsetur <> empty then
      IF AdseturByrjarDags = EMPTY THEN
        AdseturByrjarDags := SysDate
        AdseturByrjarTimi := SysTime
      ENDIF
    ENDIF
    IF Aðsetur = Nei THEN
      Gata
      NýSveit
      SvfKóti|zveit.LOOKUP(Tri:=(NýSveit)).Sveitarfélagskóti
    ENDIF
    IF aðsetur = já then 
        endanlegt_heimilisfang := Leiðrétta.Staðsetning
    elseif aðsetur = nei then 
        endanlegt_heimilisfang := gata
    endif


ENDBLOCK

