# Write your MySQL query statement below
SELECT p.product_id ,ifnull(round(sum(units*price)/sum(units),2),0) as average_price

FROM Prices p
LEFT JOIN
UnitsSold U
on p.product_id=U.product_id 
-- group by
-- p.product_id
and  u.purchase_date between p.start_date and p.end_date
group  by p.product_id;

