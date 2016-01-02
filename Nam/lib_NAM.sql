SELECT heiti,namKodi,Stada,'K'+REPLACE(namKodi,'.','') AS stuttheiti
FROM KONNUN_INS.dbo.Kotun_Nam
WHERE Stada>0
ORDER BY namKodi