SELECT namKodi,REPLACE(heiti,';','') AS heiti
FROM KONNUN_INS.dbo.Kotun_Nam
WHERE Stada=3 AND namKodi LIKE '3.3.%' AND heiti NOT LIKE '%skóli%'
UNION 
SELECT virkurKoti,REPLACE(heiti,';','') AS heiti
FROM KONNUN_INS.dbo.Kotun_Nam
WHERE Stada=0 AND namKodi LIKE '3.3.%' AND heiti NOT LIKE '%skóli%'