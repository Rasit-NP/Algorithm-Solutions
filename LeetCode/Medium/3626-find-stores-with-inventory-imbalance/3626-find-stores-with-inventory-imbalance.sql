select s.store_id, store_name, location, most_exp_product, cheapest_product, imbalance_ratio
from stores s
inner join (
    select i1.store_id, i1.product_name as most_exp_product, i2.product_name as cheapest_product, round(i2.quantity / i1.quantity, 2) as imbalance_ratio
    from inventory i1, inventory i2
    where
        i1.store_id = i2.store_id
        and
        i1.price in (
            select max(price)
            from inventory i3
            group by store_id
            having i3.store_id = i1.store_id
        )
        and
        i2.price in (
            select min(price)
            from inventory i4
            group by store_id
            having i4.store_id = i2.store_id
        )
        and
        i1.quantity < i2.quantity
        and
        (
            select count(product_name)
            from inventory i5
            group by store_id
            having i5.store_id = i1.store_id
        ) >= 3
) t
on s.store_id = t.store_id
order by imbalance_ratio desc, store_name
;