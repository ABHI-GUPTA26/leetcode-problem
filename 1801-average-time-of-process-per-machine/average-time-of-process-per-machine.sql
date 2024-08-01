# Write your MySQL query statement below
SELECT t1.machine_id ,round(avg(t2.timestamp-t1.timestamp),3) as processing_time
FROM Activity as t1 
INNER JOIN Activity as t2
 ON t1.machine_id=t2.machine_id
 AND t1.process_id=t2.process_id
 AND t1.timestamp<t2.timestamp 
 GROUP BY machine_id;