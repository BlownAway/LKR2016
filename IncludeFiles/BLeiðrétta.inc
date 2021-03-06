{ BLei�r�tta.INC
  �H (c) des. 2002

  Eftirfarandi breytur �urfa a� vera fyrir hendi:
  haus        :  Heiti k�nnunar og dagsetning
                 Au�kenni ��tttakanda
  fsvar       :  Fyrra svar (ef til er)
  strik       :  Strikal�na sem a�skilur haus og spurningu

}

BLOCK BLei�r�tta "Lei�r�tta s�ma og heimilisf�ng"

 FIELDS
   S�mi  "^haus@/^fsvar@/^strik@/
          Anna� s�man�mer?"
         /"A�als�mi"
         : STRING[12],EMPTY
   AS�mar"^haus@/^fsvar@/^strik@/
          �nnur s�man�mer "
         /"A�rir s�mar"
         : STRING[150],EMPTY
   Aths1 "^haus@/^fsvar@/^strik@/
          Athugasemd"
         /"Athugasemd"
         : STRING[250]
   Sta�setning
         "^haus@/^fsvar@/^strik@/
          Heimilisfang"
         /"Heimilisfang"
         : STRING[50],EMPTY
   AnnarVi�m�landi
         "^haus@/^fsvar@/^strik@/
          Hvert er nafn �ess sem � a� tala vi� n�st �egar hringt er til a� f� sv�r vi� seinni hlutanum?"
         /"Annar vi�m�landi"
         : STRING[50],EMPTY

    AUXFIELDS
      nS�mi, nS�mar : String

RULES
    S�mi
    AS�mar
    prc_Trimma(S�mi, nS�mi)
    prc_B�taVi�A�raS�ma (S�mi, aS�mar, nS�mar)
    IF nS�mar <> AS�mar And (Len(nS�mi)> 7 Or (Len(nS�mi) = 7 And Position(Substring(nS�mi,1,1),'4568')>0)) THEN
      AS�mar := nS�mar
    ENDIF
    Aths1
    AnnarVi�m�landi
    Sta�setning
    IF (Len(nS�mi)>0 And Len(nS�mi)< 7) Or (Len(nS�mi)=7 AND Position(Substring(nS�mi,1,1),'45678')=0) INVOLVING (S�mi) THEN
        Len(nS�mi)> 7 Or (Len(nS�mi) = 7 And Position(Substring(nS�mi,1,1),'45678')>0) "�gilt s�man�mer!"
    ENDIF
LAYOUT
  At AS�mar
    FIELDPANE tvofoldLongLina
ENDBLOCK

