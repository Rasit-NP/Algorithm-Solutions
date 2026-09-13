select category, sum(sales) as total_sales
from (
    select *
    from book_sales
    where sales_date >= '2022-01-01' and sales_date <= '2022-01-31'
) bs
left join book b
on bs.book_id = b.book_id
group by category
order by category
;