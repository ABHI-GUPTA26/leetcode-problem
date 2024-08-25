# Write your MySQL query statement belowselect 
select
 CASE
   WHEN
   id=(select max(id) from seat) and mod(id,2)=1
   then
   id
   when
   mod(id,2)=1
   then
   id+1
   else
   id-1

 END
 as id ,student

from seat
order by id
