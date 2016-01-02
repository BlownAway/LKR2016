SELECT heiti,menntKodi,Stada,'K'+REPLACE(menntKodi,'.','') AS stuttheiti
FROM KONNUN_INS.dbo.Kotun_Menntun
WHERE Stada>0
ORDER BY menntKodi