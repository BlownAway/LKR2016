
SELECT heiti,svfKoti,Stada,CASE WHEN svfNr IS NOT NULL THEN 'K'+svfNr ELSE heiti END stuttheiti
FROM KONNUN_INS.dbo.Kotun_Sveit
WHERE Stada>0
ORDER BY svfKoti