# Write your MySQL query statement below
-- select v.customer_id,count(visit_id) as count_no_trans from visits as v left join transactions as t on v.visit_id=t.visit_id group by v.customer_id  having t.transaction_id is null; 

select v.customer_id,count(v.customer_id)  as count_no_trans
from Visits v
left join Transactions t
on v.visit_id=t.visit_id
where t.transaction_id is null
group by v.customer_id
