# Write your MySQL query statement below
SELECT query_name,round(avg(rating/position),2) as quality,
round(avg(if(rating<3,1,0))*100,2) as poor_query_percentage

from Queries 
group by
query_name having query_name is not null ; 