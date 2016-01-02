SELECT heiti,namKodi,Stada,'K'+REPLACE(namKodi,'.','') AS stuttheiti
FROM KONNUN_INS.dbo.Kotun_Nam
WHERE Stada>0 AND namKodi LIKE '3.3.%' AND heiti NOT LIKE '%skóli%'
ORDER BY namKodi