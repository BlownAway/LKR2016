{bVMR.inc}

BLOCK bVMR "L�fskjaraspurningar"
  PARAMETERS
    IMPORT
      AllarSpurningar     : TJ�Nei
      vi�mi�unardagur     : datetype
      F���r               : integer
      pers�na             : tPers�na
      heimili             : tJ�Nei
      nafn                : String
      XKyn                : Tkyn
      FyrraHmnr           : integer { N�mer heimilismanns � fyrri k�nnun, nota� til a� finna fyrri sv�r }
      Aldur               : integer {aldur ��tttakanda}

  INCLUDE "IncludeFiles\BlokkA.inc"
  INCLUDE "IncludeFiles\BlokkB.inc"
  INCLUDE "IncludeFiles\BlokkC.inc" {T�mabundin r��ning}
  INCLUDE "IncludeFiles\BlokkD.inc"
  INCLUDE "IncludeFiles\BlokkGb.inc"  {Vinnut�mi � aukast�rfum}
  INCLUDE "IncludeFiles\BlokkGD.inc"  {Skammur vinnut�mi}
  INCLUDE "IncludeFiles\BlokkI.inc" {Hefur�u veri� � vinnumarka�i}
  INCLUDE "IncludeFiles\BlokkJ.inc"  {varstu laun�egi o.s.frv.}
  INCLUDE "IncludeFiles\BlokkK.inc"  {Atvinnuleit atvinnulausra}
  INCLUDE "IncludeFiles\BlokkO.inc" {Varstu � n�mi}
  INCLUDE "IncludeFiles\BlokkP.inc"
  INCLUDE "IncludeFiles\BlokkQ.inc" {Sta�a � s��asta �ri}


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
    Q  : BLOKKQ {Sta�a � s��asta �ri}



AUXFIELDS
    {F�ribreytur}
    spurtUmStarf : TJ�Nei
    spurtUmFirma : TJ�Nei
    Skylduli� : TJ�Nei
    H�fSt�rf : DateType
    Vinnandi : TJ�Nei
    Status : TStatus
    LeitStatus : TStatus
    Fjarverandi : TJ�Nei
    Tv�St�rf : TJ�Nei
    Leitara�vinnu : TJ�Nei
    Skr� : TJ�Nei
    H�ttur�Starfi : TJ�Nei
    VinnaFundin : TJ�Nei
    LeitarA�Aukastarfi : TJ�Nei
    SpurtUm�skat�ma : TJ�Nei
    Ja�arvinna : TJ�Nei
    Fyrirt�ki : String[50]
    Fjarvera : TFjarvera
    VinnandiS��ustuFj�rarVikur : TJ�Nei
    Hven�rH�ttur : DateType
    Sta�a : TSta�a
    Menntun : TGMenntun
    Sk�lak�ti : TNam
    Sk�li�S��ustuViku : TJ�Nei
    vaktavinna : TJ�Nei
    virkur : TJ�Nei
    SamiSk�li : TSamiSk�li
    ekki�vinnumarka�i :TJ�Nei
    N�fnHeimilisf�lks : STRING [31]
    FulltStarf : TJ�Nei
    Starfa�Lengi : Integer
    BSta�ur_string : string
    BAK�ti_string : string
    BSK�ti_string : string
    GSta�ur_string : string
    GAK�ti_string : string
    GSK�ti_string : string
    JSta�ur_string : string
    JAK�ti_string : string
    JSK�ti_string : string
    PK�ti_string : string
    aa�al_b: tsta�a

    AFjarvst_b : TJ�NeiAFjarvst

  LOCALS
    ��na, �u, ur, r, n, stu, tu, ��, �itt, �ig, �inn, �ig_hann_hana, st, �, ggamall, tokstu, fekkstu, haettirdu, skiptirdu, �inni, f�rstu : string
    you, do_you, your, are, were, have, radinn, skipulagdi, ferdthu, sjalf_ur, thu_vaerir   : STRING
    �remur, three :Integer
    do_, you_, yourself: string
    ��num, ��num_hans_hennar               : string
    �ttu, ��r, hhann : string
    ��n, ��gast, st�rfum��num, heilsu��na, ��rhonum, g�ti, for_med: string

  RULES
    prc_��HannH�n      (Pers�na, hhann)
    prc_��naHansHennar (Pers�na, ��na)
    prc_�uEnding       (Pers�na, �u)
    prc_stuEnding      (pers�na, stu)
    prc_tuEnding       (pers�na, tu)
    prc_rEnding        (pers�na, r)
    prc_urEnding       (pers�na, ur)
    prc_nEnding        (pers�na, n)
    prc_ferdthu        (pers�na, ferdthu)
    prc_��HannH�n      (pers�na, ��)
    prc_�igsig         (Pers�na, �ig)
    prc_�ighannhana    (pers�na, �ig_hann_hana)
    prc_�ittHansHennar (pers�na, �itt)
    prc_��numHansHennar (Pers�na, ��num_hans_hennar)
    prc_�innHansHennar (pers�na, �inn)
    prc_ttuEnding      (pers�na, �ttu)
    prc_��rS�r         (Pers�na, ��r)
    prc_��nHansHennar (pers�na, ��n)
    prc_��Gast (pers�na, ��gast)
    prc_St�rfum��num (pers�na, st�rfum��num)
    prc_Heilsu��na (pers�na, heilsu��na)
    prc_��rHonumHenni (pers�na, ��rhonum)
    prc_stEnding      (pers�na, st)
    prc_�Ending       (pers�na, �)
    prc_ggamall       (pers�na, ggamall)
    prc_tokstu         (pers�na, tokstu)
    prc_fekkstu        (pers�na, fekkstu)
    prc_haettirdu      (pers�na, haettirdu)
    prc_skiptirdu      (pers�na, skiptirdu)
    prc_�inni          (pers�na, �inni)
    prc_f�rstu         (pers�na, f�rstu)
    prc_��num          (pers�na, ��num)
    prc_Gaeti          (pers�na, g�ti)
    prc_radin_radinn   (pers�na, radinn)
    prc_skipulagdi_hann_hun_thu (pers�na, skipulagdi)
    prc_for_hann_hun_thu    (pers�na, for_med)
    prc_sjalf_ur        (pers�na, sjalf_ur)
    prc_thu_vaerir      (pers�na, thu_vaerir)
    prc_YouHeShe       (pers�na, you)
    prc_YouHimHer       (pers�na, you_)
    prc_YouDoDoes      (pers�na, do_you)
    prc_YourHisHer     (pers�na, your)
    prc_WereWas        (pers�na, were)
    prc_DoDoes          (pers�na, do_)
    prc_AreIs          (pers�na, are)
    prc_HaveHas        (pers�na, have)
    prc_YourselfHimselfHerself      (pers�na, yourself)
    Ja�arvinna := Nei
    SpurtUm�skat�ma := Nei

    A (AllarSpurningar, vi�mi�unardagur, Tv�St�rf, Vinnandi, Fjarverandi, Vaktavinna, aa�al_b, AFjarvst_b)

    IF vinnandi = Nei THEN
      I (AllarSpurningar, pers�na, heimili, Vinnandi, VinnandiS��ustuFj�rarVikur, Hven�rH�ttur)
    ENDIF
    vinnandi.show

    IF Vinnandi = J� THEN
        spurtumfirma := j�
        spurtumstarf := j�
        b  (AllarSpurningar, spurtUmFirma, spurtUmStarf, tv�st�rf, skylduli�, Status, Fyrirt�ki)
        IF spurtUmFirma = J� THEN
          c
        ENDIF
      IF spurtUmFirma = Nei THEN
        Ja�arvinna := Nei
      ENDIF

      d  (pers�na, tv�st�rf)
      IF Tv�St�rf = J� THEN
          IF (A.Astarf2 = j�) THEN
            Gb
          ENDIF
      ENDIF
      Gd (AllarSpurningar,  pers�na, Tv�St�rf)
    ENDIF { Vinnandi = J� }

    IF Vinnandi = Nei and I.IReynsla = J� THEN
        spurtUmFirma := J�
        spurtUmStarf := J�
        J (AllarSpurningar)
    ENDIF {Vinnandi = Nei and I.IReynsla = J� {And Hven�rH�ttur + (8,0,0) >= vi�mi�unardagur }THEN }
    IF (aa�al_b IN  [n�msma�ur,aldur,�ryrki,heimavinnandi,f��ingarorlof,atvinnulaus,veikindi,anna�])
        OR AFjarvst_b = nei
    THEN
        K (vi�mi�unardagur, pers�na)
    ENDIF
    O (vi�mi�unardagur, F���r, Menntun, Sk�lak�ti)
    P (vi�mi�unardagur, F���r)
    Q (vi�mi�unardagur, aldur, vinnandi)
ENDBLOCK
