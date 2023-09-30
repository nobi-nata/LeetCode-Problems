# Write your MySQL query statement below


select round(avg(order_date = customer_pref_delivery_date)*100, 2) as immediate_percentage
from Delivery
where (order_date, customer_id) in (
    select min(order_date), customer_id
    from Delivery
    group by customer_id
);