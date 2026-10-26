select
    customer_id,
    count(order_timestamp) as total_orders,
    round(sum(if((time(order_timestamp)>='11:00' and time(order_timestamp)<='14:00') or (time(order_timestamp)>='18:00' and time(order_timestamp)<='21:00'), 1, 0)) * 100 / count(order_timestamp), 0) as peak_hour_percentage,
    round(avg(order_rating), 2) as average_rating
from restaurant_orders
group by customer_id
having
    total_orders >= 3
        and
    peak_hour_percentage >= 60
        and
    count(order_rating) * 2 >= count(*)
        and
    average_rating >= 4.0
order by average_rating desc, customer_id desc
;