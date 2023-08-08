# Write your MySQL query statement below

select em.unique_id,e.name from EmployeeUNI em
RIGHT JOIN Employees e on e.id = em.id
GROUP BY e.id;
