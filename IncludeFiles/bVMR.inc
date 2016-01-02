{bVMR.inc}

BLOCK bVMR "Lífskjaraspurningar"
  PARAMETERS
    IMPORT
      AllarSpurningar     : TJáNei
      viğmiğunardagur     : datetype
      FæğÁr               : integer
      persóna             : tPersóna
      heimili             : tJáNei
      nafn                : String
      XKyn                : Tkyn
      FyrraHmnr           : integer { Númer heimilismanns í fyrri könnun, notağ til ağ finna fyrri svör }
      Aldur               : integer {aldur şátttakanda}

  INCLUDE "IncludeFiles\BlokkA.inc"
  INCLUDE "IncludeFiles\BlokkB.inc"
  INCLUDE "IncludeFiles\BlokkC.inc" {Tímabundin ráğning}
  INCLUDE "IncludeFiles\BlokkD.inc"
  INCLUDE "IncludeFiles\BlokkGb.inc"  {Vinnutími í aukastörfum}
  INCLUDE "IncludeFiles\BlokkGD.inc"  {Skammur vinnutími}
  INCLUDE "IncludeFiles\BlokkI.inc" {Hefurğu veriğ á vinnumarkaği}
  INCLUDE "IncludeFiles\BlokkJ.inc"  {varstu launşegi o.s.frv.}
  INCLUDE "IncludeFiles\BlokkK.inc"  {Atvinnuleit atvinnulausra}
  INCLUDE "IncludeFiles\BlokkO.inc" {Varstu í námi}
  INCLUDE "IncludeFiles\BlokkP.inc"
  INCLUDE "IncludeFiles\BlokkQ.inc" {Stağa á síğasta ári}


  FIELDS
    A  : BLOKKA
    B  : BLOKKB
    C  : BLOKKC
    D  : BLOKKD
    Gb : BLOKKGb
    Gd : BLOKKGd
    I  : BLOKKI
    J  : BLOKKJ
    K  : BLOKKK
    O  : BLOKKO
    P  : BLOKKP
    Q  : BLOKKQ {Stağa á síğasta ári}



AUXFIELDS
    {Færibreytur}
    spurtUmStarf : TJáNei
    spurtUmFirma : TJáNei
    Skylduliğ : TJáNei
    HófStörf : DateType
    Vinnandi : TJáNei
    Status : TStatus
    LeitStatus : TStatus
    Fjarverandi : TJáNei
    TvöStörf : TJáNei
    Leitarağvinnu : TJáNei
    Skrá : TJáNei
    HætturÍStarfi : TJáNei
    VinnaFundin : TJáNei
    LeitarAğAukastarfi : TJáNei
    SpurtUmÓskatíma : TJáNei
    Jağarvinna : TJáNei
    Fyrirtæki : String[50]
    Fjarvera : TFjarvera
    VinnandiSíğustuFjórarVikur : TJáNei
    HvenærHættur : DateType
    Stağa : TStağa
    Menntun : TGMenntun
    Skólakóti : TNam
    SkóliíSíğustuViku : TJáNei
    vaktavinna : TJáNei
    virkur : TJáNei
    SamiSkóli : TSamiSkóli
    ekkiávinnumarkaği :TJáNei
    NöfnHeimilisfólks : STRING [31]
    FulltStarf : TJáNei
    StarfağLengi : Integer
    BStağur_string : string
    BAKóti_string : string
    BSKóti_string : string
    GStağur_string : string
    GAKóti_string : string
    GSKóti_string : string
    JStağur_string : string
    JAKóti_string : string
    JSKóti_string : string
    PKóti_string : string
    aağal_b: tstağa

    AFjarvst_b : TJáNeiAFjarvst

  LOCALS
    şína, ğu, ur, r, n, stu, tu, şú, şitt, şig, şinn, şig_hann_hana, st, ğ, ggamall, tokstu, fekkstu, haettirdu, skiptirdu, şinni, fórstu : string
    you, do_you, your, are, were, have, radinn, skipulagdi, ferdthu, sjalf_ur, thu_vaerir   : STRING
    şremur, three :Integer
    do_, you_, yourself: string
    şínum, şínum_hans_hennar               : string
    Áttu, şér, hhann : string
    şín, şúgast, störfumşínum, heilsuşína, şérhonum, gæti, for_med: string

  RULES
    prc_ŞúHannHún      (Persóna, hhann)
    prc_şínaHansHennar (Persóna, şína)
    prc_ğuEnding       (Persóna, ğu)
    prc_stuEnding      (persóna, stu)
    prc_tuEnding       (persóna, tu)
    prc_rEnding        (persóna, r)
    prc_urEnding       (persóna, ur)
    prc_nEnding        (persóna, n)
    prc_ferdthu        (persóna, ferdthu)
    prc_şúHannHún      (persóna, şú)
    prc_şigsig         (Persóna, şig)
    prc_şighannhana    (persóna, şig_hann_hana)
    prc_ŞittHansHennar (persóna, şitt)
    prc_ŞínumHansHennar (Persóna, şínum_hans_hennar)
    prc_ŞinnHansHennar (persóna, şinn)
    prc_ttuEnding      (persóna, Áttu)
    prc_ŞérSér         (Persóna, şér)
    prc_ŞínHansHennar (persóna, şín)
    prc_ŞúGast (persóna, şúgast)
    prc_StörfumŞínum (persóna, störfumşínum)
    prc_HeilsuŞína (persóna, heilsuşína)
    prc_ŞérHonumHenni (persóna, şérhonum)
    prc_stEnding      (persóna, st)
    prc_ğEnding       (persóna, ğ)
    prc_ggamall       (persóna, ggamall)
    prc_tokstu         (persóna, tokstu)
    prc_fekkstu        (persóna, fekkstu)
    prc_haettirdu      (persóna, haettirdu)
    prc_skiptirdu      (persóna, skiptirdu)
    prc_şinni          (persóna, şinni)
    prc_fórstu         (persóna, fórstu)
    prc_şínum          (persóna, şínum)
    prc_Gaeti          (persóna, gæti)
    prc_radin_radinn   (persóna, radinn)
    prc_skipulagdi_hann_hun_thu (persóna, skipulagdi)
    prc_for_hann_hun_thu    (persóna, for_med)
    prc_sjalf_ur        (persóna, sjalf_ur)
    prc_thu_vaerir      (persóna, thu_vaerir)
    prc_YouHeShe       (persóna, you)
    prc_YouHimHer       (persóna, you_)
    prc_YouDoDoes      (persóna, do_you)
    prc_YourHisHer     (persóna, your)
    prc_WereWas        (persóna, were)
    prc_DoDoes          (persóna, do_)
    prc_AreIs          (persóna, are)
    prc_HaveHas        (persóna, have)
    prc_YourselfHimselfHerself      (persóna, yourself)
    Jağarvinna := Nei
    SpurtUmÓskatíma := Nei

    A (AllarSpurningar, viğmiğunardagur, TvöStörf, Vinnandi, Fjarverandi, Vaktavinna, aağal_b, AFjarvst_b)

    IF vinnandi = Nei THEN
      I (AllarSpurningar, persóna, heimili, Vinnandi, VinnandiSíğustuFjórarVikur, HvenærHættur)
    ENDIF
    vinnandi.show

    IF Vinnandi = Já THEN
        spurtumfirma := já
        spurtumstarf := já
        b  (AllarSpurningar, spurtUmFirma, spurtUmStarf, tvöstörf, skylduliğ, Status, Fyrirtæki)
        IF spurtUmFirma = Já THEN
          c
        ENDIF
      IF spurtUmFirma = Nei THEN
        Jağarvinna := Nei
      ENDIF

      d  (persóna, tvöstörf)
      IF TvöStörf = Já THEN
          IF (A.Astarf2 = já) THEN
            Gb
          ENDIF
      ENDIF
      Gd (AllarSpurningar,  persóna, TvöStörf)
    ENDIF { Vinnandi = Já }

    IF Vinnandi = Nei and I.IReynsla = Já THEN
        spurtUmFirma := Já
        spurtUmStarf := Já
        J (AllarSpurningar)
    ENDIF {Vinnandi = Nei and I.IReynsla = Já {And HvenærHættur + (8,0,0) >= viğmiğunardagur }THEN }
    IF (aağal_b IN  [námsmağur,aldur,öryrki,heimavinnandi,fæğingarorlof,atvinnulaus,veikindi,annağ])
        OR AFjarvst_b = nei
    THEN
        K (viğmiğunardagur, persóna)
    ENDIF
    O (viğmiğunardagur, FæğÁr, Menntun, Skólakóti)
    P (viğmiğunardagur, FæğÁr)
    Q (viğmiğunardagur, aldur, vinnandi)
ENDBLOCK
