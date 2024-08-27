# Write your MySQL query statement below
select p.product_name as product_name ,s.year as year  ,s.price as price 
from Sales s left join Product p on p.product_id=s.product_id;