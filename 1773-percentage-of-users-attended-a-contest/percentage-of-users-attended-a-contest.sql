# Write your MySQL query statement below
SELECT r.contest_id ,round((count(r.user_id)/(select count(*)from users))*100,2) as percentage

FROM Register r
left join
Users u
on r.user_id=u.user_id
group by 
r.contest_id
order by count(*) desc,contest_id ;