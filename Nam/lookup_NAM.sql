SELECT namKodi,REPLACE(heiti,';','') AS heiti
FROM KONNUN_INS.dbo.Kotun_Nam
WHERE Stada=3 
UNION 
SELECT virkurKoti,REPLACE(heiti,';','') AS heiti
FROM KONNUN_INS.dbo.Kotun_Nam
WHERE Stada=0 