SELECT stfKoti,heiti
FROM KONNUN_INS.dbo.Kotun_StFelag
WHERE Stada=2
UNION 
SELECT virkurKoti,heiti
FROM KONNUN_INS.dbo.Kotun_StFelag
WHERE Stada=0
