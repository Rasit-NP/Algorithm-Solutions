select stock_name, sum(price) as capital_gain_loss
from (
    select stock_name, if(1, -price, 0) as price
    from Stocks
    where operation = 'Buy'

    union all

    select stock_name, price
    from Stocks
    where operation = 'Sell'
) t
group by stock_name
;