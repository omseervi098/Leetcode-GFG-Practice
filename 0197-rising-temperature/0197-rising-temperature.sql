# Write your MySQL query statement below
select w.id as Id from Weather w
INNER JOIN Weather w2 on DATEDIFF(w.recordDate,w2.recordDate)=1
WHERE w.temperature > w2.temperature;