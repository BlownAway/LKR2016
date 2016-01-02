SELECT fjvKoti,heiti
FROM KONNUN_INS.dbo.Kotun_Fjarvera
WHERE Stada=2
UNION 
SELECT virkurKoti,heiti
FROM KONNUN_INS.dbo.Kotun_Fjarvera
WHERE Stada=0
