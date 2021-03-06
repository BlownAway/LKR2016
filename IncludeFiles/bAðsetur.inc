{   BA�setur.INC
    �H des 2002

    Eftirfarandi breytur �urfa a� vera fyrir hendi:
    haus      : Au�kenni k�nnunar
                Au�kenni ��tttakanda
    fsvar     : Vi�eigandi fyrra svar
    strik     : Strik milli hauss og spurninga

    Sveitarf�lag  : Sveitarf�lag l�gheimilis (me� forsetningu)
    AS�mar        : Allir s�mar
    UpphafsS�mi   : �ll s�man�mer � upphafi k�nnunar


}

EMBEDDED BLOCK BA�setur     "A�setur ��tttakanda"
  PARAMETERS
    IMPORT  Pers�na : TPers�na

  FIELDS
    A�setur (X01)
      "^haus@/^fsvar@/^strik@/
       �� er komi� a� spurningum um heimili� og heimilismenn.
       @/�
       @/
       Er ^Lei�r�tta.Sta�setning r�tt heimilisfang?"
      "^haus@/^fsvar@/^strik@/
       Next I will ask questions about the household and householdmembers.
       @/�
       @/
       ^Do_you still live at ^Lei�r�tta.Sta�setning  ?"
      /"R�tt a�setur"
      : TJ�Nei
    N�Sveit (X02)
      "^haus@/^fsvar@/^strik@/
       Hva�a sveitarf�lagi?"
      "^haus@/^fsvar@/^strik@/
       What town or municipality ?"
      /"Hva�a sveitarf�lag"
      : STRING[30]
    SvfK�ti (X03)
        "^haus@/^fsvar@/^strik@/
        @GFlettu upp vi�eigandi k�ta me� �v� a� �ta � BILST�NGINA@G"
        /"Sveitarf�lagsk�ti"
      : TSveit

    Gata  (X04)
     "^haus@/^fsvar@/^strik@/
       Hvert er r�tta heimilisfangi�?
       @/@/@GSkr�i� n�kv�mt g�tuheiti og �b��arn�mer ef � fj�lb�li.  �essar uppl�singar ver�a nota�ar til a� reikna �t
       fasteignagj�ldin.@G"
      "^haus@/^fsvar@/^strik@/
       What is your address?"
      /"Gata og h�sn�mer"
      : STRING[50]

    AdseturByrjarDags : Datetype
    AdseturByrjarTimi : Timetype
    endanlegt_heimilisfang: string[50]


  LOCALS
   do_you: STRING

  EXTERNALS
    zveit: SVEIT ('Sveit\SVEIT')

  RULES

   
    prc_YouDoDoes   (pers�na, do_you)

    A�setur
    AdseturByrjarDags.keep
    AdseturByrjarTimi.keep
    IF A�setur <> empty then
      IF AdseturByrjarDags = EMPTY THEN
        AdseturByrjarDags := SysDate
        AdseturByrjarTimi := SysTime
      ENDIF
    ENDIF
    IF A�setur = Nei THEN
      Gata
      N�Sveit
      SvfK�ti|zveit.LOOKUP(Tri:=(N�Sveit)).Sveitarf�lagsk�ti
    ENDIF
    IF a�setur = j� then 
        endanlegt_heimilisfang := Lei�r�tta.Sta�setning
    elseif a�setur = nei then 
        endanlegt_heimilisfang := gata
    endif


ENDBLOCK

