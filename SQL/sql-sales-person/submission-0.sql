-- Write your query below
SELECT s.name
FROM sales_person AS s
WHERE sales_id NOT IN (
    SELECT sales_id
    FROM orders AS o
    JOIN company AS c ON o.com_id = c.com_id
    WHERE c.name = 'CRIMSON'
);