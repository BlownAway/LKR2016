SELECT menntKodi,heiti
FROM KONNUN_INS.dbo.Kotun_Menntun
WHERE Stada=3 
UNION 
SELECT virkurKodi,heiti
FROM KONNUN_INS.dbo.Kotun_Menntun
WHERE Stada=0 