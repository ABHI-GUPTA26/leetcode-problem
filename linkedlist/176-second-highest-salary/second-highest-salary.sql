# Write your MySQL query statement below
-- select distinct(salary) as SecondHighestSalary from employee as e1 where 1 = (select count(*) from employee as e2 where e1.salary < e2.salary);

select max(salary) as SecondHighestSalary from employee where salary != (
    select max(salary) from employee
);