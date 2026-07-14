select p.product_name, sum(unit) as unit
from Products p
left join Orders o
on p.product_id = o.product_id
where o.order_date >= '2020-02-01'::date and o.order_date < '2020-03-01'::date
group by p.product_id, p.product_name
having sum(unit) >= 100;