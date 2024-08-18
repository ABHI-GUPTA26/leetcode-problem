# Write your MySQL query statement below
SELECT e2.name as name
FROM Employee  e1
inner JOIN Employee  e2
ON e1.managerid = e2.id 
group by e1.managerId 
having count(e1.id)>=5;
;


