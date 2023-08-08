# Write your MySQL query statement below
select v.customer_id, COUNT(v.customer_id) as count_no_trans  from Visits v
LEFT JOIN Transactions t on v.visit_id=t.visit_id
WHERE t.transaction_id is null
GROUP BY v.customer_id;
