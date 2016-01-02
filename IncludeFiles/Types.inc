{   Types.inc
    Samfelld vinnumarkaðsrannsókn
    ÓH (c) nóvember 2002}

 TYPE TStatus         = (
        Launþegi                        "Launþegi"             "Employee",
        Sjálfstætt                      "Sjálfstætt starfandi" "Self-employed",
        Hvorugt                         "Hvorugt"              "Neither")

 TYPE TKyn                = (
        karl                            "Karl" "Male",
        kona                            "Kona" "Female")

 TJáNei          = (
        Já                              "Já"  "Yes",
        Nei                             "Nei" "No")

 TYPE TJáNeiJáEf          = (
        Já                              "Já"         "Yes",
        Nei                             "Nei"        "No",
        JáEf                            "Já, ef ..." "Yes, if ...")

 TYPE TJáNeiAFjarvst          = (
        Já                              "Já, var tímabundið fjarverandi" "Yes, was temporarily absent",
        Nei                             "Nei, er ekki í vinnu" "No, does not have a job")

 TYPE TSama    = (Já     "Já"                "Yes",
                  Nei    "Nei"               "No",
                  Rangt  "Fyrra svar rangt"  "Previous answer wrong")

 TYPE TPersóna = (karl         "1. persóna, karl",
                  kona         "1. persóna, kona",
                  annarKarl    "3. persóna, karl",
                  annarKona    "3. persóna, kona",
                  annarÓvíst   "3. persóna, kyn óþekkt")

TYPE TTími = (t0 (0) " ", t1 " ", t2 " ", t3 " ", t4 " ", t5 " ", t6 " ", t7 " ", t8 " ", t9 " ", t10 " ",
             t11 " ", t12 " ", t13 " ", t14 " ", t15 " ", t16 " ", t17 " ", t18 " ", t19 " ", t20 " ",
             t21 " ", t22 " ", t23 " ", t24 " ", t25 " ", t26 " ", t27 " ", t28 " ", t29 " ", t30 " ",
             t31 " ", t32 " ", t33 " ", t34 " ", t35 " ", t36 " ", t37 " ", t38 " ", t39 " ", t40 " ",
             t41 " ", t42 " ", t43 " ", t44 " ", t45 " ", t46 " ", t47 " ", t48 " ", t49 " ", t50 " ",
             t51 " ", t52 " ", t53 " ", t54 " ", t55 " ", t56 " ", t57 " ", t58 " ", t59 " ", t60 " ",
             t61 " ", t62 " ", t63 " ", t64 " ", t65 " ", t66 " ", t67 " ", t68 " ", t69 " ", t70 " ",
             t71 " ", t72 " ", t73 " ", t74 " ", t75 " ", t76 " ", t77 " ", t78 " ", t79 " ", t80 " ",
             t81 " ", t82 " ", t83 " ", t84 " ", t85 " ", t86 " ", t87 " ", t88 " ", t89 " ", t90 " ",
             t91 " ", t92 " ", t93 " ", t94 " ", t95 " ", t96 " ", t97 " ", t98 " ", t99 " ", t100 " ",
             t101 " ", t102 " ", t103 " ", t104 " ", t105 " ", t106 " ", t107 " ", t108 " ", t109 " ", t110 " ",
             t111 " ", t112 " ", t113 " ", t114 " ", t115 " ", t116 " ", t117 " ", t118 " ", t119 " ", t120 " ")

 TYPE TVenja = (Venjulega    "Venjulega"    "Usually",
                Stundum      "Stundum"      "Sometimes",
                Aldrei       "Aldrei"       "Never")

 TYPE TStaða = (
        ifullustarfi                    "starfandi í fullu starfi"
                                        "working in full time job",
        ihalfustarfi                    "starfandi í hlutastarfi"
                                        "working in part time job",
        námsmaður                       "námsmann, eða á námssamningi"
                                        "student",
        aldur                           "hætta^n að vinna vegna aldurs"
                                        "retired",
        öryrki                          "öryrkja eða fatlaða^n"
                                        "disabled",
        heimavinnandi                   "heimavinnandi án launaðrar vinnu"
                                        "homeworking",
        fæðingarorlof                   "í fæðingarorlofi"
                                        "in maternity/paternity leave",
        atvinnulaus                     "atvinnulausa^n"
                                        "unemployed",
        veikindi                        "veika^n eða tímabundið ófæra^n til vinnu"
                                        "ill or temporarily unable to work",
        annað                           "annað"
                                        "other")

 TYPE TGMenntun = (
        MinnaEnGrunnskóli        (10)  "Ekki lokið grunnskólaprófi",
        Grunnskóli               (21)  "Grunnskólapróf",
        Stúdent                  (35)  "Stúdentspróf",
        Fyrrihlutapróf           (53)  "Grunnpróf úr háskóla")

 TYPE THju =       (ógiftur       "Hefur ekki gifst"      "Single",
                    giftur        "gift^ur"                "Married",
                    sambúð        "Í óvígðri sambúð"       "Cohabiting/living together",
                    skilinn       "Fráskilin^n"            "Divorced",
                    ekkill        "^Ekkill"                "Widowed")

 TYPE THjuSpurt =  (ógiftur       "Hefur ekki gifst"      "Single",
                    giftur        "gift^ur"                "Married",
                    staðfest      "Í staðfestri samvist"   "Registered partnership",
                    sambúð        "Í skráðri sambúð"       "Registered as a couple in consensual union",
                    óskráðsambúð  "Í ó-skráðri sambúð"     "Un-registered as a couple in consensual union",
                    skilinn       "Fráskilin^n"            "Divorced",
                    ekkill        "^Ekkill"                "Widowed")

 TYPE TSkóli = (
     skóli                           "í skóla"                   "Attending school ",
     námssamningur                   "á námssamningi"            "In apprenticeship",
     námskeið                        "á námskeiði"               "Taking a course",
     ráðstefna                       "á ráðstefnu, fyrirlestri"  "In a conference",
     ekkert                      (9) "EKKERT AF ÞESSU"           "NONE OF ABOVE")

 TYPE TSkóli2 = (
     skóli                           "í skóla"                   "Attending school ",
     námssamningur                   "á námssamningi"            "In apprenticeship",
     ekkert                      (9) "HVORUGT"                   "NEITHER")

 TYPE TSkóli2b = (
           skóli                           "í skóla"                    "Attending school ",
           námssamningur                   "á námssamningi"             "In apprenticeship",
           bæði                            "bæði í skóla og á samningi" "Both in school and in apprenticeship",
           SamiSkóli                       "^sama_og_síðast"            "^same_as_last_time",
           ekkert                      (9) "Hvorki í skóla né á námssamningi"                    "NEITHER")

 TYPE TFræðsla = (
     námskeið                       "námskeið"                      "course",
     ráðstefna                      "ráðstefnu"                     "conference",
     málþing                        "málþing"                       "seminar",
     fyrirlestur                    "fyrirlestur"                   "lecture",
     annað                          "aðra fræðslu með leiðbeinanda" "other taught activity",
     ekkert                     (9) "EKKERT AF ÞESSU"               "NONE OF ABOVE")

 TYPE THmFj = 0..15

 TYPE THmFjB = (t0 (0) "Ekki einkaheimili", t1 " ", t2 " ", t3 " ", t4 " ", t5 " ", t6 " ", t7 " ", t8 " ",
                t9 " ", t10 " ", t11 " ", t12 " ", t13 " ", t14 " ", t15 " ")

 TYPE TTengsl = (
         Sjálfur  (0)   " " " ",
         Maki           "Maki"
                        "Spouse",
         Barn           "Barn (svaranda og/eða maka) (eða fósturbarn)"
                        "Child (own or spouse's)",
         Systkini       "Systkini"
                        "Sibling",
         Systkinabarn   "Systkinabarn"
                        "Child of sibling",
         Foreldri       "Foreldri"
                        "Parent",
         AfiAmma        "Afi/amma"
                        "Grandparent",
         Tengdaforeldri "Tengdaforeldri"
                        "Parent in law",
         Tengdabarn     "Tengdabarn"
                        "Child in law",
         Mágur          "Mágur, mágkona, svili, svilkona"
                        "Sister or brother in law",
         Barnabarn      "Barnabarn"
                        "Grandchild",
         Ættingi        "Annar ættingi"
                        "Another relative",
         Óskyldur       "Óskyldur"
                        "Not related")

 TYPE THvenær = (
        SíðastaVika     "Í síðustu viku"
                        "In the last week",
        SíðastaMánuð    "Á síðustu fjórum vikum"
                        "During last four weeks",
        SíðastaÁr       "Fyrr"
                        "During last twelve months")
 {Vegna fyrri svara}
 TYPE TIÁstæða = (
        Uppsögn,
        TímabundiðStarf,
        Verkefnaskortur,
        Menntun,
        Fæðingarorlof,
        SinnaBörnum,
        Eftirlaun,
        Veikindi,
        Annað)

 TYPE TFsv_Status = (
        í_vinnu (11),
        frá_vinnu,
        frá_vinnu_fæðingarorlof,
        skyldulið,
        reynsla_aldur (21),
        reynsla_skóli,
        reynsla_vinnuvilji,
        reynsla_annað,
        ekki_reynsla_aldur (31),
        ekki_reynsla_skóli,
        ekki_reynsla_vinnuvilji,
        ekki_reynsla_annað,
        engin_fyrrisvör (99))


 TYPE TFsv_sama = (
       Já           "Já"                            "Yes",
       Nei          "Nei"                           "No",
       JáAnnaðStarf "Sama fyrirtæki, nýtt starf"    "Same firm, different job",
       JáAnnaðFirma "Sama starf, nýtt fyrirtæki"    "Same job, new firm",
       SamaEnRangt  "Sama en rangt síðast"          "Same, but previous incorrect",
       AnnaðEnRangt "Annað starf en rangt síðast"   "Different job, but previous incorrect")

 TYPE TFsv_húsnæði_sama = (
       Já           "Já"                            "Yes",
       Nei          "Nei"                           "No",
       SamaEnRangt  "Sama húsnæði en rangt síðast"          "Same house, but previous incorrect",
       AnnaðEnRangt "Annað húsnæði en rangt síðast"   "Different house, but previous incorrect")

  TYPE TFsv_heilsa_sama = (
       Já           "Já"                            "Yes",
       Nei          "Nei"                           "No",
       SamaEnRangt  "Sama heilsufar en rangt síðast"          "Same health, but previous incorrect",
       AnnaðEnRangt "Annað heilsufar en rangt síðast"   "Different health, but previous incorrect")

 TYPE TSamiSkóli = (
        Já,
        Nei,
        Ekki_í_Skóla)

 TYPE TÁrtal = Integer[4]

 TYPE TLeiguár = 1900..2014

 Type Tártal50 = 1950..2050

 Type Tártal150 = 1900..2050

 Type TFæðÁr = 1890..2050

 Type TMánuðir = ( janúar     "janúar" "January",
                   febrúar    "febrúar" "February",
                   mars       "mars" "March",
                   apríl      "apríl" "April",
                   maí        "maí" "May",
                   júní       "júní" "June",
                   júlí       "júlí" "July",
                   ágúst      "ágúst" "August",
                   september  "september" "September",
                   október    "október" "October",
                   nóvember   "nóvember" "November",
                   desember   "desember" "December"
                  )

 Type TMánuðir_allt_árið = ( allt_árið (0) "allt árið" "all year",
                   janúar     "janúar" "January",
                   febrúar    "febrúar" "February",
                   mars       "mars" "March",
                   apríl      "apríl" "April",
                   maí        "maí" "May",
                   júní       "júní" "June",
                   júlí       "júlí" "July",
                   ágúst      "ágúst" "August",
                   september  "september" "September",
                   október    "október" "October",
                   nóvember   "nóvember" "November",
                   desember   "desember" "December"
                  )
 Type THlutfallYfir =(minnaen10 "Minna en 10%" "Less than ten percent",
                     meiraen10 "Meira en 10% og minna en einn þriðji" "More than ten percent and less than one third",
                     meiraen33 "Meira en einn þriðji og minna en 100%" "More than one third and less than 100 percent",
                     meiraen100 "Meira en 100%" "More than 100 percent")

 Type THjúsvar = (einhleyur "Einhleyp/ur - Ekkill/Ekkja - Fráskilin/n" "Single - Widowed - Divorced",
                  sambud "Í sambúð - Kvæntur/Gift - Í staðfestri samvist" "Cohabiting - Married - Registered relationship")

 Type TOfDyrt = (ofdyrt "Of dýrt" "To expensive",
                 annad "Af öðrum ástæðum" "Other reasons")

 Type TVidbrogd = (samth "Samþykkti strax þátttöku",
             nei   "Færðist undan þátttöku",
             frest "Bað um að fresta viðtali til síðari tíma",
             uppl  "Bað um frekari upplýsingar",
             annad "Annað"
             )
 TYPE TLeit = (Fannst,EkkertFannst)
