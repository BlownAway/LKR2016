{bForskráning.inc
 ÓH (c) mars 2003 v. 2. útg. VMR-eyðublaðs}


EMBEDDED BLOCK BForskráning "Athuga forskráningu á heimili"
  PARAMETERS
    IMPORT Persóna         : TPersóna
           fjöldiHeimili   : INTEGER     {fjöldi heimilismanna}
           Fjöldi          : INTEGER     {fjöldi annarra heimilismanna}
    EXPORT FjöldiÚtstrikaðraHeimilismanna        : tHmFj       {skila fjölda útstrikaðra heimilismanna}

  FIELDS
    HmMed (Hm03)
      "^haus@/^fsvar@/^strik@/
       Þá eru nokkrar spurningar um ^hina_heimilismennina og hvernig ^þeir ^tengjast ^þér^Ef_við_byrjum_á_þeim_fyrsta"
      "^haus@/^fsvar@/^strik@/
       Then there are few questions on other ^members of the household and how ^they ^are connected to ^you^Beginning_with_first"
      /"Formáli"
      : STRING[1], EMPTY
    HmSkrá (Hm04)
      "^haus@/^fsvar@/^strik@/
       Er einhver af eftirfarandi ekki á heimilinu ?
       @/@/@RSPYRILL!!! Merktu bara við þá sem búa EKKI á heimilinu - Engin breyting = ENTER@R"
      "^haus@/^fsvar@/^strik@/
       Then, a few questions about who lives in the household and how they are connected to ^you@/
       Have any of the following left home? @/@/@G
       /@RSPYRILL!!! Merktu bara við þá sem búa EKKI á heimilinu - Engin breyting = ENTER@R"
      /"Listi yfir heimilismenn"
       : SET OF
        (ENGINN  "BÝR EKKI MEÐ NEINUM ÞESSARA!",
         heim02  "^heimNafn[2]",
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

        HmHvorFlutti "^haus@/^fsvar@/^strik@/
                        @G^brottfluttnafn býr ekki lengur með svaranda@G
                        @/@/Fluttir þú af heimilinu, flutti ^brottfluttnafn eða hafið þið aldrei búið á sama heimilinu?"
                        "^haus@/^fsvar@/^strik@/
                        @G^brottfluttnafn býr ekki lengur með svaranda@G
                        @/@/Did you move away from the home, did ^nafn_brottflutts move or has ^brottfluttnafn never lived with you?"
                        / "Hver flutti" : array[2..15] of
        ( svarandi      "Svarandi flutti",
          hinn          "Hann/hún flutti",
          aldrei        "Hafa aldrei búið á sama heimili",
          latinn        "Hann/hún lést"
         )


        HmHvertFluttur "^haus@/^fsvar@/^strik@/
                        @G^brottfluttnafn býr ekki lengur með svaranda@G
                        @/@/^hm_txt_1"
                        "^haus@/^fsvar@/^strik@/
                        @G^brottfluttnafn býr ekki lengur með svaranda@G
                        @/@/Did ^nafn_brottflutts years old, move abroad, to another household within the country, to an institution or somewhere else?"
                        / "Hvert fluttur" : array[2..15] of
        ( til_útlanda "Til útlanda" "Abroad",
          annað_innan "Á (annað) heimili innanlands" "To another household within the country",
          stofnun     "Á stofnun eða sambýli" "To an institution",
          annað       "Annað" "Somewhere else"
         )

        HmHvertAnnað  "^haus@/^fsvar@/^strik@/
                        @G^brottfluttnafn býr ekki lengur með svaranda@G
                        @/@/Annað, hvert?"
                        "^haus@/^fsvar@/^strik@/
                        @G^brottfluttnafn býr ekki lengur með svaranda@G
                        @/@/Where?"
                        / "Annað hvert" : array[2..15] of string[80]

        HmBrottMán        "^haus@/^fsvar@/^strik@/
                        @G^brottfluttnafn býr ekki lengur með svaranda@G
                            @/@/Í hvaða mánuði flutti ^hm_txt_2
                            @/@GEkki lesa upp valkosti@G"
                           "^haus@/^fsvar@/^strik@/
                        @G^brottfluttnafn býr ekki lengur með svaranda@G
                            @/@/Which month did ^nafn_brottflutts years old, move out of the household?
                            @/@GEkki lesa upp valkosti@G"
                            / "Í hvaða mánuði"
                            : array[2..15] of TMánuðir

        HmBrottMánGisk     "^haus@/^fsvar@/^strik@/
                        @G^brottfluttnafn býr ekki lengur með svaranda@G
                            @/@/En ef þú ættir að segja þína bestu ágiskun. Í hvaða mánuði heldur þú að ^hm_txt_3
                            @/@REkki lesa upp valkosti@R"
                           "^haus@/^fsvar@/^strik@/
                        @G^brottfluttnafn býr ekki lengur með svaranda@G
                            @/@/But if you had to give your best guess. Which month do you think ^nafn_brottflutts years old, moved?
                            @/@REkki lesa upp valkosti@R"
                            / "Í hvaða mánuði, ágiskun"
                            : array[2..15] of TMánuðir

       HmBrottÁr            "^haus@/^fsvar@/^strik@/
                        @G^brottfluttnafn býr ekki lengur með svaranda@G
                            @/@/Hvaða ár ^hm_txt_2"
                            "^haus@/^fsvar@/^strik@/
                        @G^brottfluttnafn býr ekki lengur með svaranda@G
                            @/@/Which year?"
                             / "Hvaða ár flutt"
                             : array[2..15] of TÁrtal50

       HmBrottStarf          "^haus@/^fsvar@/^strik@/
                        @G^brottfluttnafn býr ekki lengur með svaranda@G
                            @/@/Var ^nafn_brottflutts ára, í vinnu, atvinnulaus, á eftirlaunum, í námi eða eitthvað annað?"
                             "^haus@/^fsvar@/^strik@/
                        @G^brottfluttnafn býr ekki lengur með svaranda@G
                            @/@/Was ^nafn_brottflutts years old, working, unemployed, in retirement, studying or something else?
                              "
                              / "Starf brottflutts"
                              : array[2..15] of
                              (
                                 í_vinnu      "Í vinnu" "Working",
                                 atvinnulaus  "Atvinnulaus" "Unemployed",
                                 eftirlaun    "Á eftirlaunum" "In retirement",
                                 í_námi       "Í námi" "Studying",
                                 annað        "Annað" "Something else"
                              )

       HmBrottStarfAnnað     "^haus@/^fsvar@/^strik@/
                        @G^brottfluttnafn býr ekki lengur með svaranda@G
                            @/@/Annað, hvað ?"
                             "^haus@/^fsvar@/^strik@/
                        @G^brottfluttnafn býr ekki lengur með svaranda@G
                            @/@/Something else, specify"
                              / "Annað starf brottflutts"
                              : array[2..15] of string[80]


  AUXFIELDS
    heimNafn         : ARRAY [2..15] OF STRING[50]
    heimNafn_2       : ARRAY [2..15] OF STRING[50]
    þFj              : THmFj
    Inngangur        : STRING
    Preamble         : STRING
    þér, you         : string
    nafn_brottflutts : string
    hm_txt_1         : string
    hm_txt_2         : string
    hm_txt_3         : string
    brottfluttnafn   : string

  LOCALS
    fj           : INTEGER             {Fjöldi þerirra sem er merkt við 'býr ekki með þessum' }
    chck         : INTEGER
    I            : INTEGER
    FJ1, FJ2     : STRING
    hina_heimilismennina, þeir, tengjast, members, they, are : string
    Ef_við_byrjum_á_þeim_fyrsta, Beginning_with_first : string
    FæðÁr, aldur, öld : integer


  RULES
    
    IF NOT (Persóna IN [karl, kona]) THEN
      þér := fornafn
      you := fornafn
    ELSE
      þér := 'þér'
      you := 'you'
    ENDIF
    
    þFj := Fjöldi + 1
    fsvar := ''
    IF Fjöldi = 0 THEN
        IF FjöldiHeimili = 2 THEN
          hina_heimilismennina := 'hinn heimilismanninn'
          þeir := 'hann'
          members := 'member'
          they := 'he'
          are := 'is'
          tengjast := 'tengist'
          Ef_við_byrjum_á_þeim_fyrsta := '...'
          Beginning_with_first := '...'
        ELSE
          hina_heimilismennina := 'hina heimilismennina'
          þeir := 'þeir'
          members := 'members'
          they := 'they'
          are  := 'are'
          tengjast := 'tengjast'
          Ef_við_byrjum_á_þeim_fyrsta := '@/Ef við byrjum á þeim fyrsta...'
          Beginning_with_first := '@/Beginning with first...'
        ENDIF
      {IF hmfjöldi >1
      THEN HmMed endif}
      HmFjöldi := FjöldiHeimili
    ELSE
      IF FjöldiHeimili = 2 THEN
        hina_heimilismennina := 'hinn heimilismanninn'
        þeir := 'hann'
        members := 'member'
        they := 'he'
        are := 'is'
        tengjast := 'tengist'
        Ef_við_byrjum_á_þeim_fyrsta := '...'
        Beginning_with_first := '...'
      ELSE
        hina_heimilismennina := 'hina heimilismennina'
        þeir := 'þeir'
        members := 'members'
        they := 'they'
        are  := 'are'
        tengjast := 'tengjast'
        Ef_við_byrjum_á_þeim_fyrsta := '@/Ef við byrjum á þeim fyrsta...'
        Beginning_with_first := '@/Beginning with first...'
      ENDIF
      {IF hmfjöldi >1
      THEN HmMed endif}
      FOR I := 2 TO 15 DO
        heimNafn[I] := Fjölskylda.Heimilismaður[I].Nafn
        IF HeimNafn[I] > '' THEN
          heimNafn[I] := heimNafn[I] + ', ' + Str(Fjölskylda.Heimilismaður[I].Aldur)
        ENDIF
      ENDDO
      FOR I := 2 TO 15 DO
        heimNafn_2[I] := Fjölskylda.Heimilismaður[I].Nafn
        IF HeimNafn_2[I] > '' THEN
          heimNafn_2[I] := Fjölskylda.Heimilismaður[I].Nafn
        ENDIF
      ENDDO
      if (HmFjöldi = 1) then
        HmSkrá := [ENGINN]
      else
        HmSkrá
        check if Enginn in HmSkrá then HmSkrá.cardinal = 1 "Ef þú velur 'ENGINN' þá má ekki merkja við aðra kosti" endif
      endif
      IF ENGINN IN HmSkrá THEN
        if Fjöldi = 1 then
          HmSkrá := [heim02]
        elseif Fjöldi = 2 then
          HmSkrá := [heim02,heim03]
        elseif Fjöldi = 3 then
          HmSkrá := [heim02,heim03,heim04]
        elseif Fjöldi = 4 then
          HmSkrá := [heim02,heim03,heim04,heim05]
        elseif Fjöldi = 5 then
          HmSkrá := [heim02,heim03,heim04,heim05,heim06]
        elseif Fjöldi = 6 then
          HmSkrá := [heim02,heim03,heim04,heim05,heim06,heim07]
        elseif Fjöldi = 7 then
          HmSkrá := [heim02,heim03,heim04,heim05,heim06,heim07,heim08]
        elseif Fjöldi = 8 then
          HmSkrá := [heim02,heim03,heim04,heim05,heim06,heim07,heim08,heim09]
        elseif Fjöldi = 9 then
          HmSkrá := [heim02,heim03,heim04,heim05,heim06,heim07,heim08,heim09,heim10]
        elseif Fjöldi = 10 then
          HmSkrá := [heim02,heim03,heim04,heim05,heim06,heim07,heim08,heim09,heim10,heim11]
        elseif Fjöldi = 11 then
          HmSkrá := [heim02,heim03,heim04,heim05,heim06,heim07,heim08,heim09,heim10,heim11,heim12]
        elseif Fjöldi = 12 then
          HmSkrá := [heim02,heim03,heim04,heim05,heim06,heim07,heim08,heim09,heim10,heim11,heim12,heim13]
        elseif Fjöldi = 13 then
          HmSkrá := [heim02,heim03,heim04,heim05,heim06,heim07,heim08,heim09,heim10,heim11,heim12,heim13,heim14]
        else {hér ættu menn ekki að lenda, sett til vara}
          HmSkrá := [ENGINN]
        endif

        Fj := Fjöldi
      ELSE
        Fj := HmSkrá.CARDINAL
      ENDIF
      FOR chck := 1 TO 14 DO
       IF HmSkrá[chck].ord > Fjöldi + 1 {OR HmSkrá[chck].ord = 1} THEN
         HmSkrá[chck].ord > 1 AND HmSkrá[chck].ord <= Fjöldi + 1 "Það má bara velja þá sem eru forskráðir!"
       ENDIF
      ENDDO
      for chck := 2 to 15 do
        if (chck in HmSkrá) or ((HmFjöldi = 1) and (heimNafn[chck] > '')) or ((ENGINN in HmSkrá) and (heimNafn[chck] > '')) then
          newpage
          nafn_brottflutts := heimNafn[chck]
          brottfluttnafn := heimNafn_2[chck]
          HmHvorFlutti [chck]
         IF HmHvorFlutti [chck]= svarandi
                then hm_txt_1 := 'Býr hann/hún í útlöndum, á heimili innanlands, á stofnun eða einhverjum öðrum stað?'
                     hm_txt_2 := 'fluttir þú af heimilinu?'
                     hm_txt_3 := 'þú hafir flutt?'
         endif
         if HmHvorFlutti [chck]= hinn then
                     hm_txt_1 := 'Flutti hann/hún, til útlanda, á annað heimili innanlands, á stofnun eða eitthvert annað?'
                     hm_txt_2 := 'flutti hann/hún, af heimilinu?'
                     hm_txt_3 := 'hann/hún, hafi flutt?'
         ENDIF

         IF (HmHvorFlutti [chck] <> aldrei) AND (HmHvorFlutti [chck] <> latinn) then
            HmHvertFluttur[chck]
             if HmHvertFluttur[chck] = Annað then HmHvertAnnað[chck] endif
             HmBrottÁr[chck]
             check
             if (HmBrottÁr[chck] = response) then HmBrottÁr[chck] <= year(VidtalByrjarDags) "ár getur ekki verið fram í tímann" endif
             if (Fjölskylda.Heimilismaður[chck].FæðÁr = response) then
               Fjölskylda.Heimilismaður[chck].Aldur := max(year(viðmiðunardagur_aldurs) - Fjölskylda.Heimilismaður[chck].FæðÁr, 0)
             elseif (Fjölskylda.Heimilismaður[chck].kennitala = response) then
               öld := val(substring(Fjölskylda.Heimilismaður[chck].kennitala,10,1))
               FæðÁr := val(substring(Fjölskylda.Heimilismaður[chck].kennitala,5,2))
               if öld = 8 then
                 FæðÁr := 1800 + FæðÁr
               elseif öld = 9 then
                 FæðÁr := 1900 + FæðÁr
               elseif öld = 0 then
                 FæðÁr := 2000 + FæðÁr
               endif
               Fjölskylda.Heimilismaður[chck].FæðÁr := FæðÁr
               Fjölskylda.Heimilismaður[chck].Aldur := max(year(viðmiðunardagur_aldurs) - FæðÁr, 0)
             endif
             IF HmBrottÁr[chck] > 2004 then
                HmBrottMán[chck]
                    if HmBrottMán[chck] = dk then HmBrottMánGisk[chck] endif
             ENDIF
             if ((Fjölskylda.Heimilismaður[chck].Aldur >= 16) and (Fjölskylda.Heimilismaður[chck].Aldur <= 70)) then
               HmBrottStarf[chck]
             endif
             if HmBrottStarf[chck] = annað then HmBrottStarfAnnað[chck] endif
         ENDIF
        endif
      enddo
      {Ef upplýsingar um fjölda heimilismanna skv. fyrri spurningu og forskráningu stangast á}
      SIGNAL
      IF Fjöldi - Fj >= FjöldiHeimili - 1 INVOLVING (HmFj.HeimFj, HmSkrá) "Hér gæti verið innsláttarvilla@/" THEN
        fj1 := Str(FjöldiHeimili)
        fj2 := Str(Fjöldi - Fj + 1)
        Fjöldi - Fj < FjöldiHeimili "Skv. þessu eru ^fj2 á heimili en skv. fyrri spurningu voru það ^fj1"
      ENDIF

      FjöldiÚtstrikaðraHeimilismanna := Fj
      {HmFjöldi = fjöldi forskráðra + fjöldi annarra heimilismanna}
{      IF Fjöldi - Fj >= FjöldiHeimili - 1 THEN
         HmFjöldi := Fjöldi + 1
      ELSE
         HmFjöldi := FjöldiHeimili - Fj
      ENDIF }
    ENDIF
  { LAYOUT
       AT HmSkrá INFOPANE adalskjartveirdalkar }

ENDBLOCK
