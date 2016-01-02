
SELECT heiti,fjvKoti,Stada,CASE WHEN fjvNr IS NULL THEN heiti ELSE 'K'+fjvNr END AS stuttheiti
FROM KONNUN_INS.dbo.Kotun_Fjarvera
ORDER BY fjvKoti