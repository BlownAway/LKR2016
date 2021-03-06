{   BlokkQ.inc
    SILC
    RJ (c) n�vember 2004
 }

EMBEDDED BLOCK BlokkQ "Sta�a � s��asta �ri"
  PARAMETERS
  IMPORT vi�mi�unardagur : datetype
  IMPORT pers�na         : TPers�na
  import aldur           : integer
  {import vinnandi        : TJ�Nei}
  { Merkja �arf a� minnsta kosti einu sinni vi� hvern m�nu� �rsins, annars er ekki h�gt a� halda �fram me� vi�tali�.}
  EMBEDDED BLOCK BAllt�ri�
      FIELDS
          Allt�ri�:(J�),empty
          Jan�ar,Febr�ar,Mars,Apr�l,Ma�,J�n�{,J�l�,�g�st,September,Okt�ber,N�vember,Desember}:(J�),empty
      RULES
          Allt�ri�
          IF (Allt�ri�<>J�) THEN
              Jan�ar Febr�ar Mars Apr�l Ma� J�n� {J�l� �g�st September Okt�ber N�vember Desember}
          ENDIF
  ENDBLOCK
  
  EMBEDDED TABLE BM�nu�ir 
      FIELDS
        AM�nFullt             "laun�egi � fullu starfi?" "working full time?" : BAllt�ri�
        AM�nHluta             "laun�egi � hlutastarfi?"  "working part time?" : BAllt�ri�
        AM�nSjalfst_fullt     "sj�lfst�tt starfandi � fullu starfi?" "full time self-employed?": BAllt�ri�
        AM�nSjalfst_hluta     "sj�lfst�tt starfandi � hlutastarfi?" "part time self-employed?" : BAllt�ri�
        AM�nAtvinnulaus       "atvinnulaus?" "unemployed?": BAllt�ri�
        AM�nF��ingarorlof     "� f��ingarorlofi?" "on maternity / paternity leave?": BAllt�ri�
        AM�nN�mi              "� n�mi?" "studying?": BAllt�ri�
        AM�nEllilifeyrir      "ellil�feyris�egi?" "receiving old age pension?": BAllt�ri�
        AM�n�rorkulifeyrir    "�rorkul�feyris�egi?" "receiving disability pension?": BAllt�ri�
        AM�nHeimavinnandi     "heimavinnandi?" "Home working": BAllt�ri�
        AM�nVeikur            "veik^ur?" "sick or unable to work?": BAllt�ri�
        AM�nAnna�             "a� gera eitthva� anna�?" "doing something else?": BAllt�ri�
      RULES
        if A�ri�.cardinal > 1 then
          if starfandi in A�ri� then
              AM�nFullt
          endif
          if �_hlutastarfi in A�ri� then
              AM�nHluta
          endif
          if �_f��ingarorlofi in A�ri� then
              AM�nF��ingarorlof
          endif
          if atvinnulaus in A�ri� then
              AM�nAtvinnulaus
          endif
          if �_n�mi in A�ri� then
              AM�nN�mi
          endif
          if sjalfst_fullt in A�ri� then
              AM�nSjalfst_fullt     
          endif
          if sjalfst_hluta in A�ri� then
              AM�nSjalfst_hluta
          endif
          if ellilifeyrir in A�ri� then
              AM�nEllilifeyrir
          endif
          if ororkulifeyrir in A�ri� then
              AM�n�rorkulifeyrir
          endif
          if heimavinnandi in A�ri� then
              AM�nHeimavinnandi
          endif
          if veikur in A�ri� then
              AM�nVeikur
          endif
          if anna� in A�ri� then
              AM�nAnna�
          endif
        endif
   ENDBLOCK

   FIELDS
      
      A�ri� (E02)  {SILC spurning}
        "N� �tla �g a� spyrja �ig um st��u ^��na s��asta �r, fr� jan�ar til desember.
         �g vil bi�ja �ig um a� nefna allt sem �tti vi� um ^�ig � s��asta �ri,
         jafnvel ��tt �a� hafi bara veri� � stuttan t�ma.
         Var^stu ...
   @/@/@GEf vefst fyrir svaranda a� greina � milli, �� telst hann vera
         � fullu starfi ef hann vinnur 35 klukkustundir e�a meira � viku annars � hlutastarfi.@G
   @/@/@GMuni� a� setja - � milli valkosta ef �i� noti� lyklabor�i�.@G
   @/@/@GSpyrlar, ef vi�komandi segist vera � milli starfa f�i� �� n�nari �tsk�ringu � �v�.@G"

        "Now I will ask about ^your status over the course of last year, from january to december.
         In what position were ^you?
   @/@/@GEf vefst fyrir svaranda a� greina � milli, �� telst hann vera
         � fullu starfi ef hann vinnur 35 klukkustundir e�a meira � viku annars � hlutastarfi.@G
   @/@/@GMuni� a� setja - � milli valkosta ef �i� noti� lyklabor�i�.@G
   @/@/@GSpyrlar, ef vi�komandi segist vera � milli starfa f�i� �� n�nari �tsk�ringu � �v�.@G"
        /"Sta�a � �rinu"
        : SET OF (starfandi        (11) "Laun�egi � fullu starfi" "Full time employment",
                  �_hlutastarfi    (12) "Laun�egi � hlutastarfi"  "Part time employment",
                  sjalfst_fullt    (13) "Sj�lfst�tt starfandi � fullu starfi" "Full time self-employed",  {n�tt fyrir SILC2010; A�K 13.01.10}
                  sjalfst_hluta    (14) "Sj�lfst�tt starfandi � hlutastarfi" "Part time self-employed",   {n�tt fyrir SILC2010; A�K 13.01.10}
                  atvinnulaus      (15) "atvinnulaus" "Unemployed",
                  �_f��ingarorlofi (16)  "^orlof" "^orlof_en",
                  �_n�mi           (17) "� n�mi" "In education",
                 {l�feyris�egi (6) "elli- e�a �rorkul�feyris�egi" "Pensioner, old age or disability allowance",}  {teki� �r �r SILC2010; A�K 04.02.10}
                  ellilifeyrir      (18) "^ellilif" "^ellilif_en",  {n�tt fyrir SILC2010; A�K 04.02.10}
                  ororkulifeyrir    (19) "�rorkul�feyris�egi" "Did you receive disability pension?",{n�tt fyrir SILC2010; A�K 04.02.10}
                  heimavinnandi     (20)  "heimavinnandi" "working at home?",
                  veikur            (21) "Veik^ur" "Ill (unable to work)",
                  anna�             (22) "anna�" "Other")
      Am�nu�ir:Bm�nu�ir 
AUXFIELDS
  ��   : (karl2p "��",kona2p "��",karl3p "hann",kona3p "h�n",�v�st3p "hann/h�n")
   ��na :(karl2p "��na",kona2p "��na",karl3p "hans",kona3p "hennar",�v�st3p "hans/hennar")
   �ig  :(karl2p "�ig",kona2p "�ig",karl3p "hann",kona3p "hann",�v�st3p "hann/hana")
   stu  :(karl2p "stu",kona2p "stu",karl3p "�hann",kona3p "�h�n",�v�st3p "�hann/h�n")
   your : (karl2p "your",kona2p "your",karl3p "his",kona3p "her",�v�st3p "his/her")
  you :  (karl2p "you",kona2p "you",karl3p "he",kona3p "she",�v�st3p "he/she")
  {��rHonum : (karl2p "��r",kona2p "��r",karl3p "honum",kona3p "henni",�v�st3p "honum/henni")
  �inni    : (karl2p "�inni",kona2p "�inni", karl3p"hans",kona3p "hennar",�v�st3p "hans/hennar")
  �itt     : (karl2p "�itt",kona2p "�itt", karl3p "hans",kona3p "hennar",�v�st3p "hans/hennar")
  ��num :(karl2p "��num",kona2p "��num",karl3p "hans",kona3p "hennar",�v�st3p "hans/hennar")
  ere : (karl2p "ere",kona2p "ere",karl3p "as",kona3p "as",�v�st3p "as")
  st  :(karl2p "st",kona2p "st",karl3p "�hann",kona3p "�h�n",�v�st3p "�hann/h�n")
  n : (karl2p "n",kona2p " ",karl3p "n",kona3p " ", �v�st3p "/n")
  r : (karl2p "r",kona2p "r",karl3p " ",kona3p " ", �v�st3p " ")
  �u   :(karl2p "� ��",kona2p "� ��",karl3p " hann",kona3p " h�n",�v�st3p " hann/h�n")
  do_you : (karl2p "do you",kona2p "do you",karl3p "does he",kona3p "does she",�v�st3p "does he/she")
  �inn   :(karl2p "�inn",kona2p "�inn",karl3p "hans",kona3p "hennar",�v�st3p "hans/hennar")
  ��r  :    (karl2p "��r",kona2p "��r",karl3p "s�r",kona3p "s�r",�v�st3p "s�r")
  ur: (karl2p "ur",kona2p " ",karl3p "ur",kona3p " ",�v�st3p "(ur)")}
  
LOCALS
    �rsins,last_year,�_s��asta_�ri:STRING
    ellilif : string
    ellilif_en : string
    orlof:string
    orlof_en:string
RULES
  ��    :=pers�na.ord
  ��na  := pers�na.ord
  �ig   :=pers�na.ord
  stu   :=pers�na.ord
  you   :=pers�na.ord
  your  :=pers�na.ord
  {��rHonum := pers�na.ord
  �inni := pers�na.ord
  �itt  :=pers�na.ord
  ere   :=pers�na.ord
  st   :=pers�na.ord
  n     :=pers�na.ord
  r     :=pers�na.ord
  �u    :=pers�na.ord
  do_you:=pers�na.ord
  �inn :=pers�na.ord
  ��r  :=pers�na.ord
  ur   :=pers�na.ord}

  �rsins := '�ri� '+STR(YEAR(vi�mi�unardagur))
  �_s��asta_�ri:=�rsins
  last_year:='in ' +STR(YEAR(vi�mi�unardagur))

  if aldur > 59 then ellilif := 'Ellil�feyris�egi'
                     ellilif_en := 'Did you receive old-age pension?'
  elseif aldur < 60 then ellilif := ''
                         ellilif_en := ''
  endif
  if aldur > 59 then orlof:= ''
                     orlof_en := ''
  elseif aldur < 60 then orlof := '� f��ingarorlofi'
                         orlof_en := 'On maternity / paternity leave'
  endif

  A�ri�

  { signal
  if (�_n�mi in A�ri�) then (A�ri�.cardinal > 1) "Varstu � n�mi alla 12 m�nu�i �rsins, l�ka sumarm�nu�ina? @/@GSpyrill lagar svari� ef svarandi lei�r�ttir sig@G" endif

  if A�ri�.cardinal > 1 then
    if starfandi in A�ri� then
      AM�nu�ir_fullt
      check
      if allt_�ri� in AM�nu�ir_fullt then AM�nu�ir_fullt.cardinal = 1 "ekki er h�gt a� velja 'allt �ri�' me� ��rum kostum" endif
    endif
    if �_hlutastarfi in A�ri� then
      AM�nu�ir_hluta
      check
      if allt_�ri� in AM�nu�ir_hluta then AM�nu�ir_hluta.cardinal = 1 "ekki er h�gt a� velja 'allt �ri�' me� ��rum kostum" endif
    endif
    if �_f��ingarorlofi in A�ri� then
      AM�nu�ir_f��ingarorlof
      check
      if allt_�ri� in AM�nu�ir_f��ingarorlof then AM�nu�ir_f��ingarorlof.cardinal = 1 "ekki er h�gt a� velja 'allt �ri�' me� ��rum kostum" endif
    endif
    if atvinnulaus in A�ri� then
      AM�nu�ir_atvinnulaus
      check
      if allt_�ri� in AM�nu�ir_atvinnulaus then AM�nu�ir_atvinnulaus.cardinal = 1 "ekki er h�gt a� velja 'allt �ri�' me� ��rum kostum" endif
    endif
    if �_n�mi in A�ri� then
      AM�nu�ir_n�mi
      check
      if allt_�ri� in AM�nu�ir_n�mi then AM�nu�ir_n�mi.cardinal = 1 "ekki er h�gt a� velja 'allt �ri�' me� ��rum kostum" endif
      signal
      if (allt_�ri� in AM�nu�ir_n�mi) or (AM�nu�ir_n�mi.cardinal = 12) then not ((allt_�ri� in AM�nu�ir_n�mi) or (AM�nu�ir_n�mi.cardinal = 12) ) "Varstu � n�mi alla 12 m�nu�i �rsins, l�ka sumarm�nu�ina?" endif
    endif
    if sjalfst_fullt in A�ri� then
      at_ful
      check
      if allt_�ri� in at_ful then at_ful.cardinal = 1 "ekki er h�gt a� velja 'allt �ri�' me� ��rum kostum" endif
    endif
    if sjalfst_hluta in A�ri� then
      at_hlu
      check
      if allt_�ri� in at_hlu then at_hlu.cardinal = 1 "ekki er h�gt a� velja 'allt �ri�' me� ��rum kostum" endif
    endif
    if ellilifeyrir in A�ri� then
      at_elli
      check
      if allt_�ri� in at_elli then at_elli.cardinal = 1 "ekki er h�gt a� velja 'allt �ri�' me� ��rum kostum" endif
    endif
    if ororkulifeyrir in A�ri� then
      at_oror
      check
      if allt_�ri� in at_oror then at_oror.cardinal = 1 "ekki er h�gt a� velja 'allt �ri�' me� ��rum kostum" endif
    endif
    if heimavinnandi in A�ri� then
      AM�nu�ir_heimavinnandi
      check
      if allt_�ri� in AM�nu�ir_heimavinnandi then AM�nu�ir_heimavinnandi.cardinal = 1 "ekki er h�gt a� velja 'allt �ri�' me� ��rum kostum" endif
    endif
    if veikur in A�ri� then
      AM�nu�ir_veikur
      check
      if allt_�ri� in AM�nu�ir_veikur then AM�nu�ir_veikur.cardinal = 1 "ekki er h�gt a� velja 'allt �ri�' me� ��rum kostum" endif
    endif
    if anna� in A�ri� then
      AM�nu�ir_anna�
      check
      if allt_�ri� in AM�nu�ir_anna� then AM�nu�ir_anna�.cardinal = 1 "ekki er h�gt a� velja 'allt �ri�' me� ��rum kostum" endif
    endif
   ENDIF
    if not (
     (allt_�ri� in AM�nu�ir_fullt) or (allt_�ri� in AM�nu�ir_hluta) or (allt_�ri� in AM�nu�ir_f��ingarorlof) or
     (allt_�ri� in AM�nu�ir_atvinnulaus) or (allt_�ri� in AM�nu�ir_n�mi) or (allt_�ri� in at_elli) or (allt_�ri� in at_oror) or
     (allt_�ri� in AM�nu�ir_heimavinnandi) or (allt_�ri� in AM�nu�ir_veikur) or (allt_�ri� in AM�nu�ir_anna�) or (allt_�ri� in at_ful) or (allt_�ri� in at_hlu)
           ) then
      jan := 0
      if (jan�ar in AM�nu�ir_fullt) then jan := 1 endif
      if (jan�ar in AM�nu�ir_hluta) then jan := jan + 1 endif
      if (jan�ar in AM�nu�ir_f��ingarorlof) then jan := jan + 1 endif
      if (jan�ar in AM�nu�ir_atvinnulaus) then jan := jan + 1 endif
      if (jan�ar in AM�nu�ir_n�mi) then jan := jan + 1 endif
      if (jan�ar in at_ful) then jan := jan + 1 endif
      if (jan�ar in at_hlu) then jan := jan + 1 endif
      if (jan�ar in at_elli) then jan := jan + 1 endif
      if (jan�ar in at_oror) then jan := jan + 1 endif
      if (jan�ar in AM�nu�ir_heimavinnandi) then jan := jan + 1 endif
      if (jan�ar in AM�nu�ir_veikur) then jan := jan + 1 endif
      if (jan�ar in AM�nu�ir_anna�) then jan := jan + 1 endif
      check
      if (A�ri�.cardinal > 1) involving ( AM�nu�ir_fullt, AM�nu�ir_hluta, AM�nu�ir_f��ingarorlof, AM�nu�ir_atvinnulaus,
                                      AM�nu�ir_n�mi, at_elli, at_oror,
                                      AM�nu�ir_heimavinnandi, AM�nu�ir_veikur, AM�nu�ir_anna�, at_ful, at_hlu)
      then ( jan >= 1 ) "jan�ar a� minnsta kosti eini sinni"
      endif

      feb := 0
      if (febr�ar in AM�nu�ir_fullt) then feb := 1 endif
      if (febr�ar in AM�nu�ir_hluta) then feb := feb + 1 endif
      if (febr�ar in AM�nu�ir_f��ingarorlof) then feb := feb + 1 endif
      if (febr�ar in AM�nu�ir_atvinnulaus) then feb := feb + 1 endif
      if (febr�ar in AM�nu�ir_n�mi) then feb := feb + 1 endif
      if (febr�ar in at_ful) then feb := feb + 1 endif
      if (febr�ar in at_hlu) then feb := feb + 1 endif
      if (febr�ar in at_elli) then feb := feb + 1 endif
      if (febr�ar in at_oror) then feb := feb + 1 endif
      if (febr�ar in AM�nu�ir_heimavinnandi) then feb := feb + 1 endif
      if (febr�ar in AM�nu�ir_veikur) then feb := feb + 1 endif
      if (febr�ar in AM�nu�ir_anna�) then feb := feb + 1 endif
      check
      if (A�ri�.cardinal > 1) involving ( AM�nu�ir_fullt, AM�nu�ir_hluta, AM�nu�ir_f��ingarorlof, AM�nu�ir_atvinnulaus,
                                      AM�nu�ir_n�mi, at_elli, at_oror,
                                      AM�nu�ir_heimavinnandi, AM�nu�ir_veikur, AM�nu�ir_anna�, at_ful, at_hlu)
      then ( feb >= 1 ) "febr�ar a� minnsta kosti eini sinni"
      endif

      mar := 0
      if (mars in AM�nu�ir_fullt) then mar := 1 endif
      if (mars in AM�nu�ir_hluta) then mar := mar + 1 endif
      if (mars in AM�nu�ir_f��ingarorlof) then mar := mar + 1 endif
      if (mars in AM�nu�ir_atvinnulaus) then mar := mar + 1 endif
      if (mars in AM�nu�ir_n�mi) then mar := mar + 1 endif
      if (mars in at_ful) then mar := mar + 1 endif
      if (mars in at_hlu) then mar := mar + 1 endif
      if (mars in at_elli) then mar := mar + 1 endif
      if (mars in at_oror) then mar := mar + 1 endif
      if (mars in AM�nu�ir_heimavinnandi) then mar := mar + 1 endif
      if (mars in AM�nu�ir_veikur) then mar := mar + 1 endif
      if (mars in AM�nu�ir_anna�) then mar := mar + 1 endif
      check
      if (A�ri�.cardinal > 1) involving ( AM�nu�ir_fullt, AM�nu�ir_hluta, AM�nu�ir_f��ingarorlof, AM�nu�ir_atvinnulaus,
                                      AM�nu�ir_n�mi, at_elli, at_oror,
                                      AM�nu�ir_heimavinnandi, AM�nu�ir_veikur, AM�nu�ir_anna�, at_ful, at_hlu)
      then ( mar >= 1 ) "mars a� minnsta kosti eini sinni"
      endif

      apr := 0
      if (apr�l in AM�nu�ir_fullt) then apr := 1 endif
      if (apr�l in AM�nu�ir_hluta) then apr := apr + 1 endif
      if (apr�l in AM�nu�ir_f��ingarorlof) then apr := apr + 1 endif
      if (apr�l in AM�nu�ir_atvinnulaus) then apr := apr + 1 endif
      if (apr�l in AM�nu�ir_n�mi) then apr := apr + 1 endif
      if (apr�l in at_ful) then apr := apr + 1 endif
      if (apr�l in at_hlu) then apr := apr + 1 endif
      if (apr�l in at_elli) then apr := apr + 1 endif
      if (apr�l in at_oror) then apr := apr + 1 endif
      if (apr�l in AM�nu�ir_heimavinnandi) then apr := apr + 1 endif
      if (apr�l in AM�nu�ir_veikur) then apr := apr + 1 endif
      if (apr�l in AM�nu�ir_anna�) then apr := apr + 1 endif
      check
      if (A�ri�.cardinal > 1) involving ( AM�nu�ir_fullt, AM�nu�ir_hluta, AM�nu�ir_f��ingarorlof, AM�nu�ir_atvinnulaus,
                                      AM�nu�ir_n�mi, at_elli, at_oror,
                                      AM�nu�ir_heimavinnandi, AM�nu�ir_veikur, AM�nu�ir_anna�, at_ful, at_hlu)
      then ( apr >= 1 ) "apr�l a� minnsta kosti eini sinni"
      endif

      ma�m�nu�ur := 0
      if (ma� in AM�nu�ir_fullt) then ma�m�nu�ur := 1 endif
      if (ma� in AM�nu�ir_hluta) then ma�m�nu�ur := ma�m�nu�ur + 1 endif
      if (ma� in AM�nu�ir_f��ingarorlof) then ma�m�nu�ur := ma�m�nu�ur + 1 endif
      if (ma� in AM�nu�ir_atvinnulaus) then ma�m�nu�ur := ma�m�nu�ur + 1 endif
      if (ma� in AM�nu�ir_n�mi) then ma�m�nu�ur := ma�m�nu�ur + 1 endif
      if (ma� in at_ful) then ma�m�nu�ur := ma�m�nu�ur + 1 endif
      if (ma� in at_hlu) then ma�m�nu�ur := ma�m�nu�ur + 1 endif
      if (ma� in at_elli) then ma�m�nu�ur := ma�m�nu�ur + 1 endif
      if (ma� in at_oror) then ma�m�nu�ur := ma�m�nu�ur + 1 endif
      if (ma� in AM�nu�ir_heimavinnandi) then ma�m�nu�ur := ma�m�nu�ur + 1 endif
      if (ma� in AM�nu�ir_veikur) then ma�m�nu�ur := ma�m�nu�ur + 1 endif
      if (ma� in AM�nu�ir_anna�) then ma�m�nu�ur := ma�m�nu�ur + 1 endif
      check
      if (A�ri�.cardinal > 1) involving ( AM�nu�ir_fullt, AM�nu�ir_hluta, AM�nu�ir_f��ingarorlof, AM�nu�ir_atvinnulaus,
                                      AM�nu�ir_n�mi, at_elli, at_oror,
                                      AM�nu�ir_heimavinnandi, AM�nu�ir_veikur, AM�nu�ir_anna�, at_ful, at_hlu)
      then ( ma�m�nu�ur >= 1 ) "ma� a� minnsta kosti eini sinni"
      endif

      j�n := 0
      if (j�n� in AM�nu�ir_fullt) then j�n := 1 endif
      if (j�n� in AM�nu�ir_hluta) then j�n := j�n + 1 endif
      if (j�n� in AM�nu�ir_f��ingarorlof) then j�n := j�n + 1 endif
      if (j�n� in AM�nu�ir_atvinnulaus) then j�n := j�n + 1 endif
      if (j�n� in AM�nu�ir_n�mi) then j�n := j�n + 1 endif
      if (j�n� in at_ful) then j�n := j�n + 1 endif
      if (j�n� in at_hlu) then j�n := j�n + 1 endif
      if (j�n� in at_elli) then j�n := j�n + 1 endif
      if (j�n� in at_oror) then j�n := j�n + 1 endif
      if (j�n� in AM�nu�ir_heimavinnandi) then j�n := j�n + 1 endif
      if (j�n� in AM�nu�ir_veikur) then j�n := j�n + 1 endif
      if (j�n� in AM�nu�ir_anna�) then j�n := j�n + 1 endif
      check
      if (A�ri�.cardinal > 1) involving ( AM�nu�ir_fullt, AM�nu�ir_hluta, AM�nu�ir_f��ingarorlof, AM�nu�ir_atvinnulaus,
                                      AM�nu�ir_n�mi, at_elli, at_oror,
                                      AM�nu�ir_heimavinnandi, AM�nu�ir_veikur, AM�nu�ir_anna�, at_ful, at_hlu)
      then ( j�n >= 1 ) "j�n� a� minnsta kosti eini sinni"
      endif

      j�l := 0
      if (j�l� in AM�nu�ir_fullt) then j�l := 1 endif
      if (j�l� in AM�nu�ir_hluta) then j�l := j�l + 1 endif
      if (j�l� in AM�nu�ir_f��ingarorlof) then j�l := j�l + 1 endif
      if (j�l� in AM�nu�ir_atvinnulaus) then j�l := j�l + 1 endif
      if (j�l� in AM�nu�ir_n�mi) then j�l := j�l + 1 endif
      if (j�l� in at_ful) then j�l := j�l + 1 endif
      if (j�l� in at_hlu) then j�l := j�l + 1 endif
      if (j�l� in at_elli) then j�l := j�l + 1 endif
      if (j�l� in at_oror) then j�l := j�l + 1 endif
      if (j�l� in AM�nu�ir_heimavinnandi) then j�l := j�l + 1 endif
      if (j�l� in AM�nu�ir_veikur) then j�l := j�l + 1 endif
      if (j�l� in AM�nu�ir_anna�) then j�l := j�l + 1 endif
      check
      if (A�ri�.cardinal > 1) involving ( AM�nu�ir_fullt, AM�nu�ir_hluta, AM�nu�ir_f��ingarorlof, AM�nu�ir_atvinnulaus,
                                      AM�nu�ir_n�mi, at_elli, at_oror,
                                      AM�nu�ir_heimavinnandi, AM�nu�ir_veikur, AM�nu�ir_anna�, at_ful, at_hlu)
      then ( j�l >= 1 ) "j�l� a� minnsta kosti eini sinni"
      endif

      �g� := 0
      if (�g�st in AM�nu�ir_fullt) then �g� := 1 endif
      if (�g�st in AM�nu�ir_hluta) then �g� := �g� + 1 endif
      if (�g�st in AM�nu�ir_f��ingarorlof) then �g� := �g� + 1 endif
      if (�g�st in AM�nu�ir_atvinnulaus) then �g� := �g� + 1 endif
      if (�g�st in AM�nu�ir_n�mi) then �g� := �g� + 1 endif
      if (�g�st in at_ful) then �g� := �g� + 1 endif
      if (�g�st in at_hlu) then �g� := �g� + 1 endif
      if (�g�st in at_elli) then �g� := �g� + 1 endif
      if (�g�st in at_oror) then �g� := �g� + 1 endif
      if (�g�st in AM�nu�ir_heimavinnandi) then �g� := �g� + 1 endif
      if (�g�st in AM�nu�ir_veikur) then �g� := �g� + 1 endif
      if (�g�st in AM�nu�ir_anna�) then �g� := �g� + 1 endif
      check
      if (A�ri�.cardinal > 1) involving ( AM�nu�ir_fullt, AM�nu�ir_hluta, AM�nu�ir_f��ingarorlof, AM�nu�ir_atvinnulaus,
                                      AM�nu�ir_n�mi, at_elli, at_oror,
                                      AM�nu�ir_heimavinnandi, AM�nu�ir_veikur, AM�nu�ir_anna�, at_ful, at_hlu)
      then ( �g� >= 1 ) "�g�st a� minnsta kosti eini sinni"
      endif

      sep := 0
      if (september in AM�nu�ir_fullt) then sep := 1 endif
      if (september in AM�nu�ir_hluta) then sep := sep + 1 endif
      if (september in AM�nu�ir_f��ingarorlof) then sep := sep + 1 endif
      if (september in AM�nu�ir_atvinnulaus) then sep := sep + 1 endif
      if (september in AM�nu�ir_n�mi) then sep := sep + 1 endif
      if (september in at_ful) then sep := sep + 1 endif
      if (september in at_hlu) then sep := sep + 1 endif
      if (september in at_elli) then sep := sep + 1 endif
      if (september in at_oror) then sep := sep + 1 endif
      if (september in AM�nu�ir_heimavinnandi) then sep := sep + 1 endif
      if (september in AM�nu�ir_veikur) then sep := sep + 1 endif
      if (september in AM�nu�ir_anna�) then sep := sep + 1 endif
      check
      if (A�ri�.cardinal > 1) involving ( AM�nu�ir_fullt, AM�nu�ir_hluta, AM�nu�ir_f��ingarorlof, AM�nu�ir_atvinnulaus,
                                      AM�nu�ir_n�mi, at_elli, at_oror,
                                      AM�nu�ir_heimavinnandi, AM�nu�ir_veikur, AM�nu�ir_anna�, at_ful, at_hlu)
      then ( sep >= 1 ) "september a� minnsta kosti eini sinni"
      endif

      okt := 0
      if (okt�ber in AM�nu�ir_fullt) then okt := 1 endif
      if (okt�ber in AM�nu�ir_hluta) then okt := okt + 1 endif
      if (okt�ber in AM�nu�ir_f��ingarorlof) then okt := okt + 1 endif
      if (okt�ber in AM�nu�ir_atvinnulaus) then okt := okt + 1 endif
      if (okt�ber in AM�nu�ir_n�mi) then okt := okt + 1 endif
      if (okt�ber in at_ful) then okt := okt + 1 endif
      if (okt�ber in at_hlu) then okt := okt + 1 endif
      if (okt�ber in at_elli) then okt := okt + 1 endif
      if (okt�ber in at_oror) then okt := okt + 1 endif
      if (okt�ber in AM�nu�ir_heimavinnandi) then okt := okt + 1 endif
      if (okt�ber in AM�nu�ir_veikur) then okt := okt + 1 endif
      if (okt�ber in AM�nu�ir_anna�) then okt := okt + 1 endif
      check
      if (A�ri�.cardinal > 1) involving ( AM�nu�ir_fullt, AM�nu�ir_hluta, AM�nu�ir_f��ingarorlof, AM�nu�ir_atvinnulaus,
                                      AM�nu�ir_n�mi, at_elli, at_oror,
                                      AM�nu�ir_heimavinnandi, AM�nu�ir_veikur, AM�nu�ir_anna�, at_ful, at_hlu)
      then ( okt >= 1 ) "okt�ber a� minnsta kosti eini sinni"
      endif

      n�v := 0
      if (n�vember in AM�nu�ir_fullt) then n�v := 1 endif
      if (n�vember in AM�nu�ir_hluta) then n�v := n�v + 1 endif
      if (n�vember in AM�nu�ir_f��ingarorlof) then n�v := n�v + 1 endif
      if (n�vember in AM�nu�ir_atvinnulaus) then n�v := n�v + 1 endif
      if (n�vember in AM�nu�ir_n�mi) then n�v := n�v + 1 endif
      if (n�vember in at_ful) then n�v := n�v + 1 endif
      if (n�vember in at_hlu) then n�v := n�v + 1 endif
      if (n�vember in at_elli) then n�v := n�v + 1 endif
      if (n�vember in at_oror) then n�v := n�v + 1 endif
      if (n�vember in AM�nu�ir_heimavinnandi) then n�v := n�v + 1 endif
      if (n�vember in AM�nu�ir_veikur) then n�v := n�v + 1 endif
      if (n�vember in AM�nu�ir_anna�) then n�v := n�v + 1 endif
      check
      if (A�ri�.cardinal > 1) involving ( AM�nu�ir_fullt, AM�nu�ir_hluta, AM�nu�ir_f��ingarorlof, AM�nu�ir_atvinnulaus,
                                      AM�nu�ir_n�mi, at_elli, at_oror,
                                      AM�nu�ir_heimavinnandi, AM�nu�ir_veikur, AM�nu�ir_anna�, at_ful, at_hlu)
      then ( n�v >= 1 ) "n�vember a� minnsta kosti eini sinni"
      endif

      des := 0
      if (desember in AM�nu�ir_fullt) then des := 1 endif
      if (desember in AM�nu�ir_hluta) then des := des + 1 endif
      if (desember in AM�nu�ir_f��ingarorlof) then des := des + 1 endif
      if (desember in AM�nu�ir_atvinnulaus) then des := des + 1 endif
      if (desember in AM�nu�ir_n�mi) then des := des + 1 endif
      if (desember in at_ful) then des := des + 1 endif
      if (desember in at_hlu) then des := des + 1 endif
      if (desember in at_elli) then des := des + 1 endif
      if (desember in at_oror) then des := des + 1 endif
      if (desember in AM�nu�ir_heimavinnandi) then des := des + 1 endif
      if (desember in AM�nu�ir_veikur) then des := des + 1 endif
      if (desember in AM�nu�ir_anna�) then des := des + 1 endif
      check
      if (A�ri�.cardinal > 1) involving ( AM�nu�ir_fullt, AM�nu�ir_hluta, AM�nu�ir_f��ingarorlof, AM�nu�ir_atvinnulaus,
                                      AM�nu�ir_n�mi, at_elli, at_oror,
                                      AM�nu�ir_heimavinnandi, AM�nu�ir_veikur, AM�nu�ir_anna�, at_ful, at_hlu)
      then ( des >= 1 ) "desember a� minnsta kosti eini sinni"
      endif

  endif {
      if not (
     (allt_�ri� in AM�nu�ir_fullt) or (allt_�ri� in AM�nu�ir_hluta) or (allt_�ri� in AM�nu�ir_f��ingarorlof) or
     (allt_�ri� in AM�nu�ir_atvinnulaus) or (allt_�ri� in AM�nu�ir_n�mi) or (allt_�ri� in AM�nu�ir_l�feyris�egi) or
     (allt_�ri� in AM�nu�ir_heimavinnandi) or (allt_�ri� in AM�nu�ir_veikur) or (allt_�ri� in AM�nu�ir_anna�)
           ) then
        }

  endif
  IF ((�_f��ingarorlofi in A�ri�) AND ((allt_�ri� in Am�nu�ir_f��ingarorlof) OR (jan�ar in Am�nu�ir_f��ingarorlof)))
        or ((�_f��ingarorlofi in A�ri�) AND (Am�nu�ir_f��ingarorlof = empty)) then f_faedin endif {N�tt fyrir SILC2010; A�K 08.02.2010}

    IF (starfandi in A�ri�) or (�_hlutastarfi in a�ri�) or (sjalfst_fullt in a�ri�) or (sjalfst_hluta in a�ri�) then Bskipta endif
    IF Bskipta = j�
        then B01
            IF B01 = anna�
                then B01annad
            endif
    endif

    al�feyrir
    IF Al�feyrir = j� THEN
    Asj��ur
        IF TR in Asj��ur THEN ATRM�n
        ENDIF
        IF LS in ASj��ur THEN ALSM�n
        ENDIF
            IF  ATRM�n <> empty or ALSM�n <> empty THEN
            AL�fTegund
            ENDIF
                If anna� in al�ftegund then
                AL�fAnna�
                ENDIF
    ENDIF

    {if (aldur >= 60) or (a.Aa�al = �ryrki) or (ellilifeyrir in A�ri�) or (ororkulifeyrir in A�ri�) then}  {04.02.10; Dettur �t t�mabundi� fyrir SILC2010}
      As�rfa
      if AS�rfa = j� then
        AS�rfaUpph��
        signal if (AS�rfaUpph�� = response) and (AS�rfaUpph�� > 500) then (AS�rfaUpph�� > 500) "Ertu viss um a� upph��in s� meira en fimm hundru� ��sund � m�nu�i ?" endif
        signal if (AS�rfaUpph�� = response) and (AS�rfaUpph�� < 5000) then (AS�rfaUpph�� < 5000) "Ertu viss um a� upph��in s� ekki � ��sundum ? H�n � a� vera � kr�num" endif
        if AS�rfaUpph�� = dk then As�rfaUpph��_gisk endif
      endif
{    endif}
    if vinnandi = j� then
      AS�rl�f
      if AS�rl�f = j� then
        AS�rl�fPr�sent
        if AS�rl�fPr�sent = dk then
          AS�rl�fPr�sent_gisk
        endif
      endif
    endif

    IF �_n�mi IN a�ri�
    THEN Namslan
    ENDIF
    IF namslan = j�
    THEN namsl_upph
         {namslan_man}
    ENDIF

 }

 ENDBLOCK
