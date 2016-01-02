{   BFjölskylda.inc SILC

    Eftirfarandi breytur þurfa að vera til staðar:
    haus      : Auðkenni könnunar
                Auðkenni þátttakanda
    fsvar     : Viðeigandi fyrra svar
    strik     : Strik sem aðskilur haus og spurningu
}

TABLE BFjölskylda
  PARAMETERS
    IMPORT viðmiðunardagur  : DateType
    IMPORT Persóna          : TPersóna
    IMPORT aldur            : INTEGER
    IMPORT Hjústétt         : THju
    IMPORT Fjöldi, Hmfjöldi : THmFj
    EXPORT FjöldiVinnufærra : THmFj
    EXPORT Hjusvar_1        : Integer

  INCLUDE "IncludeFiles\BHeimilismaður.inc"
  FIELDS
      Heimilismaður : ARRAY [1..15] OF BHeimilismaður
      Heimilismaður2 : ARRAY [1..15] OF BHeimilismaður
      ErMaki : array[1..15] of 1..15,empty

      Að_Heiman (Hm16)
      "^haus@/^fsvar@/^strik@/
      Er einhver heimilismanna tímabundið að heimann? Þá er átt við lengri dvöl utan heimilis.
      @/@/@GSkyldu eftir auðann reit ef engin heimilismanna er tímabundið að heiman@G"
      "^haus@/^fsvar@/^strik@/
      Are any of the residents in your household temporary away from home ?
      @/@/@GSkyldu eftir auðann reit ef engin heimilismanna er tímabundið að heiman@G"
      /"Tímabundið að heiman"
      :   SET [14] OF
        (heim02 (2) "^heimNafn[2]",
         heim03  "^heimNafn[3]",
         heim04  "^heimNafn[4]",
         heim05  "^heimNafn[5]",
         heim06  "^heimNafn[6]",
         heim07  "^heimNafn[7]",
         heim08  "^heimNafn[8]",
         heim09  "^heimNafn[9]",
         heim10  "^heimNafn[10]",
         heim11  "^heimNafn[11]",
         heim12  "^heimNafn[12]",
         heim13  "^heimNafn[13]",
         heim14  "^heimNafn[14]",
         heim15  "^heimNafn[15]"),EMPTY

  HjúSvar (Hm17)
      "^haus@/^fsvar@/^strik@/
      Hver er hjúskaparstaða ^þín?"
      "^haus@/^fsvar@/^strik@/
      What is ^your marital status ?"
      /"HjúskaparstaðaSvaranda"
      : THjúsvar  {THjuSpurt AOK_151107}

      HverSvararHeimilismaður
      "^haus@/^fsvar@/^strik@/
      Kæri spyrill, nú þarft þú að merkja hver er viðmælandinn ^Þ.HverSvarar"
      / "Merkja við hver annar svarar"
      :
        (heim02 (2) "^heimNafn[2]",
         heim03  "^heimNafn[3]",
         heim04  "^heimNafn[4]",
         heim05  "^heimNafn[5]",
         heim06  "^heimNafn[6]",
         heim07  "^heimNafn[7]",
         heim08  "^heimNafn[8]",
         heim09  "^heimNafn[9]",
         heim10  "^heimNafn[10]",
         heim11  "^heimNafn[11]",
         heim12  "^heimNafn[12]",
         heim13  "^heimNafn[13]",
         heim14  "^heimNafn[14]",
         heim15  "^heimNafn[15]"),EMPTY

  AUXFIELDS
    Nýr         : TJáNei
    Farinn      : TJáNei
    M           : THmFj
    Vinnufær    : TJáNei
    heimNafn         : ARRAY [2..15] OF STRING[50]
    hjústéttin  : THju
    þín,your    : string[11]
    avarp_heimilismenn       "^haus@/^fsvar@/^strik@/
                              Nú ætla ég að fá hjá þér upplýsingar um þá sem búa á heimilinu.
                              Ef við byrjum á þeim elsta og endum á þeim yngsta.
                              @/@/@GÝttu á einhvern lykil til að byrja@G"
                             "^haus@/^fsvar@/^strik@/
                              Next I will ask you series of questions about other people living in the household.
                              If we could start with the oldest and end with the youngest.
                              @/@/@GÝttu á einhvern lykil til að byrja@G"
                              : string, EMPTY

  LOCALS
      I : INTEGER
      A : INTEGER
      fjöldi_í_sambúð : integer
      er_til_maki : integer
  RULES
    prc_ÞínHansHennar(persóna,þín)
    prc_YourHisHer   (persóna,your)
  NEWPAGE
    M := HmFjöldi
    farinn := nei
    nýr := nei
    Heimilismaður[1].KEEP (viðmiðunardagur, persóna, aldur, nýr, farinn, hjústétt, Vinnufær, 1,1,Heimilismaður[1].kyn, hjusvar_1, heimilismaður[1].óskráður)
    Heimilismaður[1].KEEP (viðmiðunardagur, persóna, aldur, nýr, farinn, hjústétt, Vinnufær, 1,2,Heimilismaður[1].kyn, hjusvar_1, heimilismaður[1].óskráður)
    IF aldur >= 16
    THEN HjúSvar
    ENDIF
    IF Hjúsvar = sambud
        then hjusvar_1 := 1  endif
    IF hjúsvar <> sambud then hjusvar_1 := 0
        endif
    avarp_heimilismenn
    FOR I := 2 TO M DO
      Farinn := já     {20070222}
      IF (I In Forskráning.HmSkrá OR 1 IN Forskráning.HmSkrá) {AND I <= Fjöldi + 1 } THEN {20070222}
        Farinn := Já
      ELSE
        Farinn := Nei
      ENDIF
      hjústéttin := hjústétt
      IF I <= Fjöldi + 1 THEN
        Nýr := Nei
      ELSE
        Nýr := Já
        hjústéttin := empty
      ENDIF
      Heimilismaður[I] (viðmiðunardagur, persóna, aldur, nýr, farinn, hjústéttin, Vinnufær, 1,1,Heimilismaður[I].kyn, hjusvar_1, heimilismaður[I].óskráður) {fyrsta umferð}
      IF vinnufær = Já THEN
        FjöldiVinnufærra := FjöldiVinnufærra + 1
      ENDIF
      IF (Heimilismaður[I].Brottfluttur = Já) THEN
        heimNafn[I] := ''
      ELSE
        heimNafn[I] := Heimilismaður[I].Nafn
        IF HeimNafn[I] > '' THEN
          heimNafn[I] := heimNafn[I] + ', ' + Str(Heimilismaður[I].Aldur)
        ENDIF
      ENDIF
      if Heimilismaður[I].HjúSvar = Sambud then
        fjöldi_í_sambúð := fjöldi_í_sambúð + 1
      endif
      if Heimilismaður[I].Tengsl = maki then
        er_til_maki := 1
      endif
    ENDDO

    check
    if Heimilismaður[M].HjúSvar = response then
      ((fjöldi_í_sambúð + er_til_maki) / 2.0) = round( (fjöldi_í_sambúð + er_til_maki) / 2.0)
        "Stemmir ekki fjöldi í sambúð"
    endif
    FOR A := 2 TO M DO
      if Heimilismaður[A].brottfluttur = nei then nýr :=já else nýr := nei endif
      Heimilismaður2[A] (viðmiðunardagur, persóna, aldur, nýr, farinn, hjústéttin, Vinnufær, A,2,Heimilismaður[A].kyn, hjusvar_1, heimilismaður[A].óskráður) {önnur umferð}
    ENDDO

ENDTABLE
