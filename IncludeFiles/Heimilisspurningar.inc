{SILC 2003}
BLOCK BHeimilisspurningar


PARAMETERS
IMPORT Fjöldi, FjöldiHeimilismanna, hmFjöldi : THmFj
Import AllirAdrirBorn : TJáNei
import er_til_barn_á_grunnskólaaldri : TJáNei
import er_til_barn_1_15_ara : TJáNei


AuxFields
Kynning1                 "^haus@/^fsvar@/^strik@/
                       Næstu spurningar eru um húsnæði og rekstur heimilisins"
                        "^haus@/^fsvar@/^strik@/
                        The next questions are about housing and household costs" / "Kynning":STRING [1],empty

Kynning2                 "^haus@/^fsvar@/^strik@/
                        Nú er komið að nokkrum spurningum um skuldir og afborganir"
                        "^haus@/^fsvar@/^strik@/
                        Now a few question about debts and debt payments" / "Kynning":STRING [1],empty

Kynning3                 "^haus@/^fsvar@/^strik@/
                        Næst eru fáeinar spurningar um neysluvenjur"
                        "^haus@/^fsvar@/^strik@/
                        Next a few questions about consumption habits" / "Kynning":STRING [1],empty

Kynning4                 "^haus@/^fsvar@/^strik@/
                        Nú koma nokkrar spurningar um fjárhagsgreiðslur og/eða -stuðning"
                        "^haus@/^fsvar@/^strik@/
                        Now a few questions about financial payments and / or support" / "Kynning":STRING [1],empty


HeimNafn                : ARRAY [1..15] OF STRING[50]

M : THmFj

ErBarnMedlag : TJáNei


Locals
   I : integer
   eigandi_leigjandi_lán : string[60]
   do_you : string

FIELDS
    HeimiliByrjarDags : Datetype
    HeimiliByrjarTimi : Timetype   {Breytur til að vista upphaf í þessari blokk  }
    HeimiliLokidDags : Datetype
    HeimiliLokidTimi : Timetype   {Breytur til að vista lok í þessari blokk  }
    endir_yttu "^haus@/^fsvar@/^strik@/
                        @gSpyrill! Veldu áfram til að halda áfram.@g": (afram "Áfram"), noempty, nodk, norefusal


    Heimilisíðast (HK0)    {ef já hérna þá hoppað í HK4a til HK4f of síðan í HK6d og áfram}
   "^haus@/^fsvar@/^strik@/
     @GTegund húsnæðis   @|: ^fsv_HTegund @/
     Staðsetning @|: ^fsv_Hstaðsetning @/@/@G
     ^buidA enn í sama húsnæði og í mars í fyrra ? @/@/@Gþað er í @G@R < ^fsv_HTegund ·· ^fsv_Hstaðsetning>@R @/"
    "^haus@/^fsvar@/^strik@/
     @GHouse       @|: ^fsv_HTegund @/
     Address        @|: ^fsv_HStaðsetning @/@/@/@G
     Do you still live at the same adress as you did in March last year ?@/@/@GThat is @G@R < ^fsv_HTegund ·· ^fsv_Hstaðsetning>@R"
     /"Sama og síðast"
     : TFsv_húsnæði_sama


HK1a (H1411)        "^haus@/^fsvar@/^strik@/
                        Í hvernig húsnæði ^buid?"
                        "^haus@/^fsvar@/^strik@/
                        In what type of housing do you live?" / "Tegund Húsnæðis":
                        (Einbýli  "Einbýlishúsi" "Detached house / Single dwelling / single family house (Einbýlishús)",
                        Raðhús  "Raðhúsi eða parhúsi" "Semi detached (Raðhús / parhús)",
                        Tveggja_til_fimm    "2-5 íbúða húsi" "House with 2-5 flats",
                        Fjölbýli    "Fjölbýlishúsi" "House with 6 flats or more (Fjölbýlishús)",
                        Annað   "Annars konar" "Other type of housing")


Einbýli (1)             "^haus@/^fsvar@/^strik@/
                        Býrð þú í..."
                        "^haus@/^fsvar@/^strik@/
                        Do you live in..." / "Hvernig einbýli":
                        (EinbýliA "...aðalíbúð?" "...the main appartment?",
                        EinbýliB  "...aukaíbúð, til dæmis kjallaraíbúð eða risi?" "...an extra flat, for example in the basement or the attic?",
                        EinbýliC  "...eða herbergi eða hluta af óskiptri íbúð?" "...or in a room or part of an undivided flat?")


Raðhús (2)             "^haus@/^fsvar@/^strik@/
                        Býrð þú í..."
                        "^haus@/^fsvar@/^strik@/
                        Do you live in... " / "Hvernig Rað/parhús":
                        (RaðhúsA   "...aðalíbúð?" "...the main flat?",
                        RaðhúsB  "...aukaíbúð, til dæmis kjallaraíbúð eða risi?" "...an extra flat, for example in the basement or the attic?",
                        RaðhúsC "...eða herbergi eða hluta af óskiptri íbúð?" "...or in a room or part of an undivided flat?")

Tveggja_til_fimm (3)    "^haus@/^fsvar@/^strik@/
                        Býrð þú í...?"
                        "^haus@/^fsvar@/^strik@/
                        Do you live in... "
                         / "Hvernig íbúð":
                        (Tveggja_til_fimmA    "...íbúð?" "...a flat?",
                        Tveggja_til_fimmB   "...eða herbergi eða hluta af óskiptri íbúð?"
                                            "...or in a room or part of an undivided flat?")

Fjölbýli (4)            "^haus@/^fsvar@/^strik@/
                        Býrð þú í..."
                        "^haus@/^fsvar@/^strik@/
                        Do you live in..." / "Hvernig fjölbýli":
                        (FjölbýliA    "...íbúð?" "...a flat?",
                        FjölbýliB   "...eða herbergi eða hluta af óskiptri íbúð?" "...or in a room or part of an undivided flat?")


HK1aa (H14111)      "^haus@/^fsvar@/^strik@/
                        Hvers konar húsnæði er það?"
                        "^haus@/^fsvar@/^strik@/
                        What type of housing is it?"  / "Önnur tegund húsn": STRING [50]

HK1b(H14112)        "^haus@/^fsvar@/^strik@/
                        Eru íbúðir í húsinu 10 eða fleiri?"
                        "^haus@/^fsvar@/^strik@/
                        Are there 10 or more flats in the house?"  /
                        "Fleiri íbúðir": (færri "Færri en 10" "Fewer than 10", Fleiri "10 eða fleiri íbúðir" "10 or more")

HK2                 "^haus@/^fsvar@/^strik@/
                     Fylgir bílskúr með húsnæðinu?"
                     "^haus@/^fsvar@/^strik@/
                     Does a garage come with the dwelling?"
                     / "Fylgir bílskúr"
                     : TJáNei

HK2_bils           "^haus@/^fsvar@/^strik@/
                     Hversu stór er bílskúrinn í fermetrum?"
                     "^haus@/^fsvar@/^strik@/
                     How many square meters is the garage?"
                     / "Bílskúrsstærð"
                     : 4..900

HK2a (H1421)       "^haus@/^fsvar@/^strik@/
                        Hversu stórt er húsnæðið í fermetrum ^með_bílskúr?
                        @/@/@GTelja á með herbergi í kjallara og risi ef þau eru notuð sem
                        vistarverur heimilisins. Ekki skal telja með sameign í fjölbýlishúsi.
                        @G"
                        "^haus@/^fsvar@/^strik@/
                        How many square meters is your house or flat, ^including_the_garage?
                        @/@/@G Also including basement or loft if they are used as part of the living quarters. Do not include common areas.@G"
                         / "Flatarmál húsnæðis":   4..900

HK2b (H1422)        "^haus@/^fsvar@/^strik@/
                        Hve mörg herbergi eru í húsnæðinu, það er, svefnherbergi og stofa?"
                        "^haus@/^fsvar@/^strik@/
                        How many rooms are there in the house / flat?"
                       / "Fjöldi herbergja":1..15

HK2c (H1423)        "^haus@/^fsvar@/^strik@/
                        Fylgir húsnæðinu, bílskúr eða stæði í bílskýli ?"
                        "^haus@/^fsvar@/^strik@/
                        Is there a garage or covered parking space?"  / "Bílskúr eða stæði": (Já (1)"Já, bílskúr" "Yes, garage",
                        JáEn (2) "Já, bílskýli" "Yes, covered parking space",
                        Nei (3) "Nei" "No")


HK3a (H1431)        "^haus@/^fsvar@/^strik@/
                        Fylgir húsnæðinu salerni sem aðeins ^Þú_þið_hafir aðgang að?"
                        "^haus@/^fsvar@/^strik@/
                        Is there a toilet which only you have access to?"/ "Sér salerni":
                        (
                        seradgangur "Já, aðeins við höfum aðgang" "Yes, private access",
                        deilum      "Nei, deilum með öðrum" "No, shared"
                        )

HK3d  (H1434)       "^haus@/^fsvar@/^strik@/
                        ^hafa_hei aðgang að baðkeri eða sturtu í húsnæðinu?"
                        "^haus@/^fsvar@/^strik@/
                        Is there a bathtub or shower in the house / flat?"/ "Bað eða sturta": Tjánei

HK3dd  (H1434d)       "^haus@/^fsvar@/^strik@/
                        Er það aðeins fyrir þitt heimili eða er því deilt með öðrum heimilum?"
                        "^haus@/^fsvar@/^strik@/
                        Is it only used by your household or is it shared with other households?"/ "Einkabað":
                        (
                         mitt "Aðeins fyrir mitt heimili"   "Only used by my household",
                         deilt "Deilt með öðrum heimilum"   "Shared with other households"
                         )


HK4aa (H1435)       "^haus@/^fsvar@/^strik@/
                       Átt þú í @uvandræðum@u með þakleka, raka eða fúa í veggjum, gólfi eða gluggum?"
                        "^haus@/^fsvar@/^strik@/
                        ^do_you have any of the following problems in your dwelling: Leaking roof, damp walls, floors
                        or foundations, or rot in window frames or floor"/"Raki fúi eða leki": TJáNei

HK4ac (H14351)       "^haus@/^fsvar@/^strik@/
                       ^hafa_hei efni á að halda húsnæði þínu nægilega heitu?"
                        "^haus@/^fsvar@/^strik@/
                        Can your household afford to keep its home adequately warm?"/"Hiti": TJáNei

{HK4b (H14351)       "^haus@/^fsvar@/^strik@/
                        Hvernig er dagsbirtan í húsnæðinu á björtum degi. Er hún góð, viðunandi eða of lítil?"
                        "^haus@/^fsvar@/^strik@/
                        Hows is the daylight in the house on a bright day. Is it sufficient, acceptable, or too little?"/"Dagsbirta":
                        (Góð "Góð" "Sufficient",
                        Viðunandi"Viðunandi" "Acceptable",
                        lítil "Of lítil" "Too little") }

HK4b_08            "^haus@/^fsvar@/^strik@/
                        Kemur næg dagsbirta inn um gluggana á húsnæðinu?"
                        "^haus@/^fsvar@/^strik@/
                        Is there enough day-light coming through the windows of the dwelling?"/"Dagsbirta":
                        TjáNei


HK4c (H1437)        "^haus@/^fsvar@/^strik@/
                        Verður þú fyrir óþægindum í húsnæðinu vegna hávaða, til dæmis frá nágrönnum, umferð, skemmtistöðum eða einhverri
                        starfsemi?"
                        "^haus@/^fsvar@/^strik@/
                        Are you troubled in the house by noise, eg. from neighbours, traffic, clubs or some work related activity?"/"Hávaði":TJáNei

HK4c2a (H14381)        "^haus@/^fsvar@/^strik@/
                        En vegna mengunar til dæmis ryks, reyks eða ólyktar frá umferð eða atvinnustarfsemi ?"
                        "^haus@/^fsvar@/^strik@/
                        Are you troubled in the house by pollution, such as dust, smoke or smell from traffic or work related activity?"/"Mengun": TJáNei

HK4c3a (H14391)        "^haus@/^fsvar@/^strik@/
                        En vegna skemmdarverka, ofbeldis eða ólöglegrar starfsemi af einhverju tagi í nágrenninu ?"
                        "^haus@/^fsvar@/^strik@/
                        Are you troubled in the house by vandalism, violence or illegal activities of any kind in the neighbourhood?"/"Ofbeldi": TJáNei

HK5a  (H1441)       "^haus@/^fsvar@/^strik@/
                        Er húsnæðið ^thitt ...?"
                        "^haus@/^fsvar@/^strik@/
                        Is your housing your own, rented or rent free?" /"Eigið eða leiga":
                        (Eigið    "Eigið húsnæði" "Own",
                        Leiga     "Leiguhúsnæði, íbúð í búseturétti" "Rented or a co-operative building association",
                        Embætti  "endurgjaldslaust eða frítt húsnæði" "Rent free")

HK5a_leiga          "^haus@/^fsvar@/^strik@/
                     Borgið þið fullt verð fyrir leiguna, er afsláttur veittur eða hún niðurgreidd á einhvern hátt,
                     til dæmis af vinnuveitendum, ættingjum eða opinberum aðilum? Hér er ekki verið að spyrja um húsaleigubætur."
                     "^haus@/^fsvar@/^strik@/
                     Do you pay full price or is there  a discount from the rent or is it subsidized in any way,
                     for instance from public funds, employer or family members?"
                     / "Full verð fyrir leigu"
                     : (
                        Fullt         "Borga fullt verð" "Full price",
                        Niðurgreidd   "Niðurgreidd leiga" "Discount"
                        )

{HK5b                 "^haus@/^fsvar@/^strik@/
                     Var húsnæðið keypt tilbúið eða byggðuð þið það sjálf?"
                     "^haus@/^fsvar@/^strik@/
                      Did you buy the house or apartment or did you build it yourselves?"
                      / "Keypt tilbúið eða byggðuð"
                      : (
                         keypt     "Keypt tilbúið" "Bought it",
                         byggðum   "Byggðum sjálf" "Built it"
                         )
}
HK5ba                "^haus@/^fsvar@/^strik@/
                      Hvaða ár var húsnæðið keypt?
                      @/@/@GEf svarandi segist hafa byggt húsið þá skrá árið sem húsið var byggt@G"
                     "^haus@/^fsvar@/^strik@/
                      What year was the house or apartment bought?
                      @/@/@GEf svarandi segist hafa byggt húsið þá skrá árið sem húsið var byggt@G"
                      / "Hvaða ár keypt eða byggt"
                       : Tártal150

HK5Bb  (H14421)      "^haus@/^fsvar@/^strik@/
                        Hvaða ár ^hk5bb_texti?
                        @/@/@GEf allir heimilismenn hafa ekki búið í húsnæðinu frá ""upphafi"", skal miða við það ár sem sá er lengst hefur búið í húsnæðinu tók það á leigu.@G"
                        "^haus@/^fsvar@/^strik@/
                        What year did you begin renting the house?"/ "Leigu-ár" :TLeiguár {1900..2010  {Fæst úr fasteignamati}}

HK5ca  (H)          "^haus@/^fsvar@/^strik@/
                        Hver eða hverjir eru skráðir eigendur húsnæðisins?"
                        "^haus@/^fsvar@/^strik@/
                        Who is / are the registered owner/s of the house?"
                         /"Skráður eigandi"
                        : SET [15] OF
        (heim01  "^HeimNafn[1]",
         heim02  "^HeimNafn[2]",
         heim03  "^HeimNafn[3]",
         heim04  "^HeimNafn[4]",
         heim05  "^HeimNafn[5]",
         heim06  "^HeimNafn[6]",
         heim07  "^HeimNafn[7]",
         heim08  "^HeimNafn[8]",
         heim09  "^HeimNafn[9]",
         heim10  "^HeimNafn[10]",
         heim11  "^HeimNafn[11]",
         heim12  "^HeimNafn[12]",
         heim13  "^HeimNafn[13]",
         heim14  "^HeimNafn[14]",
         heim15  "^HeimNafn[15]",
         Annar "Annar eigandi")  {fá upp lista með heimilismönnunum}

HK5cX       "^haus@/^fsvar@/^strik@/
                        Hvað heitir sá sem er skráður eigandi að húsnæðinu?"
                        "^haus@/^fsvar@/^strik@/
                        What is the name of the registered owner?" /"Annar eigandi"
                        : STRING [50]

HK5cb  (H)          "^haus@/^fsvar@/^strik@/
                        Hver eða hverjir eru skráðir leigutakar húsnæðisins?
                        @/@/@GEf svarið er 'Veit ekki' spyrðu þá 'En hver heldurðu að sé skráður leigutaki'@G
                        @/@/@GMunið að setja mínusmerki á milli ef þið notið lyklaborðið
                        @/@/Hérna koma allir heimilismenn á skjáinn@G"
                        "^haus@/^fsvar@/^strik@/
                        Who is / are the registered lodger/s of the house?" /"Skráður leigutaki"

                        : SET [15] OF
        (heim01  "^HeimNafn[1]",
         heim02  "^HeimNafn[2]",
         heim03  "^HeimNafn[3]",
         heim04  "^HeimNafn[4]",
         heim05  "^HeimNafn[5]",
         heim06  "^HeimNafn[6]",
         heim07  "^HeimNafn[7]",
         heim08  "^HeimNafn[8]",
         heim09  "^HeimNafn[9]",
         heim10  "^HeimNafn[10]",
         heim11  "^HeimNafn[11]",
         heim12  "^HeimNafn[12]",
         heim13  "^HeimNafn[13]",
         heim14  "^HeimNafn[14]",
         heim15  "^HeimNafn[15]",
         Annar "Annar leigutaki")  {fá upp lista með heimilismönnunum}


HK5cbX  (H145)       "^haus@/^fsvar@/^strik@/
                        Hvað heitir sá sem er skráður leigutaki að húsnæðinu?
                        @/@/@GSmellt var á annan leigutaka í spurningunni hér að framan og þess vegna þurfum við nafnið á honum@R"
                        "^haus@/^fsvar@/^strik@/
                        What is the name of the registered lodger?" /"Annar eigandi"
                        : STRING [50]

HK6a (H145a)         "^haus@/^fsvar@/^strik@/Hvers konar eigandi er að húsnæðinu?"
                     "^haus@/^fsvar@/^strik@/Who ownes the house?"
                     / "Eigandi leiguhúsnæðis":
                        (Ríki     "Ríkisstofnun",
                        Sveitarfélag     "Sveitarfélag",
                        Stúdentar     "Stúdentagarðar",
                        Öryrkjar "Öryrkjabandalagið",
                        Búseti     "Búsetufélag (kaupleiguíbúð)",
                        Búmenn "Búmenn",
                        Skyldmenni     "Skyldmenni/ eða vinafólk",
                        Einkaaðili     "Einkaaðili, óskyldur heimilismönnum",
                        Vinnuveitandi      "Vinnuveitandi þó ekki ríki eða sveitarfélag",
                        Annar    "Annar")

HK6aa  (H145b)       "^haus@/^fsvar@/^strik@/
                        Hvaða eigandi er það?"
                        "^haus@/^fsvar@/^strik@/
                        What type of owner?" /"Annar eigandi":STRING [50]

HK6d  (H1454)       "^haus@/^fsvar@/^strik@/
                        Hversu mikið var greitt í húsaleigu fyrir síðasta mánuð?
                        @/@/@GEf húsaleiga er frí skráið þá 0 í reitinn@G
                        @/@GÁn húsaleigubóta@G"
                        "^haus@/^fsvar@/^strik@/
                        How much was paid in rent for last month?
                        @/@/@GIf rent is free then register 0 here@G
                        @/@GÁn húsaleigubóta@G"/ "Húsaleiga":   0..600000

HK6d1              "^haus@/^fsvar@/^strik@/
                        Er það ... ?"
                   "^haus@/^fsvar@/^strik@/
                        Is it ... ?"
                    / "Bil húsaleigu"
                    : (
                       minna_en_30       "minna en 30 þúsund" "less than 30 thousand",
                       minna_en_50       "minna en 50 þúsund" "less than 50 thousand",
                       minna_en_70       "minna en  70 þúsund" "less than 70 thousand",
                       minna_en_90       "minna en  90 þúsund" "less than 90 thousand",
                       minna_en_110      "minna en 110 þúsund" "less than 110 thousand",
                       minna_en_130      "minna en 130 þúsund" "less than 130 thousand",
                       minna_en_150      "minna en 150 þúsund" "less than 150 thousand",
                       minna_en_170      "minna en 170 þúsund" "less than 170 thousand",
                       minna_en_190      "minna en 190 þúsund" "less than 190 thousand",
                       minna_en_210      "minna en 210 þúsund" "less than 210 thousand",
                       minna_en_230      "minna en 230 þúsund" "less than 230 thousand",
                       minna_en_250      "minna en 250 þúsund" "less than 250 thousand",
                       minna_en_270      "minna en 270 þúsund" "less than 270 thousand",
                       minna_en_290      "minna en 290 þúsund" "less than 290 thousand",
                       meira_en_290      "290 þúsund eða meira" "290 thousand or more"
                       )

HK6f(H1456a)         "^haus@/^fsvar@/^strik@/
                        ^fa_heimi húsaleigubætur ?"
                        "^haus@/^fsvar@/^strik@/
                        Does anyone in the home get government support to pay the rent?" / "Húsaleigubætur":  TJáNei

HK6fa(H1456b)         "^haus@/^fsvar@/^strik@/
                        Hve mikið fenguð þið samtals í húsaleigubætur á mánuði ?"
                        "^haus@/^fsvar@/^strik@/
                        How much per month?" / "Húsaleigubætur":  0..100000

HK7a    (H1457)    "^haus@/^fsvar@/^strik@/
                        Er eitthvað af eftirfarandi innifalið í húsaleigunni?"
                        "^haus@/^fsvar@/^strik@/
                        Is any of the following included in the rent?" /  "Innifalið í húsaleigu":
                        SET [7] OF(HSameign "Hiti í sameign" "Heating in common areas of the house",
                        Híbúð   "Hiti í íbúð" "Heating in flat",
                        RSameign "Rafmagn í sameign" "Electricity in common areas of the house",
                        RÍbúð  "Rafmagn í íbúð" "Electricity in flat",
                        Þrif    "Þrif á sameign" "Cleaning in common areas of the house",
                        Hússjóður "Hússjóður" "House fund",
                        Annað "Annað" "Other",
                        Ekkert "Ekkert af þessu" "None of the above")

HK7b(H1458)     "^haus@/^fsvar@/^strik@/
                    Hve mikið var greitt í hússjóð eða bílskúrssjóð í síðasta mánuði?
                    @O@/@/@GEf ekkert greitt skráið þá 0@G"
                    "^haus@/^fsvar@/^strik@/
                    How much was paid to the house fund or garage fund last month?" / "Hússjóður":   0..100000

HK7c(H1457)    "^haus@/^fsvar@/^strik@/
                    Er eitthvað af eftirfarandi innifalið í hússjóði?"
                    "^haus@/^fsvar@/^strik@/
                    Is any of the following included in the house fund?" / "Innifalið í hússjóði":
                    SET [8] OF(HSameign "Hiti í sameign" "Heating in common areas of the house",
                    Híbúð   "Hiti í íbúð" "Heating in flat",
                    RSameign "Rafmagn í sameign" "Electricity in common areas of the house",
                    RÍbúð  "Rafmagn í íbúð" "Electricity in flat",
                    Þrif    "Þrif á sameign" "Cleaning in common areas of the house",
                    Viðhald "Viðhald" "Maintenance",
                    Trygging "Húseigendatrygging" "Home owner's insurance",
                    Bílskýli "Rekstur bílskúra" "Upkeep of garages",
                    Annað "Annað" "Other",
                    Ekkert "Ekkert af þessu" "None of the above")

Fasteignagjöld (H1461) :   0..500000

Brunatrygging (H1462)  :  0..100000

HK8d (H1464)        "^haus@/^fsvar@/^strik@/
                        Hversu mikið var greitt í framkvæmdasjóð í síðasta mánuði ^fyrir_utan1 ^hussjodur?
                        @/@/@GEf framkvæmdasjóður var inn í hússjóðnum sem var gefinn upp áðan, þá skal skrá 0.@G"
                        "^haus@/^fsvar@/^strik@/
                        In addition to what is paid into house fund, how much was paid into maintainance fund for the last month?
                        @/@/@GEf framkvæmdasjóður var inn í hússjóðnum sem var gefinn upp áðan, þá skal skrá 0.@G"
                        / "Framkvæmdasjóður":  0..150000   {Ekki fyrir einbýli og raðhús}

HK8e(H1465)     "^haus@/^fsvar@/^strik@/
                    Hversu miklu varði heimilið í viðhald og endurbætur á síðustu 12 mánuðum ^fyrir_utan ^hussjodur ^eda ^frkvsjodur ?
                    @O@/@/@GÞetta er fyrir utan hússjóð og framkvæmdasjóð.
                    @/@/Athugið að hér er átt við 12 mánaða tímabil.@G"
                    "^haus@/^fsvar@/^strik@/
                    In addition to what was paid into maintainance fund or house fund, how much money was used in maintainance or improvements of
                    the house during the last 12 months in addition to what was paid from house fund or maintainance fund?
                    @/@/Note this is over a 12 month period.@G" / "Kostnaður viðhalds":  0..10000000

VSK_jn     "^haus@/^fsvar@/^strik@/
                    Fékkst virðisaukaskattur endurgreiddur vegna viðhalds eða endurbóta á húsnæði þínu á síðustu 12 mánuðum?"
                    "^haus@/^fsvar@/^strik@/
                    Did you receive any tax refunds for maintenance or improvements of the house in the last 12 months"
                    /"Endurgreiðsla viðhalds": tjánei


VSK_upph     "^haus@/^fsvar@/^strik@/
                    Hversu há upphæð var það?"
                    "^haus@/^fsvar@/^strik@/
                    How much money did you receive?"
                    / "Upphæð endurgreiðslu viðhalds": 0..10000000


{HK8e_2007(H1465)     "^haus@/^fsvar@/^strik@/
                    En hversu miklu var varið í viðhald og endurbætur á árinu 2006 ^fyrir_utan ^hussjodur ^eda ^frkvsjodur ?
                    @O@/@/@GÞetta er fyrir utan hússjóð og framkvæmdastjóð.
                    @/@/Athugið að hér er átt við 12 mánaða tímabil.
                    @/@/Spyrill! Reyndu að fá svar fá svaranda, til dæmis með því að biðja hann um að giska á upphæðina eða reyna að meta hana.@G"
                    "^haus@/^fsvar@/^strik@/
                    In addition to what was paid into maintainance fund or house fund, how much money was used in maintainance or improvements of
                    the house during the year 2006 in addition to what was paid from house fund or maintainance fund?
                    @/@/Note this is over a 12 month period.@G" / "Kostnaður viðhalds":  0..10000000}



HK9a(H1471 )   "^haus@/^fsvar@/^strik@/
                    Hvernig er húsnæðið hitað upp?
                    @/@/@GHitaveita er þar sem heitu vatni er dælt upp úr jörðinni og notað til hitunar á húsum.
                    Rafmagnshitun er þar sem  kalt vatn er hitað upp með rafmagni til húshitunar.@G"
                    "^haus@/^fsvar@/^strik@/
                    How is the house heated?
                    @/@/@GHitaveita er þar sem heitu vatni er dælt upp úr jörðinni og notað til hitunar á húsum.
                    Rafmagnshitun er þar sem  kalt vatn er hitað upp með rafmagni til húshitunar.@G"
                    / "Upphitun":
                    (Hitaveita     "Hitaveita / Fjarvarmaveita" "Geothermal heating",
                    Rafmagn      "Rafmagnshitun" "Electrically heated",
                    Olía      "Olíukynding" "Oil heating",
                    Annar_hiti    "Annars konar húshitun" "Other type of heating")

{HC050  TEKIÐ ÚT JAN 2013 - HLUTI AF VIÐHENGI 2012 }
{HC050               "^haus@/^fsvar@/^strik@/
                    Er miðstöðvarhitun í húsnæðinu, til dæmis samtengt ofnakerfi?"
                    "^haus@/^fsvar@/^strik@/
                    Do you have central heating, for example a combined radiator system?"
                    / "Húshitun":
                    tjánei

HC050_annad         "^haus@/^fsvar@/^strik@/
                    Hvernig hitakerfi er í húsnæðinu, það er, hvernig er hitanum miðlað um húsið?"
                    "^haus@/^fsvar@/^strik@/
                    What type of heating system is in your house, that is, how is the heat delivered to various parts of the house?"
                    / "Húshitun": string[150] }

HK9aa(H1471 )   "^haus@/^fsvar@/^strik@/
                    Hvernig?"
                    "^haus@/^fsvar@/^strik@/
                    What type?"
                    / "Önnur upphitun": string[120]


{HK9b(H14722)   "^haus@/^fsvar@/^strik@/
                    Hver var fjárhæð síðasta reiknings vegna húshitunar?
                    @/@/@GEf svarandi veit ekki sundurliðaða upphæð rafmagns og hita, þá má skrifa heildarupphæð hita og rafmagns hér og setja 0 við rafmagnsreikning.@G"
                    "^haus@/^fsvar@/^strik@/
                    What was the amount of the last heating bill?
                    @/@/@GEf svarandi veit ekki sundurliðaða upphæð rafmagns og hita, þá má skrifa heildarupphæð hita og rafmagns hér og setja 0 við rafmagnsreikning.@G"
                    / "Kynding":0..200000

HK9b2
                 "^haus@/^fsvar@/^strik@/
                    Hversu langt tímabil náði reikningurinn yfir?"
                    "^haus@/^fsvar@/^strik@/
                    What time period does the bill cover?"
                    / "Tímabil kyndingar" : string[80]}

HK9bjn           "^haus@/^fsvar@/^strik@/
                    ^greitt_heimili fyrir hita?"
                    "^haus@/^fsvar@/^strik@/
                    Does somebody in the household pay heating bills for the household?"
                    / "Hitareikningur" : Tjánei

{HK9c(H1472)    "^haus@/^fsvar@/^strik@/
                    Hver var fjárhæð síðasta rafmagnsreiknings?"
                    "^haus@/^fsvar@/^strik@/
                    What was the amount of the last electrical bill?" / "Rafmagnsreikningur":0..100000

HK9c2           "^haus@/^fsvar@/^strik@/
                    Hversu langt tímabil náði reikningurinn yfir?"
                    "^haus@/^fsvar@/^strik@/
                    What time period does the bill cover?"
                    / "Tímabil rafmagnsreiknings" : string[80]}

HK9cjn           "^haus@/^fsvar@/^strik@/
                    ^greitt_heimili fyrir rafmagn?"
                    "^haus@/^fsvar@/^strik@/
                    Does somebody in the household pay electrical bills for the household?"
                    / "Rafmagnsreikningur" : Tjánei

HK10  (H1467)   "^haus@/^fsvar@/^strik@/
                    ^borgar af húsnæðislánum, það er veðlánum eða öðrum lánum til húsnæðiskaupa?@O
                    @/@/@GVeðlán eru þau lán sem koma fram á veðbókarvottorði.  Lán hjá Íbúðalánasjóði, Byggingarsjóði og öllum
                    lífeyrissjóðum eru alltaf veðlán.  Stærri lán í bönkum eru lang oftast veðlán.  Ekki skiptir máli hvort veðlán
                    sé á eign viðmælanda eða hvort hann hafi fengið lánað veð hjá vinum eða ættingjum.@G"
                    "^haus@/^fsvar@/^strik@/
                    Do you pay for a mortgage because of your house purchase?" / "Húsnæðislán": TJáNei

HK10nei         "^haus@/^fsvar@/^strik@/
                    Er það vegna þess að ^Thuert_heimilider ekki með húsnæðislán eða af öðrum ástæðum?
                    @/@/@GEkki lesa upp svarkostina@G"
                    "^haus@/^fsvar@/^strik@/
                    Is it because you do not have a mortgage for a house purchase or for other reasons?
                    @/@/@GEkki lesa upp svarkostina@G"
                    / "Ekki húsnæðislán":
                    (ekki "Ekki með húsnæðislán" "Does not have a mortgage for a house purchase",
                     frysting "Lánið hefur verið fryst" "The mortgage has been frozen",
                     neita "Viðkomandi hefur neitað að borga lánið" "The respondent has refused to pay the loan",
                     annad "Aðrar ástæður" "Other reasons"
                    )

HK10neiannad  "^haus@/^fsvar@/^strik@/
                    Hverjar eru ástæðurnar?"
                    "^haus@/^fsvar@/^strik@/
                    What are the reasons?" / "Aðrar ástæður":STRING[200]

Vaxtabætur (H1466):0..500000

Vaxtagreiðslur(H1468):0..1000000

HK11(H1482)     "^haus@/^fsvar@/^strik@/
                    Er kostnaður við rekstur húsnæðisins þung, nokkur eða engin fjárhagsleg byrði?@"
                "^haus@/^fsvar@/^strik@/
                    Are your housing costs a heavy, some or no financial burden?" / "Byrði húsnæðiskostnaður":
                    (þung "Þung byrði" "Heavy burden",
                    nokkur "Nokkur byrði" "Some burden",
                    engin "Engin byrði" "No burden")

HK11_010(H1482)     "^haus@/^fsvar@/^strik@/
                    Er kostnaður við rekstur húsnæðisins, þar með talið afborganir húsnæðislána, leigu,
                    tryggingar, fasteignagjöld, viðhald og viðgerðir þung, nokkur eða engin fjárhagsleg byrði?@"
                    "^haus@/^fsvar@/^strik@/
                    Is the total housing costs, including mortgage repayment, rent, insurance and service
                    charges, regular maintenance and repairs, a heavy, some or no financial burden to you?" / "Byrði húsnæðiskostnaður":
                    (þung "Þung byrði" "Heavy burden",
                    nokkur "Nokkur byrði" "Some burden",
                    engin "Engin byrði" "No burden")

HK12            "^haus@/^fsvar@/^strik@/
                    Hvað telur þú að myndi vera greitt í leigu fyrir húsnæði eins og þitt á almennum markaði?"
                    "^haus@/^fsvar@/^strik@/
                    What is your idea about what would be paid in rent for a house like yours on the open market?
                    " / "Leigumat" : 0..900000

HK12_gisk         "^haus@/^fsvar@/^strik@/
                    En ef þú ættir að giska?
                    @/@/@GLestu upp svarkostina@G"
                    "^haus@/^fsvar@/^strik@/
                    But if you had to give your best guess?
                    @/@/@GLestu upp svarkostina@G
                    " / "Leigumat giska" :
                    (minna_en_50 "minna en 50.000 krónur?"   "Less than fifty thousand kronur?",
                    fra_51 "Á bilinu 51.000 til 80.000 krónur?"   "About fifty one thousand to eighty thousand kronur?",
                    fra_80 "Á bilinu 81.000 til 100.000 krónur?"   "About eighty one thousand to one hundred thousand kronur?",
                    fra_101 "Á bilinu 101.000 til 120.000 krónur?"   "About one hundred and one thousand to one hundred and twenty thousand kronur?",
                    fra_121 "Á bilinu 121.000 til 150.000 krónur?"   "About one hundred and one thousand to hundred and fifty thousand kronur?",
                    fra_150 "Á bilinu 151.000 til 200.000 krónur?"   "About one hundred and fifty one thousand to two hundred thousand kronur?",
                    fra_201 "Á bilinu 201.000 til 300.000 krónur?"   "About two hundred and one thousand to three hundred thousand kronur?",
                    meira_en_300 "meira en 300.000 krónur?"   "more than than three hundred thousand kronur?")

TV1a   (H151)    "^haus@/^fsvar@/^strik@/
                    Er heimasími á heimilinu?"
                    "^haus@/^fsvar@/^strik@/
                    Does the home have a landline or a home telephone?"
                    / "Heimilissímar" : TJáNei

TV1b   (H152)    "^haus@/^fsvar@/^strik@/
                    Er farsími á heimilinu?"
                    "^haus@/^fsvar@/^strik@/
                    Does the home have a mobile phone?"
                    / "Farsímar" : TJáNei

TV1c   (H153)    "^haus@/^fsvar@/^strik@/
                    Er sjónvarp á heimilinu?"
                    "^haus@/^fsvar@/^strik@/
                    Does the home have a television?"
                    / "Sjónvörp" : TJáNei

TV1d   (H154)    "^haus@/^fsvar@/^strik@/
                    Er tölva á heimilinu?"
                    "^haus@/^fsvar@/^strik@/
                    Does the home have a computer?"
                    / "Tölvur" : TJáNei

TV1f  (H156)    "^haus@/^fsvar@/^strik@/
                    Er þvottavél á heimilinu?
                    @/@/@GFlokkið svarið, ekki lesa upp svarmöguleikana."
                    "^haus@/^fsvar@/^strik@/
                    Does the home have a washing machine?
                    @/@/@GFlokkið svarið, ekki lesa upp svarmöguleikana."
                    / "Þvottavél" :
                    SET OF (Já "Já" "Yes",
                    Sameign "Já í sameign" "Yes commonly owned",
                    Nei "Nei" "No")

TV1g  (H157)    "^haus@/^fsvar@/^strik@/
                    Er uppþvottavél á heimilinu?"
                    "^haus@/^fsvar@/^strik@/
                    Is there a dishwasher in the home?"  / "Uppþvottavél" : TJáNei

TV1h  (H158)    "^haus@/^fsvar@/^strik@/
                    Hve margir bílar eru á heimilinu?  Ekki telja vinnubíla með, nema þeir séu notaðir fyrir heimilið."
                    "^haus@/^fsvar@/^strik@/
                    How many cars are there in the home? Not counting company cars unless they are used for household related purposes."  / "Bílar" : 0..8


TV1aI   (H1511)  "^haus@/^fsvar@/^strik@/
                    Er ekki fastlínusími á heimilinu vegna þess að hann er of dýr eða af öðrum ástæðum?"
                    "^haus@/^fsvar@/^strik@/
                    Is there not a landline telephone in the home because it is too expensive or for other reasons?"  / "Ekki heimilissíma":
                    (Ekkiráð "Hef ekki ráð, of dýrt" "Can not afford it, too expensive",
                     Annað "af öðrum ástæðum" "other reasons")

TV1bI   (H1512) "^haus@/^fsvar@/^strik@/
                    Er ekki farsími á heimilinu vegna þess að hann er of dýr eða af öðrum ástæðum?"
                    "^haus@/^fsvar@/^strik@/
                    Is there not a mobile telephone in the home because it is too expensive or for other reasons?"  / "Ekki farsíma":
                    (Ekkiráð "Hef ekki ráð, of dýrt" "Can not afford it, too expensive",
                     Annað "af öðrum ástæðum" "other reasons")

TV1cI   (H1513) "^haus@/^fsvar@/^strik@/
                    Er ekki sjónvarp á heimilinu vegna þess að það er of dýrt eða af öðrum ástæðum?"
                    "^haus@/^fsvar@/^strik@/
                    Is there not a television in the home because it is too expensive or for other reasons?"  / "Ekki sjónvarp":
                    (Ekkiráð "Hef ekki ráð, of dýrt" "Can not afford it, too expensive",
                     Annað "af öðrum ástæðum" "other reasons")

TV1dI   (H1514) "^haus@/^fsvar@/^strik@/
                    Er ekki tölva á heimilinu vegna þess að hún er of dýr eða af öðrum ástæðum?"
                    "^haus@/^fsvar@/^strik@/
                    Is there not a computer in the home because it is too expensive or for other reasons?"  / "Ekki tölva":
                    (Ekkiráð "Hef ekki ráð, of dýrt" "Can not afford it, too expensive",
                     Annað "af öðrum ástæðum" "other reasons")

TV1fI   (H1515) "^haus@/^fsvar@/^strik@/
                    Er ekki þvottavél á heimilinu vegna þess að hún er of dýr eða af öðrum ástæðum?"
                    "^haus@/^fsvar@/^strik@/
                    Is there not a washing machine in the home because it is too expensive or for other reasons?"  / "Ekki þvottavél":
                    (Ekkiráð "Hef ekki ráð, of dýrt" "Can not afford it, too expensive",
                     Annað "af öðrum ástæðum" "other reasons")

TV1gI   (H1515) "^haus@/^fsvar@/^strik@/
                    Er ekki uppþvottavél á heimilinu vegna þess að hún er of dýr eða af öðrum ástæðum?"
                    "^haus@/^fsvar@/^strik@/
                    Is there not a dishwasher in the home because it is too expensive or for other reasons?"  / "Ekki Uppþvottavél":
                    (Ekkiráð "Hef ekki ráð, of dýrt" "Can not afford it, too expensive",
                     Annað "af öðrum ástæðum" "Other reasons")

TV1hI   (H1515) "^haus@/^fsvar@/^strik@/
                    Er ekki bíll á heimilinu vegna þess að það er of dýrt að kaupa hann og reka eða af öðrum ástæðum?"
                    "^haus@/^fsvar@/^strik@/
                    Is there not a car in the home because it is too expensive or for other reasons?"  / "Ekki bíll":
                    (Ekkiráð "Hef ekki ráð, of dýrt" "Can not afford it, too expensive",
                     Annað "af öðrum ástæðum" "other reasons")


{Skuldir og afborganir}
TV2a (H15211)     "^haus@/^fsvar@/^strik@/
                     ^eru_heim með önnur lán en þau sem tekin hafa verið vegna kaupa á húsnæði, til dæmis bílalán,
                   námslán eða lán vegna fjárfestinga, kaupa á tækjum, húsgögnum, ferðum eða öðru?"
                 "^haus@/^fsvar@/^strik@/
                 Do you have other loans than mortgage loans taken because of house purchase, for example car loans, student loans, loans on investments, loans for purchasing equipment, furniture, travels or other expenses?"
                        / "Önnur lán": (já, nei)

TV2a_010 (H15211)     "^haus@/^fsvar@/^strik@/
                     En er einhver einstaklingur á heimilinu með slík lán?"
                 "^haus@/^fsvar@/^strik@/
                      Does anyone in the household have these types of loans?"
                        / "Önnur lán - 2010": Tjánei

TV2b (H15212)    "^haus@/^fsvar@/^strik@/
                      Eru afborganir og vextir annarra lána, en þeirra sem tekin hafa verið vegna húsnæðiskaupa, þung, nokkur eða engin fjárhagsleg byrði?"
                      "^haus@/^fsvar@/^strik@/
                      Are the payments and interests of those loans a heavy, some or no financial burden?"  / "Byrði skulda":
                        (þung "Þung byrði" "Heavy burden",
                        nokkur "Nokkur byrði" "Some burden",
                         engin "Engin byrði" "No burden")

TV3a (H15311)   "^haus@/^fsvar@/^strik@/
                    Hefur einhverntíma staðið þannig á síðustu 12 mánuði að ^Þú_þið_hafir ekki @ugetað@u greitt á eindaga vegna fjárskorts og þannig orðið
                     í vanskilum með húsaleigu?
                     @/@/@GAthugið að sá sem gleymdi að borga reikning á ekki að svara já hér aðeins þeir sem gátu ekki borgað@G"
                    "^haus@/^fsvar@/^strik@/
                    During the last 12 months have you ever not been able to pay your rent on time and thus
                   overdue with your rent payments?"
                   / "Vanskil húsaleigu": TJáNei

leiga_vanskil_oft   "^haus@/^fsvar@/^strik@/
                    Gerðist það einu sinni eða oftar með leiguna?"
                    "^haus@/^fsvar@/^strik@/
                    Did that happen once or more often with the rent? ?"
                   / "Vanskil húsaleigu oft"
                   : (einu "Einu sinni" "Once",
                      oftar "Oftar" "More often")


TV3b (H15311)   "^haus@/^fsvar@/^strik@/
                    Hefur einhverntíma staðið þannig á síðustu 12 mánuðum að ^þú_þið_hafir ekki @ugetað@u greitt á eindaga vegna fjárskorts og
                    þannig orðið í vanskilum með húsnæðislán af því húsnæði þar sem ^Thu_thid_buid?
                     @/@/@GAthugið að sá sem gleymdi að borga reikning á ekki að svara já hér aðeins þeir sem gátu ekki borgað@G"
                    "^haus@/^fsvar@/^strik@/
                   During the last 12 months have you ever not been able to pay your mortgage on time and thus
                   overdue with your mortgage payments?"
                    / "Vanskil húsnæðislána": TJáNei

Huslan_vanskil_oft  "^haus@/^fsvar@/^strik@/
                    Gerðist það einu sinni eða oftar með húsnæðislánin?"
                    "^haus@/^fsvar@/^strik@/
                    Did that happen once or more often with the mortgage?"
                   / "Vanskil húsnæðislána oft"
                   : (einu "Einu sinni" "Once",
                      oftar "Oftar" "More often")


TV3c(H15311)   "^haus@/^fsvar@/^strik@/
                    ^hafa_hei einhvern tíma ekki getað greitt í hússjóð vegna fjárskorts á síðustu 12 mánuðum?
                     @/@/@GAthugið að sá sem gleymdi að borga reikning á ekki að svara já hér aðeins þeir sem gátu ekki borgað@G"
                    "^haus@/^fsvar@/^strik@/
                    During the last 12 months have you ever not been able to pay your house fund on time?"
                    / "Vanskil hússjóðs": TJáNei

hussj_vanskil_oft  "^haus@/^fsvar@/^strik@/
                    Gerðist það einu sinni eða oftar með hússjóðinn?"
                    "^haus@/^fsvar@/^strik@/
                    Did that happen once or more often with the house fund?"
                   / "Vanskil hússjóðs oft"
                   : (einu "Einu sinni" "Once",
                      oftar "Oftar" "More often")


TV3d (H15311)   "^haus@/^fsvar@/^strik@/
                    Hefur einhvern tíma staðið þannig á síðustu 12 mánuði að ^Þú_þið_hafir ekki @ugetað@u greitt á eindaga vegna fjárskorts og
                    þannig orðið í vanskilum með hita- eða rafmagnsreikninga?
                     @/@/@GAthugið að sá sem gleymdi að borga reikning á ekki að svara já hér aðeins þeir sem gátu ekki borgað@G"
                    "^haus@/^fsvar@/^strik@/
                    During the last 12 months have you ever not been able to pay your heating or electricity bills?
                     @/@/@GAthugið að sá sem gleymdi að borga reikning á ekki að svara já hér aðeins þeir sem gátu ekki borgað@G"
                    / "Vanskil hita og rafmagns": TJáNei

Ra_hi_vanskil_oft   "^haus@/^fsvar@/^strik@/
                    Gerðist það einu sinni eða oftar með rafmagn eða hita?"
                    "^haus@/^fsvar@/^strik@/
                    Did that happen once or more often with the utilities??"
                   / "Vanskil rafmagn og hita oft"
                   : (einu "Einu sinni" "Once",
                      oftar "Oftar" "More often")


TV3e(H15311)        "^haus@/^fsvar@/^strik@/
                   Ef þú hugsar um önnur lán en húsnæðislán, svo sem bílalán,
                   námslán eða lán vegna fjárfestinga, kaupa á tækjum, húsgögnum, ferðum eða öðru.
                   Hefur einhvern tímann staðið þannig á síðustu 12 mánuðina
                   að ^þú_þið_hafir @Uekki getað@U greitt á eindaga vegna
                   fjárskorts og þannig lent í @uvanskilum@u?
                   @/Þetta gætu til dæmis verið raðgreiðslur eða greiðsludreifing
                   á vörum eða þjónustu sem ^hon_hen hefur ekki tekist að standa í skilum með.
                     @/@/@GAthugið að sá sem gleymdi að borga reikning á ekki að svara já hér aðeins þeir sem gátu ekki borgað@G"
                    "^haus@/^fsvar@/^strik@/
                    Have you ever during the last 12 months not been able to pay on time any other lones than your mortgage?"
                     / "Vanskil annarra lána": TJáNei

onnur_vanskil_oft  "^haus@/^fsvar@/^strik@/
                    Gerðist það einu sinni eða oftar með önnur lán?"
                    "^haus@/^fsvar@/^strik@/
                    Did that happen once or more often with other loans? ?"
                   / "Önnur vanskil oft"
                   : (einu "Einu sinni" "Once",
                      oftar "Oftar" "More often")

TV4a (H1541)   "^haus@/^fsvar@/^strik@/
                    Hvernig gengur ^hon_hen að ná endum saman með þeim tekjum sem eru til ráðstöfunar?
                    Er það mjög erfitt, erfitt, nokkuð erfitt, nokkuð auðvelt, auðvelt eða mjög auðvelt?"
                    "^haus@/^fsvar@/^strik@/
                    Is it very difficult, difficult, fairly difficult, fairly easy, easy or very easy to make ends meet with the
                    income that you have available?"
                    / "Ná endum saman":
                       (Mjög "Mjög erfitt" "Very difficult",
                        Erfitt "Erfitt" "Difficult",
                        Nokkuð "Nokkuð erfitt" "Fairly difficult",
                        NokkuðAuð "Nokkuð auðvelt" "Fairly easy",
                        Auðvelt "Auðvelt" "Easy",
                        MjögAu "Mjög auðvelt" "Very easy")

TV4b (H1542)    "^haus@/^fsvar@/^strik@/
                    Hverjar eru að þínum dómi lægstu nettó tekjur, það er tekjur eftir skatt, sem ^þarf að hafa á mánuði til
                    að ná endum saman?"
                    "^haus@/^fsvar@/^strik@/
                    What is according to you the lowest income, after taxes that you need to have per month?
                    to make ends meet?" / "Lægstu nettó tekjur": 0..2000000

TV4b_gisk       "^haus@/^fsvar@/^strik@/
                    En ef þú ættir að giska?"
                    "^haus@/^fsvar@/^strik@/
                    But if you had to give your best guess?" / "Lægstu nettó tekjur gisk": 0..2000000

TV4c (H1553)    "^haus@/^fsvar@/^strik@/
                    ^geta mætt óvæntum, en nauðsynlegum útgjöldum að fjárhæð 170 þúsund krónur með þeim leiðum sem heimilið notar venjulega til að standa undir útgjöldum?"
                     "^haus@/^fsvar@/^strik@/
                    Could you pay an unexpected but necessary expenditure of 170.000 kr. on your own, using the means the household
                    ususally uses to pay its expenses?" / "Óvænt útgjöld": TJáNei

TV5a (H1551)   "^haus@/^fsvar@/^strik@/
                    ^hafa_hei efni á að fara árlega í 7 daga ferðalag innanlands?"
                    "^haus@/^fsvar@/^strik@/
                    Would you afford to go on a yearly trip within the country, paying for both travelling and accommodation?" / "Ferðalag innanlands": TJáNei

Fri_gisting    "^haus@/^fsvar@/^strik@/
                    En ^hef_thid_thu efni á því að fara ef þið mynduð gista hjá vinum eða ættingjum?"
                    "^haus@/^fsvar@/^strik@/
                    But could you afford to if you could stay with friends or relatives?"
                    /"Frí gisting"
                    : TjáNei

HD240               "^haus@/^fsvar@/^strik@/
                    En hafið þið efni á að senda einungis börnin á heimilinu sem eru á aldrinum eins til fimmtán ára?"
                    "^haus@/^fsvar@/^strik@/
                    But could you afford to let only children in the household aged one to fifteen year go?"
                    /"Börnin í frí"
                    : TjáNei


ferda011            "^haus@/^fsvar@/^strik@/
                    ^hafa_hei efni á að fara í vikulangt frí árlega, fjarri heimilinu? Þar með talið er gisting í sumarbústað eða hjá vinum og ættingjum."
                    "^haus@/^fsvar@/^strik@/
                    Could you afford to go on an annual, weeklong vacation, including if you could stay in a summer cottage or with friends or relatives?"
                    /"Ferðalag"
                    : TjáNei
                    {bætt við fyrir gagnasöfnun 2011 fyrir athugun á ferðaspurningum.}

TV5b (H1551)   "^haus@/^fsvar@/^strik@/
                     En ef ^vill fara árlega í einnar viku ferðalag til útlanda og þyrft^ir_uð að greiða fyrir flug og gistingu ?"
                    "^haus@/^fsvar@/^strik@/
                    What about one week's holiday abroad if you were to pay for both travelling and accommodation?" / "Ferðalag til útlanda": TJáNei

TV5c (H1552)   "^haus@/^fsvar@/^strik@/
                   ^hafa_hei ráð á kjöt-, fisk- eða sambærilegri grænmetismáltið að minnsta kosti annan hvern dag?"
                    "^haus@/^fsvar@/^strik@/
                    Can your household afford a meal with meat, chicken, fish or vegetarian equivalent every other day?" / "Ráð á hollum mat": TJáNei

TV6a (TV6a)     "^haus@/^fsvar@/^strik@/
                    ^fa_heimi greitt meðlag með barni eða börnum yngra en 18 ára á síðasta ári?
                    @/@/@GÞað er á tímabilinu janúar til desmeber síðasta ár.@G"
                    "^haus@/^fsvar@/^strik@/
                   ^anyone in the household get maintenance or an alimony for a child or children younger than eighteen last year?
                    @/@/@GThat is from january to december last year.@G" / "Meðlag": TJáNei

TV6a1           "^haus@/^fsvar@/^strik@/
                    Með hversu mörgum börnum á heimilinu fenguð þið greitt meðlag?
                    @/@/@GÞað er á tímabilinu janúar til desmeber síðasta ár.@G"
                    "^haus@/^fsvar@/^strik@/
                   With how many children in total did household members receive alimony?
                    @/@/@GThat is from january to december last year.@G" / "Fjöldi fenginna meðlaga": 1..15

TV6b (TV6b)      "^haus@/^fsvar@/^strik@/
                    Hve mikið á mánuði á hvert barn?"
                    "^haus@/^fsvar@/^strik@/
                    How much per month?" / "Hve mikið": 1000..100000

TV6ba (TV6ba)    "^haus@/^fsvar@/^strik@/
                    Er þetta venjulegt/lögbundið meðlag, meira en það eða minna?"
                    "^haus@/^fsvar@/^strik@/
                    Is this a usual / obligatory maintenance, more or less than that?" / "Venjulegt":
                     (Venjulegt "Venjulegt" "Usual",
                      Meira "Meira en venjulegt" "More than usual",
                      Minna "Minna en venjulegt" "Less than usual")

TV6c (TV6c)      "^haus@/^fsvar@/^strik@/
                    ^fa_heimi reglulegan fjárhagsstuðning frá öðru heimili á síðasta ári?
                    @/@/@GÞað er á tímabilinu janúar til desmeber síðasta ár.@G"
                    "^haus@/^fsvar@/^strik@/
                    ^Anyone in the home receive regular financial support from another home last year?
                    @/@/@GFrom january to december last year.@G"
                    / "Fjárhagsstuðningur": TJáNei

TV6d (TV6d)      "^haus@/^fsvar@/^strik@/
                    Hvað var sá stuðningur mikill yfir árið?"
                    "^haus@/^fsvar@/^strik@/
                    How much was that over the course of the year?" / "Hve mikið": 1000..1000000

TV7a (TV7a)      "^haus@/^fsvar@/^strik@/
                    ^Medlag meðlag með barni/börnum yngri en 18 ára á síðasta ári?"
                    "^haus@/^fsvar@/^strik@/
                    ^Anyone in the home pay maintenance or alimoney for a child or children younger than 18 over the last year?
                    " / "Greitt meðlag": TJáNei

TV7a1           "^haus@/^fsvar@/^strik@/
                    Með hversu mörgum börnum var greitt meðlag?"
                    "^haus@/^fsvar@/^strik@/
                   With how many children in total did the household members pay alimoney?" / "Fjöldi greiddra meðlaga": 1..15

TV7B (TV7B)      "^haus@/^fsvar@/^strik@/
                    Hve mikið á mánuði á hvert barn?"
                    "^haus@/^fsvar@/^strik@/
                    How much per month?" / "Hve mikið": 1000..1000000

TV7Ba (TV7Ba)    "^haus@/^fsvar@/^strik@/
                    Er þetta venjulegt/lögbundið meðlag, meira en það eða minna?"
                    "^haus@/^fsvar@/^strik@/
                    Is this a usual / obligatory maintenance, more or less than that?" / "Venjulegt":
                     (Venjulegt "Venjulegt" "Usual",
                      Meira "Meira en venjulegt" "More than usual",
                      Minna "Minna en venjulegt" "Less than usual")


TV7d (TV7d)     "^haus@/^fsvar@/^strik@/
                    ^medlag reglulegan fjárhagsstuðning til einhvers á öðru heimili á síðasta ári?"
                    "^haus@/^fsvar@/^strik@/
                    ^Anyone in the home give regular financial support to someone in another home over the last year?"
                    / "Fjárhagsstuðningur": TJáNei

TV7e (TV7e)      "^haus@/^fsvar@/^strik@/
                    Hve mikið var það yfir árið í heildina?"
                    "^haus@/^fsvar@/^strik@/
                    How much?" / "Hve mikið": 1000..1000000

spyrill: string


Auxfields
  hussjodur: string
  með_bílskúr, including_the_garage, an_bilskur, excluding_the_garage : string
  hk5bb_texti : string
  ir_uð : string
  eigid_leiga_isl : string
  eigid_leiga_ens : string
  {Málfarsbreytur fyrir viðhengi2008}
  thu_annar,
  thu_einhver,
  Thu_heimili_komid,
  Thinum_heimilisins,
  Thins_allra,
  Ert_thu_thid,
  Thu_thid_buid,
  Hafid_hefur_thid,
  Rukkad_rukkud,
  Heimilistekjur_thinar,
  Thu_heimili,
  Thu_heimilismadur,
  Gat_gast,
  Haetti_haettur,
  Heimilisins_thin,
  Noti_notadir,
  thurfum_tharf,
  kjosum_kys,
  bua_vinna,
  okkur_mer,
  Vaeri_vaerir,
  faum_fae,
  geatum_gaeti,
  sottum_sotti,
  hofum_hef,
  eg_vid,
  thinar_heimilisins,
  lan_leiga, hef_thid_thu, frkvsjodur, eda, fyrir_utan, fyrir_utan1, borgar, Thuert_heimilider, greitt_heimili :string
  kt_sub: integer

{EXTERNALS
  Fyrrisvör   : FSV ('Fyrrisvor')}


RULES
  kt_sub := val(substring(kennitala,1,2)) {bætt við fyrir gagnasöfnun 2011 fyrir athugun á ferðaspurningum.}
  prc_YouDoDoes      (persóna, do_you)
  M := FjöldiHeimilismanna
  ErBarnMedlag := Nei
  FOR I := 1 TO M DO
    if (Fjölskylda.Heimilismaður[I].Brottfluttur = Nei) then
      HeimNafn[I] := Fjölskylda.Heimilismaður[I].Nafn
    else
      HeimNafn[I] := ''
    endif
    IF (HeimNafn[I] > '') and (Fjölskylda.Heimilismaður[I].Brottfluttur = Nei) THEN
      HeimNafn[I] := HeimNafn[I] + ', ' + Str(Fjölskylda.Heimilismaður[I].Aldur)
    ENDIF
    IF (Fjölskylda.Heimilismaður[I].Brottfluttur = Nei) and (Fjölskylda.Heimilismaður[I].Aldur <= 18 ) THEN
      ErBarnMedlag := Já
    ENDIF
  ENDDO



  greitt_heimili  := 'Greiðir heimilið/Greiðir þú'
  hann_hun  := 'hann/hún'
  hans_hen  := 'hans/hennar'
  hon_hen   := 'honum/henni'
  hafa_hei  := 'Hafið þið'{Hafa heimilismenn}
  fa_heimi  := 'Fáið þið' {Fá heimilismenn}
  a_heimil  := 'Eigið þið'{Eiga heimilismenn}
  eru_heim  := 'Eruð þið' {Eru heimilismenn}
  st_heim   := 'Stundaði hann/hún'
  er_heim   := 'Er hann/hún'
  var_heim  := 'Var hann/hún'
  thitt     := 'hans/hennar'
  sig       := 'sig'
  Var_einhv := 'Var einhver'
  Þú_þið    := 'þið'
  Þú_þið_hafir    := 'þú/þið hefur/hafið'
  Borðar    := 'Borðar þú/borðið þið'
  buid      := 'býrðu/búið þið'
  buidA      := 'Býrðu/Búið þið'
  þarf      := 'Þarft/þurfið'
  geta_veitt  := 'Getur þú veitt þér það /Getið þið veitt ykkur það'
  Vill := 'Þú vildir /þið vilduð öll'
  Medlag := 'Greiddir þú /Greiddi einhver heimilismanna'
  Anyone := 'Did you/anyone'
  ir_uð := 'ir/uð'
  borgar := 'borgar þú/borgið þið'
  geta := 'getur þú/getið þið'
  Thuert_heimilider := 'þú ert/heimilið er'

  if   hmFjöldi  > 1 then                {Fjöldiheimilismanna = Fjöldi annarra heimilismanna}
    greitt_heimili  := 'Greiðir heimilið'
    buid      := 'búið þið'
    buidA      := 'Búið þið'
    hafa_hei  := 'Hafið þið'
    fa_heimi  := 'Fékk einhver heimilismanna'
    a_heimil  := 'Eigið þið'
    eru_heim  := 'Eruð þið'
    geta  := 'Getið þið'
    Þú_þið    := 'þið'
    Þú_þið_hafir    := 'þið hafið'
    thitt     := 'ykkar'
    þinn_ykkar := 'ykkar'
    þinu_ykkar := 'ykkar'
    hon_hen   := 'ykkur'
    Vill := 'þið vilduð öll'
    Medlag := 'Greiddi einhver heimilismanna'
    Borðar := 'borðið þið saman'
    hann_hun := 'þið'
    þarf      := 'þið á heimilinu þurfið'
    geta_veitt  := 'getið þið veitt ykkur það'
    Leigið_þið := 'Leigið þið'
    {Var_einhv  := 'Voru þið' }
    Anyone := 'Did anyone'
    ir_uð := 'uð'
    {málfarsbreytur fyrir viðhengi2008 þar sem fleiri en 1 er á heimili}
    thu_annar:= 'þú eða einhver annar á heimilinu'
    thu_einhver := 'er einhver heimilismanna'
    Thu_heimili_komid := 'heimilið í heildina er komið'
    Thinum_heimilisins := 'heimilisins'
    Thins_allra := 'allra heimilismanna'
    Ert_thu_thid := 'eruð þið'
    Thu_thid_buid := 'þið búið'
    Hafid_hefur_thid :='hafið þið'
    Rukkad_rukkud :='heimilið er rukkað'
    Heimilistekjur_thinar :='heimilistekjum'
    Thu_heimili := 'heimilið'
    Thu_heimilismadur := 'heimilismaður'
    Gat_gast := 'gat'
    Haetti_haettur :='hætti'
    Heimilisins_thin := 'heimilisins'
    Noti_notadir :='enginn í fjölskyldunni noti'
    thurfum_tharf :='við þurfum'
    kjosum_kys := 'við kjósum'
    bua_vinna :='við búum eða vinnum'
    okkur_mer  :='okkur'
    Vaeri_vaerir :='enginn heimilismaður væri'
    faum_fae := 'við fáum'
    geatum_gaeti :='við gætum'
    sottum_sotti :='við sóttum'
    hofum_hef := 'við höfum'
    eg_vid :='við'
    thinar_heimilisins := 'heimilisins'
    hef_thid_thu := 'hefðuð þið'
    borgar := 'borgið þið'
    Thuert_heimilider := 'heimilið er'

  {Búa til orðalag miðað við 1, 2 eða fleiri fullorðna í heimili   }

  elseif hmFjöldi = 1 then
    greitt_heimili  := 'Greiðir þú'
    buid      := 'býrðu'
    buidA      := 'Býrðu'
    Þú_þið    := 'þú'
    Þú_þið_hafir    := 'þú hefur'
    hans_hen  := 'þín'
    hon_hen   := 'þér'
    hafa_hei  := 'Hefur þú'
    fa_heimi  := 'Fékkst þú'
    a_heimil  := 'Átt þú'
    eru_heim  := 'Ert þú'
    st_heim   := 'Stundaðir þú'
    eru_heim   := 'Ert þú'
    var_heim  := 'Varst þú'
    thitt     := 'þitt'
    sig       := 'þig'
    Var_einhv := 'Varst þú'
    þinn_ykkar := 'þinni'
    þinu_ykkar := 'þínu'
    Vill := 'þú vildir'
    geta  := 'Getur þú'
    Medlag := 'Greiddir þú'
    Borðar := 'borðar þú'
    hann_hun := 'þú'
    þarf      := 'Þú þarft'
    geta_veitt  := 'getur þú veitt þér það'
    Leigið_þið := 'Leigir þú'
    Anyone := 'Did you'
    ir_uð := 'ir'
    {málfarsbreytur fyrir viðhengi2008 þar sem 1 er á heimili}
    thu_annar := 'þú'
    thu_einhver :='ert þú'
    Thu_heimili_komid :='þú er komin/n'
    Thinum_heimilisins := 'þínum'
    Thins_allra := 'þíns'
    Ert_thu_thid := 'ert þú'
    Thu_thid_buid := 'þú býrð'
    Hafid_hefur_thid := 'hefur þú'
    Rukkad_rukkud :='þú ert rukkuð/rukkaður'
    Heimilistekjur_thinar :='tekjum þínum'
    Thu_heimili := 'þú'
    Thu_heimilismadur := 'þú'
    Gat_gast := 'gast'
    Haetti_haettur :='hættir'
    Heimilisins_thin := 'þín'
    Noti_notadir :='þú notaðir ekki'
    thurfum_tharf := 'ég þarf'
    kjosum_kys := 'ég kýs'
    bua_vinna :='ég bý eða vinn'
    okkur_mer :='mér'
    Vaeri_vaerir :='þú værir ekki'
    faum_fae := 'ég fæ'
    geatum_gaeti :='ég gæti'
    sottum_sotti :='ég sótti'
    hofum_hef  := 'ég hef'
    eg_vid :='ég'
    thinar_heimilisins := 'þínar'
    hef_thid_thu := 'hefðir þú'
    borgar := 'borgar þú'
    Thuert_heimilider := 'þú ert'
  endif

  NEWPAGE

  hk1a
  hk2

    HeimiliByrjarDags.keep
    HeimiliByrjarTimi.keep
    spyrill.keep
    if (HK1a = response or hk1a = refusal or hk1a <> empty) then
    if HeimiliByrjarDags = empty then HeimiliByrjarDags := sysdate endif
    if HeimiliByrjarTimi = empty then HeimiliByrjarTimi := systime endif
  endif
  if (HK2 = response or hk2 = refusal) then
    if HeimiliByrjarDags = empty then HeimiliByrjarDags := sysdate endif
    if HeimiliByrjarTimi = empty then HeimiliByrjarTimi := systime endif
  endif
    if (HK2 = response or hk2 = refusal) then
    if spyrill = empty then spyrill := username endif
  endif

  if hk2 = já then
    HK2_bils
    með_bílskúr := ' með bílskúr'
    including_the_garage := ' including the garage'
  else
    með_bílskúr := ''
    including_the_garage := ''
  endif

  {if hk2 = já then
    HK2_bils
    an_bilskur := ' án bílskúrs'
    excluding_the_garage := ' excluding the garage'
  else
    an_bilskur := ' '
    excluding_the_garage := ' '
  endif}
  hk2a {fært neðar}

    IF HK1a = annað THEN HK1aa  ENDIF
    IF HK1a = einbýli THEN Einbýli  ENDIF
    IF HK1a = raðhús  THEN Raðhús  ENDIF
    IF HK1a = tveggja_til_fimm  THEN  Tveggja_til_fimm  ENDIF
    IF HK1a = fjölbýli THEN fjölbýli HK1b ENDIF
    HK2b
    IF (einbýli IN [einbýlib, einbýlic]) or (raðhús in [raðhúsb ,raðhúsc]) or  (tveggja_til_fimm in [tveggja_til_fimmb]) or (fjölbýli
        in [fjölbýlib]) or (HK1a = annað)  THEN
      HK3a
      HK3d
      IF HK3d = já then HK3dd endif
    ENDIF

  HK5a

  if Hk5a = leiga then eigid_leiga_isl := 'leiga'
                       eigid_leiga_ens := 'rent'
  else if hk5a = eigið then eigid_leiga_isl := 'lánaafborganir'
                            eigid_leiga_ens := 'loan payments'
  endif
  endif


  if HK5a = leiga then HK5a_leiga endif


  IF HK5a = eigið THEN
    eigandi_leigjandi_lán := 'önnur lán en lán sem tekin hafa verið vegna kaupa á húsnæði'
  ELSE
    eigandi_leigjandi_lán := 'lán'
  ENDIF

  IF HK5a = eigið THEN
      HK5ba   {kaupár}

    check if HK5ba = response then HK5ba <= year(VidtalByrjarDags) "ártal getur ekki verið hærra en núna" endif

    HK5ca  {Skráðir eigendur}
    IF Annar in HK5ca THEN HK5cX ENDIF
    HK10 {Áhvílandi lán}
    IF HK10 = nei
        then HK10nei
            IF HK10nei = annad
                then HK10neiannad
            ENDIF
    ENDIF
  ELSE
    NEWPAGE
      if hk5a = leiga then
        hk5bb_texti := 'var húsnæðið tekið á leigu'
      else
        hk5bb_texti := 'fluttu þið inn í húsnæðið'
      endif
      HK5bb     {leiguár}
    HK5cb    {skráðir leigjendur}
    IF Annar in HK5cb THEN HK5cbX ENDIF
    HK6a
    if hk6a = Annar then hk6aa endif
    if HK5a <> Embætti then HK6d endif
    signal
    if hk6d = response then (hk6d >= 10000 and hk6d <= 200000) "Ertu viss um að húsaleiga ^hk6d sé rétt?" endif
    if HK6d = dk then HK6d1 endif
    HK6f
    IF HK6f = já THEN
      HK6fa
      signal
      if hk6fa = response then (hk6fa >= 1000 and hk6fa <= 50000) "Ertu viss um að upphæð sé rétt?" endif
    ENDIF
    HK7a
  ENDIF
  IF (HK1a = raðhús or HK1a = tveggja_til_fimm or HK1a = fjölbýli or HK1a = annað)
     and not (hússjóður in HK7a) THEN {Ef um raðhús eða fjölbýli þá er spurt um hússjóð og framkvæmdasjóð}
    HK7b
    signal
    if (hk7b = response) then (hk7b <= 15000) "Ertu viss um að upphæð sé 15.000 eða hærri?" endif

    IF HK7b > 0 THEN HK7c ENDIF
    IF HK7b <> 0 then hussjodur := ' í hússjóð'
                      fyrir_utan1 := ', fyrir utan það sem var greitt'
        else if HK7b = 0 then hussjodur := ''
                              fyrir_utan1 := ''
    ENDIF
    ENDIF
    HK8d
    signal
    if (hk8d = response) then (hk8d <= 50000) "Ertu viss um að upphæð sé 50.000 eða hærri?" endif
    IF HK8d <> 0 then frkvsjodur := ' í framkvæmdasjóð'
        else if HK8d = 0 then frkvsjodur := ''
    ENDIF
    ENDIF
    IF HK8d <> 0 OR HK7b <> 0 then fyrir_utan := ', fyrir utan það sem var greitt'
        else if (HK8d = 0 or HK8d = empty) OR (HK7b = 0 or HK7b = empty) then fyrir_utan := ''
    ENDIF
    ENDIF
    IF HK8d <> 0 AND HK7b <> 0 then eda := 'eða'
        else if HK8d = 0 AND HK7b = 0 then eda := ''
    ENDIF
    ENDIF
  ENDIF
  IF HK5a = eigið
    then
        HK8e

        signal
        if (hk8e = response) then (hk8e <= 10000000) "Ertu viss um að upphæð sé 10 milljónir eða hærri?" endif
  ENDIF
  IF (HK5a = eigið and hk1a <> einbýli) or (HK5a = eigið and hk8e <> 0 and HK1a = einbýli)
    then VSK_jn
        IF VSK_jn = já
            then VSK_upph
        ENDIF
  ENDIF
  HK9a
  IF HK9a = Annar_hiti then HK9aa endif

{HC050  TEKIÐ ÚT JAN 2013 - HLUTI AF VIÐHENGI 2012 }
{  IF HK9a <> hitaveita then HC050
    IF HC050 = nei then HC050_annad ENDIF
  ENDIF}

  IF not (híbúð in HK7a) and not (Híbúð in HK7c) THEN {rafmagn og hiti}
    HK9bjn
    {if hk9b > 0 then hk9b2 endif}
    {signal
    if (hk9b = response) then (hk9b <= 35000) "Ertu viss um að upphæð sé 35.000 eða hærri?" endif}
  ENDIF
  IF not (ríbúð in HK7a) and not (Ríbúð in HK7c) THEN
    HK9cjn
    {if hk9c > 0 then hk9c2 endif
    signal
    if (hk9c = response) then (hk9c <= 50000) "Ertu viss um að upphæð sé 50.000 eða hærri?" endif}
  ENDIF
  HK11_010
  IF HK5a = eigið THEN
    HK12
    signal
    if (hk12 = response) then (hk12 >= 10000) and (Hk12 <= 300000) "Ertu viss um að upphæð sé rétt?" endif
    if hk12 = dk then HK12_gisk endif
  ENDIF

  {Allir, þakleki o.þ.h.}
  NEWPAGE
  HK4aa
  HK4ac
  HK4b_08
  HK4c
  HK4c2a
  HK4c3a

  newpage

  NEWPAGE
  TV1a
  TV1b
  TV1c
  TV1d
  TV1f
  check if Nei in TV1f then TV1f.cardinal = 1 "Ekki er hægt að velja 'Nei' með öðrum kostum" endif
  if 1 = 0 then TV1g endif
  TV1h
  IF TV1a = nei THEN
    TV1aI
  ENDIF
  IF TV1b = nei THEN
    TV1bI
  ENDIF
  IF TV1c = nei THEN
    TV1cI
  ENDIF
  IF TV1d = nei THEN
    TV1dI
  ENDIF
  IF nei in TV1f THEN
    TV1fI
  ENDIF
  IF (0 = 1) and TV1g = nei THEN
    TV1gI
  ENDIF
  IF TV1h = 0 THEN
    TV1hI
  ENDIF

  NEWPAGE
  Kynning2
  TV2a
  IF TV2a = nei AND er_eldri_en_15_ara_a_heimilinu = já then TV2a_010 endif
  IF TV2a = já or tv2a_010 = já THEN
    TV2b
  ENDIF



  IF HK6d <> empty THEN
    TV3a  {Ef hann fær spurningu um húsaleigu}
    if tv3a = já then leiga_vanskil_oft endif
  ENDIF
  IF HK10 = já OR hk10nei = frysting OR hk10nei = neita OR hk10nei = annad THEN
    TV3b
    if tv3b = já then Huslan_vanskil_oft endif
  ENDIF
  IF HK7b <> 0 OR HK7b = refusal OR HK7b = dk THEN  {AÖK 27.01.09}
    TV3c  {Ef hann fær spurningu um hússjóð}
    IF tv3c = já THEN hussj_vanskil_oft ENDIF
  ENDIF
  IF HK9bjn = já or HK9cjn = já THEN {breytt fyrir SILC2010}
    TV3d
    if tv3d = já then Ra_hi_vanskil_oft endif
  ENDIF
  IF TV2a = já THEN
    TV3e
    if tv3e = já then onnur_vanskil_oft endif
  ENDIF

  IF HK5a = eigið then lan_leiga := 'lánaafborgana' endif
  IF Hk5a = leiga then lan_leiga := 'leiga' endif
  TV4a
  TV4b
  signal
  if (tv4b = response) then (tv4b >= 30000)  "Hverjar eru að þínum dómi lægstu nettó tekjur, það er tekjur eftir skatt, sem ^þarf að hafa á mánuði til að ná endum saman?" endif
  if TV4b = dk then TV4b_gisk endif
  TV4c

  TV5a
    IF Tv5a = nei
        then fri_gisting
            {if (fri_gisting = nei) and (er_til_barn_1_15_ara = já)
                then HD240
            endif}
    endif
    IF tv5a = já
        then TV5b
    ENDIF

  TV5c
  IF er_yngri_en_19_ara_a_heimilinu = Já THEN
    TV6a
    IF TV6a = já THEN
      Tv6a1
      TV6b
      signal
      if (tv6b = response) then (tv6b >= 12000) "Ertu viss um að upphæð sé lægri en 12.000 ?" endif
      IF TV6b = dontknow THEN
        TV6ba
      ENDIF
    ENDIF
  ENDIF
  TV6c
  IF TV6c = já THEN
    TV6d
    signal
    if (tv6d = response) then (tv6d >= 10000) "Ertu viss um að upphæð sé lægri en 10.000 ?" endif
  ENDIF

    TV7a   {Greiddirðu meðlag}
    IF TV7a =já THEN
      tv7a1
      TV7B
      IF TV7B = dk THEN
        TV7BA
      ENDIF
    ENDIF

  TV7d
  IF TV7d = já THEN
    TV7e
    signal
    if (tv7e = response) then (tv7e >= 12000) "Ertu viss um að upphæð sé lægri en 12.000 ?" endif

  ENDIF

 HeimiliLokidDags.keep
 HeimiliLokidTimi.keep
 endir_yttu
 IF endir_yttu <> empty and heimililokiddags = empty then
 HeimiliLokidDags := SysDate
 HeimiliLokidTimi := SysTime
 ENDIF

  LAYOUT
  AT BLOCKSTART
  INFOPANE AdalSkjarTveirDalkar
ENDBLOCK
