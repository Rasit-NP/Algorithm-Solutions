select s1.product_id, first_year, s1.quantity, s1.price
from Sales s1
right join (
    select product_id, min(year) as first_year
    from Sales
    group by product_id
) s2
on s1.product_id = s2.product_id and year = first_year
;