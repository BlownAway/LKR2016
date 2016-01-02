
SELECT heiti,stfKoti,Stada,CASE WHEN StfNr IS NOT NULL THEN 'K'+StfNr ELSE heiti END stuttheiti
FROM KONNUN_INS.dbo.Kotun_StFelag
WHERE Stada>0
ORDER BY stfKoti