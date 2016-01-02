SELECT svfKoti,heiti
FROM KONNUN_INS.dbo.Kotun_Sveit
WHERE Stada=3
UNION 
SELECT virkurKoti,heiti
FROM KONNUN_INS.dbo.Kotun_Sveit
WHERE Stada=0



