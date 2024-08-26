# Write your MySQL query statement below
(select  name as results
from Users as u
inner join 
MovieRating as r
on 
u.user_id=r.user_id
 group by r.user_id
 order by
 count(r.user_id) desc, 
 u.name asc limit 1)
 union all
 (select title as results
 from Movies m
 inner join
 MovieRating r
 on 
 m.movie_id=r.movie_id
 where month(r.created_at)=02 and year(r.created_at)=2020
 group by
 r.movie_id 
 order by avg(rating) desc,
 title asc limit 1)