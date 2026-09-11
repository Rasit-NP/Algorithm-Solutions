select name, balance
from Users u
cross join (
    select account, sum(amount) as balance
    from Transactions
    group by account
) t
on u.account = t.account
where balance > 10000
;