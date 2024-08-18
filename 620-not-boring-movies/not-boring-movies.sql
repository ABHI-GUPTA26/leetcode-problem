# Write your MySQL query statement belowSELECT 
SELECT *
FROM 
Cinema 
WHERE 
ID%2 !=0 and description !="boring"
order by rating  desc;