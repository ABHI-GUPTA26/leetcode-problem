# Write your MySQL query statement below
SELECT E.name ,B.bonus
FROM Employee as E  
LEFT JOIN  Bonus as B
 ON  E.empID =B.empid
where B.bonus<1000 or b.bonus is null;