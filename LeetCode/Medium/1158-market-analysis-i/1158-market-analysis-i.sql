select u.user_id as buyer_id, join_date, if(orders_in_2019 is null, 0, orders_in_2019) as orders_in_2019
from Users u
left join (
    select buyer_id, count(*) as orders_in_2019
    from (select * from Orders where order_date >= '2019-01-01' and order_date <= '2019-12-31') o
    group by buyer_id
) o2
on u.user_id = o2.buyer_id
;