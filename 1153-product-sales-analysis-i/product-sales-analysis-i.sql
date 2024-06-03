# Write your MySQL query statement below
select p.product_name,S.year,S.price from Sales s
left join Product p on p.product_id=s.product_id;