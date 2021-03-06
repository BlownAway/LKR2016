{   Types.inc
    Samfelld vinnumarka�sranns�kn
    �H (c) n�vember 2002}

 TYPE TStatus         = (
        Laun�egi                        "Laun�egi"             "Employee",
        Sj�lfst�tt                      "Sj�lfst�tt starfandi" "Self-employed",
        Hvorugt                         "Hvorugt"              "Neither")

 TYPE TKyn                = (
        karl                            "Karl" "Male",
        kona                            "Kona" "Female")

 TJ�Nei          = (
        J�                              "J�"  "Yes",
        Nei                             "Nei" "No")

 TYPE TJ�NeiJ�Ef          = (
        J�                              "J�"         "Yes",
        Nei                             "Nei"        "No",
        J�Ef                            "J�, ef ..." "Yes, if ...")

 TYPE TJ�NeiAFjarvst          = (
        J�                              "J�, var t�mabundi� fjarverandi" "Yes, was temporarily absent",
        Nei                             "Nei, er ekki � vinnu" "No, does not have a job")

 TYPE TSama    = (J�     "J�"                "Yes",
                  Nei    "Nei"               "No",
                  Rangt  "Fyrra svar rangt"  "Previous answer wrong")

 TYPE TPers�na = (karl         "1. pers�na, karl",
                  kona         "1. pers�na, kona",
                  annarKarl    "3. pers�na, karl",
                  annarKona    "3. pers�na, kona",
                  annar�v�st   "3. pers�na, kyn ��ekkt")

TYPE TT�mi = (t0 (0) " ", t1 " ", t2 " ", t3 " ", t4 " ", t5 " ", t6 " ", t7 " ", t8 " ", t9 " ", t10 " ",
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

 TYPE TSta�a = (
        ifullustarfi                    "starfandi � fullu starfi"
                                        "working in full time job",
        ihalfustarfi                    "starfandi � hlutastarfi"
                                        "working in part time job",
        n�msma�ur                       "n�msmann, e�a � n�mssamningi"
                                        "student",
        aldur                           "h�tta^n a� vinna vegna aldurs"
                                        "retired",
        �ryrki                          "�ryrkja e�a fatla�a^n"
                                        "disabled",
        heimavinnandi                   "heimavinnandi �n launa�rar vinnu"
                                        "homeworking",
        f��ingarorlof                   "� f��ingarorlofi"
                                        "in maternity/paternity leave",
        atvinnulaus                     "atvinnulausa^n"
                                        "unemployed",
        veikindi                        "veika^n e�a t�mabundi� �f�ra^n til vinnu"
                                        "ill or temporarily unable to work",
        anna�                           "anna�"
                                        "other")

 TYPE TGMenntun = (
        MinnaEnGrunnsk�li        (10)  "Ekki loki� grunnsk�lapr�fi",
        Grunnsk�li               (21)  "Grunnsk�lapr�f",
        St�dent                  (35)  "St�dentspr�f",
        Fyrrihlutapr�f           (53)  "Grunnpr�f �r h�sk�la")

 TYPE THju =       (�giftur       "Hefur ekki gifst"      "Single",
                    giftur        "gift^ur"                "Married",
                    samb��        "� �v�g�ri samb��"       "Cohabiting/living together",
                    skilinn       "Fr�skilin^n"            "Divorced",
                    ekkill        "^Ekkill"                "Widowed")

 TYPE THjuSpurt =  (�giftur       "Hefur ekki gifst"      "Single",
                    giftur        "gift^ur"                "Married",
                    sta�fest      "� sta�festri samvist"   "Registered partnership",
                    samb��        "� skr��ri samb��"       "Registered as a couple in consensual union",
                    �skr��samb��  "� �-skr��ri samb��"     "Un-registered as a couple in consensual union",
                    skilinn       "Fr�skilin^n"            "Divorced",
                    ekkill        "^Ekkill"                "Widowed")

 TYPE TSk�li = (
     sk�li                           "� sk�la"                   "Attending school ",
     n�mssamningur                   "� n�mssamningi"            "In apprenticeship",
     n�mskei�                        "� n�mskei�i"               "Taking a course",
     r��stefna                       "� r��stefnu, fyrirlestri"  "In a conference",
     ekkert                      (9) "EKKERT AF �ESSU"           "NONE OF ABOVE")

 TYPE TSk�li2 = (
     sk�li                           "� sk�la"                   "Attending school ",
     n�mssamningur                   "� n�mssamningi"            "In apprenticeship",
     ekkert                      (9) "HVORUGT"                   "NEITHER")

 TYPE TSk�li2b = (
           sk�li                           "� sk�la"                    "Attending school ",
           n�mssamningur                   "� n�mssamningi"             "In apprenticeship",
           b��i                            "b��i � sk�la og � samningi" "Both in school and in apprenticeship",
           SamiSk�li                       "^sama_og_s��ast"            "^same_as_last_time",
           ekkert                      (9) "Hvorki � sk�la n� � n�mssamningi"                    "NEITHER")

 TYPE TFr��sla = (
     n�mskei�                       "n�mskei�"                      "course",
     r��stefna                      "r��stefnu"                     "conference",
     m�l�ing                        "m�l�ing"                       "seminar",
     fyrirlestur                    "fyrirlestur"                   "lecture",
     anna�                          "a�ra fr��slu me� lei�beinanda" "other taught activity",
     ekkert                     (9) "EKKERT AF �ESSU"               "NONE OF ABOVE")

 TYPE THmFj = 0..15

 TYPE THmFjB = (t0 (0) "Ekki einkaheimili", t1 " ", t2 " ", t3 " ", t4 " ", t5 " ", t6 " ", t7 " ", t8 " ",
                t9 " ", t10 " ", t11 " ", t12 " ", t13 " ", t14 " ", t15 " ")

 TYPE TTengsl = (
         Sj�lfur  (0)   " " " ",
         Maki           "Maki"
                        "Spouse",
         Barn           "Barn (svaranda og/e�a maka) (e�a f�sturbarn)"
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
         M�gur          "M�gur, m�gkona, svili, svilkona"
                        "Sister or brother in law",
         Barnabarn      "Barnabarn"
                        "Grandchild",
         �ttingi        "Annar �ttingi"
                        "Another relative",
         �skyldur       "�skyldur"
                        "Not related")

 TYPE THven�r = (
        S��astaVika     "� s��ustu viku"
                        "In the last week",
        S��astaM�nu�    "� s��ustu fj�rum vikum"
                        "During last four weeks",
        S��asta�r       "Fyrr"
                        "During last twelve months")
 {Vegna fyrri svara}
 TYPE TI�st��a = (
        Upps�gn,
        T�mabundi�Starf,
        Verkefnaskortur,
        Menntun,
        F��ingarorlof,
        SinnaB�rnum,
        Eftirlaun,
        Veikindi,
        Anna�)

 TYPE TFsv_Status = (
        �_vinnu (11),
        fr�_vinnu,
        fr�_vinnu_f��ingarorlof,
        skylduli�,
        reynsla_aldur (21),
        reynsla_sk�li,
        reynsla_vinnuvilji,
        reynsla_anna�,
        ekki_reynsla_aldur (31),
        ekki_reynsla_sk�li,
        ekki_reynsla_vinnuvilji,
        ekki_reynsla_anna�,
        engin_fyrrisv�r (99))


 TYPE TFsv_sama = (
       J�           "J�"                            "Yes",
       Nei          "Nei"                           "No",
       J�Anna�Starf "Sama fyrirt�ki, n�tt starf"    "Same firm, different job",
       J�Anna�Firma "Sama starf, n�tt fyrirt�ki"    "Same job, new firm",
       SamaEnRangt  "Sama en rangt s��ast"          "Same, but previous incorrect",
       Anna�EnRangt "Anna� starf en rangt s��ast"   "Different job, but previous incorrect")

 TYPE TFsv_h�sn��i_sama = (
       J�           "J�"                            "Yes",
       Nei          "Nei"                           "No",
       SamaEnRangt  "Sama h�sn��i en rangt s��ast"          "Same house, but previous incorrect",
       Anna�EnRangt "Anna� h�sn��i en rangt s��ast"   "Different house, but previous incorrect")

  TYPE TFsv_heilsa_sama = (
       J�           "J�"                            "Yes",
       Nei          "Nei"                           "No",
       SamaEnRangt  "Sama heilsufar en rangt s��ast"          "Same health, but previous incorrect",
       Anna�EnRangt "Anna� heilsufar en rangt s��ast"   "Different health, but previous incorrect")

 TYPE TSamiSk�li = (
        J�,
        Nei,
        Ekki_�_Sk�la)

 TYPE T�rtal = Integer[4]

 TYPE TLeigu�r = 1900..2014

 Type T�rtal50 = 1950..2050

 Type T�rtal150 = 1900..2050

 Type TF���r = 1890..2050

 Type TM�nu�ir = ( jan�ar     "jan�ar" "January",
                   febr�ar    "febr�ar" "February",
                   mars       "mars" "March",
                   apr�l      "apr�l" "April",
                   ma�        "ma�" "May",
                   j�n�       "j�n�" "June",
                   j�l�       "j�l�" "July",
                   �g�st      "�g�st" "August",
                   september  "september" "September",
                   okt�ber    "okt�ber" "October",
                   n�vember   "n�vember" "November",
                   desember   "desember" "December"
                  )

 Type TM�nu�ir_allt_�ri� = ( allt_�ri� (0) "allt �ri�" "all year",
                   jan�ar     "jan�ar" "January",
                   febr�ar    "febr�ar" "February",
                   mars       "mars" "March",
                   apr�l      "apr�l" "April",
                   ma�        "ma�" "May",
                   j�n�       "j�n�" "June",
                   j�l�       "j�l�" "July",
                   �g�st      "�g�st" "August",
                   september  "september" "September",
                   okt�ber    "okt�ber" "October",
                   n�vember   "n�vember" "November",
                   desember   "desember" "December"
                  )
 Type THlutfallYfir =(minnaen10 "Minna en 10%" "Less than ten percent",
                     meiraen10 "Meira en 10% og minna en einn �ri�ji" "More than ten percent and less than one third",
                     meiraen33 "Meira en einn �ri�ji og minna en 100%" "More than one third and less than 100 percent",
                     meiraen100 "Meira en 100%" "More than 100 percent")

 Type THj�svar = (einhleyur "Einhleyp/ur - Ekkill/Ekkja - Fr�skilin/n" "Single - Widowed - Divorced",
                  sambud "� samb�� - Kv�ntur/Gift - � sta�festri samvist" "Cohabiting - Married - Registered relationship")

 Type TOfDyrt = (ofdyrt "Of d�rt" "To expensive",
                 annad "Af ��rum �st��um" "Other reasons")

 Type TVidbrogd = (samth "Sam�ykkti strax ��ttt�ku",
             nei   "F�r�ist undan ��ttt�ku",
             frest "Ba� um a� fresta vi�tali til s��ari t�ma",
             uppl  "Ba� um frekari uppl�singar",
             annad "Anna�"
             )
 TYPE TLeit = (Fannst,EkkertFannst)
