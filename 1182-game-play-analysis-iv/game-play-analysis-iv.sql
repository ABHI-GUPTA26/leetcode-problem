# Write your MySQL query statement below
select round(count(distinct t.player_id)/count(distinct a.player_id),2) as fraction
FROM Activity a 
left join 

(SELECT player_id,min(event_date) as event_date 
FROM Activity 
group by 
player_id) T
on a.player_id =t.player_id and
 DATE_SUB(a.event_date,interval 1 day)=t.event_date;